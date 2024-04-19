	/*                    ROBOCON 2016                       */
	// Created: 25/12/2015 09:00:00 PM
	// Author: La Tien Sinh ft DG

	#include <stdlib.h>
	#include <math.h>

	unsigned char nho_phai, nho_trai;

	//=================================================
	//--------------- Cac hang so ---------------------
	//=================================================
	const unsigned char maxSpeed = 255;  // Toc do toi da se chinh la fixDirError + maxSpeed
	extern char tang_toc;
	extern s16 data_gyro , temp;
	unsigned int time_out = 0, so_cam_bien =0, so_cam_bien_trai, so_vach=0,Vach_ngang = 0, so_vach_trai=0, dem_so=0;
	vu8 bit_tang_toc,bit_e_speed;
	
	s16 firstAngle;
	unsigned char speed,tam_speed,tam,td_sau,a,so_line,Bien_sensor;
	unsigned char pwm_50,pwm_40,pwm_30,pwm_20,pwm_10,pwm_90,pwm_80,pwm_70,pwm_60;
	

	void TD_trai (int pwm)								// DC trai sau
	{
			if(pwm >= 0) mor_traisau_next;
			else        mor_traisau_back;      
			mor_traisau = abs(pwm); 
	}

	void TD_phai (int pwm)							// DC phai sau
	{
			if(pwm >= 0) mor_phaisau_next; 
			else        mor_phaisau_back; 
			mor_phaisau = abs(pwm);  
	}

	void TD_truoc (int pwm)						// DC truoc
	{
			if(pwm <= 0) mor_phaitruoc_next, mor_traitruoc_next;
			else       mor_phaitruoc_back, mor_traitruoc_back;
			mor_phaitruoc = abs(pwm);
			mor_traitruoc = abs(pwm);
	}
