#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lcd.h"
//#include "Auto_Robot_Manual.h"
//#include "gamepad.h"
//#include "ControlerMecanum.h"
//#include "ControlerOmni.h"
//#include "SensorDetect.h"

#define 	ADC1_DR_ADDRESS    ((uint32_t)0x4001204C)

//-------------------------------- DEFINE MOTOR ---------------------------------------
#define		mor_FrontLeft						TIM4->CCR2					//D13		
#define 	mor_FrontLeft_next			GPIOD->BSRRH=1<<10	//GPIO_WriteBit(GPIOC,GPIO_Pin_12,0)
#define 	mor_FrontLeft_back			GPIOD->BSRRL=1<<10	//GPIO_WriteBit(GPIOC,GPIO_Pin_12,1)

#define		mor_RearLeft						TIM4->CCR1					//D12
#define 	mor_RearLeft_next				GPIOD->BSRRL=1<<11	//GPIO_WriteBit(GPIOB,GPIO_Pin_5,1)
#define 	mor_RearLeft_back				GPIOD->BSRRH=1<<11	//GPIO_WriteBit(GPIOB,GPIO_Pin_5,0)

#define		mor_FrontRight					TIM1->CCR4					//E14
#define 	mor_FrontRight_next			GPIOE->BSRRL=1<<15	//GPIO_WriteBit(GPIOC,GPIO_Pin_4,1)
#define 	mor_FrontRight_back			GPIOE->BSRRH=1<<15	//GPIO_WriteBit(GPIOC,GPIO_Pin_4,0)

#define		mor_RearRight						TIM1->CCR3					//E13
#define 	mor_RearRight_next			GPIOB->BSRRH=1<<12	//GPIO_WriteBit(GPIOC,GPIO_Pin_3,0)
#define 	mor_RearRight_back			GPIOB->BSRRL=1<<12	//GPIO_WriteBit(GPIOC,GPIO_Pin_3,1)

#define		mor_nang								TIM4->CCR3					//D12	
#define 	mor_nang_up							GPIOD->BSRRL=1<<9	//GPIO_WriteBit(GPIOC,GPIO_Pin_2,1)
#define 	mor_nang_down						GPIOD->BSRRH=1<<9	//GPIO_WriteBit(GPIOC,GPIO_Pin_2,0)

#define		mor_ngang								TIM4->CCR4					//D13
#define 	mor_ngang_next					GPIOD->BSRRL=1<<8	//GPIO_WriteBit(GPIOC,GPIO_Pin_1,1)
#define 	mor_ngang_back					GPIOD->BSRRH=1<<8	//GPIO_WriteBit(GPIOC,GPIO_Pin_1,0)

#define 	cb_TT0                  	GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7)
#define 	cb_TT1                  	GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_9)
#define 	cb_TT2 	                	GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_11)

#define 	cb_TS0                  	GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6)
#define 	cb_TS1                  	GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8)
#define 	cb_TS2                  	GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_10)


#define 	cb_PT0                  	GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_1)
#define 	cb_PT1                  	GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_3)
#define 	cb_PT2                  	GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_5)

#define 	cb_PS0                  	GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_0)
#define 	cb_PS1                  	GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_2)
#define 	cb_PS2                  	GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_4)

#define 	cb_NC_TAY_1    					  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_7)
#define 	cb_NC_TAY_2          			GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)
#define 	cb_NC_TAY_3            		GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)	
#define 	cb_NC_TAY_4          			GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)
#define 	cb_NC_TAY_5	  						GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)
#define 	cb_NC_TAY_6 		          GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_5)
#define 	cb_NC_TAY_7 		          GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4)
#define 	cb_NC_TAY_8 		          GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_8)				 // DAU HANH TRINH


#define 	XANH_DO		            		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)

#define 	cb_mode		            		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)

#define 	cb_XICHDU_T           		GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15)												
#define 	cb_XICHDU_P    					  GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_13)										
#define 	cb_DON_XICHDU_T 		      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_14)										
#define 	cb_DON_XICHDU_P 		      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_12)		

#define 	cb_XICHDU			           	GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_8)								

#define 	cb_quang_bb           		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)
#define 	cb_quang_bb_xanh       		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)

#define 	cb_quang_left          		GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_9)

#define 	cb_Kep			           		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)			
#define 	cb_Tay			           		GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_11)								


