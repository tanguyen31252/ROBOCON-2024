
u8  modeAuto = 0, bit_1 = 1, bit_2 = 1, bit_3 = 1,ACC=10;
int ii=0;

extern unsigned char giu;
extern unsigned char _accAla;
extern  u32 CN;
extern u32 i;
extern vu32 pwm;
//==============================================================================


//==============================================================================
//==============================================================================

void tocdo_line(unsigned char d,unsigned char c)
{
	 if(d<c)
            {bit_tang_toc=1;bit_e_speed=1;}
    else    {bit_tang_toc=0;bit_e_speed=1;}

    speed=d;
    td_sau=c;
}
void tocdochay(unsigned char a,unsigned char b)
{
    if(a<b)     {bit_tang_toc=1;bit_e_speed=1;}
        else        {bit_tang_toc=0;bit_e_speed=1;}

   speed=a,td_sau=b;

}
																																																													

//void hatay_thoi(void)
//	{
//		kepnang_on;
//		kepthoi_on;
//		
//	}
void CB_quat_manh (void)
	{
		if(!CB_quat)
		{
			//quat(380);
			Quet_cam_bien();
			DK_do_duong_do();
			tocdochay(130,130);	
		
		}
		
	}
	
	void CB_quat_nhe (void)
	{
		if(!CB_quat)
		{
			//quat(360);
			tocdochay(100,100);
				Quet_cam_bien();
					DK_do_duong_do();
		}
	}

void robotGamePadControl(void)
{
		char tocdo = 25;
    if (!L1)   tocdo = 60;  
		 
    if(!UP && DOWN && LEFT && RIGHT)
   	{
				
				TD_trai(tocdo), TD_phai(tocdo), TD_truoc(2);
					
		}        	  
    else if(UP && DOWN && LEFT && !RIGHT) 	{TD_trai(20), TD_phai(-20), TD_truoc(20);}         
    else if(UP && !DOWN && LEFT && RIGHT)   {TD_trai(-25), TD_phai(-25), TD_truoc(0);}      
    else if(UP && DOWN && !LEFT && RIGHT)   {TD_trai(-20), TD_phai(20), TD_truoc(-20);}   
	
		else if(LJOY_UD < 64 && UP && DOWN && LEFT && RIGHT) 	TD_trai(tocdo), TD_phai(tocdo), TD_truoc(0);
		else if(LJOY_UD > 192 && UP && DOWN && LEFT && RIGHT)	TD_trai(-80), TD_phai(-80), TD_truoc(0); 
		else if(LJOY_LR < 64 && UP && DOWN && LEFT && RIGHT) 
		{
			
			TD_truoc(-50 ); TD_phai(-50); TD_trai(50);	
		}	//trai
		else if(LJOY_LR > 192 && UP && DOWN && LEFT && RIGHT)
		{
			
			TD_truoc(50); TD_phai(50); TD_trai(-50);			// phai
		}		
     else stopRobot(0);
}	

/*============================================================*/
/*========================== SAN XANH ==========================*/
/*============================================================*/
void xuatphat_xanh(void)				// 162700
{    
	
	kepthoi_off;
	resetencoderSau();
	while(abs(encoderSau())<100)
	{
		TD_trai(70),TD_truoc(-70),TD_phai(-70);
	}		
	
				truot(-100);	
				resetencoderSau();
	resetencoderSau();
	while(abs(encoderSau())<200)
	{
		TD_trai(120),TD_truoc(-125),TD_phai(-120);
	}
	resetencoderSau();
	while(abs(encoderSau())<150)
	{
		TD_trai(180),TD_truoc(-185),TD_phai(-180);
	}			
	resetencoderSau();	
	while(abs(encoderSau())<900)
	{
		TD_trai(250),TD_truoc(-253),TD_phai(-250);
	}
	resetencoderSau();
	while(abs(encoderSau())<250)
	{
		TD_trai(220),TD_truoc(-225),TD_phai(-220);
	}
	resetencoderSau();
	while(abs(encoderSau())<200)
	{
		TD_trai(180),TD_truoc(-185),TD_phai(-180);
	}
	
	resetencoderSau();
	while(abs(encoderSau())<150)
	{
		TD_trai(150),TD_truoc(-153),TD_phai(-150);
	}
	resetencoderSau();
	while(abs(encoderSau())<200)
	{
		TD_trai(100),TD_truoc(-100),TD_phai(-100);
	}
	TD_trai(60),TD_truoc(-60),TD_phai(-60);
		quat(340);
				//kepthoi_off;
				
				//run_ngang(0,speed);
					
				while(b0);
				stopRobot(0);
				ACC=0;
				quat(350);
				TD_trai(30),TD_truoc(-30),TD_phai(-30);
				while(b5);
				stopRobot(2);
				delay_ms(100);
				quat(360);
				kepnang_on;
				
				delay_ms(50);		
	
}