//	void TD_sau (int pwm)								
//	{
//			if(pwm >= 0) mor_traisau_next,mor_phaisau_next ;
//			else        mor_traisau_back,mor_phaisau_back ;			
//			mor_traisau = abs(pwm);
//			mor_traisau = abs(pwm);
//	}
	
	
	void truot (int pwm)
	{
			if(pwm <= 0) mor_truotngang_next;
			else        mor_truotngang_back;			
			mor_truotngang = abs(pwm);
	}
	void truot_CB (void)
	{
		if(Switch)  // san do
		{
			truot(-70);
			
			while(CB);
			delay_ms(150);
			while(CB);
			truot(3);
			
						
		}
		if(!Switch)  // san xanh
		{
			truot(70);
			while(CB);
			delay_ms(150);
			while(CB);
			truot(-5);			
		}
		
		
	}
	void nang (int pwm)
{	
	  if(pwm > 0 && ct_tren) mor_truot_next , mor_truot = abs(pwm);
			else if(pwm > 0 && !ct_tren) mor_truot = 5,	mor_truot_next;
				else if(pwm < 0 && ct_duoi) mor_truot_back , mor_truot = abs(pwm);
					else if(pwm < 0 && !ct_duoi) mor_truot = 2, mor_truot_next;
							else  mor_truot = 2,	mor_truot_next;
}
void setcot(int pwm, int pwm2) //trai, phai
{
    if(pwm >= 0 ) mor_leotrai_next;
				else  mor_leotrai_back;
		mor_leotrai = abs(pwm);
				
		if(pwm2 >= 0 ) mor_leophai_back;
				else  mor_leophai_next;
				mor_leophai = abs(pwm2);
}
void quat(int pwm)
{
	mor_quat=abs(pwm);
}
	void stopRobot (int pwm)
	{
			TD_trai(pwm), TD_truoc(pwm), TD_phai(pwm);
	}
	
	
	//------------------------------------------------------------------------------------
	//---------------------------	 SAN DO  -----------------------------------------------
	//------------------------------------------------------------------------------------
	
	void Quet_cam_bien (void) //BEN PHAI
	{    
			if(b0 && b1 && b2 && b3 && b4 && b5 && b6 && b7 && nho_phai==1) 				{a=1;}	// lech phai hoan toan
			else if(!b0 && b1 && b2 && b3 && b4 && b5 && b6 && b7 )									{a=2; nho_phai=1;nho_trai=0;	}												//01111111
			else if(!b0&&!b1 && b2 && b3 && b4 && b5 && b6 && b7)										{a=3; nho_phai=1;nho_trai=0;	}												//00111111
			else if(b0 && !b1 && b2 && b3 && b4 && b5 && b6 && b7)									{a=4; nho_phai=0;nho_trai=0;	}												//10111111
			else if(b0 &&!b1&&!b2 && b3 && b4 && b5 && b6 && b7)										{a=5;	}																		//10011111
			else if(b0 && b1 &&!b2 && b3 && b4 && b5 && b6 && b7)										{a=6;	}																		//11011111
			else if(b0 && b1 && !b2&&!b3 && b4 && b5 && b6 && b7)										{a=7;		}																	//11001111	
			else if(b0 && b1 && b2 && !b3 && b4 && b5 && b6 && b7)									{a=8;}																			//11101111
	
			else if(b0 && b1 && b2 && !b3&&!b4 && b5 && b6 && b7)										{a =9;	}																		//11100111
	
			else if(b0 && b1 && b2 && b3&& !b4 && b5 && b6 && b7)										{a =10;	}																	//11110111
			else if(b0 && b1 && b2 && b3&& !b4&&!b5 && b6 && b7 )										{a =11;	}																	//11110011
			else if(b0 && b1 && b2 && b3&& b4&& !b5 && b6 && b7 )										{a =12;	}																	//11111011
			else if(b0 && b1 && b2 && b3&& b4&& !b5 && !b6 && b7) 									{a =13;	}																//10011001
			else if(b0 && b1 && b2 && b3&& b4&& b5 && !b6 && b7) 										{a =14; nho_trai =0;nho_phai=0;}											//10111101
			else if(b0 && b1 && b2 && b3&& b4&& b5 &&!b6 && !b7) 										{a =15; nho_trai =1;nho_phai=0;}												//11111100
			else if(b0 && b1 && b2 && b3&& b4&& b5 &&b6 &&!b7) 											{a =16; nho_trai =1;nho_phai=0;}												//11111110
			else if(b0 && b1 && b2 && b3 && b4 && b5 && b6 && b7 && nho_trai==1)		{ a =17;}   // lech trai hoan toan
			
		
			else if( (!b3 && !b4) && (!b5| !b1 | !b2 |!b6|!b0|!b7)){ a = 19;}  // vach ngang
			
	else if ((!b5 &&!b6) && (!b0 | !b1 | !b2 | !b3 | !b4 | !b7)) { a=19;}
	else if ((!b1 && !b2 && !b3 && !b4 && !b5 ) && (!b6 | !b7 | !b0)) {a = 20;} 
	else if ((!b1 && !b2 && !b3 && !b4 && !b0 ) && (!b6 | !b7 | !b5)) {a = 21;}
	else if ((!b1 && !b2 && !b3  && !b0 ) && (!b6 | !b7 | !b0 | !b4)) {a = 22;} 
	else if ((!b1 && !b2  && !b0 ) && (!b6 | !b7 | !b0 | !b4 | !b3)) {a = 23;}
	else if ((!b1  && !b0 ) && (!b6 | !b7 | !b0 | !b4 | !b3 | !b2)) {a = 24;}	
	else if ((!b1 && !b2 && !b3 && !b4 && !b5 && !b0 && !b6 ) && ( !b7 )) {a = 25;}
		else a=18;
	}
	
	void DK_do_duong (void) 
	{
	 if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
	 }
	 
	 if(a==1)           TD_trai(pwm_30),TD_truoc(-pwm_90),TD_phai(speed);
	 else if(a==2)      TD_trai(pwm_40),TD_truoc(-pwm_80),TD_phai(speed);   
	 else if(a==3)      TD_trai(pwm_50),TD_truoc(-pwm_70),TD_phai(speed);
	 else if(a==4)      TD_trai(pwm_60),TD_truoc(-pwm_60),TD_phai(speed);
	 else if(a==5)      TD_trai(pwm_70),TD_truoc(-pwm_50),TD_phai(speed);
	 else if(a==6)      TD_trai(pwm_80),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==7)      TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==8)      TD_trai(speed),TD_truoc(-pwm_20),TD_phai(speed);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 
	 else if(a==10)      TD_trai(speed),TD_truoc(pwm_20),TD_phai(speed);
	 else if(a==11)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	 else if(a==12)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_80);
	 else if(a==13)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_70);
	 else if(a==14)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_60);
	 else if(a==15)      TD_trai(speed),TD_truoc(pwm_70),TD_phai(pwm_50);
	 else if(a==16)      TD_trai(speed),TD_truoc(pwm_80),TD_phai(pwm_40);
	 else if(a==17)      TD_trai(speed),TD_truoc(pwm_90),TD_phai(pwm_30);
	 
	 else if(a==19)				TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 else if(a==20)				TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 else if(a==21)				TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 else if(a==22)				TD_trai(speed),TD_truoc(2),TD_phai(speed);
		
	 else if(a==18)      TD_trai(speed),TD_truoc(pwm_10),TD_phai(pwm_90);
	}
	
	void DK_do_duong_nhanh (void) 
	{
	 if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
	 }
	 
	 if(a==1)           TD_trai(pwm_40),TD_truoc(-pwm_80),TD_phai(speed-5);
	 else if(a==2)      TD_trai(pwm_50),TD_truoc(-pwm_70),TD_phai(speed-5);   
	 else if(a==3)      TD_trai(pwm_60),TD_truoc(-pwm_40),TD_phai(speed-5);
	 else if(a==4)      TD_trai(pwm_70),TD_truoc(-pwm_40),TD_phai(speed-5);
	 else if(a==5)      TD_trai(pwm_80),TD_truoc(-pwm_30),TD_phai(speed-5);
	 else if(a==6)      TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed-5);
	 else if(a==7)      TD_trai(speed),TD_truoc(-pwm_20),TD_phai(speed-5);
	 else if(a==8)      TD_trai(speed),TD_truoc(-pwm_10),TD_phai(speed-5);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed-5);
	 
	 else if(a==10)      TD_trai(speed),TD_truoc(pwm_10),TD_phai(speed-5);
	 else if(a==11)      TD_trai(speed),TD_truoc(pwm_20),TD_phai(speed-5);
	 else if(a==12)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90-5);
	 else if(a==13)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_80-5);
	 else if(a==14)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_70-5);
	 else if(a==15)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_60-5);
	 else if(a==16)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_50-5);
	 else if(a==17)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_40-5);
	 
	 else if(a==19)				TD_trai(pwm_70),TD_truoc(pwm_30),TD_phai(pwm_40-3);
	 else if(a==20)				TD_trai(pwm_70),TD_truoc(pwm_30),TD_phai(pwm_40-3);
	 else if(a==21)				TD_trai(pwm_70),TD_truoc(pwm_30),TD_phai(pwm_40-3);
	 else if(a==22)				TD_trai(pwm_70),TD_truoc(pwm_30),TD_phai(pwm_40-3);
	else if(a==23)				TD_trai(pwm_70),TD_truoc(pwm_20),TD_phai(pwm_40-3);
	else if(a==24)				TD_trai(pwm_70),TD_truoc(pwm_20),TD_phai(pwm_40-3);
	else if(a==25)				TD_trai(pwm_70),TD_truoc(pwm_20),TD_phai(pwm_40-3);
	 else if(a==18)      TD_trai(pwm_70),TD_truoc(pwm_20),TD_phai(pwm_40-3);
	}
	
	void DK_do_duong_do (void) 
	{
	 if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
	 }
	 
	 if(a==1)           TD_trai(pwm_70),TD_truoc(-pwm_70),TD_phai(speed);
	 else if(a==2)      TD_trai(pwm_70),TD_truoc(-pwm_60),TD_phai(speed);   
	 else if(a==3)      TD_trai(pwm_80),TD_truoc(-pwm_50),TD_phai(speed);
	 else if(a==4)      TD_trai(pwm_80),TD_truoc(-pwm_50),TD_phai(speed);
	 else if(a==5)      TD_trai(pwm_90),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==6)      TD_trai(pwm_90),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==7)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==8)      TD_trai(speed),TD_truoc(-pwm_20),TD_phai(speed);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 
	 else if(a==10)      TD_trai(speed),TD_truoc(pwm_20),TD_phai(speed);
	 else if(a==11)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(speed);
	 else if(a==12)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_90);
	 else if(a==13)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_90);
	 else if(a==14)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_80);
	 else if(a==15)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_80);
	 else if(a==16)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_70);
	 else if(a==17)      TD_trai(speed),TD_truoc(pwm_70),TD_phai(pwm_70);
	 
	 else if(a==19)				TD_trai(pwm_90),TD_truoc(-pwm_20),TD_phai(speed);
	 else if(a==20)				TD_trai(pwm_90),TD_truoc(-pwm_20),TD_phai(speed);
	 else if(a==21)				TD_trai(pwm_90),TD_truoc(-pwm_20),TD_phai(speed);
	 else if(a==22)				TD_trai(pwm_90),TD_truoc(-pwm_20),TD_phai(speed);
		
	 else if(a==18)      TD_trai(pwm_90),TD_truoc(-pwm_20),TD_phai(speed);
	}
	
	void DK_do_duong_san_xanh (void) 
	{
	 if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
	 }
	 
	 if(a==1)           TD_trai(pwm_60),TD_truoc(-pwm_70),TD_phai(speed);
	 else if(a==2)      TD_trai(pwm_70),TD_truoc(-pwm_60),TD_phai(speed);   
	 else if(a==3)      TD_trai(pwm_80),TD_truoc(-pwm_50),TD_phai(speed);
	 else if(a==4)      TD_trai(pwm_80),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==5)      TD_trai(pwm_90),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==6)      TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==7)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==8)      TD_trai(speed),TD_truoc(-pwm_20),TD_phai(speed);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 
	 else if(a==10)      TD_trai(speed),TD_truoc(pwm_20),TD_phai(speed);
	 else if(a==11)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(speed);
	 else if(a==12)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	 else if(a==13)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_90);
	 else if(a==14)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_80);
	 else if(a==15)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_80);
	 else if(a==16)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_70);
	 else if(a==17)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_60);
	 
	 else if(a==19)				TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==20)				TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==21)				TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==22)				TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	 
	 else if(a==18)      TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	}
	
	void DK_do_duong_san_xanh_cham (void) 
	{
	 if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
	 }
	 
	 if(a==1)           TD_trai(pwm_30),TD_truoc(-pwm_90),TD_phai(speed);
	 else if(a==2)      TD_trai(pwm_30),TD_truoc(-pwm_80),TD_phai(speed);   
	 else if(a==3)      TD_trai(pwm_40),TD_truoc(-pwm_70),TD_phai(speed);
	 else if(a==4)      TD_trai(pwm_50),TD_truoc(-pwm_60),TD_phai(speed);
	 else if(a==5)      TD_trai(pwm_60),TD_truoc(-pwm_60),TD_phai(speed);
	 else if(a==6)      TD_trai(pwm_70),TD_truoc(-pwm_50),TD_phai(speed);
	 else if(a==7)      TD_trai(pwm_80),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==8)      TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 
	 else if(a==10)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	 else if(a==11)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_80);
	 else if(a==12)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_70);
	 else if(a==13)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_60);
	 else if(a==14)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_50);
	 else if(a==15)      TD_trai(speed),TD_truoc(pwm_70),TD_phai(pwm_40);
	 else if(a==16)      TD_trai(speed),TD_truoc(pwm_80),TD_phai(pwm_30);
	 else if(a==17)      TD_trai(speed),TD_truoc(pwm_90),TD_phai(pwm_30);	 
	 
	 else if(a==18)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
	}
	
	void DK_do_duong_san_do_cham (void) 
	{
	 if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
	 }
	 
	 if(a==1)           TD_trai(pwm_30),TD_truoc(-pwm_90),TD_phai(speed);
	 else if(a==2)      TD_trai(pwm_30),TD_truoc(-pwm_90),TD_phai(speed);   
	 else if(a==3)      TD_trai(pwm_40),TD_truoc(-pwm_80),TD_phai(speed);
	 else if(a==4)      TD_trai(pwm_50),TD_truoc(-pwm_70),TD_phai(speed);
	 else if(a==5)      TD_trai(pwm_60),TD_truoc(-pwm_60),TD_phai(speed);
	 else if(a==6)      TD_trai(pwm_70),TD_truoc(-pwm_50),TD_phai(speed);
	 else if(a==7)      TD_trai(pwm_80),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==8)      TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 
	 else if(a==10)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	 else if(a==11)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_80);
	 else if(a==12)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_70);
	 else if(a==13)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_60);
	 else if(a==14)      TD_trai(speed),TD_truoc(pwm_70),TD_phai(pwm_50);
	 else if(a==15)      TD_trai(speed),TD_truoc(pwm_80),TD_phai(pwm_40);
	 else if(a==16)      TD_trai(speed),TD_truoc(pwm_90),TD_phai(pwm_30);
	 else if(a==17)      TD_trai(speed),TD_truoc(pwm_90),TD_phai(pwm_30);	 
	 
	 else if(a==18)      TD_trai(speed),TD_truoc(pwm_20),TD_phai(pwm_90);
	}
	
	void DK_do_duong_thang (void) 
	{
	 if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
	 }
	 
	 if(a==1)           TD_trai(speed),TD_truoc(-pwm_70),TD_phai(speed-3);
	 else if(a==2)      TD_trai(speed),TD_truoc(-pwm_50),TD_phai(speed-3);   
	 else if(a==3)      TD_trai(speed),TD_truoc(-pwm_40),TD_phai(speed-3);
	 else if(a==4)      TD_trai(speed),TD_truoc(-pwm_40),TD_phai(speed-3);
	 else if(a==5)      TD_trai(speed),TD_truoc(-pwm_40),TD_phai(speed-3);
	 else if(a==6)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(speed-3);
	 else if(a==7)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(speed-3);
	 else if(a==8)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(speed-3);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed-3);
	 
	 else if(a==10)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(speed-3);
	 else if(a==11)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(speed-3);
	 else if(a==12)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(speed-3);
	 else if(a==13)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(speed-3);
	 else if(a==14)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(speed-3);
	 else if(a==15)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(speed-3);
	 else if(a==16)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(speed-3);
	 else if(a==17)      TD_trai(speed),TD_truoc(pwm_70),TD_phai(speed-3);
		
	 else if(a==18)      TD_trai(pwm_80),TD_truoc(2),TD_phai(pwm_80);
	}
