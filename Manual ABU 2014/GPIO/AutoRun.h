//      CODE NHANH 
void lcdViewer(void);
vu32 	flash_bit=0;
vu32 	flash_bit1=0;
void robotGamePadControl(void);

char robotLineDetect(unsigned char speed)
{
    char vitri=0;

       do{
						robotRun(0,speed,0);                                // toc do chay den line
						do{
									if(!cb_TTruoc || !cb_TSau) vitri=1;
									else if(!cb_PTruoc || !cb_PSau) vitri=2;
									else vitri=0;
									if(wantExit()) return 0;
							}
						while(vitri==0);

									robotStop(0);
									delay_ms(10);

									if(!cb_TTruoc || !cb_TSau) vitri=1;
									else if(!cb_PTruoc || !cb_PSau) vitri=2;
									else vitri=0;
									if(wantExit()) return 0;
				}
			while(vitri==0);

    if(vitri==2)// ben Trai sai
    {
        robotRotate(30000, 0.6, 2);
        while(cb_TTruoc && cb_TSau) if(wantExit()) return 0;
    }
    else // ben Phai sai
    {
        robotRotate(-30000, 0.6, 1);
        while(cb_PTruoc && cb_PSau)if(wantExit()) return 0;
    }

    robotStop(0);
    return 1;
}
//==============================================================================
//==============================================================================
//==============================================================================
void robotLineRun(int angle, char maxSP, float hesoTraiDat)
{
    int k;
	float hesoXoay=0.3;
    if(angle>0){ k= -1;}
    else { k=1;}

	if(colorSensorLeft && colorSensorRight)// dang o dung vi tri, chay theo Line
	{
									robotRotateStop();
									robotRun(angle, maxSP , k*hesoTraiDat);
	}
	else{
			if(!colorSensorLeft && colorSensorRight)// ben Trai sai
				{
				if(lastSensorLeft >= 0)
								{
										robotRun(angle + k*10, maxSP , k*hesoTraiDat);
										robotRotate(30000 , hesoXoay, 2);
								}
				else{
										robotRun(angle - k*20, maxSP , k*hesoTraiDat);
										robotRotate(30000, -hesoXoay, 2);
						}
			}
			else if(colorSensorLeft && !colorSensorRight)// ben Phai sai
			{
    			if(lastSensorRight >= 0){
									robotRun(angle + k*10, maxSP , k*hesoTraiDat);
									robotRotate(30000, -hesoXoay, 1);
			    }
					else{
									robotRun(angle - k*20, maxSP , k*hesoTraiDat);
									robotRotate(30000, hesoXoay, 1);
    			}
			}
			else // Ca hai dieu sai
			{
				if(lastSensorLeft >= 0 && lastSensorRight >= 0){ // 2 Dang o ngoai
					robotRotateStop();
					robotRun(angle + k*10, maxSP, k*1.35);
				}else if(lastSensorLeft < 0 && lastSensorRight < 0){ // 2 Dang o trong
					robotRotateStop();
					robotRun(angle - k*10, maxSP, k*1.35);
					// 1 trong 1 ngoai
				}else; //if(lastSensorLeft >= 0) 	
				{
						robotRotateStop();
						robotRun(angle, maxSP , k*hesoTraiDat);
				}

			}		
	}
}

//==============================================================================
void robotLineRun1(int angle, char maxSP, float hesoTraiDat)
{
    int k;
	float hesoXoay=0.45;
    if(angle>0){ k= -1;}
    else { k=1;}

	if(colorSensorLeft && colorSensorRight)// dang o dung vi tri, chay theo Line
	{
									robotRotateStop();
									robotRun(angle, maxSP , k*hesoTraiDat);
	}
	else{
			if(!colorSensorLeft && colorSensorRight)// ben Trai sai
				{
				if(lastSensorLeft >= 0)
								{
										robotRun(angle + k*20, maxSP , k*hesoTraiDat);
										robotRotate(30000 , hesoXoay, 2);
								}
				else{
										robotRun(angle - k*30, maxSP , k*hesoTraiDat);
										robotRotate(30000, -hesoXoay, 2);
						}
			}
			else if(colorSensorLeft && !colorSensorRight)// ben Phai sai
			{
    			if(lastSensorRight >= 0){
									robotRun(angle + k*20, maxSP , k*hesoTraiDat);
									robotRotate(30000, -hesoXoay, 1);
			    }
					else{
									robotRun(angle - k*30, maxSP , k*hesoTraiDat);
									robotRotate(30000, hesoXoay, 1);
    			}
			}
				else // Ca hai dieu sai
			{
				if(lastSensorLeft >= 0 && lastSensorRight >= 0){ // 2 Dang o ngoai
					robotRotateStop();
					robotRun(angle + k*20, maxSP, k*1.4);
				}else if(lastSensorLeft < 0 && lastSensorRight < 0){ // 2 Dang o trong
					robotRotateStop();
					robotRun(angle - k*40, maxSP, k*1.4);
					// 1 trong 1 ngoai
				}else if(lastSensorLeft >= 0) 	robotRotate(30000, 1.4, 0);

    			    else 						robotRotate(30000, -1.4, 0);
			}
		}		
	}

//==============================================================================


