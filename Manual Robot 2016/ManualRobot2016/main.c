/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "lcd.h"
#include <stdio.h>
#include <math.h>
#include "initAlaBoard.h"
#include "main.h"
#include "gamepad.h"
#include "ControlerWheel.h"
//#include "SensorDetect.h"
#include "AutoRun.h"
#include <stdlib.h>


/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */
unsigned char GP_BTN [6];
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

__IO uint32_t systic_time=0;
s16 data_gyro , temp = 0;
u32 en_gyro;
u8	_lcd;
u8 data_tx_gyro;

u32 receiver_ok=0, i =0;
unsigned char lcd_buffer[33];
char dataUsart3;
u8 ACC;
unsigned char arr[16], giu = 35;
float angle;
char rxUsart3;
char autoRun, qt, tang_toc = 0;
vu32 pwm = 0, enableADC=0, dataADC=0;
u32 CN=1000;
u8 van=0, van1 = 0, van2 = 0, van3 = 0, van4 = 0;
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
void delay_ms(__IO uint32_t num)
{
	__IO uint32_t index = 0;
	
	for(index = (8000 * num); index != 0; index--)
	{
	}
}
void delay_us(__IO uint32_t num)
{
	__IO uint32_t index = 0;
	
	for(index = (8 * num); index != 0; index--)
	{
	}
}
void TIM6_IRQHandler(void)
{
	static unsigned char sl_t0 = 0;
	TIM6->SR = (uint16_t)~TIM_IT_Update; // xoa co ngat timer 2
	
		time_out++;  
	
		if(sl_t0++ > ACC)
		{
				sl_t0=0;
				
			      if(speed < td_sau) speed++;  
               else if(speed > td_sau) speed--;
//				if(bit_e_speed)
//          {
//             if(bit_tang_toc)
//                  {
//                    if(++speed >= td_sau) bit_e_speed=0;  
//                  }
//              else
//                  if(--speed <= td_sau) bit_e_speed=0;
//					}
		}
}
void TIM6_IRQHand(void)
{
	TIM6->SR = (uint16_t)~TIM_IT_Update; // xoa co ngat timer 2
	if(enableADC)
		{
			dataADC = ReadADC(ADC1,ADC_Channel_5);
		}
}
void printString (char row, char column, int temp)
{
 	 lcd_GotoXY(row,column);
   printf("%i",temp);
	printf(" ");
}
void printBit (char row, char column, int temp)
{
	 lcd_GotoXY(row,column);
   printf("%i",temp);
}

void activeIMU (void)
{
	u32 i;
	for(i=0;i<2;i++)
		{
			putchar2('a');  // set IMU is zero
			//data_tx_gyro='a';
			delay_ms(100);		
		}
	en_gyro=1;
  data_tx_gyro='z';
}
void resetIMU (void)
{
		putchar2('a');
	delay_ms(100);
}
void lcdViewer (void)
{		
		
		printString(0,13,ReadADC(ADC1,ADC_Channel_4));
		printString(1,0,encoderDoc());
		printString(1,15,data_gyro);
		printString(3,10,encoderSau());
	
		printString(0,4,b0);
		printString(0,5,b1);
		printString(0,6,b2);
		printString(0,7,b3);
		printString(0,8,b4);
		printString(0,9,b5);
		printString(0,10,b6);
		printString(0,11,b7);
	
		printString(2,3,cam_bien);
		printString(2,4,CB);
		printString(2,5,CB_trai);
		printString(2,6,CB_phai);
		printString(2,7,CB_truoc_phai);
		printString(2,8,CB_truoc_trai);
	
		printString(3,3,ct_tren);
		printString(3,4,ct_duoi);
		printString(3,5,ct_cot_tren_trai);
		printString(3,6,ct_cot_tren);
		printString(3,7,ct_cot_duoi);
		printString(3,8,kho_mau);
		
		lcd_GotoXY(1,12);
		printf("LB:");
		
		lcd_GotoXY(2,0);
		printf("CB:");
		
		lcd_GotoXY(3,0);
		printf("HT:");
}
void testquat(void) 
{

	pwm = 0;
	delay_ms(100);
	pwm = 270;
	while(1)
 	{	
		
		pwm++;	
		mor_quat = pwm;
		printString(1,4,pwm);
		delay_ms(10);
		if(pwm>310) break;	
			
	}
	delay_ms(50);
	mor_quat = 280;
}

