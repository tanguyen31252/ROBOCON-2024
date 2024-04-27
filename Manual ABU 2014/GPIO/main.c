#include "stm32f4xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#include "lcd.h"
#include "gamepad.h"
//#include "ControlerMecanum.h"
#include "ControlerOmni.h"
#include "SensorDetect.h"
#include "AutoRun1.h"
#include "xylinder.h"
#include "Auto_Robot_Manual.h"

vs16 data_imu=0;
vu16 _ADC1_Value[3];
extern unsigned int auto_mode;

void robotGamePadControl(void);
void lcdViewer(void);
vu8 wantExit(void);
void Auto_program(void);
void Auto_program_analoge(void);

int main(void)
{ 
	int tocdo;
	int goc;
	
  Config_out_mode();
	Config_in_mode();
	
	Config_pwm_time_t1();
	Config_pwm_time_t4();
	
	config_uart1(115200);
	
	Config_encoder_timer2_timer3();
	
	Config_ADC1_DMA();
	Config_int_time6();
	
	Config_gamepad_PS2();
	
	if (SysTick_Config(SystemCoreClock / 1000))while (1);// 1ms
	run_read_gyro_uart1();
	
	lcd_Init();
	lcd_Clear();

while (1)
{	
	gp_update_btn();
	lcdViewer();
	obotStop(0);  
	Nang_truc();
	Truot_ngang();
	flash_bit=1;
	
	Auto_program();
	while(gp_get_mode() == GP_MODE_ANALOGUE_RED_LED)
		{
				lcdViewer();
				Nang_truc();
				Truot_ngang();
				Kich_Xylanh();
				gp_update_btn();															// update gamepad
				robotGamePadControl();
			
				if(R2 && !SELECT)        Reset_Truot_ngang();	  				// RESET ENCODER DOC,RESET ENCODER NGANG
				
				if(!R1)          						robotLineDetect(50);			
            if(LJOY_LR <= 10)
                {   
                    if(!L1)  	goc = -850, tocdo = 250;			   					// CUNG CHIEU DONG HO
										else			goc = -900, tocdo = 30;                    // he so cang nho thi tien ra ngoai
									
										//robotCurve(-900,50,0.5);
                    robotLineRun(goc,tocdo); 
								}     
            if(LJOY_LR >= 250)      
                {    
                    if(!L1)  goc = 850, tocdo = 250;					// 830, 60 , 1.29	
										else goc = 900, tocdo = 30; 							// 905 , 20 , 1.26 // 880,50,1.32
                    robotLineRun(goc,tocdo);
                }
			Auto_program_analoge();
		}
}
}


//______________________________ GAME PAD CONTROL__________________________________
//______________________________ GAME PAD CONTROL__________________________________
//______________________________ GAME PAD CONTROL__________________________________

void robotGamePadControl(void)
	{

    int tocdo= 0;
    int rJoy_LR  = (RJOY_LR >= 5 && RJOY_LR <= 250)? 1 : 0; 
    int lJoy_LR  = (LJOY_LR >= 5 && LJOY_LR <= 250)? 1 : 0;

    if(UP && DOWN && RIGHT && LEFT && rJoy_LR && lJoy_LR)
		{ // Khong dieu khien
        robotStop(0); 
        return;
    }                
/*_____________________________//___________________________*/

/********************** TOC DO ****************************/
/*_____________________________//___________________________*/

    if(!L1) tocdo = 200;
    else tocdo = 80;
    //--------- chay cac huong -----------
    if(!UP && DOWN && RIGHT && LEFT && R2)        robotRun(0,tocdo);
    else if(UP && !DOWN && RIGHT && LEFT && R2)   robotRun(1800,tocdo);
    else if(UP && DOWN && !RIGHT && LEFT && R2)   robotRun(900,tocdo);
    else if(UP && DOWN && RIGHT && !LEFT && R2)   robotRun(-900,tocdo);
    
    else if(!UP && DOWN && !RIGHT && LEFT && R2)  robotRun(450,tocdo);
    else if(!UP && DOWN && RIGHT && !LEFT && R2)  robotRun(-450,tocdo);
    else if(UP && !DOWN && !RIGHT && LEFT && R2)  robotRun(1350,tocdo);
    else if(UP && !DOWN && RIGHT && !LEFT && R2)  robotRun(-1350,tocdo);
	
    //-------------- Dang chay va Khong chay nua, chi xoay ----------------
    if(UP && DOWN && RIGHT && LEFT && !rJoy_LR && lJoy_LR && robotIsRun()) robotStop(0);   

    //-------------- Xoay ----------------
    if(rJoy_LR) robotRotateStop();
    else if((RJOY_LR < 5) && L2)
    {
        if(robotIsRun()) robotRotateFree(-0.5,0);
        else robotRotateFree(-0.7,0);
    }
    else if((RJOY_LR > 250) && L2)
    {
        if(robotIsRun()) robotRotateFree(0.5,0);
        else robotRotateFree(0.7,0);
    }
    else robotRotateStop();		
	}

