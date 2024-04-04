//*****************************8 bien toan cuc *************************************
char bien_xl_hot_banh, bien_xl_nap_dan, bien_xl_kep_lua_13, bien_xl_lay_bong, bien_xl_kep_lua_24, bien_xl_tay_gap, bien_xl_keo_lua, bien_xoay_dong_co_nong_ban;

//--------------------------- LAZE SAN 2 DOC------------------------------------------
int san_2_1_d = 210,                san_2_2_d = 260;
int san_2_3_d = 310,                san_2_4_d = 360;
int san_2_5_d = 410,                san_2_6_d = 460;

void laze_san_2()
{
    if(abs(_robotIMUAngle) > 800)
    {
        if     (LAZEDOC_2[2] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[1])                 {ban_thoc = tocdo[0][0], ban_lep = tocdo[1][0], goc_xoay_thoc = gocxoay_thoc[SAN+2][1], goc_xoay_lep = gocxoay_lep[SAN+2][1];}              //vi tri 1
        else if(LAZEDOC_2[3] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[2])                 {ban_thoc = tocdo[0][1], ban_lep = tocdo[1][1], goc_xoay_thoc = gocxoay_thoc[SAN+2][2], goc_xoay_lep = gocxoay_lep[SAN+2][2];}
        else if(LAZEDOC_2[4] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[3])                 {ban_thoc = tocdo[0][2], ban_lep = tocdo[1][2], goc_xoay_thoc = gocxoay_thoc[SAN+2][3], goc_xoay_lep = gocxoay_lep[SAN+2][3];}
        else if(LAZEDOC_2[5] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[4])                 {ban_thoc = tocdo[0][3], ban_lep = tocdo[1][3], goc_xoay_thoc = gocxoay_thoc[SAN+2][4], goc_xoay_lep = gocxoay_lep[SAN+2][4];}
        else if(LAZEDOC_2[6] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[5])                 {ban_thoc = tocdo[0][4], ban_lep = tocdo[1][4], goc_xoay_thoc = gocxoay_thoc[SAN+2][5], goc_xoay_lep = gocxoay_lep[SAN+2][5];}
        else if(                                 lazeTruocValue > LAZEDOC_2[6])                 {ban_thoc = tocdo[0][5], ban_lep = tocdo[1][5], goc_xoay_thoc = gocxoay_thoc[SAN+2][6], goc_xoay_lep = gocxoay_lep[SAN+2][6];}              //vi tri 6
    }
    else
    {
        if(SAN == 1)
        {
            if     (LAZENGANG_2[SAN][2] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][1])       {ban_thoc = tocdo[0][0], ban_lep = tocdo[1][0], goc_xoay_thoc = gocxoay_thoc[SAN][1], goc_xoay_lep = gocxoay_lep[SAN][1], phe_thoc = giamphe[0][0], phe_lep = giamphe[1][0];}                //vi tri 1
            else if(LAZENGANG_2[SAN][3] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][2])       {ban_thoc = tocdo[0][1], ban_lep = tocdo[1][1], goc_xoay_thoc = gocxoay_thoc[SAN][2], goc_xoay_lep = gocxoay_lep[SAN][2], phe_thoc = giamphe[0][1], phe_lep = giamphe[1][1];}
            else if(LAZENGANG_2[SAN][4] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][3])       {ban_thoc = tocdo[0][2], ban_lep = tocdo[1][2], goc_xoay_thoc = gocxoay_thoc[SAN][3], goc_xoay_lep = gocxoay_lep[SAN][3], phe_thoc = giamphe[0][2], phe_lep = giamphe[1][2];}
            else if(LAZENGANG_2[SAN][5] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][4])       {ban_thoc = tocdo[0][3], ban_lep = tocdo[1][3], goc_xoay_thoc = gocxoay_thoc[SAN][4], goc_xoay_lep = gocxoay_lep[SAN][4], phe_thoc = giamphe[0][3], phe_lep = giamphe[1][3];}
            else if(LAZENGANG_2[SAN][6] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][5])       {ban_thoc = tocdo[0][4], ban_lep = tocdo[1][4], goc_xoay_thoc = gocxoay_thoc[SAN][5], goc_xoay_lep = gocxoay_lep[SAN][5], phe_thoc = giamphe[0][4], phe_lep = giamphe[1][4];}
            else if(                                          lazeNgangDoValue < LAZENGANG_2[SAN][6])       {ban_thoc = tocdo[0][5], ban_lep = tocdo[1][5], goc_xoay_thoc = gocxoay_thoc[SAN][6], goc_xoay_lep = gocxoay_lep[SAN][6], phe_thoc = giamphe[0][5], phe_lep = giamphe[1][5];}                //vi tri 6
        }
        else
        {
            if     (LAZENGANG_2[SAN][2] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][1])   {ban_thoc = tocdo[0][0], ban_lep = tocdo[1][0], goc_xoay_thoc = gocxoay_thoc[SAN][1], goc_xoay_lep = gocxoay_lep[SAN][1], phe_thoc = giamphe[0][0], phe_lep = giamphe[1][0];}                //vi tri 1
            else if(LAZENGANG_2[SAN][3] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][2])   {ban_thoc = tocdo[0][1], ban_lep = tocdo[1][1], goc_xoay_thoc = gocxoay_thoc[SAN][2], goc_xoay_lep = gocxoay_lep[SAN][2], phe_thoc = giamphe[0][1], phe_lep = giamphe[1][1];}
            else if(LAZENGANG_2[SAN][4] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][3])   {ban_thoc = tocdo[0][2], ban_lep = tocdo[1][2], goc_xoay_thoc = gocxoay_thoc[SAN][3], goc_xoay_lep = gocxoay_lep[SAN][3], phe_thoc = giamphe[0][2], phe_lep = giamphe[1][2];}
            else if(LAZENGANG_2[SAN][5] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][4])   {ban_thoc = tocdo[0][3], ban_lep = tocdo[1][3], goc_xoay_thoc = gocxoay_thoc[SAN][4], goc_xoay_lep = gocxoay_lep[SAN][4], phe_thoc = giamphe[0][3], phe_lep = giamphe[1][3];}
            else if(LAZENGANG_2[SAN][6] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][5])   {ban_thoc = tocdo[0][4], ban_lep = tocdo[1][4], goc_xoay_thoc = gocxoay_thoc[SAN][5], goc_xoay_lep = gocxoay_lep[SAN][5], phe_thoc = giamphe[0][4], phe_lep = giamphe[1][4];}
            else if(                                            lazeNgangXanhValue < LAZENGANG_2[SAN][6])   {ban_thoc = tocdo[0][5], ban_lep = tocdo[1][5], goc_xoay_thoc = gocxoay_thoc[SAN][6], goc_xoay_lep = gocxoay_lep[SAN][6], phe_thoc = giamphe[0][5], phe_lep = giamphe[1][5];}                //vi tri 6
        }
    }
}

