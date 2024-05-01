void reset_all()
{
    robotResetIMU();
    RESET_ENCODER();
    vTaskDelay(10);
}
void laze_chay_silo(int silo_sap_chay)
{
// *************************SAN DO*****************************
        if     (silo_sap_chay == 1)            do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
        else if(silo_sap_chay == 2)            do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
        else if(silo_sap_chay == 3)            do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
        else if(silo_sap_chay == 4)            do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
        else if(silo_sap_chay == 5)            do_laze_silo = laze_silo[NUT_CHUYEN_SAN][silo_so];
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

void di_chuyen_ve()
{   
    reset_all();
    vTaskDelay(111);
    XL_NONG_HA_TAT;
    XL_TR_NONG_HA_BAT;

/********************SAN DO******************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        for(noise=0;noise<50;noise++)
        {
            while (laze_4H_Value > 230 || ENCODER_TONG() < 3000)
            {
                bam_thanh_laze_ngang(1800, 50, 0, 2, 650, 250, 0, laze_8H_Value);
                if(wantExit())  break;
            }
        }

        RESET_ENCODER();

        robotRunAngle(1800, 50, 0, 2);
        while(ENCODER_TONG() < 4800){if(wantExit())break;}

        robotStop(0);

        robotRotate(900,1,0);                     // có thể đang bị đứng ở chỗ này cần fix 21h06 25/4
        while(robotFixAngle()){vTaskDelay(1);}

        while(laze_4H_Value > 35 || ENCODER_TONG() < 300)
        {
            robotRunAngle(1800, absI(laze_4H_Value - 30), 900, 2);
            if(wantExit())  break;
        }

        XL_MO_90;

        robotStop(0);
    }
    /*////////////////////////////SAN XANH///////////////////////*/
    else
    {
        if(laze_4H_Value > 242)
        {
            robotRunAngle(1250, 50, 0, 2);
            while(laze_4H_Value > 242){if(wantExit()) break;}
        }
        else
        {
            robotRunAngle(-1250, 50, 0, 2);
            while(laze_4H_Value < 242){if(wantExit()) break;}
        }

        while(laze_8H_Value > 350)
        {
            bam_thanh_laze_ngang(1800, 50, 0, 2, 80, 242, 0, laze_4H_Value);
            if(wantExit())  break;
        }

        RESET_ENCODER();

        robotRunAngle(1800, 50, 0, 2);
        while(ENCODER_TONG() < 5200){if(wantExit())break;}

        robotStop(0);

        robotRotate(-900,1,0);                     // có thể đang bị đứng ở chỗ này cần fix 21h06 25/4
        while(robotFixAngle()){vTaskDelay(1);}

        robotStop(0);
    }
    XL_MO_90;
    XL_TR_NONG_HA_TAT;
}

void kiem_tra_lech_IMU()
{
    if(abs(robotAngle()) > 0)
    {
        robotRotate(0, 0.5, 0);
        while(robotFixAngle()){vTaskDelay(1);}
        // robotRotateStop();
    }
}

void kiem_tra_cap_thanh()
{
    // while(CB_CAP_THANH_TRAI == 1 || CB_CAP_THANH_PHAI == 1)
    // {
        // for(noise=0;noise<100;noise++)
        // {
            // robotStop(0);
            while (CB_CAP_THANH_TRAI == 0)
            {
                robotRotateFree(-0.9,0);
            }
            while (CB_CAP_THANH_PHAI  == 0)
            {
                robotRotateFree(0.9,0);
            }
        // }
    // }
    // reset_all();
}

void duong_di_silo()
{
    laze_chay_silo(silo_so);
    bien_nhan_bong = 0;
    robotStop(0);
    XL_NONG_XOAY_BAT;

/****************************************SAN DO****************************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        while(laze_4H_Value < 350)
        {
            bam_thanh_laze_ngang(0, 50, 0, 2, -350, 175, 10, laze_8H_Value);
            if(wantExit())  break;
        }

        if(laze_8H_Value > do_laze_silo)
        {
            robotRunAngle(-700, 50, 0, 2);
            while(laze_8H_Value > do_laze_silo+30)
            {
                if(wantExit())  break;
            }
        }
        else
        {
            robotRunAngle(700, 50, 0, 2);
            while(laze_8H_Value < do_laze_silo-30)
            {
                if(wantExit())  break;
            }
        }

        for(noise=0;noise<100;noise++)
        {
            do
            {
                bam_thanh_laze_ngang(0, absI((laze_0H_Value - 10)/2), 0, 2, -150, do_laze_silo-5, 0, laze_8H_Value);
                if(wantExit())  break;
            }
            while(laze_0H_Value > 40);
        }
        robotRunAngle(0, 5, 0, 2);
        while(laze_0H_Value > 22){if(wantExit())break;}

        while(CB_TU_NHAN_SILO == 1)
        {
            if(laze_8H_Value > do_laze_silo)
            {
                robotRun(-750, 5);
            }
            else
            {
                robotRun(750, 5);
            }
            kiem_tra_cap_thanh();
        }
        robotStop(0);
        robotRun(0, 10);
        delay_ms(100);
        robotStop(0);
    }
/****************************************SAN XANH***************************************/
    else    
    {
        while(laze_8H_Value < 350)
        {
            bam_thanh_laze_ngang(0, 50, 0, 2, 350, do_laze_silo, 0, laze_4H_Value);
            if(wantExit())  break;
        }
        for(i=0;i<100;i++)
        {
            while(laze_0H_Value > 30)
            {
                bam_thanh_laze_ngang(0, absI((laze_0H_Value - 10))<10? 5:absI((laze_0H_Value - 10)), 0, 2, 150, do_laze_silo, 0, laze_4H_Value);
                if(wantExit())  break;
            }
        }
        robotStop(0);
    }
}

void di_chuyen()        //viet lai di chuyen --> dung laze de chay
{
/****************************************SAN DO****************************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        laze_chay_silo(silo_so);
/*
    neu silo_so = 1 || silo_so = 5 thi cho di huong nguoc lai
*/
        if(bien_di_chuyen == 1)                           //di chuyen sang trai
        {
            robotRun(850, 25);
            while(laze_8H_Value < do_laze_silo-30){if(wantExit())break;}

            while(CB_TU_NHAN_SILO == 1)
            {
                if(laze_8H_Value > do_laze_silo)
                {
                    robotRunAngle(-900, 5, 0, 2);
                }
                else
                {
                    robotRunAngle(900, 5, 0, 2);
                }
                kiem_tra_cap_thanh();
            }
        }
        else if(bien_di_chuyen == 0)                      //di chuyen sang phai
        {
            robotRun(-850, 25);
            while(laze_8H_Value > do_laze_silo+30){if(wantExit())break;}

            while(CB_TU_NHAN_SILO == 1)
            {
                if(laze_8H_Value > do_laze_silo)
                {
                    robotRunAngle(-900, 5, 0, 2);
                }
                else
                {
                    robotRunAngle(900, 5, 0, 2);
                }
                kiem_tra_cap_thanh();
            }
        }
    }
/****************************************SAN XANH****************************************/
    else
    {
        laze_chay_silo(silo_so);
        if(bien_di_chuyen == 1)                           //di chuyen sang phai
        {
            // robotRun(-850, 25);
            // while(laze_4H_Value < do_laze_silo-44){if(wantExit())break;}
            // robotRun(-850, 10);
            // while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}

            for(i=0;i<50;i++)
            {
                while(laze_4H_Value < do_laze_silo)
                {
                    bam_thanh_laze_doc(-900, 20, 0, 2, 20, 22, 0, laze_0H_Value);
                }
            }
            robotStop(0);        
        }
        else if(bien_di_chuyen == 0)                      //di chuyen sang trai
        {
            // robotRun(820, 25);
            // while(laze_4H_Value > do_laze_silo+44){if(wantExit())break;}
            // robotRun(850, 10);
            // while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            for(i=0;i<50;i++)
            {
                while(laze_4H_Value > do_laze_silo)
                {
                    bam_thanh_laze_doc(900, 20, 0, 2, 20, 22, 0, laze_0H_Value);
                }
            }
            robotStop(0);  
        }
    }
}

