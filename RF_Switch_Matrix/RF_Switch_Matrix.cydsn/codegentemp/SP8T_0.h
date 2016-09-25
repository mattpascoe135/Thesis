/*******************************************************************************
* File Name: SP8T_0.h  
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

#if !defined(CY_PINS_SP8T_0_H) /* Pins SP8T_0_H */
#define CY_PINS_SP8T_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SP8T_0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SP8T_0_Write(uint8 value) ;
void    SP8T_0_SetDriveMode(uint8 mode) ;
uint8   SP8T_0_ReadDataReg(void) ;
uint8   SP8T_0_Read(void) ;
uint8   SP8T_0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SP8T_0_DRIVE_MODE_BITS        (3)
#define SP8T_0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SP8T_0_DRIVE_MODE_BITS))

#define SP8T_0_DM_ALG_HIZ         (0x00u)
#define SP8T_0_DM_DIG_HIZ         (0x01u)
#define SP8T_0_DM_RES_UP          (0x02u)
#define SP8T_0_DM_RES_DWN         (0x03u)
#define SP8T_0_DM_OD_LO           (0x04u)
#define SP8T_0_DM_OD_HI           (0x05u)
#define SP8T_0_DM_STRONG          (0x06u)
#define SP8T_0_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SP8T_0_MASK               SP8T_0__MASK
#define SP8T_0_SHIFT              SP8T_0__SHIFT
#define SP8T_0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SP8T_0_PS                     (* (reg32 *) SP8T_0__PS)
/* Port Configuration */
#define SP8T_0_PC                     (* (reg32 *) SP8T_0__PC)
/* Data Register */
#define SP8T_0_DR                     (* (reg32 *) SP8T_0__DR)
/* Input Buffer Disable Override */
#define SP8T_0_INP_DIS                (* (reg32 *) SP8T_0__PC2)


#if defined(SP8T_0__INTSTAT)  /* Interrupt Registers */

    #define SP8T_0_INTSTAT                (* (reg32 *) SP8T_0__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SP8T_0_DRIVE_MODE_SHIFT       (0x00u)
#define SP8T_0_DRIVE_MODE_MASK        (0x07u << SP8T_0_DRIVE_MODE_SHIFT)


#endif /* End Pins SP8T_0_H */


/* [] END OF FILE */
