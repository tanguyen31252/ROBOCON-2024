// #include "cmsis_os.h"

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
// #include "ROBOTRUN.h"
#include "BasicFunction.h"
#include "San_Xanh.h"
#include "San_Do.h"

vu8 speed, speed1;

static void taskGyro(void *pvParameters)
{
	while (1)
	{
		//-------------------------------------------------------------

		//-----------------------------------------------------------------
		HMI_RUN_LOOP(18);
		vTaskDelay(15);
	}
}
static void taskDieuKhienCoCau(void *pvParameters)
{
	while (1)
	{
		vTaskDelay(10);
	}
}
static void taskADCValue(void *pvParameters)
{
	while (1)
	{
		ADCValue_Control();

		vTaskDelay(1);
	}
}
static void taskRobotAnalytics(void *pvParameters)
{
	while (1)
	{
		robotAnalytics();
		vTaskDelay(7);
	}
}
static void taskMain(void *pvParameters)
{
	Config_out_mode(); // khai b�o ngo ra cua mot chan bat ky
	Config_in_mode();  // khai bao ngo v�o cua mot chan bat ky
	// Config_pwm_time_t8();//cai dat timer8 o che do dieu xung
	Config_pwm_time_t4(); // cai dat timer4 o che do dieu xung
	// Config_pwm_time_t9();//cai dat timer9 o che do RC SEVOR
	Config_encoder_timer2_timer3(); // doc encoder  timer 2, timer 3, timer 5 ,timer 9
	Config_encoder_timer1();
	// Config_encoder_timer5();
	// ngat_ngoai();			//chuy�n dung de doc sieu am ket hop timer7, hoac co the dung lam nut nh�n
	Config_ADC1_DMA(); // su dung  khi doc tin hieu laze hay cac t�n hieu ADC<3,3v
	// Config_int_time6();		//phuc vu cho chuong trinh hoat dong song song voi he thong v?i chu ky 1ms
	Config_int_time7();	  // su dung de doc sieu am, tang giam bien, ch�ng nhieu, v� c�c chuong tr�nh hoat dong khong song song voi he thong
	UART1_DMA_RX(115200); // usart giao tiep voi laban
	UART2_DMA_TX(115200); /// DIEU KHIEN DONG CO
	UART3_DMA_RX(115200); // usart giao tiep de doc gamepad
	// UART4_DMA_RX(115200); // SU DUNG DE GIAO TIEP 12 NUT LUA
	UART6_DMA_RX(115200); // SU DUNG DE GIAO TIEP MACH DO LAI
	UART5_DMA_TX(921600); // GIAO TIEP MAN HINH HMI
	// if (SysTick_Config(SystemCoreClock / 1000))while (1);// 1ms truyen du lieu usart den cac slever

	// reset lai laban

	robotResetIMU();
	RESET_ENCODER();

	XL_THUC_XUONG;
	XL_THA_LUA_BAT;
	XL_KEP_BONG_NHA;
	XL_DAY_LUA_TAT;

	//---- reset he thong ve vi tri ban dau

	//-----------------------------------
	xTaskCreate(taskADCValue, (signed char *)"taskADCValue", 256, NULL, 0, NULL);
	xTaskCreate(taskRobotAnalytics, (signed char *)"taskRobotAnalytics", 256, NULL, 0, NULL);
	xTaskCreate(taskDieuKhienCoCau, (signed char *)"taskDieuKhienCoCau", 256, NULL, 0, NULL);
	// san=2;
	// vi_tri_can_toi=1;
	// XL_KEP_BONG_KEP;
	// XL_DAY_LUA_BAT;
	// XL_THA_LUA_TAT;
	// XL_THUC_LEN;
	while (1)
	{
		if (!CB_BONG_RA && lan_trong == 0)
			THI(); ///// xuat phat
		while (gp_get_mode_uart() == GP_MODE_ANALOGUE_RED_LED)
		{

			robotGamePadControl();
			if (san == 1)
			{
				if (!SELECT)
					retry();
				if (!START && lan_trong == 0)
					XuatPhat();
				else if (!START && (lan_trong == 1 || lan_trong == 2 || lan_trong == 3) && hang_trong == 1)
					quy_trinh_trong_lua_hang_1();
				if (!R1 && !X)
					trong_lua();
				if (!R2 && !R1 && L1 && L2)
				{
					san = 2;
				}
			}
			else // len san 2
			{
				if (L1 && L2 && R1 && R2 && !SQUARE)
				{
					RESET_ENCODER();
					while (ENCODER_TONG() < 300)
					{
						do_line(-25);
						if (wantExit_R2())
							break;
						vTaskDelay(1);
					}
					while (CB_BONG_GIUA_TRAI == 0 && CB_BONG_SAU_TRAI == 1)
					{
						do_line(-25);
						if (wantExit_R2())
							break;
						vTaskDelay(1);
					}
					while (CB_BONG_GIUA_PHAI == 0 && CB_BONG_SAU_PHAI == 0)
					{
						do_line(-5);
						if (wantExit_R2())
							break;
						vTaskDelay(1);
					}
					robotStop(0);
				}
				if (L1 && L2 && R1 && R2 && !O)
				{
					RESET_ENCODER();
					while (ENCODER_TONG() < 300)
					{
						do_line(25);
						if (wantExit_R2())
							break;
						vTaskDelay(1);
					}
					while (CB_BONG_GIUA_PHAI == 0 && CB_BONG_SAU_PHAI == 0)
					{
						do_line(25);
						if (wantExit_R2())
							break;
						vTaskDelay(1);
					}
					while (CB_BONG_GIUA_TRAI == 0 && CB_BONG_SAU_TRAI == 1)
					{
						do_line(5);
						if (wantExit_R2())
							break;
						vTaskDelay(1);
					}
					robotStop(0);
				}
				if (!SELECT)
					retry_2();
				if(!L1 && !L2 && R1 && R2 && X && O && TRIANGLE && SQUARE)
				{
					robotRotateFree(1,0);
					if(wantExit_R2())break;
				}
				dieuKhienCoCau();
			}
		}
	}
}
int main(void)
{
	xTaskCreate(taskMain, (signed char *)"taskMain", 256, NULL, 0, NULL);
	xTaskCreate(taskGyro, (signed char *)"taskGyro", 256, NULL, 0, NULL);

	vTaskStartScheduler(); // lenh nay cho phep cac tac vu da nhiem hoat dong.
}