void nhan_bong_trong_silo()
{
    if(CB_BONG_1 == 1)                                                              //chua co bong thi tha bong roi cho so bong = 1
    {
        bien_nhan_bong = 1;
        bien_nho_bong_trong_silo[silo_so] = 1;
    }

    else if(CB_BONG_1 == 0 && CB_BONG_2 == 0 && CB_BONG_3 == 0)                     //silo da co 3 bong va bo qua 
    {
        bien_nhan_bong = 0;
        bien_nho_bong_trong_silo[silo_so] = 3;
    }
    else if(CB_BONG_1 == 0 && CB_BONG_2 == 0)                                       //co 2 bong thi tha bong roi cho so bong = 3
    {
        bien_nhan_bong = 1;
        bien_nho_bong_trong_silo[silo_so] = 3;
    }
/*
    co 1 bong thi kiem tra:
    - neu tat ca da 1 bong thi tha bong va len so bong 2
    - neu khong thi di chuyen theo huong da cai
*/
    else if(CB_BONG_1 == 0)
    {
        if(bien_nho_bong_trong_silo[0] == 1)    bien_nho_bong_trong_silo[silo_so] = 2, bien_nho_silo_co_2_bong = silo_so, bien_nhan_bong = 1;
        else                                    bien_nhan_bong = 0, bien_nho_bong_trong_silo[silo_so] = 1;
    }
    if(bien_nho_bong_trong_silo[5] >= 1 && bien_nho_bong_trong_silo[1] >= 1 && bien_nho_bong_trong_silo[2] >= 1 && bien_nho_bong_trong_silo[3] >= 1 && bien_nho_bong_trong_silo[4] >= 1)
    {
        bien_nho_bong_trong_silo[0]=1;
    }
}