//void giucot(void)
//{	
//	kepcot_off;	
//	setcot(20,20);
//}

void ganquat_do(void)
{	

	truot(-90);
	delay_ms(100);
	for(i=0;i<5000;i++){
	while(CB);}
	thoi_off;
	truot(-10);
	delay_ms(140);
	truot(0);
	nang(-150);
	delay_ms(100);
	taygap_on;
	setcot(-40,-40);
	delay_ms(200);
	thoi_on;
	
	nang(2);

	setcot(-80,-80);
	
	delay_ms(800);
	
	while(1)
		
	{setcot(0,0);}
}
void ganquat_xanh(void)
{	

	truot(90);
	delay_ms(100);
	for(i=0;i<5000;i++){
	while(CB);}
	thoi_off;
	setcot(0,0);
	truot(10);
	delay_ms(140);
	truot(0);
	
	nang(-150);
	delay_ms(100);
	taygap_on;
	setcot(-40,-40);
	delay_ms(200);
	thoi_on;
	
	nang(2);

	setcot(-80,-80);
	delay_ms(800);
	
	
	
	while(1)
	{setcot(0,0);}

}
void leocot(int pwmt,int pwmp)
{			
		setcot(pwmt,pwmp);
		

	
				nang(130);
				truot_CB();
				for(i=0;i<50000;i++)
				{
				while(ct_tren);
				}
				nang(3);
				while(1)
				{
						setcot(255,255);
						if(!CB_trai | !CB_phai) 
						{
								setcot(160,160);
							for(i=0;i<50000;i++)
							{
								while(ct_cot_tren && ct_cot_tren_trai);	
							}
								
										setcot(-50,-50);
										delay_ms(100);
										setcot(0,0);
										delay_ms(50);
										setcot(180,180);			
							for(i=0;i<50000;i++)
							{
								while(ct_cot_tren || ct_cot_tren_trai)	;
							}	
										setcot(50,50);
										if(!Switch)	
										{	
											ganquat_xanh();
										}
										else if(Switch) 
										{
											ganquat_do();
										}			
									}
									}
						//else setcot(255,255);
				
}

void test_cot (void)
{
	lcd_GotoXY(3,10);
		printf("Xn");	
	for(i=0;i<5000;i++){
	while(ADC_Channel_4<300);}
	
	lcd_GotoXY(3,14);
		printf("Xn");		
	
	
}

//---------------------------------vao cot --------------------
//void vaocot(int e, int w, int z)
//{
//		
//		resetencoderSau();
//		while(abs(encoderSau()) < e)
//			{  
//				tocdochay(100,100);
//				kepcot_on;
//				Quet_cam_bien();
//				DK_do_duong_thang();
//			}
//			resetencoderSau();
//		while(abs(encoderSau()) < w)
//			{  
//				tocdochay(130,130);				
//				Quet_cam_bien();
//				DK_do_duong_thang();
//				
//			}
//			resetencoderSau();
//		while(abs(encoderSau()) < z)
//			{  
//				tocdochay(40,40);
//				Quet_cam_bien();
//			  DK_do_duong_thang();
//				if(!cam_bien) break;
//			}	
//				nangline_on;
//				taygap_on;
//				
//				TD_trai(26), TD_phai(30), TD_truoc(2);
//				while(ct_cot_duoi);
//				kepcot_off;
//				taygap_off;
//				nang(150);
//				delay_ms(300);
//				nang(3);
//				leocot(255,255);
//				if(Switch)	ganquat_do();
//				
//					
//				else if(!Switch)	ganquat_xanh();
//				
//			
//}

/*======================= RETRY ========================*/