//----------------------------------------- lcd viewer -------------------------	
void lcdViewer(void)
{
		lcd_printInt(0,0,Encoder_doc());
		lcd_printInt(1,0,Encoder_ngang());
	
		lcd_printInt(1,8,_robotIMUAngle);
	
		lcd_printInt(0,8, _ADC1_Value[0]);			//between
		lcd_printInt(0,15,_ADC1_Value[1]); 			//right
		lcd_printInt(1,15,_ADC1_Value[2]);			//BT
//		lcd_printInt(1,13,GP_BTN[0]);
//		lcd_printInt(1,17,GP_BTN[1]);
//	
// 		if(auto_mode==0) lcd_printStr(3,0,"BB");
// 		if(auto_mode==1) lcd_printStr(3,0,"X-BB");
// 		if(auto_mode==2) lcd_printStr(3,0,"X-D");
// 		if(auto_mode==3) lcd_printStr(3,0,"L-T");
// 		if(auto_mode==4) lcd_printStr(3,0,"C-T");
	
		lcd_printInt(2,0,cb_TT0);	
		lcd_printInt(2,1,cb_TT1);	
		lcd_printInt(2,2,cb_TT2);	
		lcd_printInt(2,3,cb_TS0);	
		lcd_printInt(2,4,cb_TS1);	
		lcd_printInt(2,5,cb_TS2);
	
		lcd_printInt(3,0,cb_PT0);	
		lcd_printInt(3,1,cb_PT1);	
		lcd_printInt(3,2,cb_PT2);	
		lcd_printInt(3,3,cb_PS0);	
		lcd_printInt(3,4,cb_PS1);	
		lcd_printInt(3,5,cb_PS2);
		
		lcd_printInt(3,7,auto_mode);

//	lcd_printInt(2,0,GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_0));	
//	lcd_printInt(2,1,GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_1));	
//	lcd_printInt(2,2,GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_2));	
//	lcd_printInt(2,3,GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_3));	
//	lcd_printInt(2,4,GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_4));	
//	lcd_printInt(2,5,GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_5));

//	lcd_printInt(3,0,GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6));	
//	lcd_printInt(3,1,GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7));	
//	lcd_printInt(3,2,GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8));	
//	lcd_printInt(3,3,GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_9));	
//	lcd_printInt(3,4,GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_10));	
//	lcd_printInt(3,5,GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_11));
	
// 	lcd_printInt(2,0,cb_NC_TAY_1);	
//	lcd_printInt(2,1,cb_NC_TAY_2);	
//	lcd_printInt(2,2,cb_NC_TAY_3);	
//	lcd_printInt(2,3,cb_NC_TAY_4);	
//	lcd_printInt(2,4,cb_NC_TAY_5);	
//	lcd_printInt(2,5,cb_NC_TAY_6);	
//	lcd_printInt(2,6,cb_NC_TAY_7);	
//	lcd_printInt(2,7,cb_NC_TAY_8);
//	
//	lcd_printInt(3,0,cb_NC_1);	
//	lcd_printInt(3,1,cb_NC_2);	
//	lcd_printInt(3,2,cb_NC_3);	
//	lcd_printInt(3,3,cb_NC_4);	
//	lcd_printInt(3,4,cb_NC_5);	
//	lcd_printInt(3,5,cb_NC_6);	
//	lcd_printInt(3,6,cb_NC_7);	
//	lcd_printInt(3,7,cb_NC_8);	
//	lcd_printInt(3,8,cb_NC_9);	
//	lcd_printInt(3,9,cb_NC_10);	

		lcd_printInt(2,10,cb_quang_left);	
		lcd_printInt(3,10,XANH_DO);	
	
		lcd_printInt(2,12,cb_DON_XICHDU_T);	
		lcd_printInt(3,12,cb_XICHDU_T);	
	
		lcd_printInt(2,14,cb_DON_XICHDU_P);	
		lcd_printInt(3,14,cb_XICHDU_P);	
	
		lcd_printInt(2,16,cb_Kep);	
		lcd_printInt(3,16,cb_mode);
	
		lcd_printInt(2,18,cb_quang_bb);	
		lcd_printInt(3,18,cb_quang_bb_xanh);

		lcd_printInt(2,19,cb_Tay);
		lcd_printInt(3,19,cb_XICHDU);
	
}

//==============================================================================
vu8 wantExit(void)
{
	gp_update_btn();
	
	if(R2 && L2 && !DOWN)    		  {Xilanh_mode_off;return 1;} 
  else           								return 0;
}

