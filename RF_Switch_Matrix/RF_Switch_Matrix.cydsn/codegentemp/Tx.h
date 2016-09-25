/*******************************************************************************
* File Name: Tx.h  
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

#if !defined(CY_PINS_Tx_H) /* Pins Tx_H */
#define CY_PINS_Tx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Tx_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Tx_Write(uint8 value) ;
void    Tx_SetDriveMode(uint8 mode) ;
uint8   Tx_ReadDataReg(void) ;
uint8   Tx_Read(void) ;
uint8   Tx_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Tx_DRIVE_MODE_BITS        (3)
#define Tx_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Tx_DRIVE_MODE_BITS))

#define Tx_DM_ALG_HIZ         (0x00u)
#define Tx_DM_DIG_HIZ         (0x01u)
#define Tx_DM_RES_UP          (0x02u)
#define Tx_DM_RES_DWN         (0x03u)
#define Tx_DM_OD_LO           (0x04u)
#define Tx_DM_OD_HI           (0x05u)
#define Tx_DM_STRONG          (0x06u)
#define Tx_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Tx_MASK               Tx__MASK
#define Tx_SHIFT              Tx__SHIFT
#define Tx_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Tx_PS                     (* (reg32 *) Tx__PS)
/* Port Configuration */
#define Tx_PC                     (* (reg32 *) Tx__PC)
/* Data Register */
#define Tx_DR                     (* (reg32 *) Tx__DR)
/* Input Buffer Disable Override */
#define Tx_INP_DIS                (* (reg32 *) Tx__PC2)


#if defined(Tx__INTSTAT)  /* Interrupt Registers */

    #define Tx_INTSTAT                (* (reg32 *) Tx__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Tx_DRIVE_MODE_SHIFT       (0x00u)
#define Tx_DRIVE_MODE_MASK        (0x07u << Tx_DRIVE_MODE_SHIFT)


#endif /* End Pins Tx_H */


/* [] END OF FILE */
