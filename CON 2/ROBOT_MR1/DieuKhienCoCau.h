//*****************************8 bien toan cuc *************************************
char vi_tri = 0, Cbnv = 0, Cbnn = 0, Resetnangvong = 0;
char bien_xl_hot_banh, bien_xl_nap_dan, bien_xl_kep_lua_13, bien_xl_lay_bong, bien_xl_kep_lua_24, bien_xl_tay_gap, bien_xl_keo_lua, bien_xoay_dong_co_nong_ban;

/********************************ENCODER SILO 5 4 3 2 1 TU TRONG RA HUONG LEN****************************************************/
int silo_5 = 14, silo_4 = 40, silo_3 = 80, silo_2 = 120, silo_1 = 160;




//--------------------------------------------------------------------------------
void robotGamePadControl(void) {
    int tocdo = 15, toc_do_xoay_free = 0;
	float	tocdoXoay = 0;
    int rJoy_LR  = (RJOY_LR >= 5 && RJOY_LR <= 250)? 1 : 0; 
    int lJoy_LR  = (LJOY_LR >= 5 && LJOY_LR <= 250)? 1 : 0;

    if(UP && DOWN && RIGHT && LEFT && rJoy_LR && lJoy_LR && O) { // Khong dieu khien
			
        robotStop(2); //truot banh
				
        return;
    }                
/*_____________________________//___________________________*/

/********************** TOC DO ****************************/
/*_____________________________//___________________________*/
    if(!L1) tocdo = 50, tocdoXoay = 20, toc_do_xoay_free = 20;
    else if(!L2) tocdo = 10, tocdoXoay = 0.5, toc_do_xoay_free = 7;
    else tocdo = 30, tocdoXoay = 0.05, toc_do_xoay_free = 10;                    //sua toc_do_xoay_free tu 7 len 10
                                                                                //sua tocdoXoay tu 0.05 len 5
    
    //--------- chay cac huong -----------
    if	   (!UP && DOWN && RIGHT && LEFT)   robotRun(0, tocdo);
    else if(UP && !DOWN && RIGHT && LEFT)   robotRun(1800, tocdo);
    else if(UP && DOWN && !RIGHT && LEFT)   robotRun(900, tocdo);
	else if(UP && DOWN && RIGHT && !LEFT)   robotRun(-900, tocdo);
    
    else if(!UP && DOWN && !RIGHT && LEFT)  robotRun(450,tocdo);
    else if(!UP && DOWN && RIGHT && !LEFT)  robotRun(-450,tocdo);
    else if(UP && !DOWN && !RIGHT && LEFT)  robotRun(1350,tocdo);
    else if(UP && !DOWN && RIGHT && !LEFT)  robotRun(-1350,tocdo);

    
    //-------------- Dang chay va Khong chay nua, chi xoay ----------------
    if(UP && DOWN && RIGHT && LEFT && !rJoy_LR && lJoy_LR  && robotIsRun()) robotStop(5);   

    //-------------- Xoay ----------------
    if(rJoy_LR) robotRotateStop();
    else if((RJOY_LR < 5) && L2)
    {
        if(robotIsRun()) robotRotateFree(-1.5,0, tocdo);
        //else robotRotateFree(-tocdoXoay,0);
				else {bit_khoa_ham_chay_thay_tuan = 1;setMotor(-toc_do_xoay_free,toc_do_xoay_free,-toc_do_xoay_free,toc_do_xoay_free);}
    }
    else if((RJOY_LR > 250) && L2)
    {
        if(robotIsRun()) robotRotateFree(1.5,0, tocdo);
        //else robotRotateFree(tocdoXoay,0);
				else {bit_khoa_ham_chay_thay_tuan = 1;setMotor(toc_do_xoay_free,-toc_do_xoay_free,toc_do_xoay_free,-toc_do_xoay_free);}
    }

    else setMotor(2,2,2,2);bit_khoa_ham_chay_thay_tuan = 0;robotRotateStop();
	}
//////-------------------------------------------------------------	
void ADCValue_Control(void)
{
    static unsigned int lazeTruocCouter =0, lazeTruoc_SUM =0, lazeNgang_Counter_do =0, lazeNgang_SUM_do =0, BienTroGocBanThoc_Couter =0, BienTroGocBanThoc_SUM =0, BT_Dia_xoay_Couter =0, BT_Dia_xoay_SUM =0, lazeNgang_Counter_xanh =0,lazeNgang_SUM_xanh =0;
//------------------------	
    if(lazeTruocCouter++ < 20)	lazeTruoc_SUM += cam_bien_laze_truoc;  
    else
    {
        lazeSauValue = lazeTruoc_SUM/20
        ;
        lazeTruocCouter = 0;
        lazeTruoc_SUM = 0;
    }
//------------------------
    if(lazeNgang_Counter_do++ < 20)	lazeNgang_SUM_do += cam_bien_laze_ngang_do;  
    else
    {
        lazeNgangDoValue = lazeNgang_SUM_do/20;
        lazeNgang_Counter_do = 0;
        lazeNgang_SUM_do = 0;
    }
//------------------------
    if(lazeNgang_Counter_xanh++ < 20)	lazeNgang_SUM_xanh += cam_bien_laze_ngang_xanh;  
    else
    {
        lazeNgangXanhValue = lazeNgang_SUM_xanh/20;
        lazeNgang_Counter_xanh = 0;
        lazeNgang_SUM_xanh = 0;
    }
////------------------------
//	if(BienTroGocBanThoc_Couter++ < 50)	BienTroGocBanThoc_SUM += BT_Nang_goc_ban;  
//	else
//  {
//		BT_Nang_goc_ban_value = BienTroGocBanThoc_SUM/50;
//		BienTroGocBanThoc_Couter = 0;
//		BienTroGocBanThoc_SUM = 0;
//	}
//-------------------------	
//	if(BT_Dia_xoay_Couter++ < 50)	BT_Dia_xoay_SUM += BT_Dia_xoay;
//	else
//  {
//		BT_Dia_xoay_value = BT_Dia_xoay_SUM/50;
//		BT_Dia_xoay_Couter = 0;
//		BT_Dia_xoay_SUM = 0;
//	}
}

void test_xl()
{
        if(!TRIANGLE)
    {
        ROLE_HOT_BONG_BAT;
    }
    if(!X)
    {
        XL_HOT_BONG_HA_XUONG;
        XL_TRO_LUC_HA_BAT;
        delay_ms(500);
        XL_TRO_LUC_HA_TAT;
    }
}

void testtaygap(void)	
{
}
void testbanhxe()
{
            
}
//--------------------------- DIEU KHIEN CO CAU ---------------------------------------
void dieuKhienCoCau(void) 
{
    if (!X)
    {
        XL_HOT_BONG_HA_XUONG;
        XL_TRO_LUC_HA_BAT;
        delay_ms(200);
        XL_TRO_LUC_HA_TAT;

    }
    else if (!TRIANGLE)
    {
        XL_HOT_BONG_BAT_LEN;
    }
}
