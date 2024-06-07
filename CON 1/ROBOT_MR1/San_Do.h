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

void LEN_SAN_2()
//////////////////////////SAN DO//////////////////////////
{
    if (SAN == 1)
    {
        RESET_ENCODER();
        robotRunAngle(900, 30, 0, 0);
        while (ENCODER_TONG() < 100)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        };

        robotRunAngle(0, 60, 0, 0);
        while (lazeSauValue < 285)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        };

        // robotStop(0);
        robotRunAngle(-900, 30, 0, 2);
        while (lazePhaiValue < 125)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        };

        robotRunAngle(0, 20, 900, 2.5);
        while (robotAngle() < 895)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
            XL_DAY_LUA_BAT;
            XL_THA_LUA_TAT;
            XL_THUC_LEN;
            XL_KEP_BONG_KEP;
        }

        robotStop(0);

        RESET_ENCODER();
        resetIMU();

        robotRunAngle(0, 35, 0, 2);
        while (ENCODER_TONG() < 3000)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        robotRunAngle(0, 35, 0, 2);
        while (lazeTruocValue > 120)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        robotStop(0);

        reset_all();

        for (noise = 0; noise < 50; noise++)
        {
            while (lazeTraiValue < 180)
            {
                Bam_thanh_laser_truoc_900(50, 0, 82, 2);
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
            }
        }
        for (i = 0; i < 50; i++)
        {
            while (lazeTraiValue < 354 - 30)
            {
                do_line(40);
                if (wantExit_R2())
                    break;
            }
        }
        for (i = 0; i < 50; i++)
        {
            while (CB_BONG_GIUA_TRAI == 0 && CB_BONG_SAU_TRAI == 1)
            {
                do_line(5);
                if (wantExit_R2())
                    break;
            }
        }
        san = 2;
    }

    else
    {
        RESET_ENCODER();

        robotRunAngle(900, 30, 0, 0);
        while (ENCODER_TONG() < 100)
        {
            XL_KEP_BONG_KEP;
            XL_DAY_LUA_BAT;
            XL_THA_LUA_TAT;
            XL_THUC_LEN;
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        };

        robotRunAngle(1800, 60, 0, 0);
        while (lazeTruocValue < 285)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        };

        robotStop(0);
        robotRunAngle(-900, 30, 0, 2);
        while (lazePhaiValue < 125)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        };

        robotRunAngle(1800, 20, 900, 2.5);
        while (robotAngle() < 895)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        robotStop(0);

        reset_all();

        robotRunAngle(0, 35, 0, 2);
        while (ENCODER_TONG() < 3000)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        robotRunAngle(0, 35, 0, 2);
        while (lazeTruocValue > 120)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        robotStop(0);
        reset_all();

        for (noise = 0; noise < 50; noise++)
        {
            while (lazePhaiValue < 180)
            {
                Bam_thanh_laser_truoc_am_900(50, 0, 80, 2);
                if (wantExit_R2())
                    break;
            }
        }
        for (noise = 0; noise < 50; noise++)
        {
            while (lazePhaiValue < 347 - 25)
            {
                do_line(-50);
                if (wantExit_R2())
                    break;
            }
        }
        for (i = 0; i < 50; i++)
        {
            while (CB_BONG_GIUA_PHAI == 0 && CB_BONG_SAU_PHAI == 0)
            {
                do_line(-5);
                if (wantExit_R2())
                    break;
            }
        }
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
        while (lazePhaiValue > 52)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        robotRunAngle(1800, 20, 0, 0);
        while (lazeSauValue > laze_ngang_ve + 5)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        robotStop(0);

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue < 150)
            {
                chuanbicocau();
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
                Bam_thanh_laser_sau_am_900(50, 5, laze_ngang_ve + 10, 2);
            }
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue < 250)
            {
                chuanbicocau();
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
                Bam_thanh_laser_sau_am_900(30, 2, laze_ngang_ve + 10, 2);
            }
        }
        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue < 307)
            {
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
                Bam_thanh_laser_sau_am_900(10, 2, laze_ngang_ve + 10, 2);
            }
        }
        robotStop(0);
        for (i = 0; i < 50; i++)
            while (CB_LUA_DUOI == 1 || CB_LUA_TREN == 1)
            {
                robotRun(-1700, 10);
                vTaskDelay(1);
                if(wantExit_R2())break;
            }
    }
    else
    {
        RESET_ENCODER();
        XL_DAY_TAT;
        XL_DAY_LUA_TAT;
        XL_THA_LUA_BAT;
        robotRunAngle(900, 25, 0, 0);
        while (lazePhaiValue > 52)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        robotRunAngle(0, 25, 0, 0);
        while (lazeTruocValue > laze_ngang_ve + 5)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        robotStop(0);

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue < 150)
            {
                chuanbicocau();
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
                Bam_thanh_laser_truoc_am_900(50, 0, laze_ngang_ve - 5, 2);
            }
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue < 250)
            {
                chuanbicocau();
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
                Bam_thanh_laser_truoc_am_900(30, 0, laze_ngang_ve - 5, 2);
            }
        }
        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue < 308)
            {
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
                Bam_thanh_laser_truoc_am_900(10, 0, laze_ngang_ve - 5, 2);
            }
        }
        robotStop(0);
        for (i = 0; i < 50; i++)
            while (CB_LUA_DUOI == 1 || CB_LUA_TREN == 1)
            {
                robotRun(-1700, 5);
            }
    }
    robotStop(0);
}

