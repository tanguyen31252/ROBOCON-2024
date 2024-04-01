void reset_all()
{
    robotResetIMU();
    RESET_ENCODER();
    vTaskDelay(10);
}
void laze_chay_silo(int silo_sap_chay)
{
// *************************SAN DO*****************************
    if(NUT_CHUYEN_SAN == 1)
    {

    }
// *************************SAN XANH***************************
    else
    {

        if     (silo_sap_chay == 1)            do_laze_silo = laze_silo[0][silo_so];
        else if(silo_sap_chay == 2)            do_laze_silo = laze_silo[0][silo_so];
        else if(silo_sap_chay == 3)            do_laze_silo = laze_silo[0][silo_so];
        else if(silo_sap_chay == 4)            do_laze_silo = laze_silo[0][silo_so];
        else if(silo_sap_chay == 5)            do_laze_silo = laze_silo[0][silo_so];
    }
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
    RESET_ENCODER();
    bien_ve_xuat_phat = 0;

/********************SAN DO******************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        if (CB_DAY_BONG_RA_NGOAI == 1)
        {
            bien_ve_xuat_phat == 1;
        robotRunAngle(900,70,0,0);
        while (lazeNgangXanhValue < 236);
        robotRunAngle(0,80,0,0);
        while (lazeSauValue < 200);

        delay_ms(50);
        RESET_ENCODER();
        robotRunAngle(0,30,0,0);
        while(ENCODER_TONG() < 2000);

        robotRotate(30000,-0.5,0,40);
        while (_robotAngle < -900);
        }
        else if (CB_DAY_BONG_RA_NGOAI == 1)
        {
            bien_ve_xuat_phat == 2;
        robotRunAngle(900,70,0,0);
        while (lazeNgangXanhValue < 236);
        robotRunAngle(0,80,0,0);
        while (lazeSauValue < 200);

        delay_ms(50);
        RESET_ENCODER();
        robotRunAngle(0,30,0,0);
        while(ENCODER_TONG() < 2000);

        robotRotate(30000,-0.5,0,40);
        while (_robotAngle < -900);
        }
        else if (CB_DAY_BONG_RA_NGOAI == 1)
        {
            bien_ve_xuat_phat == 3;
        robotRunAngle(900,70,0,0);
        while (lazeNgangXanhValue < 236);
        robotRunAngle(0,80,0,0);
        while (lazeSauValue < 200);

        delay_ms(50);
        RESET_ENCODER();
        robotRunAngle(0,30,0,0);
        while(ENCODER_TONG() < 2000);

        robotRotate(30000,-0.5,0,40);
        while (_robotAngle < -900);
        }
        if (bien_ve_xuat_phat == 3)
        {
            robotStop(2);
            RESET_ENCODER();
        }
    }
    else
    {
        if(bien_ve_xuat_phat != 3)
        {
            // if(lazeNgangXanhValue < 230)
            // {
            //     for(i=0;i<50;i++)   
            //     {
            //         while(lazeSauValue < 170)
            //         {
            //             bam_thanh_laze_ngang(0, 50, 0, -450, 250, 2);
            //             if(wantExit()){break;}
            //         }
            //         vTaskDelay(10);
            //     }
            // }
            // else
            // {
            //     for(i=0;i<50;i++)   
            //     {
            //         while(lazeSauValue < 170)
            //         {
            //             bam_thanh_laze_ngang(0, 50, 0, 300, 250, 2);
            //             if(wantExit())break;
            //         }
            //         vTaskDelay(10);
            //     }
            // }

            if(lazeNgangXanhValue < 200)
            {
                while(lazeNgangXanhValue < 250){robotRunAngle(700, 70, 0, 0.2),vTaskDelay(10);}
            }
            else
            {
                while(lazeNgangXanhValue > 250){robotRunAngle(-300, 70, 0, 0.2),vTaskDelay(10);}
            }
            for(i=0;i<50;i++)   while(lazeSauValue < 190)   bam_thanh_laze_ngang(0, 70, 0,  30, 250, 2);

            RESET_ENCODER();

            robotRunAngle(0, 50, 0, 0);
            while(ENCODER_TONG() < 2550){if(wantExit())break;}

            robotStop(0);
            for(i=0;i<50;i++)
            {
                if(robotAngle() > -900)
                {
                    while(robotAngle() > -900)
                    {
                        robotRotateFree(-0.5, 0, 50);
                    }
                }
                else
                {
                    while(robotAngle() < -900)
                    {
                        robotRotateFree(0.5, 0, 50);
                    }
                }
                vTaskDelay(10);
            }
            bien_ve_xuat_phat++;
        }
        else
        {
            if(lazeNgangXanhValue > 20)
            {
                while(lazeNgangXanhValue > 20){robotRunAngle(-700, 70, 0, 0.2),vTaskDelay(10);}
            }
            for(i=0;i<50;i++)   while(lazeSauValue < 170)   bam_thanh_laze_ngang(0, 70, 0,  30, 250, 2);

            RESET_ENCODER();

            robotRunAngle(0, 50, 0, 0);
            while(ENCODER_TONG() < 2550){if(wantExit())break;}
        }
    }
    
}

void duong_di_silo()
{
    reset_all();
    laze_chay_silo(silo_so);
    bien_nhan_bong = 0;
/****************************************SAN DO****************************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        RESET_ENCODER();
        robotRunAngle(1800, 200, 0, 0);
        while(ENCODER_TONG() < 2000){if(wantExit_UP())break;}

        for(i=0;i<50;i++)
        {
            if(robotAngle() > 0)    while(robotAngle() > 0)   robotRotateFree(-0.5,0,100);
            else                    while(robotAngle() < 0)   robotRotateFree( 0.5,0,100);
            vTaskDelay(10);
        }
        robotStop(0);
        robotRunAngle(1800, 40, 0, 0);
        while(CB_CAP_THANH == 1){if(wantExit())break;}

        if(lazeNgangXanhValue > do_laze_silo)
        {
            robotRunAngle(-1000, 40, -0.2, 0);
            while(lazeNgangXanhValue > do_laze_silo+45){if(wantExit())break;}

            robotRunAngle(-1400, 10, 0.2, 0.5);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}

            robotStop(0);
        }
        else
        {
            robotRunAngle(900, 40, 0, 0);
            while(lazeNgangXanhValue > 6){if(wantExit())break;}
            robotStop(2);

            robotRunAngle(1000, 10, 0, 0);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            robotStop(2);
        }
    }
/****************************************SAN XANH***************************************/
    else    
    {
        RESET_ENCODER();

        robotRunAngle(1800, 50, 0, 0);
        while(ENCODER_TONG() < 3000){if(wantExit_UP())break;}

        robotStop(0);
        delay_us(100);

        for(i=0;i<50;i++)
        {
            if(robotAngle() > 0)    while(robotAngle() > 0)   robotRotateFree(-0.5,0,100),vTaskDelay(10);
            else                    while(robotAngle() < 0)   robotRotateFree( 0.5,0,100),vTaskDelay(10);
            // vTaskDelay(10);
        }
        robotStop(0);

        robotRunAngle(1800, 20, 0, 0);
        while (CB_CAP_THANH == 1){if(wantExit())break;}

        reset_all();

        if(lazeNgangXanhValue > do_laze_silo)
        {
            robotRunAngle(-1000, 40, -0.2, 0);
            while(lazeNgangXanhValue > do_laze_silo+44){if(wantExit())break;}
            
            robotRunAngle(-1000, 10, -0.2, 0);
            while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
            robotStop(0);
        }
        else
        {
            robotRunAngle(1000, 40, 0.2, 0);
            while(lazeNgangXanhValue < do_laze_silo-44){if(wantExit())break;}

            robotRunAngle(1000, 10, 0.2, 0);
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
        if(bien_nho_bong_trong_silo[0] == 1)
        {
            bien_di_chuyen = random(0,1);
            if      (silo_so == 1)                                                          bien_di_chuyen = 1;
            else if (silo_so == 5)                                                          bien_di_chuyen = 0;
            else if (bien_nho_bong_trong_silo[silo_so+1] == 3 && bien_di_chuyen == 0)       bien_di_chuyen = 1;
            else if (bien_nho_bong_trong_silo[silo_so-1] == 3 && bien_di_chuyen == 1)       bien_di_chuyen = 0;   
        }

        if(silo_so > 0 && bien_di_chuyen == 0)                           //di chuyen sang trai
        {
            if(bien_nho_bong_trong_silo[silo_so] == 1 || bien_nho_bong_trong_silo[silo_so] == 3)
            {
                robotRunAngle(1000, 40, 0.2, 0);
                while(lazeNgangXanhValue < do_laze_silo-44){if(wantExit())break;}

                robotRunAngle(1000, 10, 0.2, 0);
                while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
                robotStop(0);

                silo_so--;
            }     
            if(silo_so == 1)
            {
                bien_di_chuyen = 1;
            }
        }
        else if(silo_so < 6 && bien_di_chuyen == 1)                      //di chuyen sang phai
        {
            if(bien_nho_bong_trong_silo[silo_so] == 1 || bien_nho_bong_trong_silo[silo_so] == 3)
            {
                robotRunAngle(-1000, 40, -0.2, 0);
                while(lazeNgangXanhValue > do_laze_silo+44){if(wantExit())break;}
                
                robotRunAngle(-1000, 10, -0.2, 0);
                while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
                robotStop(0);

                silo_so--;
            }
            if(silo_so == 5)
            {
                bien_di_chuyen = 0;
            }
        }
    }
/****************************************SAN XANH****************************************/
    else
    {
        laze_chay_silo(silo_so);
        if(bien_nho_bong_trong_silo[0] == 1)
        {
            bien_di_chuyen = random(0,1);
            if      (silo_so == 1)                                                          bien_di_chuyen = 0;
            else if (silo_so == 5)                                                          bien_di_chuyen = 1;
            else if (bien_nho_bong_trong_silo[silo_so+1] == 3 && bien_di_chuyen == 1)       bien_di_chuyen = 0;
            else if (bien_nho_bong_trong_silo[silo_so-1] == 3 && bien_di_chuyen == 0)       bien_di_chuyen = 1;   
        }
        if(silo_so == 1)    bien_di_chuyen = 0;
        
        if(silo_so > 0 && bien_di_chuyen == 1)                           //di chuyen sang phai
        {
            if(bien_nho_bong_trong_silo[silo_so] == 3)  silo_so--,laze_chay_silo(silo_so);
            
            if(bien_nho_bong_trong_silo[silo_so] == 1 || bien_nho_bong_trong_silo[silo_so] == 3)
            {
                robotRunAngle(1000, 40, -0.2, 0);
                while(lazeNgangXanhValue < do_laze_silo-44){if(wantExit())break;}
                
                robotRunAngle(1000, 10, -0.2, 0);
                while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
                robotStop(0);
                
                silo_so--;
            }                
            if(silo_so == 1)
            {
                bien_di_chuyen = 0;
            }            
        }
        else if(silo_so < 6 && bien_di_chuyen == 0)                      //di chuyen sang trai
        {
            if(bien_nho_bong_trong_silo[silo_so] == 1 || bien_nho_bong_trong_silo[silo_so] == 3)
            {
                robotRunAngle(-1000, 40, -0.2, 0);
                while(lazeNgangXanhValue > do_laze_silo+44){if(wantExit())break;}
                
                robotRunAngle(-1000, 10, -0.2, 0);
                while(CB_TU_NHAN_SILO == 1){if(wantExit())break;}
                robotStop(0);   
                
                silo_so++;
            }  
            
            if(silo_so == 5)
            {
                bien_di_chuyen = 1;
            }
        }
    }
}

void nhan_bong_trong_silo()
{
    if(bien_nho_bong_trong_silo[5] == 1 && bien_nho_bong_trong_silo[1] == 1 && bien_nho_bong_trong_silo[2] == 1 && bien_nho_bong_trong_silo[3] == 1 && bien_nho_bong_trong_silo[4] == 1)
    {
        bien_nho_bong_trong_silo[0]=1;
        // for(i = 1; i <= 5; i++)
        // {
        //     if(bien_nho_bong_da_tha_trong_silo[i] != 0 && bien_nho_bong_trong_silo[i] != 3)
        //     {
        //         silo_so = i;
        //         break;
        //     }
        // }
    }
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
}

void kiem_tra_nhan_bong()
{
    nhan_bong_trong_silo();
    if(bien_nhan_bong == 1)
    {
        tha_bong();
    }
}

void kiem_tra_di_chuyen()
{
    nhan_bong_trong_silo();
    
    while(bien_nhan_bong == 0){di_chuyen(),delay_ms(1000),nhan_bong_trong_silo();}
}


void di_chuyen_len_1()                              //di chuyen len silo 1
{
    RESET_ENCODER();

    silo_so = 1;
    
    duong_di_silo();
    
    kiem_tra_di_chuyen();
    
    silo_vua_chay = silo_so;
}

void di_chuyen_len_2()                              //di chuyen len silo 2
{
    RESET_ENCODER();

    silo_so = 2;
    
    duong_di_silo();
    
    kiem_tra_di_chuyen();
    
    silo_vua_chay = silo_so;
}

void di_chuyen_len_3()                              //di chuyen len silo 3
{
    RESET_ENCODER();

    silo_so = 3;
    
    duong_di_silo();
    
    kiem_tra_di_chuyen();
    
    silo_vua_chay = silo_so;
}

void di_chuyen_len_4()                              //di chuyen len silo 4
{
    RESET_ENCODER();

    silo_so = 4;
    
    duong_di_silo();

    kiem_tra_di_chuyen();
    
    silo_vua_chay = silo_so;
}
void di_chuyen_len_5()                              //di chuyen len silo 5
{
    RESET_ENCODER();

    silo_so = 5;

    duong_di_silo();

    kiem_tra_di_chuyen();
    
    silo_vua_chay = silo_so;
}

void do_bong_trong_Analytics()
{
    if(CB_NHAN_MAU_XANH_TRAI == 0 || CB_NHAN_MAU_XANH_PHAI == 0)    
    {
        bien_do_bong = 1;
        ROLE_HOT_BONG_TAT;
        Mor_Silo = 254, Mor_Silo_day_ra;

        while(CB_NHAN_MAU_XANH_TRAI == 0 || CB_NHAN_MAU_XANH_PHAI == 0){}
        while(CB_DUNG_BANG_TAI == 0){}
        delay_ms(100);
        while(CB_DAY_BONG_RA_NGOAI == 1){}        

        // if (CB_DUNG_BANG_TAI == 0 && CB_DAY_BONG_RA_NGOAI == 0)
        // {
        //     bien_chay_cap_thanh = 1;
        //     while(CB_DUNG_BANG_TAI == 0 && CB_DAY_BONG_RA_NGOAI == 0){}
        // }
        // else if(CB_DUNG_BANG_TAI == 0)
        // {
        //     bien_chay_cap_thanh = 2;
        //     while(CB_NHAN_MAU_XANH_TRAI == 0 || CB_NHAN_MAU_XANH_PHAI == 0){}
        //     while(CB_TU_DUNG_LAY_BANH == 0){}
        //     delay_ms(100);
        // }
        // else if(CB_DAY_BONG_RA_NGOAI == 0)
        // {
        //     bien_chay_cap_thanh = 3;
        //     while(CB_DAY_BONG_RA_NGOAI == 0 && (CB_NHAN_MAU_XANH_TRAI == 0 || CB_NHAN_MAU_XANH_PHAI == 0)){}
        //     while(CB_DAY_BONG_RA_NGOAI == 0 && CB_TU_DUNG_LAY_BANH == 0){}
        //     // delay_ms(200);
        // }
        // else if(CB_DUNG_BANG_TAI == 1 && CB_DAY_BONG_RA_NGOAI == 1)
        // {
        //     bien_chay_cap_thanh = 4;
        //     while(CB_DAY_BONG_RA_NGOAI == 1){}
        // }
        ROLE_BANG_TAI_TAT;
        Mor_Silo = 0;
    }
}
int kiem_tra_dung_tuong_trong_Analystics()
{
    if(HT_DUNG == 1)    return bien_cham_tuong = 0;
    else                return bien_cham_tuong = 1;
}
void do_bong()
{
    resetIMU();
    vTaskDelay(100);
    bien_do_bong = 0;
    bien_chay_cap_thanh = 0;
    bien_nhan_bong = 0;
    Mor_Silo = 254, Mor_Silo_day_vao;
    ROLE_BANG_TAI_BAT;
    ROLE_HOT_BONG_BAT;        
    while (1)
    {
        robotRunAngle(0,10,0,0);
        while((HT_DUNG == 1) && CB_TU_DUNG_LAY_BANH == 0){if(bien_do_bong == 1)break;}

        robotStop(0);
        delay_ms(500);
        if(bien_do_bong == 1)   
        {
            break;
        }
        else if(bien_cham_tuong == 1)
        {
            RESET_ENCODER();
            robotRunAngle(1800, 20, 0, 0);
            while(ENCODER_TONG() < 200){}
        }
    }
    if(bien_ve_xuat_phat != 3)
    {
        end = ENCODER_TONG();
        robotRunAngle(1800, 50, 0, 0.2);
        while(ENCODER_TONG() > end - 300)
        {
            XL_HOT_BONG_BAT_LEN;
            if(wantExit())break;
        }
        for(i=0;i<50;i++)
        {
            if(robotAngle() < -900)
            {
                while(robotAngle() < -600)
                {
                    robotRotateFree(0.5, 0, 100);
                    vTaskDelay(10);
                }
                while(robotAngle() < -900)
                {
                    robotRotateFree(0.5, 0, 50);
                    vTaskDelay(10);
                }
            }
            else
            {
                while(robotAngle() > -900)
                {
                    robotRotateFree(-0.5, 0, 50);
                    vTaskDelay(10);
                }
            }
        }
        robotStop(0);
    }
    
}

void XuatPhat()
{
    // XL_HOT_BONG_HA_XUONG;
    if(NUT_CHUYEN_SAN == 1)
    {
        reset_all();
        
        robotRunAngle(1800, 150, -0.5, 0.2);
        while(ENCODER_TONG() < 2000){if(wantExit())break;}
        
        robotRunAngle(1800, 120, 0.5, 0.2);
        while(ENCODER_TONG() < 4000){if(wantExit())break;}
        
        robotRunAngle(1800, 70, 0.5, 0.2);
        while(lazeSauValue < 37+7){if(wantExit())break;}

        // robotRunAngle(-1750, 20, 0.5, 0.2);
        // while(CB_CAP_THANH == 1){if(wantExit())break;}
        
        robotStop(2);

        reset_all();

        // robotRunAngle(-1000, 50, 0.5, -0.2);
        // while(ENCODER_TONG() < 3700){if(wantExit()) break;}

        robotStop(2);
        RESET_ENCODER();
        
        robotRunAngle(1800, 50, 0, 0);
        while(ENCODER_TONG() < 2350){if(wantExit())break;}

        robotStop(2);
        delay_ms(5000);
        
        robotRotate(30000, 0.5, 0, 150);
        while(robotAngle() < 900){if(wantExit())break;}
        
        robotRotate(30000, -0.5, 0, 20);
        while(robotAngle() > 890){if(wantExit())break;}
        
        reset_all();    

        robotRunAngle(0, 50, 0, 0);
        while(ENCODER_TONG() < 3000){if(wantExit())break;}

        robotStop(2);
        delay_ms(200);

        robotRotate(30000, 0.5, 0, 150);
        while(robotAngle() < 900){if(wantExit())break;}
        
        robotRotate(30000, -0.5, 0, 10);
        while(robotAngle() > 890){if(wantExit())break;}

        robotStop(2);
    }
/**********************************SAN XANH***********************************/
    else
    {
        reset_all();
        
        robotRunAngle(1750, 150, 0, 0);
        while(ENCODER_TONG() < 2200){if(wantExit())break;}
        
        robotRunAngle(1750, 120, 0, 0);
        while(ENCODER_TONG() < 4400){if(wantExit())break;}

        robotRunAngle(1750, 50, 0, 0);
        while(ENCODER_TONG() < 5700){if(wantExit())break;}

        robotStop(0);
        
        robotRunAngle(1800, 20, 0.5, 0.2);
        while(lazeSauValue > 35){if(wantExit())break;}

        // robotRunAngle(-1750, 20, 0.5, 0.2);
        // while(CB_CAP_THANH == 1){if(wantExit())break;}

        for(i=0;i<50;i++)   while(lazeNgangXanhValue < 340) bam_thanh_laze_doc(900, 100, 0, 50, 30, 0);
        
        robotStop(0);
        delay_ms(200);

        // reset_all();

        // robotRunAngle(900, 200, 0.5, -0.2);
        // while(ENCODER_TONG() < 2000){if(wantExit()) break;}
        
        // robotRunAngle(900, 100, 0.5, -0.2);
        // while(ENCODER_TONG() < 3000){if(wantExit()) break;}

        // robotRunAngle(900, 50, 0.5, -0.2);
        // while(ENCODER_TONG() < 4000){if(wantExit()) break;}

        // robotStop(2);
        RESET_ENCODER();
        
        robotRunAngle(1800, 150, 0, 0);
        while(ENCODER_TONG() < 1500){if(wantExit())break;}

        robotStop(0);

        XL_HOT_BONG_HA_XUONG;

        // for(i=0;i<50;i++)
        // {
        //     if(robotAngle() > -900)
        //     {
        //         while(robotAngle() > -600)
        //         {
        //             robotRotateFree(-0.5, 0, 100);
        //             vTaskDelay(10);
        //         }
        //         while(robotAngle() > -900)
        //         {
        //             robotRotateFree(-0.5, 0, 50);
        //             vTaskDelay(10);
        //         }
        //     }
        //     else
        //     {
        //         while(robotAngle() < -900)
        //         {
        //             robotRotateFree(0.5, 0, 50);
        //             vTaskDelay(10);
        //         }
        //     }
        //     robotStop(0);
        // }

        // // reset_all();    

        RESET_ENCODER();

        robotRunAngle(-900, 50, 1800, 1.5);
        while(ENCODER_TONG() < 1500){if(wantExit())break;}

        robotRunAngle(-900, 50, 1800, 1.5);
        while(lazeNgangDoValue > 80){if(wantExit())break;}


        robotStop(0);
        // for(i=0;i<50;i++)
        // {
        //     if(robotAngle() > -1800)
        //     {
        //         while(robotAngle() > -1800)
        //         {
        //             robotRotateFree(-0.5, 0, 100);
        //             vTaskDelay(10);
        //         }
        //         while(robotAngle() > -1800)
        //         {
        //             robotRotateFree(-0.5, 0, 50);
        //             vTaskDelay(10);
        //         }
        //     }
        //     else
        //     {
        //         while(robotAngle() < -1800)
        //         {
        //             robotRotateFree(0.5, 0, 50);
        //             vTaskDelay(10);
        //         }
        //     }
        //     robotRotateStop();
        // }
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
        if(silo_vua_chay == 5)
        {
            di_chuyen_len_4();
        }
        else if(silo_vua_chay == 4)
        {
            di_chuyen_len_3();
        }
        else if(silo_vua_chay == 3)
        {
            di_chuyen_len_2();
        }
        else if(silo_vua_chay == 2)
        {
            di_chuyen_len_1();
        }
        else if(silo_vua_chay == 1)
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

void test()
{
    XuatPhat();

    // do_bong_lan_dau_1();
    do_bong();

    // di_chuyen_len_2();

    // tha_bong();

    // di_chuyen_ve();

    // // do_bong_lan_dau_1();
    // do_bong();

    // di_chuyen_len_1();

    // tha_bong();

    // di_chuyen_ve();
}



///////////////////////////////////////////////// THI ROBOCON ////////////////////////////////////////////////////
void THI()
{
    XuatPhat();

    do_bong_lan_dau_1();

    di_chuyen_len();

    tha_bong();

    di_chuyen_ve();

    while(1)
    {
        do_bong();

        di_chuyen_len();

        tha_bong();

        di_chuyen_ve();
        
        if(bien_nho_silo_co_2_bong != 0)
        {
            di_chuyen_len_bo_bong_thu_3();
            tha_bong();
            di_chuyen_ve();
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
    return 0;
}