void DK_do_duong_cot_do (void) 
	{
	 if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_90=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
	 }
	 
	 
	 if(a==1)           TD_trai(pwm_60),TD_truoc(-pwm_70),TD_phai(speed);
	 else if(a==2)      TD_trai(pwm_70),TD_truoc(-pwm_60),TD_phai(speed);   
	 else if(a==3)      TD_trai(pwm_80),TD_truoc(-pwm_50),TD_phai(speed);
	 else if(a==4)      TD_trai(pwm_80),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==5)      TD_trai(pwm_90),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==6)      TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==7)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==8)      TD_trai(speed),TD_truoc(-pwm_20),TD_phai(speed);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 
	 else if(a==10)      TD_trai(speed),TD_truoc(pwm_20),TD_phai(speed);
	 else if(a==11)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(speed);
	 else if(a==12)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	 else if(a==13)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_90);
	 else if(a==14)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_80);
	 else if(a==15)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_80);
	 else if(a==16)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_70);
	 else if(a==17)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_60);
	 
	 else if(a==19)				TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	 else if(a==20)				TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	 else if(a==21)				TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	 else if(a==22)				TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	 
	 else if(a==18)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
	}
//void DK_do_duong_cot_xanh (void) 
//	{
//	 if(speed!=tam_speed)
//	 { tam_speed=speed;
//					tam=speed/10;
//					pwm_90=tam*9; 
//					pwm_80=tam*8;
//					pwm_70=tam*7;
//					pwm_60=tam*6;
//					pwm_50=tam*5;
//					pwm_40=tam*4;
//					pwm_30=tam*3;
//					pwm_20=tam*2;
//					pwm_10=tam*1;
//	 }
//	 
//	 if(a==1)           TD_trai(pwm_70),TD_truoc(-pwm_60),TD_phai(speed);
//	 else if(a==2)      TD_trai(pwm_70),TD_truoc(-pwm_50),TD_phai(speed);   
//	 else if(a==3)      TD_trai(pwm_80),TD_truoc(-pwm_50),TD_phai(speed);
//	 else if(a==4)      TD_trai(pwm_80),TD_truoc(-pwm_40),TD_phai(speed);
//	 else if(a==5)      TD_trai(pwm_90),TD_truoc(-pwm_40),TD_phai(speed);
//	 else if(a==6)      TD_trai(pwm_90),TD_truoc(-pwm_40),TD_phai(speed);
//	 else if(a==7)      TD_trai(pwm_90),TD_truoc(-pwm_30),TD_phai(speed);
//	 else if(a==8)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(speed);
//	 
//	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
//	 
//	 else if(a==10)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(speed);
//	 else if(a==11)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_90);
//	 else if(a==12)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_90);
//	 else if(a==13)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_90);
//	 else if(a==14)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_80);
//	 else if(a==15)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_80);
//	 else if(a==16)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_70);
//	 else if(a==17)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_70);
//		
//	 else if(a==18)      TD_trai(pwm_40),TD_truoc(2),TD_phai(pwm_80);
//	}