void giu_Mam_Xoay()
{
    // if(BT_Dia_xoay_value < Min_BT_Xoay - 10 || BT_Dia_xoay_value > Max_BT_Xoay + 10)  {Mor_Dia_xoay = 2; return;}
    // if(abs(BT_Dia_xoay_value - taget_BT_Xoay) > 3)
    // {
    //     if(BT_Dia_xoay_value > taget_BT_Xoay) Mor_Dia_xoay_phai;
    //     else Mor_Dia_xoay_trai;
    //     speed_temp = (int)fabs(BT_Dia_xoay_value - taget_BT_Xoay)*max_speed/(Max_BT_Xoay - Min_BT_Xoay);
    //     if(speed_temp < 35) speed_temp = 35;
    //     Mor_Dia_xoay = speed_temp;
    // }
    // else Mor_Dia_xoay = 2;
}
//--------------------------- TEST CO CAU ------------------------------------------
void testDiaxoay() 
{
}

void testRulo()	{
    if(!SELECT) 
    {	
        bien_xoay_dong_co_nong_ban = ~bien_xoay_dong_co_nong_ban;
        while(!SELECT)  vTaskDelay(1);									
    }
    if(bien_xoay_dong_co_nong_ban == 0)		                Mor_xoay_phai = Mor_xoay_trai = 0;	
    else
    {
                                            Mor_xoay_phai = 254, Mor_xoay_phai_thuan;
                                            Mor_xoay_trai = 254, Mor_xoay_trai_thuan;
    }
}
//--------------------------------------------------------------------------------
void robotGamePadControl_s1(void) {
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
        if(robotIsRun()) robotRotateFree(-1.5,0,tocdo);
        //else robotRotateFree(-tocdoXoay,0);
                else {bit_khoa_ham_chay_thay_tuan = 1;setMotor(-toc_do_xoay_free,toc_do_xoay_free,-toc_do_xoay_free,toc_do_xoay_free);}
    }
    else if((RJOY_LR > 250) && L2)
    {
        if(robotIsRun()) robotRotateFree(1.5,0,tocdo);
        //else robotRotateFree(tocdoXoay,0);
                else {bit_khoa_ham_chay_thay_tuan = 1;setMotor(toc_do_xoay_free,-toc_do_xoay_free,toc_do_xoay_free,-toc_do_xoay_free);}
    }

    else setMotor(2,2,2,2);bit_khoa_ham_chay_thay_tuan = 0;robotRotateStop();
    }

