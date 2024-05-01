//*****************************8 bien toan cuc *************************************
char xl_gap_bong, xl_kep_lua_tren, xl_kep_lua_duoi, xl_truot_lua;
char vi_tri = 0, Cbcc = 0, Cbnv = 0, Cbnn = 0;

int Nang_vong_max = 322, Nang_vong_min = 105, i;
int Nang_goc_max = 540, Nang_goc_min = 300;

int en_tru = 60;
int max_speed = 10;
int speed_temp = 0;
int speed_tay_lua = 100;

extern vu8 update;

void robotLineRunLeft(vu8 speed);
void robotLineRunRight(vu8 speed);

// char CB_line_trai, CB_line_phai, Nho_trai_truoc, Nho_trai_sau, Nho_phai_truoc, Nho_phai_truoc;
void robotGamePadControl(void)
{

	int tocdo = 15, td_x = 5;
	float tocdoXoay = 0;
	int rJoy_LR = (RJOY_LR >= 5 && RJOY_LR <= 250) ? 1 : 0;
	int lJoy_LR = (LJOY_LR >= 5 && LJOY_LR <= 250) ? 1 : 0;

	if (UP && DOWN && RIGHT && LEFT && rJoy_LR)
	{				  // Khong dieu khien
		robotStop(0); // truot banh

		return;
	}
	/*_____________________________//___________________________*/

	/********************** TOC DO ****************************/
	/*_____________________________//___________________________*/
	if (!L1)
		tocdo = 40, tocdoXoay = 0.4;
	else
		tocdo = 20, tocdoXoay = 0.2;

	//--------- chay cac huong -----------
	if (!UP && DOWN && RIGHT && LEFT && L2)
		robotRun(1800, tocdo);
	else if (UP && !DOWN && RIGHT && LEFT && L2)
		robotRun(0, tocdo);
	else if (UP && DOWN && !RIGHT && LEFT && L2)
		robotRun(-900, tocdo);
	else if (UP && DOWN && RIGHT && !LEFT && L2)
		robotRun(900, tocdo);

	else if (!UP && DOWN && !RIGHT && LEFT && L2)
		robotRun(-1350, tocdo);
	else if (!UP && DOWN && RIGHT && !LEFT && L2)
		robotRun(1350, tocdo);
	else if (UP && !DOWN && !RIGHT && LEFT && L2)
		robotRun(-450, tocdo);
	else if (UP && !DOWN && RIGHT && !LEFT && L2)
		robotRun(450, tocdo);

	//-------------- Dang chay va Khong chay nua, chi xoay ----------------
	if (UP && DOWN && RIGHT && LEFT && !rJoy_LR && lJoy_LR && robotIsRun())
		robotStop(0);

	//-------------- Xoay ----------------
	if (rJoy_LR)
		robotRotateStop();
	else if ((RJOY_LR < 5) && L2)
	{
		if (robotIsRun())
			robotRotateFree(0.5, 0);
		else
			robotRotateFree(tocdoXoay, 0);
	}
	else if ((RJOY_LR > 250) && L2)
	{
		if (robotIsRun())
			robotRotateFree(-0.5, 0);
		else
			robotRotateFree(-tocdoXoay, 0);
		//			robotLineRunLeft(20);//
	}

	else
		robotRotateStop();
}
//////-------------------------------------------------------------

