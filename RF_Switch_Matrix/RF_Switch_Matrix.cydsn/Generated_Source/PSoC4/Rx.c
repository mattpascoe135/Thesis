/*******************************************************************************
* File Name: Rx.c  
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
#include "Rx.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Rx_PC =   (Rx_PC & \
                                (uint32)(~(uint32)(Rx_DRIVE_MODE_IND_MASK << (Rx_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Rx_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Rx_Write
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
void Rx_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Rx_DR & (uint8)(~Rx_MASK));
    drVal = (drVal | ((uint8)(value << Rx_SHIFT) & Rx_MASK));
    Rx_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Rx_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Rx_DM_STRONG     Strong Drive 
*  Rx_DM_OD_HI      Open Drain, Drives High 
*  Rx_DM_OD_LO      Open Drain, Drives Low 
*  Rx_DM_RES_UP     Resistive Pull Up 
*  Rx_DM_RES_DWN    Resistive Pull Down 
*  Rx_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Rx_DM_DIG_HIZ    High Impedance Digital 
*  Rx_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Rx_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Rx__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Rx_Read
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
*  Macro Rx_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Rx_Read(void) 
{
    return (uint8)((Rx_PS & Rx_MASK) >> Rx_SHIFT);
}


/*******************************************************************************
* Function Name: Rx_ReadDataReg
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
uint8 Rx_ReadDataReg(void) 
{
    return (uint8)((Rx_DR & Rx_MASK) >> Rx_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Rx_INTSTAT) 

    /*******************************************************************************
    * Function Name: Rx_ClearInterrupt
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
    uint8 Rx_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Rx_INTSTAT & Rx_MASK);
		Rx_INTSTAT = maskedStatus;
        return maskedStatus >> Rx_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