void robotLineRun_new(int angle, int maxSP, float hesoTraiDat)
{
		float _S1 = 10 , _R1 = 1;
		float _S2 = 200, _R2 = 70;
		float _A=(_R2-_R1)/(_S2-_S1), _B=(_R1*_S2-_S1*_R2)/(_S2-_S1);
		float hesoXoayVo= 1.5;
		float hesoXoayRa= 1.5;

    int k = (angle>0? -1:1);
    float hesoCungTron;

	if(robotSpeed() != 0) hesoCungTron = (float)(robotSpeed()*_A + _B)/robotSpeed();

	if(colorSensorLeft && colorSensorRight)// dang o dung vi tri, chay theo Line
	{
			//robotRotateStop();
			robotRun(angle, maxSP , k*hesoTraiDat);
		//robotCurve(angle, maxSP , k*hesoCungTron);
	}
	else// dang sai vi tri
	{		
		if(!colorSensorLeft && colorSensorRight)// ben Trai sai
		{
			if(lastSensorLeft >= 0)
			{
				//robotRotateStop();
				robotRun(angle + k*40, maxSP , k*hesoXoayRa);
				//robotCurve(angle + k*40, maxSP , k*hesoXoayRa);// Dang o ngoai
			}
			else
			{
				//robotRotateStop();
				robotRun(angle - k*40, maxSP , k*hesoXoayVo);
				//robotCurve(angle - k*40, maxSP , k*hesoXoayVo);// Dang o trong
			}
		}
		else
		{
			if(colorSensorLeft && !colorSensorRight)// ben Phai sai
    		{
		    	if(lastSensorRight >= 0)
				{
						//robotRotateStop();
						robotRun(angle + k*40, maxSP , k*hesoXoayVo);
					//robotCurve(angle + k*40, maxSP , k*hesoXoayVo);// Dang o ngoai
			   }
				else
				{
						//robotRotateStop();
						robotRun(angle - k*40, maxSP , k*hesoXoayRa);
					//robotCurve(angle - k*40, maxSP , k*hesoXoayRa);// Dang o trong
    			}
			}
			else // Ca hai dieu sai
			{
				if(lastSensorLeft >= 0 && lastSensorRight >= 0)// 2 Dang o ngoai
				{ 
					//robotRotateStop();
					robotRun(angle + k*60, maxSP , k*hesoTraiDat);
					//robotCurve(angle + k*60, maxSP, k*hesoCungTron);
				}
				else
				{
					if(lastSensorLeft < 0 && lastSensorRight < 0)// 2 Dang o trong
					{ 
						//robotRotateStop();
						robotRun(angle - k*60, maxSP , k*hesoTraiDat);
						//robotCurve(angle - k*60, maxSP, k*hesoCungTron);
					}
					else // 1 trong 1 ngoai
					{ 					
						if(lastSensorLeft >= 0)// ben trai o ngoai
						{
								//robotRotateStop();
								robotRun(angle - k*40, maxSP , (angle>0?hesoXoayRa:-hesoXoayVo));
								//robotCurve(angle - k*40, maxSP, (angle>0?hesoXoayRa:-hesoXoayVo));
						}	
							
						else
						{
								//robotRotateStop();
								robotRun(angle + k*40, maxSP , (angle>0?-hesoXoayVo:hesoXoayRa));	
							//robotCurve(angle + k*40, maxSP, (angle>0?-hesoXoayVo:hesoXoayRa));
						}
					}
				}
			}		
		}
	}
}
	
void bap_benh_auto(unsigned int time)
{
				unsigned char noise;    
    while(time-- > 0)
    {
			for(noise=0;noise<5;noise++)while(cb_NC_8)    {mor_nang = 250; mor_nang_down;if(wantExit()) return;  }
			for(noise=0;noise<5;noise++)while(cb_NC_5)    {mor_nang = 220; mor_nang_up;if(wantExit()) return;  }
    } 
//										robotRun(0,8,0);			
//				for(noise=0;noise<5;noise++)while(cb_NC_8)  
//										{
//												mor_nang = 250; mor_nang_down;
//												if(wantExit()) return;
//												if(!cb_TTruoc && !cb_PTruoc) robotStop(0);		
//										}
//				for(noise=0;noise<5;noise++)while(cb_NC_5)  
//										{
//												mor_nang = 220; mor_nang_up;
//												if(wantExit()) return;  
//												if(!cb_TTruoc && !cb_PTruoc) robotStop(0);
//										}
			mor_nang = 2;    
}



// ----------------------------------------------------------------
// --------------------------- START XANH -------------------------
// ----------------------------------------------------------------

void  AUTO_BB_XANH(int fix_goc_line)
{						
						flash_bit=1;
						auto_mode=1;
						Reset_encoder_ngang();			
						Xilanh53_ve_on;
						robotRun(900 - _robotIMUAngle,50,0);
						robotRotate(1,1,0);
			do{		
						Nang_Truc(20,3);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 8900);													// chay ngang
			do{		
						
						Nang_Truc(20,3);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 9000);													// chay ngang		
						Xilanh53_ve_off;
						bitha=1;
						Reset_encoder_doc();
						robotRun(1350 - _robotIMUAngle,50,0);
						robotRotate(1,1,0);		
			do{		
						Nang_Truc(120,2);
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 10000);
						Reset_encoder_ngang();
			do{		
						Nang_Truc(150,2);
						if(wantExit()) return;
				}	
			while(cb_quang_bb_xanh);																				// kiem tra cam bien quang
						Xilanh50_on;
						flash_bit=1;
				Reset_encoder_ngang();
						robotRun(900 - _robotIMUAngle,30,0);
						robotRotate(-35,-1,0);
			do{		
						Nang_Truc(150,2);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 8000);
						robotRun(fix_goc_line - _robotIMUAngle,20,0);							// cang nho cang gan line
						robotRotate(-30,-1,0);
			do{		
						Nang_Truc(150,2);
						Truot_Ra(50,4);
						if(wantExit()) return;
				}
			while(_ADC1_Value[0] > 1600);																	 // nhan laze giua chay cham lai
						Xilanh_mode_on;
						flash_bit=1;
						Reset_encoder_ngang();
						robotRun(fix_goc_line - _robotIMUAngle,8,0);
						robotRotate(-30,-1,0);
			do{
						Ha_Truc(60,7);
						Truot_Ra(100,4);
						if(wantExit()) return;
				}
			while(_ADC1_Value[1] > 1000);															// dung bang laze ben phai
						flash_bit=1;
						Xilanh_mode_off;
						robotRun(0,10,0);

			do{
						if(!cb_TTruoc && !cb_PTruoc)   robotStop(0);
						Ha_Truc(180,7);
						Truot_Ra(150,4);
						if(wantExit()) return;
				}
		 while(cb_NC_7);
						mor_ngang=2,mor_nang=2;
						bitha=0;
}
// ----------------------------------------------------------------
// ---------------------- XOAY BAP BENH ---------------------------
// ----------------------------------------------------------------