#define 	cb_NC_1            				GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_0)
#define 	cb_NC_2            				GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_1)
#define 	cb_NC_3            				GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)
#define 	cb_NC_4            				GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)
#define 	cb_NC_5            				GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)
#define 	cb_NC_6            				GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_5)
#define 	cb_NC_7            				GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)
#define 	cb_NC_8            				GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_7)
#define 	cb_NC_9            				GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)
#define 	cb_NC_10           				GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6)
// 
#define 	cb_BAN		 		          	GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
 // ============================ OUTPUT =================================
#define   Xilanh53_ra_on					GPIOE->BSRRH=1<<0
#define   Xilanh53_ra_off					GPIOE->BSRRL=1<<0

#define   Xilanh53_ve_on					GPIOE->BSRRH=1<<2
#define   Xilanh53_ve_off					GPIOE->BSRRL=1<<2

#define   Xilanh50_on					   	GPIOB->BSRRH=1<<8
#define   Xilanh50_off					 	GPIOB->BSRRL=1<<8

#define   Xilanh_kep_on						GPIOE->BSRRL=1<<1
#define   Xilanh_kep_off					GPIOE->BSRRH=1<<1

#define   Xilanh_cheo_on					GPIOE->BSRRH=1<<4
#define   Xilanh_cheo_off					GPIOE->BSRRL=1<<4

#define   Xilanh_ban_on						GPIOE->BSRRH=1<<3
#define   Xilanh_ban_off					GPIOE->BSRRL=1<<3

#define   Xilanh_mode_on					GPIOB->BSRRH=1<<13
#define   Xilanh_mode_off					GPIOB->BSRRL=1<<13

vs32 	num_over_t2, num_over_t3;
vu8 	data_tx_gyro, a, en_gyro;
vu8 	RxBuffer_compass[2];
extern vu16 _ADC1_Value[3];
extern int _robotIMUAngle;

unsigned int bitha=0;
unsigned int flash_bit=0;

unsigned int auto_mode=0;

//------------------------------------ DELAY MICROSECOND--------------------------------------------
void delay_us(vu32 num)
{
	__IO uint32_t index = 0;

	/* default system clock is 180MHz */
	for(index = (18 * num); index != 0; index--);
}

//void delay_us(u32 num)
//{
// TIM7->CNT=0;
// while(TIM7->CNT<num);
//}

//------------------------------------ DELAY MILISECOND--------------------------------------------
void delay_ms(vu32 num)
{
	__IO uint32_t index = 0;

	/* default system clock is 180MHz */
	for(index = (18000 * num); index != 0; index--);
}


//void delay_ms(u32 num)
//{
// while(num--) delay_us(1000);
//}



//----------------------------------- PRINT A STRING TO LCD ---------------------------------------
void lcd_printStr(char x, char y, char* data)
{
	lcd_gotoxy(x,y);
  lcd_putsf(data);
}

//--------------------------------- PRINT A INT NUMBER TO LCD -------------------------------------
void lcd_printInt(char x, char y, vs32 n) 
{
	char str[33];
	lcd_gotoxy(x,y);
	sprintf(str,"%i", n);
	lcd_putsf(str);
	lcd_putsf("   ");
}

//--------------------------------- PRINT A INT NUMBER TO LCD -------------------------------------
void lcd_printInt_32(char x, char y, vu32 n) 
{
	char str[33];
	lcd_gotoxy(x,y);
	sprintf(str,"%u", n);
	lcd_putsf(str);
	lcd_putsf("   ");
}


//---------------------------- config out mode -----------------------------
void Config_out_mode(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIOB->ODR|= GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_13;
	GPIOB->BSRRL=GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_13;
	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIOC->ODR|= GPIO_Pin_13;
	GPIOC->BSRRL=GPIO_Pin_13;	
}

//---------------------------- config out mode -----------------------------
void Config_in_mode(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOG, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_12 | GPIO_Pin_4 | GPIO_Pin_5;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_10;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}

//---------------------------- config timer6 1ms --------------------------
void Config_int_time6(void)
{
 	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

	NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

  NVIC_InitStructure.NVIC_IRQChannel = TIM6_DAC_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
    
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	TIM_TimeBaseInitStructure.TIM_Prescaler=50;
  TIM_TimeBaseInitStructure.TIM_Period=999;//1ms
  TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//
  TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);
  
  TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
  TIM_SetCounter(TIM6, 0); 
  TIM_Cmd(TIM6,ENABLE);
}

