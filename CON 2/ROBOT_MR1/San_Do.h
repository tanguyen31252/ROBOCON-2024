void reset_all()
{
    resetIMU();
    RESET_ENCODER();
}
void encoder_silo(int silo_sap_chay)
{
    if     (silo_sap_chay == 1)            do_encoder_silo = silo_1;
    else if(silo_sap_chay == 2)            do_encoder_silo = silo_2;
    else if(silo_sap_chay == 3)            do_encoder_silo = silo_3;
    else if(silo_sap_chay == 4)            do_encoder_silo = silo_4;
    else if(silo_sap_chay == 5)            do_encoder_silo = silo_5;
}

void tha_bong()
{
    while(HT_DUNG_TREN == 1){Mor_Silo = 150, Mor_Silo_next;}
    
    delay_ms(500);
    KEP_BONG_NHA;
    delay_ms(500);
    
    bien_nho_bong_da_tha_trong_silo[silo_so]++;
    
    Mor_Silo = 150, Mor_Silo_back;
    while(HT_DUNG_DUOI == 1){Mor_Silo = 150, Mor_Silo_back;}
}

void di_chuyen_ve()
{   
    RESET_ENCODER();
/********************SAN DO******************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        robotRunAngle(600, 30, -10, 0);
        while(HT_PHAI == 1){if(wantExit){break;}}
        
        RESET_ENCODER();
        
        // robotRunAngle(0, 30, -10, 0);
        // while(ENCODER_TONG() < 50){}
                        
        // if(silo_so > 3)
        // {
        //     robotRunAngle(900, 30, 0, 0);
        //     while(ENCODER_TONG() > 80){}
        // }
        // else if(silo_so < 3)
        // {
        //     robotRunAngle(-900, 30, 0, 0);
        //     while(ENCODER_TONG() < 110){}
        // }
    }
/********************SAN XANH*************************/
    else
    {
        robotRunAngle(-600, 30, -10, 0);
        while(HT_TRAI == 1){if(wantExit){break;}}
        
        RESET_ENCODER();
        
        // robotRunAngle(0, 30, -10, 0);
        // while(ENCODER_TONG() < 50){}
                        
        // if(silo_so > 3)
        // {
        //     robotRunAngle(900, 30, 0, 0);
        //     while(ENCODER_TONG() > 80){}
        // }
        // else if(silo_so < 3)
        // {
        //     robotRunAngle(-900, 30, 0, 0);
        //     while(ENCODER_TONG() < 110){}
        // }
        robotStop(2);
    }
    

}

void duong_di_silo()
{
    encoder_silo(silo_so);
    bien_nhan_bong = 0;
    
    if(_robotIMUAngle < 0)
    {
        robotRotate(30000, 0.5, 0, 35);
        while(_robotIMUAngle <= 0){if(wantExit_UP()) break;}
    }
    else
    {            
        robotRotate(30000, -0.5, 0, 35);
        while(_robotIMUAngle >= 0){if(wantExit_UP()) break;}
    }
    robotRunAngle(1800, 100, 0, 0);
    while(ENCODER_TONG() < 100){}

    
/****************************************SAN DO****************************************/
    if(NUT_CHUYEN_SAN == 1)
    {   
        robotRunAngle(900, 20, -6, 0.5);
        while(HT_PHAI == 1){}
        
        robotStop(2);
        delay_ms(500);
        
        robotRunAngle(900, 5, -6, 0.5);
        while(HT_PHAI == 1){}
            
        robotStop(2);
        reset_all();
        
        robotRunAngle(1750, 15, -6, 0.5);
        while(HT_DUNG_SAU == 1){}
        
        delay_ms(50);
            
        robotRunAngle(1800, 5, -6, 0.5);
        while(HT_DUNG_SAU == 1){}
            
        robotStop(2);
            
        reset_all();
            
        robotRunAngle(-1000, 25, -6, 0.3);
        while(ENCODER_TONG() < do_encoder_silo){}   
        
        robotStop(2);
            
        robotRunAngle(1000, 5, -6, 0.3);
        while(CB_TU_NHAN_SILO == 1){if(!START) break;}
        robotStop(2);
    }
/****************************************SAN XANH****************************************/
    else    
    {   
        robotRunAngle(-900, 20, -6, 0.5);
        while(HT_TRAI == 1){}
        
        robotStop(2);
        delay_ms(500);
        
        robotRunAngle(-900, 5, -6, 0.5);
        while(HT_TRAI == 1){}
            
        robotStop(2);
        reset_all();
        
        robotRunAngle(-1750, 15, -6, 0.5);
        while(HT_DUNG_SAU == 1){}
        
        delay_ms(50);
            
        robotRunAngle(1800, 5, -6, 0.5);
        while(HT_DUNG_SAU == 1){}
            
        robotStop(2);
            
        reset_all();
            
        robotRunAngle(1000, 25, -6, 0);
        while(ENCODER_TONG() < do_encoder_silo){}   
        
        robotStop(2);
            
        robotRunAngle(1000, 5, -6, 0);
        while(CB_TU_NHAN_SILO == 1){if(!START) break;}
        robotStop(2);
    }
}