void XOAY_BAPBENH_XANH(int fix_bb_d)
{											
						auto_mode=2;
						bitha=0;
						Xilanh_mode_off,Xilanh_kep_off;									// nha kep
		 while(cb_Kep)								if(wantExit()) return;		
						Nang_Truc_While(240,6);													// nang truc qua bap benh
						Xilanh53_ra_off,Xilanh53_ve_on;
						Xilanh50_off;				
						Reset_encoder_ngang();	
		do{				
				    robotLineRun(925, 30 , 1.10); 
						Nang_Truc(20,3);
						Truot_Vao(150,8);
						if(wantExit()) return;	
			}  			
		while(abs(Encoder_ngang())<2800);	
		do{				
				    robotLineRun(925, 30 , 1.10); 
						Nang_Truc(20,3);
						Truot_Vao(150,8);
						if(wantExit()) return;	
			}  			
		while(abs(Encoder_ngang())<2900);	
		do{				
				    robotLineRun(925, 30 , 1.10); 
						Nang_Truc(20,3);
						Truot_Vao(150,8);
						if(wantExit()) return;	
			}  			
		while(abs(Encoder_ngang())<3000);											// chay cham 4000 	
						Reset_encoder_ngang();
			do{
						robotLineRun(830, 65 , 1.31);									
						Nang_Truc(60,3);	
						Truot_Vao(50,8);
						if(wantExit()) return;						
				}
			while(abs(Encoder_ngang()) < 25000);
			do{
						robotLineRun(830, 65 , 1.31);									
						Nang_Truc(60,3);	
					  Truot_Ra(220,1); 
						if(wantExit()) return;						
				}
			while(abs(Encoder_ngang()) < 34000);
				
				Reset_encoder_ngang();
						robotRun(-820 - _robotIMUAngle,20,0);					// cang nho cang gan line
						robotRotate(-1800,-1.2,0);
			do{
						Nang_Truc(60,3);	
						Truot_Ra(200,1); 
						if(wantExit()) return;	
				}  
			while(abs(Encoder_ngang())<4800);			
			do{
						Nang_Truc(60,3);	
						Truot_Ra(200,1); 
						if(wantExit()) return;	
				}  
			while(abs(Encoder_ngang())<4900);			
			do{
						Nang_Truc(60,3);	
						Truot_Ra(200,1); 
						if(wantExit()) return;	
				}  
			while(abs(Encoder_ngang())<5000);							
						robotStop(0);
						delay_ms(100);
						bap_benh_auto(2);				
//	__________________________________________________________________________//

						Xilanh53_ve_off;
				Reset_encoder_ngang();
			do{
						robotLineRun(-920, 30 , 1.10); 
						Truot_Vao(200,8);	
						if(wantExit()) return;	
				}  
			while(abs(Encoder_ngang())<3800);											
			do{
						robotLineRun(-920, 30 , 1.10); 
						Truot_Vao(200,8);	
						if(wantExit()) return;	
				}  
			while(abs(Encoder_ngang())<3900);										
			do{
						robotLineRun(-920, 30 , 1.10); 
						Truot_Vao(200,8);	
						if(wantExit()) return;	
				}  
			while(abs(Encoder_ngang())<4000);											// chay cham 4000	
				Reset_encoder_ngang();		
						Xilanh53_ra_on,Xilanh50_on;
			while(abs(Encoder_ngang())<19900)											// chay nhanh 35000
				{  	
						robotLineRun(-830, 65 , 1.32);          								
						Ha_Truc(50,6);		
						if(abs(Encoder_ngang())<20000)						Truot_Vao(40,8);	
						if(abs(Encoder_ngang())>21000)						Truot_Ra(60,4);
						if(wantExit()) return;
				}		
			while(abs(Encoder_ngang())<20000)											// chay nhanh 35000
				{  	
						robotLineRun(-830, 65 , 1.32);          								
						Ha_Truc(50,6);		
						if(abs(Encoder_ngang())<20000)						Truot_Vao(40,8);	
						if(abs(Encoder_ngang())>21000)						Truot_Ra(60,3);
						if(wantExit()) return;
				}
			do{
						robotLineRun(-830, 65 , 1.32);          								
						Ha_Truc(50,6);	
						Truot_Ra(60,3);
						if(wantExit()) return;
				}
			while(cb_quang_left);
						Reset_encoder_ngang();		
						robotRun(-fix_bb_d - _robotIMUAngle,12,0);						// so cang nho cang gan line
						robotRotate(30,4.2,0);
			do{
						Truot_Ra(60,3);
						Ha_Truc(50,6);
						if(wantExit()) return;
				}
			while(_ADC1_Value[0]>300);																// kiem tra laze dung robot
				flash_bit=1;
						mor_ngang=2;
						robotRun(0,15,0);
			while(cb_TTruoc && cb_PTruoc)
				{	
						Ha_Truc(60,7);
						if(wantExit()) return;		
				}
						robotStop(0);
						Ha_Truc_While(200,7);					
						Xilanh53_ra_on,Xilanh50_on;	
						Xilanh_kep_on;
}
		

// -----------------------------------------------------------------
// ----------------------  XICH DU BLUE  ---------------------------
// -----------------------------------------------------------------