void ADCValue_Control(void)
{
	// khai bao lazer
	static unsigned int lazeSauCouter = 0, lazeSau_SUM = 0;
	static unsigned int lazeTruocCouter = 0, lazeTruoc_SUM = 0;
	static unsigned int lazePhaiCouter = 0, lazePhai_SUM = 0;
	static unsigned int lazeTraiCouter = 0, lazeTrai_SUM = 0;

	// Bien tro vi tri co cau
	static unsigned int bientromamxoayCouter = 0, bientromamxoay_SUM = 0;
	static unsigned int bientronangluaCouter = 0, bientronanglua_SUM = 0;
	static unsigned int bientronangbongCouter = 0, bientronangbong_SUM = 0;
	////----------------TINH TOAN LAZER---------------
	if (lazeSauCouter++ < 100)
	{
		lazeSau_SUM += cam_bien_laze_sau;
	}
	else
	{
		lazeSauValue = lazeSau_SUM / 100;
		lazeSauCouter = 0;
		lazeSau_SUM = 0;
	}
	//-------------------------------------------
	if (lazeTruocCouter++ < 100)
	{
		lazeTruoc_SUM += cam_bien_laze_truoc;
	}
	else
	{
		lazeTruocValue = lazeTruoc_SUM / 100;
		lazeTruocCouter = 0;
		lazeTruoc_SUM = 0;
	}
	//------------------------------
	if (lazePhaiCouter++ < 100)
	{
		lazePhai_SUM += cam_bien_laze_phai;
	}
	else
	{
		lazePhaiValue = lazePhai_SUM / 100;
		lazePhaiCouter = 0;
		lazePhai_SUM = 0;
	}
	//-----------------------------------------
	if (lazeTraiCouter++ < 100)
	{
		lazeTrai_SUM += cam_bien_laze_trai;
	}
	else
	{
		lazeTraiValue = lazeTrai_SUM / 100;
		lazeTraiCouter = 0;
		lazeTrai_SUM = 0;
	}
	//-----------------TINH TOAN BIEN TRO---------------

	if (bientromamxoayCouter++ < 50)
	{
		bientromamxoay_SUM += bien_tro_mam_xoay;
	}
	else
	{
		BienTroMamXoayValue = bientromamxoay_SUM / 50;
		bientromamxoayCouter = 0;
		bientromamxoay_SUM = 0;
	}
	//-----------------------------------
	if (bientronangluaCouter++ < 50)
	{
		bientronanglua_SUM += bien_tro_nang_lua;
	}
	else
	{
		bientronangluaValue = bientronanglua_SUM / 50;
		bientronangluaCouter = 0;
		bientronanglua_SUM = 0;
	}
	//-----------------------------
	if (bientronangbongCouter++ < 50)
	{
		bientronangbong_SUM += bien_tro_nang_bong;
	}
	else
	{
		bientronangbongValue = bientronangbong_SUM / 50;
		bientronangbongCouter = 0;
		bientronangbong_SUM = 0;
	}
}

//-----------------------------------------RESET CAC CO CAU----------------------------------------------------
//---------------------------------------NANG LUA---------------------------------------------------------------
void giu_Tay_Nang_Lua()
{
	if (taget_BT_Nang_Lua < Min_BT_Nang_Lua - 5)
		taget_BT_Nang_Lua = Min_BT_Nang_Lua;
	if (taget_BT_Nang_Lua > Max_BT_Nang_Lua)
		taget_BT_Nang_Lua = Max_BT_Nang_Lua;

	if (bientronangluaValue < Min_BT_Nang_Lua)
	{
		Mor_NangLua_nghich;
		Mor_NangLua = 10;
		return;
	}
	if (bientronangluaValue > Max_BT_Nang_Lua)
	{
		Mor_NangLua_thuan;
		Mor_NangLua = 10;
		return;
	}

	if (abs(bientronangluaValue - taget_BT_Nang_Lua) > 3)
	{
		if (bientronangluaValue > taget_BT_Nang_Lua)
			Mor_NangLua_thuan;
		else
			Mor_NangLua_nghich;

		speed_temp = abs(bientronangluaValue - taget_BT_Nang_Lua) * 13;
		if (speed_temp > 250) // 50
			speed_temp = 250;
		if (speed_temp < 50)
			speed_temp = 50;
		Mor_NangLua = speed_temp;
	}
	else
		Mor_NangLua = 0;
}

void Nang_ha_tay_lua(void)
{
	if ((RJOY_UD > 250) && (taget_BT_Nang_Lua > Min_BT_Nang_Lua))
		taget_BT_Nang_Lua--, vTaskDelay(150);
	else if ((RJOY_UD < 5) && (taget_BT_Nang_Lua < Max_BT_Nang_Lua))
		taget_BT_Nang_Lua++, vTaskDelay(150);
}