void kiem_tra_di_chuyen()
{
    nhan_bong_trong_silo();
    while(bien_nhan_bong == 0)
    {
        if(bien_nho_bong_trong_silo[0] == 0)
        {
            for(bien_di_chuyen = 0; bien_di_chuyen < 2; bien_di_chuyen++)
            {
                if(bien_di_chuyen == 0)
                {
                    for (silo_sap_bo = silo_so+1; silo_sap_bo < 6; silo_sap_bo++)
                    {
                        if(/*bien_nho_bong_da_tha_trong_silo[i] == 0 && */bien_nho_bong_trong_silo[silo_sap_bo] == 0)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1 || bien_nho_bong_trong_silo[0] == 1) break;
                        }
                    }
                }
                if(bien_di_chuyen == 1)
                {
                    for (silo_sap_bo = silo_so-1; silo_sap_bo > 0; silo_sap_bo--)
                    {
                        if(/*bien_nho_bong_da_tha_trong_silo[i] == 0 &&*/ bien_nho_bong_trong_silo[silo_sap_bo] == 0)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1 || bien_nho_bong_trong_silo[0] == 1) break;
                        }
                    }
                }
                if(bien_nhan_bong == 1 || bien_nho_bong_trong_silo[0] == 1) break;
            }
        }
        if(bien_nho_bong_trong_silo[0] == 1)
        {
            for(bien_di_chuyen = 0; bien_di_chuyen < 2; bien_di_chuyen++)
            {
                if(bien_di_chuyen == 0)
                {
                    for (silo_sap_bo = silo_so+1; silo_sap_bo < 6; silo_sap_bo++)
                    {
                        if(bien_nho_bong_da_tha_trong_silo[silo_sap_bo] != 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1) break;
                        }
                        else if(bien_nho_bong_da_tha_trong_silo[silo_sap_bo] == 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1) break;
                        }
                    }
                }
                if(bien_di_chuyen == 1)
                {
                    for (silo_sap_bo = silo_so-1; silo_sap_bo > 0; silo_sap_bo--)
                    {
                        if(bien_nho_bong_da_tha_trong_silo[silo_sap_bo] != 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1) break;
                        }
                        else if(bien_nho_bong_da_tha_trong_silo[silo_sap_bo] == 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                        {
                            silo_so = silo_sap_bo;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1) break;
                        }
                    }
                }
                if(bien_nhan_bong == 1) break;
            }
        }
    }
}


