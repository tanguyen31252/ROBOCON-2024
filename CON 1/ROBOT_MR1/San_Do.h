void reset_all()
{
    resetIMU();
    RESET_ENCODER();
    vTaskDelay(111);
}
/*******************KHAI BAO GIA TRI LAZE NGANG***************************/
void thong_so_laze_ngang_doc(void)
{
    if (lan_trong == 1 && hang_trong == 1)
    {
        laze_trong = LAZE_THANH_TRONG[SAN][lan_trong];
    }
    else if (lan_trong == 1 && hang_trong == 2)
    {
        laze_trong = LAZE_THANH_TRONG[SAN][lan_trong], laze_ngang_ve = LAZE_VE[SAN][0];
    }

    if (lan_trong == 2 && hang_trong == 1)
    {
        laze_trong = LAZE_THANH_TRONG[SAN][lan_trong];
    }
    else if (lan_trong == 2 && hang_trong == 2)
    {
        laze_trong = LAZE_THANH_TRONG[SAN][lan_trong], laze_ngang_ve = LAZE_VE[SAN][1];
    }

    if (lan_trong == 3 && hang_trong == 1)
    {
        laze_trong = LAZE_THANH_TRONG[SAN][lan_trong];
    }
    else if (lan_trong == 3 && hang_trong == 2)
    {
        laze_trong = LAZE_THANH_TRONG[SAN][lan_trong];
    }
}
<<<<<<< Updated upstream
void thong_so_laze_ngang_doc_san_xanh()
{
        if      (lan_trong == 1 && hang_trong == 1)     {lazengang = LAZENGANG_1[SAN][1];}
        else if (lan_trong == 1 && hang_trong == 2)     {lazengang = LAZENGANG_1[SAN][2],laze_ngang_ve = LAZE_VE[SAN][0];}
        
        if      (lan_trong == 2 && hang_trong == 1)     {lazengang = LAZENGANG_1[SAN][3];}
        else if (lan_trong == 2 && hang_trong == 2)     {lazengang = LAZENGANG_1[SAN][4],laze_ngang_ve = LAZE_VE[SAN][1];}    
        
        if      (lan_trong == 3 && hang_trong == 1)     {lazengang = LAZENGANG_1[SAN][5];}
        else if (lan_trong == 3 && hang_trong == 2)     {lazengang = LAZENGANG_1[SAN][6];}
}
=======
// void thong_so_laze_ngang_doc_san_xanh()
// {
//         if      (lan_trong == 1 && hang_trong == 1)     {lazengang = LAZENGANG_1[SAN][1];}
//         else if (lan_trong == 1 && hang_trong == 2)     {lazengang = LAZENGANG_1[SAN][2],laze_ngang_ve = LAZE_VE[SAN][0];}
        
//         if      (lan_trong == 2 && hang_trong == 1)     {lazengang = LAZENGANG_1[SAN][3];}
//         else if (lan_trong == 2 && hang_trong == 2)     {lazengang = LAZENGANG_1[SAN][4],laze_ngang_ve = LAZE_VE[SAN][1];}    
        
//         if      (lan_trong == 3 && hang_trong == 1)     {lazengang = LAZENGANG_1[SAN][5];}
//         else if (lan_trong == 3 && hang_trong == 2)     {lazengang = LAZENGANG_1[SAN][6];}
// }
>>>>>>> Stashed changes

