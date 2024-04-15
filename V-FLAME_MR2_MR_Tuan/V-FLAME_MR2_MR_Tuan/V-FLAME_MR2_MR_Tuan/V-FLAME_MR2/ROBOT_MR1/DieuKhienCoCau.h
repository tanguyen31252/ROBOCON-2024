//*****************************8 bien toan cuc *************************************
char 	bien_xi_lanh_nang,bien_xi_lanh_kep,Khoang_cach_1_vong = 16, bien_xl_nang_ha, bien_xl_mac_vong, bien_xl_chot, bien_xl_kep_vong, bien_xl_day,bien_xl_tru_giua,bien_xl_keo_loxo;
char	vi_tri = 0, Cbcc = 0, Cbnv = 0,Cbnn = 0, Resetnangvong = 0;

int max_speed = 50;
int speed_temp = 0;
int en_tru = 60;
int RoboMode = 0;

void GAP_BONG(void);

// Hieu's copyright
void Quay_Mam(bool chieu, int speed);
void Di_Chuyen_Truc_X(bool chieu, int speed);

void Bam_thanh_laser_phai(int speed,int AngleHead,int lazer_stable_phai,int num_change_stable){
	int fix;
	
	fix = abs(lazePhaiValue - lazer_stable_phai)*15;
	
	if(fix > 650)	fix = 650;
	
		if(lazePhaiValue - lazer_stable_phai > num_change_stable){
			robotRunAngle(0 - fix,speed,AngleHead,0.1);
		}
		else if(lazePhaiValue - lazer_stable_phai < num_change_stable){
			robotRunAngle(0 + fix,speed,AngleHead,0.1);
		}
		else robotRunAngle(0,speed,AngleHead,0.1);
}
void Bam_thanh_laser_phai_lui(int speed,int AngleHead,int lazer_stable_phai,int num_change_stable){
	int fix;
	fix = abs(lazePhaiValue - lazer_stable_phai)*15;
	
	if(fix > 500)	fix = 500;
	
		if(lazePhaiValue - lazer_stable_phai > num_change_stable){
			robotRunAngle(-1800 + fix,speed,AngleHead,0.1);
		}
		else if(lazePhaiValue - lazer_stable_phai < num_change_stable){
			robotRunAngle(1800 - fix,speed,AngleHead,0.1);
		}
		else robotRunAngle(1800,speed,AngleHead,0.1);
}

void Bam_thanh_laser_trai(int speed,int AngleHead,int lazer_stable_trai,int num_change_stable){
	int fix;
	
	fix = abs(lazeTraiValue - lazer_stable_trai)*15;
	
	if(fix > 500)	fix = 500;
	
	if(lazeTraiValue - lazer_stable_trai > num_change_stable){
		robotRunAngle(0 + fix,speed,AngleHead,0.2);
	}
	else if(lazeTraiValue - lazer_stable_trai < num_change_stable){
		robotRunAngle(0 - fix,speed,AngleHead,0.2);
	}
	else robotRunAngle(0,speed,AngleHead,0.2);
}

void Bam_thanh_laser_trai_lui(int speed,int AngleHead,int lazer_stable_trai,int num_change_stable){
	int fix;
	
	fix = abs(lazeTraiValue - lazer_stable_trai)*15;
	
	if(fix > 500)	fix = 500;
	
		if(lazeTraiValue - lazer_stable_trai > num_change_stable){
			robotRunAngle(1800 - fix,speed,AngleHead,0.2);
		}
		else if(lazeTraiValue - lazer_stable_trai < num_change_stable){
			robotRunAngle(-1800 + fix,speed,AngleHead,0.2);
		}
		else robotRunAngle(1800,speed,AngleHead,0.2);
}

// Hieu's copyright