//==============================================================================
void Auto_program(void)
 {
	if(XANH_DO==0)
			{					
					if(!START && auto_mode == 0)				AUTO_BB_DO(-5);
					if(!START && auto_mode == 1) 				XOAY_BAPBENH_DO();
				
					if(!START && auto_mode == 2) 				XICH_DU_DO(1440,1755);		//   cang lon cang gan xd
					if(!START && auto_mode == 3)				BAN_XICHDU_DO();	
					if(!START && auto_mode == 4)				DON_XICHDU_DO();	
						
					if(!START && auto_mode	== 5)				LEO_COT_DO(55);						// so cang lon cang gan cot
					if(!R2 && !SELECT)									LEO_COT_DO_1(55);	
					if(!START && auto_mode	== 6)				THA_COT_DO(9000);
				
					if(!START && auto_mode	== 7)	  		CAUTHANG_DO(1800,1100);				// so cang lon cang gan cau thang	
					if(!START && auto_mode	== 8)				THA_CAUTHANG_DO();				
						
					if(!R2 && L2 && !UP)								fix_bapbenh_do();
					if(!R2 && L2 && !LEFT)							fix_xichdu_do();
					if(!R2 && L2 && !DOWN)							fix_leocot_do();
					if(!R2 && L2 && !RIGHT)							fix_cauthang_do();
			}
		else
			{
					if(!START && auto_mode == 0)				AUTO_BB_XANH(-30);
					if(!START && auto_mode == 1) 				XOAY_BAPBENH_XANH();
				
					if(!START && auto_mode == 2)				XICH_DU_XANH(1650,1755);		//   cang lon cang gan xd
					if(!START && auto_mode == 3)				BAN_XICHDU_XANH();	
					if(!START && auto_mode == 4)				DON_XICHDU_XANH();	
						
					if(!START && auto_mode	== 5)				LEO_COT_XANH(50);						// so cang lon cang gan cot
					if(!R2 && !SELECT)									LEO_COT_XANH_1(50);
					if(!START && auto_mode	== 6)				THA_COT_XANH(9200);
				
					if(!START && auto_mode	== 7)				CAUTHANG_XANH(1750,2400);		//we're the champion!	
					if(!START && auto_mode	== 8)				THA_CAUTHANG_XANH();	
				
					if(!R2 && L2 && !UP)								fix_bapbenh_xanh();
					if(!R2 && L2 && !LEFT)							fix_xichdu_xanh();
					if(!R2 && L2 && !DOWN)							fix_leocot_xanh();
					if(!R2 && L2 && !RIGHT)							fix_cauthang_xanh();
			}
}

//==============================================================================
void Auto_program_analoge(void)
{
	if(XANH_DO==0)
			{					
					if( !START && auto_mode == 0)															AUTO_BB_DO(-5);
					if((!START && auto_mode == 1) || (!R2 && !TRIANGLE)) 			XOAY_BAPBENH_DO();
				
					if((!START && auto_mode == 2) || (!R2 && !SQUARE)) 				XICH_DU_DO(1440,1760);		//   cang lon cang gan xd
					if((!START && auto_mode == 3) || (!L2 && LJOY_UD < 5))		BAN_XICHDU_DO();	
					if((!START && auto_mode == 4) || (!L2 && LJOY_UD > 253))	DON_XICHDU_DO();	
						
					if((!START && auto_mode	== 5) || (!R2 && !X))		  				LEO_COT_DO(55);						// so cang lon cang gan cot
					if(!R2 && !SELECT)																				LEO_COT_DO_1(55);	
					if((!START && auto_mode	== 6) || (!L2 && RJOY_UD > 253))	THA_COT_DO(9000);
				
					if((!START && auto_mode	== 7) || (!R2 && !O))		  				CAUTHANG_DO(1800,1200);				// so cang lon cang gan cau thang	
					if((!START && auto_mode	== 8) || (!L2 && RJOY_UD < 5))	  THA_CAUTHANG_DO();				
						
					if(!R2 && L2 && !UP)						fix_bapbenh_do();
					if(!R2 && L2 && !LEFT)					fix_xichdu_do();
					if(!R2 && L2 && !DOWN)					fix_leocot_do();
					if(!R2 && L2 && !RIGHT)					fix_cauthang_do();
			}
		else
			{
					if( !START && auto_mode == 0)													  	AUTO_BB_XANH(-30);
					if((!START && auto_mode == 1) || (!R2 && !TRIANGLE)) 			XOAY_BAPBENH_XANH();
				
					if((!START && auto_mode == 2) || (!R2 && !SQUARE)) 				XICH_DU_XANH(1650,1755);		//   cang lon cang gan xd
					if((!START && auto_mode == 3) || (!L2 && LJOY_UD < 5))		BAN_XICHDU_XANH();	
					if((!START && auto_mode == 4) || (!L2 && LJOY_UD > 253))	DON_XICHDU_XANH();	
						
					if((!START && auto_mode	== 5) || (!R2 && !X))		  				LEO_COT_XANH(50);						// so cang lon cang gan cot
					if(!R2 && !SELECT)																				LEO_COT_XANH_1(50);
					if((!START && auto_mode	== 6) || (!L2 && RJOY_UD > 253))	THA_COT_XANH(9200);
				
					if((!START && auto_mode	== 7) || (!R2 && !O))		  				CAUTHANG_XANH(1750,2400);		//we're the champion!	
					if((!START && auto_mode	== 8) || (!L2 && RJOY_UD < 5))	  THA_CAUTHANG_XANH();	
				
					if(!R2 && L2 && !UP)						fix_bapbenh_xanh();
					if(!R2 && L2 && !LEFT)					fix_xichdu_xanh();
					if(!R2 && L2 && !DOWN)					fix_leocot_xanh();
					if(!R2 && L2 && !RIGHT)					fix_cauthang_xanh();
			}
}
