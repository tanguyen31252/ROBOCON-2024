//****************************** Khai bao bien toan cuc ******************************//
char vi_tri = 0, Cbnv = 0, Cbnn = 0;
char bien_test_rulo, bien_xl_tay_lay_lua_tren, bien_xl_tay_lay_lua_duoi, bien_xl_vuon_tay_lay_lua, bien_xl_lay_thoc, bien_xl_ban_thoc, bien_xl_ha_lay_lua, bien_xl_nang_lay_lua;
extern int Vi_tri_LX, Vi_tri_TP, BT_MamXoay_value;
extern char bit_reset_mamxoay;

int goc_lech;
int T1=0, T2=0, T3=0, T4=0, P1=0, P2=0, P3=0, P4=0;
int BT_MamXoay_Trai = 410, BT_MamXoay_Phai = 635, BT_MamXoay_0 = 515;

//----------------------------- CAC CO CAU TREN ROBOT ----------------------------------------------------
int tinh_goc_lech()
{
	goc_lech = 0 - robotAngle();
	return goc_lech;
}

//********************** RESET KHI KHOI DONG ROBOT ****************************//
void RESET_MamXoay(){
	int Speed_MamXoay = 100;
	
	if(BT_MamXoay_value < 500){	
		while(BT_MamXoay_value < BT_MamXoay_0){
			Mor_MamXoay = Speed_MamXoay, Mor_MamXoay_back;
			if(wantExit()) break; 
			vTaskDelay(2);
		}
			Mor_MamXoay = 0, bit_reset_mamxoay = 0;
	}
	
	if(BT_MamXoay_value > 520){
		while(BT_MamXoay_value > BT_MamXoay_0){
			Mor_MamXoay = Speed_MamXoay, Mor_MamXoay_next;
			if(wantExit()) break; 
			vTaskDelay(2);
		}
		Mor_MamXoay = 0, bit_reset_mamxoay = 0;
	}	
} 

//------------------------------ DI CHUYEN DO LINE TREN VUNG 2 ------------------------------//
void HamChangeValueDoLine(){	
	if(CB_Line_T1 == 0) T1 = 0;
	else 			 					T1 = 1;
	
	if(CB_Line_T2 == 0) T2 = 0;
	else 			 					T2 = 1;
	
	if(CB_Line_T3 == 0) T3 = 0;
	else 			 					T3 = 1;
	
	if(CB_Line_T4 == 0) T4 = 0;
	else 			 					T4 = 1;
	
	if(CB_Line_P1 == 0) P1 = 0;
	else 			 					P1 = 1;
	
	if(CB_Line_P2 == 0) P2 = 0;
	else 			 					P2 = 1;
	
	if(CB_Line_P3 == 0) P3 = 0;
	else 			 					P3 = 1;
	
	if(CB_Line_P4 == 0) P4 = 0;
	else 			 					P4 = 1;
	
	if		(T1==0 && T2==1 && T3==1 && T4==1)	LechLineTrai = -3,mat_line_trai=-3;
	else if	(T1==0 && T2==0 && T3==1 && T4==1)	LechLineTrai = -2;
	else if	(T1==1 && T2==0 && T3==1 && T4==1)	LechLineTrai = -1;	
	else if	(T1==1 && T2==0 && T3==0 && T4==1)	LechLineTrai = 0,mat_line_trai=0;	
	else if	(T1==1 && T2==1 && T3==0 && T4==1)	LechLineTrai = 1;	
	else if	(T1==1 && T2==1 && T3==0 && T4==0)	LechLineTrai = 2;
	else if	(T1==1 && T2==1 && T3==1 && T4==0)	LechLineTrai = 3,mat_line_trai=3;				
	else LechLineTrai = 0;
	
	if		(P1==0 && P2==1 && P3==1 && P4==1)	LechLinePhai = -3,mat_line_phai=-3;
	else if	(P1==0 && P2==0 && P3==1 && P4==1)	LechLinePhai = -2;
	else if	(P1==1 && P2==0 && P3==1 && P4==1)	LechLinePhai = -1;	
	else if	(P1==1 && P2==0 && P3==0 && P4==1)	LechLinePhai = 0,mat_line_phai=0;	
	else if	(P1==1 && P2==1 && P3==0 && P4==1)	LechLinePhai = 1;	
	else if	(P1==1 && P2==1 && P3==0 && P4==0)	LechLinePhai = 2;
	else if	(P1==1 && P2==1 && P3==1 && P4==0)	LechLinePhai = 3,mat_line_phai=3;
	else LechLinePhai = 0;
}

