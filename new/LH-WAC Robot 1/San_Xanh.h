extern int Vi_tri_LX, Vi_tri_TP;

//********************** GOC BAN THOC ****************************//
void GocBanThoc_Xanh(int GocBan, int Speed_Mor_RuloTren, int Speed_Mor_RuloDuoi){
	Mor_MamXoay = 200, Mor_MamXoay_back;
	while(BT_MamXoay_value < GocBan){if(BT_MamXoay_value > BT_MamXoay_Phai) break;  vTaskDelay(2);}
	Mor_MamXoay = 0;
	
	Mor_RuloTren = Speed_Mor_RuloTren, Mor_RuloTren_next;
	Mor_RuloDuoi = Speed_Mor_RuloDuoi, Mor_RuloDuoi_next;
}

//********************** THONG SO BAN THOC ****************************//
//Thoc Xanh
void ThongSoGocBanThocXanh(void){
	if		 (Vi_tri_LX == 1 && Vi_tri_TP == 1){GocBanThoc_Xanh(507,30,160);}	//GocBan, Speed_Mor_RuloTren, Speed_Mor_RuloDuoi	
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 2){GocBanThoc_Xanh(512,30,160);}
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 3){GocBanThoc_Xanh(532,30,160);}
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 4){GocBanThoc_Xanh(552,30,160);}
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 5){GocBanThoc_Xanh(572,30,160);}
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 6){GocBanThoc_Xanh(608,30,160);}
	
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 1){GocBanThoc_Xanh(507,35,160);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 2){GocBanThoc_Xanh(512,35,160);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 3){GocBanThoc_Xanh(532,35,160);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 4){GocBanThoc_Xanh(552,35,160);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 5){GocBanThoc_Xanh(572,35,160);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 6){GocBanThoc_Xanh(608,35,160);}
}
//Thoc Tim
void ThongSoGocBanThocTim_Xanh(void){
	if		 (Vi_tri_LX == 1 && Vi_tri_TP == 1){GocBanThoc_Xanh(507,30,145);}	//GocBan, Speed_Mor_RuloTren, Speed_Mor_RuloDuoi	
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 2){GocBanThoc_Xanh(512,30,145);}
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 3){GocBanThoc_Xanh(532,30,145);}
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 4){GocBanThoc_Xanh(552,30,145);}
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 5){GocBanThoc_Xanh(572,30,150);}
	else if(Vi_tri_LX == 1 && Vi_tri_TP == 6){GocBanThoc_Xanh(608,30,150);}
	
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 1){GocBanThoc_Xanh(507,30,145);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 2){GocBanThoc_Xanh(512,30,145);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 3){GocBanThoc_Xanh(532,30,145);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 4){GocBanThoc_Xanh(552,30,145);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 5){GocBanThoc_Xanh(572,30,150);}
	else if(Vi_tri_LX == 2 && Vi_tri_TP == 6){GocBanThoc_Xanh(608,30,150);}
}

//********************** BAN THOC ****************************//
void BanThoc_Xanh(){
	int bit_mamxoay = 0;
	
//Ban thoc Xanh
	if(!R1){
		XI_LANH_LAY_THOC_ON;	
		vTaskDelay(10000);		
		XI_LANH_LAY_THOC_OFF;
		vTaskDelay(1000);	
		
		ThongSoGocBanThocXanh();
		vTaskDelay(8000);

		XI_LANH_BAN_THOC_ON;
		vTaskDelay(5000);
		XI_LANH_BAN_THOC_OFF;
		Mor_RuloDuoi = Mor_RuloTren = 0;

		bit_mamxoay = 1;
	}
	
//Ban thoc Tim
	else if(!R2){
		XI_LANH_LAY_THOC_ON;	
		vTaskDelay(10000);		
		XI_LANH_LAY_THOC_OFF;
		vTaskDelay(1000);	
		
		ThongSoGocBanThocTim_Xanh();
		vTaskDelay(8000);
		
		XI_LANH_BAN_THOC_ON;
		vTaskDelay(5000);
		XI_LANH_BAN_THOC_OFF;
		Mor_RuloDuoi = Mor_RuloTren = 0;
			
		bit_mamxoay = 1;
	}
	
	if(bit_mamxoay == 1){
		while(BT_MamXoay_value > BT_MamXoay_0){
			Mor_MamXoay = 200, Mor_MamXoay_next;
			if(wantExit()) break;  
			vTaskDelay(2);
		}
		Mor_MamXoay = 0, bit_mamxoay = 0;
	}
}

