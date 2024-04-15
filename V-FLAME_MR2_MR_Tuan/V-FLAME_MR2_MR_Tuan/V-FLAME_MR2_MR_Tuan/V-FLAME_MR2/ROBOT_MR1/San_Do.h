void XUAT_PHAT_SAN_DO()
{
	RESET_ENCODER();

	robotRunAngle(-900,60,0,0.1);
	while(ENCODER_TONG() < 2000) vTaskDelay(1);		
	taget_BT_Xoay = BT_Xoay_Gap_Bong;
	taget_BT_Truc_X = BT_Truc_X_Tha_Bong;
	XI_LANH_KEP_THA_BONG_OFF;	
	robotRunAngle(-800,60,0,0.1);
	while(ENCODER_TONG() < 4000) vTaskDelay(1);		
	
	robotRunAngle(-500,60,0,0.1);
	for(i=0;i<50;i++)	while(lazePhaiValue > 40 ) vTaskDelay(1);		

	robotRunAngle(-200,60,0,0.1);
	for(i=0;i<50;i++)	while(lazePhaiValue > 25 ) vTaskDelay(1);		

	RESET_ENCODER();

	robotRunAngle(0,60,0,0.1);
	while(ENCODER_TONG() < 2000) vTaskDelay(1);		

	robotRunAngle(0,45,0,0.1);
	for(i=0;i<50;i++)	while(lazePhaiValue < 35 ) vTaskDelay(1);		

	RESET_ENCODER();

	robotRunAngle(0,30,0,0.1);
	while(ENCODER_TONG() < 600) vTaskDelay(1);		

	// len doc 
	robotStop(0);
	RESET_ENCODER();

	// chay ngan
	robotRunAngle(-920,60,0,0.1);
	while(ENCODER_TONG() < 1800) vTaskDelay(1);	
	
	while(ENCODER_TONG() < 3500) Bam_thanh_laser_phai_lui(40,0,ViTriLazeThaBong[2],5);		
	
	// chay xuong kho bong
	RESET_ENCODER();

	robotRunAngle(1800,15,0,0.1);
	while(ENCODER_TONG() < 800) vTaskDelay(1);	
	
	robotStop(0);
}

void retry_sando(void){
	
	for(i=0;i<50;i++) while(ENCODER_TONG() < 1200) {	Bam_thanh_laser_phai(40,0,20,5); vTaskDelay(1);};		
	
	for(i=0;i<50;i++) while(ENCODER_TONG() < 5000) {	Bam_thanh_laser_phai(50,0,15,5); vTaskDelay(1);};		
	taget_BT_Xoay = BT_Xoay_Gap_Bong;
	taget_BT_Truc_X = BT_Truc_X_Tha_Bong; 
	XI_LANH_KEP_THA_BONG_OFF;
																										
	robotRunAngle(0,45,0,0.1);
	for(i=0;i<50;i++)	while(lazePhaiValue < 35 ) vTaskDelay(1);		

	RESET_ENCODER();

	robotRunAngle(0,30,0,0.1);
	while(ENCODER_TONG() < 600) vTaskDelay(1);		
	
	// len doc 
	robotStop(0);
	RESET_ENCODER();

	robotRunAngle(-920,60,0,0.1);
	while(ENCODER_TONG() < 2000) vTaskDelay(1);	
	
	while(ENCODER_TONG() < 3500) Bam_thanh_laser_phai_lui(40,0,ViTriLazeThaBong[2],5);		
	robotStop(0); 
	robotRunAngle(1800,10,0,0.1);
	while(ENCODER_TONG() < 3900) vTaskDelay(1);
	vTaskDelay(1);
	Cho_Mam_Xoay();
}

//----------------------------------------------------------------------

