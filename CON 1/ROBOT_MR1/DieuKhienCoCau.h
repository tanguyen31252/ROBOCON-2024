//*****************************8 bien toan cuc *************************************
char bien_xl_hot_banh, bien_xl_nap_dan, bien_xl_kep_lua_13, bien_xl_lay_bong, bien_xl_kep_lua_24, bien_xl_tay_gap, bien_xl_keo_lua, bien_xoay_dong_co_nong_ban;

//--------------------------- LAZE SAN 2 DOC------------------------------------------
int san_2_1_d = 210,                san_2_2_d = 260;
int san_2_3_d = 310,                san_2_4_d = 360;
int san_2_5_d = 410,                san_2_6_d = 460;


void laze_san_2()
{
    if(abs(_robotIMUAngle) > 650)
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
            if     (LAZENGANG_2[SAN][5] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][6])       {vi_tri_laze =6,ban_thoc = tocdo[0][0], ban_lep = tocdo[1][0], goc_xoay_thoc = gocxoay_thoc[SAN][6], goc_xoay_lep = gocxoay_lep[SAN][6], phe_thoc = giamphe[0][0], phe_lep = giamphe[1][0];}                //vi tri 1
            else if(LAZENGANG_2[SAN][4] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][5])       {vi_tri_laze =5,ban_thoc = tocdo[0][1], ban_lep = tocdo[1][1], goc_xoay_thoc = gocxoay_thoc[SAN][5], goc_xoay_lep = gocxoay_lep[SAN][5], phe_thoc = giamphe[0][1], phe_lep = giamphe[1][1];}
            else if(LAZENGANG_2[SAN][3] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][4])       {vi_tri_laze =4,ban_thoc = tocdo[0][2], ban_lep = tocdo[1][2], goc_xoay_thoc = gocxoay_thoc[SAN][4], goc_xoay_lep = gocxoay_lep[SAN][4], phe_thoc = giamphe[0][2], phe_lep = giamphe[1][2];}
            else if(LAZENGANG_2[SAN][2] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][3])       {vi_tri_laze =3,ban_thoc = tocdo[0][3], ban_lep = tocdo[1][3], goc_xoay_thoc = gocxoay_thoc[SAN][3], goc_xoay_lep = gocxoay_lep[SAN][3], phe_thoc = giamphe[0][3], phe_lep = giamphe[1][3];}
            else if(LAZENGANG_2[SAN][1] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][2])       {vi_tri_laze =2,ban_thoc = tocdo[0][4], ban_lep = tocdo[1][4], goc_xoay_thoc = gocxoay_thoc[SAN][2], goc_xoay_lep = gocxoay_lep[SAN][2], phe_thoc = giamphe[0][4], phe_lep = giamphe[1][4];}
            else if(                                       lazePhaiValue < LAZENGANG_2[SAN][1])       {vi_tri_laze =1,ban_thoc = tocdo[0][5], ban_lep = tocdo[1][5], goc_xoay_thoc = gocxoay_thoc[SAN][1], goc_xoay_lep = gocxoay_lep[SAN][1], phe_thoc = giamphe[0][5], phe_lep = giamphe[1][5];}                //vi tri 6
        }
        else
        {
            if     (LAZENGANG_2[SAN][2] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][1])       {ban_thoc = tocdo[0][0], ban_lep = tocdo[1][0], goc_xoay_thoc = gocxoay_thoc[SAN][1], goc_xoay_lep = gocxoay_lep[SAN][1], phe_thoc = giamphe[0][0], phe_lep = giamphe[1][0];}                //vi tri 1
            else if(LAZENGANG_2[SAN][3] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][2])       {ban_thoc = tocdo[0][1], ban_lep = tocdo[1][1], goc_xoay_thoc = gocxoay_thoc[SAN][2], goc_xoay_lep = gocxoay_lep[SAN][2], phe_thoc = giamphe[0][1], phe_lep = giamphe[1][1];}
            else if(LAZENGANG_2[SAN][4] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][3])       {ban_thoc = tocdo[0][2], ban_lep = tocdo[1][2], goc_xoay_thoc = gocxoay_thoc[SAN][3], goc_xoay_lep = gocxoay_lep[SAN][3], phe_thoc = giamphe[0][2], phe_lep = giamphe[1][2];}
            else if(LAZENGANG_2[SAN][5] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][4])       {ban_thoc = tocdo[0][3], ban_lep = tocdo[1][3], goc_xoay_thoc = gocxoay_thoc[SAN][4], goc_xoay_lep = gocxoay_lep[SAN][4], phe_thoc = giamphe[0][3], phe_lep = giamphe[1][3];}
            else if(LAZENGANG_2[SAN][6] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][5])       {ban_thoc = tocdo[0][4], ban_lep = tocdo[1][4], goc_xoay_thoc = gocxoay_thoc[SAN][5], goc_xoay_lep = gocxoay_lep[SAN][5], phe_thoc = giamphe[0][4], phe_lep = giamphe[1][4];}
            else if(                                       lazePhaiValue < LAZENGANG_2[SAN][6])       {ban_thoc = tocdo[0][5], ban_lep = tocdo[1][5], goc_xoay_thoc = gocxoay_thoc[SAN][6], goc_xoay_lep = gocxoay_lep[SAN][6], phe_thoc = giamphe[0][5], phe_lep = giamphe[1][5];}                //vi tri 6
        }
    }
}

