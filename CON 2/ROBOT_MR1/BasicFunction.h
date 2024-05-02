//----------------------------CHAY BAM THANH BANG LAZE--------------------------
// void bam_thanh_laze_ngang(float angle, int maxSpeed, float robotAngle, float rototate, float angle_fix, int laze_stable_ngang, int num_stable_change, int dung_laze_nao)
// {
// 	int fix;

// 	int lim = 333;
	
// 	if (bit_lz_truoc == 1)			sai_so_cap_thanh = laser - LaserTruocValue;
// 	else if (bit_lz_truoc == 2)	sai_so_cap_thanh = laser - LaserSauValue;
	
// 	sai_so_cap_thanh = sai_so_cap_thanh * 13;
	
// 	if(sai_so_cap_thanh > lim)sai_so_cap_thanh=lim;
// 	else if(sai_so_cap_thanh < -lim)sai_so_cap_thanh=-lim;

// 	if(angle_fix > 0)
// 	{
// 		fix = abs(dung_laze_nao - laze_stable_ngang) * 12;
// 		if (fix > angle_fix)	fix = angle_fix;
// 	}
// 	else
// 	{
// 		fix = -abs(dung_laze_nao - laze_stable_ngang) * 12;
// 		if (fix < angle_fix)	fix = angle_fix;
// 	}

// 	if(dung_laze_nao - laze_stable_ngang > num_stable_change)
// 	{
// 		robotRunAngle(angle + fix, maxSpeed, robotAngle, rototate);
// 	}
// 	else if(dung_laze_nao - laze_stable_ngang < num_stable_change)
// 	{
// 		robotRunAngle(angle - fix, maxSpeed, robotAngle, rototate);
// 	}
// 	else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
// }