//-----------------------------------------------------------------//
//void xuatphat_xanh(void)				// 162700
//{    
//	resetencoderSau();
//		resetIMU();
//	delay_ms(10);
//		resetencoderSau();
//		resetIMU();
//	delay_ms(10);
//	
//	ACC=2;

//	tocdochay(60,100);
//	while(abs(encoderSau())<100)					
//				{				
//					run_ngang(0,speed);					
//				}
//				
//							
//			truot(-100);	
//				resetencoderSau();
//				ACC=2;
//				td_sau = 240;
//		
//	while(abs(encoderSau())<1100)					
//				{	
//					run_ngang(0,speed);									
//				}
//				
//				resetencoderSau();
//				ACC=0;
//			td_sau=200;
//	while(abs(encoderSau())<250)					
//				{	
//					run_ngang(0,speed);									
//				}
//				
//				resetencoderSau();
//				ACC=0;
//			td_sau=180;
//	while(abs(encoderSau())<200)					
//				{	
//					run_ngang(0,speed);									
//				}
//				
//				resetencoderSau();
//				ACC=0;
//			td_sau=140;
//	while(abs(encoderSau())<150)					
//				{	
//					run_ngang(0,speed);									
//				}
//				
//				resetencoderSau();
//				ACC=0;
//			td_sau=100;
//	while(abs(encoderSau())<150)					
//				{	
//					run_ngang(0,speed);									
//				}
//				
//				ACC=0;
//				truot(3);
//				resetencoderSau();
//			td_sau=60;
//	while(abs(encoderSau())<200)					
//				{				
//					run_ngang(0,speed);								
//				}
//				quat(310);
//				
//				ACC=0;
//				td_sau=20;
//				quat(310);
//				kepthoi_off;
//				
//				run_ngang(0,speed);
//					
//				while(b0);
//				stopRobot(0);
//				ACC=0;
//				td_sau=10;
//				run_ngang(0,speed);
//				while(b5);
//				stopRobot(2);
//				delay_ms(100);
//				quat(340);
//				kepnang_on;
//				
//				delay_ms(50);				
//				
//					
//}

