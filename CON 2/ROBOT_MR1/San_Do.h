void Bam_thanh_laser_phai(int speed, int AngleHead, int lazer_stable_phai, int num_change_stable)
{
    int fix;

    fix = abs(laze_4H_Value - lazer_stable_phai) * 15;

    if (fix > 600)
        fix = 600;

    if (laze_4H_Value - lazer_stable_phai > num_change_stable)
    {
        robotRunAngle(0 + fix, speed, AngleHead, 0.1);
    }
    else if (laze_4H_Value - lazer_stable_phai < num_change_stable)
    {
        robotRunAngle(0 - fix, speed, AngleHead, 0.1);
    }
    else
        robotRunAngle(0, speed, AngleHead, 0.1);
}
void Bam_thanh_laser_phai_lui(int speed, int AngleHead, int lazer_stable_phai, int num_change_stable)
{
    int fix;

    fix = abs(laze_4H_Value - lazer_stable_phai) * 15;

    if (fix > 600)
        fix = 600;

    if (laze_4H_Value - lazer_stable_phai > num_change_stable)
    {
        robotRunAngle(1800 - fix, speed, AngleHead, 0.1);
    }
    else if (laze_4H_Value - lazer_stable_phai < num_change_stable)
    {
        robotRunAngle(1800 + fix, speed, AngleHead, 0.1);
    }
    else
        robotRunAngle(1800, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_trai(int speed, int AngleHead, int lazer_stable_trai, int num_change_stable)
{
    int fix;

    fix = abs(laze_8H_Value - lazer_stable_trai) * 15;

    if (fix > 600)
        fix = 600;

    if (laze_8H_Value - lazer_stable_trai > num_change_stable)
    {
        robotRunAngle(0 - fix, speed, AngleHead, 0.1);
    }
    else if (laze_8H_Value - lazer_stable_trai < num_change_stable)
    {
        robotRunAngle(0 + fix, speed, AngleHead, 0.1);
    }
    else
        robotRunAngle(0, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_trai_lui(int speed, int AngleHead, int lazer_stable_trai, int num_change_stable)
{
    int fix;

    fix = abs(laze_8H_Value - lazer_stable_trai) * 15;

    if (fix > 600)
        fix = 600;

    if (laze_8H_Value - lazer_stable_trai > num_change_stable)
    {
        robotRunAngle(-1800 + fix, speed, AngleHead, 0.1);
    }
    else if (laze_8H_Value - lazer_stable_trai < num_change_stable)
    {
        robotRunAngle(-1800 - fix, speed, AngleHead, 0.1);
    }
    else
        robotRunAngle(1800, speed, AngleHead, 0.1);
}

void reset_all()
{
    robotResetIMU();
    RESET_ENCODER();
    vTaskDelay(10);
}
void laze_chay_silo(int silo_sap_chay)
{
    // *************************SAN DO*****************************
    if (silo_sap_chay == 1)
        do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
    else if (silo_sap_chay == 2)
        do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
    else if (silo_sap_chay == 3)
        do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
    else if (silo_sap_chay == 4)
        do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
    else if (silo_sap_chay == 5)
        do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
}

void tha_bong()
{
    Mor_nong = 150;
    // Bang_tai = 254;
    delay_ms(1200);
    Mor_nong = Bang_tai = 0;
    bien_nho_bong_da_tha_trong_silo[silo_so]++;
    bien_chay_cap_thanh = 1;
}
void bat_cam()
{
    int check_phai = 1;
    for (i = 0; i < 150; i++)
        while (GP_BTN[1] != 22)
        {
            if (GP_BTN[1] == 33)
                robotRunAngle(-900, 30, 0, -0.5);
            else if (GP_BTN[1] == 11)
                robotRunAngle(900, 30, 0, 0.5);
            else if (GP_BTN[1] == 44)
            {
                if (laze_4H_Value > 50)
                {
                    if (check_phai)
                        robotRunAngle(900, 30, 0, 0.5);
                    else
                        robotRunAngle(-900, 20, 0, 0.5);
                }
                else
                {
                    check_phai = 0;
                    robotRunAngle(-900, 30, 0, 0.5);
                }
            }
        }
    if (laze_8H_Value < 50)
    {
        XL_NONG_XOAY_BAT;
        XL_DONG_90;
    }
    else if (laze_4H_Value < 50)
    {
        XL_NONG_XOAY_BAT;
        XL_DONG_90;
    }
    else
    {
        XL_NONG_XOAY_TAT;
        XL_MO_90;
    }

    robotStop(0);
}
void di_chuyen_ve()
{
    reset_all();
    vTaskDelay(111);
    XL_NONG_HA_TAT;
    XL_TR_NONG_HA_BAT;

    /********************SAN DO******************************/
    if (NUT_CHUYEN_SAN == 1)
    {
        for (noise = 0; noise < 50; noise++)
        {
            while (laze_4H_Value > 230 || ENCODER_TONG() < 3000)
            {
                bam_thanh_laze_ngang(1800, 50, 0, 2, 450, 150, 2);
                if (wantExit())
                    break;
            }
        }
        bat_cam();
        // RESET_ENCODER();

        // robotRunAngle(1800, 50, 0, 2);
        // while(ENCODER_TONG() < 4800){if(wantExit())break;}

        // robotStop(0);

        // robotRotate(900,1,0);                     // có thể đang bị đứng ở chỗ này cần fix 21h06 25/4
        // while(robotFixAngle()){vTaskDelay(1);}

        // while(laze_4H_Value > 35 || ENCODER_TONG() < 300)
        // {
        //     robotRunAngle(1800, absI(laze_4H_Value - 30), 900, 2);
        //     if(wantExit())  break;
        // }

        XL_MO_90;

        robotStop(0);
    }
    /*////////////////////////////SAN XANH///////////////////////*/
    else
    {
        for (noise = 0; noise < 50; noise++)
        {
            while (laze_8H_Value > 230 || ENCODER_TONG() < 3000)
            {
                bam_thanh_laze_ngang(1800, 50, 0, 2, 450, 250, 1);
                if (wantExit())
                    break;
            }
        }

        RESET_ENCODER();

        robotRunAngle(1800, 50, 0, 2);
        while (ENCODER_TONG() < 4500)
        {
            if (wantExit())
                break;
        }

        robotStop(0);

        robotRotate(-900, 1, 0); // có thể đang bị đứng ở chỗ này cần fix 21h06 25/4
        while (robotFixAngle())
        {
            vTaskDelay(1);
        }

        robotStop(0);
    }
    XL_MO_90;
    XL_TR_NONG_HA_TAT;
}

void kiem_tra_cap_thanh()
{
    while (CB_CAP_THANH_PHAI == 1 || CB_CAP_THANH_TRAI == 1)
    {
        if (CB_CAP_THANH_TRAI == 0 && CB_CAP_THANH_PHAI == 0)
        {
            /* dung */
            robotStop(0);
        }
        else if (CB_CAP_THANH_TRAI == 1 && CB_CAP_THANH_PHAI == 0)
        {
            /* quay phai */
            robotRotateFree(1, 0);
        }
        else if (CB_CAP_THANH_TRAI == 0 && CB_CAP_THANH_PHAI == 1)
        {
            /* quay trai */
            robotRotateFree(-1, 0);
        }
        else
        {
            robotRotateStop();
            robotRun(0, (laze_0H_Value - 5) / 4);
        }
    }
}

void duong_di_silo()
{
    laze_chay_silo(silo_so);
    bien_nhan_bong = 0;
    robotStop(0);
    XL_NONG_XOAY_BAT;

    /****************************************SAN DO****************************************/
    if (NUT_CHUYEN_SAN == 1)
    {
        while (laze_4H_Value < 350)
        {
            bam_thanh_laze_ngang(0, 50, 0, 2, 350, 175, 2);
            if (wantExit())
                break;
        }

        if (laze_8H_Value > do_laze_silo)
        {
            robotRunAngle(-700, 50, 0, 2);
            while (laze_8H_Value > do_laze_silo + 40)
            {
                if (wantExit())
                    break;
            }
        }
        else
        {
            robotRunAngle(700, 50, 0, 2);
            while (laze_8H_Value < do_laze_silo - 40)
            {
                if (wantExit())
                    break;
            }
        }

        for (noise = 0; noise < 100; noise++)
        {
            do
            {
                bam_thanh_laze_ngang(0, absI((laze_0H_Value - 10) / 2), 0, 2, 100, do_laze_silo - 5, 2);
                if (wantExit())
                    break;
            } while (laze_0H_Value > 40);
        }
        robotRunAngle(0, 10, 0, 2);
        while (laze_0H_Value > 25)
        {
            if (wantExit())
                break;
        }
        // while(CB_CAP_THANH_PHAI == 1 || CB_CAP_THANH_TRAI == 1)
        // {
        kiem_tra_cap_thanh();
        // }
        robotStop(0);
        reset_all();

        while (CB_TU_NHAN_SILO == 1)
        {
            if (laze_8H_Value > do_laze_silo)
            {
                // robotRunAngle(-900, 5, 0, 2);
                robotRun(-850, 10);
            }
            else
            {
                // robotRunAngle(900, 5, 0, 2);
                robotRun(850, 10);
            }
        }
        robotStop(0);
    }
    /****************************************SAN XANH***************************************/
    else
    {
        while (laze_8H_Value < 350)
        {
            bam_thanh_laze_ngang(0, 50, 0, 2, 350, 175, 1);
            if (wantExit())
                break;
        }

        if (laze_4H_Value > do_laze_silo)
        {
            robotRunAngle(700, 50, 0, 2);
            while (laze_4H_Value > do_laze_silo + 30)
            {
                if (wantExit())
                    break;
            }
        }
        else
        {
            robotRunAngle(-700, 50, 0, 2);
            while (laze_4H_Value < do_laze_silo - 30)
            {
                if (wantExit())
                    break;
            }
        }

        for (noise = 0; noise < 100; noise++)
        {
            do
            {
                bam_thanh_laze_ngang(0, absI((laze_0H_Value - 10) / 2), 0, 2, 100, do_laze_silo - 5, 2);
                if (wantExit())
                    break;
            } while (laze_0H_Value > 40);
        }
        robotRunAngle(0, 10, 0, 2);
        while (laze_0H_Value > 22)
        {
            if (wantExit())
                break;
        }
        // while(CB_CAP_THANH_PHAI == 1 || CB_CAP_THANH_TRAI == 1)
        // {
        kiem_tra_cap_thanh();
        // }
        robotStop(0);
        reset_all();

        while (CB_TU_NHAN_SILO == 1)
        {
            if (laze_4H_Value > do_laze_silo)
            {
                // robotRunAngle(-900, 5, 0, 2);
                robotRun(850, 10);
            }
            else
            {
                // robotRunAngle(900, 5, 0, 2);
                robotRun(-850, 10);
            }
        }
        robotStop(0);
    }
}

void di_chuyen() // viet lai di chuyen --> dung laze de chay
{
    /****************************************SAN DO****************************************/
    laze_chay_silo(silo_so);
    if (NUT_CHUYEN_SAN == 1)
    {
        /*
            neu silo_so = 1 || silo_so = 5 thi cho di huong nguoc lai
        */
        if (bien_di_chuyen == 1) // di chuyen sang trai
        {
            robotRun(850, 25);
            while (laze_8H_Value < do_laze_silo - 20)
            {
                if (wantExit())
                    break;
            }

            kiem_tra_cap_thanh();

            while (CB_TU_NHAN_SILO == 1)
            {
                if (laze_8H_Value > do_laze_silo)
                {
                    // robotRunAngle(-900, 5, 0, 2);
                    robotRun(-850, 5);
                }
                else
                {
                    // robotRunAngle(900, 5, 0, 2);
                    robotRun(850, 5);
                }
            }
        }
        else if (bien_di_chuyen == 0) // di chuyen sang phai
        {
            robotRun(-850, 25);
            while (laze_8H_Value > do_laze_silo + 20)
            {
                if (wantExit())
                    break;
            }

            kiem_tra_cap_thanh();

            while (CB_TU_NHAN_SILO == 1)
            {
                if (laze_8H_Value > do_laze_silo)
                {
                    // robotRunAngle(-900, 5, 0, 2);
                    robotRun(-850, 5);
                }
                else
                {
                    // robotRunAngle(900, 5, 0, 2);
                    robotRun(850, 5);
                }
            }
        }
    }
    /****************************************SAN XANH****************************************/
    else
    {
        if (bien_di_chuyen == 1) // di chuyen sang trai
        {
            robotRun(-850, 25);
            while (laze_4H_Value < do_laze_silo - 20)
            {
                if (wantExit())
                    break;
            }

            kiem_tra_cap_thanh();

            while (CB_TU_NHAN_SILO == 1)
            {
                if (laze_4H_Value > do_laze_silo)
                {
                    // robotRunAngle(-900, 5, 0, 2);
                    robotRun(850, 5);
                }
                else
                {
                    // robotRunAngle(900, 5, 0, 2);
                    robotRun(-850, 5);
                }
            }
        }
        else if (bien_di_chuyen == 0) // di chuyen sang phai
        {
            robotRun(850, 25);
            while (laze_4H_Value > do_laze_silo + 20)
            {
                if (wantExit())
                    break;
            }

            kiem_tra_cap_thanh();

            while (CB_TU_NHAN_SILO == 1)
            {
                if (laze_4H_Value > do_laze_silo)
                {
                    // robotRunAngle(-900, 5, 0, 2);
                    robotRun(850, 5);
                }
                else
                {
                    // robotRunAngle(900, 5, 0, 2);
                    robotRun(-850, 5);
                }
            }
        }
    }
}

void nhan_bong_trong_silo()
{
    if (CB_BONG_1 == 1) // chua co bong thi tha bong roi cho so bong = 1
    {
        bien_nhan_bong = 1;
        bien_nho_bong_trong_silo[silo_so] = 1;
    }

    else if (/*CB_BONG_1 == 0 && CB_BONG_2 == 0 &&*/ CB_BONG_3 == 0) // silo da co 3 bong va bo qua
    {
        bien_nhan_bong = 0;
        bien_nho_bong_trong_silo[silo_so] = 3;
    }
    else if (/*CB_BONG_1 == 0 &&*/ CB_BONG_2 == 0) // co 2 bong thi tha bong roi cho so bong = 3
    {
        bien_nhan_bong = 1;
        bien_nho_bong_trong_silo[silo_so] = 3;
    }
    /*
        co 1 bong thi kiem tra:
        - neu tat ca da 1 bong thi tha bong va len so bong 2
        - neu khong thi di chuyen theo huong da cai
    */
    else if (CB_BONG_1 == 0)
    {
        if (bien_nho_bong_trong_silo[0] == 1)
            bien_nho_bong_trong_silo[silo_so] = 2, bien_nho_silo_co_2_bong = silo_so, bien_nhan_bong = 1;
        else
            bien_nhan_bong = 0, bien_nho_bong_trong_silo[silo_so] = 1;
    }
    //     if(bien_nho_bong_trong_silo[5] >= 1 && bien_nho_bong_trong_silo[1] >= 1 && bien_nho_bong_trong_silo[2] >= 1 && bien_nho_bong_trong_silo[3] >= 1 && bien_nho_bong_trong_silo[4] >= 1)
    //     {
    //         bien_nho_bong_trong_silo[0]=1;
    //     }
    // if(CB_BONG_3 == 0)
    // {
    //     bien_nho_bong_trong_silo[silo_so] = 3;
    //     exclude_list[silo_so-1] = silo_so;
    // }
}

void kiem_tra_di_chuyen()
{
    nhan_bong_trong_silo();
    while (bien_nhan_bong == 0)
    {
        if (bien_nho_bong_trong_silo[0] == 0)
        {
            for (bien_di_chuyen = 0; bien_di_chuyen < 2; bien_di_chuyen++)
            {
                if (bien_di_chuyen == 0)
                {
                    for (silo_sap_bo = silo_so + 1; silo_sap_bo < 6; silo_sap_bo++)
                    {
                        if (/*bien_nho_bong_da_tha_trong_silo[i] == 0 && */ bien_nho_bong_trong_silo[silo_sap_bo] == 0)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if (bien_nhan_bong == 1 || bien_nho_bong_trong_silo[0] == 1)
                                break;
                        }
                    }
                }
                if (bien_di_chuyen == 1)
                {
                    for (silo_sap_bo = silo_so - 1; silo_sap_bo > 0; silo_sap_bo--)
                    {
                        if (/*bien_nho_bong_da_tha_trong_silo[i] == 0 &&*/ bien_nho_bong_trong_silo[silo_sap_bo] == 0)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if (bien_nhan_bong == 1 || bien_nho_bong_trong_silo[0] == 1)
                                break;
                        }
                    }
                }
                if (bien_nhan_bong == 1 || bien_nho_bong_trong_silo[0] == 1)
                    break;
            }
        }
        if (bien_nho_bong_trong_silo[0] == 1)
        {
            for (bien_di_chuyen = 0; bien_di_chuyen < 2; bien_di_chuyen++)
            {
                if (bien_di_chuyen == 0)
                {
                    for (silo_sap_bo = silo_so + 1; silo_sap_bo < 6; silo_sap_bo++)
                    {
                        if (bien_nho_bong_da_tha_trong_silo[silo_sap_bo] != 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if (bien_nhan_bong == 1)
                                break;
                        }
                        else if (bien_nho_bong_da_tha_trong_silo[silo_sap_bo] == 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if (bien_nhan_bong == 1)
                                break;
                        }
                    }
                }
                if (bien_di_chuyen == 1)
                {
                    for (silo_sap_bo = silo_so - 1; silo_sap_bo > 0; silo_sap_bo--)
                    {
                        if (bien_nho_bong_da_tha_trong_silo[silo_sap_bo] != 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if (bien_nhan_bong == 1)
                                break;
                        }
                        else if (bien_nho_bong_da_tha_trong_silo[silo_sap_bo] == 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if (bien_nhan_bong == 1)
                                break;
                        }
                    }
                }
                if (bien_nhan_bong == 1)
                    break;
            }
        }
    }
}

void di_chuyen_len_1() // di chuyen len silo 1
{
    RESET_ENCODER();

    silo_so = 1;

    duong_di_silo();
}

void di_chuyen_len_2() // di chuyen len silo 2
{
    RESET_ENCODER();

    silo_so = 2;

    duong_di_silo();
}

void di_chuyen_len_3() // di chuyen len silo 3
{
    RESET_ENCODER();

    silo_so = 3;

    duong_di_silo();
}

void di_chuyen_len_4() // di chuyen len silo 4
{
    RESET_ENCODER();

    silo_so = 4;

    duong_di_silo();
}
void di_chuyen_len_5() // di chuyen len silo 5
{
    RESET_ENCODER();

    silo_so = 5;

    duong_di_silo();
}

void do_bong_trong_Analytics()
{
    if (CB_NHAN_DO_TREN == 0 || CB_NHAN_XANH_TREN == 0)
    {
        bien_nhan_bong = 1;
        XL_NONG_HA_BAT;
        Mor_hot_bong = 0;
        Bang_tai = 0;
        delay_ms(500);
        Bang_tai = Mor_nong = 254;
        while (CB_NHAN_DO_TREN == 0 || CB_NHAN_XANH_TREN == 0)
        {
            vTaskDelay(1);
        }
        while (CB_BONG_NONG_RA == 0)
        {
            vTaskDelay(1);
        }
        Bang_tai = Mor_nong = 0;
    }
}
int kiem_tra_dung_tuong_trong_Analystics()
{
    if (CB_TU_DUNG_THANH == 1)
        bien_cham_tuong = 0;
    else
        bien_cham_tuong = 1, delay_ms(500);
    if (ENCODER_TONG() > 3500)
        XL_DONG_90;
    if (ENCODER_TONG() > 5555)
        bien_cham_tuong = 1;
}
void do_bong()
{
    RESET_ENCODER();
    bien_do_bong = 0;
    // bien_chay_cap_thanh = 1;
    bien_nhan_bong = 0;

    Mor_hot_bong = 200, Bang_tai = Mor_nong = 254;
    Mor_hot_bong_vao, Bang_tai_thuan, Mor_nong_ra;
    while (1)
    {
        bat_cam();
        robotRun(1800, 20);
        while (CB_TU_DUNG_THANH == 1 && bien_cham_tuong == 0 && bien_nhan_bong == 0)
        {
            while (CB_TU_DUNG_LAY_BANH == 0)
            {
            }
            robotStop(0);
            delay_ms(400);
        }

        if (bien_do_bong == 1)
        {
            break;
        }
        else if (bien_cham_tuong == 1)
        {
            robotRunAngle(0, 20, 0, 2);
            while (ENCODER_TONG() < 4500)
                ;
        }
    }
}
void XuatPhat()
{
    reset_all();
    vTaskDelay(111);
    if (NUT_CHUYEN_SAN == 1)
    {
        robotRunAngle(0, 50, 0, 1);
        while (ENCODER_TONG() < 300)
        {
            if (wantExit())
                break;
        }

        robotRunAngle(0, 120, 0, 1);
        while (ENCODER_TONG() < 4000)
        {
            if (wantExit())
                break;
        }

        robotRunAngle(30, 80, 0, 1);
        while (ENCODER_TONG() < 7500)
        {
            if (wantExit())
                break;
        }

        robotRunAngle(200, 50, 0, 1);
        while (laze_0H_Value > 80)
        {
            if (wantExit())
                break;
        }

        robotStop(0);

        for (i = 0; i < 100; i++)
        {
            bam_thanh_laze_doc(900, 50, 0, 2, -50, 30, 0, laze_0H_Value);
            while (laze_8H_Value < 375)
            {
                if (wantExit())
                    break;
                vTaskDelay(1);
            }
        }

        robotStop(0);

        RESET_ENCODER();

        robotRunAngle(0, 70, 0, 2);
        while (ENCODER_TONG() < 4800)
        {
            if (wantExit())
                break;
        }

        // robotRunAngle(0,30,0,0);
        // while(laze_0H_Value > 300){if(wantExit())break;}

        robotStop(0);
        robotRunAngle(900, 30, 900, 1);
        while (absI(robotAngle()) < 900)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotRun(0, 20);
        while (laze_0H_Value > 25)
        {
            if (wantExit())
                break;
        }

        RESET_ENCODER();

        robotRun(0, 5);
        while (ENCODER_TONG() < 100)
        {
            if (wantExit())
                break;
        }

        robotStop(0);
        XL_NONG_HA_TAT;
        XL_TR_NONG_HA_BAT;

        Mor_hot_bong = Bang_tai = Mor_nong = 254;
        Mor_hot_bong_vao, Bang_tai_thuan, Mor_nong_ra;

        reset_all();
        vTaskDelay(111);

        robotRunAngle(1800, 50, 0, 2);
        while (ENCODER_TONG() < 6800)
        {
            if (wantExit())
                break;
        }
        robotStop(0);

        robotRotate(450, 2, 0);
        while (robotFixAngle())
        {
            vTaskDelay(1);
        }

        robotStop(0);

        XL_MO_90;
        XL_TR_NONG_HA_TAT;
    }
    /**********************************SAN XANH***********************************/
    else
    {
        robotRunAngle(0, 50, 0, 1);
        while (ENCODER_TONG() < 300)
        {
            if (wantExit())
                break;
        }

        robotRunAngle(0, 120, 0, 1);
        while (ENCODER_TONG() < 4000)
        {
            if (wantExit())
                break;
        }

        robotRunAngle(20, 80, 0, 1);
        while (ENCODER_TONG() < 7500)
        {
            if (wantExit())
                break;
        }
        robotRunAngle(-200, 50, 0, 1);
        while (laze_0H_Value > 80)
        {
            if (wantExit())
                break;
        }

        robotStop(0);

        for (i = 0; i < 100; i++)
        {
            bam_thanh_laze_doc(-900, 50, 0, 2, 50, 35, 0, laze_0H_Value);
            while (laze_4H_Value < 350)
            {
                if (wantExit())
                    break;
                vTaskDelay(1);
            }
        }

        robotStop(0);

        RESET_ENCODER();

        robotRunAngle(0, 70, 0, 2);
        while (ENCODER_TONG() < 4500)
        {
            if (wantExit())
                break;
        }

        robotRunAngle(0, 30, 0, 0);
        while (laze_0H_Value > 300)
        {
            if (wantExit())
                break;
        }

        robotStop(0);
        robotRunAngle(-900, 30, -900, 2);
        while (absI(robotAngle()) < 900)
        {
            if (wantExit())
                break;
            vTaskDelay(1);
        }

        robotRun(0, 20);
        while (laze_0H_Value > 30)
        {
            if (wantExit())
                break;
        }

        RESET_ENCODER();

        robotRun(0, 5);
        while (ENCODER_TONG() < 300)
        {
            if (wantExit())
                break;
        }

        robotStop(0);
        XL_NONG_HA_BAT;
        reset_all();
        vTaskDelay(111);

        for (i = 0; i < 50; i++)
        {
            robotRunAngle(1800, 50, 0, 2);
            while (ENCODER_TONG() < 7000)
            {
                if (wantExit())
                    break;
            }
        }
        robotStop(0);

        robotRotate(-450, 2, 0);
        while (robotFixAngle())
        {
            vTaskDelay(1);
        }

        robotStop(0);

        XL_MO_90;
    }
}
void di_chuyen_len_bo_bong_thu_3()
{
    if (bien_nho_silo_co_2_bong == 1)
    {
        di_chuyen_len_1();
    }
    if (bien_nho_silo_co_2_bong == 2)
    {
        di_chuyen_len_2();
    }
    if (bien_nho_silo_co_2_bong == 3)
    {
        di_chuyen_len_3();
    }
    if (bien_nho_silo_co_2_bong == 4)
    {
        di_chuyen_len_4();
    }
    if (bien_nho_silo_co_2_bong == 5)
    {
        di_chuyen_len_5();
    }
}

void di_chuyen_len()
{
    if (bien_nho_bong_trong_silo[0] == 1)
    {
        if (bai == 2)
        {
            for (silo_sap_bo = 5; silo_sap_bo >= 1; silo_sap_bo--)
            {
                if (bien_nho_bong_da_tha_trong_silo[silo_sap_bo] != 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                {
                    silo_so = silo_sap_bo;
                    break;
                }
                else if (bien_nho_bong_da_tha_trong_silo[silo_sap_bo] == 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                {
                    silo_so = silo_sap_bo;
                    break;
                }
            }
        }
        else
        {
            for (silo_sap_bo = 1; silo_sap_bo <= 5; silo_sap_bo++)
            {
                if (bien_nho_bong_da_tha_trong_silo[silo_sap_bo] != 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                {
                    silo_so = silo_sap_bo;
                    break;
                }
                else if (bien_nho_bong_da_tha_trong_silo[silo_sap_bo] == 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                {
                    silo_so = silo_sap_bo;
                    break;
                }
            }
        }
        if (silo_so == 5)
        {
            di_chuyen_len_5();
        }
        else if (silo_so == 4)
        {
            di_chuyen_len_4();
        }
        else if (silo_so == 3)
        {
            di_chuyen_len_3();
        }
        else if (silo_so == 2)
        {
            di_chuyen_len_2();
        }
        else if (silo_so == 1)
        {
            di_chuyen_len_1();
        }
    }
    else
    {
        // random_exclude(exclude_list,exclude_count);
        for (silo_sap_bo = 1; silo_sap_bo < 6; silo_sap_bo++)
        {
            if (bien_nho_bong_trong_silo[silo_sap_bo] == 0)
            {
                silo_so = silo_sap_bo;
                break;
            }
        }

        // for(silo_sap_bo=1;silo_sap_bo<3;silo_sap_bo++)
        // {
        //     if(bien_nho_bong_trong_silo[silo_sap_bo] != 3)
        //     {
        //         silo_so = silo_sap_bo;
        //         break;
        //     }
        // }
        if (silo_so == 4)
        {
            di_chuyen_len_4();
        }
        else if (silo_so == 3)
        {
            di_chuyen_len_3();
        }
        else if (silo_so == 2)
        {
            di_chuyen_len_2();
        }
        else if (silo_so == 1)
        {
            di_chuyen_len_1();
        }
        else if (silo_so == 5)
        {
            di_chuyen_len_5();
        }
    }
}

void quy_trinh_lua_bong_up_silo()
{
    do_bong();
    if (silo_so == 1)
        di_chuyen_len_1();
    else if (silo_so == 2)
        di_chuyen_len_2();
    else if (silo_so == 3)
        di_chuyen_len_3();
    else if (silo_so == 4)
        di_chuyen_len_4();
    else if (silo_so == 5)
        di_chuyen_len_5();
    while (1)
    {
        nhan_bong_trong_silo();
        while (bien_nhan_bong == 0)
        {
            nhan_bong_trong_silo();
            if (bien_nhan_bong == 1)
            {
                tha_bong();
                break;
            }
            else
                di_chuyen();
        }
        break;
    }
    bien_nhan_bong = 0;
    di_chuyen_ve();
    while (1)
    {
        do_bong();
        if (bien_nho_silo_co_2_bong != 0)
        {
            di_chuyen_len_bo_bong_thu_3();
            bien_nho_silo_co_2_bong = 0;
        }
        else
        {
            di_chuyen_len();
        }
        while (bien_nhan_bong == 0)
        {
            nhan_bong_trong_silo();
            if (bien_nhan_bong == 1)
                tha_bong(), di_chuyen_ve();
            else
                di_chuyen();
        }
        bien_nhan_bong = 0;
    }
}

void XuatPhatRetry()
{
    reset_all();
    vTaskDelay(111);
    if (NUT_CHUYEN_SAN == 1)
    {
        robotRunAngle(-450, 40, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (laze_8H_Value > 55)
            {
                vTaskDelay(1);
            }
        robotRunAngle(0, 60, 0, 0.5);
        RESET_ENCODER();
        for (i = 0; i < 50; i++)
            while (ENCODER_TONG() < 3900)
            {
                vTaskDelay(1);
            }
        robotRunAngle(0, 20, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (laze_0H_Value > 153)
            {
                vTaskDelay(1);
            }
        RESET_ENCODER();
        robotRunAngle(-900, 60, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (ENCODER_TONG() < 5800)
            {
                vTaskDelay(1);
            }

        robotRunAngle(-900, 40, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (laze_8H_Value > 175)
            {
                vTaskDelay(1);
            }

        RESET_ENCODER();
        robotRunAngle(-1800, 40, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (ENCODER_TONG() < 2000)
            {
                vTaskDelay(1);
            }
    }
    /**********************************SAN XANH***********************************/
    else
    {
        robotRunAngle(450, 40, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (laze_4H_Value > 50)
            {
                vTaskDelay(1);
            }
        robotRunAngle(0, 60, 0, 0.5);
        RESET_ENCODER();
        for (i = 0; i < 50; i++)
            while (ENCODER_TONG() < 3900)
            {
                vTaskDelay(1);
            }
        robotRunAngle(0, 20, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (laze_0H_Value > 165)
            {
                vTaskDelay(1);
            }
        RESET_ENCODER();
        robotRunAngle(900, 60, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (ENCODER_TONG() < 3500)
            {
                vTaskDelay(1);
            }

        robotRunAngle(900, 40, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (laze_4H_Value > 200)
            {
                vTaskDelay(1);
            }

        RESET_ENCODER();
        robotRunAngle(-1800, 40, 0, 0.5);
        for (i = 0; i < 50; i++)
            while (ENCODER_TONG() < 2600)
            {
                vTaskDelay(1);
            }
        delay_ms(500);
        robotStop(0);
        while (1)
        {
            vTaskDelay(1);
        }
    }
}

void retry()
{
    XuatPhatRetry();

    do_bong();

    di_chuyen_len_5();

    kiem_tra_di_chuyen();

    tha_bong();

    di_chuyen_ve();

    while (1)
    {
        do_bong();

        if (bien_nho_silo_co_2_bong != 0)
        {
            di_chuyen_len_bo_bong_thu_3();
            kiem_tra_di_chuyen();
            tha_bong();
            di_chuyen_ve();
            bien_nho_silo_co_2_bong = 0;
        }
        else
        {
            di_chuyen_len();

            kiem_tra_di_chuyen();
            tha_bong();
            di_chuyen_ve();
        }
        bien_nhan_bong = 0;
    }
}

///////////////////////////////////////////////// THI ROBOCON ////////////////////////////////////////////////////
void THI()
{
    // XuatPhat();

    robotRotate(450, 2, 0);
    while (robotFixAngle())
    {
        vTaskDelay(1);
    }

    robotStop(0);
    XL_MO_90;
    XL_NONG_HA_TAT;
    XL_TR_NONG_HA_BAT;
    delay_ms(1500);
    XL_TR_NONG_HA_TAT;

    do_bong();

    di_chuyen_len_5();

    kiem_tra_di_chuyen();

    tha_bong();

    di_chuyen_ve();

    while (1)
    {
        do_bong();

        if (bien_nho_silo_co_2_bong != 0)
        {
            di_chuyen_len_bo_bong_thu_3();
            kiem_tra_di_chuyen();
            tha_bong();
            di_chuyen_ve();
            bien_nho_silo_co_2_bong = 0;
        }
        else
        {
            di_chuyen_len();

            kiem_tra_di_chuyen();

            tha_bong();

            di_chuyen_ve();
        }
        bien_nhan_bong = 0;
    }
}

void bai1()
{
    XuatPhat();

    for (silo_sap_bo = 1; silo_sap_bo < 4; silo_sap_bo++)
    {
        do_bong();

        if (silo_sap_bo == 1)
            di_chuyen_len_1();

        if (silo_sap_bo == 2)
            di_chuyen_len_2();

        if (silo_sap_bo == 3)
            di_chuyen_len_3();

        tha_bong();

        bien_nho_bong_trong_silo[silo_so]++;

        di_chuyen_ve();
    }

    while (1)
    {
        do_bong();

        if (bien_nho_silo_co_2_bong != 0)
        {
            di_chuyen_len_bo_bong_thu_3();
            kiem_tra_di_chuyen();
            tha_bong();
            di_chuyen_ve();
            bien_nho_silo_co_2_bong = 0;
        }
        else
        {
            di_chuyen_len();

            kiem_tra_di_chuyen();

            tha_bong();

            di_chuyen_ve();
        }
        bien_nhan_bong = 0;
    }
}

void bai2()
{
    XuatPhat();

    for (silo_sap_bo = 1; silo_sap_bo < 4; silo_sap_bo++)
    {
        do_bong();
        bien_ve_xuat_phat = 1;

        if (silo_sap_bo == 1)
            di_chuyen_len_3();

        if (silo_sap_bo == 2)
            di_chuyen_len_4();

        if (silo_sap_bo == 3)
            di_chuyen_len_5();

        tha_bong();

        bien_nho_bong_trong_silo[silo_so]++;

        di_chuyen_ve();
    }

    while (1)
    {
        do_bong();

        if (bien_nho_silo_co_2_bong != 0)
        {
            di_chuyen_len_bo_bong_thu_3();

            kiem_tra_di_chuyen();

            tha_bong();

            di_chuyen_ve();

            bien_nho_silo_co_2_bong = 0;
        }
        else
        {
            di_chuyen_len();

            kiem_tra_di_chuyen();

            tha_bong();

            di_chuyen_ve();
        }
        bien_nhan_bong = 0;
    }
}

void test()
{
}

void dung_ct()
{
    if (bien_nho_bong_trong_silo[1] == 3 && bien_nho_bong_trong_silo[2] == 3 && bien_nho_bong_trong_silo[3] == 3 && bien_nho_bong_trong_silo[4] == 3 && bien_nho_bong_trong_silo[5] == 3)
    {
        bien_nho_bong_trong_silo[0] = 3;
    }
}

////////////////-********************************SON*==============================================================================================

void restartDo()
{
    reset_all();
    robotRunAngle(-450, 40, 0, 0.5);
    for (i = 0; i < 50; i++)
        while (laze_8H_Value > 55)
        {
            vTaskDelay(1);
        }
    robotRunAngle(0, 60, 0, 0.5);
    RESET_ENCODER();
    for (i = 0; i < 50; i++)
        while (ENCODER_TONG() < 3900)
        {
            vTaskDelay(1);
        }
    robotRunAngle(0, 20, 0, 0.5);
    for (i = 0; i < 50; i++)
        while (laze_0H_Value > 153)
        {
            vTaskDelay(1);
        }
    RESET_ENCODER();
    robotRunAngle(-900, 60, 0, 0.5);
    for (i = 0; i < 50; i++)
        while (ENCODER_TONG() < 5800)
        {
            vTaskDelay(1);
        }

    robotRunAngle(-900, 40, 0, 0.5);
    for (i = 0; i < 50; i++)
        while (laze_8H_Value > 175)
        {
            vTaskDelay(1);
        }

    RESET_ENCODER();
    robotRunAngle(-1800, 40, 0, 0.5);
    for (i = 0; i < 50; i++)
        while (ENCODER_TONG() < 2000)
        {
            vTaskDelay(1);
        }

check_bong:
    while (GP_BTN[1] != 22)
    {
        if (GP_BTN[1] == 33)
            robotRunAngle(-900, 20, 0, -0.5);
        else if (GP_BTN[1] == 11)
            robotRunAngle(900, 20, 0, 0.5);
        if (laze_4H_Value < 50)
        {
            XL_NONG_XOAY_BAT;
            vTaskDelay(1000);
        }
        else
        {
            XL_NONG_XOAY_TAT;
            vTaskDelay(1000);
        }
    }
    robotStop(0);
    robotRunAngle(-1800, 20, 0, -0.5);
    bien_nhan_bong = 0;
    bien_cham_tuong = 0;
    while (CB_TU_DUNG_THANH == 1 && bien_cham_tuong == 0 && bien_nhan_bong == 0)
    {
        XL_MO_90;
        XL_NONG_HA_TAT;
        robotRunAngle(-1800, 20, 0, -0.5);
        Mor_hot_bong = 200, Bang_tai = Mor_nong = 254;
        Mor_hot_bong_vao, Bang_tai_thuan, Mor_nong_ra;
        if (CB_NHAN_DO_TREN == 0 || CB_NHAN_XANH_TREN == 0)
        {
            bien_nhan_bong = 1;
            Mor_hot_bong = Bang_tai = 0;
            break;
        }
        while (CB_TU_DUNG_LAY_BANH == 1)
        {
            robotStop(0);
            vTaskDelay(10);
        }

        vTaskDelay(1);
    }
    robotStop(0);
    delay_ms(500);
    if (bien_nhan_bong == 1)
    {
        XL_DONG_90;
        XL_NONG_HA_BAT;
        Bang_tai = Mor_nong = 254;

        while (CB_BONG_NONG_RA == 0)
        {
            Bang_tai = Mor_nong = 254;
            vTaskDelay(1);
        }
        Bang_tai = Mor_nong = 0;
    }

    delay_ms(200);
    robotStop(0);
}
