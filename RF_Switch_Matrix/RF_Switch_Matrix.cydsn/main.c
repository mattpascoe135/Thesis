/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <cli.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <main.h>

int switchFreq          =   100;            // Set default switch speed to 10KHz (1/10000)=0.0001s=100us
bool power              =   false;          // When device turns on, set power to off
int calibrate           =   0;

typedef struct node {       //node for switch
    uint16 number;
    struct node *next;
    struct node *prev;
} node_t;
node_t *head;
node_t *curr;

//Setup states for CLI
status_t status=HOME;
currMode_t mode=MODEA;



CY_ISR(rx_int) {    
    static int freq=0;
    char data;
    
    data = UART_GetChar();        
    UART_WriteTxData(data);
            
    switch(status) {
        case HOME:
            homeProcess(data);
            UART_PutString("\r\n");
            break;
            
        case SET_FREQ:
            //gather input until enter is pressed
            if(data > '0' && data < '9') {
                freq = freq*10 + (data-'0');            //Calculate the freq.
            } else if(data =='\r' || data=='\n') {
                switchFreq = 1000000/freq;        //convert frequency to delay time (us)
                status = HOME;
                UART_PutString("Returning to main menu, press 'h' for help.\r\n\r\n");
                UART_PutString("> ");   
            }
            break;
            
        case SET_SWITCH:
            switchProcess(data);
            UART_PutString("\r\n");
            break;
            
        case QUESTION:
            if(data == 'y' || data == 'Y') {
                status = SET_SWITCH;
                UART_PutString("\r\n");
                dispSwitchHelp();
                UART_PutString("> ");   
            } else if(data == 'n' || data == 'N') {
                status = HOME;
                UART_PutString("Returning to main menu, press 'h' for help.\r\n");
                UART_PutString("> ");                
            } else {
                UART_PutString("Invalid response, choose: y/n\r\n");
                UART_PutString("> ");
            }
            UART_PutString("\r\n");
            break;
            
        case DEBUG_MODE:
            if(data == 'x') {
                status = HOME;           //move to main again
                UART_PutString("Returning to main menu, press 'h' for help.\r\n");
                UART_PutString("> ");  
            } else {
                curr=curr->next;
                updateOutput(curr->number);
            }
            break;
    }
}


int main() {    
    initHardware();
        
    for(;;) {
        while(mode==MODEA) {                   // Loop through all the switches
            updateOutput(curr->number);
            curr=curr->next;
            CyDelay(switchFreq);                //Delay for switchFreq;    
        }
        
        while(mode==MODEB){}
    }
}


/**     void updateOutput(int switchNo)
 *      @param
 *          int switchNo
 *      @ret
 *          void
 *
 *      Updates the output 
 */
void updateOutput(int switchNo) {
    uint8 val;
    val=OutputReg_Read() & 240;                     // XXXX XXXX & 1111 0000 = XXXX 0000
    OutputReg_Write(val|switchNo);                  // XXXX 0000 | 0000 YYYY = XXXX YYYY 
}


/*      void updatePower(void)
 *      @param
 *          void
 *      @ret
 *          void
 *
 *      Inialises all switches to be on, creates the linked list
 *      and links all the switches together in a standard order.
 */
void updatePower(void) {
    uint8 data = OutputReg_Read();
    data &= 239;        // XXXX XXXX & 1110 1111 = XXX0 XXXX
    if(power) {
        data |= 16;     //XXX0 XXXX | 0001 0000 = XXX1 XXXX 
    }
    OutputReg_Write(data);
}


/*      void initSwitches(void)
 *      @param
 *          void
 *      @ret
 *          void
 *
 *      Inialises all switches to be on, creates the linked list
 *      and links all the switches together in a standard order.
 */
void initSwitches(void) {
    int i;
    node_t *tmp = NULL;
    head = curr = malloc(sizeof(node_t));
    head->number = 0;
    for(i=1; i<MAX_SWITCHES; i++) {
        tmp = malloc(sizeof(node_t));
        tmp->number=i;
        curr->next = tmp;
        tmp->prev=curr;
        curr=tmp;
    }
    curr->next = head;
    head->prev = curr;
    curr = head;                //Set curr at the HEAD
}


/*      bool addSwitch(int switchNo)
 *      @param
 *          int switchNo
 *      @ret
 *          bool: true if switch was added, false if switch couldnt be added
 *
 *      Adds new switch to the linked list
 */
bool addSwitch(int switchNo) {
    node_t *tmp=head, *newNode=NULL;
    do{
        if(tmp->number == switchNo) {
            return false;
        } else if(tmp->number < switchNo && tmp->next->number > switchNo) {
            ///create the new node and add it to the linked list
            newNode=malloc(sizeof(node_t));
            newNode->number=switchNo;
            newNode->prev = tmp;
            newNode->next=tmp->next;
            
            //link list to new node
            tmp->next = newNode;
            tmp->next->prev = newNode;
            return true;
        }
        tmp=tmp->next;
    }while(tmp!=head);
    
    return false;
}


/*      bool addSwitch(int switchNo)
 *      @param
 *          int switchNo
 *      @ret
 *          bool: true if switch was removed, false if switch couldnt be removed
 *
 *      Removes switch if it has the parsed number from the linked list
 */
bool removeSwitch(int switchNo) {
    node_t *tmp = head;
    if(tmp->number == switchNo) {
        tmp->prev->next = tmp->next;
        free(tmp);
        return true;
    }
    do{
        tmp=tmp->next;
        if(tmp->number == switchNo) {
            tmp->prev->next = tmp->next;
            free(tmp);
            return true;
        }
    }while(tmp!=head);
    
    //If we got here then the switch no was not active
    return false;
}


/*      bool isSwitchActive(int switchNumber)
 *      @param
 *          int switchNumber
 *      @ret
 *          bool: true if switch was removed, false if switch couldnt be removed
 *
 *      Checks to see if the switch number is currently in the linked list
 */
bool isSwitchActive(int switchNumber) {
    node_t *tmp = head;
    do{
        if(tmp->number == switchNumber) {
            return true;
        }
        tmp=tmp->next;
    }while(tmp!=head);
    return false;
}


/*      void initHardware(void)
 *      @param
 *          void
 *      @ret
 *          void
 *
 *      Initalised the hardware that is used by the microcontroller for the switch matrix
 */
void initHardware(void) {
    CyGlobalIntEnable;
    UART_Start();                   //Setup UART comm.
    uartRx_isr_StartEx(rx_int);     //Inialise Rx ISR
    UART_PutString("\r\n\r\n");
    OutputReg_Write(0u);            //Set all vaules to 0
    
    initSwitches();
    
    dispMenuHelp();
    UART_PutString("> ");
}

/* [] END OF FILE */