void LEN_SAN_2()
//////////////////////////SAN DO//////////////////////////
{
    if (SAN == 1)
    {
        RESET_ENCODER();
        // robotFixAngle();
        robotRunAngle(900, 30, 0, 0);
        while (ENCODER_TONG() < 200)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        };

        robotRunAngle(0, 30, 0, 0);
        while (lazeSauValue < 360)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        };

        robotStop(0);
        robotRunAngle(-900, 30, 0, 2);
        while (lazePhaiValue < 125)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        };

        robotRunAngle(0, 20, 900, 2.5);
        while (robotAngle() < 895)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotStop(0);

        XL_DAY_LUA_BAT;
        XL_THA_LUA_TAT;
        XL_THUC_LEN;
        XL_KEP_BONG_KEP;
        robotStop(0);
        // robotRotate(900,1,0);
        // while(robotFixAngle()){vTaskDelay(1);}
        // robotStop(0);

        RESET_ENCODER();
        resetIMU();

        robotRunAngle(0, 35, 0, 2);
        while (ENCODER_TONG() < 3000)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotRunAngle(0, 35, 0, 2);
        while (lazeTruocValue > 120)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotStop(0);
        robotFixAngle();
        robotStop(0);
        reset_all();

        for (noise = 0; noise < 50; noise++)
        {
            while (lazeTraiValue < 310)
            {
                bam_thanh_laze_doc(900, 10, 0, 2, 50, 120, 0, lazeTraiValue);
                if (wantExit())
                    break;
                vTaskDelay(1);
            }
        }
        san = 2;
    }

    else
    {
        RESET_ENCODER();
        // robotFixAngle();
        robotRunAngle(900, 30, 0, 0);
        while (ENCODER_TONG() < 200)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        };

        robotRunAngle(1800, 30, 0, 0);
        while (lazeTruocValue < 360)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        };

        robotStop(0);
        robotRunAngle(-900, 30, 0, 2);
        while (lazePhaiValue < 125)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        };

        robotRunAngle(1800, 20, 900, 2.5);
        while (robotAngle() < 895)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotStop(0);

        XL_DAY_LUA_BAT;
        XL_THA_LUA_TAT;
        XL_THUC_LEN;
        robotStop(0);
        // robotRotate(900,1,0);
        // while(robotFixAngle()){vTaskDelay(1);}
        // robotStop(0);

        RESET_ENCODER();
        resetIMU();

        robotRunAngle(0, 35, 0, 2);
        while (ENCODER_TONG() < 3000)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotRunAngle(0, 35, 0, 2);
        while (lazeTruocValue > 120)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotStop(0);
        robotFixAngle();
        robotStop(0);
        reset_all();

        for (noise = 0; noise < 50; noise++)
        {
            while (lazePhaiValue < 600)
            {
                bam_thanh_laze_doc(-900, 10, 0, 2, 50, 120, 1, lazeTraiValue);
            }
        }

        // robotRunAngle(900,15,900,0);
        // while (lazeTruocValue > 110){if(wantExit()) break; vTaskDelay(1);}
        // XL_DAY_LUA_BAT;

        // resetIMU();
        // RESET_ENCODER();
        // robotRunAngle(900,10,0,2);
        // while (ENCODER_TONG() < 300){if(wantExit()) break; vTaskDelay(1);}

        // robotRunAngle(-900,20,0,2);
        // while(lazePhaiValue < 150){if(wantExit()) break; vTaskDelay(1);}

        // delay_ms(50);

        // XL_DAY_LUA_TAT;
        san = 2;
    }
}