void quy_trinh_trong_lua_hang_1()
{
    /****************************************LEN TRONG LUA*************************************************/
    thong_so_laze_ngang_doc();
    XL_THA_LUA_TAT;
    XL_KEP_LUA_TREN_KEP;
    XL_KEP_LUA_DUOI_KEP;
    delay_ms(500);

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
        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 180)
                Bam_thanh_laser_sau_900(40, 0, laze_trong, 2);
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 150)
                Bam_thanh_laser_sau_900(30, 0, laze_trong, 2);
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 125)
                Bam_thanh_laser_sau_900(20, 0, laze_trong, 2);
            vTaskDelay(1);
        }
        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 120)
                Bam_thanh_laser_sau_900(10, 0, laze_trong, 2);
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 109)
                Bam_thanh_laser_sau_900(5, 0, laze_trong, 2);
            vTaskDelay(1);
        }

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
        {
            while (lazePhaiValue > 180)
                Bam_thanh_laser_truoc_900(40, -2, laze_trong, 2);
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 150)
                Bam_thanh_laser_truoc_900(30, -2, laze_trong, 2);
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 125)
                Bam_thanh_laser_truoc_900(20, -2, laze_trong, 2);
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 120)
                Bam_thanh_laser_truoc_900(10, -2, laze_trong, 2);
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 109)
                Bam_thanh_laser_truoc_900(5, -2, laze_trong, 2);
            vTaskDelay(1);
        }

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
        {
            while (lazePhaiValue > 70)
                Bam_thanh_laser_sau_900(10, 0, laze_trong, 2);
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 58)
                Bam_thanh_laser_sau_900(5, 0, laze_trong, 2);
            vTaskDelay(1);
        }

        robotStop(0);
    }
    else
    {
        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 70)
                Bam_thanh_laser_truoc_900(10, 3, laze_trong, 2);
            vTaskDelay(1);
        }

        for (i = 0; i < 50; i++)
        {
            while (lazePhaiValue > 58)
                Bam_thanh_laser_truoc_900(5, 3, laze_trong, 2);
            vTaskDelay(1);
        }
        robotStop(0);
    }
}
void trong_lua()
{
    if (SAN == 1)
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
                lan_trong++;
                LEN_SAN_2();
            }
        }
        else
        {
            XL_KEP_LUA_TREN_KEP;
            XL_THA_LUA_TAT;
            XL_DAY_LUA_TAT;
            // delay_ms(50);
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
                lan_trong++;
                LEN_SAN_2();
            }
        }
        else
        {
            XL_KEP_LUA_TREN_KEP;
            XL_THA_LUA_TAT;
            XL_DAY_LUA_TAT;

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

    /****************************************DI CHUYEN LAY LUA TIEP THEO*************************************************/
    if (SAN == 1)
    {
        lan_trong++;
        thong_so_laze_ngang_doc();

        robotRunAngle(-1750, 20, 0, 2);
        while (CB_LUA_DUOI == 1 || CB_LUA_TREN == 1)
        {
            if (wantExit_R2())
                break;
        }

        robotStop(0);
    }
    else
    {
        lan_trong++;
        thong_so_laze_ngang_doc();

        robotRunAngle(-50, 20, 0, 2);
        while (CB_LUA_DUOI == 1 || CB_LUA_TREN == 1)
        {
            if (wantExit_R2())
                break;
        }

        robotStop(0);
    }
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
            if (wantExit_R2())
                break;
            vTaskDelay(1);
            chuanbicocau();
        }

        for (i = 0; i < 50; i++)
        {
            while (lazeSauValue > 300)
            {
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
                Bam_thanh_laser_phai_1800(15, 0, 309, 2);
            }
        }
        for (i = 0; i < 50; i++)
        {

            while (CB_LUA_TREN == 1 || CB_LUA_DUOI == 1)
            {
                robotRun(-1700, 10);
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
            }
        }
        lan_trong++;

        robotStop(0);
    }
    else
    {
        robotRunAngle(450, 40, 0, 2);
        while (ENCODER_TONG() < 500)
        {
            chuanbicocau();
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        while (lazeTruocValue > 305)
        {
            // bam_thanh_laze_doc(0, 15, 0, 2, 40, 306, 2, lazePhaiValue);
            Bam_thanh_laser_phai(15, 0, 310, 2);
            if (wantExit_R2())
                break;
        }

        for (i = 0; i < 50; i++)
        {
            while (CB_LUA_DUOI == 1 || CB_LUA_TREN == 1)
            {
                robotRun(-100, 10);
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
            }
        }
        lan_trong++;

        robotStop(0);
    }
}