void vungdoi_xanh(void) 
{
			resetEncoderDoc();
			ACC=10;
			tocdo_line(25,60);
			while(abs(encoderDoc())<30000)					
				{	
						
					Quet_cam_bien();
					DK_do_duong();
					quat(355);
					//nang(50);			
					CB_quat_nhe();
				}
				resetEncoderDoc();	
					tocdo_line(80,110);
			while(abs(encoderDoc())<30600)								//start
				{				
					
					Quet_cam_bien();
					DK_do_duong();
					quat(360);
					nang(0);
					CB_quat_nhe();
				}
				tocdo_line(120,140);
				resetEncoderDoc();				
			while(abs(encoderDoc())<75230)						// xanh 1
				{				
						
					Quet_cam_bien();
					DK_do_duong();
					nang(110);
					quat(350);
					CB_quat_nhe();	
					truot(-10);
				}
				tocdo_line(140,150);
				resetEncoderDoc();
			while(abs(encoderDoc())<56050)					// cam 1
				{  
					
					Quet_cam_bien();
					DK_do_duong();
					nang(3);
					quat(355);
					CB_quat_nhe();
					
					}
				resetEncoderDoc();
					tocdo_line(150,150);	
				while(abs(encoderDoc())<63800)				// xanh 2
				{  
					
					Quet_cam_bien();
					DK_do_duong();
					nang(110);
					quat(355);
					CB_quat_nhe();
					
				}
				
				resetEncoderDoc();
				tocdochay(150,160);
				while(abs(encoderDoc())<117230)				// cam 2
				{  
					
					Quet_cam_bien();
					DK_do_duong();
					nang(100);
					quat(350);
					CB_quat_nhe();
					
				}				
				resetEncoderDoc();
				kepthoi_on;
				//tocdochay(135,135);
				while(abs(encoderDoc())<40090)				// xanh 3.1
				{						
					Quet_cam_bien();
					DK_do_duong();
					nang(130);
					quat(330);
					CB_quat_nhe();
				}
				
				resetEncoderDoc();
				//tocdo_line(130,130);	
				while(abs(encoderDoc())<70071)				// xanh 3.2
				{  					
					Quet_cam_bien();
					DK_do_duong();
					quat(335);
					CB_quat_nhe();
					nang(0);
					if(!b2 && !b3 && !b4 && !b5 && !b6) break;
				}
				tocdo_line(90,70);	
				resetencoderSau();
				while(abs(encoderSau())<250)
				{
					Quet_cam_bien();
					DK_do_duong();
					quat(347);
					CB_quat_nhe();
					nang(0);
				}
				stopRobot(2);
				
				truot(-120);
				quat(353);
				delay_ms(700);
					
					tocdo_line(5,25);
					resetEncoderDoc();
					while(abs(encoderDoc())<20071)
					{
						Quet_cam_bien();
					  DK_do_duong_do();
						quat(365);
						
					}	
					quat(450);				
				delay_ms(50);
				
}
void chay_vao_cot_xanh(void)
{
		ACC=8;
		resetEncoderDoc();
		tocdochay(30,70);
	
		while(abs(encoderDoc()) < 21400)
			{ 	
				Quet_cam_bien();
				DK_do_duong_san_xanh();
					
				truot(-130);
			}
			quat(280);	
//				truot(0);
//				stopRobot(2);
//					while(1);
			ACC=5;
			//tocdochay(60,250);
			td_sau = 250;
			resetEncoderDoc();
			while(abs(encoderDoc()) < 200000)
			{ 								
				Quet_cam_bien();
				DK_do_duong_san_xanh();
				nang(-100);
				truot(0);
			}
			resetEncoderDoc();
			ACC=30;
			//tocdochay(250,180);
			td_sau = 220;
			while(abs(encoderDoc()) < 190000)
			{  
				Quet_cam_bien();
				DK_do_duong_san_xanh();
				truot(0);
			}
			ACC=0;
			td_sau = 95;
			resetEncoderDoc();
			//tocdochay(100,90);
			while(abs(encoderDoc()) < 1000000)
			{  
				Quet_cam_bien();
				DK_do_duong_san_xanh_cham();
				truot(-110);
				if(cam_bien) break;
			}
			ACC=0;
			td_sau = 2;
			truot(3);
			nangline_on;
			taygap_on;
			kepcot_on;
			stopRobot(2);
			
			for(i=0;i<5000;i++){
			while(CB_truoc_trai);}
			delay_ms(50);
			TD_trai(35), TD_phai(35), TD_truoc(2);
			delay_ms(50);
			TD_trai(50), TD_phai(50), TD_truoc(2);		
			
			
				for(i=0;i<5000;i++){	
				while(ct_cot_duoi);}
				
			stopRobot(0);
}

/*============================================================*/
/*==========================code nhanh san xanh ==========================*/
/*===================================================================*/



/*============================================================*/
/*========================== SAN DO ========================*/
/*============================================================*/