void XICH_DU_XANH(int Stop_Roate, int Roate)
{
						auto_mode=3;
						Xilanh_kep_on;delay_ms(100);											// kep delay 100ms
						Xilanh53_ve_off,Xilanh50_on,Xilanh53_ra_on;				// cho canh tay nam ngang
				Reset_encoder_doc();	
						Nang_Truc(100,5);																	// nang truc toc do 100
						robotRun(1350 - _robotIMUAngle,60,0);
						robotRotate(1,0.5,0);
		while(abs(Encoder_doc()) < 2011)	
			{
						Nang_Truc(100,5);
						Truot_Vao(150,8);
						if(wantExit()) return;
			}	
		while(abs(Encoder_doc()) < 2012)	
			{
						Nang_Truc(100,5);
						Truot_Vao(150,8);
						if(wantExit()) return;
			}	
		while(abs(Encoder_doc()) < 2013)	
			{
						Nang_Truc(100,5);
						Truot_Vao(150,8);
						if(wantExit()) return;
			}			
		while(abs(Encoder_doc()) < 2014)	
			{
						Nang_Truc(100,5);
						Truot_Vao(150,8);
						if(wantExit()) return;
			}			
				Reset_encoder_ngang();				
						robotRun(1200 - _robotIMUAngle,60,0);					// chay goc -1200-imu, xoay goc -1800
						robotRotate(1800,2.8,0);
		do{		
						Truot_Vao(120,8);
						Nang_Truc(50,2);
						Xilanh53_ve_off,Xilanh50_on,Xilanh53_ra_on;
						if(_robotIMUAngle > 1680)   Xilanh_cheo_on;
						if(wantExit()) return;
			}
		while(_robotIMUAngle < Stop_Roate);							// bat dau chay ngang
						flash_bit=1;
						Xilanh_cheo_on;		
				Reset_encoder_ngang();
						robotRun(900 - _robotIMUAngle,35,0);
						robotRotate(Roate,0.7,0);
		do{		
						Truot_Vao(20,8);
						Nang_Truc(150,2);
						if(wantExit()) return;
			}
		while(_ADC1_Value[1] > 500);														 // nhan laze dem encoder, tat mode
				    flash_bit=1;					
				Reset_encoder_ngang();
						Xilanh_mode_on;
						robotRun(900 - _robotIMUAngle,20,0);				// speed=20
						robotRotate(Roate,0.7,0);
		do{
						if(abs(Encoder_ngang()) > 500)	Xilanh_mode_off;	
						Truot_Vao(20,8);	
						Nang_Truc(150,2);
						if(wantExit()) return;	
			}  
		while(abs(Encoder_ngang())<2000);
						robotRun(900 - _robotIMUAngle,10,0);				// speed=5
						robotRotate(Roate,0.7,0);
		do{		
						Truot_Vao(20,8);
						Nang_Truc(120,1);
						if(wantExit()) return;
		  }
		while(!cb_XICHDU_P && cb_XICHDU_T);								// cam bien ben phai nhan truoc
						flash_bit=1;							
		do{		
						Truot_Vao(20,8);
						Nang_Truc(150,1);
						if(wantExit()) return;
						flash_bit=1;	
		  }
		while(cb_XICHDU_P);															// cam bien trai nhan, robot chay thang						
						flash_bit=1;					
				Reset_encoder_doc();
						robotRun(1800 - _robotIMUAngle,12,0);
						robotRotate(Roate,0.7,0);
		 do{		
						Truot_Ra(200,1);
						Nang_Truc(200,1);
						if(wantExit()) return;
				}
		while(cb_XICHDU);										 // robot stop neu nhan laze xich du
						flash_bit=1;	
						robotStop(0);
						Truot_Ra_While(250,1);								//  dua het canh tay ra 
						Ha_Truc_While(150,4);									//  ha truc	
						Truot_Vao_While(150,7);					
}
// -----------------------------------------------------------------
// ----------------------  COT DO  ---------------------------------
// -----------------------------------------------------------------
void LEO_COT_XANH(int fix_cot)
{
						auto_mode=4;
			Reset_encoder_doc();
						Xilanh_kep_on;delay_ms(100);
						Xilanh_mode_on;delay_ms(80);Xilanh_mode_off;
						Xilanh_cheo_off,Xilanh53_ra_off,Xilanh53_ve_on;
						Truot_Ra(200,1);
						Nang_Truc(180,2);
						robotRun(0+ _robotIMUAngle,20,0);
						robotRotate(1780,0.8,0);
			do{		 
						Nang_Truc(180,2);			
						Truot_Ra(150,1);			
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 1800);
			do{		 
						Nang_Truc(180,2);			
						Truot_Ra(150,1);			
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 1900);
			do{		 
						Nang_Truc(180,2);			
						Truot_Ra(150,1);			
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 2000);
			do{		 
						Ha_Truc(50,8);			
						Truot_Vao(200,8);		
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 2400);	
			do{		 
						Ha_Truc(50,8);			
						Truot_Vao(200,8);		
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 2500);	
			do{		 
						Ha_Truc(60,8);
						Truot_Vao(200,8);	
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 3900);
			do{		 
						Ha_Truc(150,8);
						Truot_Vao(200,8);	
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 4000);
					Reset_encoder_doc();
					Xilanh50_off;
				Reset_encoder_doc();
						robotRun(-540+ _robotIMUAngle,60,0);						//	 so cang nho cang ve cau thang
						robotRotate(800,-2.8,0);
			do{
						Ha_Truc(200,10);
						Truot_Vao(120,8);
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 19000);
						Reset_encoder_ngang();
						robotRun(fix_cot- _robotIMUAngle,80,0);  				// CANG LON CANG GAN COT
						robotRotate(900,-0.7,0);
			do{
						Ha_Truc(80,10);Truot_Vao(40,8);
						if(wantExit()) return;
				}
			while(_ADC1_Value[0] > 1000);
						
						flash_bit=1;
						Reset_encoder_ngang();
						robotRun(fix_cot- _robotIMUAngle,80,0);
						robotRotate(900,-0.7,0);
			do{
						Ha_Truc(40,10);
						Truot_Vao(40,8);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 20000);
						robotRun(fix_cot- _robotIMUAngle,30,0);
						robotRotate(900,-0.7,0);
			do{
						Truot_Ra(120,5);
						if(wantExit()) return;
				}
			while(_ADC1_Value[0] > 1000);		
						Xilanh_mode_on;		
						flash_bit=1;
						Reset_encoder_ngang();
						robotRun(fix_cot- _robotIMUAngle,20,0);
						robotRotate(750,-4.2,1);
			do{
						if(abs(Encoder_ngang()) > 1000)			Xilanh_mode_off;
						Truot_Ra(120,5);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 3500);
						robotRun(0,15,0);
						robotRotate(750,-1.8,0);
			while(cb_TTruoc && cb_PTruoc)
				{	
						Truot_Ra(40,5);
						if(wantExit()) return;	
				}
						mor_nang=2,mor_ngang=2;
						robotStop(0);
			do{
						Truot_Ra(40,5);
						robotLineRun(900, 20 , 1.29); 
						if(wantExit()) return;
				}
	   while(cb_mode);												
						robotStop(0);
}