void retry_do (void)
{
			TD_truoc(30), TD_phai(30), TD_trai(40);
	
			resetEncoderDoc();
	ACC=20;
	tocdochay(20,50);
	
		while(abs(encoderDoc()) < 21400)
			{  
				
				Quet_cam_bien();
				DK_do_duong_cot_do();
				//kepcot_on;	
				truot(130);
			}
			ACC=10;
			td_sau = 200;
			quat(280);			
			//tocdochay(80,200);	
			resetEncoderDoc();			
			while(abs(encoderDoc()) < 100000)
			{ 								
				Quet_cam_bien();
				DK_do_duong_cot_do();
				
				truot(0);
			}			
			resetEncoderDoc();
			td_sau = 200;
			//tocdochay(200,200);			
		while(abs(encoderDoc()) < 250000)
			{  				
				Quet_cam_bien();
				DK_do_duong_cot_do();
				truot(0);
				nang(-120);
			}
			resetEncoderDoc();
			//tocdochay(200,150);
		td_sau = 180;	
		while(abs(encoderDoc()) < 50000)
			{  				
				Quet_cam_bien();
				DK_do_duong_cot_do();
				nang(-80);
				truot(0);
			}
			resetEncoderDoc();
			//stopRobot(2);
			//while(1);
			ACC=0;
			td_sau = 90;
			//tocdochay(150,130);
		while(abs(encoderDoc()) < 1000000)
			{  
				
				Quet_cam_bien();
				DK_do_duong_san_do_cham();
				truot(80);
				nang(0);
				if(cam_bien) break;
			}
			truot(0);
			
			nangline_on;
			taygap_on;
			kepcot_on;
			
			TD_trai(60), TD_phai(60), TD_truoc(2);		
			
			
			
			for(i=0;i<5000;i++){	
			while(ct_cot_duoi);}
			stopRobot(0);
	
			taygap_off;
			kepcot_off;
			nang(250);
			delay_ms(400);
			nang(3);
			delay_ms(500);
			leocot(255,255);
			
	
	
}
void retry_xanh (void)
{
	
	TD_truoc(2), TD_phai(30), TD_trai(30);
	delay_ms(1000);
	resetEncoderDoc();
	while(abs(encoderDoc()) < 100000)
	{
		nang(120);
		TD_truoc(-10), TD_phai(60), TD_trai(50);
		if(!b3) break;
	}
	
	stopRobot(2);
	while(1);
	resetEncoderDoc();
	ACC = 40;
	tocdochay(20,50);
	
		while(abs(encoderDoc()) < 21400)
			{  
				
				Quet_cam_bien();
				DK_do_duong_san_xanh();
				
				truot(-130);
			}
			quat(280);
				ACC=10;
			td_sau = 200;
			//tocdochay(60,250);	
			resetEncoderDoc();			
			while(abs(encoderDoc()) < 100000)
			{ 								
				Quet_cam_bien();
				DK_do_duong_san_xanh();
				
				truot(0);
			}			
			resetEncoderDoc();
			td_sau = 200;
			//tocdochay(200,200);			
		while(abs(encoderDoc()) < 250000)
			{  				
				Quet_cam_bien();
				DK_do_duong_san_xanh();
				truot(0);
				nang(-120);
			}
			resetEncoderDoc();
			ACC=2;
			td_sau = 180;
			//tocdochay(200,140);
			
		while(abs(encoderDoc()) < 50000)
			{  				
				Quet_cam_bien();
				DK_do_duong_san_xanh();
				nang(-80);
				truot(0);
			}
			resetEncoderDoc();
			//stopRobot(2);
			//while(1);
			ACC=0;
			td_sau = 90;
		while(abs(encoderDoc()) < 1000000)
			{  
				
				Quet_cam_bien();
				DK_do_duong_san_xanh_cham();
				truot(-80);
				nang(0);
				if(cam_bien) break;
			}
			truot(0);
			
			nangline_on;
			taygap_on;
			kepcot_on;
			
			TD_trai(60), TD_phai(60), TD_truoc(2);		
			
			
			
			for(i=0;i<5000;i++){	
			while(ct_cot_duoi);}
			stopRobot(0);
	
			taygap_off;
			kepcot_off;
			nang(250);
			delay_ms(400);
			nang(3);
			delay_ms(500);
			leocot(255,255);
	
}
void retry_gap_quat_xuat_phat (void)
{
				
				
				
				if(!Switch)	retry_xanh();
			
				//if(Switch)	retry_do();
			
}
//--------------------------------retry 90 -------------------------------
void retry_90_xanh (void)
{
	truot(-130);
	stopRobot(2);
	TD_truoc(-30 ); TD_phai(-30); TD_trai(30);
	quat(330);
	while(b3);
	stopRobot(2);
	kepnang_on;
	
	truot(-120);
	quat(350);
	delay_ms(500);
					
	tocdo_line(15,30);
	resetEncoderDoc();
	while(abs(encoderDoc())<20071)
	{
		Quet_cam_bien();
		DK_do_duong_do();
		quat(365);
						
	}	
	quat(450);				
	delay_ms(50);
				
	chay_vao_cot_xanh();
	taygap_off;
	kepcot_off;
	nang(250);
	delay_ms(400);
	nang(3);
	delay_ms(500);
	leocot(255,255);
}
void retry_90_do(void)
{
	truot(130);
	stopRobot(2);
	TD_truoc(30); TD_phai(30); TD_trai(-30);
	while(b4);
	stopRobot(2);
	quat(335);
	
	kepnang_on;
	
				resetencoderSau();
					tocdo_line(0,20);
				while(abs(encoderSau())<200)	
				{
					Quet_cam_bien();
					DK_do_duong_do();
					quat(325);
				}
	quat(335);
	delay_ms(800);
	quat(340);
	tocdo_line(20,40);
	resetEncoderDoc();
	while(abs(encoderDoc())<20071)
	{
		Quet_cam_bien();
		DK_do_duong_do();
		quat(340);						
	}	
	quat(450);				
	delay_ms(50);
	
	chay_vao_cot_do();
	taygap_off;
	kepcot_off;
	nang(250);
	delay_ms(400);
	nang(3);
	delay_ms(500);
	leocot(255,255);
	//ganquat_do();		
	
}
void retry_90 (void)
{
	resetIMU();
	resetEncoderDoc();
	tocdo_line(15,120);	
	while(abs(encoderDoc())<40000)					
				{				
					
					Update_imu();
					DK_do_duong_imu();
					nang(80);
								
				}
				tocdo_line(180,230);
			resetEncoderDoc();
	while(abs(encoderDoc())<220000)					
				{				
						
					Update_imu();
					DK_do_duong_imu();
					nang(120);							
				}
				
				tocdo_line(230,130);
			resetEncoderDoc();
	while(abs(encoderDoc())<100000)					
				{				
						
					Update_imu();
					DK_do_duong_imu();
											
				}
				TD_truoc(2); TD_phai(80); TD_trai(80);
				
				while(b3 && b2 && b4 && b5 && b6); //11165
				resetencoderSau();
					tocdo_line(80,70);
				while(abs(encoderSau())<250)	
				{
					Update_imu();
					DK_do_duong_imu();
					quat(325);
				}
				stopRobot(2);
				delay_ms(500);
				kepnang_off;
				
				
				
				if(!Switch) retry_90_xanh();
				if(Switch) retry_90_do();
}
/*=======================  DIEU KHIEN TU DONG SAN DO  =======================*/  
void san_do (void)
{
	
	xuatphat_do();
	vungdoi_do();
	chay_vao_cot_do();
	taygap_off;
	kepcot_off;
	nang(255);
	delay_ms(350);
	nang(3);
	
	leocot(255,255);
		 
}
void san_xanh (void)
{	
	xuatphat_xanh();
	vungdoi_xanh();
	chay_vao_cot_xanh();
	taygap_off;
	kepcot_off;
	nang(255);
	delay_ms(350);
	nang(3);
	//delay_ms(1000);
	leocot(255,255);

}
void chay_tu_dong (void)
{
	
	
		if(!Switch)	
		{	
			san_xanh();
		
		}
		else if(Switch) 
		{
			san_do();	
		}
}


