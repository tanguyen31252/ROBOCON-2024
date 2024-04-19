/*-------------------------------Init main board ALA-SIMBA------------------------------------------
----------------------------------STM32F103VCT6 - 100LQFP-------------------------------------------
---------
--------------------------------25/12/2013/------------------------------------------------
--------------------------------------------------------------------------------------------------*/

#include "stm32f10x.h"


//------------------------ KHAI BAO DONG CO ---------------------

#define mor_truot	 								TIM1->CCR1									//pwm 1
#define mor_truot_next						GPIOA->BRR = GPIO_Pin_12	
#define mor_truot_back						GPIOA->BSRR = GPIO_Pin_12

#define mor_leotrai	 							TIM1->CCR2									//pwm 2
#define mor_leotrai_next					GPIOC->BRR = GPIO_Pin_0		
#define mor_leotrai_back					GPIOC->BSRR = GPIO_Pin_0

#define mor_leophai	 							TIM1->CCR3								// pwm 3
#define mor_leophai_next					GPIOC->BRR = GPIO_Pin_1	
#define mor_leophai_back					GPIOC->BSRR = GPIO_Pin_1

#define mor_truotngang	 					TIM1->CCR4							// pwm 4
#define mor_truotngang_next				GPIOC->BRR = GPIO_Pin_2	
#define mor_truotngang_back				GPIOC->BSRR = GPIO_Pin_2

#define mor_quat	 								TIM4->CCR2			// uart2	

#define mor_phaitruoc	 						TIM8->CCR1											// pwm 5
#define mor_phaitruoc_back				GPIOC->BRR = GPIO_Pin_3		
#define mor_phaitruoc_next				GPIOC->BSRR = GPIO_Pin_3				

#define mor_phaisau	 							TIM8->CCR2											// pwm 6
#define mor_phaisau_back					GPIOC->BRR = GPIO_Pin_4		
#define mor_phaisau_next					GPIOC->BSRR = GPIO_Pin_4						

#define mor_traisau	 							TIM8->CCR3											// pwm 7
#define mor_traisau_next					GPIOB->BRR = GPIO_Pin_5     
#define mor_traisau_back					GPIOB->BSRR = GPIO_Pin_5 

#define mor_traitruoc	 						TIM8->CCR4											// pwm 8
#define mor_traitruoc_next				GPIOC->BSRR = GPIO_Pin_12			
#define mor_traitruoc_back				GPIOC->BRR = GPIO_Pin_12					



//---------------- CAM BIEN DO LINE -------------------------// I1

#define b0									GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)
#define b1									GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)
#define b2									GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)
#define b3									GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)
#define b4									GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)
#define b5									GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
#define b6									GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define b7									GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)

//-------------------- CONG TAC CHUYEN SAN  ------------------

#define Switch				GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_1)

//-------------------- CONG TAC HANH TRINH  	------------------ O2
#define ct_tren									GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15)							//DC nang
#define ct_duoi									GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5)
#define ct_cot_tren							GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14)							// HT cot gan quat
#define ct_cot_duoi							GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)
#define ct_cot_tren_trai				GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15)
#define kho_mau									GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_11)



#define cam_bien				 		GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_8)
#define CB				 			 		GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_14)
#define CB_trai				 			GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_12)
#define CB_phai				 			GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_13)
#define CB_truoc_phai				GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_11)
#define CB_truoc_trai				GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_10)
#define CB_quat							GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_9)


//-------------------- XY LANH  ------------------ O1
#define kepcot_on					GPIOE->BRR = GPIO_Pin_5		
#define kepcot_off					GPIOE->BSRR = GPIO_Pin_5	

#define nangline_on					GPIOE->BRR = GPIO_Pin_4		
#define nangline_off 				GPIOE->BSRR = GPIO_Pin_4

#define kepnang_on					GPIOE->BSRR = GPIO_Pin_6			
#define kepnang_off					GPIOE->BRR = GPIO_Pin_6

#define taygap_on						GPIOE->BRR = GPIO_Pin_7	
#define taygap_off					GPIOE->BSRR = GPIO_Pin_7