//********************** DI CHUYEN TREN VUNG 2 ****************************//
void DiChuyenTrenVung2_Xanh(void){		
	if(LJOY_LR<5){	//SANG TRAI
		if(Vi_tri_TP<7){
			Vi_tri_TP++;
			if		 (Vi_tri_TP == 2)	{SangTrai_DoLine(1050,20);}	//EN, SPEED - SANG TRAI TU 1 QUA 2
			else if(Vi_tri_TP == 3)	{SangTrai_DoLine(1050,20);}	//EN, SPEED - SANG TRAI TU 2 QUA 3
			else if(Vi_tri_TP == 4)	{SangTrai_DoLine(1050,20);}	//EN, SPEED - SANG TRAI TU 3 QUA 4
			else if(Vi_tri_TP == 5)	{SangTrai_DoLine(1050,20);}	//EN, SPEED - SANG TRAI TU 4 QUA 5
			else if(Vi_tri_TP == 6)	{SangTrai_DoLine(1050,20);}	//EN, SPEED - SANG TRAI TU 5 QUA 6
		}
		while(LJOY_LR <5) vTaskDelay(5);
		robotStop(0);
	}
	else if(LJOY_LR>250){	//SANG PHAI
		if(Vi_tri_TP>1){
			Vi_tri_TP--;
			if		 (Vi_tri_TP == 5)	{SangPhai_DoLine(1050,20);}	//EN, SPEED - SANG PHAI TU 6 QUA 5
			else if(Vi_tri_TP == 4)	{SangPhai_DoLine(1050,20);}	//EN, SPEED - SANG PHAI TU 5 QUA 4
			else if(Vi_tri_TP == 3)	{SangPhai_DoLine(1050,20);}	//EN, SPEED - SANG PHAI TU 4 QUA 3
			else if(Vi_tri_TP == 2)	{SangPhai_DoLine(1050,20);}	//EN, SPEED - SANG PHAI TU 3 QUA 2
			else if(Vi_tri_TP == 1)	{SangPhai_DoLine(1050,20);}	//EN, SPEED - SANG PHAI TU 2 QUA 1
		}
		while(LJOY_LR >250) vTaskDelay(5);
		robotStop(0);
	}	
	else if(LJOY_UD<5){	//DI LEN
		if(Vi_tri_LX == 2){
			
			DiLen(950,20);		//EN, SPEED - DI TU HANG 1 LEN HANG 2
			Vi_tri_LX--;
		}
		while(LJOY_UD<5)vTaskDelay(5);
		robotStop(0);
	}
	else if(LJOY_UD>250){	//DI XUONG
		if(Vi_tri_LX == 1){
			
			DiXuong(950,20);	//EN, SPEED - DI TU HANG 2 XUONG HANG 1
			Vi_tri_LX++;
		}
		while(LJOY_UD>250)vTaskDelay(5);
		robotStop(0);
	}
}