void ThaBong_Do()
{
	int SoFrameNhanSilo = 0;
	int SiloDaChon = 10;
	int KhoangCachNhinBong = 300;
	int HuongLaBan = 0;

	taget_BT_Xoay = 175;
	taget_BT_Truc_X = BT_Truc_X_Tha_Bong;

	RESET_ENCODER();

	robotRunAngle(HuongLaBan, 60, HuongLaBan, 1.5);
	while (absI(robotAngle()) > 100)
		vTaskDelay(1);

	RESET_ENCODER();

	for (i = 0; i < 50; i++)
	{
		while (ENCODER_TONG() < 2000)
			vTaskDelay(1);
	}

	robotRunAngle(HuongLaBan, 40, HuongLaBan, 1.5);	
	for (i = 0; i < 50; i++)
	{
		while (lazeTraiValue < 350)
			vTaskDelay(1);
	}
	robotRunAngle(HuongLaBan, 10, HuongLaBan, 1.5);

	for (i = 0; i < 50; i++)
	{
		while (lazeSauValue > KhoangCachNhinBong+20)
			vTaskDelay(5);
	}
	
	robotStop(0);

	viTriThaBong = ViTriLazeThaBong[2];
	RobotMode = 2;

	Servo_Cam = 800;
	// ve vi tri giua
	while (absI(lazePhaiValue - viTriThaBong) > 5)
	{
		if (viTriThaBong > lazePhaiValue)
		{
			robotRunAngle(900, 30, 0, 0.3);
		} 
		else if (viTriThaBong < lazePhaiValue)
		{
			robotRunAngle(-900, 30, 0, 0.3);
		}
		else
		{
			robotStop(0);
		}
	}

	robotStop(0);
	robotRotate(0, 0.5, 0);
	while (robotFixAngle())
	{
		vTaskDelay(1);
	}
	robotStop(0);
	
	if( lazeSauValue > KhoangCachNhinBong){
		robotRunAngle(0, 10, 0, 1.5);
		for (i = 0; i < 50; i++)
		{
			while (lazeSauValue > KhoangCachNhinBong)
				vTaskDelay(5);
		}
	}
	
	if( lazeSauValue < KhoangCachNhinBong){
		robotRunAngle(1800, 10, 0, 1.5);
		for (i = 0; i < 50; i++)
		{
			while (lazeSauValue < KhoangCachNhinBong)
				vTaskDelay(5);
		}
	}
	
	robotStop(0);
	robotRotate(0, 0.5, 0);
	while (robotFixAngle())
	{
		vTaskDelay(1);
	}
	robotStop(0);

	for (i = 0; i < 50; i++)
	{
		while (BienTroMamXoayValue < taget_BT_Xoay - 10 && BienTroMamXoayValue > taget_BT_Xoay + 10)
		{
			vTaskDelay(10);
		}
		vTaskDelay(10);
	}

	// kiem tra gia tri silo tu raspberry pi
	while(SoFrameNhanSilo < 500)
	{
		while (SILO_THA_BONG > 4)
		{
			vTaskDelay(10);
		}
		
		if(SiloDaChon == SILO_THA_BONG) SoFrameNhanSilo += 1;
		else{
			SoFrameNhanSilo = 0;
			SiloDaChon = SILO_THA_BONG;
		}
		vTaskDelay(10);
	}

	if (SILO_THA_BONG >= 0 && SILO_THA_BONG < 5)
			viTriThaBong = ViTriLazeThaBong[SILO_THA_BONG];
	else
	{
		while (1)
			vTaskDelay(100);
	}

	robotStop(0); 
	while(1) vTaskDelay(1000);

	XI_LANH_NANG_BONG_ON;
	// ---------------- chay tha bong -------------------
	RobotMode = 10;
	Chay_Bo_Bong(viTriThaBong);
	Tha_Bong_Vao_Silo(viTriThaBong);
	robotStop(0);
}

//---------------------------------ve gap boong do-----------------------------
void Ve_gap_bong_do(void)
{
	int viTriLazeVeLayBong = 0;

	viTriLazeVeLayBong = ViTriLazeThaBong[2];

	RESET_ENCODER();
	while (ENCODER_TONG() < 500)
	{
		robotRunAngle(1800, 15, 0, 0.3); // Hieu
	}
	// Reset vi tri tay gap, camera, ... chuan bi gap tiep
	if (lazeSauValue > 180)
	{
		taget_BT_Xoay = BT_Xoay_Gap_Bong;
		XI_LANH_NANG_BONG_OFF;
		Servo_Cam = 1700;
	}

	// tim vi tri dung
	while (absI(lazePhaiValue - viTriLazeVeLayBong) > 10)
	{
		if (viTriLazeVeLayBong > lazePhaiValue)
		{
			robotRunAngle(1200, 40, 0, 0.3);
		}
		else if (viTriLazeVeLayBong < lazePhaiValue)
		{
			robotRunAngle(-1200, 40, 0, 0.3);
		}
		else
		{
			robotStop(0);
		}
	}

	robotStop(0);
	while (lazeSauValue < 333)
	{
		robotRunAngle(1800, 40, 0, 0.3);
	}

	RESET_ENCODER();
	while (ENCODER_TONG() < 1500)
	{
		robotRunAngle(1800, 40, 0, 0.3);
	}

	while (ENCODER_TONG() < 2000)
	{
		robotRunAngle(1800, 20, 0, 0.3);
	}

	// Hieu - kiem tra vi tri mam xoay
	while (abs(BienTroMamXoayValue - taget_BT_Xoay) > 50)
	{
		vTaskDelay(10);
	}

	robotStop(0);
}