void SangTrai_DoLine(int En, int Speed){
	RESET_ENCODER();
//	robotSetACC(20,100);

	// while(ENCODER_TONG()< En){
		if		 (LechLineTrai == -3 && LechLinePhai == -3)	robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -3 && LechLinePhai == -2)	robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -3 && LechLinePhai == -1)	robotRunAngle(900, Speed,goc_lech, 0.1);
		
		else if(LechLineTrai == -2 && LechLinePhai == -3)	robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -2 && LechLinePhai == -2)	robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -2 && LechLinePhai == -1)	robotRunAngle(900, Speed,goc_lech, 0.1);
		
		else if(LechLineTrai == -1 && LechLinePhai == -3)	robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -1 && LechLinePhai == -2)	robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -1 && LechLinePhai == -1)	robotRunAngle(900, Speed,goc_lech, 0.1);
		
		else if(LechLineTrai == 0 && LechLinePhai == -3)	robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == -2)	robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == -1)	robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == 1)		robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == 2)		robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == 3)		robotRunAngle(900, Speed,goc_lech, 0.1);
		
		else if(LechLineTrai == 0 && LechLinePhai == 0)		robotRunAngle(900, Speed, goc_lech, 0.1);
		
		else if(LechLineTrai == -3 && LechLinePhai == 0)	robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -2 && LechLinePhai == 0)	robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -1 && LechLinePhai == 0)	robotRunAngle(900, Speed,goc_lech, 0.1);		
		else if(LechLineTrai == 1 && LechLinePhai == 0)		robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 2 && LechLinePhai == 0)		robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 3 && LechLinePhai == 0)		robotRunAngle(900, Speed, goc_lech, 0.1);
		
		else if(LechLineTrai == 1 && LechLinePhai == 1)		robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 1 && LechLinePhai == 2)		robotRunAngle(900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 1 && LechLinePhai == 3)		robotRunAngle(900, Speed,goc_lech, 0.1);
		
		else if(LechLineTrai == 2 && LechLinePhai == 1)		robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 2 && LechLinePhai == 2)		robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 2 && LechLinePhai == 3)		robotRunAngle(900, Speed,goc_lech, 0.1);
		
		else if(LechLineTrai == 3 && LechLinePhai == 1)		robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 3 && LechLinePhai == 2)		robotRunAngle(900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 3 && LechLinePhai == 3)		robotRunAngle(900, Speed, goc_lech, 0.1);
		
		else robotRunAngle(900, Speed, goc_lech, 0.1);
	// }	
	// robotStop(0);
}
//------------------------------------------------------------//
void SangPhai_DoLine(int En, int Speed){
	// RESET_ENCODER();	
	// robotSetACC(20,100);
		
	// while(ENCODER_TONG()< En){
		if		 (LechLineTrai == -3 && LechLinePhai == -3)	robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == -3 && LechLinePhai == -2)	robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == -3 && LechLinePhai == -1)	robotRunAngle(-900, Speed, goc_lech, 0.1);
		
		else if(LechLineTrai == -2 && LechLinePhai == -3)	robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == -2 && LechLinePhai == -2)	robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == -2 && LechLinePhai == -1)	robotRunAngle(-900, Speed, goc_lech, 0.1);
		
		else if(LechLineTrai == -1 && LechLinePhai == -3)	robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == -1 && LechLinePhai == -2)	robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == -1 && LechLinePhai == -1)	robotRunAngle(-900, Speed, goc_lech,0.1);
		
		else if(LechLineTrai == 0 && LechLinePhai == -3)	robotRunAngle(-900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == -2)	robotRunAngle(-900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == -1)	robotRunAngle(-900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == 1)		robotRunAngle(-900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == 2)		robotRunAngle(-900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 0 && LechLinePhai == 3)		robotRunAngle(-900, Speed,goc_lech, 0.1);
		
		else if(LechLineTrai == 0 && LechLinePhai == 0)		robotRunAngle(-900, Speed,goc_lech, 0.1);
		
		else if(LechLineTrai == -3 && LechLinePhai == 0)	robotRunAngle(-900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -2 && LechLinePhai == 0)	robotRunAngle(-900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == -1 && LechLinePhai == 0)	robotRunAngle(-900, Speed,goc_lech, 0.1);		
		else if(LechLineTrai == 1 && LechLinePhai == 0)		robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 2 && LechLinePhai == 0)		robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 3 && LechLinePhai == 0)		robotRunAngle(-900, Speed, goc_lech, 0.1);
		
		else if(LechLineTrai == 1 && LechLinePhai == 1)		robotRunAngle(-900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 1 && LechLinePhai == 2)		robotRunAngle(-900, Speed,goc_lech, 0.1);
		else if(LechLineTrai == 1 && LechLinePhai == 3)		robotRunAngle(-900, Speed,goc_lech, 0.1);
		
		else if(LechLineTrai == 2 && LechLinePhai == 1)		robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 2 && LechLinePhai == 2)		robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 2 && LechLinePhai == 3)		robotRunAngle(-900, Speed, goc_lech, 0.1);
		
		else if(LechLineTrai == 3 && LechLinePhai == 1)		robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 3 && LechLinePhai == 2)		robotRunAngle(-900, Speed, goc_lech, 0.1);
		else if(LechLineTrai == 3 && LechLinePhai == 3)		robotRunAngle(-900, Speed, goc_lech, 0.1);
		
		else robotRunAngle(-900, Speed, 0, 1);
	// }	
	// robotStop(0);
}
//------------------------------------------------------------//
void DiLen(int En, int Speed){
	RESET_ENCODER();	
	robotSetACC(20,100);
	
	robotRunAngle(1800, Speed, 0, 1);
	while(ENCODER_TONG()< En){if(wantExit()) break; vTaskDelay(2);}		
	robotStop(0);
}
//------------------------------------------------------------//
void DiXuong(int En, int Speed){
	RESET_ENCODER();	
	robotSetACC(20,100);
	
	robotRunAngle(0, Speed, 0, 1);
	while(ENCODER_TONG()< En){if(wantExit()) break; vTaskDelay(2);}		
	robotStop(0);
}