#define kepthoi_on					GPIOE->BSRR = GPIO_Pin_3			
#define kepthoi_off					GPIOE->BRR = GPIO_Pin_3

#define thoi_on					GPIOE->BSRR = GPIO_Pin_2			
#define thoi_off					GPIOE->BRR = GPIO_Pin_2


//************************************************************
// --------------------------------------------------------
vu32 num_over_t3 = 0,num_over_t4 = 0, num_over_t5 = 0;
char mang[2];

// --------------------------------------------------------
 
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;

GPIO_InitTypeDef GPIO_InitStructure;
DMA_InitTypeDef DMA_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
ADC_InitTypeDef ADC_InitStructure;
//---------------------------------------------------------

void configInOutPort(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE);
	GPIO_InitStructure.GPIO_Pin = 0xffff;//GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_10|GPIO_Pin_11; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_Write(GPIOA, 0xffff);
	GPIO_Write(GPIOB, 0xffff);
	GPIO_Write(GPIOC, 0xffff);
	GPIO_Write(GPIOD, 0xffff);
	GPIO_Write(GPIOE, 0xffff);
	
//	GPIO_InitStructure.GPIO_Pin = 0xffff;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	/*------------------------------xi lanh ----------------------*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7| GPIO_Pin_6| GPIO_Pin_5|GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	/*---------------------- CTHT -----------------------*/
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_11 |GPIO_Pin_15 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_2 ; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
//----------------------------------- CB --------------------------------//
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8 | GPIO_Pin_14 |GPIO_Pin_13 |GPIO_Pin_12 |GPIO_Pin_11 |GPIO_Pin_10 |GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_1 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}


//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//---------------------- config TIM1 PWM ---------------------------------------------------

void config_TIM1_PWM(void)
{
  /* TIM1 clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

  /* GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);

  /* GPIOA Configuration:TIM1 Channel1, 2, 3 and 4 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 255;
  TIM_TimeBaseStructure.TIM_Prescaler = 1900;  // 1900 for board driver cu
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

  /* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM1, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel2 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC2Init(TIM1, &TIM_OCInitStructure);

  TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel3 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC3Init(TIM1, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel4 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC4Init(TIM1, &TIM_OCInitStructure);

  TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM1, ENABLE);

  /* TIM1 Main Output Enable */
  TIM_CtrlPWMOutputs(TIM1, ENABLE);
  /* TIM3 enable counter */
  TIM_Cmd(TIM1, ENABLE);
}

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//---------------------- config TIM8 PWM ---------------------------------------------------

void config_TIM8_PWM (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* TIM8 clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);

	/* Enable GPIOC clocks */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO, ENABLE);	
	
	/* Configuration PC.6, PC.7, PC.8, PC.9 pin:TIM8 as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 255;
	TIM_TimeBaseStructure.TIM_Prescaler = 150;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);

	/* PWM1 Mode configuration: Channel2 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	
  TIM_OC1Init(TIM8, &TIM_OCInitStructure);
	TIM_OC2Init(TIM8, &TIM_OCInitStructure);
 	TIM_OC3Init(TIM8, &TIM_OCInitStructure);
 	TIM_OC4Init(TIM8, &TIM_OCInitStructure);
	
	TIM_ARRPreloadConfig (TIM8, ENABLE);
	TIM_CtrlPWMOutputs (TIM8, ENABLE);
	/* TIM8 enable counter */
	TIM_Cmd(TIM8, ENABLE);
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//---------------------- config TIM5 PWM ---------------------------------------------------

//void config_TIM2_PWM(void)
//{
//  NVIC_InitTypeDef NVIC_InitStructure;
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO, ENABLE);

//  /* GPIOA Configuration:TIM1 Channel1, 2, 3 and 4 as alternate function push-pull */
//  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14 ;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

//  GPIO_Init(GPIOD, &GPIO_InitStructure);
//	
//  /* Time base configuration */
//  TIM_TimeBaseStructure.TIM_Period = 4799;
//  TIM_TimeBaseStructure.TIM_Prescaler = 299;  // 1900 for board driver cu
//  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
//  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