void di_chuyen_len_1()                              //di chuyen len silo 1
{
    RESET_ENCODER();

    silo_so = 1;

    duong_di_silo();
}

void di_chuyen_len_2()                              //di chuyen len silo 2
{
    RESET_ENCODER();

    silo_so = 2;

    duong_di_silo();
}

void di_chuyen_len_3()                              //di chuyen len silo 3
{
    RESET_ENCODER();

    silo_so = 3;

    duong_di_silo();
}

void di_chuyen_len_4()                              //di chuyen len silo 4
{
    RESET_ENCODER();

    silo_so = 4;

    duong_di_silo();
}
void di_chuyen_len_5()                              //di chuyen len silo 5
{
    RESET_ENCODER();

    silo_so = 5;

    duong_di_silo();
}

void do_bong_trong_Analytics()
{
    if(CB_NHAN_DO_TREN == 0 || CB_NHAN_XANH_TREN == 0)    
    {
        robotStop(0);
        bien_do_bong = 1;
        XL_TR_NONG_HA_TAT;
        XL_NONG_HA_BAT;
        Mor_hot_bong = Bang_tai = 0;
        delay_ms(500);
        Bang_tai = 254;
        while(1)
        {
            while(CB_NHAN_DO_TREN == 0 || CB_NHAN_XANH_TREN == 0){}
            // Mor_nong = Bang_tai = 0;
            // delay_ms(10000);
            while(CB_BONG_NONG_RA == 0){}
            Mor_nong = Bang_tai = 0;
            break;
        }
        XL_NONG_XOAY_BAT;
    }
}
int kiem_tra_dung_tuong_trong_Analystics()
{
    if(bien_ve_xuat_phat == -30)
    {
        if(bien_do_bong == 0)
        {
            if(ENCODER_TONG() > 2000 || CB_TU_DUNG_THANH == 0)  
            {
                bien_cham_tuong = 1;
                bien_ve_xuat_phat = 0;
                XL_DONG_90;
                delay_ms(500);
            }
            if(ENCODER_TONG() > 2000)   XL_DONG_90;
            
        }
    }
    else
    {
        if(CB_TU_DUNG_THANH == 1)   bien_cham_tuong = 0;
        else                        bien_cham_tuong = 1,delay_ms(500);
        if(ENCODER_TONG() > 3500)   XL_DONG_90;
        if(ENCODER_TONG() > 5555)   bien_cham_tuong = 1;
    }
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
        robotRun(1800, 20);
        while(CB_TU_DUNG_THANH == 1 && CB_TU_DUNG_LAY_BANH == 0 && bien_cham_tuong == 0 && bien_nhan_bong == 0)
        {
            if(wantExit())  break;
        }

        robotStop(0);
        delay_ms(400);

        if(bien_do_bong == 1)   
        {
            en = ENCODER_TONG();
            RESET_ENCODER();
            while(ENCODER_TONG() < en*1/5){robotRun(0, 30),XL_NONG_HA_TAT,XL_DONG_90;}

            robotStop(0);
            
            robotRunAngle(0, 30, 0, 1);
            while (absI(robotAngle()) > 2)
            {
                if(wantExit())  break;
                vTaskDelay(1);
            }
            break;
        }
        else if(bien_cham_tuong == 1)
        {
            en = ENCODER_TONG();
            RESET_ENCODER();
/*********************************SAN DO*********************************/
            if(NUT_CHUYEN_SAN == 1)
            {
                for(noise = 0; noise < 50; noise++)
                {
                    while(ENCODER_TONG() < en*4/5)
                    {
                        robotRunAngle(900, 50, 900, 2);
                        if(wantExit())break;
                    }
                }
                if(bien_chay_cap_thanh % 3 == 0)
                {
                    RESET_ENCODER();
                    for(noise=0;noise<50;noise++)
                    {
                        // robotRun(900, 20);
                        // while(laze_4H_Value > 40){if(wantExit())break;}
                        while(laze_4H_Value > 35 || ENCODER_TONG() < 300)
                        {
                            robotRunAngle(1800, absI(laze_4H_Value - 30), 900, 2);
                            if(wantExit())  break;
                        }
                    }
                    XL_NONG_XOAY_BAT;

                    bien_chay_cap_thanh = 1;
                }
                else
                {
                    bien_chay_cap_thanh+=1;
                    RESET_ENCODER();
                    robotRun(-900,20);
                    while(ENCODER_TONG() < 1000){if(wantExit()) break;}
                }
                XL_MO_90;
                RESET_ENCODER();
            }
/*********************************SAN XANH*********************************/
            else
            {
                for(noise = 0; noise < 50; noise++)
                {
                    while(laze_0H_Value > 100)
                    {   
                        robotRunAngle(-900, absI((laze_0H_Value - 100)/2), -900, 2);
                        if(wantExit())break;
                    }
                }
                if(bien_chay_cap_thanh % 3 == 0)
                {
                    robotStop(0);
                    robotRotate(-900, 1, 0);
                    while(robotFixAngle()){vTaskDelay(1);}
                    robotStop(0);

                    // robotRun(-900, 15);
                    // while(laze_8H_Value > 40){if(wantExit())break;}

                    for(noise=0;noise<50;noise++)
                    {
                        while(laze_8H_Value > 40)
                        {
                            robotRun(-900, absI((40-laze_8H_Value)/2));
                        }
                    }

                    bien_chay_cap_thanh = 1;
                }
                else
                {
                    bien_chay_cap_thanh+=1;
                    RESET_ENCODER();
                    // robotRun(900,20);
                    // while(ENCODER_TONG() < 1500){if(wantExit()) break;}
                    for(noise=0;noise<50;noise++)
                    {
                        while(laze_8H_Value < 100)
                        {
                            robotRun(900, (laze_8H_Value - 100) < 15? 10 : absI(laze_8H_Value - 100));
                        }
                    }
                }
            }
        }
    }
}

