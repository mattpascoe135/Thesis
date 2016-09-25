/*******************************************************************************
* File Name: SDPT_0.h  
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

#if !defined(CY_PINS_SDPT_0_H) /* Pins SDPT_0_H */
#define CY_PINS_SDPT_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SDPT_0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SDPT_0_Write(uint8 value) ;
void    SDPT_0_SetDriveMode(uint8 mode) ;
uint8   SDPT_0_ReadDataReg(void) ;
uint8   SDPT_0_Read(void) ;
uint8   SDPT_0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SDPT_0_DRIVE_MODE_BITS        (3)
#define SDPT_0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SDPT_0_DRIVE_MODE_BITS))

#define SDPT_0_DM_ALG_HIZ         (0x00u)
#define SDPT_0_DM_DIG_HIZ         (0x01u)
#define SDPT_0_DM_RES_UP          (0x02u)
#define SDPT_0_DM_RES_DWN         (0x03u)
#define SDPT_0_DM_OD_LO           (0x04u)
#define SDPT_0_DM_OD_HI           (0x05u)
#define SDPT_0_DM_STRONG          (0x06u)
#define SDPT_0_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SDPT_0_MASK               SDPT_0__MASK
#define SDPT_0_SHIFT              SDPT_0__SHIFT
#define SDPT_0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SDPT_0_PS                     (* (reg32 *) SDPT_0__PS)
/* Port Configuration */
#define SDPT_0_PC                     (* (reg32 *) SDPT_0__PC)
/* Data Register */
#define SDPT_0_DR                     (* (reg32 *) SDPT_0__DR)
/* Input Buffer Disable Override */
#define SDPT_0_INP_DIS                (* (reg32 *) SDPT_0__PC2)


#if defined(SDPT_0__INTSTAT)  /* Interrupt Registers */

    #define SDPT_0_INTSTAT                (* (reg32 *) SDPT_0__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SDPT_0_DRIVE_MODE_SHIFT       (0x00u)
#define SDPT_0_DRIVE_MODE_MASK        (0x07u << SDPT_0_DRIVE_MODE_SHIFT)


#endif /* End Pins SDPT_0_H */


/* [] END OF FILE */