void run_ngang(int angle,int pwm)
{
	if(data_gyro>angle+1)
	{
		TD_trai(pwm),TD_truoc(-pwm*0.95),TD_phai(-pwm);
	
	}
	else if(data_gyro<angle-1)
	{
		TD_trai(pwm),TD_truoc(-pwm*1.05),TD_phai(-pwm);
	}
	else TD_trai(pwm),TD_truoc(-pwm),TD_phai(-pwm);


}

void run_ngang_do(int angle,int pwm)
{
	if(data_gyro>angle+1)
	{
		TD_truoc(pwm*1.05); TD_phai(pwm); TD_trai(-pwm);
	
	}
	else if(data_gyro<angle-1)
	{
		TD_truoc(pwm*0.95); TD_phai(pwm); TD_trai(-pwm);
	}
	else TD_truoc(pwm); TD_phai(pwm); TD_trai(-pwm);
}

void Update_imu (void)
{
		temp = data_gyro;
		
		if       (temp > 45)     a=1;
		else if  (temp > 40)     a=2;
		else if  (temp > 35)     a=3;
		else if  (temp > 30)     a=4;
		else if  (temp > 25)     a=5; 
		else if  (temp > 15)     a=6;
		else if  (temp > 10)     a=7;
		else if  (temp > 5)     a=8;  
		else if  (temp >0)      a=9;
		else if  (temp < -45)    a=17;
		else if  (temp < -35)    a=16;
		else if  (temp < -30)    a=15;
		else if  (temp < -25)    a=14;
		else if  (temp < -20)    a=13;
		else if  (temp < -15)    a=12;
		else if  (temp < -10)    a=11;
		else if  (temp < -5)    a=10;
		else if  (temp < 0)      a=9;
		else                     a=18;
}


