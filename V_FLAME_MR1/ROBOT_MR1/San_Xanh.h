//*********************************** SAN XANH *********************************8
void Xuat_phat_xanh(void)
{
//*********************THA LUA LAN 1 ************************************//
	RESET_ENCODER();

	robotRunAngle(1350,80,0,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 6000)	{	if(wantExit() == 1) break; vTaskDelay(1);}
	
	robotRunAngle(900,80,5,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000)	{	taget_BT_Nang_Lua = Min_BT_Nang_Lua ;
																										if(wantExit() == 1) break; vTaskDelay(1);}		
	
	robotRunAngle(850,120,5,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 38000)	{	if(wantExit() == 1) break; vTaskDelay(1);}
	
	robotRunAngle(850,40,5,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 42000)	{	if(wantExit() == 1) break; vTaskDelay(1);}
		
	for(i=0;i<50;i++)	while(lazePhaiValue > 102)		{	if(wantExit() == 1) break; vTaskDelay(1);}
	XI_LANH_TRUOTGAPLUA_ON;
	
	robotRunAngle(650,20,5,0.1);
	for(i=0;i<50;i++)	while(CB_NHAN_LUA == 1) {	if(wantExit() == 1) break; vTaskDelay(1);}	
//	RESET_ENCODER();	
//	for(i=0;i<50;i++)	while(ENCODER_TONG() < 160)	{	if(wantExit() == 1) break; vTaskDelay(1);}
	vTaskDelay(500);
	robotStop(0);
	robotRunAngle(0,15,0,0.1);		//15  
	
	vTaskDelay(3000);
	
	robotStop(0);
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}	
	
	XI_LANH_KEPLUADUOI_ON,XI_LANH_KEPLUATREN_ON;
	vTaskDelay(2000);
	
	taget_BT_Nang_Lua = Min_BT_Nang_Lua + 90;
	
	RESET_ENCODER();
	
	robotRunAngle(1800,40,15,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 2000)	{	if(wantExit() == 1) break; vTaskDelay(1);}
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 40000)					{	Bam_thanh_laser_phai_1800(80,0,75,3,120);			//-5
																														if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)						{		Bam_thanh_laser_phai_1800(80,0,75,3,100);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}	
	
	taget_BT_Nang_Lua = Min_BT_Nang_Lua + 15   ;
	////	for(i=0;i<50;i++)	while(DATA_COLOR[0] != 6 && DATA_COLOR[3] != 6)					{		bam_Thanh_Lazer_Phai_1800(20,50,40,90,3);//-5	
////																																								if(wantExit() == 1) break; vTaskDelay(1);}		//
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 60000)					{		Bam_thanh_laser_phai_1800(40,0,75,1,100);//-5	
																															if(wantExit() == 1) break; vTaskDelay(1);}	
	
	for(i=0;i<50;i++)	{while(lazeSauValue > 89)					{		Bam_thanh_laser_phai_1800(17,0,75,1,80);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}
																																vTaskDelay(1);}
	
	robotStop(1);
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	XI_LANH_KEPLUATREN_OFF;
	vTaskDelay(1500);																														
	
