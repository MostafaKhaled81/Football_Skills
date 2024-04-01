/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../../include/HAL/LED_Matrix/LEDMat_Private.h"
#include "../../../include/HAL/LED_Matrix/LEDMat_Interface.h"
#include "../../../include/HAL/LED_Matrix/LEDMat_Config.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u8 LEDMat_DisplayFlag = 1;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void LEDMat_voidInit(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void LEDMat_voidInit(LEDMat_t* LEDMat)
{
	voidSetLEDMatConfig();
	u8 i;
	for(i=0;i<8;i++)
	{
		/*Set Columns and Rows Pins To Be Output*/
		GPIO_voidSetPinMode(LEDMat[i].COL.Port , LEDMat[i].COL.Pin , GPIO_OUTPUT_PIN_MODE);
		GPIO_voidSetPinMode(LEDMat[i].ROW.Port , LEDMat[i].ROW.Pin , GPIO_OUTPUT_PIN_MODE);
		
		/*Set Columns and Rows Pins To Be Output PP*/
		GPIO_voidSetPinOutputMode(LEDMat[i].COL.Port , LEDMat[i].COL.Pin , GPIO_OUTPUT_PIN_PUSH_PULL);
		GPIO_voidSetPinOutputMode(LEDMat[i].ROW.Port , LEDMat[i].ROW.Pin , GPIO_OUTPUT_PIN_PUSH_PULL);
		
		/*Set Columns and Rows Pin To Be Output Low Speed*/
		GPIO_voidSetPinOutputSpeed(LEDMat[i].COL.Port , LEDMat[i].COL.Pin , GPIO_OUTPUT_PIN_LOW_SPEED);
		GPIO_voidSetPinOutputSpeed(LEDMat[i].ROW.Port , LEDMat[i].ROW.Pin , GPIO_OUTPUT_PIN_LOW_SPEED);
	}
}

/******************************************************************************
* \Syntax          : void LEDMat_voidDisplay(u8* RowsVal)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void LEDMat_voidDisplay(u8* RowsVal , LEDMat_t* LEDMat)
{
	u8 i,j;
	while(LEDMat_DisplayFlag)
	{
		for(i=0;i<8;i++)
		{
			/*Disable All Columns*/
            voidDisableAllColumns(LEDMat0);
            /*Set Rows Value*/
            for(j=0;j<8;j++)
			{
				GPIO_voidSetPinValue(LEDMat[j].ROW.Port , LEDMat[j].ROW.Pin , (RowsVal[i]>>j)&0b1);
			}
            /*Activate Column 0*/
            GPIO_voidSetPinValue(LEDMat[i].COL.Port , LEDMat[i].COL.Pin , GPIO_LOW);
            /*Delay for 2.5msec*/
            STK_VoidSetBusyWait(2500);
		}
	}
}

/******************************************************************************
* \Syntax          : static void voidDisableAllColumns(LEDMat_t* LEDMat)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void LEDMat_voidDisplayLimTime(u8* RowsVal , u32 No_Frames , LEDMat_t* LEDMat)
{
	u8 i,j;
	while(No_Frames)
	{
		for(i=0;i<8;i++)
		{
			/*Disable All Columns*/
            voidDisableAllColumns(LEDMat0);
            /*Set Rows Value*/
            for(j=0;j<8;j++)
			{
				GPIO_voidSetPinValue(LEDMat[j].ROW.Port , LEDMat[j].ROW.Pin , (RowsVal[i]>>j)&0b1);
			}
            /*Activate Column 0*/
            GPIO_voidSetPinValue(LEDMat[i].COL.Port , LEDMat[i].COL.Pin , GPIO_LOW);
            /*Delay for 2.5msec*/
            STK_VoidSetBusyWait(2500);
		}
		No_Frames--;
	}
}

/******************************************************************************
* \Syntax          : void LEDMat_voidDisplayLimTime(u8* RowsVal , u32 No_Frames , LEDMat_t* LEDMat)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
static void voidDisableAllColumns(LEDMat_t* LEDMat)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		GPIO_voidSetPinValue(LEDMat[i].COL.Port , LEDMat[i].COL.Pin , GPIO_HIGH);
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