void di_chuyen()
{
/****************************************SAN DO****************************************/
    if(NUT_CHUYEN_SAN == 1)
    {
        encoder_silo(silo_so);
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
                robotRunAngle(-900, 20, 0, 0);
                while(ENCODER_TONG() < do_encoder_silo + 20){}
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
                robotRunAngle(900, 20, 0, 0);
                while(ENCODER_TONG() < do_encoder_silo - 20){}
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
        encoder_silo(silo_so);
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
            if(bien_nho_bong_trong_silo[silo_so] == 3)  silo_so--,encoder_silo(silo_so);
            
            if(bien_nho_bong_trong_silo[silo_so] == 1 || bien_nho_bong_trong_silo[silo_so] == 3)
            {
                robotRunAngle(960, 20, -10, -0.5);
                while(ENCODER_TONG() < do_encoder_silo + 20){}
                
                robotRunAngle(1100, 5, -10, -0.5);
                while(CB_TU_NHAN_SILO == 1){}
                
                robotStop(2);
                
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
                robotRunAngle(-1000, 20, 6, 0);
                while(ENCODER_TONG() < do_encoder_silo - 20){}
                
                robotRunAngle(-1000, 5, 6, 0);
                while(CB_TU_NHAN_SILO == 1){}
                
                robotStop(2);
                
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
void do_bong()
{
    bien_do_bong = 0;
    bien_chay_cap_thanh = 0;
    
    #pragma region code_con_2_moi
    while(1)
    {
/*************************SAN DO*********************************/
        if(NUT_CHUYEN_SAN == 1)
        {
            robotRunAngle(0, 20, 0, 0);
            while(HT_TRUOC_TRAI == 1 && HT_TRUOC_PHAI == 1)
            {
                if(bien_do_bong == 1)
                {
                    robotRunAngle(_robotIMUAngle, 5, 0, 0);
                    while(CB_KEP_BONG == 1){}

                    robotStop(2);

                    delay_ms(200);
                    KEP_BONG_KEP;
                    delay_ms(500);

                    if(CB_NHAN_MAU_DO == 0)     {break;}
                    else                        {tha_bong();}
                }
            }
            if(bien_do_bong == 1) break;
            
            RESET_ENCODER();
            robotRunAngle(1800, 50, 0, 0);
            while(ENCODER_TONG() < 100){}
            
            if(bien_chay_cap_thanh%3 == 0)
            {
                robotRunAngle(-900, 20, 0, 0);
                while(ENCODER_TONG() < 250){}
                    
                bien_chay_cap_thanh++;
            }
            else
            {
                robotRunAngle(900, 20, 0, 0);
                while(HT_PHAI == 1){}
            }
            
            robotStop(2);
        }
/*************************SAN XANH*********************************/
        else
        {
            robotRunAngle(0, 20, 0, 0);
            while(HT_TRUOC_TRAI == 1 && HT_TRUOC_PHAI == 1)
            {
                if(bien_do_bong == 1)
                {
                    robotRunAngle(_robotIMUAngle, 5, 0, 0);
                    while(CB_KEP_BONG == 1){}

                    robotStop(2);

                    delay_ms(200);
                    KEP_BONG_KEP;
                    delay_ms(500);

                    if(CB_NHAN_MAU_XANH == 0)   {break;}
                    else                        {tha_bong();}
                }
            }
            if(bien_do_bong == 1) break;
            
            RESET_ENCODER();
            robotRunAngle(1800, 50, 0, 0);
            while(ENCODER_TONG() < 100){}
            
            if(bien_chay_cap_thanh%3 == 0)
            {
                robotRunAngle(900, 20, 0, 0);
                while(ENCODER_TONG() < 250){}
                    
                bien_chay_cap_thanh++;
            }
            else
            {
                robotRunAngle(-900, 20, 0, 0);
                while(HT_TRAI == 1){}
            }

            robotStop(2);

        }
    }
            #pragma endregion
        
    delay_ms(100);
}
void XuatPhat()
{
    if(NUT_CHUYEN_SAN == 1)
    {reset_all();
        
        robotRunAngle(1800, 100, 0, 0);
        while(ENCODER_TONG() < 80){if(wantExit_UP()) break;}
        
        robotStop(2);
        
        robotRunAngle(1800, 10, 0, 0);
        while(ENCODER_TONG() < 100){if(wantExit_UP()) break;}
        
        robotStop(2);
        
        robotRunAngle(-1250, 55, 0, 0);
        while(ENCODER_TONG() < 185){if(wantExit_UP()) break;}

        robotStop(2);
        delay_ms(100);
        
        robotRunAngle(-900, 55, 0, 0);
        while(ENCODER_TONG() < 242){if(wantExit_UP()) break;}
        
        robotStop(2);
        delay_ms(100);
        
        RESET_ENCODER();
        
        robotRunAngle(1800, 80, 0, 0);
        while(ENCODER_TONG() < 50){if(wantExit_UP()) break;}
        
        robotStop(2);
        delay_ms(100);
                
        robotRotate(30000, 0.5, 0, 150);
        while(_robotIMUAngle < 900){if(wantExit_UP()) break;}

        robotStop(2);

        robotRotate(30000, -0.5, 0, 20);
        while(_robotIMUAngle > 900){if(wantExit_UP()) break;}

        robotStop(2);
        reset_all();
        
        robotRunAngle(0, 40, 1800, 0);
        robotRotate(30000, 0.5, 0, 20);
        // while(ENCODER_TONG() < 50);      
        while (_robotIMUAngle < 450){}
        
        robotStop(2);
        
        delay_ms(100);
    }
/**********************************SAN XANH***********************************/
    else
    {
        reset_all();
        
        robotRunAngle(1800, 100, 0, 0);
        while(ENCODER_TONG() < 80){if(wantExit_UP()) break;}
        
        robotStop(2);
        
        robotRunAngle(1800, 10, 0, 0);
        while(ENCODER_TONG() < 100){if(wantExit_UP()) break;}
        
        robotStop(2);
        
        robotRunAngle(1250, 55, 0, 0);
        while(ENCODER_TONG() < 185){if(wantExit_UP()) break;}

        robotStop(2);
        delay_ms(100);

        robotStop(2);
        
        robotRunAngle(900, 55, 0, 0);
        while(ENCODER_TONG() < 242){if(wantExit_UP()) break;}
        
        robotStop(2);
        delay_ms(100);
        
        RESET_ENCODER();
        
        robotRunAngle(1800, 80, 0, 0);
        while(ENCODER_TONG() < 50){if(wantExit_UP()) break;}
        
        robotStop(2);
        delay_ms(100);
                
        robotRotate(30000, -0.5, 0, 150);
        while(_robotIMUAngle > -900){if(wantExit_UP()) break;}

        robotStop(2);

        robotRotate(30000, 0.5, 0, 20);
        while(_robotIMUAngle < -900){if(wantExit_UP()) break;}

        robotStop(2);
        reset_all();
        
        robotRunAngle(0, 40, 1800, 0);
        robotRotate(30000, -0.5, 0, 20);
        // while(ENCODER_TONG() < 50);      
        while (_robotIMUAngle > -450){}
        
        robotStop(2);
        
        delay_ms(100);
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
        robotRunAngle(1800, 15, 0, 0);
        while(HT_DUNG_SAU == 1){}
        
        RESET_ENCODER();

        robotRunAngle(-900, 50, 850, 0);
        while(ENCODER_TONG() < 80){if(wantExit_UP()) break;}
        
        robotRunAngle(-900, 20, 850, 0);
        while(ENCODER_TONG() < 113){if(wantExit_UP()) break;}
        
        robotStop(2);
        RESET_ENCODER();
        
        robotRunAngle(1800, 80, 0, 0);
        while(ENCODER_TONG() < 70){if(wantExit_UP()) break;}
                
        robotRotate(30000, 0.5, 0, 100);
        while(_robotIMUAngle < 900){if(wantExit_UP()) break;}

        robotRotate(30000, -0.5, 0, 20);
        while(_robotIMUAngle > 900){if(wantExit_UP()) break;}
        
        robotStop(2);
        delay_ms(500);
        reset_all();
        
        robotRunAngle(0, 40, 0, 0);
        while(ENCODER_TONG() < 15){if(wantExit_UP()) break;}
        
        quy_trinh_lua_bong_up_silo();
    }
    else
    {
        robotRunAngle(1800, 15, 0, 0);
        while(HT_DUNG_SAU == 1){}
        
        RESET_ENCODER();

        robotRunAngle(900, 50, 850, 0);
        while(ENCODER_TONG() < 80){if(wantExit_UP()) break;}
        
        robotRunAngle(900, 20, 850, 0);
        while(ENCODER_TONG() < 113){if(wantExit_UP()) break;}
        
        RESET_ENCODER();
        
        robotRunAngle(1800, 80, 0, 0);
        while(ENCODER_TONG() < 70){if(wantExit_UP()) break;}
        
        robotRotate(30000, -0.5, 0, 100);
        while(_robotIMUAngle > -900){if(wantExit_UP()) break;}

        robotStop(2);
        delay_ms(500);

        robotRotate(30000, 0.5, 0, 20);
        while(_robotIMUAngle < -900){if(wantExit_UP()) break;}
        
        robotStop(2);
        delay_ms(500);
        reset_all();
        
        robotRunAngle(0, 40, 0, 0);
        while(ENCODER_TONG() < 15){if(wantExit_UP()) break;} 
        
        quy_trinh_lua_bong_up_silo();
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
        
    do_bong();

    di_chuyen_len_5();
    
    tha_bong();

    di_chuyen_ve();

    while(1)
    {
        do_bong();
        
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

    for(i = 1; i <= silo_so; i++)
    {
        if(bien_nho_bong_da_tha_trong_silo[i] != 0 && bien_nho_bong_trong_silo[i] != 3)
        {
            break;
        }
    }
}
