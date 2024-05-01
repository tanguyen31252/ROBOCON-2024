int ViTriLazeThaBong[5];
int khoangCach = 1000;
int viTriThaBong = 0;
int i;

void USART_SendSTRING(void)
{
	USART_SendData(USART3, 255); // bat dau gui du lieu
	vTaskDelay(10);
	//------------------------------------------
	USART_SendData(USART3, (uint16_t)MauSan);
	vTaskDelay(10);
	USART_SendData(USART3, (uint16_t)RobotMode); // 1- lay bong tai kho; 2- lay bong tu do; 5-quan sat ro bong
	vTaskDelay(10);
	USART_SendData(USART3, (uint16_t)Servo_Cam / 100);
	vTaskDelay(10);
}

//---------------------------------------------------------------
int DO_BONG()
{
	int gap = 1;
	int Y_TARGET = 18;
	int X_TARGET = 32;
	int speed = 100;

	for (i = 0; i < 5; i++)
	{
		while (abs(TAM_X - X_TARGET) > gap || abs(TAM_Y - Y_TARGET) > 1)
		{

			while (abs(TAM_X - X_TARGET) > gap)
			{
				if (TAM_X < X_TARGET + gap)
				{
					Quay_Mam(0, 200);
				}
				else if (TAM_X > X_TARGET - gap)
				{
					Quay_Mam(1, 200);
				}

				if (TAM_X == 0 && TAM_Y == 0)
					return 0;
			}

			while (abs(TAM_Y - Y_TARGET) > gap)
			{
				if (TAM_Y < Y_TARGET + gap)
				{
					Di_Chuyen_Truc_X(0, 100);
				}
				else if (TAM_Y > Y_TARGET - gap)
				{
					Di_Chuyen_Truc_X(1, 100);
				}

				if ((TAM_X == 0 && TAM_Y == 0) || taget_BT_Truc_X > 580 || taget_BT_Truc_X < 150)
					return 0;
			}
		}
		vTaskDelay(1000);
	}
	return 1;
}