void robotGamePadControl(void)
{
	
    int tocdo = 50,td_x = 30;
		float	tocdoXoay = 0;
    int rJoy_LR  = (RJOY_LR >= 5 && RJOY_LR <= 250)? 1 : 0; 
    int lJoy_LR  = (LJOY_LR >= 5 && LJOY_LR <= 250)? 1 : 0;

    if(UP && DOWN && RIGHT && LEFT && rJoy_LR && lJoy_LR && O)
		{ // Khong dieu khien
        robotStop(0); //truot banh
				
        return;
    }                
/*_____________________________//___________________________*/

/********************** TOC DO ****************************/
/*_____________________________//___________________________*/
     if(!L1) tocdo = 35, tocdoXoay = 0.3;
		 else tocdo = 10, tocdoXoay = 0.2;
    
    //--------- chay cac huong -----------
    if		(!UP && DOWN && RIGHT && LEFT && L2)   	robotRun(0, tocdo);
    else if(UP && !DOWN && RIGHT && LEFT && L2)   robotRun(1800, tocdo);
    else if(UP && DOWN && !RIGHT && LEFT && L2)   robotRun(900, tocdo);
    else if(UP && DOWN && RIGHT && !LEFT && L2)   robotRun(-900, tocdo);
    
    else if(!UP && DOWN && !RIGHT && LEFT && L2)  robotRun(450,tocdo);
    else if(!UP && DOWN && RIGHT && !LEFT && L2)  robotRun(-450,tocdo);
    else if(UP && !DOWN && !RIGHT && LEFT && L2)  	robotRun(1350,tocdo);
    else if(UP && !DOWN && RIGHT && !LEFT && L2)  robotRun(-1350,tocdo);
	
    //-------------- Dang chay va Khong chay nua, chi xoay ----------------
    if(UP && DOWN && RIGHT && LEFT && !rJoy_LR && lJoy_LR  && robotIsRun()) robotStop(0);   

    //-------------- Xoay ----------------
    if(rJoy_LR) robotRotateStop();
    else if((RJOY_LR < 5) && L2)
    {
        if(robotIsRun()) robotRotateFree(-0.3,0);
        else robotRotateFree(-tocdoXoay,0);
    }
    else if((RJOY_LR > 250) && L2)
    {
        if(robotIsRun()) robotRotateFree(0.3,0);
        else robotRotateFree(tocdoXoay,0);
    }

    else robotRotateStop();
	}
//////-------------------------------------------------------------	
	void ADCValue_Control(void)
{
	//KHAI BAO LAZER
	static unsigned int lazeTruocCouter = 0, lazeTruoc_SUM = 0;
	static unsigned int lazeSauCouter = 0, lazeSau_SUM = 0;
	static unsigned int lazePhaiCouter = 0, lazePhai_SUM = 0;
	static unsigned int lazeTraiCouter = 0, lazeTrai_SUM = 0;
	
	
	//KHAI BAO BIEN TRO
	
	static unsigned int BientroTrucXCouter = 0,BientroTrucX_SUM = 0; 
	static unsigned int BientroTrucYCouter = 0,BientroTrucY_SUM = 0; 
	static unsigned int BientroMamXoayCouter= 0,BientroMamXoay_SUM = 0;
////------------------------	
	if(lazeTruocCouter++ < 100)	
	{
		lazeTruoc_SUM += cam_bien_laze_truoc;  
	}
	else
	{
		lazeTruocValue = lazeTruoc_SUM/100;
		lazeTruocCouter = 0;
		lazeTruoc_SUM = 0;}
	
	if(lazeSauCouter++ < 100)	
	{
		lazeSau_SUM += cam_bien_laze_sau;  
	}
	else
  {
		lazeSauValue = lazeSau_SUM/100;
		lazeSauCouter = 0;
		lazeSau_SUM = 0;}
//	 
	
	if(lazePhaiCouter++ < 50)	
	{
		lazePhai_SUM += cam_bien_laze_phai;  
	}
	else
  {
		lazePhaiValue = lazePhai_SUM/100;
		lazePhaiCouter = 0;
		lazePhai_SUM = 0;}
	
	if(lazeTraiCouter++ < 100)	
	{
		lazeTrai_SUM += cam_bien_laze_trai;  
	}
	else
  {
		lazeTraiValue = lazeTrai_SUM/100;
		lazeTraiCouter = 0;
		lazeTrai_SUM = 0;
	}
	
	// BIEN TRO
	if(BientroTrucXCouter++ < 50)	
	{
		BientroTrucX_SUM += bien_tro_nang_trucX;
	}
	else
  {
		BienTroTrucXValue = BientroTrucX_SUM/50;
		BientroTrucXCouter = 0;
		BientroTrucX_SUM = 0;
	}
	
	if(BientroTrucYCouter++ < 50)	
	{
		BientroTrucY_SUM += bien_tro_nang_trucY;
	}
	else
  {
		BienTroTrucYValue = BientroTrucY_SUM/50;
		BientroTrucYCouter = 0;
		BientroTrucY_SUM = 0;
	}
	
	if(BientroMamXoayCouter++ < 50)	
	{
		BientroMamXoay_SUM += bien_tro_xoay_mam;
	}
	else
  {
		BienTroMamXoayValue = BientroMamXoay_SUM/50;
		BientroMamXoayCouter = 0;
		BientroMamXoay_SUM = 0;
	}
}
//void test_truc_XY (void)
//{
//	if(!TRIANGLE) 			Mor_TrucY = 50, Mor_TrucY_len;
//	else if(!X)					Mor_TrucY = 50, Mor_TrucY_xuong;
//	else if(!SQUARE)		Mor_Mam = 250, Mor_Mam_thuan;
//	else if(!O)					Mor_Mam = 250, Mor_Mam_nghich;
//	
//	else 								Mor_TrucY = 0,
//											Mor_Mam=0;
//	
//}

