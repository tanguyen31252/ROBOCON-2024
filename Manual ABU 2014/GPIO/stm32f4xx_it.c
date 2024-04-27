/**
  ******************************************************************************
  * @file    TIM/6Steps/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-September-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
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
#include "stm32f4xx_it.h"

void robotAnalytics(void);
char colorSensorDetect(void);

/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup TIM_6Steps
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{}

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
	extern vu8 en_gyro;
	vu32 _view_systick=0;
	u8 _index_gyro=0;
	extern unsigned int bitha;
	extern unsigned int flash_bit;
void SysTick_Handler(void)
{
	static u32 tam_gyro=0;
				if(++tam_gyro>10)// sau 20ms thi lay imu 1 lan
				{	tam_gyro=0;
					if(en_gyro==1)
					{ 	
						USART1->DR='z';
						_index_gyro=0;
					
					}
				}
				
	if(bitha==1)
		{		
				static int   bien=0; 
				if(++bien > 70){ bien =0; GPIOE->ODR^=1<<0;}
				
    }
		
			
  if(flash_bit==1)
		{		
				static int  bit_nhay=0;	
				static int  bit_nhay1=0;
				if(++bit_nhay > 80 ){bit_nhay = 0; bit_nhay1++;GPIOC->ODR^=1<<13;}
				if(bit_nhay1>5)      flash_bit=0,bit_nhay1=0,GPIOC->BSRRL=1<<13;
				
    }

}



/******************************************************************************/
/*            STM32F4xx Peripherals Interrupt Handlers                        */
/******************************************************************************/

/**
  * @brief  This function handles TIM1 Trigger and commutation and TIM11 
  *         global interrupts requests.
  * @param  None
  * @retval None
  */


//xxxxxxxxxxxxxxxxxxxxxxxxxxx
extern vu8 RxBuffer_compass[2];
extern vs16 data_imu;


void USART1_IRQHandler(void)// ngat  uart1 RX
{ 
	if(USART_GetITStatus(USART1,USART_IT_RXNE)!= RESET)
    {      
			 USART_ClearFlag(USART1, USART_FLAG_RXNE);
//			USART1->SR = (uint16_t)~USART_FLAG_RXNE;
			 RxBuffer_compass[_index_gyro++]=USART1->DR;
			 if(_index_gyro>1)
			 {
				data_imu=(RxBuffer_compass[0]<<8)|RxBuffer_compass[1];
			 }

			 
//			 _view_systick++;
		}
		
		
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void DMA2_Stream5_IRQHandler(void)// ngat DMA uart1 RX
{
	//if(DMA_GetITStatus(DMA2_Stream5,DMA_IT_TCIF5)!= RESET)
	//if(DMA_GetFlagStatus(DMA2_Stream5, DMA_IT_TCIF5) != RESET)
    {      
			DMA_ClearITPendingBit(DMA2_Stream5,DMA_IT_TCIF5);
			data_imu=(RxBuffer_compass[1]<<8)|RxBuffer_compass[0];
			//DMA_Cmd(DMA2_Stream5, DISABLE);
		}
		
		 _view_systick++;
}

//xxxxxxxxxxxxxxxx
void TIM6_DAC_IRQHandler(void)// INTERRUPTS TIM6
{ 
	static vu32 time=0;	
  TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
	
	robotAnalytics();
	colorSensorDetect();
	
//  if(++time>500)
//	{
//		GPIOC->ODR^=1<<7;		
//		time = 0;
//	}
	
}


void TIM1_UP_TIM10_IRQHandler(void)// INTERRUPTS TIM1 OR TIM10 OVERFLOW
{ 

}

void TIM1_TRG_COM_TIM11_IRQHandler(void)
{
  
}

extern vs32 num_over_t2;
void TIM2_IRQHandler(void)
{
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	if(TIM2->CR1&TIM_CounterMode_Down)num_over_t2--;	
	else num_over_t2++;
}

extern vs32 num_over_t3;
void TIM3_IRQHandler(void)
{
  TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	if(TIM3->CR1&TIM_CounterMode_Down)num_over_t3--;	
	else num_over_t3++;	
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void SPI1_IRQHandler(void)
{ 
}

/**
  * @brief  This function handles SPI2 global interrupt request.
  * @param  None
  * @retval None
  */
void SPI3_IRQHandler(void)
{ 
	
	
}


/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                            */
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