//---------------------------------------------------------------------------------------------
void TimBongTuDo_OLD(int MauSan)
{
	int rA = 0;
	int tocdo = 0;
	int lantimkiem = 1;

BatDauDoBong:
	lantimkiem = 0;
	taget_BT_Xoay = BT_Xoay_Gap_Bong;
	taget_BT_Truc_X = BT_Truc_X_Tha_Bong;

	RobotMode = 10;
	Servo_Cam = 1600; // Goc nhin tong quat: 800; 			//cam nhin xuong,1700 				chay len san 3: 870									so cu:1600
	vTaskDelay(2000);
	RobotMode = 9;
	vTaskDelay(2000);

	// Tim lan thu nhat
	rA = robotAngle();
	while (lantimkiem <= 10 && TAM_X == 0 && TAM_Y == 0)
	{
		if (lantimkiem % 2 == 0)
		{
			Servo_Cam = 1100;
			RobotMode = 10;
			vTaskDelay(3000);
			RobotMode = 9;
		}
		else
		{
			Servo_Cam = 1600;
			RobotMode = 10;
			vTaskDelay(3000);
			RobotMode = 9;
		}

		lantimkiem = lantimkiem + 1;
		if (TAM_X == 0 && TAM_Y == 0)
		{
			if (MauSan == 1)
				robotRotate(rA + 800, 0.5, 0);
			else
				robotRotate(rA - 800, 0.5, 0);

			while (TAM_X == 0 && TAM_Y == 0 && robotFixAngle())
			{
				vTaskDelay(1);
			}
		}
		robotStop(0);
		if (TAM_X == 0 && TAM_Y == 0)
		{
			if (MauSan == 1)
				robotRotate(rA - 800, 0.5, 0);
			else
				robotRotate(rA + 800, 0.5, 0);

			while (TAM_X == 0 && TAM_Y == 0 && robotFixAngle())
			{
				vTaskDelay(1);
			}
		}
		robotStop(0);
		if (TAM_X == 0 && TAM_Y == 0)
		{
			robotRotate(rA, 0.5, 0);
			while (robotFixAngle())
			{
				vTaskDelay(1);
			}
			robotStop(0);
			vTaskDelay(3000);
		}
	}

	robotStop(0);
	//--------------------------------------------------------
	while (TAM_X < 27 || TAM_X > 37 && TAM_X != 255)
	{
		if (TAM_X < 32)
			robotRotateFree(-0.1, 0);
		else if (TAM_X > 32)
			robotRotateFree(0.1, 0);
		else
			robotRotateStop();

		if (TAM_X == 0 && TAM_Y == 0)
		{
			robotStop(0);
			goto BatDauDoBong;
		}
	}
	robotStop(0);
	vTaskDelay(1000);
	//------------------------------------------------------------------
	while (Servo_Cam < 1700 || (Servo_Cam == 1700 && TAM_Y < 14) && TAM_X != 255)
	{
		while (Servo_Cam < 1700 || (Servo_Cam == 1700 && TAM_Y < 16) && TAM_X != 255)
		{
			if (TAM_Y > 15 && Servo_Cam < 1700)
			{
				if (Servo_Cam >= 1000)
					Servo_Cam = Servo_Cam + 1;
				else if (Servo_Cam >= 1400)
					Servo_Cam = Servo_Cam + 5;

				vTaskDelay(20);
				if (Servo_Cam > 1600)
					Servo_Cam = 1700;
			}

			if (TAM_X > 33)
				robotRotateFree(0.2, 0);
			else if (TAM_X < 31)
				robotRotateFree(-0.2, 0);
			else
				robotRotateStop();

			if (Servo_Cam > 1500)
			{
				if (TAM_Y > 7)
					tocdo = 3;
				else
					tocdo = 7;
			}
			else
				tocdo = 15;

			if (TAM_X == 0 && TAM_Y == 0)
			{
				robotStop(0);
				goto BatDauDoBong;
			}

			robotRun(1800, tocdo);
		}
		robotStop(0);
		vTaskDelay(1000);
	}

	vTaskDelay(1000);
	while (abs(TAM_X - 32) > 2 || abs(TAM_Y - 18) > 2)
	{

		while (abs(TAM_X - 32) > 1)
		{
			if (TAM_X > 32)
				robotRotateFree(0.3, 0);
			else if (TAM_X < 32)
				robotRotateFree(-0.3, 0);
			else
				robotRotateStop();

			if (TAM_X == 0 && TAM_Y == 0)
			{
				robotStop(0);
				goto BatDauDoBong;
			}
		}

		robotStop(0);

		while (abs(TAM_Y - 18) > 2 && abs(TAM_X - 32) < 2)
		{
			if (TAM_Y < 18)
				robotRun(1800, 3);
			else if (TAM_Y > 18)
				robotRun(0, 3);
			else
				robotStop(0);

			if (TAM_X == 0 && TAM_Y == 0)
			{
				robotStop(0);
				goto BatDauDoBong;
			}
		}
		robotStop(0);
	}

	robotStop(0);
	vTaskDelay(500);
	if (!DO_BONG())
	{
		robotStop(0);
		goto BatDauDoBong;
	}

	robotStop(0);
	vTaskDelay(500);
	GAP_BONG();
}