void giu_nong_xoay()
{
    // i=100;
    // if(BT_Dia_xoay_value > 450)
    // {
    //     Mor_Dia_xoay = i, Mor_Dia_xoay_phai;
    //     while(BT_Dia_xoay_value > 450){if(wantExit())break;}
    //     Mor_Dia_xoay = 0;
    // }
    // else if(BT_Dia_xoay_value < 450)
    // {
    //     Mor_Dia_xoay = i, Mor_Dia_xoay_trai;
    //     while(BT_Dia_xoay_value < 450){if(wantExit())break;}
    //     Mor_Dia_xoay = 0;
    // }
    // else Mor_Dia_xoay = 0;

}
//--------------------------- TEST CO CAU ------------------------------------------
void testDiaxoay() 
{
}

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
        if(robotIsRun()) robotRotateFree(-1.5,0);
        //else robotRotateFree(-tocdoXoay,0);
                else {bit_khoa_ham_chay_thay_tuan = 1;setMotor(-toc_do_xoay_free,toc_do_xoay_free,-toc_do_xoay_free,toc_do_xoay_free);}
    }
    else if((RJOY_LR > 250) && L2)
    {
        if(robotIsRun()) robotRotateFree(1.5,0);
        //else robotRotateFree(tocdoXoay,0);
                else {bit_khoa_ham_chay_thay_tuan = 1;setMotor(toc_do_xoay_free,-toc_do_xoay_free,toc_do_xoay_free,-toc_do_xoay_free);}
    }

    else setMotor(2,2,2,2);bit_khoa_ham_chay_thay_tuan = 0;robotRotateStop();
    }

//////-------------------------------------------------------------	
void ADCValue_Control(void)
{
    static unsigned int lazeTruocCouter = 0, lazeTruoc_SUM  = 0;
    static unsigned int lazeTraiCounter = 0, lazeTrai_SUM   = 0;
    static unsigned int lazePhaiCounter = 0, lazePhai_SUM   = 0;
    static unsigned int lazeSauCounter  = 0, lazeSau_SUM    = 0;
//------------------------	
    if(lazeTruocCouter++ < 100)	lazeTruoc_SUM += cam_bien_laze_truoc;  
    else
    {
        lazeTruocValue = lazeTruoc_SUM/100;
        lazeTruocCouter = 0;
        lazeTruoc_SUM = 0;
    }
//------------------------
    if(lazeTraiCounter++ < 50)	lazeTrai_SUM += cam_bien_laze_trai;  
    else
    {
        lazeTraiValue = lazeTrai_SUM/50;
        lazeTraiCounter = 0;
        lazeTrai_SUM = 0;
    }
//------------------------
    if(lazePhaiCounter++ < 50)	lazePhai_SUM += cam_bien_laze_phai;  
    else
    {
        lazePhaiValue = lazePhai_SUM/50;
        lazePhaiCounter = 0;
        lazePhai_SUM = 0;
    }

//------------------------
    if(lazeSauCounter++ < 50)	lazeSau_SUM += cam_bien_laze_sau;  
    else
    {
        lazeSauValue = lazeSau_SUM/50;
        lazeSauCounter = 0;
        lazeSau_SUM = 0;
    }
}



//--------------------------- TEST CYLINDER -----------------------------------------
void test_cylinder(void) 
{
    
}

//--------------------------- TEST CO CAU LAY VA BAN THOC --------------------------------------- L1 ---------------------------------------
void tesLayvaBanthoc(void) 
{
    
}