//void xuatphat_do(void)		// 162700
//{   
//				
//		resetencoderSau();
//		resetIMU();
//		delay_ms(10);
//		resetencoderSau();
//		resetIMU();
//		delay_ms(10);
//		ACC=5;
//		tocdochay(40,80);
//		
//	kepthoi_off;
//	while(abs(encoderSau())<100)					
//				{						
//					run_ngang_do(0,speed)	;		
//				}
//			resetencoderSau();
//			ACC=2;
//			tocdochay(230,230);
//					
//	while(abs(encoderSau())<900)					
//				{					
//					run_ngang_do(0,speed)	;	
//				}
//				
//				truot(100);
//				resetencoderSau();	
//					
//				
//				ACC=2;
//				td_sau = 180;
//				resetencoderSau();
//				while(abs(encoderSau())<200)					
//				{				
//					run_ngang_do(0,speed)	;	
//					
//				}
//				resetencoderSau();
//				ACC=5;
//				td_sau = 160;
//				//tocdochay(160,160);
//				while(abs(encoderSau())<200)					
//				{				
//					run_ngang_do(0,speed)	;	
//					
//				}
//				resetencoderSau();
//				ACC=5;
//				td_sau = 140;
//				//tocdochay(120,120);
//				while(abs(encoderSau())<200)					
//				{				
//					run_ngang_do(0,speed)	;	
//					
//				}
//				resetencoderSau();
//				ACC=5;
//				td_sau = 120;
//				//tocdochay(100,100);
//				while(abs(encoderSau())<200)					
//				{				
//					run_ngang_do(0,speed)	;	
//					quat(310);
//				}
//				resetencoderSau();
//				ACC=5;
//				td_sau=80;
//				while(abs(encoderSau())<200)					
//				{				
//					run_ngang_do(0,speed)	;	
//					
//				}
//				resetencoderSau();
//				truot(3);	
//				
//				ACC=0;
//				TD_truoc(60); TD_phai(60); TD_trai(-60);
//				for(i=0;i<5000;i++){
//				while(b7);}
//				
//				//stopRobot(0);
//				ACC=0;
//				TD_truoc(20); TD_phai(20); TD_trai(-20);	
//				while(b3);
//				stopRobot(2);
//				//delay_ms(70);
//				
//				quat(340);
//				kepnang_on;
//				
//				delay_ms(100);
//					
//}

void xuatphat_do(void)		// 162700
{   
				
		resetencoderSau();
				
	kepthoi_off;
	while(abs(encoderSau())<100)					
				{						
					TD_truoc(72); TD_phai(70); TD_trai(-70);
				}
				
			resetencoderSau();
				while(abs(encoderSau())<200)					
				{				
					TD_truoc(122); TD_phai(120); TD_trai(-120);
					
				}	
				
				resetencoderSau();
				
				while(abs(encoderSau())<150)					
				{				
					TD_truoc(182); TD_phai(180); TD_trai(-180);
					
				}
			resetencoderSau();
								
	while(abs(encoderSau())<900)					
				{					
						TD_truoc(253); TD_phai(250); TD_trai(-250);
				}
				
				truot(100);
				
				
				
				resetencoderSau();
				
				while(abs(encoderSau())<200)					
				{				
						TD_truoc(185); TD_phai(180); TD_trai(-180);
					
				}
				resetencoderSau();
				
				while(abs(encoderSau())<150)					
				{				
					TD_truoc(180); TD_phai(180); TD_trai(-180);
					
				}
				resetencoderSau();
				
				while(abs(encoderSau())<150)					
				{				
					TD_truoc(150); TD_phai(150); TD_trai(-150);
				}
				resetencoderSau();
				quat(320);
				while(abs(encoderSau())<150)					
				{				
						TD_truoc(100); TD_phai(100); TD_trai(-100);
					
				}
				resetencoderSau();
				truot(3);					
				quat(340);
				TD_truoc(60); TD_phai(60); TD_trai(-60);
				for(i=0;i<5000;i++){
				while(b7);}
				quat(350);
				TD_truoc(25); TD_phai(25); TD_trai(-25);	
				while(b3);
				stopRobot(2);
				
				
				quat(360);
				kepnang_on;
				
				delay_ms(100);
					
}
//-------------------------------- code on dinh --------------------------------------//
void vungdoi_do(void) 
{			
			resetEncoderDoc();
			ACC=10;
			tocdo_line(20,60);
			while(abs(encoderDoc())<30000)					
				{	
						
					Quet_cam_bien();
					DK_do_duong_do();
					quat(350);	
					truot(10);
					CB_quat_nhe();
				}
				//ACC=15;
					resetEncoderDoc();	
					tocdo_line(80,120);
			while(abs(encoderDoc())<30600)								//start
				{				
					Quet_cam_bien();
					DK_do_duong_do();
					quat(350);
					nang(0);
					CB_quat_nhe();
				}
				tocdo_line(130,140);
				resetEncoderDoc();				
			while(abs(encoderDoc())<75230)						// xanh 1
				{				
					Quet_cam_bien();
					DK_do_duong_do();
					nang(115);
					quat(350);
					CB_quat_nhe();
				}
				tocdo_line(140,150);
				resetEncoderDoc();
			while(abs(encoderDoc())<56050)					// cam 1
				{  
					
					Quet_cam_bien();
					DK_do_duong_do();
					nang(3);
					quat(345);
					CB_quat_nhe();
					 
					}
				resetEncoderDoc();
				//tocdochay(135,135);		
				while(abs(encoderDoc())<63800)				// xanh 2
				{  
					
					Quet_cam_bien();
					DK_do_duong_do();
					nang(110);
					quat(345);
					CB_quat_nhe();
					
				}
				
				resetEncoderDoc();
				//tocdochay(135,135);
				while(abs(encoderDoc())<117230)				// cam 2
				{  
					
					Quet_cam_bien();
					DK_do_duong_do();
					nang(100);
					quat(345);
					CB_quat_nhe();
				}
				kepthoi_on;
				resetEncoderDoc();
				//tocdochay(140,140);
				while(abs(encoderDoc())<40090)				// xanh 3.1
				{  
						
					Quet_cam_bien();
					DK_do_duong_do();
					nang(120);
					quat(345);
					CB_quat_nhe();
				}
				
				resetEncoderDoc();
				truot(120);
				//tocdo_line(140,140);	
				while(abs(encoderDoc())<70071)				// xanh 3.2
				{  
					
					Quet_cam_bien();
					DK_do_duong_do();
					quat(330);
					
					if(!b2 && !b3 && !b4 && !b5 && !b6) break;
				}
					tocdo_line(90,80);
					resetEncoderDoc();
					while(abs(encoderDoc())<23071)
					{
						Quet_cam_bien();
					  DK_do_duong_do();
						quat(335);
						
					}
				stopRobot(2);				
				
				quat(340);
				delay_ms(650);
					ACC=15;
					tocdo_line(0,30);
					resetEncoderDoc();
					while(abs(encoderDoc())<20071)
					{
						Quet_cam_bien();
					  DK_do_duong_do();
						quat(350);
						
					}
					
//				quat(340);
//				delay_ms(450);
				
				quat(450);				
				delay_ms(50);				
}	