RESET_ENCODER();	
		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000)					{		if(ENCODER_TONG() > 4000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_phai_1800(40,0,75,2,100);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}								

	taget_BT_Nang_Lua = Min_BT_Nang_Lua +15   ;
									
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 14500)					{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_phai_1800(17,0,75,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}																																																							
																															
	for(i=0;i<50;i++)	{while(lazeSauValue > 40)			{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_phai_1800(17,-5,75,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
																											vTaskDelay(1);}
	robotStop(1);
	
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	
	XI_LANH_KEPLUADUOI_OFF;
	vTaskDelay(1500);

////********************************************************chay lay lua lan 2************************************************
RESET_ENCODER();
	robotRunAngle(-950,60,0,0.1);																															
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 12000) 					{	if(wantExit() == 1) break; vTaskDelay(1);}	
	robotStop(0);
//---------------------------------------lay lan 2-------------------------------------------------------------
	RESET_ENCODER();
	robotRunAngle(0,60,15,0.1);		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)		{	if(ENCODER_TONG() > 20000)	taget_BT_Nang_Lua = Min_BT_Nang_Lua ;
																											Bam_thanh_laser_phai(100,0,180,4,100);
																											if(wantExit() == 1) break; vTaskDelay(1);}
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 70000)		{	Bam_thanh_laser_phai(60,0,180,2,100);
																											if(wantExit() == 1) break; vTaskDelay(1);}

	for(i=0;i<50;i++)	while(CB_CHAM_THANH_LUA1 == 1) 	{	Bam_thanh_laser_phai(20,0,180,2,80);;
																											if(wantExit() == 1) break; vTaskDelay(1);}																										
																											
																						
	
	for(i=0;i<50;i++)	while(CB_CHAM_THANH_LUA == 1) 	{	Bam_thanh_laser_phai(15,0,180,2,80);;
																											if(wantExit() == 1) break; vTaskDelay(1);}

	robotStop(0);									
																																		
	RESET_ENCODER();
	robotRunAngle(-800,15,0,0.1);
																											
	for(i=0;i<50;i++)	while(CB_NHAN_LUA == 1) {	if(wantExit() == 1) break; vTaskDelay(1);}
	
	XI_LANH_TRUOTGAPLUA_ON;		
	vTaskDelay(2000);
	robotStop(0);
	robotRun(0,15);		//15  
	vTaskDelay(2500);
	robotStop(0);
	
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}	
	XI_LANH_KEPLUADUOI_ON,XI_LANH_KEPLUATREN_ON;
	vTaskDelay(2000);
	
	taget_BT_Nang_Lua = Min_BT_Nang_Lua + 90;
	
	RESET_ENCODER();
	
	robotRunAngle(1800,40,15,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 2000)	{	if(wantExit() == 1) break; vTaskDelay(1);}	

	for(i=0;i<50;i++)	while(ENCODER_TONG() < 40000)					{		//if(ENCODER_TONG() > 5000)	taget_BT_Xoay = Max_BT_Xoay;
																															
																															Bam_thanh_laser_phai_1800(80,5,176,3,120);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)						{		Bam_thanh_laser_phai_1800(80,5,176,3,100);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}	
	
	taget_BT_Nang_Lua = Min_BT_Nang_Lua + 15   ;
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 60000)					{		Bam_thanh_laser_phai_1800(40,5,176,1,100);//-5	
																															if(wantExit() == 1) break; vTaskDelay(1);}	
	
	for(i=0;i<50;i++)	{while(lazeSauValue > 90)					{		Bam_thanh_laser_phai_1800(17,5,176,1,80);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}
																																vTaskDelay(1);}
	
	robotStop(1);
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		

	XI_LANH_KEPLUATREN_OFF;
	vTaskDelay(1500);																														
	RESET_ENCODER();	
		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000)					{		if(ENCODER_TONG() > 4000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_phai_1800(40,10,174,2,100);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}								

	taget_BT_Nang_Lua = Min_BT_Nang_Lua +15   ;
									
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 14500)					{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_phai_1800(17,10,174,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}																																																							
																															
	for(i=0;i<50;i++)	{while(lazeSauValue > 40)			{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_phai_1800(17,10,174,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
																											vTaskDelay(1);}
	robotStop(1);
	
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	
	XI_LANH_KEPLUADUOI_OFF;
	vTaskDelay(1500);				
////***************************************** lay lua lan 3 ************************************************************************
	RESET_ENCODER();
	robotRunAngle(-950,60,0,0.1);																															
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 12000) 					{	if(wantExit() == 1) break; vTaskDelay(1);}	
	robotStop(0);
	
	
	
//---------------------------------------lay lan 3-------------------------------------------------------------
	RESET_ENCODER();
	robotRunAngle(0,60,15,0.1);		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)		{	if(ENCODER_TONG() > 20000)	taget_BT_Nang_Lua = Min_BT_Nang_Lua ;
																											Bam_thanh_laser_phai(100,0,279,4,100);
																											if(wantExit() == 1) break; vTaskDelay(1);}
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 70000)		{	Bam_thanh_laser_phai(60,0,279,2,100);
																											if(wantExit() == 1) break; vTaskDelay(1);}

	for(i=0;i<50;i++)	while(CB_CHAM_THANH_LUA1 == 1) 	{	Bam_thanh_laser_phai(20,0,279,2,80);;
																											if(wantExit() == 1) break; vTaskDelay(1);}																										
																											
																						
	
	for(i=0;i<50;i++)	while(CB_CHAM_THANH_LUA == 1) 	{	Bam_thanh_laser_phai(15,0,279,2,80);;
																											if(wantExit() == 1) break; vTaskDelay(1);}

	robotStop(0);									
																											
	RESET_ENCODER();
	robotRunAngle(-800,15,0,0.1);																																									
																									
	for(i=0;i<50;i++)	while(CB_NHAN_LUA == 1) {	if(wantExit() == 1) break; vTaskDelay(1);}
	XI_LANH_TRUOTGAPLUA_ON;
	
	vTaskDelay(2000);
	
	robotStop(0);	
	robotRun(0,15);		//15  
	vTaskDelay(2500);
	robotStop(0);
	
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}	
	XI_LANH_KEPLUADUOI_ON,XI_LANH_KEPLUATREN_ON;
	vTaskDelay(2000);
	
	taget_BT_Nang_Lua = Min_BT_Nang_Lua + 90;
	
	RESET_ENCODER();
	
	robotRunAngle(1800,40,15,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 2000)	{	if(wantExit() == 1) break; vTaskDelay(1);}	