/*=================================== code nhanh ===============================*/
void san_do_nhanh (void)
{
	
	xuatphat_do();
	vungdoi_do_nhanh();
	chay_vao_cot_do();
	taygap_off;
	kepcot_off;
	nang(250);
	delay_ms(350);
	nang(3);
	
	leocot(255,255);
		 
}
void san_xanh_nhanh (void)
{	
	xuatphat_xanh();
	vungdoi_xanh_nhanh();
	chay_vao_cot_xanh_nhanh();
	taygap_off;
	kepcot_off;
	nang(255);
	delay_ms(350);
	nang(3);
	leocot(255,255);

}
void chay_tu_dong_nhanh (void)
{
	
	
		if(!Switch)	
		{	
			san_xanh_nhanh();
		
		}
		else if(Switch) 
		{
			san_do_nhanh();	
		}
}


void leo_cot_xanh (void)
{
	leocot(255,255);
	ganquat_xanh();
}
void leo_cot_do (void)
{
	leocot(255,255);
	ganquat_do();
}
void leo_cot (void)
{
	if(!Switch)	
	{	
		leo_cot_xanh();
	}
	else if(Switch) 
	{
		leo_cot_do();
	}			
}


/*=======================  CHUONG TRINH DIEU KHIEN  =======================*/