void chay_vao_cot_do(void)
{
		
		resetEncoderDoc();
	ACC=10;
	tocdochay(30,60);
	
		while(abs(encoderDoc()) < 21400)
			{  
				
				Quet_cam_bien();
				DK_do_duong_cot_do();
				//kepcot_on;	
				truot(130);
			}
			quat(280);	
				ACC = 2;
			td_sau = 250;
			//tocdochay(60,230);	
			resetEncoderDoc();			
			while(abs(encoderDoc()) < 200000)
			{ 								
				Quet_cam_bien();
				DK_do_duong_cot_do();
				nang(-100);
				truot(0);
			}			
			resetEncoderDoc();
			ACC=40;
			td_sau = 220;
			//tocdochay(250,200);			
		while(abs(encoderDoc()) < 150000)
			{  				
				Quet_cam_bien();
				DK_do_duong_cot_do();
				truot(0);
			}
			resetEncoderDoc();
			ACC=40;
			td_sau = 190;
			//tocdochay(200,190);
			
		while(abs(encoderDoc()) < 50000)
			{  				
				Quet_cam_bien();
				DK_do_duong_cot_do();
				truot(0);
			}
			resetEncoderDoc();
			//stopRobot(2);
			//while(1);
			//tocdochay(130,110);
			ACC = 0;
			td_sau = 90;
		while(abs(encoderDoc()) < 1000000)
			{  
				
				Quet_cam_bien();
				DK_do_duong_san_do_cham();
				truot(90);
				
				if(cam_bien) break;
			}
			truot(3);
			
			nangline_on;
			taygap_on;
			kepcot_on;
			stopRobot(2);
			for(i=0;i<5000;i++){
			while(CB_truoc_phai);}
			//delay_ms(50);
			TD_trai(30), TD_phai(30), TD_truoc(2);
			delay_ms(50);
			TD_trai(50), TD_phai(50), TD_truoc(2);		
			
			
			for(i=0;i<5000;i++){	
			while(ct_cot_duoi);}
			stopRobot(0);
			
}

//------------------------------------------------------------------------------
//-------------------------------   AUTO RUN   ---------------------------------
//------------------------------------------------------------------------------


//--------------------------------- code nhanh --------------------------------//