void XuatPhat()
{
    reset_all();
    vTaskDelay(111);
    if(NUT_CHUYEN_SAN == 1)
    {
        robotRunAngle(0, 50, 0, 1);
        while(ENCODER_TONG() < 300){if(wantExit())break;}

        robotRunAngle(0, 120, 0, 1);
        while(ENCODER_TONG() < 4000){if(wantExit())break;}

        robotRunAngle(30, 80, 0, 1);
        while(ENCODER_TONG() < 7500){if(wantExit())break;}

        robotRunAngle(200, 50, 0, 1);
        while(laze_0H_Value > 80){if(wantExit())break;}

        robotStop(0);

        for(i=0;i<100;i++)   
        {
            bam_thanh_laze_doc(900, 50, 0, 2, -50, 30, 0, laze_0H_Value);
            while(laze_8H_Value < 375)
            {
                if(wantExit())break;
                vTaskDelay(1);
            }
        }

        robotStop(0);

        RESET_ENCODER();

        robotRunAngle(0,70,0,2);
        while(ENCODER_TONG() < 4800){if(wantExit())break;}

        // robotRunAngle(0,30,0,0);
        // while(laze_0H_Value > 300){if(wantExit())break;}

        robotStop(0);
        robotRunAngle(900, 30, 900, 1);
        while (absI(robotAngle()) < 900)
        {
            if(wantExit())  break;
            vTaskDelay(1);
        }

        robotRun(0, 20);
        while(laze_0H_Value > 25){if(wantExit())break;}

        RESET_ENCODER();

        robotRun(0, 5);
        while(ENCODER_TONG() < 100){if(wantExit())break;}

        robotStop(0);
        XL_NONG_HA_TAT;
        XL_TR_NONG_HA_BAT;
        
        Mor_hot_bong = Bang_tai = Mor_nong = 254;
        Mor_hot_bong_vao, Bang_tai_thuan, Mor_nong_ra;
        
        reset_all();
        vTaskDelay(111);

        robotRunAngle(1800, 50, 0, 2);
        while(ENCODER_TONG() < 6800){if(wantExit())break;}
        robotStop(0);

        robotRotate(450, 2, 0);
        while(robotFixAngle()){vTaskDelay(1);}

        robotStop(0);

        XL_MO_90;
        XL_TR_NONG_HA_TAT;
    }
/**********************************SAN XANH***********************************/
    else
    {
        robotRunAngle(0, 50, 0, 1);
        while(ENCODER_TONG() < 300){if(wantExit())break;}

        robotRunAngle(0, 120, 0, 1);
        while(ENCODER_TONG() < 4000){if(wantExit())break;}

        robotRunAngle(20, 80, 0, 1);
        while(ENCODER_TONG() < 7500){if(wantExit())break;}
            robotRunAngle(-200, 50, 0, 1);
        while(laze_0H_Value > 80){if(wantExit())break;}

        robotStop(0);

        for(i=0;i<100;i++)   
        {
            bam_thanh_laze_doc(-900, 50, 0, 2, 50, 35, 0, laze_0H_Value);
            while(laze_4H_Value < 350)
            {
                if(wantExit())break;
                vTaskDelay(1);
            }
        }

        robotStop(0);

        RESET_ENCODER();

        robotRunAngle(0,70,0,2);
        while(ENCODER_TONG() < 4500){if(wantExit())break;}

        robotRunAngle(0,30,0,0);
        while(laze_0H_Value > 300){if(wantExit())break;}

        robotStop(0);
        robotRunAngle(-900, 30, -900, 2);
        while (absI(robotAngle()) < 900)
        {
            if(wantExit())  break;
            vTaskDelay(1);
        }

        robotRun(0, 20);
        while(laze_0H_Value > 30){if(wantExit())break;}

        RESET_ENCODER();

        robotRun(0, 5);
        while(ENCODER_TONG() < 300){if(wantExit())break;}

        robotStop(0);
        XL_NONG_HA_BAT;
        reset_all();
        vTaskDelay(111);

        for(i=0;i<50;i++)
        {
            robotRunAngle(1800, 50, 0, 2);
            while(ENCODER_TONG() < 7000){if(wantExit())break;}
        }
        robotStop(0);

        robotRotate(-450, 2, 0);
        while(robotFixAngle()){vTaskDelay(1);}

        robotStop(0);

        XL_MO_90;
    }
}
void di_chuyen_len_bo_bong_thu_3()
{
    if(bien_nho_silo_co_2_bong == 1)
    {
        di_chuyen_len_1();
    }
    if(bien_nho_silo_co_2_bong == 2)
    {
        di_chuyen_len_2();
    }
    if(bien_nho_silo_co_2_bong == 3)
    {
        di_chuyen_len_3();
    }
    if(bien_nho_silo_co_2_bong == 4)
    {
        di_chuyen_len_4();
    }
    if(bien_nho_silo_co_2_bong == 5)
    {
        di_chuyen_len_5();
    }
}