void ve_lay_lua()
{
    RESET_ENCODER();
    if (SAN == 1)
    {
        RESET_ENCODER();
        XL_DAY_TAT;
        XL_DAY_LUA_TAT;
        XL_THA_LUA_BAT;
        robotRunAngle(900, 25, 0, 0);
        while (ENCODER_TONG() < 100)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotRunAngle(1800, 20, 0, 0);
        while (lazeSauValue > laze_ngang_ve + 10)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotStop(0);
        delay_ms(200);
        chuanbicocau();

        for (noise = 0; noise < 50; noise++)
        {
            while (lazePhaiValue < 275)
            {
                if (wantExit())
                    break;
                vTaskDelay(1);
                bam_thanh_laze_ngang(-900, 30, 0, 2, -50, laze_ngang_ve, 0, lazeSauValue);
            }
        }

        for (noise = 0; noise < 50; noise++)
        {
            while (lazePhaiValue < 306)
            {
                if (wantExit())
                    break;
                vTaskDelay(1);
                bam_thanh_laze_ngang(-900, 5, 0, 2, -50, laze_ngang_ve, 0, lazeSauValue);
            }
        }
        // RESET_ENCODER();
        // robotRunAngle(-850, 5, 0, 2);
        // while (ENCODER_TONG() < 120)
        // {
        // }

        // RESET_ENCODER();
        // robotRunAngle(-900, 5, 0, 2);
        // while (ENCODER_TONG() < 300)
        // {
        //     if (wantExit())
        //         break;
        //     vTaskDelay(1);
        // }

        // if (lazeSauValue > laze_ngang_ve + 4)
        // {
        //     robotRunAngle(1800, 5, 0, 2);
        //     while (CB_LUA_TREN == 1 || CB_LUA_DUOI == 1)
        //     {
        //         if (wantExit())
        //             break;
        //         vTaskDelay(1);
        //     }
        // }
        // if (lazeSauValue < laze_ngang_ve + 4)
        // {
        //     robotRunAngle(0, 5, 0, 2);
        //     while (CB_LUA_TREN == 1 || CB_LUA_DUOI == 1)
        //     {
        //         if (wantExit())
        //             break;
        //         vTaskDelay(1);
        //     }
        // }

        while (CB_LUA_TREN == 1 && CB_LUA_DUOI == 1)
        {
            if (lazeSauValue > laze_ngang_ve + 4)
            {
                robotRunAngle(1800, 5, 0, 2);
            }
            if (lazeSauValue < laze_ngang_ve + 4)
            {
                robotRunAngle(0, 5, 0, 2);
            }
            if (wantExit())
                break;
        }
        delay_ms(70);
        robotStop(0);
    }
    else
    {
        RESET_ENCODER();
        XL_DAY_TAT;
        XL_DAY_LUA_TAT;
        XL_THA_LUA_BAT;
        robotRunAngle(900, 25, 0, 0);
        while (ENCODER_TONG() < 100)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotRunAngle(1800, 25, 0, 0);
        while (lazeTruocValue < laze_ngang_ve - 30)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue < 278)
            {
                if (wantExit())
                    break;
                vTaskDelay(1);
                bam_thanh_laze_ngang(-900, 30, 0, 2, -130, laze_ngang_ve, 0, lazeSauValue);
            }
        }
        chuanbicocau();
        RESET_ENCODER();
        robotRunAngle(-850, 10, 0, 2);
        while (ENCODER_TONG() < 400)
        {
        }

        RESET_ENCODER();
        robotRunAngle(-850, 5, 0, 2);
        while (ENCODER_TONG() < 120)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        if (lazeTruocValue < laze_ngang_ve + 4)
        {
            robotRunAngle(1800, 9, 0, 2);
            while (CB_LUA_TREN == 1 || CB_LUA_DUOI == 1)
            {
                if (wantExit())
                    break;
                vTaskDelay(1);
            }
        }
        if (lazeTruocValue > laze_ngang_ve + 4)
        {
            robotRunAngle(0, 9, 0, 2);
            while (CB_LUA_TREN == 1 || CB_LUA_DUOI == 1)
            {
                if (wantExit())
                    break;
                vTaskDelay(1);
            }
        }
    }
}

