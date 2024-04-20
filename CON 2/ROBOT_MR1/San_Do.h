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
    Mor_nong = 100;
    delay_ms(100);
    Mor_nong = 0;
    
    bien_nho_bong_da_tha_trong_silo[silo_so]++;

    reset_all();
}

void di_chuyen_ve()
{   
    reset_all();

/********************SAN DO******************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        if(bien_ve_xuat_phat < 3)
        {
            if(laze_4H_Value < 240)
            {
                while(laze_4H_Value < 240){robotRunAngle(-700, 70, 0, 0.2),vTaskDelay(10);}
            }
            else
            {
                while(laze_4H_Value > 240){robotRunAngle(300, 70, 0, 0.2),vTaskDelay(10);}
            }
            for(i=0;i<50;i++)   while(laze_0H_Value < 190)   bam_thanh_laze_ngang(0, 70, 0, 30, 240, 2);

            robotRunAngle(0,40,450,0.7);
            while (robotAngle() < 450){};
            
            // RESET_ENCODER();
            // robotRunAngle(0)

            robotStop(0);
        }
        else
        {
            if(laze_4H_Value > 20)
            {
                while(laze_4H_Value > 30){robotRunAngle(700, 70, 0, 0);}
            }
            for(i=0;i<50;i++)   while(laze_0H_Value < 170)   bam_thanh_laze_ngang(0, 70, 0,  30, 30, 2);

            RESET_ENCODER();
            robotRunAngle(0, 100, 0, 0);
            while(ENCODER_TONG() < 1200){if(wantExit())break;}

            robotStop(0);

            RESET_ENCODER();
        }
    }
    else
    {
        if(laze_4H_Value < 240)
        {
            while(laze_4H_Value < 240){robotRunAngle(-1250, 70, 0, 0.5),vTaskDelay(10);}
        }
        else
        {
            while(laze_4H_Value > 250){robotRunAngle(1250, 70, 0, 0.5),vTaskDelay(10);}
        }
        for(i=0;i<50;i++)   while(laze_0H_Value < 190)   bam_thanh_laze_ngang(0, 70, 0,  30, 270, 2);

        robotRunAngle(1800, 30, -900, 0.9);
        while (robotAngle() > -850){};

        robotStop(0);
    }
    
}

void duong_di_silo()
{
    laze_chay_silo(silo_so);
    bien_nhan_bong = 0;
    robotStop(0);
    reset_all();
    vTaskDelay(111);

/****************************************SAN DO****************************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        robotRunAngle(-900, 30, -900, 2);
        while(robotAngle() > -900){if(wantExit())break;}

/**************DANG DUNG CHAN DOC *****************************/
        robotRunAngle(1800, 30, -900, 1.5);
        while(laze_4H_Value < 30){if(wantExit())break;}
                    
        robotRunAngle(1800, 30, -900, 1.5);
        while(laze_4H_Value < 140 && laze_4H_Value > 30){if(wantExit())break;}
        
/**************DANG DUNG GIUA DOC********************************/
        RESET_ENCODER();
        robotRunAngle(1800, 30, -450, 1.5);
        while(ENCODER_TONG() < 1500){};
/**************DANG DUNG DAU DOC********************************/
        robotRunAngle(1800, 50, 0, 1);
        while(robotAngle() < 0){};

        robotStop(0);
        reset_all();
        vTaskDelay(555);

        if(laze_4H_Value > do_laze_silo)
        {
            robotRun(1000, 40);
            while(laze_4H_Value > do_laze_silo+40){if(wantExit())break;}
            
            robotRun(1150, 10);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}

            robotStop(0);
        }
        else
        {
            robotRun(-1000, 40);
            while(laze_4H_Value < do_laze_silo-40){if(wantExit())break;}

            robotRun(-1150, 10);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            
            robotStop(0);
        }
    }