//-----------------------------------------RESET MAM XOAY-----------------------------------------------------
void giu_Mam_Xoay()
{
	//	if(bientronangluaValue < taget_BT_Nang_Lua - 5 ){
	//		Mor_NangLua = 0;
	//		return;
	//	}
	
	if (taget_BT_Xoay < Min_BT_Xoay)
		taget_BT_Xoay = Min_BT_Xoay;
	if (taget_BT_Xoay > Max_BT_Xoay)
		taget_BT_Xoay = Max_BT_Xoay;

	if (BienTroMamXoayValue < Min_BT_Xoay)
	{
		Mor_Mam_nghich;
		Mor_Mam = 10;
		return;
	}
	if (BienTroMamXoayValue > Max_BT_Xoay)
	{
		Mor_Mam_thuan;
		Mor_Mam = 10;
		return;
	}

	if (abs(BienTroMamXoayValue - taget_BT_Xoay) > 1)
	{
		if (BienTroMamXoayValue > taget_BT_Xoay)
			Mor_Mam_thuan;
		else
			Mor_Mam_nghich;

		speed_temp = abs(BienTroMamXoayValue - taget_BT_Xoay);
		if (speed_temp > 50) // 50
			speed_temp = 50;
		if (speed_temp < 5)
			speed_temp = 5;

		Mor_Mam = speed_temp;
	}
	else
		Mor_Mam = 2;
}
void Quay_mam(void)
{
	if ((!SQUARE) && (taget_BT_Xoay < Max_BT_Xoay))
		taget_BT_Xoay++, vTaskDelay(180);
	else if ((!O) && (taget_BT_Xoay > Min_BT_Xoay))
		taget_BT_Xoay--, vTaskDelay(180);
}

//---------------------------------------GIU TAY BONG---------------------------------------------------------------
void Giu_tay_lay_bong(void)
{
	//	if(bientronangbongValue < Min_BT_Nang_Bong - 12 || bientronangluaValue > Max_BT_Nang_Bong + 12)  {Mor_bong = 2; return;}
	//	if(abs(bientronangbongValue - taget_BT_Nang_Bong) > 3){
	//		if(bientronangbongValue > taget_BT_Nang_Bong) Mor_bong_vao;
	//		else Mor_bong_ra;
	//
	//		speed_temp = abs(bientronangbongValue - taget_BT_Nang_Bong)*10;
	//
	//		if(speed_temp > 50) speed_temp = 50;
	//		if(speed_temp < 10) speed_temp = 10;
	//	  Mor_bong = speed_temp;
	//	}
	//	else Mor_bong = 2;
	if (taget_BT_Nang_Bong < Min_BT_Nang_Bong)
		taget_BT_Nang_Bong = Min_BT_Nang_Bong;
	if (taget_BT_Nang_Bong > Max_BT_Nang_Bong)
		taget_BT_Nang_Bong = Max_BT_Nang_Bong;

	if (bientronangbongValue < Min_BT_Nang_Bong)
	{
		Mor_bong_ra;
		Mor_bong = 10;
		return;
	}
	if (bientronangbongValue > Max_BT_Nang_Bong)
	{
		Mor_bong_vao;
		Mor_bong = 10;
		return;
	}

	if (abs(bientronangbongValue - taget_BT_Nang_Bong) > 5)
	{
		if (bientronangbongValue > taget_BT_Nang_Bong)
			Mor_bong_vao;
		else
			Mor_bong_ra;

		speed_temp = abs(bientronangbongValue - taget_BT_Nang_Bong) * 5;
		if (speed_temp > 220) // 50
			speed_temp = 220;
		if (speed_temp < 20)
			speed_temp = 20;

		Mor_bong = speed_temp;
	}
	else
		Mor_bong = 2;
}

void Ra_vao_lay_bong(void)
{
	if ((!SQUARE) && (taget_BT_Nang_Bong < Max_BT_Nang_Bong))
		taget_BT_Nang_Bong++, vTaskDelay(100);
	else if ((!O) && (taget_BT_Nang_Bong > Min_BT_Nang_Bong))
		taget_BT_Nang_Bong--, vTaskDelay(100);
}