//--------------------------- TEST CO CAU LAY LUA --------------------------------------- L2 ---------------------------------------
void testLaylua(void) 
{
    
}

void testBT()
{
    
}

void testcambien()
{
    
}
void chuanbicocau()
{
    XL_DAY_BAT;
    XL_KEP_LUA_DUOI_NHA;
    XL_KEP_LUA_TREN_NHA;
}


void LayvaBanthoc()
{
//     i = 100;
//     laze_san_2();
//     if(!L1 & !TRIANGLE) 
//     {
//         HOT_BANH_ON;
//         KEO_LUA_LEN;
//         TAY_GAP_LEN;
//     }
// //-----------------------------BAN THOC--------------------------------------------------------
//     if(!L1 & !SQUARE)
//     {
//         NAP_DAN_ON;
//         LAY_BONG_ON;
//         HOT_BANH_OFF;
        
//         Mor_giam_phe = phe_thoc, Mor_giam_phe_thuan;
//         Mor_xoay_trai = ban_thoc, Mor_xoay_trai_thuan;
//         Mor_xoay_phai = ban_thoc, Mor_xoay_phai_thuan;
        
//         if(BT_Dia_xoay_value > goc_xoay_thoc)
//         {
//             Mor_Dia_xoay = i, Mor_Dia_xoay_phai;
//             while(BT_Dia_xoay_value > goc_xoay_thoc+22){if(wantExit())break;}
//             Mor_Dia_xoay = 0;
//         }
//         else if(BT_Dia_xoay_value < goc_xoay_thoc)
//         {
//             Mor_Dia_xoay = i, Mor_Dia_xoay_trai;
//             while(BT_Dia_xoay_value < goc_xoay_thoc-22){if(wantExit())break;}
//             Mor_Dia_xoay = 0;
//         }
//         else Mor_Dia_xoay = 0;

//         delay_ms(1000);
//         NAP_DAN_OFF;
//         LAY_BONG_OFF;
//         HOT_BANH_ON;
//         Mor_xoay_trai = Mor_xoay_phai = Mor_giam_phe = 0;
//         giu_nong_xoay();
//     }
    
// //-----------------------------BAN LEP--------------------------------------------------------
//     if(!L1 & !O) 	
//     {
//         NAP_DAN_ON;
//         LAY_BONG_ON;
//         HOT_BANH_OFF;
        
//         Mor_giam_phe = phe_lep, Mor_giam_phe_nghich;
//         Mor_xoay_trai = ban_lep, Mor_xoay_trai_thuan;
//         Mor_xoay_phai = ban_lep, Mor_xoay_phai_thuan;
        
//         if(BT_Dia_xoay_value > goc_xoay_lep)
//         {
//             Mor_Dia_xoay = i, Mor_Dia_xoay_phai;
//             while(BT_Dia_xoay_value > goc_xoay_lep+22){if(wantExit())break;}
//             Mor_Dia_xoay = 0;
//         }
//         else if(BT_Dia_xoay_value < goc_xoay_lep)
//         {
//             Mor_Dia_xoay = i, Mor_Dia_xoay_trai;
//             while(BT_Dia_xoay_value < goc_xoay_lep-22){if(wantExit())break;}
//             Mor_Dia_xoay = 0;
//         }
//         else Mor_Dia_xoay = 0;

//         delay_ms(1000);
//         NAP_DAN_OFF;
//         LAY_BONG_OFF;
//         HOT_BANH_ON;
//         Mor_xoay_trai = Mor_xoay_phai = Mor_giam_phe = 0;
//         giu_nong_xoay();
//     }
// //***********************************************************************************    
}

void testbanhxe()	
{
    i = 100;
    if(!TRIANGLE)
    {
        XL_DAY_LUA_BAT;
    }
    else if(!X)
    {
        XL_DAY_LUA_TAT;
    }
    else if(!SQUARE)
    {
        XL_THA_LUA_BAT;
        XL_DAY_LUA_TAT;
        for (i =0 ; i < 100;i++)
        {
            while (CB_NANG_HA_LUA == 1)
            {

            }
        }   
        XL_THA_LUA_TAT;
    }
    else if(!O)
    {
        
    }
    else Mor_Rulo_Duoi = Mor_Rulo_Tren = 0;
}

//--------------------------- DIEU KHIEN CO CAU ---------------------------------------
void dieuKhienCoCau(void) 
{
    // testBT();
    testbanhxe();
    // LayvaBanthoc();

}