void DK_do_duong_imu(void)
{
	if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
	 }
	 
	 if(a==17)           TD_trai(pwm_30),TD_truoc(-pwm_70),TD_phai(speed);
	 else if(a==16)      TD_trai(pwm_40),TD_truoc(-pwm_60),TD_phai(speed);   
	 else if(a==15)      TD_trai(pwm_50),TD_truoc(-pwm_50),TD_phai(speed);
	 else if(a==14)      TD_trai(pwm_60),TD_truoc(-pwm_40),TD_phai(speed);
	 else if(a==13)      TD_trai(pwm_70),TD_truoc(-pwm_30),TD_phai(speed);
	 else if(a==12)      TD_trai(pwm_80),TD_truoc(-pwm_20),TD_phai(speed);
	 else if(a==11)      TD_trai(pwm_90),TD_truoc(-pwm_20),TD_phai(speed);
	 else if(a==10)      TD_trai(speed),TD_truoc(-pwm_10),TD_phai(speed);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
	 
	 else if(a==8)      TD_trai(speed),TD_truoc(pwm_10),TD_phai(speed);
	 else if(a==7)      TD_trai(speed),TD_truoc(pwm_20),TD_phai(pwm_90);
	 else if(a==6)      TD_trai(speed),TD_truoc(pwm_20),TD_phai(pwm_80);
	 else if(a==5)      TD_trai(speed),TD_truoc(pwm_30),TD_phai(pwm_70);
	 else if(a==4)      TD_trai(speed),TD_truoc(pwm_40),TD_phai(pwm_60);
	 else if(a==3)      TD_trai(speed),TD_truoc(pwm_50),TD_phai(pwm_50);
	 else if(a==2)      TD_trai(speed),TD_truoc(pwm_60),TD_phai(pwm_40);
	 else if(a==1)      TD_trai(speed),TD_truoc(pwm_70),TD_phai(pwm_30);
		
	 else if(a==18)      TD_trai(speed),TD_truoc(2),TD_phai(speed);
}

