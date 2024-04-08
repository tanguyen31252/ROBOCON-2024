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
    ROLE_BANG_TAI_BAT;
    while (CB_DAY_BONG_RA_NGOAI == 1){}
    delay_ms(1500);

    XL_HOT_BONG_HA_XUONG;
    ROLE_BANG_TAI_TAT;
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
            if(lazeNgangDoValue < 240)
            {
                while(lazeNgangDoValue < 240){robotRunAngle(-700, 70, 0, 0.2),vTaskDelay(10);}
            }
            else
            {
                while(lazeNgangDoValue > 240){robotRunAngle(300, 70, 0, 0.2),vTaskDelay(10);}
            }
            for(i=0;i<50;i++)   while(lazeSauValue < 190)   bam_thanh_laze_ngang(0, 70, 0, 30, 240, 2);

            RESET_ENCODER();

            robotRunAngle(0,30,450,0.4);
            while (robotAngle() < 450){};

            robotStop(0);
            
        }
        else
        {
            if(lazeNgangDoValue > 20)
            {
                while(lazeNgangDoValue > 30){robotRunAngle(700, 70, 0, 0);}
            }
            for(i=0;i<50;i++)   while(lazeSauValue < 170)   bam_thanh_laze_ngang(0, 70, 0,  30, 30, 2);

            RESET_ENCODER();
            robotRunAngle(0, 100, 0, 0);
            while(ENCODER_TONG() < 1200){if(wantExit())break;}

            robotStop(0);

            RESET_ENCODER();
        }
    }
    else
    {
        if(bien_ve_xuat_phat < 3)
        {
            if(lazeNgangXanhValue < 240)
            {
                while(lazeNgangXanhValue < 240){robotRunAngle(700, 70, 0, 0.2),vTaskDelay(10);}
            }
            else
            {
                while(lazeNgangXanhValue > 250){robotRunAngle(-300, 70, 0, 0.2),vTaskDelay(10);}
            }
            for(i=0;i<50;i++)   while(lazeSauValue < 190)   bam_thanh_laze_ngang(0, 70, 0,  30, 270, 2);

            RESET_ENCODER();

            robotRunAngle(0, 30, -450, 0.9);
            while (robotAngle() > -450){};

//            robotRunAngle(450, 30, -450, 0);
//            while(lazeNgangDoValue >105){}

            robotStop(0);
            
        }
        else
        {
            if(lazeNgangXanhValue > 20)
            {
                while(lazeNgangXanhValue > 30){robotRunAngle(-700, 70, 0, 0);}
            }
            for(i=0;i<50;i++)   while(lazeSauValue < 170)   bam_thanh_laze_ngang(0, 70, 0,  30, 30, 2);

            RESET_ENCODER();
            robotRunAngle(0, 100, 0, 0);
            while(ENCODER_TONG() < 700){if(wantExit())break;}

            robotStop(0);

            RESET_ENCODER();
        }
    }
    
}

void duong_di_silo()
{
    laze_chay_silo(silo_so);
    bien_nhan_bong = 0;
    
/****************************************SAN DO****************************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        end = ENCODER_FR();
        reset_all();
        if(bien_ve_xuat_phat > 3)
        {
            robotRunAngle(-900, 30, -900, 1);
            while(robotAngle() > -900){if(wantExit())break;}

/**************DANG DUNG CHAN DOC *****************************/
            robotRunAngle(1800, 30, -900, 1.5);
            while(lazeNgangDoValue < 30){if(wantExit())break;}
                        
            robotRunAngle(1800, 30, -900, 1.5);
            while(lazeNgangDoValue < 140 && lazeNgangDoValue > 30){if(wantExit())break;}
            
/**************DANG DUNG GIUA DOC********************************/
            RESET_ENCODER();
            robotRunAngle(1800, 30, -450, 1.5);
            while(ENCODER_TONG() < 1500){};
/**************DANG DUNG DAU DOC********************************/
            robotRunAngle(1800, 50, 0, 1);
            while(robotAngle() < 0){};
        }
        
        while(lazeSauValue > 40 && CB_CAP_THANH == 1){robotRunAngle(1800, 70, 0, 1);}
        
        while(CB_CAP_THANH == 1){robotRun(1800, 20);}

        reset_all();

        if(lazeNgangDoValue > do_laze_silo)
        {
            robotRun(1000, 40);
            while(lazeNgangDoValue > do_laze_silo+40){if(wantExit())break;}
            
            robotRun(1150, 10);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}

            robotStop(0);
        }
        else
        {
            robotRun(-1000, 40);
            while(lazeNgangDoValue < do_laze_silo-40){if(wantExit())break;}

            robotRun(-1150, 10);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            
            robotStop(20);
        }
    }