void quy_trinh_trong_lua_hang_1()
{
    /****************************************LEN TRONG LUA*************************************************/
    thong_so_laze_ngang_doc();
    RESET_ENCODER();
    robotRunAngle(-850, 5, 0, 2);
    while (ENCODER_TONG() < 30)
    {
    }
    robotStop(0);
    XL_THA_LUA_TAT;
    XL_KEP_LUA_TREN_KEP;
    XL_KEP_LUA_DUOI_KEP;

    for (i = 0; i < 50; i++)
    {
        while (CB_NANG_HA_LUA_TREN == 1)
        {
            XL_DAY_LUA_BAT;
        }
    }
    XL_DAY_LUA_TAT;

    delay_ms(400);
    reset_all();
    /****************************************TRONG LUA HANG 1**************************************************/
    /****************************************SAN DO**************************************************/
    if (SAN == 1)
    {
        // for (i = 0; i < 50; i++)
        //     while (lazePhaiValue > 180)
        //         bam_thanh_laze_doc(900, 40, 0, 2, -130, laze_ngoai, 0, lazeTruocValue);

        // for (i = 0; i < 50; i++)
        //     while (lazePhaiValue > 150)
        //         bam_thanh_laze_doc(900, 30, 0, 2, -130, laze_ngoai, 0, lazeTruocValue);

        // for (i = 0; i < 50; i++)
        //     while (lazePhaiValue > 125)
        //         bam_thanh_laze_doc(900, 20, 0, 2, -130, laze_ngoai, 0, lazeTruocValue);

        // for (i = 0; i < 50; i++)
        //     while (lazePhaiValue > 110)
        //         bam_thanh_laze_doc(900, 10, 0, 2, -130, laze_ngoai, 0, lazeTruocValue);
        // robotStop(0);

        // for (i = 0; i < 50; i++)
        // {
        //     while (CB_NANG_HA_LUA_DUOI == 1)
        //     {
        //         XL_THA_LUA_BAT;
        //     }
        // }
        // XL_DAY_LUA_TAT;
        // XL_THA_LUA_TAT;
        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 180)
                bam_thanh_laze_doc(900, 40, 0, 2, 150, laze_trong, 0, lazeSauValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 150)
                bam_thanh_laze_doc(900, 30, 0, 2, 150, laze_trong, 0, lazeSauValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 125)
                bam_thanh_laze_doc(900, 20, 0, 2, 150, laze_trong, 0, lazeSauValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 120)
                bam_thanh_laze_doc(900, 10, 0, 2, 150, laze_trong, 0, lazeSauValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 103)
                bam_thanh_laze_doc(900, 5, 0, 2, 150, laze_trong, 0, lazeSauValue);
        robotStop(0);

        for (i = 0; i < 50; i++)
        {
            while (CB_NANG_HA_LUA_DUOI == 1)
            {
                XL_THA_LUA_BAT;
            }
        }
        XL_DAY_LUA_TAT;
        XL_THA_LUA_TAT;
    }
    /****************************************SAN XANH**************************************************/
    else
    {
    for (i = 0; i < 50; i++)
            while (lazePhaiValue > 180)
                bam_thanh_laze_doc(900, 40, 0, 2, 150, laze_trong, 0, lazeTruocValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 150)
                bam_thanh_laze_doc(900, 30, 0, 2, 150, laze_trong, 0, lazeTruocValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 125)
                bam_thanh_laze_doc(900, 20, 0, 2, 150, laze_trong, 0, lazeTruocValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 120)
                bam_thanh_laze_doc(900, 10, 0, 2, 150, laze_trong, 0, lazeTruocValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 103)
                bam_thanh_laze_doc(900, 5, 0, 2, 150, laze_trong, 0, lazeTruocValue);
        robotStop(0);

        for (i = 0; i < 50; i++)
        {
            while (CB_NANG_HA_LUA_DUOI == 1)
            {
                XL_THA_LUA_BAT;
            }
        }
        XL_DAY_LUA_TAT;
        XL_THA_LUA_TAT;
    }
}