void DK_do_duong_imu_ngang_do(void)
{
	if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
		 
	 if(a==17)           TD_trai(-speed),TD_truoc(pwm_30),TD_phai(speed);
	 else if(a==16)      TD_trai(-speed),TD_truoc(pwm_30),TD_phai(speed);   
	 else if(a==15)      TD_trai(-speed),TD_truoc(pwm_40),TD_phai(speed);
	 else if(a==14)      TD_trai(-speed),TD_truoc(pwm_50),TD_phai(speed);
	 else if(a==13)      TD_trai(-speed),TD_truoc(pwm_60),TD_phai(speed);
	 else if(a==12)      TD_trai(-speed),TD_truoc(pwm_70),TD_phai(speed);
	 else if(a==11)      TD_trai(-speed),TD_truoc(pwm_80),TD_phai(speed);
	 else if(a==10)      TD_trai(-speed),TD_truoc(pwm_90),TD_phai(speed);
	 
	 else if(a==9)      TD_trai(-speed),TD_truoc(speed),TD_phai(speed);
	 
	 else if(a==8)      TD_trai(-pwm_90),TD_truoc(speed),TD_phai(pwm_90);
	 else if(a==7)      TD_trai(-pwm_70),TD_truoc(speed),TD_phai(pwm_80);
	 else if(a==6)      TD_trai(-pwm_60),TD_truoc(speed),TD_phai(pwm_70);
	 else if(a==5)      TD_trai(-pwm_50),TD_truoc(speed),TD_phai(pwm_60);
	 else if(a==4)      TD_trai(-pwm_40),TD_truoc(speed),TD_phai(pwm_40);
	 else if(a==3)      TD_trai(-pwm_30),TD_truoc(speed),TD_phai(pwm_30);
	 else if(a==2)      TD_trai(-pwm_20),TD_truoc(speed),TD_phai(pwm_20);
	 else if(a==1)      TD_trai(-pwm_10),TD_truoc(speed),TD_phai(pwm_10);
		
	 else if(a==18)      TD_trai(-pwm_90),TD_truoc(pwm_90),TD_phai(pwm_90);
	 }
}
void DK_do_duong_imu_ngang_xanh(void)
{
	if(speed!=tam_speed)
	 { tam_speed=speed;
					tam=speed/10;
					pwm_90=tam*9; 
					pwm_80=tam*8;
					pwm_70=tam*7;
					pwm_60=tam*6;
					pwm_50=tam*5;
					pwm_40=tam*4;
					pwm_30=tam*3;
					pwm_20=tam*2;
					pwm_10=tam*1;
		 
//	 if(a==1)           TD_trai(pwm_30),TD_truoc(-speed),TD_phai(-pwm_30);
//	 else if(a==2)      TD_trai(pwm_40),TD_truoc(-speed),TD_phai(-pwm_40);   
//	 else if(a==3)      TD_trai(pwm_50),TD_truoc(-speed),TD_phai(-pwm_50);
//	 else if(a==4)      TD_trai(pwm_60),TD_truoc(-speed),TD_phai(-pwm_60);
//	 else if(a==5)      TD_trai(pwm_70),TD_truoc(-speed),TD_phai(-pwm_70);
//	 else if(a==6)      TD_trai(pwm_80),TD_truoc(-speed),TD_phai(-pwm_80);
//	 else if(a==7)      TD_trai(pwm_90),TD_truoc(-speed),TD_phai(-pwm_90);
//	 else if(a==8)      TD_trai(speed),TD_truoc(-speed),TD_phai(-speed);
//	 
//	 else if(a==9)      TD_trai(speed),TD_truoc(-speed),TD_phai(-speed);
//	 
//	 else if(a==10)      TD_trai(speed),TD_truoc(-speed),TD_phai(-speed);
//	 else if(a==11)      TD_trai(speed),TD_truoc(-pwm_90),TD_phai(-speed);
//	 else if(a==12)      TD_trai(speed),TD_truoc(-pwm_80),TD_phai(-speed);
//	 else if(a==13)      TD_trai(speed),TD_truoc(-pwm_70),TD_phai(-speed);
//	 else if(a==14)      TD_trai(speed),TD_truoc(-pwm_60),TD_phai(-speed);
//	 else if(a==15)      TD_trai(speed),TD_truoc(-pwm_50),TD_phai(-speed);
//	 else if(a==16)      TD_trai(speed),TD_truoc(-pwm_40),TD_phai(-speed);
//	 else if(a==17)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(-speed);
	 if(a==17)           TD_trai(pwm_30),TD_truoc(-speed),TD_phai(-pwm_30);
	 else if(a==16)      TD_trai(pwm_40),TD_truoc(-speed),TD_phai(-pwm_40);   
	 else if(a==15)      TD_trai(pwm_40),TD_truoc(-speed),TD_phai(-pwm_40);
	 else if(a==14)      TD_trai(pwm_40),TD_truoc(-speed),TD_phai(-pwm_40);
	 else if(a==13)      TD_trai(pwm_50),TD_truoc(-speed),TD_phai(-pwm_50);
	 else if(a==12)      TD_trai(pwm_70),TD_truoc(-speed),TD_phai(-pwm_70);
	 else if(a==11)      TD_trai(pwm_80),TD_truoc(-speed),TD_phai(-pwm_80);
	 else if(a==10)      TD_trai(pwm_90),TD_truoc(-speed),TD_phai(-pwm_90);
	 
	 else if(a==9)      TD_trai(speed),TD_truoc(-speed),TD_phai(-speed);
	 
	 else if(a==8)      TD_trai(speed),TD_truoc(-pwm_90),TD_phai(-speed);
	 else if(a==7)      TD_trai(speed),TD_truoc(-pwm_80),TD_phai(-speed);
	 else if(a==6)      TD_trai(speed),TD_truoc(-pwm_70),TD_phai(-speed);
	 else if(a==5)      TD_trai(speed),TD_truoc(-pwm_60),TD_phai(-speed);
	 else if(a==4)      TD_trai(speed),TD_truoc(-pwm_50),TD_phai(-speed);
	 else if(a==3)      TD_trai(speed),TD_truoc(-pwm_40),TD_phai(-speed);
	 else if(a==2)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(-speed);
	 else if(a==1)      TD_trai(speed),TD_truoc(-pwm_30),TD_phai(-speed);
		
	 else if(a==18)      TD_trai(pwm_90),TD_truoc(-pwm_90),TD_phai(-pwm_90);
	 }
	 
	 
}



	//==========================================================================================
	//=====================================  END THIS FILE =====================================
	//==========================================================================================