void vungdoi_do_nhanh(void) 
{			
			
			resetEncoderDoc();
			ACC = 8;
			tocdo_line(25,70);
			while(abs(encoderDoc())<30000)					
				{	
						
					Quet_cam_bien();
					DK_do_duong_do();
					quat(365);	
					truot(10);
					//CB_quat_manh();
				}
					ACC=8;
					resetEncoderDoc();
					td_sau = 120;
					//tocdo_line(80,120);
			while(abs(encoderDoc())<30600)								//start
				{				
					Quet_cam_bien();
					DK_do_duong_do();
					quat(365);
					nang(0);
					//CB_quat_manh();
				}
				ACC=2;
				td_sau = 150;
				//tocdo_line(140,150);
				resetEncoderDoc();				
			while(abs(encoderDoc())<75230)						// xanh 1
				{				
					Quet_cam_bien();
					DK_do_duong_do();
					nang(120);
					quat(370);
					//CB_quat_manh();
				}
				ACC = 0;
				td_sau = 170;
				//tocdo_line(160,160);
				resetEncoderDoc();
			while(abs(encoderDoc())<56050)					// cam 1
				{  
					
					Quet_cam_bien();
					DK_do_duong_do();
					nang(3);
					quat(370);
					//CB_quat_manh();
					
					}
				resetEncoderDoc();
					td_sau = 175;
				//tocdochay(150,160);		
				while(abs(encoderDoc())<63800)				// xanh 2
				{  
					
					Quet_cam_bien();
					DK_do_duong_do();
					nang(115);
					quat(350);
					//CB_quat_nhe();
					
				}
				
				resetEncoderDoc();
				//tocdochay(160,160);
				while(abs(encoderDoc())<117230)				// cam 2
				{  
					
					Quet_cam_bien();
					DK_do_duong_do();
					nang(130);
					quat(340);
					//CB_quat_nhe();
				}
				kepthoi_on;
				resetEncoderDoc();
				//tocdochay(160,160);
				while(abs(encoderDoc())<40090)				// xanh 3.1
				{  
						
					Quet_cam_bien();
					DK_do_duong_do();
					nang(120);
					quat(340);
					//CB_quat_nhe();
				}
				
				resetEncoderDoc();
				truot(120);
				ACC = 0;
				td_sau = 160;
				//tocdo_line(160,160);	
				while(abs(encoderDoc())<70071)				// xanh 3.2
				{  
					
					Quet_cam_bien();
					DK_do_duong_do();
					quat(340);
					CB_quat_nhe();
					if(!b2 && !b3 && !b4 && !b5 && !b6) break;
				}
					tocdo_line(80,70);
					resetencoderSau();
				while(abs(encoderSau())<350)
				{
						Quet_cam_bien();
					  DK_do_duong_do();
						quat(330);
						
					}
				stopRobot(2);				
				
						quat(335);
						delay_ms(700);
					
						tocdo_line(0,30);
						resetEncoderDoc();
						while(abs(encoderDoc())<20071)
						{
							Quet_cam_bien();
							DK_do_duong_do();
							quat(345);						
						}	
					quat(450);				
				delay_ms(50);
}	
//--------------------------------- code nhanh xanh ---------------------//
void vungdoi_xanh_nhanh(void) 
{
			resetEncoderDoc();
			ACC=8;
			tocdo_line(20,60);
			while(abs(encoderDoc())<30000)					
				{	
						
					Quet_cam_bien();
					DK_do_duong();
					quat(370);
					//nang(50);			
					if(!CB_quat)
					{
						tocdo_line(50,50);
						quat(365);
					}
				}
				resetEncoderDoc();
					ACC=3;
					td_sau = 120;
			while(abs(encoderDoc())<30600)								//start
				{						
					Quet_cam_bien();
					DK_do_duong();
					quat(370);
					nang(0);
					if(!CB_quat)
					{
						tocdo_line(100,100);
						quat(365);
					}
				}
				ACC=1;
				td_sau = 175;
				resetEncoderDoc();				
			while(abs(encoderDoc())<75230)						// xanh 1
				{				
						
					Quet_cam_bien();
					DK_do_duong();
					nang(110);
					quat(370);
					if(!CB_quat)
					{
						tocdo_line(120,120);
						quat(380);
					}
					truot(-10);
				}
				ACC=2;
				td_sau = 190;
				resetEncoderDoc();
			while(abs(encoderDoc())<56050)					// cam 1
				{  
					
					Quet_cam_bien();
					DK_do_duong();
					nang(3);
					quat(370);
					if(!CB_quat)
					{
						tocdo_line(140,140);
						quat(370);
					}
					}
				resetEncoderDoc();
						
				while(abs(encoderDoc())<63800)				// xanh 2
				{  
					
					Quet_cam_bien();
					DK_do_duong();
					nang(115);
					quat(360);
					if(!CB_quat)
					{
						tocdo_line(130,130);
						quat(370);
					}
				}
				
				resetEncoderDoc();
				tocdochay(170,170);
				while(abs(encoderDoc())<117230)				// cam 2
				{  
					
					Quet_cam_bien();
					DK_do_duong();
					nang(100);
					quat(340);
					if(!CB_quat)
					{
						tocdo_line(130,130);
						quat(365);
					}
					
				}				
				resetEncoderDoc();
				kepthoi_on;
				tocdochay(175,175);
				while(abs(encoderDoc())<40090)				// xanh 3.1
				{						
					Quet_cam_bien();
					DK_do_duong();
					nang(130);
					quat(320);		//355
					if(!CB_quat)
					{
						tocdo_line(130,130);
						quat(365);
					}
				}
				
				resetEncoderDoc();
				ACC = 0;
td_sau = 150;				
				while(abs(encoderDoc())<70071)				// xanh 3.2
				{  					
					Quet_cam_bien();
					DK_do_duong();
					quat(340);
					if(!CB_quat)
					{
						tocdo_line(140,140);
						quat(365);
					}
					nang(0);
					if(!b2 && !b3 && !b4 && !b5 && !b6) break;
				}
				ACC = 0;
				td_sau = 70;
				//tocdo_line(90,70);	
				resetencoderSau();
				while(abs(encoderSau())<200)
				{
					Quet_cam_bien();
					DK_do_duong();
					quat(350);
					CB_quat_nhe();
					nang(0);
				}
				stopRobot(2);
				
				
				truot(-120);
				quat(360);
				delay_ms(650);
					
					tocdo_line(5,25);
					resetEncoderDoc();
					while(abs(encoderDoc())<20071)
					{
						Quet_cam_bien();
					  DK_do_duong_do();
						quat(370);
						
					}	
					quat(450);				
				delay_ms(50);
				
}

