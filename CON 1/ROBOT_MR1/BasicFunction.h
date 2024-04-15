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

void chay_thang_line()
{
	while(robotIsRun() == 0)			//robot dang chay
	{
		while(CB_Line_P2 != 0 && CB_Line_P3 != 0 && CB_Line_T2 != 0 && CB_Line_T3 != 0)
		{
			robotRunAngle(900, 20, 0, 0.5);
			
		}
	}
}