void Cho_Mam_Xoay()
{
	while(abs(BienTroMamXoayValue - BT_Xoay_Gap_Bong) > 10) vTaskDelay(100);
}


void bam_Thanh_Lazer_Trai_0do(int speed,int angle_fix,int AngleHead,int lazer_stable_truoc,int num_change_stable){
		if(lazeTraiValue - lazer_stable_truoc > num_change_stable){
			robotRunAngle(0 + angle_fix,speed,AngleHead,0.3);
		}
		else if(lazeTraiValue - lazer_stable_truoc < num_change_stable){
			robotRunAngle(0 - angle_fix,speed,AngleHead,0.3);
		}
		else robotRunAngle(0,speed,AngleHead,0.1);
}

void bam_Thanh_Lazer_Trai_SAN_XANH(int speed,int angle_fix,int AngleHead,int lazer_stable_truoc,int num_change_stable){
		if(lazeTraiValue - lazer_stable_truoc > num_change_stable){
			robotRunAngle(600 - angle_fix,speed,AngleHead,0.1);
		}
		else if(lazeTraiValue - lazer_stable_truoc < num_change_stable){
			robotRunAngle(600 + angle_fix,speed,AngleHead,0.1);
		}
		else robotRunAngle(600,speed,AngleHead,0.1);
}

void bam_Thanh_Lazer_Trai(int speed,int angle_fix,int AngleHead,int lazer_stable_truoc,int num_change_stable){
		if(lazeTraiValue - lazer_stable_truoc > num_change_stable){
			robotRunAngle(0 + angle_fix,speed,AngleHead,0.1);
		}
		else if(lazeTraiValue - lazer_stable_truoc < num_change_stable){
			robotRunAngle(0 - angle_fix,speed,AngleHead,0.1);
		}
		else robotRunAngle(0,speed,AngleHead,0.1);
}


void bam_Thanh_Lazer_Phai(int speed,int angle_fix,int AngleHead,int lazer_stable_truoc,int num_change_stable){
		if(lazePhaiValue - lazer_stable_truoc > num_change_stable){
			robotRunAngle(0 + angle_fix,speed,AngleHead,0.1);
		}
		else if(lazePhaiValue - lazer_stable_truoc < num_change_stable){
			robotRunAngle(0 - angle_fix,speed,AngleHead,0.1);
		}
		else robotRunAngle(0,speed,AngleHead,0.1);
}


void test_cylinder(void) {
//***********************************************************************************	
	if(!NUT_3 == 0) 
		{	bien_xi_lanh_nang = ~bien_xi_lanh_nang; 
		while(!NUT_3)  vTaskDelay(1);									
	}
	if(bien_xi_lanh_nang == 0)							XI_LANH_NANG_BONG_ON;
	else																	XI_LANH_NANG_BONG_OFF;
}


