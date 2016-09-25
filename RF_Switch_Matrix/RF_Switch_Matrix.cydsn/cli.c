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
#include <stdbool.h>
#include <stdio.h>
#include <main.h>

/* void sendString(char* string)
 * @param:
 *     pointer to a array of char
 *
 * Writes the parsed string to the Tx USB conneciton
 */
void sendString(char* string) {
    int i=0;
    while(string[i] != '\0') {
        UART_WriteTxData(string[i]);
        i++;
    }
}

void homeProcess(char input) {
    switch(input) {
        case '1':
            if(power) {
                power = false;
                updatePower();
                UART_PutString("Turning switch OFF\r\n\r\n");
            } else {
                power = true;
                updatePower(); 
                UART_PutString("Turning switch ON\r\n\r\n");
            }
            break;
        case '2':
            status = SET_FREQ;
            dispFuncHelp();
            break;
        case '3':
            status = SET_SWITCH;
            dispSwitchHelp();
            break;
        case '4':
            status = DEBUG_MODE;
            dispDebugHelp();
           
            //move to new for loop in main
            break;
        case 'h':
            UART_PutString("\r\n");
            dispMenuHelp();
            break;
        default:
            UART_PutString("Invalid input\r\n");
    }
    UART_PutString("> ");
}


void switchProcess(char input) {
    if(input != 'x') {
        int switchVal = input-'a';
        if(isSwitchActive(switchVal)) {
            removeSwitch(switchVal);
            UART_PutString("Deactivated switch\r\n");
        } else {
            addSwitch(switchVal);
            UART_PutString("Activated switch\r\n");
        }  
    }
    
    //Ask if there is any additional changes
    UART_PutString("Change more switches? y/n\r\n");
    UART_PutString("> ");
    status = QUESTION;
}
    


/* void dispMenuHelp(void)
 * @param:
 *     void
 *
 * Prints out a help menu
 */
void dispMenuHelp(void) {
    if(power) {
        UART_PutString("1. Turn off switch matrix\r\n");
    } else {
        UART_PutString("1. Turn on switch matrix\r\n");
    }
    UART_PutString("2. Set switching frequency\r\n");
    UART_PutString("3. Change active swiches\r\n");
}

/* void dispFuncHelp(void)
 * @param:
 *     void
 *
 * Prints out a help menu
 */
void dispFuncHelp(void) {
    UART_PutString("\r\nEnter a valid switching frequency from 0-30000Hz\r\n");
    UART_PutString("Enter the frequency in Hz and press ENTER\r\n");
    UART_PutString("Press 'x' to return to main menu\r\n");
}

/* void dispSwitchHelp(void)
 * @param:
 *     void
 *
 * Prints out a help menu
 */
void dispSwitchHelp(void) {
    char str[80];
    int i;
    UART_PutString("Enter a character for which switch to add/remove\r\n");
    for(i=0; i<MAX_SWITCHES; i++) {
        if(isSwitchActive(i)) {
            sprintf(str, "%c). Output %d - ON\r\n", 'a'+i, i);
        } else {
            sprintf(str, "%c). Output %d - OFF\r\n", 'a'+i, i);
        }
        UART_PutString(str);
    }    
    UART_PutString("x). Cancel and resturn to main menu.\r\n");
}

void dispDebugHelp(void) {
    UART_PutString("Entering Debug mode...\r\n");
    UART_PutString("Press any key to change to next switch\r\n");
    UART_PutString("Press 'x' to return to main menu\r\n");
}
/* [] END OF FILE */