//--------------------------- TEST CO CAU ------------------------------------------



//--------------------------------------------------------------------------------
void robotGamePadControl(void) {
    int tocdo = 20, toc_do_xoay_free = 0;
		float	tocdoXoay = 0;
    int rJoy_LR  = (RJOY_LR >= 5 && RJOY_LR <= 250)? 1 : 0; 
    int lJoy_LR  = (LJOY_LR >= 5 && LJOY_LR <= 250)? 1 : 0;

    if(UP && DOWN && RIGHT && LEFT && rJoy_LR && lJoy_LR && O){ // Khong dieu khien			
        robotStop(0); //truot banh
        return;
    }                
/*_____________________________//___________________________*/

/********************** TOC DO ****************************/
/*_____________________________//___________________________*/
     if(!L1) tocdo = 50, tocdoXoay = 0.2, toc_do_xoay_free = 15;
		 else tocdo = 30, tocdoXoay = 0.05, toc_do_xoay_free = 7;
    
    //--------- chay cac huong -----------
    if		(!UP && DOWN && RIGHT && LEFT)   	robotRun(1800, tocdo);
    else if(UP && !DOWN && RIGHT && LEFT)   robotRun(0, tocdo);
    else if(UP && DOWN && !RIGHT && LEFT)   robotRun(-900, tocdo);
		else if(UP && DOWN && RIGHT && !LEFT)   robotRun(900, tocdo);
    
    else if(!UP && DOWN && !RIGHT && LEFT)  robotRun(-450,tocdo);
    else if(!UP && DOWN && RIGHT && !LEFT)  robotRun(450,tocdo);
    else if(UP && !DOWN && !RIGHT && LEFT)  robotRun(-1350,tocdo);
    else if(UP && !DOWN && RIGHT && !LEFT)  robotRun(1350,tocdo);
		
    //-------------- Dang chay va Khong chay nua, chi xoay ----------------
    if(UP && DOWN && RIGHT && LEFT && !rJoy_LR && lJoy_LR  && robotIsRun()) robotStop(5);
		
    //-------------- Xoay ----------------
    if(rJoy_LR) robotRotateStop();
    else if((RJOY_LR < 5) && L2){
        if(robotIsRun()) robotRotateFree(-1.5,0);
        //else robotRotateFree(-tocdoXoay,0);
				else {bit_khoa_ham_chay_thay_tuan = 1;setMotor(-toc_do_xoay_free,toc_do_xoay_free,-toc_do_xoay_free,toc_do_xoay_free);}
    }
    else if((RJOY_LR > 250) && L2){
        if(robotIsRun()) robotRotateFree(1.5,0);
        //else robotRotateFree(tocdoXoay,0);
				else {bit_khoa_ham_chay_thay_tuan = 1;setMotor(toc_do_xoay_free,-toc_do_xoay_free,toc_do_xoay_free,-toc_do_xoay_free);}
    }
    else setMotor(2,2,2,2);bit_khoa_ham_chay_thay_tuan = 0,robotRotateStop();
	}