void giu_Mam_Xoay(){
	if(BienTroMamXoayValue < Min_BT_Xoay - 7 || BienTroMamXoayValue > Max_BT_Xoay + 7)  {Mor_Mam = 0; return;}
	if(abs(BienTroMamXoayValue - taget_BT_Xoay) > 5){
		if(BienTroMamXoayValue > taget_BT_Xoay) Mor_Mam_nghich ; 
		else Mor_Mam_thuan;
		
		speed_temp = abs(BienTroMamXoayValue - taget_BT_Xoay)*5;
		if(speed_temp > 250) speed_temp = 250;
		if(speed_temp < 50) speed_temp = 50;
	  Mor_Mam = speed_temp;
	}
	else Mor_Mam = 0;
}
void Quay_mam(void)
{
	if((!SQUARE ) && (taget_BT_Xoay < Max_BT_Xoay))						taget_BT_Xoay ++, vTaskDelay(200);
	else	if((!O ) && (taget_BT_Xoay > Min_BT_Xoay))						taget_BT_Xoay --, vTaskDelay(200);
}

// Hieu's copyright
void Di_Chuyen_Truc_X(bool chieu, int speed)
{
	if(chieu && (taget_BT_Truc_X < Max_BT_Truc_X))						taget_BT_Truc_X ++, vTaskDelay(speed);
	else	if(taget_BT_Truc_X > Min_BT_Truc_X)				taget_BT_Truc_X --, vTaskDelay(speed);
}

void Quay_Mam(bool chieu, int speed)
{
	if((chieu ) && (taget_BT_Xoay < Max_BT_Xoay))						taget_BT_Xoay ++, vTaskDelay(speed);
	else	if(taget_BT_Xoay > Min_BT_Xoay)				taget_BT_Xoay --, vTaskDelay(speed);
}

// Hieu's copyright

//******************************* dieu khien truc Y **************************************************************
void Giu_Truc_Y(){
	if(BienTroTrucYValue < Min_BT_Truc_Y - 7 || BienTroTrucYValue > Max_BT_Truc_Y + 7)  {Mor_TrucY = 2; return;}
	if(abs(BienTroTrucYValue - taget_BT_Truc_Y) > 4){
		if(BienTroTrucYValue > taget_BT_Truc_Y) Mor_TrucY_xuong;
		else Mor_TrucY_len;
		
		speed_temp = abs(BienTroTrucYValue - taget_BT_Truc_Y)*5;
		
		if(speed_temp > 250) speed_temp = 250;
		if(speed_temp < 50) speed_temp = 20;
	  Mor_TrucY = speed_temp;
	}
	else Mor_TrucY = 2;
}

void Nang_ha_Y(void)
{
	if((LJOY_UD > 250) && (taget_BT_Truc_Y > Min_BT_Truc_Y))						taget_BT_Truc_Y --, vTaskDelay(200);
	else	if((LJOY_UD < 5) && (taget_BT_Truc_Y < Max_BT_Truc_Y))				taget_BT_Truc_Y ++, vTaskDelay(200);
}

//******************************* dieu khien truc X **************************************************************
void Giu_Truc_X(void){
	if(BienTroTrucXValue < Min_BT_Truc_X - 7 || BienTroTrucXValue > Max_BT_Truc_X +7)  {Mor_TrucX = 0; return;}
	if(abs(BienTroTrucXValue - taget_BT_Truc_X) > 3){
		if(BienTroTrucXValue > taget_BT_Truc_X) Mor_TrucX_vao;
		else Mor_TrucX_ra;
		speed_temp = (int)abs(BienTroTrucXValue - taget_BT_Truc_X)*20;
		if(speed_temp > 250) speed_temp = 250;
		if(speed_temp < 20) speed_temp = 15;
	  Mor_TrucX = speed_temp;
	}
	else Mor_TrucX = 0;
}

void Ra_vao_X(void)
{
	if((LJOY_LR > 250) && (taget_BT_Truc_X < Max_BT_Truc_X))						taget_BT_Truc_X ++, vTaskDelay(200);
	else	if((LJOY_LR < 5) && (taget_BT_Truc_X > Min_BT_Truc_X))				taget_BT_Truc_X --, vTaskDelay(200);
}

void GAP_BONG(void){
		XI_LANH_KEP_THA_BONG_OFF;
		XI_LANH_NANG_BONG_OFF;

		taget_BT_Truc_Y = Min_BT_Truc_Y;
		
		while(BienTroTrucYValue > Min_BT_Truc_Y + 10)	{
			if(	BienTroTrucYValue < Min_BT_Truc_Y +  75)		XI_LANH_KEP_THA_BONG_ON;}
		vTaskDelay(1000);

		taget_BT_Truc_Y = Max_BT_Truc_Y;
		while(BienTroTrucYValue < 800)	vTaskDelay(1);	
}