//  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

//  /* PWM1 Mode configuration: Channel1 */
//  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//  TIM_OCInitStructure.TIM_Pulse = 0;
//  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

//  TIM_OC1Init(TIM2, &TIM_OCInitStructure);

//  TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

//  /* PWM1 Mode configuration: Channel2 */
//  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//  TIM_OCInitStructure.TIM_Pulse = 0;

//  TIM_OC2Init(TIM2, &TIM_OCInitStructure);

//  TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

//  /* PWM1 Mode configuration: Channel3 */
//  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//  TIM_OCInitStructure.TIM_Pulse = 0;

//  TIM_OC3Init(TIM2, &TIM_OCInitStructure);

//  TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);

//  /* PWM1 Mode configuration: Channel4 */
//  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//  TIM_OCInitStructure.TIM_Pulse = 0;

//  TIM_OC4Init(TIM2, &TIM_OCInitStructure);

//  TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

//  TIM_ARRPreloadConfig(TIM2, ENABLE);

//  /* TIM1 Main Output Enable */
//  TIM_CtrlPWMOutputs(TIM2, ENABLE);
//  /* TIM3 enable counter */
//  TIM_Cmd(TIM2, ENABLE);
//}

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//---------------------- config TIM3 ENCODER ---------------------------------------------------

void config_TIM3_encoder(void)
{

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	
  /* Enable the TIM3 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	// khai bao ngo vao cho TIM3 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;// t3
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//GPIO_Mode_AF_PP; mode IPU is ok, Mode AF-PP no ok
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	   
    TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI1, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);
	 // note : TIM_EncoderMode_TI1 is x2, TIM_EncoderMode_TI12 is x4

    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
		
    TIM_Cmd(TIM3,ENABLE);
	
    TIM_SetCounter(TIM3, 0);		
}

sc32 readEncoder_t3 (void)
{
	vs32 temp = 0;
 	temp=(num_over_t3<<16)|TIM_GetCounter(TIM3);	
	return temp;
}

sc32 encoderSau (void)
{
	vs32 temp = 0;
 	temp =	readEncoder_t3();
	return temp;
}

void resetencoderSau (void)
{
		TIM3->CNT = 0;
		num_over_t3 = 0;
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//---------------------- config TIM8 ENCODER ---------------------------------------------------

void config_TIM4_PWM(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	
  /* GPIOA Configuration:TIM1 Channel1, 2, 3 and 4 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 4799;
  TIM_TimeBaseStructure.TIM_Prescaler = 299;  // 1900 for board driver cu
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

  /* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM4, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel2 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC2Init(TIM4, &TIM_OCInitStructure);

  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel3 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC3Init(TIM4, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel4 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC4Init(TIM4, &TIM_OCInitStructure);

  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM4, ENABLE);

  /* TIM1 Main Output Enable */
  TIM_CtrlPWMOutputs(TIM4, ENABLE);
  /* TIM3 enable counter */
  TIM_Cmd(TIM4, ENABLE);
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//---------------------- config TIM5 ENCODER ---------------------------------------------------


void config_TIM5_encoder(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	
  /* Enable the TIM5 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	// khai bao ngo vao cho TIM5 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;// t5
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//GPIO_Mode_AF_PP; mode IPU is ok, Mode AF-PP no ok
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	   
    TIM_EncoderInterfaceConfig(TIM5, TIM_EncoderMode_TI1, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);
	 // note : TIM_EncoderMode_TI1 is x2, TIM_EncoderMode_TI12 is x4

    TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
		
    TIM_Cmd(TIM5,ENABLE);
	
    TIM_SetCounter(TIM5, 0);		
}

vu32 readEncoder_t5 (void)
{
	vu32 temp = 0;
 	temp=(num_over_t5<<16)|TIM_GetCounter(TIM5);	
	return temp;
}

vu32 encoderDoc (void)
{
	vu32 temp = 0;
 	temp=readEncoder_t5();	
	return temp;
}

void resetEncoderDoc (void)
{
		TIM5->CNT = 0;
		num_over_t5 = 0;
}

void config_TIM6(void)
{   
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
  // time=36000000/(TIM_Period+1*TIM_Prescaler+1)
	
  TIM_TimeBaseStructure.TIM_Period = 35999;// 1ms
  TIM_TimeBaseStructure.TIM_Prescaler =0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
  
 //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

  
  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM6, ENABLE);  
	
}

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//---------------------- config USART 2 ---------------------------------------------------

void configUart2(u32 baudrate)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
	
	/* Enable UART clock, if using USART2 or USART3 ... we must use RCC_APB1PeriphClockCmd(RCC_APB1Periph_USARTx, ENABLE) */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE); 
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 
	/* Configure PA9 for USART Tx as alternate function push-pull */
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure PA10 for USART Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	/* USARTx configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  	*/
	USART_InitStructure.USART_BaudRate = baudrate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	

	/* USART configuration */
	USART_Init(USART2, &USART_InitStructure);

	/* Enable USART */
	USART_Cmd(USART2, ENABLE);	
	
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void config_DMA_Usart2(void)
{
   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
   /* DMA1 channel6 configuration ----------------------------------------------*/
  DMA_DeInit(DMA1_Channel6);// DMA1 CHANEL6 CHO USART2 
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&USART2->DR; //tu uart->portb
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&mang;//GPIOB->ODR;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_BufferSize = 2;//1;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; // ngoai vi ko tang
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//DMA_MemoryInc_Disable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;//DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel6, &DMA_InitStructure);
  
  /* Enable DMA1 channel6 */
  DMA_Cmd(DMA1_Channel6, ENABLE);
  
  /* Enable USART1 DMA */
  USART_DMACmd(USART2,USART_DMAReq_Rx, ENABLE);
  
  DMA_ITConfig(DMA1_Channel6,DMA_IT_TC,ENABLE);
  
  /* Configure the NVIC Preemption Priority Bits */  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
  
  /* Enable the USARTy Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel6_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 15;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


void putchar2(uint8_t ch)
{
   USART_SendData(USART2, (uint8_t) ch);
	/* Loop until the end of transmission */
	while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
		{}               
}

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//---------------------- config USART 3 ---------------------------------------------------

//void configUart3(u32 baudrate)
//{ 	
//	GPIO_InitTypeDef GPIO_InitStructure;
//	USART_InitTypeDef USART_InitStructure;
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
//	/* Enable UART clock, if using USART2 or USART3 ... */
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE); 


