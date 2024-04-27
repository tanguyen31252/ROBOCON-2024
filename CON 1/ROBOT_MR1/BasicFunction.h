//----------------------------CHAY BAM THANH BANG LAZE--------------------------
void bam_thanh_laze_ngang(float angle, int maxSpeed, float robotAngle, float rototate, float angle_fix, int laze_stable_ngang, int num_stable_change, int dung_laze_nao)
{
	if(dung_laze_nao - laze_stable_ngang > num_stable_change)
	{
		robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, rototate);
	}
	else if(dung_laze_nao - laze_stable_ngang < num_stable_change)
	{
		robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, rototate);
	}
	else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
}
////////////////////////////////////////////////////////////////////////////////
void bam_thanh_laze_truoc(float angle, int maxSpeed, float robotAngle, float angle_fix, int laze_stable_truoc, int num_stable_change)
{
	if(lazeTruocValue - laze_stable_truoc > num_stable_change)
	{
		robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, 0.2);
	}
	else if(lazeTruocValue - laze_stable_truoc < num_stable_change)
	{
		robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, 0.2);
	}
	else robotRunAngle(angle, maxSpeed, robotAngle, 0.2);
}

int T1,T2,T3,T4,P1,P2,P3,P4;
void ChangeStatus()
{
    if(CB_Line_T1 == 0)                 T1 = 0;
	else 			 					T1 = 1;
	
	if(CB_Line_T2 == 0)                 T2 = 0;
	else 			 					T2 = 1;
	
	if(CB_Line_T3 == 0)                 T3 = 0;
	else 			 					T3 = 1;
	
	if(CB_Line_T4 == 0)                 T4 = 0;
	else 			 					T4 = 1;
	
	if(CB_Line_P1 == 0)                 P1 = 0;
	else 			 					P1 = 1;
    
	if(CB_Line_P2 == 0)                 P2 = 0;
	else 			 					P2 = 1;
	
	if(CB_Line_P3 == 0)                 P3 = 0;
	else 			 					P3 = 1;
	
	if(CB_Line_P4 == 0)                 P4 = 0;
	else 			 					P4 = 1;
}

int tinh_goc_lech()
{
	goc_lech = _robotAngle - _robotIMUAngle;

	return goc_lech;
}

void xoay_thang_line()
{
	// while(1)
	// {
	// 	while((CB_Line_P2 != 0 || CB_Line_P3 != 0 && CB_Line_T2 != 0 || CB_Line_T3 != 0) && ENCODER_TONG() < 1050)
	// 	{
	// 		if()
	// 		{
	// 			robotRotateFree(0.5, 0);
	// 		}
	// 		else
	// 		{
	// 			robotRotateFree(-0.5, 0);
	// 		}
	// 	}
	// 	break;
	// }
}


void chay_thang_line()
{
	// robotRunAngle(900, 20, 0, 0.5);
	// while(robotIsRun() == 0)			//robot dang chay
	// {
	// 	while(CB_Line_P2 != 0 && CB_Line_P3 != 0 && CB_Line_T2 != 0 && CB_Line_T3 != 0)
	// 	{
	// 		while(tinh_goc_lech() != 0 && ENCODER_TONG() < 1050){}
	// 	}
	// }
	robotRunAngle(900,20,0,0);
	while(ENCODER_TONG()<1050){xoay_thang_line();}
}