// void bam_Thanh_Lazer_Phai(int speed,int angle_fix,int AngleHead,int lazer_stable_phai,int num_change_stable){
//		if(lazePhaiValue - lazer_stable_phai > num_change_stable){
//			robotRunAngle(0 + angle_fix,speed,AngleHead,-0.1);
//		}
//		else if(lazePhaiValue - lazer_stable_phai < num_change_stable){
//			robotRunAngle(0 - angle_fix,speed,AngleHead,-0.1);
//		}
//		else robotRunAngle(0,speed,AngleHead,0.1);
// }

void bam_Thanh_Lazer_Phai_1800(int speed, int angle_fix, int AngleHead, int lazer_stable_phai, int num_change_stable)
{
	if (lazePhaiValue - lazer_stable_phai > num_change_stable)
	{
		robotRunAngle(1800 - angle_fix, speed, AngleHead, 0.1);
	}
	else if (lazePhaiValue - lazer_stable_phai < num_change_stable)
	{
		robotRunAngle(-1800 + angle_fix, speed, AngleHead, 0.1);
	}
	else
		robotRunAngle(1800, speed, AngleHead, 0.1);
}

void bam_Thanh_Lazer_Truoc(int speed, int angle_fix, int AngleHead, int lazer_stable_truoc, int num_change_stable)
{
	if (lazeTruocValue - lazer_stable_truoc > num_change_stable)
	{
		robotRunAngle(900 + angle_fix, speed, AngleHead, 0.2);
	}
	else if (lazeTruocValue - lazer_stable_truoc < num_change_stable)
	{
		robotRunAngle(900 - angle_fix, speed, AngleHead, 0.2);
	}
	else
		robotRunAngle(900, speed, AngleHead, 0.2);
}
void bam_Thanh_Lazer_Truoc_san2do(int speed, int AngleHead, int lazer_stable_truoc, int num_change_stable, int fix_max)
{
	int fix;

	fix = abs(lazeTruocValue - lazer_stable_truoc) * 12;

	if (fix > fix_max)
		fix = fix_max;

	if (lazeTruocValue - lazer_stable_truoc > num_change_stable)
	{
		robotRunAngle(-900 - fix, speed, AngleHead, 0.1);
	}
	else if (lazeTruocValue - lazer_stable_truoc < num_change_stable)
	{
		robotRunAngle(-900 + fix, speed, AngleHead, 0.1);
	}
	else
		robotRunAngle(-900, speed, AngleHead, 0.1);
}

void bam_Thanh_Lazer_Trai(int speed, int angle_fix, int AngleHead, int lazer_stable_trai, int num_change_stable)
{
	if (lazeTraiValue - lazer_stable_trai > num_change_stable)
	{
		robotRunAngle(0 - angle_fix, speed, AngleHead, -0.1);
	}
	else if (lazeTraiValue - lazer_stable_trai < num_change_stable)
	{
		robotRunAngle(0 + angle_fix, speed, AngleHead, -0.1);
	}
	else
		robotRunAngle(0, speed, AngleHead, -0.1);
}

void bam_Thanh_Lazer_Truoc_xanh(int speed, int angle_fix, int AngleHead, int lazer_stable_truoc, int num_change_stable)
{
	if (lazeSauValue - lazer_stable_truoc > num_change_stable)
	{
		robotRunAngle(-900 - angle_fix, speed, AngleHead, 0.3);
	}
	else if (lazeSauValue - lazer_stable_truoc < num_change_stable)
	{
		robotRunAngle(-900 + angle_fix, speed, AngleHead, 0.3);
	}
	else
		robotRunAngle(-900, speed, AngleHead, 0.3);
}