//---------------------------------------------------------------------------------------------
void TimBongTuDo(int MauSan)
{
	int rA = 0;
	int tocdo = 0;
	int lantimkiem = 1;

BatDauDoBong:
	lantimkiem = 0;
	taget_BT_Xoay = BT_Xoay_Gap_Bong;
	taget_BT_Truc_X = BT_Truc_X_Tha_Bong;

	RobotMode = 10;
	Servo_Cam = 1600; // Goc nhin tong quat: 800; 			//cam nhin xuong,1700 				chay len san 3: 870									so cu:1600
	vTaskDelay(2000);
	RobotMode = 9;
	vTaskDelay(2000);

	// Tim lan thu nhat
	RESET_ENCODER();
	robotRunAngle(1800, 12, 0, 0.5);
	while (ENCODER_TONG() < 1200 && TAM_X == 0 && TAM_Y == 0)
	{
		if (Servo_Cam > 1300)
			Servo_Cam = Servo_Cam - 1;
		vTaskDelay(20);
	}

	robotStop(0);
	// Tim lan thu nhat
	rA = 0; // robotAngle();
	while (lantimkiem <= 10 && TAM_X == 0 && TAM_Y == 0)
	{
		if (lantimkiem % 2 == 0)
		{
			Servo_Cam = 1100;
			RobotMode = 10;
			vTaskDelay(3000);
			RobotMode = 9;
		}
		else
		{
			Servo_Cam = 1600;
			RobotMode = 10;
			vTaskDelay(3000);
			RobotMode = 9;
		}

		lantimkiem = lantimkiem + 1;
		if (TAM_X == 0 && TAM_Y == 0)
		{
			if (MauSan == 1)
				robotRotate(rA - 900, 0.5, 0);
			else
				robotRotate(rA + 900, 0.5, 0);

			while (TAM_X == 0 && TAM_Y == 0 && robotFixAngle())
			{
				vTaskDelay(1);
			}
		}
		robotStop(0);
		if (TAM_X == 0 && TAM_Y == 0)
		{
			if (MauSan == 1)
				robotRotate(rA + 900, 0.5, 0);
			else
				robotRotate(rA - 900, 0.5, 0);

			while (TAM_X == 0 && TAM_Y == 0 && robotFixAngle())
			{
				vTaskDelay(1);
			}
		}
		robotStop(0);
		if (TAM_X == 0 && TAM_Y == 0)
		{
			Servo_Cam = 1300;
			robotRotate(rA, 0.5, 0);
			while (robotFixAngle())
			{
				vTaskDelay(1);
			}
			robotStop(0);
			vTaskDelay(3000);
		}
	}

	robotStop(0);
	//--------------------------------------------------------
	while (TAM_X < 27 || TAM_X > 37 && TAM_X != 255)
	{
		if (TAM_X < 31)
			robotRotateFree(-0.1, 0);
		else if (TAM_X > 33)
			robotRotateFree(0.1, 0);
		else
			robotRotateStop();

		if (TAM_X == 0 && TAM_Y == 0)
		{
			robotStop(0);
			goto BatDauDoBong;
		}
	}
	robotStop(0);
	vTaskDelay(1000);
	//------------------------------------------------------------------
	while (Servo_Cam < 1700 || (Servo_Cam == 1700 && TAM_Y < 14) && TAM_X != 255)
	{
		while (Servo_Cam < 1700 || (Servo_Cam == 1700 && TAM_Y < 16) && TAM_X != 255)
		{
			if (TAM_Y > 15 && Servo_Cam < 1700)
			{
				if (Servo_Cam >= 1000)
					Servo_Cam = Servo_Cam + 1;
				else if (Servo_Cam >= 1400)
					Servo_Cam = Servo_Cam + 5;

				vTaskDelay(20);
				if (Servo_Cam > 1600)
					Servo_Cam = 1700;
			}

			if (TAM_X > 33)
				robotRotateFree(0.2, 0);
			else if (TAM_X < 31)
				robotRotateFree(-0.2, 0);
			else
				robotRotateStop();

			if (Servo_Cam > 1500)
			{
				if (TAM_Y > 7)
					tocdo = 3;
				else
					tocdo = 7;
			}
			else
				tocdo = 12;

			if (TAM_X == 0 && TAM_Y == 0)
			{
				robotStop(0);
				goto BatDauDoBong;
			}

			robotRun(1800, tocdo);
		}
		robotStop(0);
		vTaskDelay(1000);
	}

	vTaskDelay(1000);
	while (abs(TAM_X - 32) > 2 || abs(TAM_Y - 18) > 2)
	{

		while (abs(TAM_X - 32) > 1)
		{
			if (TAM_X > 32)
				robotRotateFree(0.3, 0);
			else if (TAM_X < 32)
				robotRotateFree(-0.3, 0);
			else
				robotRotateStop();

			if (TAM_X == 0 && TAM_Y == 0)
			{
				robotStop(0);
				goto BatDauDoBong;
			}
		}

		robotStop(0);

		while (abs(TAM_Y - 18) > 2 && abs(TAM_X - 32) < 2)
		{
			if (TAM_Y < 18)
				robotRun(1800, 3);
			else if (TAM_Y > 18)
				robotRun(0, 3);
			else
				robotStop(0);

			if (TAM_X == 0 && TAM_Y == 0)
			{
				robotStop(0);
				goto BatDauDoBong;
			}
		}
		robotStop(0);
	}

	robotStop(0);
	vTaskDelay(500);
	if (!DO_BONG())
	{
		robotStop(0);
		goto BatDauDoBong;
	}

	robotStop(0);
	vTaskDelay(500);
	GAP_BONG();
}