/****************************************TRONG LUA HANG 2**************************************************/
void quy_trinh_trong_lua_hang_2()
{
    thong_so_laze_ngang_doc();

    if (SAN == 1)
    {
        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 70)
                bam_thanh_laze_doc(900, 10, 0, 2, 80, laze_trong, 0, lazeSauValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 56)
                bam_thanh_laze_doc(900, 5, 0, 2, 150, laze_trong, 0, lazeSauValue);

        robotStop(0);
    }
    else
    {
        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 70)
                bam_thanh_laze_doc(900, 10, 0, 2, 80, laze_trong, 0, lazeTruocValue);

        for (i = 0; i < 50; i++)
            while (lazePhaiValue > 56)
                bam_thanh_laze_doc(900, 5, 0, 2, 150, laze_trong, 0, lazeTruocValue);
        robotStop(0);
    }
}
void trong_lua()
{
    if (SAN == 1)
    {
        if (hang_trong == 2)
        {
            delay_ms(500);
            thong_so_laze_ngang_doc();

            XL_KEP_LUA_TREN_NHA;
            XL_KEP_LUA_DUOI_NHA;
            if (lan_trong != 3)
            {
                ve_lay_lua();
                lan_trong++;
                hang_trong = 1;
            }
            else
            {
                LEN_SAN_2();
            }
        }
        else
        {
            delay_ms(350);
            XL_KEP_LUA_TREN_KEP;
            XL_THA_LUA_TAT;
            XL_DAY_LUA_TAT;
            delay_ms(50);
            XL_KEP_LUA_DUOI_NHA;
            XL_DAY_TAT;
            hang_trong = 2;
            quy_trinh_trong_lua_hang_2();
        }
    }
    else
    {
        if (hang_trong == 2)
        {
            thong_so_laze_ngang_doc();

            XL_KEP_LUA_TREN_NHA;
            XL_KEP_LUA_DUOI_NHA;
            if (lan_trong != 3)
            {
                ve_lay_lua();
                lan_trong++;
                hang_trong = 1;
            }
            else
            {
                LEN_SAN_2();
            }
        }
        else
        {
            delay_ms(350);
            XL_KEP_LUA_TREN_KEP;
            XL_THA_LUA_TAT;
            XL_DAY_LUA_TAT;
            delay_ms(50);
            XL_KEP_LUA_DUOI_NHA;
            XL_DAY_TAT;
            hang_trong = 2;
            quy_trinh_trong_lua_hang_2();
        }
    }
}
/////////////////////////////////  RETRY  ////////////////////////////////////
void retry(void)
{
    reset_all();
    hang_trong = 2;

    /****************************************DI CHUYEN LAY LUA TIEP THEO*************************************************/
    thong_so_laze_ngang_doc();
    for(i = 0;i< 500;i++)
    {
        if((!R1 & !X) == 1) 
        {
            
        }
    }
    if (SAN == 1)
    {
        robotRunAngle(900, 15, 0, 0);
        while (CB_LUA_TREN == 1 || CB_LUA_DUOI == 1)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }
    }
    else
    {
        robotRunAngle(-900, 15, 0, 0);
        while (CB_LUA_TREN == 1 || CB_LUA_DUOI == 1)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }
    }

    lan_trong++;
    hang_trong = 1;
}
///////////////////////////////// XUAT PHAT///////////////////////////////////
int XuatPhat(void)
{
    reset_all();
    vTaskDelay(111);
    /****************************************DI CHUYEN LAY LUA*************************************************/
    if (SAN == 1)
    {
        robotRunAngle(1350, 35, 0, 2);
        while (lazePhaiValue > 310)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        chuanbicocau();

        for (i = 0; i < 50; i++)
        {
            while (lazeSauValue > 285)
            {
                if (wantExit())
                    break;
                vTaskDelay(1);
                bam_thanh_laze_ngang(1800, 20, 0, 2, -50, 306, 2, lazePhaiValue);
            }
        }

        while (CB_LUA_TREN == 1 || CB_LUA_DUOI == 1)
        {
            if (lazeSauValue > 271)
            {
                bam_thanh_laze_ngang(1800, 5, 0, 2, -100, 306, 2, lazePhaiValue);
            }
            if (lazeSauValue < 264)
            {
                bam_thanh_laze_ngang(0, 5, 0, 2, 100, 306, 2, lazePhaiValue);
            }
            if (wantExit())
                break;
        }
        lan_trong++;
        delay_ms(70);

        robotStop(0);
    }
    else
    {
        robotRunAngle(300, 35, 0, 2);
        while (lazePhaiValue > 310)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        chuanbicocau();

        for (i = 0; i < 50; i++)
        {
            while (lazeTruocValue > 285)
            {
                if (wantExit())
                    break;
                vTaskDelay(1);
                bam_thanh_laze_ngang(1800, 20, 0, 2, -50, 306, 2, lazePhaiValue);
            }
        }

        while (CB_LUA_TREN == 1 || CB_LUA_DUOI == 1)
        {
            if (lazeTruocValue > 271)
            {
                bam_thanh_laze_ngang(1800, 5, 0, 2, -100, 306, 2, lazePhaiValue);
            }
            if (lazeTruocValue < 264)
            {
                bam_thanh_laze_ngang(0, 5, 0, 2, 100, 306, 2, lazePhaiValue);
            }
            if (wantExit())
                break;
        }
        lan_trong++;
        delay_ms(70);

        robotStop(0);
    }
}

void THI()
{
    XuatPhat();
    do
    {
        delay_ms(500);
        quy_trinh_trong_lua_hang_1();
        trong_lua();
        delay_ms(500);
        trong_lua();
        if (wantExit())
            break;
        vTaskDelay(1);
    } while (lan_trong != 4);
    // muốn chạy tự động cần cài thêm delay vào các bước
}

void ban_bong()
{
    // while (CB_Line_T2 == 0 && CB_Line_T3 == 0)
    
}