void THI()
{
    XuatPhat();
    // muốn chạy tự động cần cài thêm delay vào các bước
    while (lan_trong != 4)
    {
        quy_trinh_trong_lua_hang_1();
        delay_ms(100);
        trong_lua();
        delay_ms(100);
        trong_lua();
        if (wantExit_R2())
            break;
        vTaskDelay(1);
    }
}

void retry_2()
{
    reset_all();
    vTaskDelay(111);

    if (SAN == 1)
    {
        while (ENCODER_TONG() < 2500)
        {
            XL_KEP_BONG_KEP;
            XL_DAY_LUA_BAT;
            XL_THA_LUA_TAT;
            XL_THUC_LEN;
            Bam_thanh_laser_trai(50, 0, 21, 2);
            if (wantExit_R2())
                break;
        }
        while (lazeTruocValue > 130)
        {
            Bam_thanh_laser_trai(30, 0, 25, 2);
            if (wantExit_R2())
                break;
        }
        for (noise = 0; noise < 50; noise++)
        {
            while (lazeTraiValue < 200)
            {
                Bam_thanh_laser_truoc_900(30, 0, 82, 2);
                if (wantExit_R2())
                    break;
                vTaskDelay(1);
            }
        }
        for (i = 0; i < 50; i++)
        {
            while (lazeTraiValue < 354 - 30)
            {
                do_line(50);
                if (wantExit_R2())
                    break;
            }
        }
        for (i = 0; i < 50; i++)
        {
            while (CB_BONG_GIUA_TRAI == 0 && CB_BONG_SAU_TRAI == 1)
            {
                do_line(5);
                if (wantExit_R2())
                    break;
            }
        }
        robotStop(0);
    }

    else
    {
        while (ENCODER_TONG() < 2500)
        {
            XL_KEP_BONG_KEP;
            XL_DAY_LUA_BAT;
            XL_THA_LUA_TAT;
            XL_THUC_LEN;
            Bam_thanh_laser_phai(50, 0, 21, 2);
            if (wantExit_R2())
                break;
        }
        RESET_ENCODER();
        while (ENCODER_TONG() < 2000)
        {
            Bam_thanh_laser_phai(30, 0, 21, 2);
            if (wantExit_R2())
                break;
        }
        robotRunAngle(0, 30, 0, 2);
        while (ENCODER_TONG() < 2500)
        {
            if (wantExit_R2())
                break;
        }

        robotRunAngle(0, 35, 0, 2);
        while (lazeTruocValue > 120)
        {
            if (wantExit_R2())
                break;
            vTaskDelay(1);
        }

        for (noise = 0; noise < 50; noise++)
        {
            while (lazePhaiValue < 200)
            {
                Bam_thanh_laser_truoc_am_900(30, 0, 80, 2);
                if (wantExit_R2())
                    break;
            }
        }
        for (noise = 0; noise < 50; noise++)
        {
            while (lazePhaiValue < 347 - 25)
            {
                do_line(-20);
                if (wantExit_R2())
                    break;
            }
        }
        for (i = 0; i < 50; i++)
        {
            while (CB_BONG_GIUA_PHAI == 0 && CB_BONG_SAU_PHAI == 0)
            {
                do_line(-5);
                if (wantExit_R2())
                    break;
            }
        }
        robotStop(0);
    }
    san = 2;
}