//---------------------------------------------------------------------------------------------
void Tha_Bong_Vao_Silo(int viTriThaBong)
{
	RESET_ENCODER();

	if (MauSan == 1) //  xanh
	{
		while (absI(lazeTraiValue - viTriThaBong) > 5)
		{
			if (viTriThaBong > lazeTraiValue)
			{
				robotRunAngle(-900, 15, 0, 0.9);
			}
			else if (viTriThaBong < lazeTraiValue)
			{
				robotRunAngle(900, 15, 0, 0.9);
			}
			else
			{
				robotStop(0);
			}
		}
	}
	else if (MauSan == 2) // do
	{
		while (absI(lazePhaiValue - viTriThaBong) > 5)
		{
			if (viTriThaBong > lazePhaiValue)
			{
				robotRunAngle(900, 15, 0, 0.9);
			}
			else if (viTriThaBong < lazePhaiValue)
			{
				robotRunAngle(-900, 15, 0, 0.9);
			}
			else
			{
				robotStop(0);
			}
		}
	}

	robotStop(0);

	robotRun(0, 10);
	for (i = 0; i < 50; i++)
		while (lazeSauValue > 195)
			vTaskDelay(1);
	
	XI_LANH_KEP_THA_BONG_OFF;
	//-------------------------------------------------------
	if (MauSan == 1) //  xanh
	{
		while (absI(lazeTraiValue - viTriThaBong) > 1)
		{
			if (viTriThaBong > lazeTraiValue)
			{
				robotRun(-800, 3);
			}
			else if (viTriThaBong < lazeTraiValue)
			{
				robotRun(800, 3);
			}
			else
			{
				robotStop(0);
			}
		}
	}
	else if (MauSan == 2) // do
	{
		while (absI(lazePhaiValue - viTriThaBong) > 1)
		{
			if (viTriThaBong > lazePhaiValue)
			{
				robotRun(800, 3);
			}
			else if (viTriThaBong < lazePhaiValue)
			{
				robotRun(-800, 3);
			}
			else
			{
				robotStop(0);
			}
		}
	}
}


void Chay_Bo_Bong(int Lazer_Siolo)
{
	
		if(MauSan == 1){// 1: san xanh; 2: san do
			while(lazeSauValue > 210)
			{
				if(lazeSauValue > 230) Bam_thanh_laser_trai(50,0,Lazer_Siolo,2);
				else Bam_thanh_laser_trai(20,0,Lazer_Siolo,10);
			}
			while(CB_CHAM_THANH == 1)	Bam_thanh_laser_trai(7,0,Lazer_Siolo,2);

		}
		
		else{
			while(lazeSauValue > 210)	
			{
				if(lazeSauValue > 240)	Bam_thanh_laser_phai(50,0,Lazer_Siolo,2	);
				else Bam_thanh_laser_phai(20,0,Lazer_Siolo,10);
			}
			while(CB_CHAM_THANH == 1)	Bam_thanh_laser_phai(7,0,Lazer_Siolo,2);

		}
		
	robotRun(0,7);
	vTaskDelay(3000);
	robotStop(0);
	SEND_UART(1, 'a');
	vTaskDelay(1000);		
}