// -----------------------------------------------------------------
// ----------------------  CAU THANG  ------------------------------
// -----------------------------------------------------------------
void CAUTHANG_XANH(int fix_roate)
{
					Xilanh_kep_on;  delay_ms(300);		
					Xilanh_mode_on; delay_ms(100);Xilanh_mode_off;
		do{
					Nang_truc();	
					if(wantExit()) return;	
			}
		while(cb_mode);	
					
					Truot_Vao(200,8);
					Reset_encoder_ngang();
					robotRun(-210+ _robotIMUAngle,60,0);					// 1050
					robotRotate(1100,-1,0);
		do{
					Truot_Vao(200,8);
					if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 6000);
					flash_bit=1;
					
					Reset_encoder_ngang();
					robotRun(-fix_roate+_robotIMUAngle,70,0);				// goc cang lon cang gan cau thang
					robotRotate(820,-2.8,0);
		do{
					Truot_Vao(50,8);
					Nang_Truc(80,8);
					if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 25000);					// bat dau chay cham lai
					Xilanh_mode_on;
					Reset_encoder_ngang();
					robotRun(-50+_robotIMUAngle,25,0);				// CANG NHO CANG GAN CAU THANG
					robotRotate(820,-2.2,0);
					Xilanh50_on;
		do{
					if(abs(Encoder_ngang()) > 1000)			Xilanh_mode_off;
					Truot_Ra(40,5);
					Nang_Truc(80,8);		
					if(wantExit()) return;
			}
		while(_ADC1_Value[0] > 1000);											// kiem tra laze nhan thanh cau thang
					robotRun(-50+_robotIMUAngle,15,0);
					robotRotate(820,-2.2,0);
					Reset_encoder_ngang();
		do{
					Truot_Ra(40,5);
					Nang_Truc(80,8);		
					if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 1600);	
					robotRun(0,25,0);
					robotRotate(820,-2.2,0);
		while(cb_TTruoc && cb_PTruoc)
		{	
					Truot_Ra(150,5);		
		}
					robotStop(0);
			mor_nang=2,mor_ngang=2;			
}

// -----------------------------------------------------------------
// ----------------------  BAN XICH DU  ----------------------------
// -----------------------------------------------------------------
void BAN_XICHDU_XANH()
{
					Xilanh_mode_on;
					delay_ms(150);
					Xilanh_mode_off,Xilanh_kep_off,Xilanh_cheo_on;
			while(cb_Kep)											if(wantExit()) return;
					Xilanh53_ra_off,Xilanh53_ve_on,Xilanh50_off;		
			while(_ADC1_Value[2] < 2300)				if(wantExit()) return;
					Xilanh_ban_on;
			while(cb_BAN)											if(wantExit()) return;		
					Xilanh_ban_off;
					Reset_encoder_doc();
					robotRun(1800,30,0);
					robotRotate(1780,0.8,0);
			do{		 
					Nang_Truc(120,1);
					Truot_Vao(180,8);				
					if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 4000);
					robotRun(1800,20,0);
					robotRotate(1780,0.8,0);
					Xilanh50_on;
			do{		 
					Nang_Truc(120,1);
					Truot_Vao(100,8);				
					if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 6000);
					mor_nang=2;
					robotStop(2);return;
					
}
// -----------------------------------------------------------------
// ----------------------  DON XICH DU -----------------------------
// -----------------------------------------------------------------
void DON_XICHDU_XANH()
{	
					Xilanh_cheo_on,Xilanh_kep_off,Xilanh53_ve_off,Xilanh53_ra_on,Xilanh50_on;
					Reset_encoder_doc();
					robotRun(0,20,0);
					robotRotate(1780,0.8,0);
			do{		 
						Truot_Ra(150,7);				
					if(wantExit()) return;
				}
			while(cb_XICHDU);
					robotStop(0);
		  while(cb_DON_XICHDU_T && cb_DON_XICHDU_P)			if(wantExit()) return;
					Ha_Truc_While(220,3);
}
// -----------------------------------------------------------------
// ----------------------  THA COT  --------------------------------
// -----------------------------------------------------------------
void THA_COT_XANH()
{
		while(cb_NC_9)					
				{
						Nang_Truc(35,9);
						if(wantExit()) return;
				}
					mor_nang=2;
					Xilanh_mode_on;delay_ms(80);Xilanh_mode_off;
		do{
					Nang_truc();	
					if(wantExit()) return;	
			}
		while(cb_mode);							
					Xilanh_kep_off;
		while(cb_Kep)								if(wantExit()) return;
					Truot_Vao_While(200,8);				
			Reset_encoder_doc();		
					robotRun(-250- _robotIMUAngle,25,0); 	// 650 // 1550
					robotRotate(1050,1,0);
			do{
						Ha_Truc(80,10);
						Truot_Vao(200,8);
						if(wantExit()) return;
				}
	   while(abs(Encoder_doc()) < 2100);
			do{
						Ha_Truc(80,10);
						Truot_Vao(200,8);
						if(wantExit()) return;
				}
	   while(abs(Encoder_doc()) < 2200);
					Reset_encoder_ngang();		
					robotRun(300- _robotIMUAngle,30,0); // -650 // 1550
					robotRotate(1100,1.5,0);
			do{
						Nang_Truc(60,9);
						if(wantExit()) return;
				}
	   while(abs(Encoder_ngang()) < 3900);
						mor_nang=2,mor_ngang=2;
						robotStop(0);
		while(cb_Tay)		if(wantExit()) return;	
						Truot_Ra_While(140,6);
						Truot_Ra_While(80,7);
}
void THA_CAUTHANG_XANH()
{
	
					Xilanh_kep_off;
			while(cb_Kep)																	if(wantExit()) return;
					Truot_Vao(200,8);
			Reset_encoder_doc();
					robotRun(900+ _robotIMUAngle,20,0);
			do{
					Truot_Vao(200,8);
					if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 3000);	
					Xilanh50_off;
			Reset_encoder_ngang();
					robotRun(- _robotIMUAngle,20,0);
			do{
					Truot_Vao(20,8);
					if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 3000);	
					robotStop(0);		
}


// ----------------------------------------------------------------
// --------------------------- START ------------------------------
// ----------------------------------------------------------------