void bam_thanh_laze_ngang(float angle, int maxSpeed, float robotAngle, float rototate,int lim, int laze_stable_ngang, char bit_laze_ngang)
{
	if(bit_laze_ngang == 1)	sai_so_cap_thanh = laze_stable_ngang - laze_4H_Value;
	if(bit_laze_ngang == 2) sai_so_cap_thanh = laze_stable_ngang - laze_8H_Value;


	sai_so_cap_thanh = sai_so_cap_thanh * 13;
	
	if		(sai_so_cap_thanh > lim)	sai_so_cap_thanh=lim;
	else if	(sai_so_cap_thanh < -lim)	sai_so_cap_thanh=-lim;

	if(bit_laze_ngang == 1 && angle == 0)
	{
		if(sai_so_cap_thanh > 0)
		{
			robotRunAngle(angle - abs(sai_so_cap_thanh), maxSpeed, robotAngle, rototate);
		}
		else if(sai_so_cap_thanh < 0)
		{
			robotRunAngle(angle + abs(sai_so_cap_thanh), maxSpeed, robotAngle, rototate);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
	}
	if(bit_laze_ngang == 1 && angle == 1800)
	{
		if(sai_so_cap_thanh > 0)
		{
			robotRunAngle(angle + abs(sai_so_cap_thanh), maxSpeed, robotAngle, rototate);
		}
		else if(sai_so_cap_thanh < 0)
		{
			robotRunAngle(angle - abs(sai_so_cap_thanh), maxSpeed, robotAngle, rototate);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
	}
	if(bit_laze_ngang == 2 && angle == 0)
	{
		if(sai_so_cap_thanh > 0)
		{
			robotRunAngle(angle + abs(sai_so_cap_thanh), maxSpeed, robotAngle, rototate);
		}
		else if(sai_so_cap_thanh < 0)
		{
			robotRunAngle(angle - abs(sai_so_cap_thanh), maxSpeed, robotAngle, rototate);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
	}
	if(bit_laze_ngang == 2 && angle == 1800)
	{
		if(sai_so_cap_thanh > 0)
		{
			robotRunAngle(angle - abs(sai_so_cap_thanh), maxSpeed, robotAngle, rototate);
		}
		else if(sai_so_cap_thanh < 0)
		{
			robotRunAngle(angle + abs(sai_so_cap_thanh), maxSpeed, robotAngle, rototate);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
	}
}
////////////////////////////////////////////////////////////////////////////////
void bam_thanh_laze_doc(float angle, int maxSpeed, float robotAngle, float rototate, float angle_fix, int laze_stable_doc, int num_stable_change, int dung_laze_nao)
{
	int fix;

	fix = abs(dung_laze_nao - laze_stable_doc) * 12;

	if (fix > angle_fix)
		fix = angle_fix;

	if(dung_laze_nao - laze_stable_doc > num_stable_change)
	{
		robotRunAngle(angle + fix, maxSpeed, robotAngle, rototate);
	}
	else if(dung_laze_nao - laze_stable_doc < num_stable_change)
	{
		robotRunAngle(angle - fix, maxSpeed, robotAngle, rototate);
	}
	else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
}
// void cap_thanh_laser_trong_lua_xanh_L1(char bit_lz_truoc, int laser, float angle, int maxSpeed, float robotAngle, float rotate){
// 	int lim = 333;
	
// 	if (bit_lz_truoc == 1)			sai_so_cap_thanh = laser - LaserTruocValue;
// 	else if (bit_lz_truoc == 2)	sai_so_cap_thanh = laser - LaserSauValue;
	
// 	sai_so_cap_thanh = sai_so_cap_thanh * 13;
	
// 	if(sai_so_cap_thanh > lim)sai_so_cap_thanh=lim;
// 	else if(sai_so_cap_thanh < -lim)sai_so_cap_thanh=-lim;

// 	if(angle == 900 && bit_lz_truoc == 1) // cap thanh lazer truoc trong lua lan 1
// 	{
// 		if(sai_so_cap_thanh > 0){robotRunAngle(angle + abs(sai_so_cap_thanh), maxSpeed, robotAngle, rotate);HC = angle + abs(sai_so_cap_thanh);}
// 		else if(sai_so_cap_thanh < 0){robotRunAngle(angle - abs(sai_so_cap_thanh), maxSpeed, robotAngle, rotate);HC = angle - abs(sai_so_cap_thanh);}
// 		else{robotRunAngle(angle, maxSpeed, robotAngle, rotate);}
// 	}
// 	else if(angle == -900 && bit_lz_truoc == 2) // cap thanh lazer sau ve lay lua lan 2
// 	{
// 		if(sai_so_cap_thanh > 0){robotRunAngle(angle + abs(sai_so_cap_thanh), maxSpeed, robotAngle, rotate);HC = angle + abs(sai_so_cap_thanh);}
// 		else if(sai_so_cap_thanh < 0){robotRunAngle(angle - abs(sai_so_cap_thanh), maxSpeed, robotAngle, rotate);HC = angle - abs(sai_so_cap_thanh);}
// 		else{robotRunAngle(angle, maxSpeed, robotAngle, rotate);}
// 	}
// 	else if(angle == 900 && bit_lz_truoc == 2) // cap thanh lazer sau len trong lua lan 2
// 	{
// 		if(sai_so_cap_thanh > 0){robotRunAngle(angle - abs(sai_so_cap_thanh), maxSpeed, robotAngle, rotate);HC = angle - abs(sai_so_cap_thanh);}
// 		else if(sai_so_cap_thanh < 0){robotRunAngle(angle + abs(sai_so_cap_thanh), maxSpeed, robotAngle, rotate);HC = angle + abs(sai_so_cap_thanh);}
// 		else{robotRunAngle(angle, maxSpeed, robotAngle, rotate);}
// 	}
// 	else if(angle == 0 && bit_lz_truoc == 1) // cap thanh lazer truoc chay vao line tren vung 2
// 	{
// 		if(sai_so_cap_thanh > 0){robotRunAngle(angle - abs(sai_so_cap_thanh), maxSpeed, robotAngle, rotate);HC = angle - abs(sai_so_cap_thanh);}
// 		else if(sai_so_cap_thanh < 0){robotRunAngle(angle + abs(sai_so_cap_thanh), maxSpeed, robotAngle, rotate);HC = angle + abs(sai_so_cap_thanh);}
// 		else{robotRunAngle(angle, maxSpeed, robotAngle, rotate);}
// 	}
// }


void USART_SendSTRING(void)
{
	// USART_SendData(USART3, 255); // bat dau gui du lieu
	// vTaskDelay(10);
	//------------------------------------------

	USART_SendData(USART3, (uint16_t)MauSan);
	vTaskDelay(10);
	// USART_SendData(USART3, (uint16_t)RobotMode); // 1- lay bong tai kho; 2- lay bong tu do; 5-quan sat ro bong
	// vTaskDelay(10);
	// USART_SendData(USART3, (uint16_t)Servo_Cam / 100);
	// vTaskDelay(10);
}