//	/* Configure PA9 for USART Tx as alternate function push-pull */
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);

//	/* Configure PA10 for USART Rx as input floating */
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);	
//	
//	/* USARTx configured as follow:
//        - BaudRate = 115200 baud  
//        - Word Length = 8 Bits
//        - One Stop Bit
//        - No parity
//        - Hardware flow control disabled (RTS and CTS signals)
//        - Receive and transmit enabled
//  	*/
//	USART_InitStructure.USART_BaudRate = baudrate;
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//	USART_InitStructure.USART_Parity = USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	

//	/* USART configuration */
//	USART_Init(USART3, &USART_InitStructure);
//	
//	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
//	/* Enable USART */
//	USART_Cmd(USART3, ENABLE);	
//	
//}

////xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//void config_DMA_Usart3(void)
//{
//   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
//	
//   /* DMA1 channel6 configuration ----------------------------------------------*/
//  DMA_DeInit(DMA1_Channel6);// DMA1 CHANEL6 CHO USART2 
//  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&USART3->DR; //tu uart->portb
//  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&mang;//GPIOB->ODR;
//  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
//  DMA_InitStructure.DMA_BufferSize = 2;//1;
//  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; // ngoai vi ko tang
//  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//DMA_MemoryInc_Disable;
//  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//DMA_PeripheralDataSize_HalfWord;
//  DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;//DMA_PeripheralDataSize_HalfWord;
//  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
//  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
//  DMA_Init(DMA1_Channel6, &DMA_InitStructure);
//  
//  /* Enable DMA1 channel6 */
//  DMA_Cmd(DMA1_Channel6, ENABLE);
//  
//  /* Enable USART1 DMA */
//  USART_DMACmd(USART3,USART_DMAReq_Rx, ENABLE);
//  
//  DMA_ITConfig(DMA1_Channel6,DMA_IT_TC,ENABLE);
//  
//  /* Configure the NVIC Preemption Priority Bits */  
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//  
//  /* Enable the USARTy Interrupt */
//  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel6_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 15;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
//}
//void putchar3(uint8_t ch)
//{
//   USART_SendData(USART3, (uint8_t) ch);
//	/* Loop until the end of transmission */
//	while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET)
//	{}               
//}