void dieukhien (void)
{
	//------------------------------- test silanh -------------------------//
	if(!L2 && !SELECT && START ) kepnang_off;
	else if(!L2 && SELECT && !START ) kepnang_on;
	if(L2 && !SELECT && START )	leocot(255,255);//leo_cot();										// retry tai tru
	
	if(L2 && SELECT && !START ) 									//start
	{
		quat(310);
		delay_ms(100);
		quat(280);
		while(kho_mau);
		retry_gap_quat_xuat_phat();	   
	}
	 if(!L2 && !R1 && R2)		kepcot_off;	// kep cot	
	
	else if(!L2 && !R2 && R1)		kepcot_on;	//
//	else if(L2 && !R2 && R1)		vaocot(500,4500,2300);			//  r2 vao tru 
	else if(L2 && R2 && !R1)
	{
		quat(310);
		delay_ms(100);
		quat(280);
		while(kho_mau);
		retry_90();
	}		// r1 retry 90
	
	else if(!L2 && !O && X && TAMGIAC && VUONG)		nangline_off;		
	
	else if(!L2 && !X && O && TAMGIAC && VUONG)		nangline_on;		
	
	else if(!L2 && !TAMGIAC && O && X && VUONG)			taygap_off; 	
	else if(!L2 && TAMGIAC && O && X && !VUONG)			taygap_on;
	else if(!L2 && RJOY_UD < 64)										kepthoi_off;
	else if(!L2 && RJOY_UD > 192)										kepthoi_on;
	
	//---------------------------------- test dong co ---------------------------------//
	else if(L2 && !TAMGIAC && O && X && VUONG) setcot(150,150);
	else if(L2 && TAMGIAC && O && X && !VUONG) //thoi_off;//setcot(-50,-50);
	{
		kepnang_off;
		while(kho_mau);
		chay_tu_dong_nhanh();
	}
	else if(L2 && TAMGIAC && !O && X && VUONG)	testquat() ;
	else if(L2 && TAMGIAC && O && !X && VUONG)	
	{	
		kepnang_off;
		while(kho_mau);
		chay_tu_dong();
	}
	else if(L2 && RJOY_UD < 64)				 nang(100);
	else if(L2 && RJOY_UD > 192)				nang(-100);
	
	else if(L2 && RJOY_LR < 64) truot(-100);					// trai
	else if(L2 && RJOY_LR >192) truot(100);  				// truot phai
	
	else 
	{
		setcot(0,0);
		truot(2);
		nang(3);
	}
}


//////////////////////////////////////////////////////////////////////
////////////////////// CHUONG TRINH CHINH ////////////////////////////
//////////////////////////////////////////////////////////////////////
int main(void)
{
	vu8 pwm = 0;
	
	if (SysTick_Config(SystemCoreClock / 1000))	{ while (1);} 	// NGAT SYSTICK LAY MAU IMU

	configInOutPort();
	gamepad_Init();	

	config_TIM1_PWM();
	config_TIM8_PWM();
	
	config_TIM4_PWM();

	config_TIM3_encoder();
	config_TIM5_encoder();
	
	config_TIM6();

	configUart2(115200);
	config_DMA_Usart2();

	//adc_config_A45();
	Config_ADC();
	activeIMU();
	
	lcd_Init();
	lcd_Clear();

	if(!Switch)		
	{
		lcd_GotoXY(0,0);
		printf("XN");	
	}
	
	else if (Switch)		
	{
		lcd_GotoXY(0,0);
		printf("DO");	
	}
	
	//autoRun = 0;	
	//qt=0;
	
while (1)
  {	
	lcdViewer();
		while(gp_get_mode() == GP_MODE_ANALOGUE_RED_LED)
		{
			gp_update_btn();
			//if(cam_bien) {nangline_on;}
			robotGamePadControl();
			dieukhien();
			lcdViewer();
			//test_cot();
			quat(280);
			//nangline_on;
			//CB_quat_nhe();
			}
			
	}
}
/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */

/**
  * @brief  Configure the TIM3 Ouput Channels.
  * @param  None
  * @retval None
  */

PUTCHAR_PROTOTYPE
{
	/* Place your implementation of fputc here */
	/* e.g. write a character to the USART */
	//USART_SendData(USART1, (uint8_t) ch);
	lcd_Data_Write((u8)ch);
	/* Loop until the end of transmission */
	//while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
	//{}
	return ch;
};

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