for(i=0;i<50;i++)	while(ENCODER_TONG() < 40000)					{		//if(ENCODER_TONG() > 5000)	taget_BT_Xoay = Max_BT_Xoay;
																															
																															Bam_thanh_laser_phai_1800(80,5,275,3,120);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)						{		Bam_thanh_laser_phai_1800(80,5,275,3,100);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}	
	
	taget_BT_Nang_Lua = Min_BT_Nang_Lua + 15   ;
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 60000)					{		Bam_thanh_laser_phai_1800(40,5,275,1,100);//-5	
																															if(wantExit() == 1) break; vTaskDelay(1);}	
	
	for(i=0;i<50;i++)	{while(lazeSauValue > 90)					{		Bam_thanh_laser_phai_1800(17,5,275,1,80);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}
																																vTaskDelay(1);}
	
	robotStop(1);
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	XI_LANH_KEPLUATREN_OFF;
	vTaskDelay(1500);																														
		
	RESET_ENCODER();	
		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000)					{		if(ENCODER_TONG() > 4000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_phai_1800(40,5,275,2,100);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}								

	taget_BT_Nang_Lua = Min_BT_Nang_Lua +15   ;
									
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 14500)					{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_phai_1800(17,5,275,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}																																																							
																															
	for(i=0;i<50;i++)	{while(lazeSauValue > 40)			{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_phai_1800(17,20,275,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
																															vTaskDelay(1);}
	robotStop(1);
	
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	
	XI_LANH_KEPLUADUOI_OFF;
	vTaskDelay(1500);
									
	RESET_ENCODER();
	robotRunAngle(-950,60,15,0.1);																															
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 8000) 					{	if(ENCODER_TONG() > 5000)		XI_LANH_KEP_BONG_OFF;vTaskDelay(3000);
																															XI_LANH_TONG_ON;
																															if(wantExit() == 1) break; vTaskDelay(1);}		
	
	taget_BT_Nang_Lua = Max_BT_Nang_Lua;
	RESET_ENCODER();			
																															
	robotRun(-450 - _robotIMUAngle,60);	
	robotRotate(1850,0.6,0);																												
	while(_robotIMUAngle < 1800){	if(wantExit() == 1) break; vTaskDelay(1);}	
	
	robotRunAngle(-900,40,1800,0.1);	
	for(i=0;i<50;i++)	while(lazePhaiValue > 5)		{	if(wantExit() == 1) break; vTaskDelay(1);}	

	robotStop(0);
	Home = 1;																																																
	Vi_tri = 1;
}
void chay_san_2(void)
{																				
	
	RESET_ENCODER();
	robotRunAngle(-1800,120,1830,0.1);	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 65000) 	{if(wantExit() == 1) break; vTaskDelay(1);}
	
	robotRunAngle(-1800,80,1830,0.1);	
	for(i=0;i<50;i++)	while(lazeTruocValue > 180 )		{	if(wantExit() == 1) break; vTaskDelay(1);}
	
	robotStop(0);
	
	RESET_ENCODER();
	robotRunAngle(1450,60,1830,0.1);	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000) 	{	taget_BT_Xoay = goc_ban;
																											if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(lazeTruocValue > 95 )		{	if(wantExit() == 1) break; vTaskDelay(1);}
	
	RESET_ENCODER();
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 20000)	{bam_Thanh_Lazer_Truoc_do(50,1850,89,2,120)	;
																											if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(lazeTraiValue > 207)		{bam_Thanh_Lazer_Truoc_do(30,1850,89,2,120)	;
																											if(wantExit() == 1) break; vTaskDelay(1);}
	robotStop(1);
																																											
}
void retry_san2_xanh(void)
{

	RESET_ENCODER();
	robotRunAngle(-1550,80,0,0.2);	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 8000) 	{if(ENCODER_TONG() > 5000)	XI_LANH_TONG_ON;vTaskDelay(2000);
																										XI_LANH_KEP_BONG_OFF;
																										if(wantExit() == 1) break; vTaskDelay(1);}
	Home = 1 ;
	robotRotate(1850,0.6,0);	
	while(_robotIMUAngle < 1800){	if(wantExit() == 1) break; vTaskDelay(1);}	
		
	robotRunAngle(-1350,30,1840,-0.3);	
	for(i=0;i<50;i++)	while(lazePhaiValue > 5)		{	if(wantExit() == 1) break; vTaskDelay(1);}	
	
	chay_san_2();
		
	robotStop(0);
}