void bam_Thanh_Lazer_Truoc_phai_do(int speed, int angle_fix, int AngleHead, int lazer_stable_truoc, int num_change_stable)
{
	if (lazePhaiValue - lazer_stable_truoc > num_change_stable)
	{
		robotRunAngle(-900 + angle_fix, speed, AngleHead, 0.1);
	}
	else if (lazePhaiValue - lazer_stable_truoc < num_change_stable)
	{
		robotRunAngle(-900 - angle_fix, speed, AngleHead, 0.1);
	}
	else
		robotRunAngle(-900, speed, AngleHead, 0.1);
}
void bam_Thanh_Lazer_Trai_quaphai(int speed, int angle_fix, int AngleHead, int lazer_stable_trai, int num_change_stable)
{
	if (lazeSauValue - lazer_stable_trai > num_change_stable)
	{
		robotRunAngle(900 + angle_fix, speed, AngleHead, -0.3);
	}
	else if (lazeSauValue - lazer_stable_trai < num_change_stable)
	{
		robotRunAngle(900 - angle_fix, speed, AngleHead, -0.3);
	}
	else
		robotRunAngle(900, speed, AngleHead, -0.3);
}
//-------------------------------------bam laze moi-----------------------------------------------
void bam_Thanh_Lazer_Truoc_do(int speed, int AngleHead, int lazer_stable_truoc, int num_change_stable, int fix_max)
{
	int fix;

	fix = abs(lazeTruocValue - lazer_stable_truoc) * 12;

	if (fix > fix_max)
		fix = fix_max;

	if (lazeTruocValue - lazer_stable_truoc > num_change_stable)
	{
		robotRunAngle(900 + fix, speed, AngleHead, 0.1);
	}
	else if (lazeTruocValue - lazer_stable_truoc < num_change_stable)
	{
		robotRunAngle(900 - fix, speed, AngleHead, 0.1);
	}
	else
		robotRunAngle(900, speed, AngleHead, 0.1);
}
void Bam_thanh_laser_phai(int speed, int AngleHead, int lazer_stable_phai, int num_change_stable, int fix_max)
{
	int fix;

	fix = abs(lazePhaiValue - lazer_stable_phai) * 12;

	if (fix > fix_max)
		fix = fix_max;

	if (lazePhaiValue - lazer_stable_phai > num_change_stable)
	{
		robotRunAngle(0 + fix, speed, AngleHead, 0.1);
	}
	else if (lazePhaiValue - lazer_stable_phai < num_change_stable)
	{
		robotRunAngle(0 - fix, speed, AngleHead, 0.1);
	}
	else
		robotRunAngle(0, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_trai(int speed, int AngleHead, int lazer_stable_trai, int num_change_stable, int fix_max)
{
	int fix;

	fix = abs(lazeTraiValue - lazer_stable_trai) * 12;

	if (fix > fix_max)
		fix = fix_max;

	if (lazeTraiValue - lazer_stable_trai > num_change_stable)
	{
		robotRunAngle(0 - fix, speed, AngleHead, 0.1);
	}
	else if (lazeTraiValue - lazer_stable_trai < num_change_stable)
	{
		robotRunAngle(0 + fix, speed, AngleHead, 0.1);
	}
	else
		robotRunAngle(0, speed, AngleHead, 0.1);
}

//-------------------------------------bam laze moi-----------------------------------------------
void Bam_thanh_laser_phai_1800(int speed, int AngleHead, int lazer_stable_phai, int num_change_stable, int fix_max)
{
	int fix;

	fix = abs(lazePhaiValue - lazer_stable_phai) * 12;

	if (fix > fix_max)
		fix = fix_max;
	if(lazePhaiValue > 23){
	if (lazePhaiValue - lazer_stable_phai > num_change_stable)
	{
		robotRunAngle(1800 - fix, speed, AngleHead, 0.1);
	}
	else if (lazePhaiValue - lazer_stable_phai < num_change_stable)
	{
		robotRunAngle(-1800 + fix, speed, AngleHead, 0.1);
	}
	else
		robotRunAngle(1800, speed, AngleHead, 0.1);
}
}	

void Bam_thanh_laser_trai_1800(int speed, int AngleHead, int lazer_stable_trai, int num_change_stable, int fix_max)
{
	int fix;

	fix = abs(lazeTraiValue - lazer_stable_trai) * 12;

	if (fix > fix_max)
		fix = fix_max;

	if(lazeTraiValue > 30){
	if (lazeTraiValue - lazer_stable_trai > num_change_stable)
	{
		robotRunAngle(-1800 + fix, speed, AngleHead, 0.1);
	}
	else if (lazeTraiValue - lazer_stable_trai < num_change_stable)
	{
		robotRunAngle(1800 - fix, speed, AngleHead, 0.1);
	}
	else
		robotRunAngle(1800, speed, AngleHead, 0.1);
}
}

int go_To_Phai_xanh(int laser_phai, int laser_sau)
{

	for (i = 0; i < 50; i++)
		while (lazePhaiValue > laser_phai)
		{
			bam_Thanh_Lazer_Truoc(20, 80, 0, laser_sau, 1);
			if (wantExit() == 1)
				break;
			vTaskDelay(1);
		}
	robotStop(0);
}

int go_To_Phai_900(int laser_trai)
{

	robotRunAngle(-900, 20, 0, 0.2);
	for (i = 0; i < 50; i++)
		while (lazeTraiValue > laser_trai)
		{ // bam_Thanh_Lazer_Truoc_do(30,50,5,laser_sau,2);
			if (wantExit() == 1)
				break;
			vTaskDelay(1);
		}
	robotStop(0);
}

int go_To_Phai_900_xanh(int laser_trai)
{

	robotRunAngle(900, 20, 0, 0.2);
	for (i = 0; i < 50; i++)
		while (lazePhaiValue > laser_trai)
		{ // bam_Thanh_Lazer_Truoc_do(30,50,5,laser_sau,2);
			if (wantExit() == 1)
				break;
			vTaskDelay(1);
		}
	robotStop(0);
}
// -----------------------------
int go_To_Trai(int speed, int laser_phai)
{

	for (i = 0; i < 50; i++)
		while (lazePhaiValue < laser_phai)
		{
			robotLineRunLeft(speed);
			if (wantExit() == 1)
				break;
			vTaskDelay(1);
		}
	robotStop(0);
}
int go_To_Phai(int speed, int laser_phai)
{

	for (i = 0; i < 50; i++)
		while (lazePhaiValue > laser_phai)
		{
			robotLineRunRight(speed);
			if (wantExit() == 1)
				break;
			vTaskDelay(1);
		}
	robotStop(0);
}
//------------------------------------
int go_To_Trai_xanh(int laser_phai, int laser_sau)
{

	for (i = 0; i < 50; i++)
		while (lazePhaiValue < laser_phai)
		{
			bam_Thanh_Lazer_Truoc_xanh(20, 80, 0, laser_sau, 1);
			if (wantExit() == 1)
				break;
			vTaskDelay(1);
		}
	robotStop(0);
}
int go_To_Trai_900_xanh(int laser_trai)
{

	robotRunAngle(-900, 20, 0, 0.2);
	for (i = 0; i < 50; i++)
		while (lazePhaiValue < laser_trai)
		{ // bam_Thanh_Lazer_Truoc_do(30,50,5,laser_sau,2);
			if (wantExit() == 1)
				break;
			vTaskDelay(1);
		}
	robotStop(0);
}


// Robot chay den vi tri bong 
int mapSan2Do[] = {307, 255, 207, 155, 103, 53};

void chuyen_Bong_do(void)
{
	int speed = 0;
	int speed_max = 60;
	int speed_min = 30;
	int gap = 5;
	if (vi_tri_bong >= 0 && vi_tri_bong <= 5)
	{
		while (absI(lazePhaiValue - mapSan2Do[vi_tri_bong]) > gap)
		{
			// tu chinh toc do
			speed = absI(mapSan2Do[vi_tri_bong] - lazePhaiValue) / 2;
			if(speed >= speed_max) 
			{
				speed = speed_max;
			}
			else if(speed < speed_min)
			{
				speed = speed_min;
			}

			// tu bam lazer
			if (lazePhaiValue < mapSan2Do[vi_tri_bong] + gap)
			{
				robotLineRunLeft(speed);
			}
			else if (lazePhaiValue > mapSan2Do[vi_tri_bong] - gap)
			{
				robotLineRunRight(speed);
			}
			else
			{
				robotStop(50);
			}
			if(wantExit()) break;
		}
	}
	return;
}
//------------------------chuyen_Bong_Xanh----------------------------
int mapSan2Xanh[] = {307, 258, 207, 155, 107, 55};
void chuyen_Bong_xanh(void)
{
	int speed = 0;
	int speed_max = 60;
	int speed_min = 30;
	int gap = 5;
	if (vi_tri_bong >= 0 && vi_tri_bong <= 5)
	{
		while (absI(lazeTraiValue - mapSan2Xanh[vi_tri_bong]) > gap)
		{
			// tu chinh toc do
			speed = absI(mapSan2Xanh[vi_tri_bong] - lazeTraiValue) / 2;
			if(speed >= speed_max) 
			{
				speed = speed_max;
			}
			else if(speed < speed_min)
			{
				speed = speed_min;
			}

			// tu bam lazer
			if (lazeTraiValue < mapSan2Xanh[vi_tri_bong] + gap)
			{
				robotLineRunRight(speed);
			}
			else if (lazeTraiValue > mapSan2Xanh[vi_tri_bong] - gap)
			{
				robotLineRunLeft(speed);
			}
			else
			{
				robotStop(50);
			}
			if(wantExit()) break;
		}
	}
	return;
}
void test_cylinder(void)
{
	//***********************************************************************************
	if (!R2)
	{
		XI_LANH_KEP_BONG_ON;
	}
	else
	{
		XI_LANH_KEP_BONG_OFF;
	}
}


void GAP_BONG_TRONG(void)
{
	if (!TRIANGLE)
	{ //***************ban gan********************
		update = 0;
		XI_LANH_TONG_ON;
		XI_LANH_DAY_BONG_VAO;
		for (i = 0; i < 50; i++)
			while (CB_XL_DAY_BONG_VAO == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		XI_LANH_LAY_BONG_LEN;
		for (i = 0; i < 50; i++)
			while (CB_TAY_GAP_BONG_DUOI == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		XI_LANH_KEP_BONG_OFF;
		taget_BT_Nang_Bong = BT_Bat_Bong_giua;
		for (i = 0; i < 50; i++)
			while (bientronangbongValue > BT_Bat_Bong_giua)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			};
		vTaskDelay(5000);
		XI_LANH_LAY_BONG_XUONG;
		for (i = 0; i < 50; i++)
			while (CB_TAY_GAP_BONG_TREN == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		XI_LANH_KEP_BONG_ON;
		vTaskDelay(3000);
		Ban_Bong();
		XI_LANH_LAY_BONG_LEN;
		for (i = 0; i < 50; i++)
			while (CB_TAY_GAP_BONG_DUOI == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
			
		if (CHON_SAN == 1){
			Quay_Mam_Gamepad_Xanh();}
		else{ 
			Quay_Mam_Gamepad();
		}
		
		taget_BT_Nang_Bong = BT_Nang_Tha_Bong;
		XI_LANH_DAY_BONG_VAO;
		for (i = 0; i < 50; i++)
			while (CB_XL_DAY_BONG_VAO == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}

		for (i = 0; i < 50; i++)
			while (bientronangbongValue > BT_Nang_Tha_Bong + 5)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			};

		XI_LANH_KEP_BONG_OFF;
		while(RJOY)	vTaskDelay(1);;
		Mor_BanDuoi = 0;
		Mor_BanTren = 0;
		//vTaskDelay(1500);
		taget_BT_Xoay = goc_ban;
		taget_BT_Nang_Bong = BT_Bat_Bong_giua;
		
		update = 1;

	}
	if(!R1){
		taget_BT_Nang_Bong = BT_Nang_Tha_Bong;
		XI_LANH_DAY_BONG_VAO;
		if (CHON_SAN == 1){
			Quay_Mam_Gamepad_Xanh();}
		else{ 
			Quay_Mam_Gamepad();
		}
		Ban_Bong();
		for (i = 0; i < 50; i++)
			while (CB_XL_DAY_BONG_VAO == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		for (i = 0; i < 50; i++)
			while (bientronangbongValue > BT_Nang_Tha_Bong  + 5)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			};
		
		XI_LANH_KEP_BONG_OFF;
		vTaskDelay(20000);
		Mor_BanDuoi = 0;
		Mor_BanTren = 0;
		vTaskDelay(1500);
		taget_BT_Xoay = goc_ban;
		taget_BT_Nang_Bong = BT_Bat_Bong_giua;	
		update = 1;

	}	
}
//----------------------------------------------LAY BONG NGOAI---------------------------------------
void GAP_BONG_NGOAI(void)
{
	if (!X)
	{
		update = 0;
		XI_LANH_DAY_BONG_VAO;
		XI_LANH_TONG_ON;
		XI_LANH_LAY_BONG_LEN;
		for (i = 0; i < 50; i++)
			while (CB_TAY_GAP_BONG_DUOI == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		XI_LANH_KEP_BONG_ON;
		taget_BT_Nang_Bong = BT_Bat_Bong_sau;
		XI_LANH_DAY_BONG_RA;
		for (i = 0; i < 50; i++)
			while (CB_XL_DAY_BONG_RA == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		for (i = 0; i < 50; i++)
			while (bientronangbongValue > BT_Bat_Bong_sau - 3)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			};
		vTaskDelay(3000);
		XI_LANH_KEP_BONG_OFF;
		XI_LANH_LAY_BONG_XUONG;
		for (i = 0; i < 50; i++)
			while (CB_TAY_GAP_BONG_TREN == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		XI_LANH_KEP_BONG_ON;
		vTaskDelay(3000);
		XI_LANH_LAY_BONG_LEN;
		// tu quay mam
		if (CHON_SAN == 1){
			Quay_Mam_Gamepad_Xanh();}
		else{ 
			Quay_Mam_Gamepad();
		}
		for (i = 0; i < 50; i++)
			while (CB_TAY_GAP_BONG_DUOI == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		Ban_Bong();
		taget_BT_Nang_Bong = BT_Nang_Tha_Bong;
		XI_LANH_DAY_BONG_VAO;
		for (i = 0; i < 50; i++)
			while (CB_XL_DAY_BONG_VAO == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		
		for (i = 0; i < 50; i++)
			while (bientronangbongValue > BT_Nang_Tha_Bong + 5)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			};
		XI_LANH_KEP_BONG_OFF;
		while(RJOY) vTaskDelay(1);
	
		Mor_BanDuoi = 0;
		Mor_BanTren = 0;
		taget_BT_Xoay = goc_ban;
		taget_BT_Nang_Bong = BT_Bat_Bong_giua;
		update = 1;
	}
	if(!R1){
		taget_BT_Nang_Bong = BT_Nang_Tha_Bong;
		XI_LANH_DAY_BONG_VAO;
		if (CHON_SAN == 1){
			Quay_Mam_Gamepad_Xanh();}
		else{ 
			Quay_Mam_Gamepad();
		}
		for (i = 0; i < 50; i++)
			while (CB_XL_DAY_BONG_VAO == 1)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			}
		Ban_Bong();
		for (i = 0; i < 50; i++)
			while (bientronangbongValue > BT_Nang_Tha_Bong + 5)
			{
				if (wantExit() == 1)
					break;
				vTaskDelay(1);
			};
		
		XI_LANH_KEP_BONG_OFF;
		while(RJOY);
		Mor_BanDuoi = 0;
		Mor_BanTren = 0;
	
		taget_BT_Xoay = goc_ban;
		taget_BT_Nang_Bong = BT_Bat_Bong_giua;		
		update = 1;

	}
}

// tu chinh goc mam
int mamArray[] = {440, 470, 490, 525, 555, 580};
int Quay_Mam_Gamepad()
{
	taget_BT_Xoay = mamArray[vi_tri_bong];
	while(absI(BienTroMamXoayValue - taget_BT_Xoay) > 1) vTaskDelay(100);
	robotStop(1);
	return 1;
}

int mamArrayXanh[] = {461, 420, 405, 375, 345, 320};
int Quay_Mam_Gamepad_Xanh()
{
	
	taget_BT_Xoay = mamArrayXanh[vi_tri_bong];
	while(absI(BienTroMamXoayValue - taget_BT_Xoay) > 1) vTaskDelay(100);
	robotStop(1);
	return 1;
}

int BanArray[6][2] = {{40,110},{40,110},{40,110},{40,110},{40,120},{40,120}} ; // -------mor tren,mor duoi/

int Ban_Bong(){
	Mor_BanTren =  BanArray[vi_tri_bong][0];
	Mor_BanDuoi =  BanArray[vi_tri_bong][1];
	robotStop(1);
	return 1;
}    