/****************************************SAN XANH***************************************/
    else    
    {
        robotRunAngle(0, 40, 0, 0.5);
        while(laze_0H_Value > 50){}

        for(i=0;i<50;i++)
        {
            while(laze_4H_Value < do_laze_silo && CB_TU_NHAN_SILO == 1)
            {
                bam_thanh_laze_doc(-900, 20, 0, 50, 25, 2);
                if(wantExit())  break;
            }
            while (laze_4H_Value > do_laze_silo && CB_TU_NHAN_SILO == 1)
            {
                bam_thanh_laze_doc(900, 20, 0, 50, 25, 2);
                if(wantExit())  break;
            }
            
        }

        // if(laze_4H_Value > do_laze_silo)
        // {
        //     robotRun(-1150, 40);
        //     while(laze_4H_Value > do_laze_silo+35){if(wantExit())break;}
            
        //     robotRun(-1150, 10);
        //     while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
        //     robotStop(0);
        // }
        // else
        // {
        //     robotRun(1150, 40);
        //     while(laze_4H_Value < do_laze_silo-35){if(wantExit())break;}

        //     robotRun(1150, 10);
        //     while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
        //     robotStop(0);
        // }
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
                robotRun(-1000, 40);
                while(laze_4H_Value < do_laze_silo-44){if(wantExit())break;}
                
                robotRun(-1150, 10);
                while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
                robotStop(0);      
        }
        else if(bien_di_chuyen == 0)                      //di chuyen sang phai
        {
            robotRun(1000, 40);
            while(laze_4H_Value > do_laze_silo+44){if(wantExit())break;}
            
            robotRun(1150, 10);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            robotStop(0);
        }
    }
