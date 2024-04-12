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

char Home = 0;


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
			ADCValue_Control();
			if(Home!=0){giu_Mam_Xoay(); Giu_Truc_X();}
			Giu_Truc_Y();
			vTaskDelay(5);
	  }
}

static void taskRobotAnalytics_uart(void *pvParameters)
{	
	while(1) 
	{
		TAM_X = GP_BTN[0];
		TAM_Y = GP_BTN[1];
		SILO_THA_BONG = GP_BTN[2];
		
		USART_SendSTRING();
		vTaskDelay(7);
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
	Config_out_mode();//khai b�o ngo ra cua mot chan bat ky	
	Config_in_mode();//khai bao ngo v�o cua mot chan bat ky
	
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
	//ngat_ngoai();			//chuy�n dung de doc sieu am ket hop timer7, hoac co the dung lam nut nh�n
	Config_ADC1_DMA();		//su dung  khi doc tin hieu laze hay cac t�n hieu ADC<3,3v	
	//Config_int_time6();		//phuc vu cho chuong trinh hoat dong song song voi he thong v?i chu ky 1ms
	Config_int_time7();		//su dung de doc sieu am, tang giam bien, ch�ng nhieu, v� c�c chuong tr�nh hoat dong khong song song voi he thong
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
	xTaskCreate(taskRobotAnalytics_uart, (signed char*)"taskRobotAnalytics_uart", 256, NULL, 0, NULL);
	xTaskCreate(taskDieuKhienCoCau, (signed char*)"taskDieuKhienCoCau", 256, NULL, 0, NULL);
//	void gp_update_uart ();

	BienTroTrucYValue = Max_BT_Truc_Y;
	while(BienTroTrucYValue < Max_BT_Truc_Y - 20)	vTaskDelay(1);
	
	Home = 1;
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)) MauSan = 1; // Xanh		
	else	MauSan = 2; // Do
	
	Servo_Cam = 1500;//Goc nhin tong quat: 800; 			//cam nhin xuong,1700 				chay len san 3: 870									so cu:1600
	RobotMode = 10;
	vTaskDelay(500);
	RobotMode = 9;
	
	//------ test --------
	taget_BT_Truc_X = 360;							//580
	taget_BT_Xoay = BT_Xoay_Gap_Bong;			//590;
	Servo_Cam = 1700;
	Servo_Bong = 1900;	// 800: 0 do					1900:90 do
	XI_LANH_KEP_THA_BONG_ON;
	
	// 1: san xanh; 2: san do
	if(MauSan == 1){
			// lay lazer silo san xanh
			ViTriLazeThaBong[0] = 315;
			ViTriLazeThaBong[1] = 244;
			ViTriLazeThaBong[2] = 170;
			ViTriLazeThaBong[3] = 93;
			ViTriLazeThaBong[4] = 20;
	}
	else{
			// lay lazer silo san do
			ViTriLazeThaBong[0] = 12;
			ViTriLazeThaBong[1] = 49;
			ViTriLazeThaBong[2] = 87;
			ViTriLazeThaBong[3] = 126;
			ViTriLazeThaBong[4] = 163;
	}
	
	while(1)//(gp_get_mode()  == GP_MODE_ANALOGUE_RED_LED)
	{
		if(NUT_1 ==  0)  		
		{
			if(MauSan == 1){// 1: san xanh; 2: san do
				//XUAT_PHAT_SAN_XANH();
				while(1){
					TimBongTuDo(MauSan);	
					ThaBong_Xanh();
					Ve_gap_bong_xanh();
				}
				robotStop(0);
				while(1) vTaskDelay(1000);
			}
			else{
				//XUAT_PHAT_SAN_DO();
				while(1) {
					TimBongTuDo(MauSan);
					ThaBong_Do();
					
					Ve_gap_bong_do();
				}
				robotStop(0);
				while(1) vTaskDelay(1000);
			}
		}
		if(NUT_2 == 0) 		
		{
			if(MauSan == 1){// 1: san xanh; 2: san do
				
					// Retry san xanh
					retry_sanxanh();
				while(1)
				{
					TimBongTuDo(MauSan);
					ThaBong_Xanh();
					Ve_gap_bong_xanh();
				}
				robotStop(0);
				while(1) vTaskDelay(1000);
			}
			else{
				// Retry san do
				retry_sando();
				while(1)
				{
					// TimBongTuDo(MauSan);
//					ThaBong_Do();
					// Ve_gap_bong_do();
				}
				robotStop(0);
				while(1) vTaskDelay(1000);
			}
		}
		if(NUT_3 == 0) 				
		{	
			if(MauSan == 1){// 1: san xanh; 2: san do
			//			TimBongTuDo(MauSan);	
  			ThaBong_Xanh();
//			Ve_gap_bong_xanh();

			// Chay_Bo_Bong(ViTriLazeThaBong[4]);
			// Tha_Bong_Vao_Silo(ViTriLazeThaBong[4]);
//			 GAP_BONG();

			}else{
			//			TimBongTuDo(MauSan);	
  			ThaBong_Do();
//			Ve_gap_bong_xanh();

			// Chay_Bo_Bong(ViTriLazeThaBong[4]);
			// Tha_Bong_Vao_Silo(ViTriLazeThaBong[4]);
//			 GAP_BONG();
			
			}
			robotStop(0);
			while(1) vTaskDelay(1000);
		}
				
		if(NUT_5 == 0) {
			taget_BT_Xoay = BT_Xoay_Bo_Bong;
			taget_BT_Truc_X = BT_Truc_X_Tha_Bong;
			XI_LANH_NANG_BONG_ON;
			XI_LANH_KEP_THA_BONG_ON;
			
		}
		robotStop(0);
	}
}

int main(void)	
{

	xTaskCreate(taskMain, (signed char*)"taskMain", 256, NULL,0, NULL);	
	xTaskCreate(taskGyro,(signed char*)"taskGyro", 256, NULL,0, NULL);	
	xTaskCreate(taskDieuKhienCoCau,(signed char*)"taskDieuKhienCoCau", 256, NULL,0, NULL);	
	
	vTaskStartScheduler();// lenh nay cho phep cac tac vu da nhiem hoat dong.
}