void  AUTO_BB_DO(int goc_fix)
{						
						auto_mode=1;
					Reset_encoder_ngang();			
						robotRun(-900 - _robotIMUAngle,200,0);
						robotRotate(1,0.2,0);						
						Xilanh53_ve_on;
			do{		
						Nang_Truc(20,3);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 10000);													// chay ngang		
						Xilanh53_ve_off;
						bitha=1;
				Reset_encoder_doc();
						robotRun(-1350 - _robotIMUAngle,200,0);
						robotRotate(1,0.2,0);		
			do{		
						Nang_Truc(120,2);
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 13000);
				 Reset_encoder_ngang();
			do{		
						Nang_Truc(120,2);
						if(wantExit()) return;
				}	
			while(cb_quang_bb);																				// kiem tra cam bien quang
						Xilanh50_on;
						flash_bit=1;
				 Reset_encoder_ngang();
						robotRun(-900 - _robotIMUAngle,20,0);								// 1
						robotRotate(-goc_fix,0.3,0);
			do{		
						Nang_Truc(150,2);
						Truot_Ra(30,3);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 8000);
						robotRun(-900 - _robotIMUAngle,10,0);								// 1
						robotRotate(-goc_fix,0.3,0);
			do{		
						Nang_Truc(150,2);
						Truot_Ra(50,4);
						if(wantExit()) return;
				}
			while(_ADC1_Value[0] > 1300);																	 // nhan laze giua chay cham lai
						Xilanh_mode_on;
						flash_bit=1;
			do{		
						Ha_Truc(10,7);
						Truot_Ra(80,4);
						if(wantExit()) return;
				}
			while( _ADC1_Value[1] > 1000 );																		// dung bang laze ben phai						
						flash_bit=1;
						robotRun(0,10,0);
						robotRotate(-goc_fix,0.3,0);
			do{
						if(!cb_TTruoc && !cb_PTruoc)   robotStop(0);
						Ha_Truc(180,7);
						Truot_Ra(150,4);
						if(wantExit()) return;
				}
		 while(cb_NC_7);
						Xilanh_mode_off;
						mor_ngang=2,mor_nang=2;
						bitha=0;
}
//=============================================================================
//============================    XOAY BB DO  =================================
//=============================================================================

void XOAY_BAPBENH_DO(int fix_bb_d)
{											
						auto_mode=2;
						bitha=0;
						Xilanh_mode_off,Xilanh_kep_off;									// nha kep
	
		 while(cb_Kep)								if(wantExit()) return;		
	
						Nang_Truc_While(240,6);													// nang truc qua bap benh
						robotSetACC(20);
						Xilanh53_ra_off,Xilanh53_ve_on,Xilanh50_off;		
				Reset_encoder_ngang();			
	
		while(abs(Encoder_ngang())<3000)
				{
						Nang_Truc(60,3);	
						Truot_Vao(50,8);
						robotLineRun(900, 30, 1);
						if(wantExit()) return;	 			
				}
				
	 while(abs(Encoder_ngang())<37000)
				{
						Nang_Truc(60,3);
					  if(abs(Encoder_ngang()) > 25000)			Truot_Ra(200,1); 
						robotLineRun(825, 60 , 1.3); 
						//robotLineRun(900, 20 , 1.5);
						if(wantExit()) return;	 			
				}
				
//	while(abs(Encoder_ngang())<41000)
//				{
//						Nang_Truc(60,3);	
//						Truot_Ra(200,1); 
//						robotLineRun(900, 20 , 1.5);
//						if(wantExit()) return;	 			
//				}
						Reset_encoder_ngang();
						robotRun(-900 - _robotIMUAngle,25,0);					// cang nho cang gan line
						robotRotate(-1800,-2.2,0);			
	 while(abs(Encoder_ngang())< 5000)
			{
						Nang_Truc(60,3);	
						Truot_Ra(200,1); 
						if(wantExit()) return;	
			}  
						robotStop(0);
						delay_ms(100);
						bap_benh_auto(3);	
	
			
//-------------------------- chay ve do robot con -----------------------------
						Xilanh53_ve_off;
						robotSetACC(15);
						Reset_encoder_ngang();	
	while(abs(Encoder_ngang())<3000)
				{
						robotLineRun(-920, 30 , 1); 
						Truot_Vao(200,8);
						if(wantExit()) return;	 			
				}
						Xilanh53_ra_on,Xilanh50_on;
	 while(abs(Encoder_ngang())<30000)
				{
						if(abs(Encoder_ngang()) < 20000)  Truot_Vao(120,8);
						if(abs(Encoder_ngang()) > 20500)  Truot_Ra(60,3);
						Ha_Truc(50,6);
						robotLineRun(-850, 55 , 1.1); 
						if(wantExit()) return;	 			
				}
				
	while(abs(Encoder_ngang())<33000)
				{
						Truot_Ra(60,3);
						Ha_Truc(50,6);
						robotLineRun(-880, 45 , 1.40); 
						if(wantExit()) return;	 			
				}
				
	while(cb_quang_left && (abs(Encoder_ngang())<40000))
				{
						Truot_Ra(60,3);
						Ha_Truc(50,6);
						robotLineRun(-880, 35 , 1.45); 
						if(wantExit()) return;	 			
				}	

	while(_ADC1_Value[0] > 500)																	 // nhan laze giua don robot
				{
						Truot_Ra(60,3);
						Ha_Truc(50,6);
						robotLineRun(-890, 20 , 1.40); 
						if(wantExit()) return;	 			
				}					
//						robotStop(0);
						robotSetACC(32);
						robotRun(0,10,0);
						robotRotate(5,0.5,0);
			do{
						if(!cb_TTruoc && !cb_PTruoc)   robotStop(0);
						Ha_Truc(180,7);
						Truot_Ra(120,3);
						if(wantExit()) return;
				}
		 while(cb_NC_7);
						return;
}
		
// -----------------------------------------------------------------
// ----------------------  XICH DU DO  -----------------------------
// -----------------------------------------------------------------