/****************************************SAN XANH****************************************/
    else
    {
        laze_chay_silo(silo_so);
        if(bien_di_chuyen == 1)                           //di chuyen sang phai
        {
            // robotRun(1000, 40);
            // while(laze_4H_Value < do_laze_silo-44){if(wantExit())break;}
            
            // robotRun(1150, 10);
            // while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}

            while(laze_4H_Value < do_laze_silo && CB_TU_NHAN_SILO == 1)
            {
                bam_thanh_laze_doc(-900, 30, 0, 50, 25, 2);
            }
            robotStop(0);    
        }
        else if(bien_di_chuyen == 0)                      //di chuyen sang trai
        {
            // robotRun(-1000, 40);
            // while(laze_4H_Value > do_laze_silo+44){if(wantExit())break;}
            
            // robotRun(-1150, 10);
            // while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            
            while(laze_4H_Value > do_laze_silo && CB_TU_NHAN_SILO == 1)
            {
                bam_thanh_laze_doc(900, 30, 0, 50, 25, 2);
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
            for(j = 0; j < 2; j++)
            {
                if(j == 0)
                {
                    for (i = silo_so+1; i < 6; i++)
                    {
                        if(/*bien_nho_bong_da_tha_trong_silo[i] == 0 && */bien_nho_bong_trong_silo[i] == 0)
                        {
                            bien_di_chuyen = j;
                            silo_so = i;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1 || bien_nho_bong_trong_silo[0] == 1) break;
                        }
                    }
                }
                if(j == 1)
                {
                    for (i = silo_so-1; i > 0; i--)
                    {
                        if(/*bien_nho_bong_da_tha_trong_silo[i] == 0 &&*/ bien_nho_bong_trong_silo[i] == 0)
                        {
                            bien_di_chuyen = j;
                            silo_so = i;
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
            for(j = 0; j < 2; j++)
            {
                if(j == 0)
                {
                    for (i = silo_so+1; i < 6; i++)
                    {
                        if(bien_nho_bong_da_tha_trong_silo[i] != 0 && bien_nho_bong_trong_silo[i] != 3)
                        {
                            bien_di_chuyen = j;
                            silo_so = i;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1) break;
                        }
                        else if(bien_nho_bong_da_tha_trong_silo[i] == 0 && bien_nho_bong_trong_silo[i] != 3)
                        {
                            bien_di_chuyen = j;
                            silo_so = i;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1) break;
                        }
                    }
                }
                if(j == 1)
                {
                    for (i = silo_so-1; i > 0; i--)
                    {
                        if(bien_nho_bong_da_tha_trong_silo[i] != 0 && bien_nho_bong_trong_silo[i] != 3)
                        {
                            bien_di_chuyen = j;
                            silo_so = i;
                            di_chuyen();
                            nhan_bong_trong_silo();
                            if(bien_nhan_bong == 1) break;
                        }
                        else if(bien_nho_bong_da_tha_trong_silo[i] == 0 && bien_nho_bong_trong_silo[i] != 3)
                        {
                            bien_di_chuyen = j;
                            silo_so = i;
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
    silo_vua_chay = silo_so;
}


void di_chuyen_len_1()                              //di chuyen len silo 1
{
    RESET_ENCODER();

    silo_so = 1;
    
    duong_di_silo();
    
    silo_vua_chay = silo_so;
}

void di_chuyen_len_2()                              //di chuyen len silo 2
{
    RESET_ENCODER();

    silo_so = 2;
    
    duong_di_silo();
    
    silo_vua_chay = silo_so;
}

void di_chuyen_len_3()                              //di chuyen len silo 3
{
    RESET_ENCODER();

    silo_so = 3;
    
    duong_di_silo();
    
    silo_vua_chay = silo_so;
}

void di_chuyen_len_4()                              //di chuyen len silo 4
{
    RESET_ENCODER();

    silo_so = 4;
    
    duong_di_silo();
    
    silo_vua_chay = silo_so;
}
void di_chuyen_len_5()                              //di chuyen len silo 5
{
    RESET_ENCODER();

    silo_so = 5;

    duong_di_silo();
    
    silo_vua_chay = silo_so;
}

void do_bong_trong_Analytics()
{
    if(CB_NHAN_DO_DUOI == 0 || CB_NHAN_XANH_DUOI == 0)    
    {
        bien_do_bong = 1;
        XL_NONG_HA_TAT;
        Mor_hot_bong = Bang_tai = Mor_nong = 0;
        delay_ms(1000);
        Bang_tai = 254;
        Mor_nong = 254;
        while(1)
        {
            if (CB_NHAN_DO_TREN == 0 || CB_NHAN_XANH_TREN == 0)
            {
                break;
            }
            vTaskDelay(1);
        }
        // Mor_hot_bong = Bang_tai = Mor_nong = 0;
        // delay_ms(5000);
        // Bang_tai = 254, Bang_tai_nghich;
        Mor_nong = 0;
        // delay_ms(500);
        Bang_tai = 2;
        XL_NONG_XOAY_BAT;
    }
}
int kiem_tra_dung_tuong_trong_Analystics()
{
    if(test_nut == 11 && bien_ve_xuat_phat < 3)
    {
        if(bien_do_bong == 0)
        {
            if(ENCODER_TONG() > 3300 /*|| HT_DUNG == 0*/)   return bien_cham_tuong = 1;
            else                                            return bien_cham_tuong = 0;
        }
    }
    else
    {
        // if(HT_DUNG == 1)    return bien_cham_tuong = 0;
        // else                return bien_cham_tuong = 1;
    }
}
void do_bong()
{
    reset_all();

    bien_do_bong = 0;
    bien_chay_cap_thanh = 1;
    bien_nhan_bong = 0;
    
    Mor_hot_bong = Bang_tai = Mor_nong = 254;
    Mor_hot_bong_vao, Bang_tai_thuan, Mor_nong_ra;

/**************************CHAY 3 LAN DAU**************************/
    if(bien_ve_xuat_phat < 3)
    {
        while (1)
        {
            robotRunAngle(0,20,0,0);
            while(HT_DUNG_PHAI == 1 && HT_DUNG_TRAI == 1 && CB_TU_DUNG_LAY_BANH == 0)
            {
                if(bien_do_bong == 1) 
                {
                    robotStop(2);
                    break;
                }
                if(bien_cham_tuong == 1)
                {
                    robotStop(2);
                    break;
                }
            }

            robotStop(0);
            delay_ms(400);

            if(bien_do_bong == 1)   
            {
                robotStop(0);
                break;
            }
            else if(bien_cham_tuong == 1)
            {
                end = ENCODER_TONG();
                RESET_ENCODER();
                robotRunAngle(0, 20, 0, 0);
                while(ENCODER_TONG() < end*17/20){}
/*********************************SAN DO*********************************/
                if(NUT_CHUYEN_SAN == 1)
                {
                    RESET_ENCODER();
                    robotRunAngle(900, 30, 0, 0);
                    while(ENCODER_TONG() < end*17/20){if(wantExit()) break;}
                }
/*********************************SAN XANH*********************************/
                else
                {
                    RESET_ENCODER();
                    robotRunAngle(900, 30, 0, 0.5);
                    while(ENCODER_TONG() < 1500){if(wantExit()) break;}
                    // robotRunAngle()
                }
            }
        }
        bien_ve_xuat_phat++;
        end = ENCODER_TONG();
        RESET_ENCODER();
        
        while(ENCODER_TONG() < end*2/5){robotRunAngle(0, 30, 0, 0),XL_NONG_HA_TAT;}

        RESET_ENCODER();
        
        robotRunAngle(900,30,900,0.6);
        while (robotAngle() < 890){}
        
        // if(NUT_CHUYEN_SAN == 1)
        // {
        //     /***********************DANG DUNG CHAN DOC****************************/
        //     RESET_ENCODER();
        //     robotRunAngle(900,30,-900, 1.5);
        //     // while(ENCODER_0H() < 1000){};

        //     RESET_ENCODER();
        //     robotRunAngle(900,30, -450, 1);
        //     while(ENCODER_TONG() < 1500){};
        //     robotStop(0);
        //     bien_do_bong = 0 ;
        // }
        // else
        // {
        //     /***********************DANG DUNG CHAN DOC****************************/
        //     RESET_ENCODER();
        //     robotRunAngle(-1150,30,0,0);
        //     while(ENCODER_0H() < 1500){};

        //     RESET_ENCODER();
        //     robotRunAngle(-1150,30, 450, 1);
        //     while(ENCODER_TONG() < 2500){};
        //     robotStop(0);
        //     bien_do_bong = 0 ;
        // }
    }
    else
    {
        while (1)
        {
            while(HT_DUNG_PHAI == 1 && HT_DUNG_TRAI == 1 && CB_TU_DUNG_LAY_BANH == 0)
            {
                robotRunAngle(0,20,0,0);
                if(bien_do_bong == 1)break;
            }

            robotStop(0);
            delay_ms(500);

            if(bien_do_bong == 1)   
            {
                // XL_HOT_BONG_BAT_LEN;
                break;
            }
            else if(bien_cham_tuong == 1)
            {
                end = ENCODER_TONG();

                RESET_ENCODER();

                while(ENCODER_TONG() < end*2/5){robotRunAngle(0, 30, 0, 0),XL_NONG_HA_TAT;}

                RESET_ENCODER();
                
                robotRunAngle(900,30,900,0.6);

                while (robotAngle() < 890)

                if(NUT_CHUYEN_SAN == 1)
                {
                    if(bien_chay_cap_thanh % 3 == 0)
                    {
                        robotRunAngle(900, 50, 0, 0);
                        while(laze_4H_Value > 25){if(wantExit()) break;}
                        bien_chay_cap_thanh++;
                    }
                    else
                    {
                        RESET_ENCODER();
                        while(ENCODER_TONG() < 2500){robotRunAngle(-900, 30, 0,1.5);}
                        bien_chay_cap_thanh++;
                    }
                }
                else
                {
                    if(bien_chay_cap_thanh % 3 == 0)
                    {
                        robotRunAngle(-900, 50, 0, 0);
                        while(laze_8H_Value > 20){if(wantExit()) break;}
                        bien_chay_cap_thanh++;
                    }
                    else
                    {
                        RESET_ENCODER();
                        while(ENCODER_TONG() < 2500){robotRunAngle(900, 30, 0, 1.5);}
                        bien_chay_cap_thanh++;
                    }
                }
            } 
        }
        // XL_HOT_BONG_BAT_LEN;
    }
}

void XuatPhat()
{
    reset_all();
    vTaskDelay(111);
    if(NUT_CHUYEN_SAN == 1)
    {
        robotRunAngle(0, 50, 0, 0.5);
        while(ENCODER_TONG() < 300){if(wantExit())break;}

        robotRunAngle(0, 100, 0, 0.5);
        while(ENCODER_TONG() < 4000){if(wantExit())break;}

        robotRunAngle(0, 80, 0, 0.5);
        while(ENCODER_TONG() < 6500){if(wantExit())break;}
        
        robotRunAngle(200, 60, 0, 0.5);
        while(laze_0H_Value > 70){if(wantExit())break;}

        robotStop(0);

        for(i=0;i<50;i++)   while(laze_8H_Value < 250)   bam_thanh_laze_doc(900, 40, 0, 50, 30, 0);

        for(i=0;i<50;i++)   while(laze_8H_Value < 385)   bam_thanh_laze_doc(900, 30, 0, 50, 30, 0);

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

        robotRunAngle(-900, 50, 1800, 0.8);
        while(robotAngle() < 1790 ){if(wantExit())break;}

        robotRunAngle(-900,30,0,0);
        while(laze_8H_Value > 80){if(wantExit())break;}
    }
/**********************************SAN XANH***********************************/
    else
    {
        robotRunAngle(0, 50, 0, 0.5);
        while(ENCODER_TONG() < 300){if(wantExit())break;}

        robotRunAngle(0, 100, 0, 0.5);
        while(ENCODER_TONG() < 4000){if(wantExit())break;}

        robotRunAngle(0, 80, 0, 0.5);
        while(ENCODER_TONG() < 6500){if(wantExit())break;}
        
        robotRunAngle(-200, 60, 0, 0.5);
        while(laze_0H_Value > 70){if(wantExit())break;}

        robotStop(0);

        for(i=0;i<50;i++)   while(laze_4H_Value < 250)   bam_thanh_laze_doc(-900, 40, 0, 50, 30, 0);

        for(i=0;i<50;i++)   while(laze_4H_Value < 385)   bam_thanh_laze_doc(-900, 30, 0, 50, 30, 0);

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
        while(laze_8H_Value > 80){if(wantExit())break;}

        // robotStop(0);

        // robotRotate(2250, 1, 0);
        // while(robotFixAngle()){vTaskDelay(1);}

        // robotRunAngle(-300, 15, 2250, 0);
        // while(laze_4H_Value > 105){if(wantExit())break;}

        // robotStop(0);
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
        int chon_silo = 0;
        for(chon_silo = 5; chon_silo >= 1; chon_silo--)
        {
            if(bien_nho_bong_da_tha_trong_silo[chon_silo] != 0 && bien_nho_bong_trong_silo[chon_silo] != 3)
            {
                silo_so = chon_silo;
                break;
            }
            else if(bien_nho_bong_da_tha_trong_silo[chon_silo] == 0 && bien_nho_bong_trong_silo[chon_silo] != 3)
            {
                silo_so = chon_silo;
                break;
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
        for(i=1;i<6;i++)
        {
            if(bien_nho_bong_trong_silo[i] == 0)
            {
                silo_so = i;
                break;
            }
        }
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


void XuatPhat_1()
{
    silo_so = 1;
    
    if(NUT_CHUYEN_SAN == 1)
    {
        
    }
    else
    {
        
    }
}

void XuatPhat_2()
{
    silo_so = 2;
}

void XuatPhat_3()
{
    silo_so = 3;
}

void XuatPhat_4()
{
    silo_so = 4;
}

void XuatPhat_5()
{
    silo_so = 5;
}

void XuatPhatRetry()
{
    reset_all();
    if(NUT_CHUYEN_SAN == 1)
    {
        robotRunAngle(-1150, 70, 0, 0);
        while(laze_0H_Value > 50){if(wantExit())break;}

        for(i=0;i<50;i++)   while(laze_4H_Value < 300)   bam_thanh_laze_doc(-900, 100, 0, -50, 30, 0);

        for(i=0;i<50;i++)   while(laze_4H_Value < 360)   bam_thanh_laze_doc(-900, 60, 0, -50, 30, 0);
        
        robotStop(2); 

        delay_ms(500);

        RESET_ENCODER();

        robotRunAngle(1750, 50, -40, 0.5);
        while(ENCODER_TONG() < 300){if(wantExit())break;}

        robotRunAngle(1750, 150, -30, 0.5);
        while(ENCODER_TONG() < 3000){if(wantExit())break;}

        // XL_HOT_BONG_HA_XUONG;

        RESET_ENCODER();

        robotRunAngle(1800, 50, 900, 1);
        while(robotAngle() < 900){vTaskDelay(1);}

        robotRunAngle(1800, 50, 900, 1);
        while(laze_4H_Value > 35){vTaskDelay(1);}

        robotStop(0);

        RESET_ENCODER();
        robotRunAngle(1000, 30, 880, 0);
        while(ENCODER_TONG() < 3500){}

        robotStop(0);
    }
/**********************************SAN XANH***********************************/
    else
    {
        robotRunAngle(1350, 70, 0, 0);
        while(laze_0H_Value > 30){if(wantExit())break;}

        for(i=0;i<50;i++)   while(laze_8H_Value < 330)   bam_thanh_laze_doc(900, 100, 0, 50, 25, 0);

        for(i=0;i<50;i++)   while(laze_8H_Value < 355)   bam_thanh_laze_doc(900, 60, 0, 50, 25, 0);

        robotStop(2);

        delay_ms(500);

        RESET_ENCODER();

        robotRunAngle(1770, 100, -50, 0.5);
        while(ENCODER_TONG() < 4000){if(wantExit())break;}

        // XL_HOT_BONG_HA_XUONG;

        robotRunAngle(1800, 70, -900, 1);
        while(robotAngle() > -900){vTaskDelay(1);}

        robotRunAngle(1800, 50, -900, 1);
        while(laze_8H_Value > 30){vTaskDelay(1);}

        robotStop(0);

        RESET_ENCODER();
        robotRunAngle(-1000, 30, -900, 0);
        while(ENCODER_TONG() < 3500){}

        robotStop(0);
    }
}

void retry()
{
    bien_ve_xuat_phat = 4;

    XuatPhatRetry();

    do_bong();

    di_chuyen_len_1();

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
    XuatPhat();

    do_bong();

    // di_chuyen_len_1();

    // kiem_tra_di_chuyen();

    // tha_bong();

    // di_chuyen_ve();

    // while(1)
    // {
    //     do_bong();

    //     if(bien_nho_silo_co_2_bong != 0)
    //     {
    //         di_chuyen_len_bo_bong_thu_3();

    //         kiem_tra_di_chuyen();

    //         tha_bong();
    //         di_chuyen_ve();
    //         bien_nho_silo_co_2_bong = 0;
    //     }
    //     else
    //     {
    //         di_chuyen_len();

    //         kiem_tra_di_chuyen();
        
    //         tha_bong();
            
    //         di_chuyen_ve();
    //     }
    //     bien_nhan_bong = 0;
    // }
    
}
void test()
{
    XL_NONG_HA_BAT;
    delay_ms(2000);
    Mor_hot_bong = Bang_tai = Mor_nong = 254;
    Mor_hot_bong_vao, Bang_tai_thuan, Mor_nong_ra;
}
