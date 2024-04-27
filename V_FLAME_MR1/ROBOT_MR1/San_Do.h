//**********************************SAN DO*************************************
void Xuat_phat_do(void)
{
	RESET_ENCODER();

	robotRunAngle(-1350,80,0,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 4200)	{	if(wantExit() == 1) break; vTaskDelay(1);}
	
	robotRunAngle(-900,80,5,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000)	{	taget_BT_Nang_Lua = Min_BT_Nang_Lua ;
																										if(wantExit() == 1) break; vTaskDelay(1);}		
	
	robotRunAngle(-850,120,5,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 36000)	{	if(wantExit() == 1) break; vTaskDelay(1);}
	
	robotRunAngle(-850,40,5,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 38000)	{	if(wantExit() == 1) break; vTaskDelay(1);}
		
	for(i=0;i<50;i++)	while(lazeTraiValue > 80 )		{	if(wantExit() == 1) break; vTaskDelay(1);}
	
	XI_LANH_TRUOTGAPLUA_ON;
	
	robotRunAngle(-850,20,5,0.1);
	for(i=0;i<50;i++)	while(CB_NHAN_LUA == 1) {	if(wantExit() == 1) break; vTaskDelay(1);}	
//	RESET_ENCODER();	
//	for(i=0;i<50;i++)	while(ENCODER_TONG() < 160)	{	if(wantExit() == 1) break; vTaskDelay(1);}
	vTaskDelay(1200);
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

	for(i=0;i<50;i++)	while(ENCODER_TONG() < 40000)					{		//if(ENCODER_TONG() > 5000)	taget_BT_Xoay = Max_BT_Xoay;
																															
																															Bam_thanh_laser_trai_1800(80,0,82,3,120);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)						{		Bam_thanh_laser_trai_1800(80,0,82,3,100);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}	
	
	taget_BT_Nang_Lua = Min_BT_Nang_Lua + 15   ;
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 60000)					{		Bam_thanh_laser_trai_1800(40,-5,82,1,100);//-5	
																															if(wantExit() == 1) break; vTaskDelay(1);}	
	
	for(i=0;i<50;i++)	{while(lazeSauValue > 89)					{		Bam_thanh_laser_trai_1800(17,-5,82,1,80);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}
																																vTaskDelay(1);}
	
	robotStop(1);
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	XI_LANH_KEPLUATREN_OFF;
	vTaskDelay(1500);																														
		
	RESET_ENCODER();	
		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000)					{		if(ENCODER_TONG() > 4000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_trai_1800(40,0,83,2,100);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}								

	taget_BT_Nang_Lua = Min_BT_Nang_Lua +15   ;
									
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 14500)					{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_trai_1800(17,0,83,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}																																																							
																															
	for(i=0;i<50;i++)	{while(lazeSauValue > 40)			{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_trai_1800(17,-20,83,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
																											vTaskDelay(1);}
	robotStop(1);
	
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	
	XI_LANH_KEPLUADUOI_OFF;
	vTaskDelay(1500);
																															
//***************************************** ve lay lua lan 2 ************************************************************																														
																															
	RESET_ENCODER();
	robotRunAngle(950,60,0,0.1);																															
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 12000) 					{	if(wantExit() == 1) break; vTaskDelay(1);}	
	robotStop(0);
//---------------------------------------lay lan 2-------------------------------------------------------------
	RESET_ENCODER();
	robotRunAngle(0,60,15,0.1);		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)		{	if(ENCODER_TONG() > 20000)	taget_BT_Nang_Lua = Min_BT_Nang_Lua ;
																											Bam_thanh_laser_trai(100,0,158,4,100);
																											if(wantExit() == 1) break; vTaskDelay(1);}
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 70000)		{	Bam_thanh_laser_trai(60,0,158,2,100);
																											if(wantExit() == 1) break; vTaskDelay(1);}

	for(i=0;i<50;i++)	while(CB_CHAM_THANH_LUA1 == 1) 	{	Bam_thanh_laser_trai(20,0,158,2,80);;
																											if(wantExit() == 1) break; vTaskDelay(1);}																										
																											
																						
	
	for(i=0;i<50;i++)	while(CB_CHAM_THANH_LUA == 1) 	{	Bam_thanh_laser_trai(15,0,158,2,80);;
																											if(wantExit() == 1) break; vTaskDelay(1);}

	robotStop(0);									
																											
	RESET_ENCODER();
	robotRunAngle(800,15,0,0.1);
																																																		
																									
	for(i=0;i<50;i++)	while(CB_NHAN_LUA == 1) {	if(wantExit() == 1) break; vTaskDelay(1);}
	
	XI_LANH_TRUOTGAPLUA_ON;	
	
	vTaskDelay(1200);
		
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
																															
																															Bam_thanh_laser_trai_1800(80,5,183,3,120);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)						{		Bam_thanh_laser_trai_1800(80,5,183,3,100);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}	
	
	taget_BT_Nang_Lua = Min_BT_Nang_Lua + 15   ;
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 60000)					{		Bam_thanh_laser_trai_1800(40,5,183,1,100);//-5	
																															if(wantExit() == 1) break; vTaskDelay(1);}	
	
	for(i=0;i<50;i++)	{while(lazeSauValue > 89)					{		Bam_thanh_laser_trai_1800(17,5,183,1,80);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}
																																vTaskDelay(1);}
	
	robotStop(1);
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	XI_LANH_KEPLUATREN_OFF;
	vTaskDelay(1500);																														
		
	RESET_ENCODER();	
		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000)					{		if(ENCODER_TONG() > 4000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_trai_1800(40,5,183,2,100);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}								

	taget_BT_Nang_Lua = Min_BT_Nang_Lua +15   ;
									
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 14500)					{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_trai_1800(17,5,183,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}																																																							
																															
	for(i=0;i<50;i++)	{while(lazeSauValue > 39)			{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_trai_1800(17,5,183,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
																											vTaskDelay(1);}
	robotStop(1);
	
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	
	XI_LANH_KEPLUADUOI_OFF;
	vTaskDelay(1500);
																																
////***************************************** va lay lua lan 3 ************************************************************																																
	RESET_ENCODER();
	robotRunAngle(950,60,0,0.1);																															
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 12000) 					{	if(wantExit() == 1) break; vTaskDelay(1);}	
	robotStop(0);
	
	
	
//---------------------------------------lay lan 3-------------------------------------------------------------
	RESET_ENCODER();
	robotRunAngle(0,60,15,0.1);		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)		{	if(ENCODER_TONG() > 20000)	taget_BT_Nang_Lua = Min_BT_Nang_Lua ;
																											Bam_thanh_laser_trai(100,0,258,4,100);
																											if(wantExit() == 1) break; vTaskDelay(1);}
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 70000)		{	Bam_thanh_laser_trai(60,0,258,2,100);
																											if(wantExit() == 1) break; vTaskDelay(1);}

	for(i=0;i<50;i++)	while(CB_CHAM_THANH_LUA1 == 1) 	{	Bam_thanh_laser_trai(20,0,258,2,80);;
																											if(wantExit() == 1) break; vTaskDelay(1);}																										
																											
																						
	
	for(i=0;i<50;i++)	while(CB_CHAM_THANH_LUA == 1) 	{	Bam_thanh_laser_trai(15,0,258,2,80);;
																											if(wantExit() == 1) break; vTaskDelay(1);}

	robotStop(0);									
																											
	RESET_ENCODER();
	robotRunAngle(800,15,0,0.1);
																																																		
																									
	for(i=0;i<50;i++)	while(CB_NHAN_LUA == 1) {	if(wantExit() == 1) break; vTaskDelay(1);}
	
	XI_LANH_TRUOTGAPLUA_ON;	
	
	
	vTaskDelay(1200);
		
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
																															
																															Bam_thanh_laser_trai_1800(80,5,283,3,120);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 50000)						{		Bam_thanh_laser_trai_1800(80,5,283,3,100);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}	
	
	taget_BT_Nang_Lua = Min_BT_Nang_Lua + 15   ;
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 60000)					{		Bam_thanh_laser_trai_1800(40,5,283,1,100);//-5	
																															if(wantExit() == 1) break; vTaskDelay(1);}	
	
	for(i=0;i<50;i++)	{while(lazeSauValue > 89)					{		Bam_thanh_laser_trai_1800(17,5,283,1,80);//-5	
																														if(wantExit() == 1) break; vTaskDelay(1);}
																																vTaskDelay(1);}
	
	robotStop(1);
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	XI_LANH_KEPLUATREN_OFF;
	vTaskDelay(1500);																														
		
	RESET_ENCODER();	
		
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000)					{		if(ENCODER_TONG() > 4000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_trai_1800(40,5,283,2,100);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}								

	taget_BT_Nang_Lua = Min_BT_Nang_Lua +15   ;
									
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 14500)					{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_trai_1800(17,5,283,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}																																																							
																															
	for(i=0;i<50;i++)	{while(lazeSauValue > 39)			{		//if(ENCODER_TONG() > 2000)		XI_LANH_TRUOTGAPLUA_OFF;
																															Bam_thanh_laser_trai_1800(17,5,283,1,80);			//-5
																															if(wantExit() == 1) break; vTaskDelay(1);}
																											vTaskDelay(1);}
	robotStop(1);
	
	while(START)	{	robotGamePadControl();
									vTaskDelay(1);}		
	
	XI_LANH_KEPLUADUOI_OFF;
	vTaskDelay(1500);
	
	RESET_ENCODER();
	robotRunAngle(950,60,0,0.1);																															
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 8000) 					{	if(ENCODER_TONG() > 5000)	XI_LANH_TONG_ON;vTaskDelay(2000);
																															XI_LANH_KEP_BONG_OFF;
																															if(wantExit() == 1) break; vTaskDelay(1);}		
	
	taget_BT_Nang_Lua = Max_BT_Nang_Lua;
	RESET_ENCODER();			
																															
	robotRun(450 - _robotIMUAngle,60);	
	robotRotate(-1850,-0.6,0);																												
	while(_robotIMUAngle > -1820){	if(wantExit() == 1) break; vTaskDelay(1);}	
	
	robotRunAngle(900,40,-1840,-0.3);	
	for(i=0;i<50;i++)	while(lazeTraiValue > 7)		{	if(wantExit() == 1) break; vTaskDelay(1);}	
	Home = 1;
	robotStop(0);
	Vi_tri = 1;																				
																														
}																									