void Config_int_time7(void)
{
 	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

//	NVIC_InitTypeDef NVIC_InitStructure;

//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

//  NVIC_InitStructure.NVIC_IRQChannel = TIM6_DAC_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
    
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
	TIM_TimeBaseInitStructure.TIM_Prescaler=83;
  TIM_TimeBaseInitStructure.TIM_Period=0xffff;
  TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//
  TIM_TimeBaseInit(TIM7, &TIM_TimeBaseInitStructure);
  
//  TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
//  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
  TIM_SetCounter(TIM7, 0); 
  TIM_Cmd(TIM7,ENABLE);
}

//----------------------------- config pwm timer1 ------------------------
void Config_pwm_time_t1(void)
{
 	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
  GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOB, ENABLE);
	 
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_TIM1);// ch1
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);// ch2
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);// ch3
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);//ch4
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType =GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  TIM_TimeBaseInitStructure.TIM_Prescaler=300; // fpwm=4khz
  TIM_TimeBaseInitStructure.TIM_Period=256;
  TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
  TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//
  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure); 


	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	

  TIM_CtrlPWMOutputs(TIM1,ENABLE);
  TIM_Cmd(TIM1,ENABLE);
//  TIM_SetCounter(TIM1, 0);
//      
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_12; // dir control driver
//  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_OUT;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//  GPIO_InitStructure.GPIO_OType =GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//  GPIO_Init(GPIOB, &GPIO_InitStructure);
//  
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15|GPIO_Pin_12;// dir control driver
//	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_OUT;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//  GPIO_InitStructure.GPIO_OType =GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//  GPIO_Init(GPIOE, &GPIO_InitStructure); 
	
//	GPIO_Write(GPIOE,0xffff);
}

//--------------------------- config pwm timer4 ---------------------------
void Config_pwm_time_t4(void)
{
 	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
		
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4); // ch1
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);// ch2
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);// ch3
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);  //ch4
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_15|GPIO_Pin_13|GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
		
	TIM_TimeBaseInitStructure.TIM_Prescaler=84000000/(2000*255); // fpwm=2khz
  TIM_TimeBaseInitStructure.TIM_Period=255;
  TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);
   
  TIM_Cmd(TIM4,ENABLE);
  TIM_SetCounter(TIM4, 0);
   
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11; // dir control driver
  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType =GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOD, &GPIO_InitStructure); 
}

//-----------------------------------------------------------------------------
void NVIC_Config_tim2_3(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  /* Enable the TIM3 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
//---------------------- config encoder timer2 && timer3 ---------------------
void Config_encoder_timer2_timer3(void)
{
 	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB, ENABLE);
	
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2); // tim2
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);

  GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3); // tim3
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
//  GPIO_InitStructure.GPIO_Pin = ;
//  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM_TimeBaseInitStructure.TIM_Prescaler=0;
  TIM_TimeBaseInitStructure.TIM_Period=0xFFFF;
  TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
    
  TIM_ICInitStructure.TIM_Channel=TIM_Channel_1|TIM_Channel_2;
  TIM_ICInitStructure.TIM_ICPolarity=TIM_ICPolarity_Falling;
  TIM_ICInitStructure.TIM_ICFilter=15;
  TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;
  TIM_ICInit(TIM2, &TIM_ICInitStructure);
  TIM_ICInit(TIM3, &TIM_ICInitStructure);
     
  TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);
  TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
  
  TIM_Cmd(TIM2,ENABLE); 
	TIM_Cmd(TIM3,ENABLE);
	
  TIM_SetCounter(TIM2, 0); 
	TIM_SetCounter(TIM3, 0);
    
  NVIC_Config_tim2_3();
}

//------------------------------------ config ADC DMA ----------------------------- 
void Config_ADC1_DMA(void)
{
  ADC_InitTypeDef       ADC_InitStructure;
  ADC_CommonInitTypeDef ADC_CommonInitStructure;
  DMA_InitTypeDef       DMA_InitStructure;
  GPIO_InitTypeDef      GPIO_InitStructure;

  /* Enable ADC3, DMA2 and GPIO clocks ****************************************/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

  /* DMA2 Stream0 channel0 configuration **************************************/
  DMA_InitStructure.DMA_Channel = DMA_Channel_0;  
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_ADDRESS;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&_ADC1_Value;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = 3;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  DMA_Init(DMA2_Stream0, &DMA_InitStructure);
  DMA_Cmd(DMA2_Stream0, ENABLE);
//	config_ngat_dma();// cau hinh ngat dma phai dat sau lenh enable kenh dma.

  /* Configure ADC1 Channel7 pin as analog input ******************************/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* ADC Common Init **********************************************************/
  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div8;
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;//ADC_DMAAccessMode_1;//
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_20Cycles;
  ADC_CommonInit(&ADC_CommonInitStructure);

  /* ADC3 Init ****************************************************************/
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 3;
  ADC_Init(ADC1, &ADC_InitStructure);

  /* ADC3 regular channel7 configuration *************************************/
	#define sample_time_adc1 ADC_SampleTime_84Cycles
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, sample_time_adc1);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, sample_time_adc1);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, sample_time_adc1);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, sample_time_adc1);
//  ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 5, sample_time_adc1);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 6, sample_time_adc1);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 7, sample_time_adc1);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 8, sample_time_adc1); // cac so rank la so thu tu chuyen doi adc 

 /* Enable DMA request after last transfer (Single-ADC mode) */
  ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