/****************************************SAN XANH***************************************/
    else    
    {
        end = ENCODER_FR();
        reset_all();

        if(bien_ve_xuat_phat > 3)
        {
            robotRunAngle(900, 30, -900, 1);
            while(robotAngle() > -900){if(wantExit())break;}

/**************DANG DUNG CHAN DOC *****************************/
            robotRunAngle(1800, 30, -900, 1.5);
            while(lazeNgangDoValue < 30){if(wantExit())break;}
                        
            robotRunAngle(1800, 30, -900, 1.5);
            while(lazeNgangDoValue < 170 && lazeNgangDoValue > 30){if(wantExit())break;}

/**************DANG DUNG GIUA DOC********************************/
            RESET_ENCODER();
            robotRunAngle(1800, 30, -450, 1.5);
            while(ENCODER_FR() < 2000){};
/**************DANG DUNG DAU DOC********************************/
            RESET_ENCODER();
            robotRunAngle(1800, 50, 0, 2);
            while(ENCODER_TONG() < 1000){};
        }
        RESET_ENCODER();
        while(lazeSauValue > 40 && CB_CAP_THANH == 1){robotRunAngle(1800, 70, 0, 1);}

        while(CB_CAP_THANH == 1){/*robotRunAngle(1800, 20, -robotAngle(), 1.5)*/robotRun(1800, 20);}

        reset_all();

        if(lazeNgangXanhValue > do_laze_silo)
        {
            robotRun(-1150, 40);
            while(lazeNgangXanhValue > do_laze_silo+35){if(wantExit())break;}
            
            robotRun(-1150, 10);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            robotStop(0);
        }
        else
        {
            robotRun(1150, 40);
            while(lazeNgangXanhValue < do_laze_silo-35){if(wantExit())break;}

            robotRun(1150, 10);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            robotStop(0);
        }
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
#pragma region cu
        // if(bien_nho_bong_trong_silo[0] == 1)
        // {
        //     bien_di_chuyen = random(0,1);
        //     if      (silo_so == 1)                                                          bien_di_chuyen = 1;
        //     else if (silo_so == 5)                                                          bien_di_chuyen = 0;
        //     else if (bien_nho_bong_trong_silo[silo_so+1] == 3 && bien_di_chuyen == 0)       bien_di_chuyen = 1;
        //     else if (bien_nho_bong_trong_silo[silo_so-1] == 3 && bien_di_chuyen == 1)       bien_di_chuyen = 0;   
        // }

        // if(silo_so > 0 && bien_di_chuyen == 0)                           //di chuyen sang trai
        // {
        //     if(bien_nho_bong_trong_silo[silo_so] == 1 || bien_nho_bong_trong_silo[silo_so] == 3)
        //     {
        //         robotRunAngle(1000, 40, 0.2, 0);
        //         while(lazeNgangXanhValue < do_laze_silo-44){if(wantExit())break;}

        //         robotRunAngle(1000, 10, 0.2, 0);
        //         while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
        //         robotStop(0);

        //         silo_so--;
        //     }     
        //     if(silo_so == 1)
        //     {
        //         bien_di_chuyen = 1;
        //     }
        // }
        // else if(silo_so < 6 && bien_di_chuyen == 1)                      //di chuyen sang phai
        // {
        //     if(bien_nho_bong_trong_silo[silo_so] == 1 || bien_nho_bong_trong_silo[silo_so] == 3)
        //     {
        //         robotRunAngle(-1000, 40, -0.2, 0);
        //         while(lazeNgangXanhValue > do_laze_silo+44){if(wantExit())break;}
                
        //         robotRunAngle(-1000, 10, -0.2, 0);
        //         while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
        //         robotStop(0);

        //         silo_so--;
        //     }
        //     if(silo_so == 5)
        //     {
        //         bien_di_chuyen = 0;
        //     }
        // }
        #pragma endregion
        
        if(bien_di_chuyen == 1)                           //di chuyen sang trai
        {
                robotRun(-1000, 40);
                while(lazeNgangDoValue < do_laze_silo-44){if(wantExit())break;}
                
                robotRun(-1150, 10);
                while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
                robotStop(0);      
        }
        else if(bien_di_chuyen == 0)                      //di chuyen sang phai
        {
            robotRun(1000, 40);
            while(lazeNgangDoValue > do_laze_silo+44){if(wantExit())break;}
            
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
            robotRun(1000, 40);
            while(lazeNgangXanhValue < do_laze_silo-44){if(wantExit())break;}
            
            robotRun(1150, 10);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            robotStop(0);    
        }
        else if(bien_di_chuyen == 0)                      //di chuyen sang trai
        {
            robotRun(-1000, 40);
            while(lazeNgangXanhValue > do_laze_silo+44){if(wantExit())break;}
            
            robotRun(-1150, 10);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
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
    if(CB_NHAN_MAU_XANH_TRAI == 0 || CB_NHAN_MAU_XANH_PHAI == 0 || CB_NHAN_MAU_DO_PHAI == 0 || CB_NHAN_MAU_DO_TRAI == 0)    
    {
        bien_do_bong = 1;
        ROLE_HOT_BONG_TAT;
        Mor_Silo = 254, Mor_Silo_day_ra;    
        while(1)
        {
            if (CB_DUNG_BANG_TAI == 1 && CB_DAY_BONG_RA_NGOAI == 0 && CB_NHAN_MAU_XANH_TRAI == 1 && CB_NHAN_MAU_XANH_PHAI == 1 && CB_NHAN_MAU_DO_PHAI == 1 && CB_NHAN_MAU_DO_TRAI == 1)
            {
                ROLE_BANG_TAI_TAT; 
                break;
            }
        }
        Mor_Silo = 0;
    }
}
int kiem_tra_dung_tuong_trong_Analystics()
{
    if(test_nut == 11 && bien_ve_xuat_phat < 3)
    {
        if(bien_do_bong == 0)
        {
            if(ENCODER_TONG() > 3300)   return bien_cham_tuong = 1;
            else                        return bien_cham_tuong = 0;
        }
    }
    else
    {
        if(HT_DUNG == 1)    return bien_cham_tuong = 0;
        else                return bien_cham_tuong = 1;
    }
}
void do_bong()
{
    reset_all();

    bien_do_bong = 0;
    bien_chay_cap_thanh = 1;
    bien_nhan_bong = 0;

    Mor_Silo = 254, Mor_Silo_day_vao;
    ROLE_BANG_TAI_BAT;
    ROLE_HOT_BONG_BAT;

/**************************CHAY 3 LAN DAU**************************/
    if(bien_ve_xuat_phat < 3)
    {
        while (1)
        {
            robotRunAngle(0,20,0,0);
            while(HT_DUNG == 1 && CB_TU_DUNG_LAY_BANH == 0)
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
                robotRunAngle(1800, 20, 0, 0);
                while(ENCODER_TONG() < end*17/20){}
/*********************************SAN DO*********************************/
                if(NUT_CHUYEN_SAN == 1)
                {
                    if(test_nut == 11)
                    {
                        RESET_ENCODER();
                        robotRunAngle(900, 50, 0, 0);
                        while(ENCODER_TONG() < 1000){if(wantExit()) break;}
                    }
                    else
                    {
                        RESET_ENCODER();
                        robotRunAngle(-900, 50, 0, 0);
                        while(ENCODER_TONG() < 2000){if(wantExit()) break;}
                    }
                    
                }
/*********************************SAN XANH*********************************/
                else
                {
                    if(test_nut == 11)
                    {
                        RESET_ENCODER();
                        robotRunAngle(-900, 50, 0, 0);
                        while(ENCODER_TONG() < 1000){if(wantExit()) break;}
                    }
                    else
                    {
                        RESET_ENCODER();
                        robotRunAngle(900, 50, 0, 0);
                        while(ENCODER_TONG() < 2000){if(wantExit()) break;}
                    }
                }
            }
        }
        bien_ve_xuat_phat++;
        end = ENCODER_TONG();
        RESET_ENCODER();
        
        while(ENCODER_TONG() < end*2/5){robotRunAngle(1800, 40, 0, 0),XL_HOT_BONG_BAT_LEN;}

        
        if(NUT_CHUYEN_SAN == 1)
        {
            /***********************DANG DUNG CHAN DOC****************************/
            RESET_ENCODER();
            robotRunAngle(900,30,-900, 1.5);
            while(ENCODER_FR() < 1000){};

            RESET_ENCODER();
            robotRunAngle(900,30, -450, 1);
            while(ENCODER_TONG() < 1500){};
            robotStop(0);
            bien_do_bong = 0 ;
        }
        else
        {
            /***********************DANG DUNG CHAN DOC****************************/
            RESET_ENCODER();
            robotRunAngle(-1150,30,0,0);
            while(ENCODER_FR() < 1500){};

            RESET_ENCODER();
            robotRunAngle(-1150,30, 450, 1);
            while(ENCODER_TONG() < 2500){};
            robotStop(0);
            bien_do_bong = 0 ;
        }
        XL_HOT_BONG_BAT_LEN;
    }
    else
    {
        while (1)
        {
            while(HT_DUNG == 1 && CB_TU_DUNG_LAY_BANH == 0)
            {
                robotRunAngle(0,20,0,0);
                if(bien_do_bong == 1)break;
            }

            robotStop(0);
            delay_ms(500);

            if(bien_do_bong == 1)   
            {
                XL_HOT_BONG_BAT_LEN;
                break;
            }
            else if(bien_cham_tuong == 1)
            {
                end = ENCODER_TONG();

                RESET_ENCODER();

                while(ENCODER_TONG() < end*17/20){robotRunAngle(1800, 30, 0, 0.5);}

                if(NUT_CHUYEN_SAN == 1)
                {
                    if(bien_chay_cap_thanh % 2 == 0)
                    {
                        robotRunAngle(900, 50, 0, 0);
                        while(lazeNgangDoValue > 20){if(wantExit()) break;}
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
                    if(bien_chay_cap_thanh % 2 == 0)
                    {
                        robotRunAngle(-900, 50, 0, 0);
                        while(lazeNgangXanhValue > 20){if(wantExit()) break;}
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
        XL_HOT_BONG_BAT_LEN;
    }
}

void XuatPhat()
{
    reset_all();
    vTaskDelay(111);
    if(NUT_CHUYEN_SAN == 1)
    {
        robotRunAngle(1770, 50, -50, 0.5);
        while(ENCODER_TONG() < 300){if(wantExit())break;}
        
        robotRunAngle(1800, 150, 0, 0.5);
        while(ENCODER_TONG() < 7000){if(wantExit())break;}

        robotRunAngle(-1550, 70, 0, 0.5);
        while(lazeSauValue > 90){if(wantExit())break;}

        robotRunAngle(-1100, 70, 0, 0.5);
        while(lazeSauValue > 60){if(wantExit())break;}

        for(i=0;i<50;i++)   while(lazeNgangDoValue < 250)   bam_thanh_laze_doc(-900, 100, 0, -50, 30, 0);

        for(i=0;i<50;i++)   while(lazeNgangDoValue < 360)   bam_thanh_laze_doc(-900, 60, 0, -50, 30, 0);

        robotStop(2);
        delay_ms(500);

        RESET_ENCODER();

        robotRunAngle(1750, 50, -40, 0.5);
        while(ENCODER_TONG() < 300){if(wantExit())break;}

        robotRunAngle(1750, 150, -30, 0.5);
        while(ENCODER_TONG() < 3000){if(wantExit())break;}

        XL_HOT_BONG_HA_XUONG;

        RESET_ENCODER();

        robotRunAngle(900, 50, -1800, 1);
        while(robotAngle() > -1800){if(wantExit())break;}

        // robotRunAngle(900, 50, -1800, 1);
        // while(lazeNgangDoValue > 50){if(wantExit())break;}

        robotStop(0);

        robotRotate(-2250, 1, 0);
        while(robotFixAngle()){vTaskDelay(1);}

        robotRunAngle(300, 20, -2250, 0.5);
        while(lazeNgangXanhValue > 105){if(wantExit())break;}

        robotStop(0);
    }
/**********************************SAN XANH***********************************/
    else
    {
        robotRunAngle(1750, 150, -50, 0.5);
        while(ENCODER_TONG() < 7500){if(wantExit())break;}

        robotRunAngle(1550, 70, 0, 0.5);
        while(lazeSauValue > 70){if(wantExit())break;}
        
        robotRunAngle(1100, 70, 0, 0.5);
        while(lazeSauValue > 40){if(wantExit())break;}

        for(i=0;i<50;i++)   while(lazeNgangXanhValue < 250)   bam_thanh_laze_doc(900, 100, 0, 50, 30, 0);

        for(i=0;i<50;i++)   while(lazeNgangXanhValue < 350)   bam_thanh_laze_doc(900, 60, 0, 50, 30, 0);

        robotStop(20);
        delay_ms(500);

        RESET_ENCODER();

        robotRunAngle(1770, 150, -70, 0.5);
        while(ENCODER_TONG() < 3200){if(wantExit())break;}

        XL_HOT_BONG_HA_XUONG;

        RESET_ENCODER();

        robotRunAngle(-900, 50, 1800, 1);
        while(robotAngle() < 1800){if(wantExit())break;}

        robotStop(0);

        robotRotate(2250, 1, 0);
        while(robotFixAngle()){vTaskDelay(1);}

        robotRunAngle(-300, 15, 2250, 0);
        while(lazeNgangDoValue > 105){if(wantExit())break;}

        robotStop(0);
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
        while(lazeSauValue > 50){if(wantExit())break;}

        for(i=0;i<50;i++)   while(lazeNgangDoValue < 300)   bam_thanh_laze_doc(-900, 100, 0, -50, 30, 0);

        for(i=0;i<50;i++)   while(lazeNgangDoValue < 360)   bam_thanh_laze_doc(-900, 60, 0, -50, 30, 0);
        
        robotStop(2); 

        delay_ms(500);

        RESET_ENCODER();

        robotRunAngle(1750, 50, -40, 0.5);
        while(ENCODER_TONG() < 300){if(wantExit())break;}

        robotRunAngle(1750, 150, -30, 0.5);
        while(ENCODER_TONG() < 3000){if(wantExit())break;}

        XL_HOT_BONG_HA_XUONG;

        RESET_ENCODER();

        robotRunAngle(1800, 50, 900, 1);
        while(robotAngle() < 900){vTaskDelay(1);}

        robotRunAngle(1800, 50, 900, 1);
        while(lazeNgangDoValue > 35){vTaskDelay(1);}

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
        while(lazeSauValue > 30){if(wantExit())break;}

        for(i=0;i<50;i++)   while(lazeNgangXanhValue < 330)   bam_thanh_laze_doc(900, 100, 0, 50, 25, 0);

        for(i=0;i<50;i++)   while(lazeNgangXanhValue < 355)   bam_thanh_laze_doc(900, 60, 0, 50, 25, 0);

        robotStop(2);

        delay_ms(500);

        RESET_ENCODER();

        robotRunAngle(1770, 100, -50, 0.5);
        while(ENCODER_TONG() < 4000){if(wantExit())break;}

        XL_HOT_BONG_HA_XUONG;

        robotRunAngle(1800, 70, -900, 1);
        while(robotAngle() > -900){vTaskDelay(1);}

        robotRunAngle(1800, 50, -900, 1);
        while(lazeNgangXanhValue > 30){vTaskDelay(1);}

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