// -------------------------- chay vao cot nhanh -------------------
void chay_vao_cot_xanh_nhanh(void)
{
		ACC=10;
		resetEncoderDoc();
		tocdochay(20,60);
	
		while(abs(encoderDoc()) < 21400)
			{ 	
				Quet_cam_bien();
				DK_do_duong_san_xanh();
					
				truot(-130);
			}
			quat(280);	
//				truot(0);
//				stopRobot(2);
//					while(1);
			ACC=5;
			//tocdochay(60,250);
			td_sau = 255;
			resetEncoderDoc();
			while(abs(encoderDoc()) < 200000)
			{ 								
				Quet_cam_bien();
				DK_do_duong_san_xanh();
				nang(-100);
				truot(0);
			}
			resetEncoderDoc();
			ACC=40;
			//tocdochay(250,180);
			td_sau = 225;
			while(abs(encoderDoc()) < 190000)
			{  
				Quet_cam_bien();
				DK_do_duong_san_xanh();
				truot(0);
			}
			ACC=0;
			td_sau = 100;
			resetEncoderDoc();
			//tocdochay(100,90);
			while(abs(encoderDoc()) < 1000000)
			{  
				Quet_cam_bien();
				DK_do_duong_san_xanh_cham();
				truot(-110);
				if(cam_bien) break;
			}
			ACC=0;
			td_sau = 2;
			truot(3);
			nangline_on;
			taygap_on;
			kepcot_on;
			stopRobot(2);
			
			for(i=0;i<5000;i++){
			while(CB_truoc_trai);}
			delay_ms(50);
			TD_trai(35), TD_phai(35), TD_truoc(2);
			delay_ms(50);
			TD_trai(50), TD_phai(50), TD_truoc(2);		
			
			
				for(i=0;i<5000;i++){	
				while(ct_cot_duoi);}
				
			stopRobot(0);
}
