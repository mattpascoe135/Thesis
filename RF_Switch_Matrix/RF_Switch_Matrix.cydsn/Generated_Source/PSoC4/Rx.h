/*******************************************************************************
* File Name: Rx.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Rx_H) /* Pins Rx_H */
#define CY_PINS_Rx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Rx_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Rx_Write(uint8 value) ;
void    Rx_SetDriveMode(uint8 mode) ;
uint8   Rx_ReadDataReg(void) ;
uint8   Rx_Read(void) ;
uint8   Rx_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Rx_DRIVE_MODE_BITS        (3)
#define Rx_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Rx_DRIVE_MODE_BITS))

#define Rx_DM_ALG_HIZ         (0x00u)
#define Rx_DM_DIG_HIZ         (0x01u)
#define Rx_DM_RES_UP          (0x02u)
#define Rx_DM_RES_DWN         (0x03u)
#define Rx_DM_OD_LO           (0x04u)
#define Rx_DM_OD_HI           (0x05u)
#define Rx_DM_STRONG          (0x06u)
#define Rx_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Rx_MASK               Rx__MASK
#define Rx_SHIFT              Rx__SHIFT
#define Rx_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rx_PS                     (* (reg32 *) Rx__PS)
/* Port Configuration */
#define Rx_PC                     (* (reg32 *) Rx__PC)
/* Data Register */
#define Rx_DR                     (* (reg32 *) Rx__DR)
/* Input Buffer Disable Override */
#define Rx_INP_DIS                (* (reg32 *) Rx__PC2)


#if defined(Rx__INTSTAT)  /* Interrupt Registers */

    #define Rx_INTSTAT                (* (reg32 *) Rx__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Rx_DRIVE_MODE_SHIFT       (0x00u)
#define Rx_DRIVE_MODE_MASK        (0x07u << Rx_DRIVE_MODE_SHIFT)


#endif /* End Pins Rx_H */


/* [] END OF FILE */