void robotGamePadControl_s2(void) {
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
    if	   (!UP && DOWN && RIGHT && LEFT)   robotRun(1800, tocdo);
    else if(UP && !DOWN && RIGHT && LEFT)   robotRun(0, tocdo);
    else if(UP && DOWN && !RIGHT && LEFT)   robotRun(-900, tocdo);
    else if(UP && DOWN && RIGHT && !LEFT)   robotRun(900, tocdo);
    
    // else if(!UP && DOWN && !RIGHT && LEFT)  robotRun(450,tocdo);
    // else if(!UP && DOWN && RIGHT && !LEFT)  robotRun(-450,tocdo);
    // else if(UP && !DOWN && !RIGHT && LEFT)  robotRun(1350,tocdo);
    // else if(UP && !DOWN && RIGHT && !LEFT)  robotRun(-1350,tocdo);

    
    //-------------- Dang chay va Khong chay nua, chi xoay ----------------
    if(UP && DOWN && RIGHT && LEFT && !rJoy_LR && lJoy_LR  && robotIsRun()) robotStop(5);   

    //-------------- Xoay ----------------
    if(rJoy_LR) robotRotateStop();
    else if((RJOY_LR < 5) && L2)
    {
        if(robotIsRun()) robotRotateFree(-1.5,0,tocdo);
        //else robotRotateFree(-tocdoXoay,0);
                else {bit_khoa_ham_chay_thay_tuan = 1;setMotor(-toc_do_xoay_free,toc_do_xoay_free,-toc_do_xoay_free,toc_do_xoay_free);}
    }
    else if((RJOY_LR > 250) && L2)
    {
        if(robotIsRun()) robotRotateFree(1.5,0,tocdo);
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
    if(lazeTruocCouter++ < 100)	lazeTruoc_SUM += cam_bien_laze_truoc;  
    else
    {
        lazeTruocValue = lazeTruoc_SUM/100
        ;
        lazeTruocCouter = 0;
        lazeTruoc_SUM = 0;
    }
//------------------------
    if(lazeNgang_Counter_do++ < 50)	lazeNgang_SUM_do += cam_bien_laze_ngang_do;  
    else
    {
        lazeNgangDoValue = lazeNgang_SUM_do/50;
        lazeNgang_Counter_do = 0;
        lazeNgang_SUM_do = 0;
    }
//------------------------
    if(lazeNgang_Counter_xanh++ < 50)	lazeNgang_SUM_xanh += cam_bien_laze_ngang_xanh;  
    else
    {
        lazeNgangXanhValue = lazeNgang_SUM_xanh/50;
        lazeNgang_Counter_xanh = 0;
        lazeNgang_SUM_xanh = 0;
    }
//------------------------
//    if(BienTroGocBanThoc_Couter++ < 50)	BienTroGocBanThoc_SUM += BT_Nang_xoay_ban;  
//    else
//    {
//        BT_Nang_goc_ban_value = BienTroGocBanThoc_SUM/50;
//        BienTroGocBanThoc_Couter = 0;
//        BienTroGocBanThoc_SUM = 0;
//    }
//-------------------------	
    if(BT_Dia_xoay_Couter++ < 50)	BT_Dia_xoay_SUM += BT_Dia_xoay;
    else
{
        BT_Dia_xoay_value = BT_Dia_xoay_SUM/50;
        BT_Dia_xoay_Couter = 0;
        BT_Dia_xoay_SUM = 0;
    }
}



//--------------------------- TEST CYLINDER -----------------------------------------
void test_cylinder(void) 
{
    
}

//--------------------------- TEST CO CAU LAY VA BAN THOC --------------------------------------- L1 ---------------------------------------
void tesLayvaBanthoc(void) {
    if(!L1 & !TRIANGLE) 
    {	
        bien_xl_hot_banh = ~bien_xl_hot_banh; 
        while(!L1 & !TRIANGLE)  vTaskDelay(1);									
    }
    if(bien_xl_hot_banh == 0)			        HOT_BANH_OFF;
    else										HOT_BANH_ON;
//-------------------------------------------------------------------------------------
    if(!L1 & !O)
    {
        bien_xl_nap_dan = ~bien_xl_nap_dan;                                             //OK
        while(!L1 & !O)  vTaskDelay(1);									
    }
    if(bien_xl_nap_dan == 0)			        NAP_DAN_OFF;
    else						        		NAP_DAN_ON;
////***********************************************************************************
    if(!L1 & !SQUARE) 	
    {
        bien_xl_lay_bong = ~bien_xl_lay_bong; 
        while(!L1 & !SQUARE)  vTaskDelay(1);									
    }
    if(bien_xl_lay_bong == 0)				    LAY_BONG_OFF;
    else									    LAY_BONG_ON;
//***********************************************************************************    
    if(!L1 & !X) 
    {	
        bien_xoay_dong_co_nong_ban = ~bien_xoay_dong_co_nong_ban;
        while(!L1 & !X)  vTaskDelay(1);									
    }
    if(bien_xoay_dong_co_nong_ban == 0)		                Mor_xoay_phai = Mor_xoay_trai = 0;	
    else
    {
//											Mor_xoay_phai = 250, Mor_xoay_phai_thuan;
                                            Mor_xoay_trai = 150, Mor_xoay_trai_thuan;
    }
}

//--------------------------- TEST CO CAU LAY LUA --------------------------------------- L2 ---------------------------------------
void testLaylua(void) 
{
//***********************************************************************************
    if(!L2 & !TRIANGLE)                                                                             
    {	
        KEP_LUA_13_KEP;
        KEP_LUA_24_KEP;
    }
//***********************************************************************************
    if(!L2 & !SQUARE)                                                                         
    {
        KEP_LUA_13_NHA;
    }
//***********************************************************************************
    if(!L2 & !O)
    {
        KEP_LUA_24_NHA;
    }
//***********************************************************************************
    if(!L2 & !X) 
    {	
        bien_xl_keo_lua = ~bien_xl_keo_lua; 
        while(!L2 & !SQUARE)  vTaskDelay(1);									
    }
    if(bien_xl_keo_lua == 0)				    KEO_LUA_XUONG;
    else										KEO_LUA_LEN;
    
}

void testBT()
{
    i = 100;
    if(L1 && !O)                   Mor_Dia_xoay = i, Mor_Dia_xoay_phai;
    else if(L1 && !SQUARE)         Mor_Dia_xoay = i, Mor_Dia_xoay_trai;
    else                           Mor_Dia_xoay = 0;
}

void testcambien()
{
    
}
void chuanbicocau()
{
    TAY_GAP_XUONG;
    KEO_LUA_XUONG;
}


void LayvaBanthoc()
{
    i = 100;
    laze_san_2();
    if(!L1 & !TRIANGLE) 
    {
        HOT_BANH_ON;
        KEO_LUA_LEN;
        TAY_GAP_LEN;
    }
//-----------------------------BAN THOC--------------------------------------------------------
    if(!L1 & !SQUARE)
    {
        NAP_DAN_ON;
        LAY_BONG_ON;
        HOT_BANH_OFF;
        
        Mor_giam_phe = phe_thoc, Mor_giam_phe_thuan;
        Mor_xoay_trai = ban_thoc, Mor_xoay_trai_thuan;
        Mor_xoay_phai = ban_thoc, Mor_xoay_phai_thuan;
        
        if(BT_Dia_xoay_value > goc_xoay_thoc)
        {
            Mor_Dia_xoay = i, Mor_Dia_xoay_phai;
            while(BT_Dia_xoay_value > goc_xoay_thoc){if(wantExit())break;}
            Mor_Dia_xoay = 0;
        }
        else if(BT_Dia_xoay_value < goc_xoay_thoc)
        {
            Mor_Dia_xoay = i, Mor_Dia_xoay_trai;
            while(BT_Dia_xoay_value < goc_xoay_thoc){if(wantExit())break;}
            Mor_Dia_xoay = 0;
        }
        else Mor_Dia_xoay = 0;

        delay_ms(2000);
        NAP_DAN_OFF;
        LAY_BONG_OFF;
        HOT_BANH_ON;
        Mor_xoay_trai = Mor_xoay_phai = Mor_giam_phe = 0;
    }
    
//-----------------------------BAN LEP--------------------------------------------------------
    if(!L1 & !O) 	
    {
        NAP_DAN_ON;
        LAY_BONG_ON;
        HOT_BANH_OFF;
        
        Mor_giam_phe = phe_lep, Mor_giam_phe_nghich;
        Mor_xoay_trai = ban_lep, Mor_xoay_trai_thuan;
        Mor_xoay_phai = ban_lep, Mor_xoay_phai_thuan;
        
        if(BT_Dia_xoay_value > goc_xoay_lep)
        {
            Mor_Dia_xoay = i, Mor_Dia_xoay_phai;
            while(BT_Dia_xoay_value > goc_xoay_lep){if(wantExit())break;}
            Mor_Dia_xoay = 0;
        }
        else if(BT_Dia_xoay_value < goc_xoay_lep)
        {
            Mor_Dia_xoay = i, Mor_Dia_xoay_trai;
            while(BT_Dia_xoay_value < goc_xoay_lep){if(wantExit())break;}
            Mor_Dia_xoay = 0;
        }
        else Mor_Dia_xoay = 0;

        delay_ms(2000);
        NAP_DAN_OFF;
        LAY_BONG_OFF;
        HOT_BANH_ON;
        Mor_xoay_trai = Mor_xoay_phai = Mor_giam_phe = 0;
    }
//***********************************************************************************    
}

void testbanhxe()	
{
    if(abs(_robotIMUAngle) > 800)
    {
        if(L1 && !TRIANGLE)
        {
            RESET_ENCODER();
            robotRun(1800, 20);
            while(ENCODER_TONG() < 50){}
        }
        if (L1 && !X)
        {
            RESET_ENCODER();
            robotRun(0, 20);
            while(ENCODER_TONG() < 50){}
        }
        if(L1 && !SQUARE)
        {
            RESET_ENCODER();
            robotRun(900, 20);
            while(ENCODER_TONG() < 50){}
        }
        if (L1 && !O)
        {
            RESET_ENCODER();
            robotRun(-900, 20);
            while(ENCODER_TONG() < 50){}
        }
    }
    else
    {
        if(L1 && !TRIANGLE)
        {
            RESET_ENCODER();
            robotRun(0, 20);
            while(ENCODER_TONG() < 50){}
        }
        if (L1 && !X)
        {
            RESET_ENCODER();
            robotRun(1800, 20);
            while(ENCODER_TONG() < 50){}
        }
        if(L1 && !SQUARE)
        {
            RESET_ENCODER();
            robotRun(-900, 20);
            while(ENCODER_TONG() < 50){}
        }
        if (L1 && !O)
        {
            RESET_ENCODER();
            robotRun(900, 20);
            while(ENCODER_TONG() < 50){}
        }
    }
}

//--------------------------- DIEU KHIEN CO CAU ---------------------------------------
void dieuKhienCoCau(void) 
{
    testBT();
    // testbanhxe();
    LayvaBanthoc();

}