void di_chuyen_len()
{
    if(bien_nho_bong_trong_silo[0] == 1)
    {
        if(bai == 2)
        {
            for(silo_sap_bo = 5; silo_sap_bo >= 1; silo_sap_bo--)
            {
                if(bien_nho_bong_da_tha_trong_silo[silo_sap_bo] != 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                {
                    silo_so = silo_sap_bo;
                    break;
                }
                else if(bien_nho_bong_da_tha_trong_silo[silo_sap_bo] == 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                {
                    silo_so = silo_sap_bo;
                    break;
                }
            }
        }
        else
        {
            for(silo_sap_bo = 1; silo_sap_bo <= 5; silo_sap_bo++)
            {
                if(bien_nho_bong_da_tha_trong_silo[silo_sap_bo] != 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                {
                    silo_so = silo_sap_bo;
                    break;
                }
                else if(bien_nho_bong_da_tha_trong_silo[silo_sap_bo] == 0 && bien_nho_bong_trong_silo[silo_sap_bo] != 3)
                {
                    silo_so = silo_sap_bo;
                    break;
                }
            }
        }
        if(silo_so == 5)
        {
            di_chuyen_len_5();
        }
        else if(silo_so == 4)
        {
            di_chuyen_len_4();
        }
        else if(silo_so == 3)
        {
            di_chuyen_len_3();
        }
        else if(silo_so == 2)
        {
            di_chuyen_len_2();
        }
        else if(silo_so == 1)
        {
            di_chuyen_len_1();
        }
    }
    else
    {
        // for(silo_sap_bo=1;silo_sap_bo<6;silo_sap_bo++)
        // {
        //     if(bien_nho_bong_trong_silo[silo_sap_bo] == 0)
        //     {
        //         silo_so = silo_sap_bo;
        //         break;
        //     }
        // }
        
        // for(silo_sap_bo=1;silo_sap_bo<3;silo_sap_bo++)
        // {
        //     if(bien_nho_bong_trong_silo[silo_sap_bo] != 3)
        //     {
        //         silo_so = silo_sap_bo;
        //         break;
        //     }
        // }
        if(silo_so == 4)
        {
            di_chuyen_len_4();
        }
        else if(silo_so == 3)
        {
            di_chuyen_len_3();
        }
        else if(silo_so == 2)
        {
            di_chuyen_len_2();
        }
        else if(silo_so == 1)
        {
            di_chuyen_len_1();
        }
        else if(silo_so == 5)
        {
            di_chuyen_len_5();
        }
    }
}


void quy_trinh_lua_bong_up_silo()
{
    do_bong();
    if      (silo_so == 1)            di_chuyen_len_1();
    else if (silo_so == 2)            di_chuyen_len_2();
    else if (silo_so == 3)            di_chuyen_len_3();
    else if (silo_so == 4)            di_chuyen_len_4();
    else if (silo_so == 5)            di_chuyen_len_5();
        while(1)
    {
        nhan_bong_trong_silo();
        while(bien_nhan_bong == 0)
        {
            nhan_bong_trong_silo();
            if(bien_nhan_bong == 1)             {tha_bong();break;}
            else                                di_chuyen();
        }
        break;
    }
    bien_nhan_bong = 0;
    di_chuyen_ve();
    while(1)
    {
        do_bong();
            if(bien_nho_silo_co_2_bong != 0)
        {
            di_chuyen_len_bo_bong_thu_3();
            bien_nho_silo_co_2_bong = 0;
        }
        else
        {
            di_chuyen_len();
        }
            while(bien_nhan_bong == 0)
        {
            nhan_bong_trong_silo();
            if(bien_nhan_bong == 1)             tha_bong(),di_chuyen_ve();
            else                                di_chuyen();
        }
        bien_nhan_bong = 0;
    }
}

void XuatPhatRetry()
{
    reset_all();
    vTaskDelay(111);
    if(NUT_CHUYEN_SAN == 1)
    {
        robotRunAngle(200, 20, 0, 0.5);
        while(laze_0H_Value > 40){if(wantExit())break;}

        robotStop(0);

        for(i=0;i<50;i++)   while(laze_8H_Value < 250)   bam_thanh_laze_doc(900, 40, 0, 1, 50, 30, 0, laze_0H_Value);

        for(i=0;i<50;i++)   while(laze_8H_Value < 385)   bam_thanh_laze_doc(900, 30, 0, 1, 50, 30, 0, laze_0H_Value);

        robotStop(0);
        // delay_ms(500);

        RESET_ENCODER();

        robotRunAngle(0,60,0,0.2);
        while(ENCODER_TONG() < 1800){if(wantExit())break;}

        robotRunAngle(0,30,0,0);
        while(laze_0H_Value > 295){if(wantExit())break;}
            XL_NONG_HA_BAT;
        XL_NONG_XOAY_BAT;
        XL_MO_90;

        RESET_ENCODER();

        robotRunAngle(-900, 50, 0, 0.8);
        while(ENCODER_TONG() < 2000 ){if(wantExit())break;}
            robotStop(0);

        robotRotate(1800, 1.5, 0);
        while(robotFixAngle()){};

        robotRunAngle(-900,30,0,0);
        while(laze_8H_Value > 80){if(wantExit())break;}
    }
/**********************************SAN XANH***********************************/
    else
    {
        robotRunAngle(-200, 20, 0, 0.5);
        while(laze_0H_Value > 40){if(wantExit())break;}

        robotStop(0);

        for(i=0;i<50;i++)   while(laze_4H_Value < 250)   bam_thanh_laze_doc(-900, 40, 0, 1, 50, 30, 0, laze_0H_Value);

        for(i=0;i<50;i++)   while(laze_4H_Value < 385)   bam_thanh_laze_doc(-900, 30, 0, 1, 50, 30, 0, laze_0H_Value);

        robotStop(0);
        // delay_ms(500);

        RESET_ENCODER();

        robotRunAngle(0,60,0,0.2);
        while(ENCODER_TONG() < 1800){if(wantExit())break;}

        robotRunAngle(0,30,0,0);
        while(laze_0H_Value > 295){if(wantExit())break;}
            XL_NONG_HA_BAT;
        XL_NONG_XOAY_BAT;
        XL_MO_90;

        RESET_ENCODER();

        robotRunAngle(900, 50, 1800, 0.8);
        while(robotAngle() < 1790 ){if(wantExit())break;}

        robotRunAngle(900,30,0,0);
        while(laze_8H_Value > 80+15){if(wantExit())break;}
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

    while(1)
    {
        do_bong();

        if(bien_nho_silo_co_2_bong != 0)
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
    while(robotFixAngle()){vTaskDelay(1);}

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

    while(1)
    {
        do_bong();

        if(bien_nho_silo_co_2_bong != 0)
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
    // XuatPhat();

    for(silo_sap_bo=1;silo_sap_bo<4;silo_sap_bo++)
    {
        do_bong();

        if(silo_sap_bo==1)  di_chuyen_len_1();

        if(silo_sap_bo==2)  di_chuyen_len_2();

        if(silo_sap_bo==3)  di_chuyen_len_3();

        tha_bong();

        bien_nho_bong_trong_silo[silo_so]++;

        di_chuyen_ve();
    }

    while(1)
    {
        do_bong();

        if(bien_nho_silo_co_2_bong != 0)
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
    // XuatPhat();
    robotRotate(450, 2, 0);
    while(robotFixAngle()){vTaskDelay(1);}

    robotStop(0);
    XL_MO_90;
    XL_NONG_HA_TAT;
    XL_TR_NONG_HA_BAT;
    delay_ms(1200);
    XL_TR_NONG_HA_TAT;

    for(silo_sap_bo=1;silo_sap_bo<4;silo_sap_bo++)
    {
        do_bong();

        if(silo_sap_bo==1)  di_chuyen_len_3();

        if(silo_sap_bo==2)  di_chuyen_len_4();

        if(silo_sap_bo==3)  di_chuyen_len_5();

        tha_bong();

        bien_nho_bong_trong_silo[silo_so]++;

        di_chuyen_ve();
    }

    while(1)
    {
        do_bong();

        if(bien_nho_silo_co_2_bong != 0)
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
    di_chuyen_len_4();
}