////------------- NGAT USART 3 ----------------------

//void NVIC_Configuration(void)
//{
//	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;

//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0xE;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);	
//}

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//---------------------- config USART 1 ---------------------------------------------------

void configUart1(u32 baudrate)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	/* Enable UART clock, if using USART2 or USART3 ... we must use RCC_APB1PeriphClockCmd(RCC_APB1Periph_USARTx, ENABLE) */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1, ENABLE); 

	/* Configure PA9 for USART Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure PA10 for USART Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	/* USARTx configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  	*/
	USART_InitStructure.USART_BaudRate = baudrate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	

	/* USART configuration */
	USART_Init(USART1, &USART_InitStructure);

	/* Enable USART */
	USART_Cmd(USART1, ENABLE);	
	
}

// khai bao ADC

void adc_config_A45 (void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	
// 	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 1, ADC_SampleTime_55Cycles5);
// 	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_55Cycles5);
	
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1);
  /* Check the end of ADC1 reset calibration register */
  while(ADC_GetResetCalibrationStatus(ADC1));
	
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	
}

unsigned int readADC(unsigned char stt)
{

	switch(stt)
	{
// 		case 0:	{ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5); break;}
// 		case 1:	{ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_55Cycles5); break;}
// 		case 2:	{ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_55Cycles5); break;}
// 		case 3:	{ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_55Cycles5); break;}
		case 4:	{ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 1, ADC_SampleTime_239Cycles5); break;}	
		case 5:	{ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_239Cycles5); break;}
	}

	return ADC_GetConversionValue(ADC1);
}


void Config_ADC(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	 /* ADCCLK = PCLK2/4 */
  RCC_ADCCLKConfig(RCC_PCLK2_Div8); 
	/* Enable ADC1 and GPIOA clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOC, ENABLE);	
  /* Configure PC.04 (ADC Channel14) as analog input -------------------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

   /* ADC1 configuration ------------------------------------------------------*/
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;//cho phep quet
  ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//trigger bang software
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//canh le
  ADC_InitStructure.ADC_NbrOfChannel = 1;
  ADC_Init(ADC1, &ADC_InitStructure);

  /* Enable ADC1 */
  ADC_Cmd(ADC1, ENABLE);//cho phep adc1

  /* Enable ADC1 reset calibration register */   
  ADC_ResetCalibration(ADC1);
  /* Check the end of ADC1 reset calibration register */
  while(ADC_GetResetCalibrationStatus(ADC1));

  /* Start ADC1 calibration */
  ADC_StartCalibration(ADC1);
  /* Check the end of ADC1 reset calibration register */
  while(ADC_GetResetCalibrationStatus(ADC1));
  	
}

uint16_t ReadADC(ADC_TypeDef* ADCx, uint8_t ADC_Channel)
{
	uint16_t val=0;
	ADC_RegularChannelConfig(ADCx, ADC_Channel, 1, ADC_SampleTime_239Cycles5);//tgian chuyen doi
	/* Start ADC1 Software Conversion */ 
  ADC_SoftwareStartConvCmd(ADCx, ENABLE);
  while( ADC_GetFlagStatus(ADCx,ADC_FLAG_EOC)==RESET);
  val= ADC_GetConversionValue(ADCx);//lay du lieu chuyen doi
  return val;	
}
/******************* (C) COPYRIGHT 2009 ARMVietNam *****END OF FILE****/



















