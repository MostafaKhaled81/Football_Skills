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
#include "../../../include/APP/Football_Skills/Football_Skills.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u8 LEDMat_ReadyState[8] = {144, 74, 127, 218, 0, 64, 0, 0};
	u8 LEDMat_ShootState[8] = {144, 74, 127, 90, 128, 64, 0, 0};
	u8 LEDMat_Dripling1[8] = {144, 74, 127, 90, 128, 32, 0, 0};
	u8 LEDMat_Dripling2[8] = {144, 74, 127, 90, 128, 16, 0, 0};
	u8 LEDMat_Wall1[8] = {144, 74, 127, 90, 128, 0, 32, 0};
	u8 LEDMat_Wall2[8] = {144, 74, 127, 90, 128, 0, 0, 16};
	u8 LEDMat_Wall3[8] = {144, 74, 127, 90, 128, 0, 8, 0};
	u8 LEDMat_Head[8] = {144, 72, 126, 79, 146, 4, 0, 0};

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
* \Syntax          : void FTBLSKLS_voidInit(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void FTBLSKLS_voidInit(void)
{
	RCC_voidInit();
    RCC_voidEnablePeripheralClk(RCC_AHB1,RCC_GPIOA);
	RCC_voidEnablePeripheralClk(RCC_AHB1,RCC_GPIOB);
	LEDMat_voidInit(LEDMat0);
}

/******************************************************************************
* \Syntax          : void FTBLSKLS_voidDrepling(u8 Repeats)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void FTBLSKLS_voidDrepling(u8 Repeats)
{
	for(Repeats;Repeats>0;Repeats--)
		{
			LEDMat_voidDisplayLimTime(LEDMat_ReadyState , 30 , LEDMat0);
		    LEDMat_voidDisplayLimTime(LEDMat_ShootState , 30 , LEDMat0);
		    LEDMat_voidDisplayLimTime(LEDMat_Dripling1 , 50 , LEDMat0);
		    LEDMat_voidDisplayLimTime(LEDMat_Dripling2 , 100 , LEDMat0);
		    LEDMat_voidDisplayLimTime(LEDMat_Dripling1 , 50 , LEDMat0);
		}
}

/******************************************************************************
* \Syntax          : void FTBLSKLS_voidHeads(u8 Repeats)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void FTBLSKLS_voidHeads(u8 Repeats)
{
	for(Repeats;Repeats>0;Repeats--)
		{
		   LEDMat_voidDisplayLimTime(LEDMat_ReadyState , 30 , LEDMat0);
		   LEDMat_voidDisplayLimTime(LEDMat_ShootState , 30 , LEDMat0);
		   LEDMat_voidDisplayLimTime(LEDMat_Wall1 , 50 , LEDMat0);
		   LEDMat_voidDisplayLimTime(LEDMat_Wall2 , 50 , LEDMat0);
		   LEDMat_voidDisplayLimTime(LEDMat_Wall3 , 50 , LEDMat0);
		   LEDMat_voidDisplayLimTime(LEDMat_Head , 35 , LEDMat0);
		   LEDMat_voidDisplayLimTime(LEDMat_Wall3 , 50 , LEDMat0);
		}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
