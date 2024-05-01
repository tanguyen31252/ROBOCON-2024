//*****************************8 bien toan cuc *************************************
char bien_xl_hot_banh, bien_xl_nap_dan, bien_xl_kep_lua_13, bien_xl_lay_bong, bien_xl_kep_lua_24, bien_xl_tay_gap, bien_xl_keo_lua, bien_xoay_dong_co_nong_ban;

//--------------------------- LAZE SAN 2 DOC------------------------------------------
int san_2_1_d = 210, san_2_2_d = 260;
int san_2_3_d = 310, san_2_4_d = 360;
int san_2_5_d = 410, san_2_6_d = 460;

void laze_san_2()
{
    if (abs(_robotIMUAngle) > 650)
    {
        if (LAZEDOC_2[2] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[1])
        {
            ban_thoc = tocdo[0][0], ban_lep = tocdo[1][0], goc_xoay_thoc = gocxoay_thoc[SAN + 2][1], goc_xoay_lep = gocxoay_lep[SAN + 2][1];
        } // vi tri 1
        else if (LAZEDOC_2[3] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[2])
        {
            ban_thoc = tocdo[0][1], ban_lep = tocdo[1][1], goc_xoay_thoc = gocxoay_thoc[SAN + 2][2], goc_xoay_lep = gocxoay_lep[SAN + 2][2];
        }
        else if (LAZEDOC_2[4] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[3])
        {
            ban_thoc = tocdo[0][2], ban_lep = tocdo[1][2], goc_xoay_thoc = gocxoay_thoc[SAN + 2][3], goc_xoay_lep = gocxoay_lep[SAN + 2][3];
        }
        else if (LAZEDOC_2[5] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[4])
        {
            ban_thoc = tocdo[0][3], ban_lep = tocdo[1][3], goc_xoay_thoc = gocxoay_thoc[SAN + 2][4], goc_xoay_lep = gocxoay_lep[SAN + 2][4];
        }
        else if (LAZEDOC_2[6] > lazeTruocValue && lazeTruocValue > LAZEDOC_2[5])
        {
            ban_thoc = tocdo[0][4], ban_lep = tocdo[1][4], goc_xoay_thoc = gocxoay_thoc[SAN + 2][5], goc_xoay_lep = gocxoay_lep[SAN + 2][5];
        }
        else if (lazeTruocValue > LAZEDOC_2[6])
        {
            ban_thoc = tocdo[0][5], ban_lep = tocdo[1][5], goc_xoay_thoc = gocxoay_thoc[SAN + 2][6], goc_xoay_lep = gocxoay_lep[SAN + 2][6];
        } // vi tri 6
    }
    else
    {
        if (SAN == 1)
        {
            if (LAZENGANG_2[SAN][5] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][6])
            {
                vi_tri_laze = 6, phe_thoc = giamphe[0][0], phe_lep = giamphe[1][0];
            } // vi tri 1
            else if (LAZENGANG_2[SAN][4] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][5])
            {
                vi_tri_laze = 5, ban_thoc = tocdo[0][1], ban_lep = tocdo[1][1], goc_xoay_thoc = gocxoay_thoc[SAN][5], goc_xoay_lep = gocxoay_lep[SAN][5], phe_thoc = giamphe[0][1], phe_lep = giamphe[1][1];
            }
            else if (LAZENGANG_2[SAN][3] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][4])
            {
                vi_tri_laze = 4, ban_thoc = tocdo[0][2], ban_lep = tocdo[1][2], goc_xoay_thoc = gocxoay_thoc[SAN][4], goc_xoay_lep = gocxoay_lep[SAN][4], phe_thoc = giamphe[0][2], phe_lep = giamphe[1][2];
            }
            else if (LAZENGANG_2[SAN][2] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][3])
            {
                vi_tri_laze = 3, ban_thoc = tocdo[0][3], ban_lep = tocdo[1][3], goc_xoay_thoc = gocxoay_thoc[SAN][3], goc_xoay_lep = gocxoay_lep[SAN][3], phe_thoc = giamphe[0][3], phe_lep = giamphe[1][3];
            }
            else if (LAZENGANG_2[SAN][1] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][2])
            {
                vi_tri_laze = 2, ban_thoc = tocdo[0][4], ban_lep = tocdo[1][4], goc_xoay_thoc = gocxoay_thoc[SAN][2], goc_xoay_lep = gocxoay_lep[SAN][2], phe_thoc = giamphe[0][4], phe_lep = giamphe[1][4];
            }
            else if (lazePhaiValue < LAZENGANG_2[SAN][1])
            {
                vi_tri_laze = 1, ban_thoc = tocdo[0][5], ban_lep = tocdo[1][5], goc_xoay_thoc = gocxoay_thoc[SAN][1], goc_xoay_lep = gocxoay_lep[SAN][1], phe_thoc = giamphe[0][5], phe_lep = giamphe[1][5];
            } // vi tri 6
        }
        else
        {
            if (LAZENGANG_2[SAN][2] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][1])
            {
                ban_thoc = tocdo[0][0], ban_lep = tocdo[1][0], goc_xoay_thoc = gocxoay_thoc[SAN][1], goc_xoay_lep = gocxoay_lep[SAN][1], phe_thoc = giamphe[0][0], phe_lep = giamphe[1][0];
            } // vi tri 1
            else if (LAZENGANG_2[SAN][3] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][2])
            {
                ban_thoc = tocdo[0][1], ban_lep = tocdo[1][1], goc_xoay_thoc = gocxoay_thoc[SAN][2], goc_xoay_lep = gocxoay_lep[SAN][2], phe_thoc = giamphe[0][1], phe_lep = giamphe[1][1];
            }
            else if (LAZENGANG_2[SAN][4] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][3])
            {
                ban_thoc = tocdo[0][2], ban_lep = tocdo[1][2], goc_xoay_thoc = gocxoay_thoc[SAN][3], goc_xoay_lep = gocxoay_lep[SAN][3], phe_thoc = giamphe[0][2], phe_lep = giamphe[1][2];
            }
            else if (LAZENGANG_2[SAN][5] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][4])
            {
                ban_thoc = tocdo[0][3], ban_lep = tocdo[1][3], goc_xoay_thoc = gocxoay_thoc[SAN][4], goc_xoay_lep = gocxoay_lep[SAN][4], phe_thoc = giamphe[0][3], phe_lep = giamphe[1][3];
            }
            else if (LAZENGANG_2[SAN][6] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][5])
            {
                ban_thoc = tocdo[0][4], ban_lep = tocdo[1][4], goc_xoay_thoc = gocxoay_thoc[SAN][5], goc_xoay_lep = gocxoay_lep[SAN][5], phe_thoc = giamphe[0][4], phe_lep = giamphe[1][4];
            }
            else if (lazePhaiValue < LAZENGANG_2[SAN][6])
            {
                ban_thoc = tocdo[0][5], ban_lep = tocdo[1][5], goc_xoay_thoc = gocxoay_thoc[SAN][6], goc_xoay_lep = gocxoay_lep[SAN][6], phe_thoc = giamphe[0][5], phe_lep = giamphe[1][5];
            } // vi tri 6
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
void dieuKhienCoCau(void)
{
    san = 2;
    while (san == 2)
    {
        // thong_so_hang_bong();
        // lấy bóng sau
        if (!R1 & !SQUARE)
        {
            XL_LAY_BONG_1_MO;
        }

        // lấy bóng trước
        else if (!R2 & !O)
        {
            XL_LAY_BONG_1_DONG;
        }

        else if (!R2 & !X)
        {
            XL_THUC_LEN;
        }
        else if (!R2 & !TRIANGLE)
        {
            XL_THUC_XUONG;
        }
        // bắn bóng sau
        else if (!L2 & !SQUARE)
        {
            XL_LAY_BONG_1_MO;
            delay_ms(500);
            XL_THUC_XUONG;
            delay_ms(500);
            XL_THUC_LEN;
            delay_ms(500);
            XL_LAY_BONG_1_DONG;
            delay_ms(500);
            XL_LAY_BONG_2_MO;
            delay_ms(500);
            Mor_Rulo_Duoi = 200;
            Mor_Rulo_Tren = 30;
            XL_KEP_BONG_NHA;
            delay_ms(700);
            XL_LAY_BONG_2_DONG;
            XL_LAY_BONG_1_DONG;
            delay_ms(1300);
            Mor_Rulo_Duoi = 0;
            Mor_Rulo_Tren = 0;
            XL_KEP_BONG_KEP;
        }

        // bắn bóng trước
        else if (!L2 & !O)
        {
            XL_LAY_BONG_1_DONG;
            delay_ms(500);
            XL_THUC_XUONG;
            delay_ms(500);
            XL_THUC_LEN;
            delay_ms(500);
            XL_LAY_BONG_1_DONG;
            delay_ms(500);
            XL_LAY_BONG_2_MO;
            delay_ms(500);
            Mor_Rulo_Duoi = 200;
            Mor_Rulo_Tren = 30;
            XL_KEP_BONG_NHA;
            delay_ms(700);
            XL_LAY_BONG_2_DONG;
            XL_LAY_BONG_1_DONG;
            delay_ms(1300);
            Mor_Rulo_Duoi = 0;
            Mor_Rulo_Tren = 0;
            XL_KEP_BONG_KEP;
        }
        // test
        else if (!L1 && !X)
        {
            XL_LAY_BONG_2_DONG;
            XL_KEP_BONG_KEP;
            Mor_Rulo_Tren = 0;
            Mor_Rulo_Duoi = 0;
        }
        else if (!R1 & !TRIANGLE)
        {
            XL_THA_LUA_TAT;
        }
        else if (!L1 & !SQUARE)
        {
            XL_DAY_LUA_BAT;
        }

        else if (!O)
        {
            do_line(10);
            vTaskDelay(1);
        }
        else if (!SQUARE)
        {
            do_line(-10);
            vTaskDelay(1);
        }
        // else if (!RIGHT)
        // {
        //     for (noise = 0; noise < 50; noise++)
        //     {
        //         while (CB_BONG_SAU_PHAI == 1 && CB_BONG_SAU_TRAI == 1 && CB_BONG_GIUA_PHAI == 1 && CB_BONG_GIUA_TRAI == 1)
        //         {
        //             bam_thanh_laze_doc(900, 10, 0, 2, 0, 60, 0, lazeTraiValue);
        //             if (lazeTruocValue > 0 && lazeTruocValue < 200)
        //             {
        //                 robotRotateFree(300, 0);
        //                 while (lazeTruocValue > 0 && lazeTruocValue < 220)
        //                 {
        //                     if (wantExit())
        //                         break;
        //                 }
        //             }
        //             else if (lazeTruocValue > 220 && lazeTruocValue < 360)
        //             {
        //                 robotRotateFree(550, 0);
        //                 while (lazeTruocValue > 0)
        //                 {
        //                     if (wantExit())
        //                         break;
        //                 }
        //             }
        //             else if (lazeTruocValue > 360)
        //             {
        //                 robotRotateFree(750, 0);
        //                 while (lazeTruocValue > 0)
        //                 {
        //                     if (wantExit())
        //                         break;
        //                 }
        //             }
        //             else
        //             {
        //             }
        //         }
        //     }
        // }
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
    if (lazeTruocCouter++ < 100)
        lazeTruoc_SUM += cam_bien_laze_truoc;
    else
    {
        lazeTruocValue = lazeTruoc_SUM / 100;
        lazeTruocCouter = 0;
        lazeTruoc_SUM = 0;
    }
    //------------------------
    if (lazeTraiCounter++ < 50)
        lazeTrai_SUM += cam_bien_laze_trai;
    else
    {
        lazeTraiValue = lazeTrai_SUM / 50;
        lazeTraiCounter = 0;
        lazeTrai_SUM = 0;
    }
    //------------------------
    if (lazePhaiCounter++ < 50)
        lazePhai_SUM += cam_bien_laze_phai;
    else

    {
        lazePhaiValue = lazePhai_SUM / 50;
        lazePhaiCounter = 0;
        lazePhai_SUM = 0;
    }

    //------------------------
    if (lazeSauCounter++ < 50)
        lazeSau_SUM += cam_bien_laze_sau;
    else
    {
        lazeSauValue = lazeSau_SUM / 50;
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
    for (noise = 0; noise < 50; noise++)
    {
        if ((CB_BONG_GIUA_PHAI == 1 && CB_BONG_GIUA_TRAI == 1 && CB_BONG_SAU_PHAI == 1 && CB_BONG_SAU_TRAI == 1) && lazePhaiValue > 50)
        {
            do_line(-20);
            vTaskDelay(1);
            while (CB_BONG_GIUA_PHAI == 0 && CB_BONG_GIUA_TRAI == 0 && CB_BONG_SAU_PHAI == 0 && CB_BONG_SAU_TRAI == 0)
            {
                if (lazeTraiValue > bong_mau[SAN][0])
                {
                    robotRotate(-800, 1.2, 0);
                }
            }
        }
    }
    robotStop(0);
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

void LayvaBan()
{
    // i = 100;
    // laze_san_2();
    // if (!L1 & !SQUARE)
    // {
    //     XL_THUC_XUONG;
    //     delay_ms(50);
    //     XL_KEP_BONG_KEP;
    //     delay_ms(50);
    //     XL_THUC_LEN;
    //     delay_ms(50);
    //     XL_LAY_BONG_1_DONG;
    //     XL_LAY_BONG_2_DONG;
    //     delay_ms(50);
    //     XL_KEP_BONG_NHA;

    //     if (robot > goc_xoay_thoc)
    //     {
    //         Mor_Dia_xoay = 100, Mor_Dia_xoay_trai;
    //         while (BT_Dia_xoay_value > goc_xoay_thoc)
    //         {
    //             if (wantExit())
    //                 break;
    //         }
    //     }
    //     else
    //     {
    //         Mor_Dia_xoay = 100, Mor_Dia_xoay_phai;
    //         while (BT_Dia_xoay_value < goc_xoay_thoc)
    //         {
    //             if (wantExit())
    //                 break;
    //         }
    //     }

    //     delay_ms(300);
    //     Mor_xoay_trai = ban_thoc, Mor_xoay_trai_thuan;
    //     Mor_xoay_phai = ban_thoc, Mor_xoay_phai_thuan;
    //     delay_ms(1800);
    //     Mor_xoay_trai = Mor_xoay_phai = 0;
    // }

    // //-----------------------------BAN LEP--------------------------------------------------------
    // if(!L1 & !O)
    // {
    //         XL_THUC_XUONG;
    //         delay_ms(50);
    //         XL_KEP_BONG_KEP;
    //         delay_ms(50);
    //         XL_THUC_LEN;
    //         delay_ms(50);
    //         XL_LAY_BONG_1_DONG;
    //         XL_LAY_BONG_2_DONG;
    //         XL_KEP_BONG_NHA;
    //     if(BT_Dia_xoay_value > goc_xoay_lep)
    // {
    //     Mor_Dia_xoay = 100, Mor_Dia_xoay_trai;
    //     while(BT_Dia_xoay_value > goc_xoay_lep){if(wantExit())break;}
    // }
    // else
    // {
    //     Mor_Dia_xoay = 100, Mor_Dia_xoay_phai;
    //     while(BT_Dia_xoay_value < goc_xoay_lep){if(wantExit())break;}
    // }

    // delay_ms(300);
    // Mor_xoay_trai = ban_lep, Mor_xoay_trai_thuan;
    // Mor_xoay_phai = ban_lep, Mor_xoay_phai_thuan;
    // delay_ms(1800);
    // Mor_xoay_trai = Mor_xoay_phai = 0;
    //     }
    // // //***********************************************************************************
}

void testbanhxe()
{
}

// //********************************* doc cam bien line **************************************8
void Doc_cb_line(void)
{
    if (!CB_Line_P1 && CB_Line_P2 && CB_Line_P3 && CB_Line_P4)
        CB_LINE_PHAI = 3;
    else if (!CB_Line_P1 && !CB_Line_P2 && CB_Line_P3 && CB_Line_P4)
        CB_LINE_PHAI = 2;
    else if (CB_Line_P1 && !CB_Line_P2 && CB_Line_P3 && CB_Line_P4)
        CB_LINE_PHAI = 1;

    else if (CB_Line_P1 && !CB_Line_P2 && !CB_Line_P3 && CB_Line_P4)
        CB_LINE_PHAI = 0;

    else if (CB_Line_P1 && CB_Line_P2 && !CB_Line_P3 && CB_Line_P4)
        CB_LINE_PHAI = -1;
    else if (CB_Line_P1 && CB_Line_P2 && !CB_Line_P3 && !CB_Line_P4)
        CB_LINE_PHAI = -2;
    else if (CB_Line_P1 && CB_Line_P2 && CB_Line_P3 && !CB_Line_P4)
        CB_LINE_PHAI = -3;

    if (!CB_Line_T1 && CB_Line_T2 && CB_Line_T3 && CB_Line_T4)
        CB_LINE_TRAI = 3;
    else if (!CB_Line_T1 && !CB_Line_T2 && CB_Line_T3 && CB_Line_T4)
        CB_LINE_TRAI = 2;
    else if (CB_Line_T1 && !CB_Line_T2 && CB_Line_T3 && CB_Line_T4)
        CB_LINE_TRAI = 1;
    else if (CB_Line_T1 && !CB_Line_T2 && !CB_Line_T3 && CB_Line_T4)
        CB_LINE_TRAI = 0;
    else if (CB_Line_T1 && CB_Line_T2 && !CB_Line_T3 && CB_Line_T4)
        CB_LINE_TRAI = -1;
    else if (CB_Line_T1 && CB_Line_T2 && !CB_Line_T3 && !CB_Line_T4)
        CB_LINE_TRAI = -2;
    else if (CB_Line_T1 && CB_Line_T2 && CB_Line_T3 && !CB_Line_T4)
        CB_LINE_TRAI = -3;
}

void robotLineRunLeft(vu8 speed)
{
    if (CB_LINE_TRAI > -1 && CB_LINE_TRAI < 1 && CB_LINE_PHAI > -1 && CB_LINE_PHAI < 1)
        robotRun(-900, speed);
    else if (CB_LINE_TRAI <= -1)
        robotCurve(-900 - 20 * abs(CB_LINE_TRAI), speed, -0.05 * abs(CB_LINE_TRAI));
    else if (CB_LINE_TRAI >= 1)
        robotCurve(-900 + 20 * abs(CB_LINE_TRAI), speed, 0.05 * abs(CB_LINE_TRAI));
    else if (CB_LINE_PHAI <= -1)
        robotCurve(-900 - 20 * abs(CB_LINE_TRAI), speed, -0.05 * abs(CB_LINE_TRAI));
    else if (CB_LINE_PHAI >= 1)
        robotCurve(-900 + 20 * abs(CB_LINE_TRAI), speed, 0.05 * abs(CB_LINE_TRAI));
}

void robotLineRunRight(vu8 speed)

{
    if (CB_LINE_TRAI >= -1 && CB_LINE_TRAI <= 1 && CB_LINE_PHAI >= -1 && CB_LINE_PHAI <= 1)
        robotRun(900, speed);

    // else if (CB_LINE_TRAI <= -1)
    // 	robotCurve(900 + 20 * abs(CB_LINE_PHAI), speed, 0.05 * abs(CB_LINE_PHAI));
    // else if (CB_LINE_TRAI >= 1)
    // 	robotCurve(900 - 20 * abs(CB_LINE_PHAI), speed, -0.05 * abs(CB_LINE_PHAI));
    // else if (CB_LINE_PHAI <= -1)
    // 	robotCurve(900 - 20 * abs(CB_LINE_PHAI), speed, -0.05 * abs(CB_LINE_PHAI));
    // else if (CB_LINE_PHAI >= 1)
    // 	robotCurve(900 - 20 * abs(CB_LINE_PHAI), speed, 0.05 * abs(CB_LINE_PHAI));

    else if (CB_LINE_TRAI <= -1)
        robotCurve(900, speed, -0.05 * abs(CB_LINE_PHAI));

    else if (CB_LINE_TRAI >= 1)
        robotCurve(900, speed, 0.05 * abs(CB_LINE_PHAI));

    else if (CB_LINE_PHAI <= -1)
        robotCurve(900, speed, 0.05 * abs(CB_LINE_PHAI));

    else if (CB_LINE_PHAI >= 1)
        robotCurve(900, speed, 0.05 * abs(CB_LINE_TRAI));
}