//ADC_MultiModeDMARequestAfterLastTransferCmd(ENABLE);
  /* Enable ADC1 DMA */
  ADC_DMACmd(ADC1, ENABLE);

  /* Enable ADC1 */
  ADC_Cmd(ADC1, ENABLE);
	ADC_SoftwareStartConv(ADC1);
}
//----------------------------------- config int uart1 ------------------------------
void Config_int_uart1_rx(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;// 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; // muc do uu tien ngat thu 15
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;// cho phep su dung ngat
  NVIC_Init(&NVIC_InitStructure);  	// cau hinh cho bang vector ngat
		
}
 
//-------------------------- config interup dma2 uart1 -----------------------
void Config_ngat_dma2_uart1_rx(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream5_IRQn;// 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 13; // muc do uu tien ngat thu 15
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;// cho phep su dung ngat
  NVIC_Init(&NVIC_InitStructure);  	// cau hinh cho bang vector ngat
}

//---------------------------- config uart1 -----------------------------
void config_uart1(u32 baudrate)
{ 
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //tx
  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
  GPIO_InitStructure.GPIO_OType =GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//rx
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	 
	 GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
   GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	USART_InitStructure.USART_BaudRate = baudrate;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

 
   USART_Init(USART1,&USART_InitStructure);
	 
	  	/* Enable the USART Rx DMA request */                
//  USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);

//	/* Clear the rx bit in the SR register by writing 0 to it */
  USART_ClearFlag(USART1, USART_FLAG_RXNE);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
 
  
	  USART_Cmd(USART1, ENABLE);
		Config_int_uart1_rx();
 }
//------------------------------ send uart1 ------------------------
void putchar1(u8 ch)
{
  USART_SendData(USART1, (uint8_t) ch);
 	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET){}       
}

//------------------------------ read uart1 ------------------------
u8 Read_uart1()
{
 	while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET){} 
  return USART1->DR;    
}

//-------------------------------- start compass -----------------------------------------
void run_read_gyro_uart1(void)
{ 
	u32 i;
  en_gyro=0;
  for(i=0;i<2;i++)
  {
		putchar1('a');
		delay_ms(200);
  }
  en_gyro=1;
  data_tx_gyro='z';
}
//--------------------------------- read encoder 2 or 3 -----------------------------
//vs32 Read_encoder(TIM_TypeDef* TIMx, char stt)
s32 Read_encoder(u8 stt)
{
	if(stt==2) 			return (num_over_t2<<16)|TIM_GetCounter(TIM2);
	else if(stt==3) return (num_over_t3<<16)|TIM_GetCounter(TIM3);
	else return 0;
}

//-------------------------------------------------------------------------------------------------
s32 Encoder_doc(void)
{
	return (num_over_t2<<16)|TIM_GetCounter(TIM2);
}

//-------------------------------------------------------------------------------------------------
s32 Encoder_ngang(void)
{
	return (num_over_t3<<16)|TIM_GetCounter(TIM3);
}

//-----------------------------------------------------------------------------------
void Vputchar(u8 ch)
{
	USART_SendData(UART4, (uint8_t) ch);
 	while (USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET){}
}

void Vputchar1(char ch)
{
	USART_SendData(USART1, (uint8_t) ch);
 	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET){}
}


void Vprintf(u8 *p)
{
	while(*p)
	{
		Vputchar(*p++);
	}
}

void Vprintf1(char *p)
{
	while(*p)
	{
		Vputchar1(*p++);
	}
}

//------------------------------------ FUNCTION ----------------------------------------

//--------------------------- reset encoder doc -------------------------
void Reset_encoder_doc(void)
{
	TIM2->CNT = 0;
	num_over_t2 = 0;
}

//--------------------------- reset encoder ngang -----------------------
void Reset_encoder_ngang(void)
{
	TIM3->CNT = 0;
	num_over_t3 = 0;	
}