//-------------------------------------------------------------	
void ADCValue_Control(void){
	static unsigned int LaserSauCouter=0, LaserSau_SUM=0, LaserPhaiCouter=0, LaserPhai_SUM=0, LaserTraiCouter=0, LaserTrai_SUM =0, BT_MamXoay_Couter =0;// BT_MamXoay_SUM =0;
	static vu32 BT_MamXoay_SUM =0;
	//------------------------	
	if(LaserTraiCouter++ < 50)	LaserTrai_SUM += CB_Laser_Trai;  
	else {
		LaserTraiValue = LaserTrai_SUM/50;
		LaserTraiCouter = 0;
		LaserTrai_SUM = 0;
	}
//------------------------
	if(LaserPhaiCouter++ < 50)	LaserPhai_SUM += CB_Laser_Phai;  
	else {
		LaserPhaiValue = LaserPhai_SUM/50;
		LaserPhaiCouter = 0;
		LaserPhai_SUM = 0;
	}
//------------------------
	if(LaserSauCouter++ < 50)	LaserSau_SUM += CB_Laser_Sau;  
	else {
		LaserSauValue = LaserSau_SUM/50;
		LaserSauCouter = 0;
		LaserSau_SUM = 0;
	}
//-------------------------	
	if(BT_MamXoay_Couter++ < 50)	BT_MamXoay_SUM += BT_MamXoay;
	else{
		BT_MamXoay_value = BT_MamXoay_SUM/50;
		BT_MamXoay_Couter = 0;
		BT_MamXoay_SUM = 0;
	}
}

//--------------------------- TEST CYLINDER -----------------------------------------
void test_cylinder(void) {
////***********************************************************************************	
	if(!R1 && !TRIANGLE) 
		{	bien_xl_tay_lay_lua_tren = ~bien_xl_tay_lay_lua_tren; 
		while(!R1 && !TRIANGLE)  vTaskDelay(1);									
	}
	if(bien_xl_tay_lay_lua_tren == 0)						XI_LANH_TAY_LAY_LUA_TREN_OFF;
	else															 					XI_LANH_TAY_LAY_LUA_TREN_ON;
//***********************************************************************************
	if(!R1 && !X) 
		{	bien_xl_tay_lay_lua_duoi = ~bien_xl_tay_lay_lua_duoi;
		while(!R1 && !X)  vTaskDelay(1);									
	}
	if(bien_xl_tay_lay_lua_duoi == 0)						XI_LANH_TAY_LAY_LUA_DUOI_OFF;
	else																				XI_LANH_TAY_LAY_LUA_DUOI_ON;	
//***********************************************************************************
	if(!R1 && !O) 
		{	bien_xl_vuon_tay_lay_lua = ~bien_xl_vuon_tay_lay_lua;
		while(!R1 && !O)  vTaskDelay(1);									
	}
	if(bien_xl_vuon_tay_lay_lua == 0)						XI_LANH_VUON_TAY_LAY_LUA_OFF;
	else																				XI_LANH_VUON_TAY_LAY_LUA_ON;	
//***********************************************************************************
	if(!R1 && !SQUARE) 
		{	bien_xl_lay_thoc = ~bien_xl_lay_thoc;
		while(!R1 && !SQUARE)  vTaskDelay(1);									
	}
	if(bien_xl_lay_thoc == 0)										XI_LANH_LAY_THOC_OFF;
	else																				XI_LANH_LAY_THOC_ON;
//***********************************************************************************
	if(!L1 && !SQUARE) 
		{	bien_xl_ban_thoc = ~bien_xl_ban_thoc;
		while(!L1 && !SQUARE)  vTaskDelay(1);									
	}
	if(bien_xl_ban_thoc == 0)										XI_LANH_BAN_THOC_OFF;
	else																				XI_LANH_BAN_THOC_ON;
//***********************************************************************************
	if(!L1 && !O) 
		{	bien_xl_nang_lay_lua = ~bien_xl_nang_lay_lua;
		while(!L1 && !O)  vTaskDelay(1);									
	}
	if(bien_xl_nang_lay_lua == 0)								XI_LANH_NANG_LAY_LUA_OFF;
	else																				XI_LANH_NANG_LAY_LUA_ON;
//***********************************************************************************
	if(!L1 && !X) 
		{	bien_xl_ha_lay_lua = ~bien_xl_ha_lay_lua;
		while(!L1 && !X)  vTaskDelay(1);									
	}
	if(bien_xl_ha_lay_lua == 0)									XI_LANH_HA_LAY_LUA_OFF;
	else																				XI_LANH_HA_LAY_LUA_ON;
}

//--------------------------- DIEU KHIEN CO CAU ---------------------------------------
void dieuKhienCoCau(void) {
//	test_cylinder();
	
}
