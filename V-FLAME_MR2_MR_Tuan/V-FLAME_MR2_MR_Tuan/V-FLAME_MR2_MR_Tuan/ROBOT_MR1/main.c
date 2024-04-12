//#include "cmsis_os.h"


// 19h42 18 03 2023

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "LID_HMI.h"
#include "config.h"
#include "doc_tay_game.h"
#include "4OmniControler.h"
#include "FreeRTOS.h"
#include "task.h"

#include "DieuKhienCoCau.h"
//#include "ROBOTRUN.h"
#include "BasicFunction.h"
#include "San_Xanh.h"
#include "San_Do.h"

char Home;

static void taskGyro(void *pvParameters)
{	
  while(1) 
  { 
	//---- gui tin hieu de lay gia tri la ban -----------
		HMI_RUN_LOOP(17);
		vTaskDelay(15);
  }
}
static void taskDieuKhienCoCau(void *pvParameters)
{	
	  while(1) 
	  {
		test_truc_XYZ();
		giu_TrucY();
			if(Home == 1)
			{
				giu_Mam_Xoay();
				giu_TrucX();
				
			}
			
		ADCValue_Control();
		vTaskDelay(5);
	  }
}

static void taskRobotAnalytics(void *pvParameters)
{	
	while(1) 
	{
		
    robotAnalytics();
		vTaskDelay(5);
	}
}
static void taskMain(void *pvParameters)
{
	Config_out_mode();//khai báo ngo ra cua mot chan bat ky	
	Config_in_mode();//khai bao ngo vào cua mot chan bat ky
	
	Config_pwm_time_t8();//cai dat timer8 o che do dieu xung
	Config_pwm_time_t4();//cai dat timer4 o che do dieu xung
	Config_pwm_time_t5();//cai dat timer9 o che do RC SEVOR	
	
	Config_encoder_timer2_timer3();//doc encoder  timer 2, timer 3, timer 5 ,timer 9
	Config_encoder_timer1();
	Config_encoder_timer4();
	//Config_encoder_timer5();
	
//	Init_I2C2();
//	Init_PCA9685();
	
	//Config_encoder_timer5();
	//ngat_ngoai();			//chuyên dung de doc sieu am ket hop timer7, hoac co the dung lam nut nhân
	Config_ADC1_DMA();		//su dung  khi doc tin hieu laze hay cac tín hieu ADC<3,3v	
	//Config_int_time6();		//phuc vu cho chuong trinh hoat dong song song voi he thong v?i chu ky 1ms
	Config_int_time7();		//su dung de doc sieu am, tang giam bien, chông nhieu, và các chuong trình hoat dong khong song song voi he thong
	UART1_DMA_RX(115200);	//usart giao tiep voi laban
	UART2_DMA_TX(115200);///DIEU KHIEN DONG CO
	UART3_DMA_RX(115200);	//usart giao tiep de doc gamepad
	UART4_DMA_RX(115200);	//SU DUNG DE GIAO TIEP MACH DO LAI
	UART5_DMA_TX(921600);	//GIAO TIEP MAN HINH HMI
	//if (SysTick_Config(SystemCoreClock / 1000))while (1);// 1ms truyen du lieu usart den cac slever
	
	//reset lai laban
	
	
		
		robotResetIMU();
		RESET_ENCODER();	
	//	Reset_nang_vong()
		Vi_tri = 0;
	//---- reset he thong ve vi tri ban dau 

	//-----------------------------------
	xTaskCreate(taskRobotAnalytics, (signed char*)"taskRobotAnalytics", 256, NULL, 0, NULL);
	xTaskCreate(taskDieuKhienCoCau, (signed char*)"taskDieuKhienCoCau", 256, NULL, 0, NULL);
	
	
		taget_BT_trucY = Max_BT_trucY;
		
		while(BienTroTrucYValue < taget_BT_trucY - 20) vTaskDelay(5);
		Home = 1;
		
		taget_BT_mam_xoay = Max_BT_mam_xoay;
		taget_BT_trucX = taget_BT_trucX;
//	void gp_update_uart ();
		
	while(1)//(gp_get_mode()  == GP_MODE_ANALOGUE_RED_LED)
	{
//		if(!NUT_RUN_RB  && NUT_CHUYEN_SAN == 0) XUAT_PHAT_SAN_XANH();
//		else if(!NUT_RUN_RB  && NUT_CHUYEN_SAN == 1) XUAT_PHAT_SAN_DO();
		
	}
}

int main(void)	
{

	xTaskCreate(taskMain, (signed char*)"taskMain", 256, NULL,0, NULL);	
	xTaskCreate(taskGyro,(signed char*)"taskGyro", 256, NULL,0, NULL);	
	
	vTaskStartScheduler();// lenh nay cho phep cac tac vu da nhiem hoat dong.
}


