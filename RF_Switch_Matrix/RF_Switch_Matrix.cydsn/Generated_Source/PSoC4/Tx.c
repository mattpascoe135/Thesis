/*******************************************************************************
* File Name: Tx.c  
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
#include "Tx.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Tx_PC =   (Tx_PC & \
                                (uint32)(~(uint32)(Tx_DRIVE_MODE_IND_MASK << (Tx_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Tx_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Tx_Write
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
void Tx_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Tx_DR & (uint8)(~Tx_MASK));
    drVal = (drVal | ((uint8)(value << Tx_SHIFT) & Tx_MASK));
    Tx_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Tx_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Tx_DM_STRONG     Strong Drive 
*  Tx_DM_OD_HI      Open Drain, Drives High 
*  Tx_DM_OD_LO      Open Drain, Drives Low 
*  Tx_DM_RES_UP     Resistive Pull Up 
*  Tx_DM_RES_DWN    Resistive Pull Down 
*  Tx_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Tx_DM_DIG_HIZ    High Impedance Digital 
*  Tx_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Tx_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Tx__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Tx_Read
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
*  Macro Tx_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Tx_Read(void) 
{
    return (uint8)((Tx_PS & Tx_MASK) >> Tx_SHIFT);
}


/*******************************************************************************
* Function Name: Tx_ReadDataReg
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
uint8 Tx_ReadDataReg(void) 
{
    return (uint8)((Tx_DR & Tx_MASK) >> Tx_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Tx_INTSTAT) 

    /*******************************************************************************
    * Function Name: Tx_ClearInterrupt
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
    uint8 Tx_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Tx_INTSTAT & Tx_MASK);
		Tx_INTSTAT = maskedStatus;
        return maskedStatus >> Tx_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
