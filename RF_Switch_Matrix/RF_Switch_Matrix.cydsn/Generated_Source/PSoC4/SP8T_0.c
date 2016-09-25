/*******************************************************************************
* File Name: SP8T_0.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SP8T_0.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SP8T_0_PC =   (SP8T_0_PC & \
                                (uint32)(~(uint32)(SP8T_0_DRIVE_MODE_IND_MASK << (SP8T_0_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SP8T_0_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SP8T_0_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void SP8T_0_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SP8T_0_DR & (uint8)(~SP8T_0_MASK));
    drVal = (drVal | ((uint8)(value << SP8T_0_SHIFT) & SP8T_0_MASK));
    SP8T_0_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SP8T_0_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SP8T_0_DM_STRONG     Strong Drive 
*  SP8T_0_DM_OD_HI      Open Drain, Drives High 
*  SP8T_0_DM_OD_LO      Open Drain, Drives Low 
*  SP8T_0_DM_RES_UP     Resistive Pull Up 
*  SP8T_0_DM_RES_DWN    Resistive Pull Down 
*  SP8T_0_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SP8T_0_DM_DIG_HIZ    High Impedance Digital 
*  SP8T_0_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SP8T_0_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SP8T_0__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SP8T_0_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro SP8T_0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SP8T_0_Read(void) 
{
    return (uint8)((SP8T_0_PS & SP8T_0_MASK) >> SP8T_0_SHIFT);
}


/*******************************************************************************
* Function Name: SP8T_0_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 SP8T_0_ReadDataReg(void) 
{
    return (uint8)((SP8T_0_DR & SP8T_0_MASK) >> SP8T_0_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SP8T_0_INTSTAT) 

    /*******************************************************************************
    * Function Name: SP8T_0_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 SP8T_0_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SP8T_0_INTSTAT & SP8T_0_MASK);
		SP8T_0_INTSTAT = maskedStatus;
        return maskedStatus >> SP8T_0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
