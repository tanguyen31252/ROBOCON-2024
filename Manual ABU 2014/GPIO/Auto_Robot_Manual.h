int 	flash_bit1;
extern unsigned int flash_bit;
extern unsigned int auto_mode;

vu8 wantExit(void);
void lcdViewer(void);
void robotGamePadControl(void);

void bap_benh_auto(unsigned int time)
{
				unsigned char noise,noise1;    
    while(time-- > 0)
    {
			for(noise=0;noise<10;noise++)   while(cb_NC_4)    {mor_nang = 250; mor_nang_down;if(wantExit()) return;  }
			for(noise1=0;noise1<10;noise1++)while(cb_NC_5)    {mor_nang = 250; mor_nang_up;  if(wantExit()) return;  }
    }
			mor_nang = 2;  
}
// ----------------------------------------------------------------
// --------------------------- START ------------------------------
// ----------------------------------------------------------------
void  AUTO_BB_DO(int goc_fix)
{					
		int noise;
		auto_mode=1;						
		Xilanh53_ve_on;
	
		Reset_encoder_ngang();			
		robotRun(-950 - _robotIMUAngle,200);
		robotRotate(1,0.5,0);
	
		while(abs(Encoder_ngang()) < 9998)													// chay ngang		
		{		
				Nang_Truc(20,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 9999)													// chay ngang		
		{		
				Nang_Truc(20,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 10000)													// chay ngang		
		{		
				Nang_Truc(20,3);
				if(wantExit()) return;
		}
		
		Xilanh53_ve_off;
		bitha=1;
		Xilanh_mode_on;
		Reset_encoder_doc();
		robotRun(-1300 - _robotIMUAngle,200);
		robotRotate(1,0.5,0);		
		while(abs(Encoder_doc()) < 12998)
		{		
				Nang_Truc(50,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 12999)
		{		
				Nang_Truc(50,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 13000)
		{		
				Nang_Truc(50,3);
				if(wantExit()) return;
		}
		
		Reset_encoder_ngang();
		
		for(noise=0;noise<100;noise++)
		{
			while(cb_quang_bb)																				// kiem tra cam bien quang							
			{		
					Nang_Truc(80,3);
					if(wantExit()) return;
			}
		}
		
		Xilanh50_on;
		
		
		Reset_encoder_ngang();
		robotRun(-900 - _robotIMUAngle,100);								// 1
		robotRotate(goc_fix,0.4,0);
		while(abs(Encoder_ngang()) < 7998)
		{		
				Truot_Ra(50,2);
				Nang_Truc(100,2);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 7999)
		{		
				Truot_Ra(50,2);
				Nang_Truc(100,2);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 8000)
		{		
				Truot_Ra(50,2);
				Nang_Truc(100,2);
				if(wantExit()) return;
		}
		
		robotRun(-900 - _robotIMUAngle,40);								// 1
		robotRotate(goc_fix,0.4,0);
		while(_ADC1_Value[0] > 1500)															// KIEM TRA LAZE GIUA			
		{		
				Truot_Ra(50,2);
				Nang_Truc(100,2);
				if(wantExit()) return;
		}
		
		Reset_encoder_ngang();
		
		robotRun(-900 - _robotIMUAngle,25);												// CHAY TOC DO CHAM
		robotRotate(goc_fix,0.4,0);	
		
		while( _ADC1_Value[1] > 460 )															//  KIEM TRA LAZE RIGHT						
		{		
				Ha_Truc(30,7);
				Truot_Ra(50,2);
				if(wantExit()) return;
		}
		
		
		robotStop(0);
		
		robotRun(-_robotIMUAngle,50);															// CHAY THANG NHAN DO LINE
		robotRotate(-1,0.4,0);
		
		while(cb_NC_7)
		{
				if(!cb_TTruoc && !cb_PTruoc)   robotStop(0);					// DUNG KHI DA NHAN LINE
				Ha_Truc(200,7);
				Truot_Ra(50,2);
				if(wantExit()) return;
		}	
		
		robotStop(0);
		Xilanh_mode_off;
  	mor_ngang=2;
		mor_nang=2;
		
		bitha=0;
}
//=============================================================================
//============================    XOAY BB DO  =================================
//=============================================================================
void XOAY_BAPBENH_DO()
{																				
		auto_mode=2;
	
		bitha=0;
		
	  Xilanh_mode_off,Xilanh_kep_off;									// nha kep
	
		while(cb_Kep) if(wantExit()) return;		
	
		Nang_Truc_While(240,6);													// nang truc qua bap benh
	
		Xilanh50_off;
	  Xilanh53_ra_off;
		Xilanh53_ve_on;						
	
		Reset_encoder_ngang();		
		robotLineRun(910, 250);
		while(abs(Encoder_ngang())<1998)
		{				
				robotLineRun(910, 250);
				Nang_Truc(20,3);
				Truot_Vao(200,8);
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<1999)
		{				
				robotLineRun(910, 250);
				Nang_Truc(20,3);
				Truot_Vao(200,8);
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<2000)
		{				
				robotLineRun(910, 250);
				Nang_Truc(20,3);
				Truot_Vao(200,8);
				if(wantExit()) return;	
		}
	
		Reset_encoder_ngang();	
		while(abs(Encoder_ngang()) < 35498)
		{
				robotLineRun(850, 250);									
				Nang_Truc(60,3);
				if(abs(Encoder_ngang()) > 15000)  Truot_Ra(120,1); 
				if(wantExit()) return;						
		}
		while(abs(Encoder_ngang()) < 35499)
		{
				robotLineRun(850, 250);									
				Nang_Truc(60,3);
				Truot_Ra(120,1); 
				if(wantExit()) return;						
		}
		while(abs(Encoder_ngang()) < 35500)
		{
				robotLineRun(850, 250);									
				Nang_Truc(60,3);
				Truot_Ra(120,1); 
				if(wantExit()) return;						
		}
		
		Reset_encoder_ngang();
		while(abs(Encoder_ngang())<4998)
		{
				Nang_Truc(60,3);	
				Truot_Ra(120,1); 
				robotLineRun(850, 150);
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<4999)
		{
				Nang_Truc(60,3);	
				Truot_Ra(120,1); 
				robotLineRun(850, 150);
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<5000)
		{
				Nang_Truc(60,3);	
				Truot_Ra(120,1); 
				robotLineRun(850, 150);
				if(wantExit()) return;	
		}
		
		robotStop(0);
		delay_ms(200);
		bap_benh_auto(3);		
//================================== CHAY VE DON ROBOT =================================				

		Xilanh53_ve_off;
		Reset_encoder_ngang();
		while(abs(Encoder_ngang())<3998)											// chay cham 4000	
		{
				robotLineRun(-870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<3999)											// chay cham 4000	
		{
				robotLineRun(-870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<4000)											// chay cham 4000	
		{
				robotLineRun(-870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		
		Xilanh53_ra_on,Xilanh50_on;
		Reset_encoder_ngang();	
		while(abs(Encoder_ngang())<31998)											// chay nhanh 35000
		{  	
				robotLineRun(-810, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)						Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)						Truot_Ra(50,2);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang())<31999)											// chay nhanh 35000
		{  	
				robotLineRun(-810, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)						Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)						Truot_Ra(50,2);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang())<32000)											// chay nhanh 35000
		{  	
				robotLineRun(-810, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)						Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)						Truot_Ra(50,2);
				if(wantExit()) return;
		}
		
		Reset_encoder_ngang();
		while(_ADC1_Value[0] > 500)																// kiem tra laze dung robot
		{
				Truot_Ra(50,2);
				Ha_Truc(50,6);
				robotLineRun(-810, 120); 
				if(wantExit()) return;
		}
		
//		robotCurve(-920 - _robotIMUAngle,60 , 1);		
		while(_robotIMUAngle < -15)
		{
				Truot_Ra(50,2);
				Ha_Truc(50,6);
				robotLineRun(-850, 80);
				robotRotateFree(0.3,0);
				if(wantExit()) return;
		}
			
		robotStop(0);		
		mor_ngang=2;
		Ha_Truc_While(240,7);					
		Xilanh53_ra_on;
		Xilanh50_on;					
}

// -----------------------------------------------------------------
// ----------------------  XICH DU DO  -----------------------------
// -----------------------------------------------------------------
void XICH_DU_DO(int Stop_Roate, int Roate)
{		
		int i;
		auto_mode=3;
		Xilanh_kep_on;delay_ms(200);											// kep delay 100ms
		Xilanh53_ve_off,Xilanh50_on,Xilanh53_ra_on;				// cho canh tay nam ngang
		Reset_encoder_doc();	
		Nang_Truc(100,5);																	// nang truc toc do 100
	
		robotRun(-1200 - _robotIMUAngle,250);							// -3560
		robotRotate(1,-0.3,0);	
		while(abs(Encoder_doc()) < 1498)									// VN->CHAMPION
		{
				Nang_Truc(100,5);
				Truot_Vao(150,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 1499)									// VN->CHAMPION
		{
				Nang_Truc(100,5);
				Truot_Vao(150,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 1500)									// VN->CHAMPION
		{
				Nang_Truc(100,5);
				Truot_Vao(150,8);
				if(wantExit()) return;
		}				
		
		Reset_encoder_ngang();				
		robotRun(-1200 - _robotIMUAngle,255);							// so cang lon cang gan xich du
		robotRotate(-1720, -0.48, 0);
		
//						-3560								-5200
		while(abs(_robotIMUAngle) < Stop_Roate)						// bat dau chay ngang         -5200
		{		
				Truot_Vao(120,8);
				Nang_Truc(50,2);
				if(abs(_robotIMUAngle) > 1550)   Xilanh_cheo_on;						
				if(wantExit()) return;
		}	
		
		
		Xilanh_cheo_on;				
		Reset_encoder_ngang();
		
		robotRun(-900 - _robotIMUAngle,120);
		robotRotate(-Roate,-0.4,0);
		
		while(_ADC1_Value[0] > 900)											// nhan laze dem encoder, tat mode
		{		
				Truot_Vao(20,8);
				Nang_Truc(150,2);
				if(wantExit()) return;
		}	
		Xilanh_mode_on;					
		robotRun(-900 - _robotIMUAngle,80);
		robotRotate(-Roate,-0.4,0);
				
		Reset_encoder_ngang();
		while(abs(Encoder_ngang()) < 2798)
		{
				Truot_Vao(20,8);	
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}	
		while(abs(Encoder_ngang()) < 2799)
		{
				Truot_Vao(20,8);	
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}	
		while(abs(Encoder_ngang()) < 2800)
		{
				Truot_Vao(20,8);	
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}	
			
		robotRun(-900 - _robotIMUAngle,50);
		robotRotate(-Roate,-0.3,0);
			

		for(i=0;i<10;i++)
		{
				while(cb_XICHDU_T || cb_XICHDU_P)
				{		
						Nang_Truc(150,2);
						if(wantExit()) return;	
				}
		}
		
		Reset_encoder_ngang();		 
		while(abs(Encoder_ngang()) < 148)
		{		
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}
		
		while(abs(Encoder_ngang()) < 149)
		{		
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}
		
		while(abs(Encoder_ngang()) < 150)
		{		
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}
		
							
		Reset_encoder_doc();
		
		robotRun(-1760 - _robotIMUAngle,40);
		robotRotate(-Roate,-0.3,0);
		
		while(cb_XICHDU)										 								// robot stop neu nhan laze xich du
		{	
				Truot_Ra(150,1);
				Nang_Truc(150,2);
				if(wantExit()) return;
		}
		
			
		robotStop(0);
		Xilanh_mode_off;	
		Truot_Ra_While(240,1);															//  dua het canh tay ra 
		Ha_Truc_While(120,3);																//  ha truc	
		Truot_Vao_While(150,6);	
		

}
// -----------------------------------------------------------------
// ----------------------  BAN XICH DU DO  -----------------------------
// -----------------------------------------------------------------
void BAN_XICHDU_DO()
{
		auto_mode = 4;
	
		Xilanh_mode_on;
		delay_ms(100);
		Xilanh_mode_off;
		Xilanh_kep_off;
		Xilanh_kep_off;
		Xilanh_cheo_on;
	
		while(cb_Kep);
	
		Xilanh53_ra_off;
		Xilanh53_ve_on;
		Xilanh50_off;		
	
		while(_ADC1_Value[2] < 2100);//	 if(wantExit()) return;
	
		Xilanh_ban_on;
		while(cb_BAN);
	
		Xilanh_ban_off;
	
		Reset_encoder_doc();
		robotRun(-_robotIMUAngle,100);
		robotRotate(-1755,-0.2,0);
		while(abs(Encoder_doc()) < 3998)
		{		 
				Nang_Truc(120,2);
				Truot_Vao(100,3);				
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 3999)
		{		 
				Nang_Truc(120,2);
				Truot_Vao(100,3);				
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 4000)
		{		 
				Nang_Truc(120,2);
				Truot_Vao(100,3);				
				if(wantExit()) return;
		}
		
		robotRun(-_robotIMUAngle,60);
		robotRotate(-1755,-0.2,0);
		while(abs(Encoder_doc()) < 5998)
		{		 
				Nang_Truc(120,2);
				Truot_Vao(100,3);
				Xilanh50_on;
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 5999)
		{		 
				Nang_Truc(120,2);
				Truot_Vao(100,3);
				Xilanh50_on;
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 6000)
		{		 
				Nang_Truc(120,2);
				Truot_Vao(100,3);
				Xilanh50_on;
				if(wantExit()) return;
		}
		
		mor_nang=2;
		robotStop(2);
		
		//while(!robotFixAngle);
}
// -----------------------------------------------------------------
void BAN_XICHDU_DO_Timeout()
{
		int time;
		auto_mode = 4;
	
		Xilanh_mode_on;
		delay_ms(100);
		Xilanh_mode_off;
		Xilanh_kep_off;
		Xilanh_kep_off;
		Xilanh_cheo_on;
	
		while(cb_Kep && time < 500){
				delay_ms(1);									//if(wantExit()) return;
				time++;
		}
	
		Xilanh53_ra_off;
		Xilanh53_ve_on;
		Xilanh50_off;		
	
		while(_ADC1_Value[2] < 2100);//	 if(wantExit()) return;
	
		Xilanh_ban_on;
	
		while(cb_BAN && time < 600){
				delay_ms(1);									//if(wantExit()) return;
				time++;
				if(wantExit()) return;
		}		
	
		Xilanh_ban_off;
	
		Reset_encoder_doc();
		robotRun(1800,120);
		robotRotate(-1760,0.1,0);
		while(abs(Encoder_doc()) < 4000)
		{		 
				Nang_Truc(120,2);
				Truot_Vao(100,4);				
				if(wantExit()) return;
		}
		
		robotRun(1800,80);
		robotRotate(-1760,-0.2,0);
		while(abs(Encoder_doc()) < 6000)
		{		 
				Nang_Truc(120,2);
				Truot_Vao(100,4);
				Xilanh50_on;
				if(wantExit()) return;
		}
		
		mor_nang=2;
		robotStop(2);
}

// -----------------------------------------------------------------
// ----------------------  DON XICH DU -----------------------------
// -----------------------------------------------------------------
void DON_XICHDU_DO()
{	
		int noise;
		auto_mode = 5;
	
		Xilanh_cheo_on,Xilanh_kep_off;
		Xilanh53_ve_off,Xilanh53_ra_on,Xilanh50_on;
	
		Reset_encoder_doc();
		robotRun(-1770- _robotIMUAngle,60);
		robotRotate(-1760,-0.2,0);
		
		while(cb_XICHDU)
		{		 
				Truot_Ra(80,6);				
				if(wantExit()) return;
		}
		
		mor_nang = 2;
		mor_ngang = 2;
		
		robotStop(0);
		
		for(noise=0;noise<20;noise++)
		{
			while(cb_DON_XICHDU_T && cb_DON_XICHDU_P)			if(wantExit()) return;
		}
		
		Ha_Truc_While(200,3);
}

// -----------------------------------------------------------------
// ----------------------  COT DO  ---------------------------------
// -----------------------------------------------------------------
void LEO_COT_DO(int fix_cot_d)
{
		int noise;
		auto_mode=6;
		Xilanh_kep_on;
		delay_ms(200);
		Xilanh_mode_on;
		delay_ms(300);
		Xilanh_cheo_off;
		Xilanh50_on, Xilanh53_ra_on, Xilanh53_ve_off;
	
		Nang_Truc(150,1);	
	for(noise=0;noise<5;noise++)		  Truot_Ra_While(250,1);
			
	for(noise=0;noise<5;noise++)			Nang_Truc_While(240,1);							
		Truot_Vao(250,8);
		Reset_encoder_doc();
		
		robotRun(0 - _robotIMUAngle,70);
		robotRotate(-1760,0.3,0);
	
		robotRun(0 - _robotIMUAngle,70);
		robotRotate(-1760,0.3,0);
	
		robotRun(0 - _robotIMUAngle,70);
		robotRotate(-1760,0.3,0);
		
		while(abs(Encoder_doc()) < 1498)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 1499)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 1500)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
			
		
		robotRun(0 - _robotIMUAngle,120);
		robotRotate(-1760,0.3,0);
	
		while(abs(Encoder_doc()) < 2998)
			{		 
				Ha_Truc(120,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 2999)
			{		 
				Ha_Truc(120,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 3000)
			{		 
				Ha_Truc(120,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
			
		Xilanh_mode_off;
		Xilanh50_off, Xilanh53_ra_off, Xilanh53_ve_on;
			
				Reset_encoder_doc();
		
		robotRun(300 + _robotIMUAngle,220);   //-1760.............-1150/// giam
		robotRotate(-800,0.4,0);
		
		while(abs(Encoder_doc()) < 20598)
			{
				flash_bit=1;
				Ha_Truc(120,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 20599)
			{
				flash_bit=1;
				Ha_Truc(120,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 20600)
			{
				flash_bit=1;
				Ha_Truc(120,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
			}
			
		Reset_encoder_ngang();
		
		robotRun(-fix_cot_d - _robotIMUAngle,400);			// so cang lon cang gan cot
		robotRotate(-900,0.4,0);
			
		while(_ADC1_Value[0] > 1000)
			{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
			}
		
		
		
		Reset_encoder_ngang();
		robotRun(-fix_cot_d - _robotIMUAngle,400);
		robotRotate(-900,0.5,0);
		while(abs(Encoder_ngang()) < 19998)
			{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 19999)
			{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 20000)
			{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
			}
		
		Xilanh_mode_on;
		
		robotRun(-fix_cot_d- _robotIMUAngle,150);
		robotRotate(-900,0.5,0);
				mor_nang=0;
		while(_ADC1_Value[0] > 1500)
			{
				Truot_Vao(20,8);
				if(wantExit()) return;
			}
		
		Xilanh_mode_off;
		
		
		Reset_encoder_ngang();
		robotRun(-fix_cot_d - _robotIMUAngle,80);
		robotRotate(-760,1.2,0);
		while(abs(Encoder_ngang()) <2998)
			{
				Truot_Ra(120,4);
				if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) <2999)
			{
				Truot_Ra(120,4);
				if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) <3000)
			{
				Truot_Ra(120,4);
				if(wantExit()) return;
			}
		
		Xilanh_mode_on;
			
		mor_nang=0;
		mor_ngang=2;
			
		robotLineDetect(40);
		
		robotStop(0);
		Xilanh_mode_off;
		
		for(noise=0;noise<5;noise++)
			{
			while(cb_mode)
				{
					Truot_Ra(90,5);
					robotLineRun(-850,60); 
					if(wantExit()) return;
				}
			}
		mor_ngang=2;
		robotRotateFree(-0.5,0);
		for(noise=0;noise<80;noise++)
		{	
				gp_update_btn();
				if(!START || (!L2 && RJOY_UD > 253))		break;	
					if(wantExit()) return;
		}
		robotStop(0);
		
}
// -----------------------------------------------------------------
// ----------------------  CAU THANG  ------------------------------
// -----------------------------------------------------------------
void CAUTHANG_DO(int fix_goc_d,int encoder_stop)
{
		auto_mode = 8;
		Xilanh_kep_on; delay_ms(300);
		Xilanh_mode_on;	
	
		while(cb_mode)
		{
				gp_update_btn();
				Nang_truc();	
				if(wantExit()) return;	
		}
		
		Xilanh_mode_off;
		Truot_Vao(200,8);
		
		Reset_encoder_ngang();
		robotRun(-1900 - _robotIMUAngle,250);
		robotRotate(-880,0.3,0);
		while(abs(Encoder_ngang()) < 13498)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 13499)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 13500)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}
		
		
		
		Reset_encoder_ngang();
		robotRun(-fix_goc_d - _robotIMUAngle,250);
		robotRotate(-860,0.5,0);
		while(abs(Encoder_ngang()) < 19998)						// bat dau chay cham lai
		{
				Truot_Vao(50,8);
				Nang_Truc(50,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 19999)						// bat dau chay cham lai
		{
				Truot_Vao(50,8);
				Nang_Truc(50,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 20000)						// bat dau chay cham lai
		{
				Truot_Vao(50,8);
				Nang_Truc(50,8);
				if(wantExit()) return;
		}
						
		Xilanh_mode_on;
		
		robotRun(-fix_goc_d - _robotIMUAngle,100);
		robotRotate(-860,0.5,0);				
		while(_ADC1_Value[0] > 750)											 // kiem tra laze nhan thanh cau thang
		{
				Nang_Truc(50,8);		
				if(wantExit()) return;
		}
					
		Xilanh_mode_off;
		Xilanh50_on;
		
		Reset_encoder_ngang();
		robotRun(fix_goc_d - _robotIMUAngle,60);
		robotRotate(-860,0.8,0);
		while(abs(Encoder_ngang()) < encoder_stop -2)
		{
				Truot_Ra(60,4);
				Nang_Truc(50,8);		
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < encoder_stop -1)
		{
				Truot_Ra(60,4);
				Nang_Truc(50,8);		
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < encoder_stop)
		{
				Truot_Ra(60,4);
				Nang_Truc(50,8);		
				if(wantExit()) return;
		}
		
		robotRun(-850 - _robotIMUAngle,60);
		robotRotate(-860,0.8,0);
		while(cb_TTruoc || cb_PTruoc)
		{	
				Truot_Ra(100,4);
				Nang_Truc(50,8);	
				if(wantExit()) return;
		}
		mor_nang=2;
		robotStop(0);
	while(cb_mode)
		{
				Truot_Ra(120,5);
				if(wantExit()) return;
				if((!START && auto_mode	== 8) || (!L2 && RJOY_UD < 5)) break;
		}
	mor_ngang=2;
		Xilanh_mode_on;
		delay_ms(300);
		
					
}
// -----------------------------------------------------------------
// ----------------------  THA COT  --------------------------------
// -----------------------------------------------------------------
void THA_COT_DO(int encoder_stop)
{
		auto_mode=7;
		robotRotateFree(-0.4,0);
		while(cb_NC_9)					
		{
				Nang_Truc(35,9);
				if(wantExit()) return;
		}
		
		robotStop(0);
		mor_nang=2;
		Xilanh_mode_on;
		delay_ms(50);
		Xilanh_mode_off;	
		
		robotRotateFree(-0.4,0);
		while(cb_mode)
		{
				gp_update_btn();
				Nang_truc();
				if(wantExit()) return;
		}
		
		robotStop(0);
		mor_nang = 2;						
		Xilanh_kep_off;
		
		while(cb_Kep)		if(wantExit()) return;
		Xilanh_mode_on;
		
		Truot_Vao(200,8);		
		Reset_encoder_ngang();
		while(abs(Encoder_ngang()) < encoder_stop -2)
		{
				Truot_Vao(200,8);
				robotLineRun(850, 100);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < encoder_stop -1)
		{
				Truot_Vao(200,8);
				robotLineRun(850, 100);
				if(wantExit()) return;
		}
	  while(abs(Encoder_ngang()) < encoder_stop)
		{
				Truot_Vao(200,8);
				robotLineRun(850, 100);
				if(wantExit()) return;
		}
		
		Xilanh_mode_off;	
		
		mor_nang=2;
		mor_ngang=2;
		
		robotStop(2);
		
		while(cb_Tay)		if(wantExit()) return;	
		
		Truot_Ra_While(160,4);
		Truot_Ra_While(80,5);
}

void THA_CAUTHANG_DO()
{
		Xilanh_kep_off;
		while(cb_Kep)		if(wantExit()) return;
		Truot_Vao(200,8);
	
		Reset_encoder_doc();
		robotRun(900- _robotIMUAngle,100);
		robotRotate(-900,0.3,0);
		while(abs(Encoder_doc()) < 2498)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 2499)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 2500)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}
		
		Xilanh50_off;
		
		Reset_encoder_ngang();
		robotRun(1800 -_robotIMUAngle,100);
		robotRotate(-900,0.3,0);
		while(abs(Encoder_ngang()) < 3998)
		{
				Truot_Vao(20,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 3999)
		{
				Truot_Vao(20,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 4000)
		{
				Truot_Vao(20,8);
				if(wantExit()) return;
		}
		
		Xilanh_mode_off;
		
		robotStop(0);		
}
//===================================================================================================================
//===================================================================================================================
//===================================================================================================================
//============================================= SAN XANH ============================================================
//===================================================================================================================
//===================================================================================================================
//===================================================================================================================
void  AUTO_BB_XANH(int fix_goc)
{						
		int noise;
	
		
		auto_mode=1;
		Xilanh53_ve_on;
	
		Reset_encoder_ngang();				
		robotRun(950 - _robotIMUAngle,200);
		robotRotate(fix_goc,0.5,0);
		while(abs(Encoder_ngang()) < 9998)													// chay ngang		
		{			
				Nang_Truc(20,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 9999)													// chay ngang		
		{			
				Nang_Truc(20,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 10000)													// chay ngang		
		{			
				Nang_Truc(20,3);
				if(wantExit()) return;
		}
						
		Xilanh53_ve_off;
		bitha=1;
		Xilanh_mode_on;
		Reset_encoder_doc();
		robotRun(1300 - _robotIMUAngle,200);
		robotRotate(fix_goc,0.5,0);
		while(abs(Encoder_doc()) < 9998)
		{		
				Nang_Truc(50,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 9999)
		{		
				Nang_Truc(50,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 10000)
		{		
				Nang_Truc(50,3);
				if(wantExit()) return;
		}
		for(noise=0;noise<10;noise++)
		{
			while(cb_quang_bb_xanh)																				// kiem tra cam bien quang
			{		
					Nang_Truc(80,3);
					if(wantExit()) return;
			}
		}
						
		Xilanh50_on;
		
		
		Reset_encoder_ngang();
		robotRun(900 - _robotIMUAngle,100);
		robotRotate(fix_goc,-0.3,0);
		while(abs(Encoder_ngang()) < 7998)
		{		
				Truot_Ra(50,3);
				Nang_Truc(100,2);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 7999)
		{		
				Truot_Ra(50,3);
				Nang_Truc(100,2);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 8000)
		{		
				Truot_Ra(50,3);
				Nang_Truc(100,2);
				if(wantExit()) return;
		}
		
		robotRun(900 - _robotIMUAngle,60);
		robotRotate(fix_goc,-0.3,0);
		while(_ADC1_Value[0] > 1500)																	 // nhan laze giua chay cham lai		
		{		
				Nang_Truc(100,2);
				Truot_Ra(50,3);
				if(wantExit()) return;
		}
					
		Reset_encoder_ngang();
		robotRun(900 - _robotIMUAngle,28);
		robotRotate(fix_goc,-0.3,0);
		while(_ADC1_Value[1] > 460)															// dung bang laze ben phai
		{
				Ha_Truc(30,7);
				Truot_Ra(50,3);
				if(wantExit()) return;
		}
		
		
		
		Xilanh_mode_off;
		robotRun(-_robotIMUAngle,50);
		while(cb_NC_7)
		{
				if(!cb_TTruoc && !cb_PTruoc)   robotStop(0);
				Ha_Truc(150,7);
				Truot_Ra(60,3);
				if(wantExit()) return;
		}
		
		robotStop(0);
		mor_ngang=2;
		mor_nang=2;
		bitha=0;
}
// ----------------------------------------------------------------
// ---------------------- XOAY BAP BENH ---------------------------
// ----------------------------------------------------------------
void XOAY_BAPBENH_XANH()
{																			
		auto_mode=2;
		bitha=0;
	
		Xilanh_mode_off;
		Xilanh_kep_off;									// nha kep
		while(cb_Kep) if(wantExit()) return;		
	
		Nang_Truc_While(240,6);													// nang truc qua bap benh
		Xilanh50_off,Xilanh53_ra_off,Xilanh53_ve_on;						
		Reset_encoder_ngang();		
		robotLineRun(-880, 250);
		while(abs(Encoder_ngang())<1998)
		{				
				robotLineRun(-880, 250);
				Nang_Truc(20,3);
				Truot_Vao(200,8);
		  	if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<1999)
		{				
				robotLineRun(-880, 250);
				Nang_Truc(20,3);
				Truot_Vao(200,8);
		  	if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<2000)
		{				
				robotLineRun(-880, 250);
				Nang_Truc(20,3);
				Truot_Vao(200,8);
		  	if(wantExit()) return;	
		}
		
		Reset_encoder_ngang();
		while(abs(Encoder_ngang()) < 36498)
		{
				robotLineRun(-850, 250);									
				Nang_Truc(60,3);
				if(abs(Encoder_ngang()) > 19000)  Truot_Ra(120,1); 
				if(wantExit()) return;						
		}
		while(abs(Encoder_ngang()) < 36499)
		{
				robotLineRun(-850, 250);									
				Nang_Truc(60,3);
				if(abs(Encoder_ngang()) > 19000)  Truot_Ra(120,1); 
				if(wantExit()) return;						
		}
		while(abs(Encoder_ngang()) < 36500)
		{
				robotLineRun(-850, 250);									
				Nang_Truc(60,3);
				if(abs(Encoder_ngang()) > 19000)  Truot_Ra(120,1); 
				if(wantExit()) return;						
		}
		
		Reset_encoder_ngang(); 
		while(abs(Encoder_ngang())<4998)
		{
				Nang_Truc(60,3);	
				Truot_Ra(120,1); 
				robotLineRun(-850, 150);
				robotRotateFree(0.1,0);
				if(wantExit()) return;	
		} 
		while(abs(Encoder_ngang())<4999)
		{
				Nang_Truc(60,3);	
				Truot_Ra(120,1); 
				robotLineRun(-850, 150);
				robotRotateFree(0.1,0);
				if(wantExit()) return;	
		} 
		while(abs(Encoder_ngang())<5000)
		{
				Nang_Truc(60,3);	
				Truot_Ra(120,1); 
				robotLineRun(-850, 150);
				robotRotateFree(0.1,0);
				if(wantExit()) return;	
		} 
		
		robotStop(0);
		delay_ms(250);
		bap_benh_auto(3);		
//================================== CHAY VE DON ROBOT =================================				\
		
		Xilanh53_ve_off;
		Reset_encoder_ngang();  
		while(abs(Encoder_ngang())<3998)											// chay cham 4000	
		{
				robotLineRun(870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<3999)											// chay cham 4000	
		{
				robotLineRun(870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<4000)											// chay cham 4000	
		{
				robotLineRun(870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		
		Xilanh53_ra_on;
		Xilanh50_on;
		
		Reset_encoder_ngang();	
		while(abs(Encoder_ngang())<31998)											// chay nhanh 35000
		{  	
				robotLineRun(850, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)		Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)		Truot_Ra(40,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang())<31999)											// chay nhanh 35000
		{  	
				robotLineRun(850, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)		Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)		Truot_Ra(40,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang())<32000)											// chay nhanh 35000
		{  	
				robotLineRun(850, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)		Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)		Truot_Ra(40,3);
				if(wantExit()) return;
		}
		
		Reset_encoder_ngang();
		while(_ADC1_Value[0] > 500)																// kiem tra laze dung robot
		{
				Truot_Ra(40,3);
				Ha_Truc(50,6);
				robotLineRun(820, 120); 
				if(wantExit()) return;
		}
	
		Xilanh50_on;
		while(_robotIMUAngle > 5)
		{
				Truot_Ra(40,3);
				Ha_Truc(50,6);
				robotLineRun(850, 80);
				robotRotateFree(-0.2,0);
				if(wantExit()) return;
		}
		
		robotStop(0);					
		Ha_Truc_While(240,7);					
}
// -----------------------------------------------------------------
// ----------------------  XICH DU XANH  ---------------------------
// -----------------------------------------------------------------
void XICH_DU_XANH(int Stop_Roate, int Roate)
{		
		int i,noise;
		auto_mode=3;
		Xilanh_kep_on;
		delay_ms(200);											// kep delay 100ms
		Xilanh53_ve_off;
		Xilanh50_on;
		Xilanh53_ra_on;				// cho canh tay nam ngang
	
		Nang_Truc(100,5);																	// nang truc toc do 100
		Reset_encoder_doc();	
		robotRun(1150 - _robotIMUAngle,250);
		robotRotate(1,0.3,0);		
		while(abs(Encoder_doc()) < 398)												// VN->CHAMPION
			{
				Nang_Truc(100,5);
				Truot_Vao(150,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 399)												// VN->CHAMPION
			{
				Nang_Truc(100,5);
				Truot_Vao(150,8);
				if(wantExit()) return;
			}		
		while(abs(Encoder_doc()) < 400)												// VN->CHAMPION
			{
				Nang_Truc(100,5);
				Truot_Vao(150,8);
				if(wantExit()) return;
			}
		
		Reset_encoder_ngang();				
		robotRun(1200 - _robotIMUAngle,255);					// so cang lon cang gan xich du
		robotRotate(1700, 0.5, 0);
		while(abs(_robotIMUAngle) < Stop_Roate)							// bat dau chay ngang         -5200
		{		
				Truot_Vao(120,8);
				Nang_Truc(50,2);
				if(abs(_robotIMUAngle) > 1480)   Xilanh_cheo_on;						
				if(wantExit()) return;
		}
		
		
		Xilanh_cheo_on;				
				Reset_encoder_ngang();
		robotRun(900 - _robotIMUAngle,120);
		robotRotate(Roate,0.3,0);

		while(_ADC1_Value[0] > 700)														 // nhan laze dem encoder, tat mode
			{		
					Truot_Vao(20,8);
					Nang_Truc(150,2);
					if(wantExit()) return;
			}	
		while(_ADC1_Value[1] > 350)														 // nhan laze dem encoder, tat mode
			{		
					Truot_Vao(20,8);
					Nang_Truc(150,2);
					if(wantExit()) return;
			}	
		Xilanh_mode_on;			
					Reset_encoder_ngang();
		robotRun(900 - _robotIMUAngle,80);
		robotRotate(Roate,0.3,0);
		while(abs(Encoder_ngang()) < 2998)
		{
				Truot_Vao(20,8);	
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang()) < 2999)
		{
				Truot_Vao(20,8);	
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang()) < 3000)
		{
				Truot_Vao(20,8);	
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}
		
		robotRun(900 - _robotIMUAngle,50);
		robotRotate(Roate,0.3,0);
			
		
		for(i=0;i<10;i++)
		{
			while(cb_XICHDU_T || cb_XICHDU_P)
			{		
				Nang_Truc(150,2);
				if(wantExit()) return;	
			}
		}
		
				Reset_encoder_ngang();
		while(abs(Encoder_ngang()) < 99)
		{		
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang()) < 100)
		{		
				Nang_Truc(150,2);
				if(wantExit()) return;	
		}
		
								
		
		Reset_encoder_doc();
		robotRun(1800 - _robotIMUAngle,40);
		robotRotate(Roate,0.3,0);
		while(cb_XICHDU)										 // robot stop neu nhan laze xich du
		{		
				Truot_Ra(150,1);
				Nang_Truc(150,2);
				if(wantExit()) return;
		}
		
			
		robotStop(0);	
		Xilanh_mode_off;
		Truot_Ra_While(240,1);								//  dua het canh tay ra 
		Ha_Truc_While(120,3);									//  ha truc	
		Truot_Vao_While(150,6);				
		
}
// -----------------------------------------------------------------
// ----------------------  BAN XICH DU XANH  -----------------------
// -----------------------------------------------------------------
void BAN_XICHDU_XANH()
 {
		auto_mode=4;
	
		Xilanh_mode_on;
		delay_ms(100);
		Xilanh_mode_off;
		Xilanh_kep_off;
		Xilanh_kep_off;
		Xilanh_cheo_on;
	
		while(cb_Kep)		if(wantExit()) return;
	
		Xilanh53_ra_off;
		Xilanh53_ve_on;
		Xilanh50_off;		
		while(_ADC1_Value[2] < 2100)		if(wantExit()) return;
	
		Xilanh_ban_on;
		while(cb_BAN)		if(wantExit()) return;		
	
		Xilanh_ban_off;
	
		Reset_encoder_doc();
		robotRun(-25 - _robotIMUAngle,100);
		robotRotate(1755,-0.2,0);
		while(abs(Encoder_doc()) < 3998)
		{		 
				Nang_Truc(100,2);
				Truot_Vao(100,3);				
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 3999)
		{		 
				Nang_Truc(100,2);
				Truot_Vao(100,3);				
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 4000)
		{		 
				Nang_Truc(100,2);
				Truot_Vao(100,3);				
				if(wantExit()) return;
		}
		
		robotRun(-25 -_robotIMUAngle,60);
		robotRotate(1755,-0.2,0);
		while(abs(Encoder_doc()) < 5998)
		{		 
				Nang_Truc(100,2);
				Truot_Vao(100,3);
				Xilanh50_on;
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 5999)
		{		 
				Nang_Truc(100,2);
				Truot_Vao(100,3);
				Xilanh50_on;
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 6000)
		{		 
				Nang_Truc(100,2);
				Truot_Vao(100,3);
				Xilanh50_on;
				if(wantExit()) return;
		}
		
		mor_nang=2;
		robotStop(2);
}

// -----------------------------------------------------------------
// ----------------------  DON XICH DU -----------------------------
// -----------------------------------------------------------------
void DON_XICHDU_XANH()
{	
		auto_mode=5;
		Xilanh_cheo_on;
		Xilanh_kep_off;
		Xilanh53_ve_off;
		Xilanh53_ra_on;
		Xilanh50_on;
	
		Reset_encoder_doc();
		robotRun(1800 -_robotIMUAngle ,60);
		robotRotate(1755,0.2,0);
		while(cb_XICHDU)
		{		 
				Truot_Ra(80,6);				
				if(wantExit()) return;
		}
		mor_nang=2;
		robotStop(2);
		while(cb_DON_XICHDU_T && cb_DON_XICHDU_P)			
				{
					Truot_Ra(120,6);
					if(wantExit()) return;
				}
				Ha_Truc_While(200,3);
						//mor_nang=2;
}

// -----------------------------------------------------------------
// ----------------------  COT XANH  ---------------------------------
// -----------------------------------------------------------------
void LEO_COT_XANH(int fix_cot)
{
		int noise;
		auto_mode=6;
	
		Xilanh_kep_on;
			delay_ms(200);
		Xilanh_mode_on;
			delay_ms(300);
		Xilanh_cheo_off;
		Xilanh50_on, Xilanh53_ra_on, Xilanh53_ve_off;
	
		Nang_Truc(150,1);	
	for(noise=0;noise<10;noise++)		  Truot_Ra_While(250,1);
			
	for(noise=0;noise<10;noise++)			Nang_Truc_While(240,1);							
		Truot_Vao(250,8);
	
		robotRun(0 + _robotIMUAngle,70);
		robotRotate(1755,0.3,0);
	
		robotRun(0 + _robotIMUAngle,70);
		robotRotate(1755,0.3,0);
		
		robotRun(0 + _robotIMUAngle,70);
		robotRotate(1755,0.3,0);

		while(abs(Encoder_doc()) < 1498)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 1499)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 1500)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
 		robotRun(0 + _robotIMUAngle,120);
		robotRotate(1755,0.3,0);
		while(abs(Encoder_doc()) < 2998)
			{		 
				Ha_Truc(70,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 2999)
			{		 
				Ha_Truc(70,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 3000)
			{		 
				Ha_Truc(70,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		
		Xilanh_mode_off;
		Xilanh50_off, Xilanh53_ra_off, Xilanh53_ve_on;
	
			Reset_encoder_doc();
		
		robotRun(-270 + _robotIMUAngle,220);   //-1760.............-1150/// giam
		robotRotate(800,-0.4,0);
		while(abs(Encoder_doc()) < 21998)
		{
				flash_bit=1;
				Ha_Truc(100,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 21999)
		{
				flash_bit=1;
				Ha_Truc(100,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 22000)
		{
				flash_bit=1;
				Ha_Truc(100,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
		}
		Reset_encoder_ngang();
		robotRun(fix_cot- _robotIMUAngle,400);			// so cang lon cang gan cot
		robotRotate(900,-0.5,0);
		
		while(_ADC1_Value[0] > 1000)
		{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
		}
		
		
		
		Reset_encoder_ngang();
		robotRun(fix_cot- _robotIMUAngle,400);
		robotRotate(900,-0.5,0);
		while(abs(Encoder_ngang()) < 21198)
		{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 21199)
		{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 21200)
		{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
		}
		
		Xilanh_mode_on;
		robotRun(fix_cot- _robotIMUAngle,120);
		robotRotate(900,-0.5,0);
				mor_nang=0;
		while(_ADC1_Value[0] > 1500)
		{			
				Truot_Vao(20,8);
				if(wantExit()) return;
		}
		
		Xilanh_mode_off;
		
		
		Reset_encoder_ngang();
		robotRun(fix_cot- _robotIMUAngle,80);
		robotRotate(755,-1.2,0);
		while(abs(Encoder_ngang()) < 3998)
		{
				Truot_Ra(100,5);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 3999)
		{
				Truot_Ra(100,5);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 4000)
		{
				Truot_Ra(100,5);
				if(wantExit()) return;
		}
	
		Xilanh_mode_on;
		
		mor_nang=0;
		mor_ngang=2;
			
		robotLineDetect(60);
						
		Xilanh_mode_off;
		robotStop(0);
		
	for(noise=0;noise<5;noise++)
			{
			while(cb_mode)
				{
					Truot_Ra(80,5);
					robotLineRun(870,60); 
					if(wantExit()) return;
				}
			} 
		robotRotateFree(0.5,0);
	for(noise=0;noise<100;noise++)
		{	
				gp_update_btn();
				if(!START || (!L2 && RJOY_UD > 253))		break;	
				if(wantExit()) return;
		}
		robotStop(0);
}
// -----------------------------------------------------------------
// ----------------------  CAU THANG  ------------------------------
// -----------------------------------------------------------------
void CAUTHANG_XANH(int fix_goc,int encoder_stop)
{
		auto_mode = 8;
	
		Xilanh_kep_on; 
		delay_ms(300);
		Xilanh_mode_on;	
	
		while(cb_mode)
		{
				gp_update_btn();
				Nang_truc();	
				if(wantExit()) return;	
		}			
			
		Xilanh_mode_off;
		Truot_Vao(200,8);
		Reset_encoder_ngang();
		
		robotRun(2000 - _robotIMUAngle,250);
		robotRotate(890,-0.3,0);
		while(abs(Encoder_ngang()) < 9998)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}	
		while(abs(Encoder_ngang()) < 9999)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}	
		while(abs(Encoder_ngang()) < 10000)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}			
		
							
		Reset_encoder_ngang();
			
		robotRun(fix_goc - _robotIMUAngle,250);
		robotRotate(890,-0.5,0);
		while(abs(Encoder_ngang()) < 20998)						// bat dau chay cham lai
		{
				Truot_Vao(50,8);
				Nang_Truc(50,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 20999)						// bat dau chay cham lai
		{
				Truot_Vao(50,8);
				Nang_Truc(50,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 21000)						// bat dau chay cham lai
		{
				Truot_Vao(50,8);
				Nang_Truc(50,8);
				if(wantExit()) return;
		}
		
		Xilanh_mode_on;
		
		robotRun(fix_goc - _robotIMUAngle,100);
		robotRotate(890,-0.5,0);				
		while(_ADC1_Value[1] > 200)											 // kiem tra laze nhan thanh cau thang
		{
				Nang_Truc(50,8);		
				if(wantExit()) return;
		}
		
		Xilanh_mode_off;
		Xilanh50_on;
		
		Reset_encoder_ngang();
		robotRun(fix_goc - _robotIMUAngle,80);
		robotRotate(890,-0.3,0);	
		while(abs(Encoder_ngang()) < encoder_stop -2)
		{
				Truot_Ra(50,4);
				Nang_Truc(50,8);		
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < encoder_stop -1)
		{
				Truot_Ra(50,4);
				Nang_Truc(50,8);		
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < encoder_stop)
		{
				Truot_Ra(50,4);
				Nang_Truc(50,8);		
				if(wantExit()) return;
		}			
		
		robotRun(850 - _robotIMUAngle,60);
		robotRotate(890,-0.5,0);
		while(cb_TTruoc && cb_PTruoc)
		{	
				Truot_Ra(100,4);
				Nang_Truc(50,8);	
				if(wantExit()) return;
		}
		mor_nang=2;
		robotStop(0);
	while(cb_mode)
		{
				Truot_Ra(120,5);
				if(wantExit()) return;
				if((!START && auto_mode	== 8) || (!L2 && RJOY_UD < 5)) break;
		}
	mor_ngang=2;
		Xilanh_mode_on;
		delay_ms(300);		
}

// -----------------------------------------------------------------
// ----------------------  THA COT  --------------------------------
// -----------------------------------------------------------------
void THA_COT_XANH(int encoder_stop)
{
		auto_mode = 7;
		robotRotateFree(0.2,0);
	
		while(cb_NC_9)					
		{
				Nang_Truc(35,9);
				if(wantExit()) return;
		}
		
		mor_nang=2;
		Xilanh_mode_on;
		delay_ms(50);
		Xilanh_mode_off;	

		robotRotateFree(0.2,0);
		while(cb_mode)
		{
				Nang_truc();
				if(wantExit()) return;
		}			
		
		robotStop(0);
		Xilanh_kep_off;
		
		while(cb_Kep)		if(wantExit()) return;
		
		Xilanh_mode_on;
						
		Truot_Vao(200,8);		
		Reset_encoder_ngang();
		while(abs(Encoder_ngang()) < encoder_stop -2)
		{
				Truot_Vao(200,8);
				robotLineRun(-850, 100);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < encoder_stop -1)
		{
				Truot_Vao(200,8);
				robotLineRun(-850, 100);
				if(wantExit()) return;
		}
	  while(abs(Encoder_ngang()) < encoder_stop)
		{
				Truot_Vao(200,8);
				robotLineRun(-850, 100);
				if(wantExit()) return;
		}
		
		
		mor_nang=2;
		mor_ngang=2;
		Xilanh_mode_off;
		
		robotStop(0);
		
		while(cb_Tay)		
			{
				Truot_Vao(50,8);	
				if(wantExit()) return;	
			}
		Truot_Ra_While(150,4);
		Truot_Ra_While(80,6);
}

void THA_CAUTHANG_XANH()
{
		Xilanh_kep_off;
		while(cb_Kep)		if(wantExit()) return;
	
		Truot_Vao(200,8);	
		Reset_encoder_doc();
		Xilanh_mode_off;
		robotRun(900+ _robotIMUAngle,100);
		robotRotate(900,0.3,0);
		while(abs(Encoder_doc()) < 2498)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 2499)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 2500)
		{
				Truot_Vao(200,8);
				if(wantExit()) return;
		}
		
		Xilanh50_off;
		Reset_encoder_ngang();
		
		robotRun(1800-_robotIMUAngle,100);
		robotRotate(900,0.3,0);
		while(abs(Encoder_ngang()) < 3998);
		{
				Truot_Vao(20,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 3999);
		{
				Truot_Vao(20,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 4000);
		{
				Truot_Vao(20,8);
				if(wantExit()) return;
		}
		
		robotStop(0);	
			
}




//===========================================================================
//================================ SUA LOI BAP BENH =========================
//===========================================================================

void fix_bapbenh_do()
	{
				bap_benh_auto(3);		
				auto_mode=2;
//================================== CHAY VE DON ROBOT =================================				

				Xilanh53_ve_off;
		Reset_encoder_ngang();
		while(abs(Encoder_ngang())<3998)											// chay cham 4000	
		{
				robotLineRun(-870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<3999)											// chay cham 4000	
		{
				robotLineRun(-870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<4000)											// chay cham 4000	
		{
				robotLineRun(-870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		
		Xilanh53_ra_on,Xilanh50_on;
		Reset_encoder_ngang();	
		while(abs(Encoder_ngang())<31998)											// chay nhanh 35000
		{  	
				robotLineRun(-810, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)						Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)						Truot_Ra(50,2);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang())<31999)											// chay nhanh 35000
		{  	
				robotLineRun(-810, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)						Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)						Truot_Ra(50,2);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang())<32000)											// chay nhanh 35000
		{  	
				robotLineRun(-810, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)						Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)						Truot_Ra(50,2);
				if(wantExit()) return;
		}
		
		Reset_encoder_ngang();
		while(_ADC1_Value[0] > 500)																// kiem tra laze dung robot
		{
				Truot_Ra(50,2);
				Ha_Truc(50,6);
				robotLineRun(-810, 120); 
				if(wantExit()) return;
		}
		
//		robotCurve(-920 - _robotIMUAngle,60 , 1);		
		while(_robotIMUAngle < -15)
		{
				Truot_Ra(50,2);
				Ha_Truc(50,6);
				robotLineRun(-850, 80);
				robotRotateFree(0.3,0);
				if(wantExit()) return;
		}
			
		robotStop(0);		
		mor_ngang=2;
		Ha_Truc_While(220,7);					
		Xilanh53_ra_on;
		Xilanh50_on;				
	}
	
void fix_bapbenh_xanh()
	{
				bap_benh_auto(3);		
				auto_mode=2;
//================================== CHAY VE DON ROBOT =================================				\
		
						
		Xilanh53_ve_off;
		Reset_encoder_ngang();  
		while(abs(Encoder_ngang())<3998)											// chay cham 4000	
		{
				robotLineRun(870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<3999)											// chay cham 4000	
		{
				robotLineRun(870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		while(abs(Encoder_ngang())<4000)											// chay cham 4000	
		{
				robotLineRun(870, 250);
				Nang_Truc(80,2);
				Truot_Vao(200,8);	
				if(wantExit()) return;	
		}
		
		Xilanh53_ra_on;
		Xilanh50_on;
		
		Reset_encoder_ngang();	
		while(abs(Encoder_ngang())<31998)											// chay nhanh 35000
		{  	
				robotLineRun(850, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)		Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)		Truot_Ra(40,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang())<31999)											// chay nhanh 35000
		{  	
				robotLineRun(850, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)		Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)		Truot_Ra(40,3);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang())<32000)											// chay nhanh 35000
		{  	
				robotLineRun(850, 250);       								
				Ha_Truc(50,6);		
				if(abs(Encoder_ngang())<20000)		Truot_Vao(40,8);	
				if(abs(Encoder_ngang())>21000)		Truot_Ra(40,3);
				if(wantExit()) return;
		}
		
		Reset_encoder_ngang();
		while(_ADC1_Value[0] > 500)																// kiem tra laze dung robot
		{
				Truot_Ra(40,3);
				Ha_Truc(50,6);
				robotLineRun(820, 120); 
				if(wantExit()) return;
		}
	
		Xilanh50_on;
		while(_robotIMUAngle > 5)
		{
				Truot_Ra(40,3);
				Ha_Truc(50,6);
				robotLineRun(850, 80);
				robotRotateFree(-0.2,0);
				if(wantExit()) return;
		}
		
		robotStop(0);					
		Ha_Truc_While(220,7);	
		Xilanh53_ra_on;
		Xilanh50_on;		
	}

	
//===========================================================================
//================================ SUA LOI XICH DU ==========================
//===========================================================================
void fix_xichdu_do()
	{			Xilanh_mode_off;
				Reset_encoder_doc();
				auto_mode=3;
					Xilanh_cheo_on;
							Xilanh53_ve_off;
									Xilanh53_ra_on;
											Xilanh50_on;
		
				robotRun(-1760 - _robotIMUAngle,40);
				robotRotate(-1755,0.2,0);
			
		while(cb_XICHDU)										 								// robot stop neu nhan laze xich du
		{	
				Truot_Vao(50,8);
				Nang_Truc(150,2);
				if(wantExit()) return;
		}
		
					
				robotStop(0);
				Truot_Ra_While(200,1);															//  dua het canh tay ra 
				Ha_Truc_While(150,3);																//  ha truc	
				Truot_Vao_While(150,6);	
	}

	
void fix_xichdu_xanh()
	{
			auto_mode=3;Xilanh_mode_off;
					Xilanh_cheo_on;
							Xilanh53_ve_off;
									Xilanh53_ra_on;
											Xilanh50_on;
						
			Reset_encoder_doc();
			robotRun(0,40);
			robotRotate(1750,0.3,0);
		
		while(cb_XICHDU)										 // robot stop neu nhan laze xich du
			{		
						Truot_Vao(50,8);
						Nang_Truc(150,2);
						if(wantExit()) return;
			}
		
					
				robotStop(0);		
				Truot_Ra_While(200,1);								//  dua het canh tay ra 
				Ha_Truc_While(150,3);									//  ha truc	
				Truot_Vao_While(150,6);						
	}
	

//===========================================================================
//================================ SUA LOI LEO COT ==========================
//===========================================================================
void fix_leocot_do()
{
	int noise;
			auto_mode=6;
		Xilanh_mode_on;
			robotLineDetect(60);	
				robotStop(0);
			Truot_Ra_While(150,6);
		Xilanh_mode_off;
	
	for(noise=0;noise<5;noise++)
			{
			while(cb_mode)
				{
					Truot_Ra(80,6);
					robotLineRun(-850,60); 
					if(wantExit()) return;
				}
			}
		mor_ngang=2;
		robotRotateFree(-0.5,0);
		for(noise=0;noise<80;noise++)
		{	
				gp_update_btn();
				if(!START || (!L2 && RJOY_UD > 253))		break;	
					if(wantExit()) return;
		}
		robotStop(0);
}


void fix_leocot_xanh()
{
	int noise;
			auto_mode=6;
		Xilanh_mode_on;
			robotLineDetect(50);	
				robotStop(0);
			Truot_Ra_While(120,5);
		Xilanh_mode_off;
	
	for(noise=0;noise<5;noise++)
			{
			while(cb_mode)
				{
					Truot_Ra(80,6);
					robotLineRun(870,60); 
					if(wantExit()) return;
				}
			} 
		robotRotateFree(0.5,0);
	for(noise=0;noise<100;noise++)
		{	
				gp_update_btn();
				if(!START || (!L2 && RJOY_UD > 253))		break;	
				if(wantExit()) return;
		}
		robotStop(0);
}



//===========================================================================
//================================ SUA LOI CAU THANG ========================
//===========================================================================
void fix_cauthang_do()
	{	
				auto_mode=8;
				Nang_Truc_While(150,8);
		Xilanh50_on;
				robotLineDetect(60);
	while(cb_mode)
		{
				Truot_Ra(120,5);
				if(wantExit()) return;
				if((!START && auto_mode	== 8) || (!L2 && RJOY_UD < 5)) break;
		}
	mor_ngang=2;
		Xilanh_mode_on;
				mor_nang=2;
				mor_ngang=0;		
	}
void fix_cauthang_xanh()
	{	
				auto_mode=8;
				Nang_Truc_While(150,8);
		Xilanh50_on;
				robotLineDetect(60);
	while(cb_mode)
		{
				Truot_Ra(120,5);
				if(wantExit()) return;
				if((!START && auto_mode	== 8) || (!L2 && RJOY_UD < 5)) break;
		}
	mor_ngang=2;
		Xilanh_mode_on;
				mor_nang=2;
				mor_ngang=0;		
	}	






void LEO_COT_DO_1(int fix_cot_d)
{
		int noise;
		auto_mode=6;
		Xilanh_kep_on;
		delay_ms(400);
		Xilanh_cheo_off;
		Xilanh50_on, Xilanh53_ra_on, Xilanh53_ve_off;
	
		Nang_Truc(150,1);	
	for(noise=0;noise<10;noise++)		  Truot_Ra_While(250,1);
			
	for(noise=0;noise<10;noise++)			Nang_Truc_While(240,1);							
		Truot_Vao(250,8);
		Reset_encoder_doc();
		
		robotRun(0 - _robotIMUAngle,70);
		robotRotate(-1760,0.3,0);
	
		robotRun(0 - _robotIMUAngle,70);
		robotRotate(-1760,0.3,0);
	
		robotRun(0 - _robotIMUAngle,70);
		robotRotate(-1760,0.3,0);
		
		while(abs(Encoder_doc()) < 1498)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 1499)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 1500)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
			
		
		robotRun(0 - _robotIMUAngle,120);
		robotRotate(-1760,0.3,0);
	
		while(abs(Encoder_doc()) < 2998)
			{		 
				Ha_Truc(120,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 2999)
			{		 
				Ha_Truc(120,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 3000)
			{		 
				Ha_Truc(120,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
			
		Xilanh50_off, Xilanh53_ra_off, Xilanh53_ve_on;
			
				Reset_encoder_doc();
		
		robotRun(270 + _robotIMUAngle,220);   //-1760.............-1150/// giam
		robotRotate(-800,0.4,0);
		
		while(abs(Encoder_doc()) < 20598)
			{
				flash_bit=1;
				Ha_Truc(120,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 20599)
			{
				flash_bit=1;
				Ha_Truc(120,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 20600)
			{
				flash_bit=1;
				Ha_Truc(120,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
			}
			
		Reset_encoder_ngang();
		
		robotRun(-fix_cot_d - _robotIMUAngle,400);			// so cang lon cang gan cot
		robotRotate(-900,0.4,0);
			
		while(_ADC1_Value[0] > 1000)
			{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
			}
		
		
		
		Reset_encoder_ngang();
		robotRun(-fix_cot_d - _robotIMUAngle,400);
		robotRotate(-900,0.5,0);
		while(abs(Encoder_ngang()) < 19998)
			{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 19999)
			{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 20000)
			{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
			}
		
		Xilanh_mode_on;
		
		robotRun(-fix_cot_d- _robotIMUAngle,150);
		robotRotate(-900,0.5,0);
				mor_nang=0;
		while(_ADC1_Value[0] > 1500)
			{
				Truot_Vao(20,8);
				if(wantExit()) return;
			}
		
		Xilanh_mode_off;
		
		
		Reset_encoder_ngang();
		robotRun(-fix_cot_d - _robotIMUAngle,80);
		robotRotate(-760,1.2,0);
		while(abs(Encoder_ngang()) <2998)
			{
				Truot_Ra(120,5);
				if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) <2999)
			{
				Truot_Ra(120,5);
				if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) <3000)
			{
				Truot_Ra(120,5);
				if(wantExit()) return;
			}
		
		Xilanh_mode_on;
			
		mor_nang=0;
		mor_ngang=2;
			
		robotLineDetect(60);
		
		robotStop(0);
		Xilanh_mode_off;
		
		for(noise=0;noise<5;noise++)
			{
			while(cb_mode)
				{
					Truot_Ra(80,6);
					robotLineRun(-850,60); 
					if(wantExit()) return;
				}
			}
		mor_ngang=2;
		robotRotateFree(-0.5,0);
		for(noise=0;noise<80;noise++)
		{	
				gp_update_btn();
				if(!START || (!L2 && RJOY_UD > 253))		break;	
					if(wantExit()) return;
		}
		robotStop(0);	
}	






// -----------------------------------------------------------------
// ----------------------  COT XANH  ---------------------------------
// -----------------------------------------------------------------
void LEO_COT_XANH_1(int fix_cot)
{
		int noise;
		auto_mode=6;
	
		Xilanh_kep_on;
			delay_ms(400);
		Xilanh_cheo_off;
		Xilanh50_on, Xilanh53_ra_on, Xilanh53_ve_off;
	
		Nang_Truc(150,1);	
	for(noise=0;noise<10;noise++)		  Truot_Ra_While(250,1);
			
	for(noise=0;noise<10;noise++)			Nang_Truc_While(240,1);							
		Truot_Vao(250,8);
	
		robotRun(0 + _robotIMUAngle,70);
		robotRotate(1755,0.3,0);
	
		robotRun(0 + _robotIMUAngle,70);
		robotRotate(1755,0.3,0);
		
		robotRun(0 + _robotIMUAngle,70);
		robotRotate(1755,0.3,0);

		while(abs(Encoder_doc()) < 1498)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 1499)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 1500)
			{		 
				Nang_Truc(150,1);		
				Truot_Vao(250,8);
				if(wantExit()) return;
			}
 		robotRun(0 + _robotIMUAngle,120);
		robotRotate(1755,0.3,0);
		while(abs(Encoder_doc()) < 2998)
			{		 
				Ha_Truc(70,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 2999)
			{		 
				Ha_Truc(70,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		while(abs(Encoder_doc()) < 3000)
			{		 
				Ha_Truc(70,7);
				Truot_Vao(200,8);	
				if(wantExit()) return;
			}
		
		Xilanh50_off, Xilanh53_ra_off, Xilanh53_ve_on;
	
			Reset_encoder_doc();
		
		robotRun(-270 + _robotIMUAngle,220);   //-1760.............-1150/// giam
		robotRotate(800,-0.4,0);
		while(abs(Encoder_doc()) < 24998)
		{
				flash_bit=1;
				Ha_Truc(100,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 24999)
		{
				flash_bit=1;
				Ha_Truc(100,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_doc()) < 25000)
		{
				flash_bit=1;
				Ha_Truc(100,10);
				Truot_Vao(120,8);
				if(wantExit()) return;
		}
		Reset_encoder_ngang();
		robotRun(fix_cot- _robotIMUAngle,400);			// so cang lon cang gan cot
		robotRotate(900,-0.5,0);
		
		while(_ADC1_Value[0] > 1000)
		{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
		}
		
		
		
		Reset_encoder_ngang();
		robotRun(fix_cot- _robotIMUAngle,400);
		robotRotate(900,-0.5,0);
		while(abs(Encoder_ngang()) < 20998)
		{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 20999)
		{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 21000)
		{
				Ha_Truc(120,10);
				Truot_Vao(40,8);
				if(wantExit()) return;
		}
		
		Xilanh_mode_on;
		robotRun(fix_cot- _robotIMUAngle,120);
		robotRotate(900,-0.5,0);
				mor_nang=0;
		while(_ADC1_Value[0] > 1500)
		{			
				Truot_Vao(20,8);
				if(wantExit()) return;
		}
		
		Xilanh_mode_off;
		
		
		Reset_encoder_ngang();
		robotRun(fix_cot- _robotIMUAngle,80);
		robotRotate(755,-1.2,0);
		while(abs(Encoder_ngang()) < 3998)
		{
				Truot_Ra(100,6);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 3999)
		{
				Truot_Ra(100,6);
				if(wantExit()) return;
		}
		while(abs(Encoder_ngang()) < 4000)
		{
				Truot_Ra(100,6);
				if(wantExit()) return;
		}
	
		Xilanh_mode_on;
		
		mor_nang=0;
		mor_ngang=2;
			
		robotLineDetect(60);
						
		Xilanh_mode_off;
		robotStop(0);
		
	for(noise=0;noise<5;noise++)
			{
			while(cb_mode)
				{
					Truot_Ra(80,6);
					robotLineRun(870,60); 
					if(wantExit()) return;
				}
			} 
		robotRotateFree(0.5,0);
	for(noise=0;noise<100;noise++)
		{	
				gp_update_btn();
				if(!START || (!L2 && RJOY_UD > 253))		break;	
				if(wantExit()) return;
		}
		robotStop(0);
}