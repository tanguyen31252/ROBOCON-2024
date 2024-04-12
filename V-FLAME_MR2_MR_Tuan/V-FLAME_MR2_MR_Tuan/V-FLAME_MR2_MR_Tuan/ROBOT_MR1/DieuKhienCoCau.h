//*****************************8 bien toan cuc *************************************
char 	Khoang_cach_1_vong = 16, bien_xl_nang_ha, bien_xl_mac_vong, bien_xl_chot, bien_xl_kep_vong, bien_xl_day,bien_xl_tru_giua,bien_xl_keo_loxo;
char	vi_tri = 0, Cbcc = 0, Cbnv = 0,Cbnn = 0, Resetnangvong = 0;

int  Nang_vong_max = 322, Nang_vong_min = 105, i; 
int  Nang_goc_max = 540, Nang_goc_min = 300;


int en_tru = 60;
int max_speed = 20;
int speed_temp = 0;
int speed_mam = 250;

int speed_trucX = 250;
int speed_trucY = 70;
int speed_tay_lua = 250;

void robotGamePadControl(void)
{
	
    int tocdo = 20,td_x = 7;
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
     if(!L1) tocdo = 35, tocdoXoay = 0.4;
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
        if(robotIsRun()) robotRotateFree(-0.5,0);
        else robotRotateFree(-tocdoXoay,0);
    }
    else if((RJOY_LR > 250) && L2)
    {
        if(robotIsRun()) robotRotateFree(0.5,0);
        else robotRotateFree(tocdoXoay,0);
    }

    else robotRotateStop();
	}
//////-------------------------------------------------------------	
	void ADCValue_Control(void)
{
	//KHAI BAO LAZER
	static unsigned int lazeTruocCouter = 0, lazeTruoc_SUM = 0;
	static unsigned int lazePhaiCouter = 0, lazePhai_SUM = 0;
	static unsigned int lazeTraiCouter = 0, lazeTrai_SUM = 0;
	
	//KHAI BAO BIEN TRO
	
	static unsigned int BientroTrucXCouter = 0,BientroTrucX_SUM = 0; 
	static unsigned int BientroTrucYCouter = 0,BientroTrucY_SUM = 0; 
	static unsigned int BientroMamXoayCouter= 0,BientroMamXoay_SUM = 0;
////------------------------	
	if(lazeTruocCouter++ < 50)	
	{
		lazeTruoc_SUM += cam_bien_laze_truoc;  
	}
	else
  {
		lazeTruocValue = lazeTruoc_SUM/50;
		lazeTruocCouter = 0;
		lazeTruoc_SUM = 0;}
	
	if(lazePhaiCouter++ < 50)	
	{
		lazePhai_SUM += cam_bien_laze_phai;  
	}
	else
  {
		lazePhaiValue = lazePhai_SUM/50;
		lazePhaiCouter = 0;
		lazePhai_SUM = 0;}
	
	if(lazeTraiCouter++ < 50)	
	{
		lazeTrai_SUM += cam_bien_laze_trai;  
	}
	else
  {
		lazeTraiValue = lazeTrai_SUM/50;
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

//-----------------------Giu tay------------------------------------
void giu_Mam_Xoay(){
	if(BienTroMamXoayValue < Min_BT_mam_xoay - 5 || BienTroMamXoayValue > Max_BT_mam_xoay + 5)  {Mor_Mam = 2; return;}
	if(abs(BienTroMamXoayValue - taget_BT_mam_xoay) > 3){
		if(BienTroMamXoayValue > taget_BT_mam_xoay) Mor_Mam_thuan;
		else Mor_Mam_nghich;
		
		speed_temp = abs(BienTroMamXoayValue - taget_BT_mam_xoay);
		
		if(speed_temp > 250) speed_temp = 250;
		if(speed_temp < 50) speed_temp = 50;
	  Mor_Mam = speed_temp;
	}
	else Mor_Mam = 2;
}



void giu_TrucX(){
	
	if(BienTroTrucXValue < Min_BT_trucX - 10  || BienTroTrucXValue > Max_BT_trucX + 10 )  {Mor_TrucX = 0; return;}
	
	if(abs(BienTroTrucXValue - taget_BT_trucX) > 3){
		
		if(BienTroTrucXValue > taget_BT_trucX) Mor_TrucX_thuan;
		else Mor_TrucX_nghich;
		
		speed_trucX = abs(BienTroTrucXValue - taget_BT_trucX);
		
		if(speed_trucX > 250) speed_trucX = 250;
		if(speed_trucX < 200) speed_trucX = 200;
	  Mor_TrucX = speed_trucX;
	}
	else Mor_TrucX = 0;
}

void giu_TrucY(){
	if(BienTroTrucYValue < Min_BT_trucY-5 || BienTroTrucYValue > Max_BT_trucY+5)  {Mor_TrucY = 2; return;}
	
	if(fabs(BienTroTrucYValue - taget_BT_trucY) > 3){
		
		if(BienTroTrucYValue > taget_BT_trucY) Mor_TrucY_thuan;
		else Mor_TrucY_nghich;
		
		if(speed_trucY > 150) speed_trucY = 150;
		if(speed_trucY < 50) speed_trucY = 50;
	  Mor_TrucY = speed_trucY;
	}
	else Mor_TrucY = 2;
}

//-----------------------Bam thanh san xanh---------------------------
void bam_Thanh_Lazer_Truoc_SAN_XANH(int speed,int angle_fix,int AngleHead,int lazer_stable_truoc,int num_change_stable){
		if(lazeTruocValue - lazer_stable_truoc > num_change_stable){
			robotRunAngle(900 + angle_fix,speed,AngleHead,0.1);
		}
		else if(lazeTruocValue - lazer_stable_truoc < num_change_stable){
			robotRunAngle(900 - angle_fix,speed,AngleHead,0.1);
		}
		else robotRunAngle(900,speed,AngleHead,0.1);
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

//-----------------------------Bam thanh san do--------------------------------
void bam_Thanh_Lazer_Truoc_SAN_DO(int speed,int angle_fix,int AngleHead,int lazer_stable_truoc,int num_change_stable){
		if(lazeTruocValue - lazer_stable_truoc > num_change_stable){
			robotRunAngle(-900 - angle_fix,speed,AngleHead,0.1);
		}
		else if(lazeTruocValue - lazer_stable_truoc < num_change_stable){
			robotRunAngle(-900 + angle_fix,speed,AngleHead,0.1);
		}
		else robotRunAngle(-900,speed,AngleHead,0.1);
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

// chay san
void chay_san_Lazer_Phai(int speed,int angle_fix,int AngleHead,int lazer_stable_truoc,int num_change_stable){
		if(lazePhaiValue - lazer_stable_truoc > num_change_stable){
			robotRunAngle(-900 + angle_fix,speed,AngleHead,0.1);
		}
		else if(lazePhaiValue - lazer_stable_truoc < num_change_stable){
			robotRunAngle(-900 - angle_fix,speed,AngleHead,0.1);
		}
		else robotRunAngle(-900,speed,AngleHead,0.1);
}


void test_truc_XYZ(void){
	if(!NUT_RESET)
	{
		
	taget_BT_mam_xoay = Min_BT_mam_xoay;
	}
}

