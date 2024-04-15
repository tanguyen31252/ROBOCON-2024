//////************************ san xanh *********************************
void XUAT_PHAT_SAN_XANH(void)
{
	RESET_ENCODER();
	robotRunAngle(900,60,0,0.1);
	while(ENCODER_TONG() < 2000) vTaskDelay(1);		
	taget_BT_Xoay = BT_Xoay_Gap_Bong;	
	taget_BT_Truc_X = BT_Truc_X_Tha_Bong; 
	XI_LANH_KEP_THA_BONG_OFF;
	robotRunAngle(800,60,0,0.1);
	while(ENCODER_TONG() < 4000) vTaskDelay(1);		
	
	robotRunAngle(700,40,0,0.1);
	for(i=0;i<50;i++)	while(lazeTraiValue > 100 ) vTaskDelay(1);	
	
	RESET_ENCODER();
	for(i=0;i<50;i++) while(ENCODER_TONG() < 1200) {	Bam_thanh_laser_trai(40,0,22,5); vTaskDelay(1);};		
	
	for(i=0;i<50;i++) while(ENCODER_TONG() < 3500) {	Bam_thanh_laser_trai(50,0,17,5); vTaskDelay(1);};		
																										
	robotRunAngle(0,45,0,0.1);
	for(i=0;i<50;i++)	while(lazeTraiValue < 35 ) vTaskDelay(1);		
	
	RESET_ENCODER();

	robotRunAngle(0,30,0,0.1);
	while(ENCODER_TONG() < 600) vTaskDelay(1);		
	robotStop(0);
	
	// len doc 
	RESET_ENCODER();
	robotRunAngle(920,50,0,0.1);
	while(ENCODER_TONG() < 1800) vTaskDelay(1);		

	
	while(ENCODER_TONG() < 3500) Bam_thanh_laser_trai_lui(40,0,ViTriLazeThaBong[2],5);		

	// robotRunAngle(900,15,0,0.1);
	// while(ENCODER_TONG() < 1000 || lazeTraiValue > ViTriLazeThaBong[2]) vTaskDelay(1);
	robotStop(0);
	
	// chay cham cho den khi thay bong
	robotRunAngle(1450,10,-450,0.3);
	while((TAM_X == 0 || abs(TAM_Y - 18) > 10)) vTaskDelay(1);		

	//-----------------------------
	RESET_ENCODER();

	robotRunAngle(1800,15,0,0.1);
	while(ENCODER_TONG() < 800) vTaskDelay(1);	
	
	robotStop(0);
}


void retry_sanxanh(void)
{
//	robotRunAngle(550,30,0,0.1);
//	for(i=0;i<50;i++)	while(lazeTraiValue > 40 ) vTaskDelay(1);	

//	robotStop(0);
//	RESET_ENCODER();
	
	for(i=0;i<50;i++) while(ENCODER_TONG() < 1200) {	Bam_thanh_laser_trai(40,0,22,5); vTaskDelay(1);};		
	
	for(i=0;i<50;i++) while(ENCODER_TONG() < 5000) {	Bam_thanh_laser_trai(50,0,17,5); vTaskDelay(1);};		
	
	
	taget_BT_Xoay = BT_Xoay_Gap_Bong;
	taget_BT_Truc_X = BT_Truc_X_Tha_Bong; 
	XI_LANH_KEP_THA_BONG_OFF;
																										
	robotRunAngle(0,45,0,0.1);
	for(i=0;i<50;i++)	while(lazeTraiValue < 35 ) vTaskDelay(1);		
	
	RESET_ENCODER();

	robotRunAngle(0,30,0,0.1);
	while(ENCODER_TONG() < 600) vTaskDelay(1);		
	robotStop(0);
	
	// len doc 
	RESET_ENCODER();
	robotRunAngle(920,50,0,0.1);
	while(ENCODER_TONG() < 1800) vTaskDelay(1);		

	
	while(ENCODER_TONG() < 3500) Bam_thanh_laser_trai_lui(40,0,ViTriLazeThaBong[2],5);		

	// robotRunAngle(900,15,0,0.1);
	// while(ENCODER_TONG() < 1000 || lazeTraiValue > ViTriLazeThaBong[2]) vTaskDelay(1);
	robotStop(0);
	Cho_Mam_Xoay();
}


//---------------------------------------------------------------------------------------------
void ThaBong_Xanh()
{
	int SoFrameNhanSilo = 0;
	int SiloDaChon = 10;
	int KhoangCachNhinBong = 300;
	int HuongLaBan = 0;

	taget_BT_Xoay = BT_Xoay_Bo_Bong;
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
		while (lazePhaiValue < 180)
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
	// tim vi tri tha bong
	while (absI(lazeTraiValue - viTriThaBong) > 5)
	{
		if (viTriThaBong > lazeTraiValue)
		{
			robotRunAngle(-900, 30, 0, 0.3);
		}
		else if (viTriThaBong < lazeTraiValue)
		{
			robotRunAngle(900, 30, 0, 0.3);
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
	
	RobotMode = 10;

	Chay_Bo_Bong(viTriThaBong);
	Tha_Bong_Vao_Silo(viTriThaBong);

	robotStop(0);
}

//---------------------------------------------------------------------------------------------
//----------------------------------quay ve lay bong--------------------------------------
void Ve_gap_bong_xanh(void)
{
	int viTriLazeVeLayBong = 0;

	viTriLazeVeLayBong = ViTriLazeThaBong[2];

	RESET_ENCODER();
	while (ENCODER_TONG() < 500)
	{
		robotRunAngle(1800, 30, 0, 0.3);
	}
	// Reset vi tri tay gap, camera, ... chuan bi gap tiep
	if (lazeSauValue > 180){
		taget_BT_Xoay = BT_Xoay_Gap_Bong;
		XI_LANH_NANG_BONG_OFF;
		Servo_Cam = 1700;
	}
	// tim vi tri dung
	while (absI(lazeTraiValue - viTriLazeVeLayBong) > 10)
	{
		if (viTriLazeVeLayBong > lazeTraiValue)
		{
			robotRunAngle(-1200, 40, 0, 0.3);
		}
		else if (viTriLazeVeLayBong < lazeTraiValue)
		{
			robotRunAngle(1200, 40, 0, 0.3);
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
		robotRunAngle(1800, 30, 0, 0.3);
	}

	while (ENCODER_TONG() < 1800)
	{
		robotRunAngle(1800, 20, 0, 0.3);
	}
	robotStop(0);

	// Hieu - kiem tra vi tri mam xoay
	while (abs(BienTroMamXoayValue - taget_BT_Xoay) > 50)
	{
		vTaskDelay(10);
	}

	robotStop(0);
	vTaskDelay(3000);
}

	