void XICH_DU_DO(int Stop_Roate, int Roate)
{
						auto_mode=3;
						Xilanh_kep_on;delay_ms(200);											// kep delay 100ms
						Xilanh53_ve_off,Xilanh50_on,Xilanh53_ra_on;				// cho canh tay nam ngang
				Reset_encoder_doc();	
						Nang_Truc(100,5);																	// nang truc toc do 100
						robotRun(-1350 - _robotIMUAngle,60,0);
						robotRotate(1,0.5,0);			
	
		while(abs(Encoder_doc()) < 2300)													// VN->CHAMPION
			{
						Nang_Truc(100,5);
						Truot_Vao(150,8);
						if(wantExit()) return;
			}		
				Reset_encoder_ngang();				
						robotRun(-1200 - _robotIMUAngle,60,0);						// chay goc -1200-imu, xoay goc -1800
						robotRotate(-1800,-2.8,0);
		do{		
						Truot_Vao(120,8);
						Nang_Truc(50,2);
						if(abs(_robotIMUAngle) > 1680)   Xilanh_cheo_on;
						if(wantExit()) return;
			}
		while(abs(_robotIMUAngle) < Stop_Roate);									// bat dau chay ngang
						flash_bit=1;
						Xilanh_cheo_on;								
				Reset_encoder_ngang();
						robotRun(-900 - _robotIMUAngle,30,0);
						robotRotate(-Roate,-1,0);
		do{		
						Truot_Vao(20,8);
						Nang_Truc(150,2);
						if(wantExit()) return;
			}
		while(_ADC1_Value[0] > 1000);														 // nhan laze dem encoder, tat mode
				    flash_bit=1;	
						Xilanh_mode_on;				
				Reset_encoder_ngang();		
						robotRun(-900 - _robotIMUAngle,15,0);				// speed=20
						robotRotate(-Roate,-0.8,0);
		do{
						Truot_Vao(20,8);	
						Nang_Truc(150,2);
						if(wantExit()) return;	
			}  
		while(abs(Encoder_ngang())<3000);
		do{		
						Truot_Vao(20,8);
						Nang_Truc(120,1);
						if(wantExit()) return;
		  }
			
		while(cb_XICHDU_P && !cb_XICHDU_T);								// cam bien ben phai nhan truoc
						flash_bit=1;							
		do{		
						Truot_Vao(20,8);
						Nang_Truc(150,1);
						if(wantExit()) return;
		  }
		while(cb_XICHDU_T || cb_XICHDU_P);															// cam bien trai nhan, robot chay thang
						flash_bit=1;					
				Reset_encoder_doc();
						Xilanh_mode_off;	
						robotRun(-1770 - _robotIMUAngle,10,0);
						robotRotate(-Roate,-0.7,0);
		 do{		
						Truot_Ra(200,1);
						Nang_Truc(200,1);
						if(wantExit()) return;
				}
		while(cb_XICHDU);										 // robot stop neu nhan laze xich du
						flash_bit=1;	
						robotStop(0);
						Truot_Ra_While(250,1);								//  dua het canh tay ra 
						Ha_Truc_While(150,4);									//  ha truc	
						Truot_Vao_While(150,7);					
}
// -----------------------------------------------------------------
// ----------------------  COT DO  ---------------------------------
// -----------------------------------------------------------------
void LEO_COT_DO(int fix_cot_d)
{
					auto_mode=4;
					Reset_encoder_doc();
						Xilanh_kep_on;delay_ms(500);
						Xilanh_mode_on;
						Xilanh_cheo_off,Xilanh53_ra_off,Xilanh53_ve_on;
						Truot_Ra(150,1);
						Nang_Truc(180,2);
						robotRun(0- _robotIMUAngle,20,0);
						robotRotate(-1770,-0.8,0);

			do{		 
						Nang_Truc(180,2);			
						Truot_Ra(150,1);			
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 1500);

			do{		 
						Ha_Truc(60,8);
						Truot_Vao(200,8);	
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 2500);
			do{		 
						Ha_Truc(150,8);
						Truot_Vao(200,8);	
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 4000);
						Xilanh_mode_off;
					Reset_encoder_doc();
						Xilanh50_off;
						Xilanh53_ra_off,Xilanh53_ve_on;
						robotRun(300+ _robotIMUAngle,60,0);   //-1800
						robotRotate(-800,2.8,0);
			do{
						Ha_Truc(150,10);
						Truot_Vao(120,8);
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 16000);
					Reset_encoder_ngang();
						Xilanh50_off;
						robotRun(-fix_cot_d- _robotIMUAngle,80,0);			// so cang lon cang gan cot
						robotRotate(-900,0.7,0);
			do{
						Ha_Truc(120,10);
						Truot_Vao(40,8);
						if(wantExit()) return;
				}
			while(_ADC1_Value[0] > 1000);
						flash_bit=1;
					Reset_encoder_ngang();
						robotRun(-fix_cot_d- _robotIMUAngle,80,0);
						robotRotate(-900,0.7,0);
			do{
						Ha_Truc(120,10);
						Truot_Vao(40,8);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 20000);
						Xilanh_mode_on;
						robotRun(-fix_cot_d- _robotIMUAngle,30,0);
						robotRotate(-900,0.7,0);
			do{
						Ha_Truc(80,10);
						Truot_Ra(120,6);
						if(wantExit()) return;
				}
			while(_ADC1_Value[0] > 1000);
						Xilanh_mode_off;
						flash_bit=1;
					Reset_encoder_ngang();
						robotRun(-fix_cot_d- _robotIMUAngle,20,0);
						robotRotate(-780,3.2,1);
			do{
						Truot_Ra(120,6);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 3000);
						Xilanh_mode_on;
						robotRun(0,15,0);
						robotRotate(-760,1,0);
			while(cb_TTruoc && cb_PTruoc)
				{	
						Truot_Ra(40,6);
						if(wantExit()) return;	
				}
						mor_nang=2,mor_ngang=2;
						robotStop(0);
						Xilanh_mode_off;
			do{
						Truot_Ra(40,6);
						robotLineRun(-900, 20 , 1.29); 
						if(wantExit()) return;
				}
	   while(cb_mode);												
						robotStop(0);
}
// -----------------------------------------------------------------
// ----------------------  CAU THANG  ------------------------------
// -----------------------------------------------------------------
void CAUTHANG_DO(int fix_goc_d)
{
					Xilanh_kep_on; delay_ms(200);
					Xilanh_mode_on;	
		do{
					Nang_truc();	
					if(wantExit()) return;	
			}
		while(cb_mode);	
					Xilanh_mode_off;
					Truot_Vao(200,8);
				Reset_encoder_ngang();
					robotRun(210+ _robotIMUAngle,60,0);
					robotRotate(-840,3.2,0);
		do{
					Truot_Vao(200,8);
					if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 11300);
		do{
					Truot_Vao(200,8);
					if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 11400);
		do{
					Truot_Vao(200,8);
					if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 11500);
					flash_bit=1;
					Xilanh_mode_on;
				Reset_encoder_ngang();
					robotRun(fix_goc_d + _robotIMUAngle,70,0);					// so cang lon cang gan cau thang
					robotRotate(-840,2.8,0);
		do{
					if(abs(Encoder_ngang()) > 1000)			Xilanh_mode_off;
					Truot_Vao(50,8);
					Nang_Truc(80,8);
					if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 20000);						// bat dau chay cham lai
					robotRun(fix_goc_d +_robotIMUAngle,20,0);					// so cang lon cang gan cau thang
					robotRotate(-840,2.2,0);
					Xilanh50_on;
		do{
					Truot_Ra(60,5);
					Nang_Truc(80,8);		
					if(wantExit()) return;
			}
		while(_ADC1_Value[0] > 1600);											 // kiem tra laze nhan thanh cau thang
				Reset_encoder_ngang();
		do{
					Truot_Ra(60,5);
					Nang_Truc(80,8);		
					if(wantExit()) return;
			}
		while(abs(Encoder_ngang()) < 1500);											// kiem tra laze nhan thanh cau thang
					robotRun(850+_robotIMUAngle,20,0);
					robotRotate(-840,2.8,0);
		while(cb_TTruoc && cb_PTruoc)
			{	
					Truot_Ra(150,5);		
			}
					robotStop(0);
					Truot_Ra_While(120,5);
			mor_nang=2,mor_ngang=2;			
}
// -----------------------------------------------------------------
// ----------------------  BAN XICH DU  ----------------------------
// -----------------------------------------------------------------
void BAN_XICHDU_DO()
{
						Xilanh_mode_on;delay_ms(100);Xilanh_mode_off;
						Xilanh_kep_off,Xilanh_cheo_on;
			while(cb_Kep)											if(wantExit()) return;
						Xilanh53_ra_off,Xilanh53_ve_on,Xilanh50_off;		
			while(_ADC1_Value[2] < 2300)				if(wantExit()) return;
						Xilanh_ban_on;
			while(cb_BAN)											if(wantExit()) return;		
						Xilanh_ban_off;
					Reset_encoder_doc();
						robotRun(1800,30,0);
						robotRotate(-1770,0.7,0);
			do{		 
						Nang_Truc(120,1);
						Truot_Vao(100,4);				
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 4000);
						robotRun(1800,20,0);
						robotRotate(-1770,0.7,0);
			do{		 
						Nang_Truc(120,1);
						Truot_Vao(100,4);
						Xilanh50_on;
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 6000);
						mor_nang=2;
						robotStop(2);

}
// -----------------------------------------------------------------
// ----------------------  DON XICH DU -----------------------------
// -----------------------------------------------------------------
void DON_XICHDU_DO()
{	
						Xilanh_cheo_on,Xilanh_kep_off;
						Xilanh53_ve_off,Xilanh53_ra_on,Xilanh50_on;
					Reset_encoder_doc();
						robotRun(0,15,0);
						robotRotate(-1770,0.5,0);
			do{		 
						Truot_Ra(150,7);				
						if(wantExit()) return;
				}
			while(cb_XICHDU);
						mor_nang=2;
						robotStop(2);
		  while(cb_DON_XICHDU_T && cb_DON_XICHDU_P)			if(wantExit()) return;
						Ha_Truc_While(200,3);
						//mor_nang=2;
}
// -----------------------------------------------------------------
// ----------------------  THA COT  --------------------------------
// -----------------------------------------------------------------
void THA_COT_DO()
{
		while(cb_NC_9)					
				{
						Nang_Truc(35,9);
						if(wantExit()) return;
				}
						mor_nang=2;
						Xilanh_mode_on;delay_ms(50);Xilanh_mode_off;	
		do{
						Nang_truc();
						if(wantExit()) return;
			}
		while(cb_mode);							
						Xilanh_kep_off;
		while(cb_Kep)								if(wantExit()) return;
						Truot_Vao(200,8);		
			Reset_encoder_doc();		
						robotRun(250- _robotIMUAngle,20,0); // -650 // 1550
						robotRotate(-1050,-1.2,0);
			do{
						Truot_Vao(200,8);
						if(wantExit()) return;
				}
	   while(abs(Encoder_doc()) < 3600);
			do{
						Truot_Vao(200,8);
						if(wantExit()) return;
				}
	   while(abs(Encoder_doc()) < 3700);
			do{
						Truot_Vao(200,8);
						if(wantExit()) return;
				}
	   while(abs(Encoder_doc()) < 3800);    // con moi 3200
					Reset_encoder_ngang();		
					robotRun(-280- _robotIMUAngle,30,0); // -650 // 1550
					robotRotate(-1120,-0.7,1);
			do{
//						Truot_Ra(80,1);
						if(wantExit()) return;
				}
	   while(abs(Encoder_ngang()) < 4200);
						mor_nang=2,mor_ngang=2;
						robotStop(2);
		while(cb_Tay)		if(wantExit()) return;	
						Truot_Ra_While(140,6);
						Truot_Ra_While(80,7);
}
void THA_CAUTHANG_DO()
{
	
						Xilanh_kep_off;
			while(cb_Kep)																	if(wantExit()) return;
						Truot_Vao(200,8);
				Reset_encoder_doc();
						robotRun(900- _robotIMUAngle,20,0);
			do{
						Truot_Vao(200,8);
						if(wantExit()) return;
				}
			while(abs(Encoder_doc()) < 3000);	
						Xilanh50_off;
				Reset_encoder_ngang();
						robotRun(- _robotIMUAngle,20,0);
			do{
						Truot_Vao(20,8);
						if(wantExit()) return;
				}
			while(abs(Encoder_ngang()) < 3000);	
						robotStop(2);		
}


