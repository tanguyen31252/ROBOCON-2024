//*****************************8 bien toan cuc *************************************
char bien_xl_hot_banh, bien_xl_nap_dan, bien_xl_kep_lua_13, bien_xl_lay_bong, bien_xl_kep_lua_24, bien_xl_tay_gap, bien_xl_keo_lua, bien_xoay_dong_co_nong_ban;

void laze_san_2()
{
    if (SAN == 0) // san xanh
    {
        if (lazePhaiValue < LAZE_THANH_NGOAI_2[SAN][1] + 25 && lazePhaiValue > LAZE_THANH_NGOAI_2[SAN][1] - 25)
        {
            vi_tri_laze = 1, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazePhaiValue < LAZE_THANH_NGOAI_2[SAN][2] + 25 && lazePhaiValue > LAZE_THANH_NGOAI_2[SAN][2] - 25)
        {
            vi_tri_laze = 2, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazePhaiValue < LAZE_THANH_NGOAI_2[SAN][3] + 25 && lazePhaiValue > LAZE_THANH_NGOAI_2[SAN][3] - 25)
        {
            vi_tri_laze = 3, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazePhaiValue < LAZE_THANH_NGOAI_2[SAN][4] + 25 && lazePhaiValue > LAZE_THANH_NGOAI_2[SAN][4] - 25)
        {
            vi_tri_laze = 4, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazePhaiValue < LAZE_THANH_NGOAI_2[SAN][5] + 25 && lazePhaiValue > LAZE_THANH_NGOAI_2[SAN][5] - 25)
        {
            vi_tri_laze = 5, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazePhaiValue < LAZE_THANH_NGOAI_2[SAN][6] + 25 && lazePhaiValue > LAZE_THANH_NGOAI_2[SAN][6] - 25)
        {
            vi_tri_laze = 6, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
    }
    else        //san do
    {
        if (lazeTraiValue < LAZE_THANH_NGOAI_2[SAN][1] - 25 && lazeTraiValue > LAZE_THANH_NGOAI_2[SAN][1])
        {
            vi_tri_laze = 1, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazeTraiValue < LAZE_THANH_NGOAI_2[SAN][2] - 25 && lazeTraiValue > LAZE_THANH_NGOAI_2[SAN][2])
        {
            vi_tri_laze = 2, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazeTraiValue < LAZE_THANH_NGOAI_2[SAN][3] - 25 && lazePhaiValue > LAZE_THANH_NGOAI_2[SAN][1])
        {
            vi_tri_laze = 3, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazeTraiValue < LAZE_THANH_NGOAI_2[SAN][4] - 25 && lazeTraiValue > LAZE_THANH_NGOAI_2[SAN][1])
        {
            vi_tri_laze = 4, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazeTraiValue < LAZE_THANH_NGOAI_2[SAN][5] - 25 && lazeTraiValue > LAZE_THANH_NGOAI_2[SAN][1])
        {
            vi_tri_laze = 5, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
        if (lazeTraiValue < LAZE_THANH_NGOAI_2[SAN][6] - 25 && lazeTraiValue > LAZE_THANH_NGOAI_2[SAN][1])
        {
            vi_tri_laze = 6, goc_xoay_de = XOAY_DE[SAN][vi_tri_laze], toc_do_ban = TOC_DO_BAN[SAN][vi_tri_laze];
        }
    }
}
void do_line(int speed)
{

    if (!CB_Line_P1 && !CB_Line_P2)
        lech_huong = -2;
    else if (!CB_Line_P1)
        lech_huong = -3;
    else if (!CB_Line_P2 && !CB_Line_P3)
        lech_huong = 0;
    else if (!CB_Line_P2)
        lech_huong = -1;

    else if (!CB_Line_P3 && !CB_Line_P4)
        lech_huong = 2;
    else if (!CB_Line_P3)
        lech_huong = 1;
    else if (!CB_Line_P4)
        lech_huong = 3;

    if (!CB_Line_T1 && !CB_Line_T2)
        lech_huong_xoay = -2;
    else if (!CB_Line_T1)
        lech_huong_xoay = -3;
    else if (!CB_Line_T2 && !CB_Line_T3)
        lech_huong_xoay = 0;
    else if (!CB_Line_T2)
        lech_huong_xoay = -1;

    else if (!CB_Line_T3 && !CB_Line_T4)
        lech_huong_xoay = 2;
    else if (!CB_Line_T3)
        lech_huong_xoay = 1;
    else if (!CB_Line_T4)
        lech_huong_xoay = 3;

    if (speed < 0)
    {
        goc_chay = -900 - lech_huong * 30;
        goc_xoay = 0 - lech_huong_xoay * 0.1;
        robotRun(goc_chay, abs(speed));
        if (lech_huong_xoay)
            robotRotateFree(goc_xoay, 2);
        else
            robotRotateStop(0);
    }

    else
    {
        goc_chay = -900 - lech_huong_xoay * 30;
        goc_xoay = 0 - lech_huong * 0.1;

        robotRun(-goc_chay, abs(speed));
        if (lech_huong_xoay)
            robotRotateFree(-goc_xoay, 1);
        else
            robotRotateStop(0);
    }
}

void giu_nong_xoay()
{
}
//--------------------------- TEST CO CAU ------------------------------------------
void testDiaxoay()
{
}

//--------------------------------------------------------------------------------
void robotGamePadControl(void)
{
    int tocdo = 15, toc_do_xoay_free = 0;
    float tocdoXoay = 0;
    int rJoy_LR = (RJOY_LR >= 5 && RJOY_LR <= 250) ? 1 : 0;
    int lJoy_LR = (LJOY_LR >= 5 && LJOY_LR <= 250) ? 1 : 0;

    if (UP && DOWN && RIGHT && LEFT && rJoy_LR && lJoy_LR && O)
    { // Khong dieu khien

        robotStop(2); // truot banh

        return;
    }
    /*_____________________________//___________________________*/

    /********************** TOC DO ****************************/
    /*_____________________________//___________________________*/
    if (!L1)
        tocdo = 50, tocdoXoay = 20, toc_do_xoay_free = 20;
    else if (!L2)
        tocdo = 10, tocdoXoay = 0.5, toc_do_xoay_free = 7;
    else
        tocdo = 30, tocdoXoay = 0.05, toc_do_xoay_free = 10; // sua toc_do_xoay_free tu 7 len 10
                                                             // sua tocdoXoay tu 0.05 len 5

    //--------- chay cac huong -----------
    if (!UP && DOWN && RIGHT && LEFT)
        robotRun(0, tocdo);
    else if (UP && !DOWN && RIGHT && LEFT)
        robotRun(1800, tocdo);
    else if (UP && DOWN && !RIGHT && LEFT)
        robotRun(900, tocdo);
    else if (UP && DOWN && RIGHT && !LEFT)
        robotRun(-900, tocdo);

    else if (!UP && DOWN && !RIGHT && LEFT)
        robotRun(450, tocdo);
    else if (!UP && DOWN && RIGHT && !LEFT)
        robotRun(-450, tocdo);
    else if (UP && !DOWN && !RIGHT && LEFT)
        robotRun(1350, tocdo);
    else if (UP && !DOWN && RIGHT && !LEFT)
        robotRun(-1350, tocdo);

    //-------------- Dang chay va Khong chay nua, chi xoay ----------------
    if (UP && DOWN && RIGHT && LEFT && !rJoy_LR && lJoy_LR && robotIsRun())
        robotStop(5);

    //-------------- Xoay ----------------
    if (rJoy_LR)
        robotRotateStop();
    else if ((RJOY_LR < 5) && L2)
    {
        if (robotIsRun())
            robotRotateFree(-1.5, 0);
        // else robotRotateFree(-tocdoXoay,0);
        else
        {
            bit_khoa_ham_chay_thay_tuan = 1;
            setMotor(-toc_do_xoay_free, toc_do_xoay_free, -toc_do_xoay_free, toc_do_xoay_free);
        }
    }
    else if ((RJOY_LR > 250) && L2)
    {
        if (robotIsRun())
            robotRotateFree(1.5, 0);
        // else robotRotateFree(tocdoXoay,0);
        else
        {
            bit_khoa_ham_chay_thay_tuan = 1;
            setMotor(toc_do_xoay_free, -toc_do_xoay_free, toc_do_xoay_free, -toc_do_xoay_free);
        }
    }
    else
        setMotor(2, 2, 2, 2);
    bit_khoa_ham_chay_thay_tuan = 0;
    robotRotateStop();
}

//////-------------------------------------------------------------
void ADCValue_Control(void)
{
    static unsigned int lazeTruocCouter = 0, lazeTruoc_SUM = 0;
    static unsigned int lazeTraiCounter = 0, lazeTrai_SUM = 0;
    static unsigned int lazePhaiCounter = 0, lazePhai_SUM = 0;
    static unsigned int lazeSauCounter = 0, lazeSau_SUM = 0;
    //------------------------
    if (lazeTruocCouter++ < 150)
        lazeTruoc_SUM += cam_bien_laze_truoc;
    else
    {
        lazeTruocValue = lazeTruoc_SUM / 150;
        lazeTruocCouter = 0;
        lazeTruoc_SUM = 0;
    }
    //------------------------
    if (lazeTraiCounter++ < 150)
        lazeTrai_SUM += cam_bien_laze_trai;
    else
    {
        lazeTraiValue = lazeTrai_SUM / 150;
        lazeTraiCounter = 0;
        lazeTrai_SUM = 0;
    }
    //------------------------
    if (lazePhaiCounter++ < 150)
        lazePhai_SUM += cam_bien_laze_phai;
    else

    {
        lazePhaiValue = lazePhai_SUM / 150;
        lazePhaiCounter = 0;
        lazePhai_SUM = 0;
    }

    //------------------------
    if (lazeSauCounter++ < 150)
        lazeSau_SUM += cam_bien_laze_sau;
    else
    {
        lazeSauValue = lazeSau_SUM / 150;
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

void line_ban_bong()
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
    XL_KEP_BONG_NHA;
}

void chay_line()
{
    laze_san_2();
    if (!SQUARE && L1)
    {
        do_line(-25);
    }
    else if (!O && L1)
    {
        do_line(25);
    }
}

void LayvaBan()
{
    laze_san_2();
    if (!TRIANGLE && R1) // lay bong GIUA
    {
        XL_THUC_XUONG;
        delay_ms(500);
        // XL_KEP_BONG_NHA;
        // delay_ms(100);
        XL_KEP_BONG_KEP;
        delay_ms(100);
        XL_THUC_LEN;
        delay_ms(400);
        XL_LAY_BONG_SAU_DONG;
        Mor_Rulo_Duoi = toc_do_ban;
        Mor_Rulo_Tren = 45;
        // robotRotate(goc_xoay_de, 0.5, 0);
        // while(robotFixAngle()){if(wantExit())break;}
    }
    if(!X && R1)
    {
        XL_LAY_BONG_GIUA_MO;
        delay_ms(200);
        XL_THUC_XUONG;
        delay_ms(500);
        // XL_KEP_BONG_KEP;
        // delay_ms(100);
        XL_THUC_LEN;
        delay_ms(500);
        XL_LAY_BONG_SAU_DONG;
        XL_LAY_BONG_GIUA_DONG;
        Mor_Rulo_Duoi = toc_do_ban;
        Mor_Rulo_Tren = 45;
        // robotRotate(goc_xoay_de, 0.5, 0);
        // while(robotFixAngle()){if(wantExit())break;}
    }
    if(!X && !R1)
    {
        XL_KEP_BONG_NHA;
        delay_ms(1000);
        XL_KEP_BONG_KEP;
        delay_ms(100);
        XL_LAY_BONG_SAU_MO;
        Mor_Rulo_Duoi = 0;
        Mor_Rulo_Tren = 0;
        // robotRotate(0, 0.5, 0);
        // while(robotFixAngle()){if(wantExit())break;}

    }
}

void testbanhxe()
{
}
void dieuKhienCoCau(void)
{
    if (san == 2)
    {
        chay_line();
        LayvaBan();
    }
}