//****************************** FIGHT!!! ******************************//
void XuatPhat_Xanh(void){
	int i=0;
	RESET_ENCODER();
//------------------------------ LAY LUA LAN 1 ------------------------------//
	robotRunAngle(1350, 100, 0, 1);
	while(ENCODER_TONG()< 555){if(wantExit()) break; vTaskDelay(2);}
			
	robotRunAngle(950, 120, 0, 1);
	while(ENCODER_TONG()< 1500){if(wantExit()) break; vTaskDelay(2);}
	XI_LANH_VUON_TAY_LAY_LUA_ON;
	vTaskDelay(1000);
	XI_LANH_HA_LAY_LUA_ON;	
	
	robotRunAngle(800, 75, -30, 1);
	for(i=0;i<50;i++)while(LaserPhaiValue > 130){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(700, 40, -20, 1);
	for(i=0;i<50;i++)while(LaserPhaiValue > 78){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(0, 20, 0, 1);
	while(CB_CA_THANH_TRUOC_TRAI == 1 && CB_CA_THANH_TRUOC_PHAI == 1){if(wantExit()) break; vTaskDelay(2);}
	XI_LANH_HA_LAY_LUA_OFF;
	
//Kep 4 cay lua lan 1
	robotRunAngle(700, 30, -20, 1);	
	while(CB_NHAN_LUA_PHAI == 1 && CB_NHAN_LUA_TRAI == 1){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);
	
	vTaskDelay(2000);
	XI_LANH_TAY_LAY_LUA_TREN_ON;
	XI_LANH_TAY_LAY_LUA_DUOI_ON;
	vTaskDelay(1000);
	XI_LANH_NANG_LAY_LUA_ON;
	vTaskDelay(7500);
		
//Trong lua lan 1
	robotRunAngle(-700, 25, 20, 1);		
	for(i=0;i<50;i++)while(LaserPhaiValue < 69){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);	
	
	SEND_UART(1,'a');
	vTaskDelay(1000);
	
	robotRunAngle(0, 20, 0, 1);
	while(CB_CA_THANH_TRUOC_TRAI == 1 && CB_CA_THANH_TRUOC_PHAI == 1){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(1800, 75, 0, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 250){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(1800, 50, 0, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 200){if(wantExit()) break; vTaskDelay(2);}	
	
	XI_LANH_NANG_LAY_LUA_OFF;
	vTaskDelay(1000);
	XI_LANH_HA_LAY_LUA_ON;
	while(CB_TU_XI_LANH_NANG_HA_LUA == 1){if(wantExit()) break; vTaskDelay(2);}	
	XI_LANH_HA_LAY_LUA_OFF;
	
	robotRunAngle(1800, 40, 25, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 92){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);
	
	while(1){
		robotGamePadControl();
		if(!X) break;
	}
	
	XI_LANH_TAY_LAY_LUA_DUOI_OFF;
	
//Trong lua lan 2	
	robotRunAngle(1800, 30, 15, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 38){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);
	
	XI_LANH_VUON_TAY_LAY_LUA_OFF;
	
	while(1){
		robotGamePadControl();
		if(!X) break;
	}

	XI_LANH_TAY_LAY_LUA_TREN_OFF;
	
	RESET_ENCODER();
	robotRunAngle(1800, 40, 0, 1);
	while(ENCODER_TONG()< 160){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);
	
//------------------------------ LAY LUA LAN 2 ------------------------------//	
	XI_LANH_HA_LAY_LUA_ON;
	robotRunAngle(-900, 75, 0, 1);
	for(i=0;i<50;i++)while(LaserPhaiValue < 130){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);
	
	robotRunAngle(0, 100, 30, 1);
	for(i=0;i<50;i++)while(LaserSauValue < 160){if(wantExit()) break; vTaskDelay(2);}
	
	XI_LANH_VUON_TAY_LAY_LUA_ON;
	XI_LANH_HA_LAY_LUA_OFF;
	robotRunAngle(0, 20, 0, 1);
	while(CB_CA_THANH_TRUOC_TRAI == 1 && CB_CA_THANH_TRUOC_PHAI == 1){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);
	
	robotRunAngle(-700, 35, 20, 1);
	for(i=0;i<50;i++)while(LaserPhaiValue < 150){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(0, 20, 0, 1);
	while(CB_CA_THANH_TRUOC_TRAI == 1 && CB_CA_THANH_TRUOC_PHAI == 1){if(wantExit()) break; vTaskDelay(2);}
	XI_LANH_HA_LAY_LUA_OFF;
	
//Kep 4 cay lua lan 2
	robotRunAngle(-700, 30, 20, 1);	
	while(CB_NHAN_LUA_PHAI == 1 && CB_NHAN_LUA_TRAI == 1){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);
	
	vTaskDelay(2000);
	XI_LANH_TAY_LAY_LUA_TREN_ON;
	XI_LANH_TAY_LAY_LUA_DUOI_ON;
	vTaskDelay(1000);
	XI_LANH_NANG_LAY_LUA_ON;
	vTaskDelay(7500);

//Trong lua lan 3
	robotRunAngle(-700, 25, 20, 1);		
	for(i=0;i<50;i++)while(LaserPhaiValue < 169){if(wantExit()) break; vTaskDelay(2);}	
	
	robotRunAngle(0, 20, 0, 1);
	while(CB_CA_THANH_TRUOC_TRAI == 1 && CB_CA_THANH_TRUOC_PHAI == 1){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);	
	
	SEND_UART(1,'a');
	vTaskDelay(1000);
	
	robotRunAngle(1800, 75, 0, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 250){if(wantExit()) break; vTaskDelay(2);}	
	
	robotRunAngle(1800, 50, 0, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 200){if(wantExit()) break; vTaskDelay(2);}	
	
	XI_LANH_NANG_LAY_LUA_OFF;
	vTaskDelay(1000);
	XI_LANH_HA_LAY_LUA_ON;
	while(CB_TU_XI_LANH_NANG_HA_LUA == 1){if(wantExit()) break; vTaskDelay(2);}	
	XI_LANH_HA_LAY_LUA_OFF;
	
	robotRunAngle(1800, 40, 25, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 92){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);
	
	while(1){
		robotGamePadControl();
		if(!X) break;
	}
	
	XI_LANH_TAY_LAY_LUA_DUOI_OFF;
	
//Trong lua lan 4	
	robotRunAngle(1800, 30, 15, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 38){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);
	
	XI_LANH_VUON_TAY_LAY_LUA_OFF;
	
	while(1){
		robotGamePadControl();
		if(!X) break;
	}

	XI_LANH_TAY_LAY_LUA_TREN_OFF;
	
	RESET_ENCODER();
	robotRunAngle(1800, 40, 0, 1);
	while(ENCODER_TONG()< 140){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);
	
//------------------------------ LAY LUA LAN 3 ------------------------------//
	XI_LANH_HA_LAY_LUA_ON;
	robotRunAngle(-900, 75, 0, 1);
	for(i=0;i<50;i++)while(LaserPhaiValue < 228){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);
	
	robotRunAngle(0, 100, 30, 1);
	for(i=0;i<50;i++)while(LaserSauValue < 160){if(wantExit()) break; vTaskDelay(2);}
	
	XI_LANH_VUON_TAY_LAY_LUA_ON;
	XI_LANH_HA_LAY_LUA_OFF;
	
	robotRunAngle(0, 20, 0, 1);
	while(CB_CA_THANH_TRUOC_TRAI == 1 && CB_CA_THANH_TRUOC_PHAI == 1){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);
	
	robotRunAngle(-700, 35, 20, 1);
	for(i=0;i<50;i++)while(LaserTraiValue > 240){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(0, 20, 0, 1);
	while(CB_CA_THANH_TRUOC_TRAI == 1 && CB_CA_THANH_TRUOC_PHAI == 1){if(wantExit()) break; vTaskDelay(2);}
	XI_LANH_HA_LAY_LUA_OFF;
	
//Kep 4 cay lua lan 3
	robotRunAngle(-700, 30, 20, 1);	
	while(CB_NHAN_LUA_PHAI == 1 && CB_NHAN_LUA_TRAI == 1){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);
	
	vTaskDelay(2000);
	XI_LANH_TAY_LAY_LUA_TREN_ON;
	XI_LANH_TAY_LAY_LUA_DUOI_ON;
	vTaskDelay(1000);
	XI_LANH_NANG_LAY_LUA_ON;
	vTaskDelay(7500);

//Trong lua lan 5
	robotRunAngle(-700, 25, 20, 1);		
	for(i=0;i<50;i++)while(LaserPhaiValue < 269){if(wantExit()) break; vTaskDelay(2);}
  robotStop(0);	
	
	SEND_UART(1,'a');
	vTaskDelay(1000);	
	
	robotRunAngle(0, 20, 0, 1);
	while(CB_CA_THANH_TRUOC_TRAI == 1 && CB_CA_THANH_TRUOC_PHAI == 1){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(1800, 75, 0, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 250){if(wantExit()) break; vTaskDelay(2);}	
	
	robotRunAngle(1800, 50, 0, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 200){if(wantExit()) break; vTaskDelay(2);}	
	
	XI_LANH_NANG_LAY_LUA_OFF;
	vTaskDelay(1000);
	XI_LANH_HA_LAY_LUA_ON;
	while(CB_TU_XI_LANH_NANG_HA_LUA == 1){if(wantExit()) break; vTaskDelay(2);}	
	XI_LANH_HA_LAY_LUA_OFF;
	
	robotRunAngle(1800, 40, 25, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 92){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);
	
	while(1){
		robotGamePadControl();
		if(!X) break;
	}
	
	XI_LANH_TAY_LAY_LUA_DUOI_OFF;
	
//Trong lua lan 6	
	robotRunAngle(1800, 30, 15, 1);
	for(i=0;i<50;i++)while(LaserSauValue > 38){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);
	
	XI_LANH_VUON_TAY_LAY_LUA_OFF;
	
	while(1){
		robotGamePadControl();
		if(!X) break;
	}

	XI_LANH_TAY_LAY_LUA_TREN_OFF;
	
	RESET_ENCODER();
	robotRunAngle(1800, 40, 0, 1);
	while(ENCODER_TONG()< 150){if(wantExit()) break; vTaskDelay(2);}	
	robotStop(0);
	XI_LANH_NANG_LAY_LUA_ON;
	
	robotRunAngle(-900, 50, 0, 1);
	while(ENCODER_TONG()< 1300){if(wantExit()) break; vTaskDelay(2);}	
	XI_LANH_NANG_LAY_LUA_OFF;
	
//------------------------------ CHAY LEN VUNG 2 ------------------------------//
	robotRunAngle(-555, 75, 0, 1);
	while(LaserTraiValue > 35){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);
	
	RESET_ENCODER();
	robotRunAngle(1800, 150, 0, 1);
	while(ENCODER_TONG()< 3000){if(wantExit()) break; vTaskDelay(2);}	
	
	robotRunAngle(1600, 75, 0, 1);
	while(LaserSauValue > 75){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(900, 50, 0, 1);
	while(LaserTraiValue < 240){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(900, 30, 0, 1);
	while(LaserPhaiValue > 205){if(wantExit()) break; vTaskDelay(2);}
	
//  robotRunAngle(0, 30, 0, 1);
//	while(LaserSauValue < 71){if(wantExit()) break; vTaskDelay(2);}	
	
	robotStop(0);	
	
	Vi_tri_TP = 3;
	Vi_tri_LX++;
	
	
//	robotRunAngle(-567, 50, 0, 1);
//	while(LaserTraiValue > 25){if(wantExit()) break; vTaskDelay(2);}
//	
//	RESET_ENCODER();
//	robotRunAngle(1800, 50, 0, 1);
//	while(ENCODER_TONG()< 5678){if(wantExit()) break; vTaskDelay(2);}	
//	
//	robotRunAngle(1800, 30, 0, 0.8);
//	while(LaserSauValue > 98){if(wantExit()) break; vTaskDelay(2);}
//	
//	robotRunAngle(900, 50, 0, 0.8);
//	while(LaserTraiValue < 165){if(wantExit()) break; vTaskDelay(2);}
//	
//	robotRunAngle(900, 30, 0, 0.8);
//	while(LaserTraiValue < 185){if(wantExit()) break; vTaskDelay(2);}
//	
//	robotStop(0);	
//	
//	Vi_tri_TP++;
//	Vi_tri_LX++;
}

//********************** XUI THOI ****************************//
void Retry_Xanh(){
	int i=0;
	
	robotRunAngle(-1555, 75, 0, 1);
	while(LaserTraiValue > 10){if(wantExit()) break; vTaskDelay(2);}
	robotStop(0);
	
	RESET_ENCODER();
	robotRunAngle(1800, 150, 0, 1);
	while(ENCODER_TONG()< 3000){if(wantExit()) break; vTaskDelay(2);}	
	
	robotRunAngle(1600, 75, 0, 1);
	while(LaserSauValue > 75){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(900, 50, 0, 1);
	while(LaserTraiValue < 240){if(wantExit()) break; vTaskDelay(2);}
	
	robotRunAngle(900, 30, 0, 1);
	while(LaserPhaiValue > 205){if(wantExit()) break; vTaskDelay(2);}
	
//  robotRunAngle(0, 30, 0, 1);
//	while(LaserSauValue < 71){if(wantExit()) break; vTaskDelay(2);}	
	
	robotStop(0);	
	
	Vi_tri_TP = 3;
	Vi_tri_LX++;
	
//	RESET_ENCODER();
//	robotRunAngle(-1350, 100, 0, 1);
//	while(LaserTraiValue > 30){if(wantExit()) break; vTaskDelay(2);}
//	
//	robotRunAngle(1800, 50, 0, 1);
//	while(ENCODER_TONG()< 6000){if(wantExit()) break; vTaskDelay(2);}	
//	
//	robotRunAngle(1800, 30, 0, 0.8);
//	while(LaserSauValue > 110){if(wantExit()) break; vTaskDelay(2);}
//	
//	robotRunAngle(900, 50, 0, 0.8);
//	while(LaserTraiValue < 165){if(wantExit()) break; vTaskDelay(2);}
//	
//	robotRunAngle(900, 30, 0, 0.8);
//	while(LaserTraiValue < 183){if(wantExit()) break; vTaskDelay(2);}
//	
//	robotStop(0);	
//	
//	Vi_tri_TP++;
//	Vi_tri_LX++;
}