void chay_san_2_do(void)
{ 
	
//------len doc-----------
	RESET_ENCODER();
	robotRunAngle(1800,120,-1850,0.1);	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 62000) 	{if(wantExit() == 1) break; vTaskDelay(1);}
	
	robotRunAngle(1800,60,-1850,0.1);	
	for(i=0;i<50;i++)	while(lazeTruocValue > 185 )		{	if(wantExit() == 1) break; vTaskDelay(1);}
	
	robotStop(0);
	
	RESET_ENCODER();
	robotRunAngle(-1350,50,-1850,0.1);	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 10000) 	{	taget_BT_Xoay = goc_ban;
																											if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(lazeTruocValue > 95)		{	if(wantExit() == 1) break; vTaskDelay(1);}
	
	RESET_ENCODER();
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 20000)	{bam_Thanh_Lazer_Truoc_san2do(50,-1850,89,2,120)	;
																											if(wantExit() == 1) break; vTaskDelay(1);}
	
	for(i=0;i<50;i++)	while(lazePhaiValue > 207)		{bam_Thanh_Lazer_Truoc_san2do(30,-1850,89,2,120)	;
																											if(wantExit() == 1) break; vTaskDelay(1);}
	robotStop(1);
	
		
}
void retry_san2_do (void)
{	
	RESET_ENCODER();
	robotRunAngle(1500,100,0,0.2);	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 9000) 	{if(ENCODER_TONG() > 5000)	XI_LANH_TONG_ON;vTaskDelay(2000);
																										XI_LANH_KEP_BONG_OFF;
																										if(wantExit() == 1) break; vTaskDelay(1);}
	Home = 1;
	robotRotate(-1850,-0.6,0);	
	while(_robotIMUAngle > -1800){	if(wantExit() == 1) break; vTaskDelay(1);}	
	
	robotRunAngle(1350,30,-1840,-0.3);	
	for(i=0;i<50;i++)	while(lazeTraiValue > 7)		{	if(wantExit() == 1) break; vTaskDelay(1);}	
	
	chay_san_2_do();
//	robotStop(0);

}