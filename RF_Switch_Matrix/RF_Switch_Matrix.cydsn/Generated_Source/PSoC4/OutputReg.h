/*******************************************************************************
* File Name: OutputReg.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_OutputReg_H) /* CY_CONTROL_REG_OutputReg_H */
#define CY_CONTROL_REG_OutputReg_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} OutputReg_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    OutputReg_Write(uint8 control) ;
uint8   OutputReg_Read(void) ;

void OutputReg_SaveConfig(void) ;
void OutputReg_RestoreConfig(void) ;
void OutputReg_Sleep(void) ; 
void OutputReg_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define OutputReg_Control        (* (reg8 *) OutputReg_Sync_ctrl_reg__CONTROL_REG )
#define OutputReg_Control_PTR    (  (reg8 *) OutputReg_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_OutputReg_H */


/* [] END OF FILE */
