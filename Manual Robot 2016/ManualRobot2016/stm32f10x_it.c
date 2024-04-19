/**
  ******************************************************************************
  * @file    TIM/PWM_Output/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *         This file provides template for all exceptions handler and
  *         peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"

/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */
extern uint32_t systic_time;
/** @addtogroup TIM_PWM_Output
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

extern char  dataUsart3;
extern	char rxUsart3;
void USART3_IRQHandler (void)
	{
		if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
		{
			(char)(dataUsart3 = USART_ReceiveData(USART3));
			rxUsart3 = 1;
		}
		//dataUsart3++;
	}
	
/*******************************************************************************
* Function Name  	: TIM6_IRQHandler
* Return         	: None
* Parameters 		: None
* Created by		: 
* Date created	: 20/06/2013
* Description		: This function handles TIM6 global interrupt request.
* Notes			: 
*******************************************************************************/
extern u32 en_gyro;
extern u8 data_tx_gyro;

void SysTick_Handler(void)
{ 
	static u32 tam=0;
	systic_time++;
        
        if(++tam>4&&(en_gyro==1))
        {
			  //putchar2('e');
          //USART_SendData(USART2, (uint8_t) ch);
           USART2->DR = data_tx_gyro;
         tam=0;
        }
		//Play_Tune();
}
/*******************************************************************************
* Function Name  	: TIM6_IRQHandler
* Return         	: None
* Parameters 		: None
* Created by		: 
* Date created	: 20/06/2013
* Description		: This function handles TIM6 global interrupt request.
* Notes			: 
*******************************************************************************/	
extern __IO int32_t num_over_t3;
void TIM3_IRQHandler(void)// encoder motor
{
  //TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	 TIM3->SR = (uint16_t)~TIM_IT_Update;
	
	 if(TIM3->CR1&TIM_CounterMode_Down)num_over_t3--;	
	 else num_over_t3++;	
}	
/*******************************************************************************
* Function Name  	: TIM6_IRQHandler
* Return         	: None
* Parameters 		: None
* Created by		: 
* Date created	: 20/06/2013
* Description		: This function handles TIM6 global interrupt request.
* Notes			: 
*******************************************************************************/
extern __IO int32_t num_over_t4;
void TIM4_IRQHandler(void)// encoder motor
{
  //TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	 TIM4->SR = (uint16_t)~TIM_IT_Update;
	
	 if(TIM4->CR1&TIM_CounterMode_Down)num_over_t4--;	
	 else num_over_t4++;	
}	
/*******************************************************************************
* Function Name  	: TIM6_IRQHandler
* Return         	: None
* Parameters 		: None
* Created by		: 
* Date created	: 20/06/2013
* Description		: This function handles TIM6 global interrupt request.
* Notes			: 
*******************************************************************************/
extern __IO int32_t num_over_t5;
void TIM5_IRQHandler(void)// encoder motor
{
  //TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	 TIM5->SR = (uint16_t)~TIM_IT_Update;
	
	 if(TIM5->CR1&TIM_CounterMode_Down)num_over_t5--;	
	 else num_over_t5++;	
}	


/*******************************************************************************
* Function Name  	: TIM6_IRQHandler
* Return         	: None
* Parameters 		: None
* Created by		: 
* Date created	: 20/06/2013
* Description		: This function handles TIM6 global interrupt request.
* Notes			: 
*******************************************************************************/


/*******************************************************************************
* Function Name  	: TIM6_IRQHandler
* Return         	: None
* Parameters 		: None
* Created by		: 
* Date created	: 20/06/2013
* Description		: This function handles TIM6 global interrupt request.
* Notes			: 
*******************************************************************************/
extern s16 data_gyro;
extern char mang[2];
extern u32 receiver_ok;

void DMA1_Channel6_IRQHandler(void)
{
    DMA1->IFCR = DMA1_IT_TC6; // xoa co ngat
    
    data_gyro=((mang[0]<<8)|mang[1]);
    receiver_ok=1;  
}



/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
