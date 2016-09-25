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
#include <stdbool.h>

#define MAX_SWITCHES        16              // Maximum no. switches is 16
#define MAX_FREQ            400000          // Maximum frequency is 40KHz 

void updateOutput(int switchNo);
void updatePower(void);
void initSwitches(void);
bool addSwitch(int switchNo);
bool removeSwitch(int switchNo);
bool isSwitchActive(int switchNumber);
void initHardware(void);

typedef enum {HOME, SET_FREQ, SET_SWITCH, QUESTION, DEBUG_MODE} status_t;
typedef enum {MODEA, MODEB} currMode_t;

int switchFreq;
bool power;
status_t status;

/* [] END OF FILE */
