void reset_all()
{
    resetIMU();
    RESET_ENCODER();
}
/*******************KHAI BAO GIA TRI LAZE NGANG***************************/
void thong_so_laze_ngang_doc(void)
{
        if      (lan_trong == 1 && hang_trong == 1)     {lazengang = LAZENGANG_1[SAN][1],  lazedoc = LAZEDOC[hang_trong],                                   laze_doc_truot = LAZEDOC[3];}
        else if (lan_trong == 1 && hang_trong == 2)     {lazengang = LAZENGANG_1[SAN][2],  lazedoc = LAZEDOC[hang_trong], laze_ngang_ve = LAZE_VE[SAN][0],  laze_doc_truot = LAZEDOC[4];}
        
        if      (lan_trong == 2 && hang_trong == 1)     {lazengang = LAZENGANG_1[SAN][3],  lazedoc = LAZEDOC[hang_trong],                                   laze_doc_truot = LAZEDOC[3];}
        else if (lan_trong == 2 && hang_trong == 2)     {lazengang = LAZENGANG_1[SAN][4],  lazedoc = LAZEDOC[hang_trong], laze_ngang_ve = LAZE_VE[SAN][1],  laze_doc_truot = LAZEDOC[4];}    
        
        if      (lan_trong == 3 && hang_trong == 1)     {lazengang = LAZENGANG_1[SAN][5],  lazedoc = LAZEDOC[hang_trong],                                   laze_doc_truot = LAZEDOC[3];}
        else if (lan_trong == 3 && hang_trong == 2)     {lazengang = LAZENGANG_1[SAN][6],  lazedoc = LAZEDOC[hang_trong];}
}

void thong_so_hang_bong()
{
    if(SAN == 1)
    {
        for(i=6;i>0;i--)
        {
            if(LAZENGANG_2[SAN][i-1] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][i])
            {
                if(CB_NHAN_MAU_THOC_GIUA == 0)  bong_mau[0][i-1]=1;
                if(CB_NHAN_MAU_TIM_GIUA == 0)   bong_mau[0][i-1]=2;
                
                if(CB_NHAN_MAU_THOC_SAU == 0)   bong_mau[1][i-1]=1;
                if(CB_NHAN_MAU_TIM_SAU == 0)    bong_mau[1][i-1]=2;

            }
        }
    }
    else
    {
        for(i=0;i<6;i--)
        {
            if(LAZENGANG_2[SAN][i+1] < lazeNgangXanhValue && lazeNgangXanhValue < LAZENGANG_2[SAN][i])
            {
                if(CB_NHAN_MAU_THOC_GIUA == 0)  bong_mau[0][i]=1;
                if(CB_NHAN_MAU_TIM_GIUA == 0)   bong_mau[0][i]=2;
                
                if(CB_NHAN_MAU_THOC_SAU == 0)   bong_mau[1][i]=1;
                if(CB_NHAN_MAU_TIM_SAU == 0)    bong_mau[1][i]=2;

            }
        }
    }
}

void ve_lay_lua()
{
    RESET_ENCODER();
    if(SAN == 1)
    {
        robotRunAngle(0, 20, 0, 0);
        while(ENCODER_TONG() < 6) {if(wantExit()) break; vTaskDelay(1);}

        robotRunAngle(900, 25, 0, 0);	 
        while(lazeNgangDoValue > laze_ngang_ve){if(wantExit()) break; vTaskDelay(1);}
        
        for(i=0;i<50;i++)   while(lazeTruocValue < laze_doc_truot-20)       bam_thanh_laze_ngang(1800, 80, 0, -50, laze_ngang_ve, 2);
        for(i=0;i<50;i++)   while(lazeTruocValue < 310)                     bam_thanh_laze_ngang(1800, 20, 0, -50, laze_ngang_ve, 2);
                    
        if(lazeNgangDoValue < laze_ngang_ve)
        {
            robotRunAngle(-900, 10, 0, 0);
            while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        if(lazeNgangDoValue > laze_ngang_ve)
        {
            robotRunAngle(900, 10, 0, 0);
            while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1){if(wantExit()) break; vTaskDelay(1);}
        }
    }
    else
    {
        robotRunAngle(0, 20, 0, 0);
        while(ENCODER_TONG() < 6) {if(wantExit()) break; vTaskDelay(1);}

        robotRunAngle(-900, 25, 0, 0);
        while(lazeNgangXanhValue > laze_ngang_ve){if(wantExit()) break; vTaskDelay(1);}
        
        for(i=0;i<50;i++)   while(lazeTruocValue < laze_doc_truot-20)       bam_thanh_laze_ngang(1800, 80, 0, -50, laze_ngang_ve, 2);
        for(i=0;i<50;i++)   while(lazeTruocValue < 310)                     bam_thanh_laze_ngang(1800, 20, 0, -50, laze_ngang_ve, 2);
        
        if(lazeNgangXanhValue < laze_ngang_ve)
        {
            robotRunAngle(900, 10, 0, 0);
            while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        if(lazeNgangXanhValue > laze_ngang_ve)
        {
            robotRunAngle(-900, 10, 0, 0);
            while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1){if(wantExit()) break; vTaskDelay(1);}
        }
    }
}

void quy_trinh_trong_lua_hang_1()
{
/****************************************LEN TRONG LUA*************************************************/    
    thong_so_laze_ngang_doc();
    
    reset_all();
    delay_ms(100);

    KEP_LUA_13_KEP;
    KEP_LUA_24_KEP;
    delay_ms(100); 
    KEO_LUA_LEN;
    delay_ms(400);
/****************************************TRONG LUA HANG 1**************************************************/        
/****************************************SAN DO**************************************************/ 
    if(SAN == 1)
    {
        for(i=0;i<50;i++)   while(lazeTruocValue > laze_doc_truot+30)        bam_thanh_laze_ngang(0, 80, 0, 100, lazengang, 2);
        for(i=0;i<50;i++)   while(lazeTruocValue > lazedoc+25)               bam_thanh_laze_ngang(0, 25, 0, 100, lazengang, 2);

        robotStop(20);
        
        KEO_LUA_XUONG;
        
        // while(_robotIMUAngle != 0)
        // {
        //     delay_ms(500);
        //     if(_robotIMUAngle < 0)
        //     {
        //         robotRotate(30000, 0.5, 0, 20);
        //         while(_robotIMUAngle < 0){if(wantExit_UP()) break;}
        //         robotRotateStop();
        //     }
        //     else
        //     {
        //         robotRotate(30000, -0.5, 0, 20);
        //         while(_robotIMUAngle > 0){if(wantExit())break;}    
        //         robotRotateStop();
        //     }
        // }
    }
/****************************************SAN XANH**************************************************/ 
    else
    {
        for(i=0;i<50;i++)   while(lazeTruocValue > laze_doc_truot+30)        bam_thanh_laze_ngang(0, 80, 0, -100, lazengang, 2);
        for(i=0;i<50;i++)   while(lazeTruocValue > lazedoc+25)               bam_thanh_laze_ngang(0, 25, 0, -100, lazengang, 2);
        
        robotStop(20);

        KEO_LUA_XUONG;
        
        // while(_robotIMUAngle != 0)
        // {
        //     delay_ms(500);
        //     if(_robotIMUAngle < 0)
        //     {
        //         robotRotate(30000, 0.5, 0, 20);
        //         while(_robotIMUAngle < 0){if(wantExit_UP()) break;}
        //         robotRotateStop();
        //     }
        //     else
        //     {
        //         robotRotate(30000, -0.5, 0, 20);
        //         while(_robotIMUAngle > 0){if(wantExit())break;}    
        //         robotRotateStop();
        //     }
        // }
    }
}    
    
/****************************************TRONG LUA HANG 2**************************************************/      


void quy_trinh_trong_lua_hang_2()
{    
    thong_so_laze_ngang_doc();
    
    ///////////////////////////////////////////// SAN DO////////////////////////////////////////////////////
    if(SAN == 1)
    {   
        for(i=0;i<50;i++)   while(lazeTruocValue > lazedoc+7)          bam_thanh_laze_ngang(0, 20, 0, 450, lazengang, 2);

        robotStop(0);
    }
    ////////////////////////////////////////////// SAN XANH/////////////////////////////////////////////////////
    else
    {        
        for(i=0;i<50;i++)   while(lazeTruocValue > lazedoc+5)          bam_thanh_laze_ngang(0, 20, 0, -400, lazengang, 0);

        robotStop(0);
    }    
    
}

void trong_lua()
{
    if(SAN == 1)
    {
        if(hang_trong == 1)         
        {
            KEP_LUA_13_NHA;
            hang_trong = 2;
            quy_trinh_trong_lua_hang_2();
        }
        else
        {
            thong_so_laze_ngang_doc();
            KEP_LUA_24_NHA;
            if(lan_trong !=3)
            {
                ve_lay_lua();
                lan_trong++;
                hang_trong = 1;
            }
            else
            {
                HOT_BANH_ON;
                KEO_LUA_LEN;
                TAY_GAP_LEN;
            }
        }
    }
    else
    {
        if(hang_trong == 2)
        {
            thong_so_laze_ngang_doc();
            KEP_LUA_13_NHA;
            if(lan_trong !=3)
            {
                ve_lay_lua();
                lan_trong++;
                hang_trong = 1;
            }
            else
            {
                HOT_BANH_ON;
                KEO_LUA_LEN;
                TAY_GAP_LEN;
            }            
        }
        else 
        {
            KEP_LUA_24_NHA;
            hang_trong = 2;
            quy_trinh_trong_lua_hang_2();
        }
    }
}

/////////////////////////////////  RETRY  ////////////////////////////////////
void retry (void)
{
    reset_all();
    hang_trong = 2;
    
/****************************************DI CHUYEN LAY LUA TIEP THEO*************************************************/	
    thong_so_laze_ngang_doc();
    
    if(SAN == 1)
    {
        robotRunAngle(900, 15, 0,0);
        while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1) {if(wantExit()) break; vTaskDelay(1);}
    }
    else
    {
        robotRunAngle(-900, 15, 0,0);
        while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1) {if(wantExit()) break; vTaskDelay(1);}
    }
    
    lan_trong++;
    hang_trong = 1;
    
}
///////////////////////////////// XUAT PHAT///////////////////////////////////
int XuatPhat(void)
{
    reset_all();
/****************************************DI CHUYEN LAY LUA*************************************************/	
	if(SAN == 1)
    {   
        robotRunAngle(450, 50, 650, 0);
        while(ENCODER_FL() < 300) {if(wantExit()) break;  vTaskDelay(1);}
        
        robotRunAngle(450, 50, 650, 0);
        while(lazeTruocValue > 312) {if(wantExit()) break;  vTaskDelay(1);}
        
        chuanbicocau();
        
        robotRunAngle(900, 25, 0, 0);
        while(lazeNgangDoValue > 277) {if(wantExit()) break;  vTaskDelay(1);}                                         //de y cai nay
                
        robotRunAngle(1800, 13, 0, 0);
        while(lazeTruocValue < 312){if(wantExit()) break; vTaskDelay(1);}  
        
        if(lazeNgangDoValue < 268)                                                                                    //de y cai nay
        {
            robotRunAngle(-900, 10, 0, 0);
            while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        else if(lazeNgangDoValue > 275)                                                                               //de y cai nay
        {
            robotRunAngle(900, 10, 0, 0);
            while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        
        lan_trong++;
    }
    else
    {       
        robotRunAngle(-450, 50, 0, 0.5);
        while(ENCODER_FR() < 300) {if(wantExit()) break;  vTaskDelay(1);}
        
        robotRunAngle(-450, 50, 0, 0.5);
        while(lazeTruocValue > 313) {if(wantExit()) break;  vTaskDelay(1);}
        
        chuanbicocau();
        
        robotRunAngle(-900, 20, 0, 0.5);
        while(lazeNgangXanhValue > 285){if(wantExit()) break; vTaskDelay(1);}  
        
        robotRunAngle(1800, 15, 0, 0.5);
        while(lazeTruocValue < 315){if(wantExit()) break; vTaskDelay(1);}  
        
        if(lazeNgangXanhValue < 276)
        {
            // robotRunAngle(900, 10, 0, 0);
            robotRun(950, 10);
            while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        else if(lazeNgangXanhValue > 281)
        {
            // robotRunAngle(-900, 10, 0, 0);
            robotRun(-950, 10);
            while(CB_KEP_LUA_1 == 1 || CB_KEP_LUA_4 == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        
        lan_trong++;
    }
}

void THI()
{
    XuatPhat();

    while(lan_trong!=3)
    {
        quy_trinh_trong_lua_hang_1();
        delay_ms(500);
        trong_lua();
        delay_ms(500);
        trong_lua();
    }

    while(1)
    {
        
    }

}

// char robotLineDetect(unsigned char speed)
// {
//     char vitri = 0;

//        do{
// 						robotRunAngle(0,20,0,0)                                // toc do chay den line
// 						do{
// 									if(!cb_TTruoc || !cb_TSau) vitri=1;
// 									else if(!cb_PTruoc || !cb_PSau) vitri=2;
// 									else vitri=0;
// 									if(wantExit()) return 0;
// 							}
// 						while(vitri==0);

// 									robotStop(0);
// 									delay_ms(10);

// 									if(!cb_TTruoc || !cb_TSau) vitri=1;
// 									else if(!cb_PTruoc || !cb_PSau) vitri=2;
// 									else vitri=0;
// 									if(wantExit()) return 0;
// 				}
// 			while(vitri==0);

//     if(vitri==2)// ben Trai sai
//     {
//         robotRotate(30000, 0.6, 2);
//         while(cb_TTruoc && cb_TSau) if(wantExit()) return 0;
//     }
//     else // ben Phai sai
//     {
//         robotRotate(-30000, 0.6, 1);
//         while(cb_PTruoc && cb_PSau)if(wantExit()) return 0;
//     }

//     robotStop(0);
//     return 1;
// }

// void EX()
//     {
//         while (1)
//         {
//             robotRunAngle(0,20,0,0);
//             if ((CB_Line_T1 == 0 && CB_Line_T2 == 0) && (CB_Line_T3 == 1 && CB_Line_T4 == 1 )) 
//             {
//                 robotRunAngle(-500,20,0,0);
//                 while (CB_Line_T2 == 0 && CB_Line_T3 == 0){}
//             }
//             else if ((CB_Line_T1 == 1 && CB_Line_T2 == 1) && (CB_Line_T3 == 0 && CB_Line_T4 == 0))
//             {
//                 robotRunAngle(500,20,0,0);
//                 while (CB_Line_T2 == 0 && CB_Line_T3){}
//             }
//         }

        
//     }

void LEN_SAN_2()
//////////////////////////SAN DO//////////////////////////
{
    reset_all();
    if (SAN == 1)
    {
        robotFixAngle();
        robotRunAngle(900,20,0,0);
        while(lazeNgangDoValue < 380){};

        robotRunAngle(900,20,0,0);
        while (CB_Line_P1 == 0 && CB_Line_P2 == 0 && CB_Line_P3 == 0 && CB_Line_P4 == 0){};

        robotStop(0);

        robotRunAngle(1800,20,0,0);
        while(lazeTruocValue > 200){};

        RESET_ENCODER();

        robotRunAngle(900,20,0,0);
        while (CB_Line_P1 == 0 && CB_Line_P2 == 0 && CB_Line_P3 == 0 && CB_Line_P4 ==0){};

        while (CB_Line_P1 == 0 && CB_Line_P2 == 0 && CB_Line_P3 == 0 && CB_Line_P4 ==0)
        {
            robotRunAngle(0,20,0,0);
            if (lazeTruocValue > 120)
        {
            break;
        }
        };
    }

    else 
    {
        robotFixAngle();
        robotRunAngle(900,20,0,0);
        while(lazeNgangDoValue < 380){};

        robotRunAngle(900,20,0,0);
        while (CB_Line_T1 == 0 && CB_Line_T2 == 0 && CB_Line_T3 == 0 && CB_Line_T4 == 0){};

        robotStop(0);

        robotRunAngle(1800,20,0,0);
        while(lazeTruocValue > 200){};

        RESET_ENCODER();

        robotRunAngle(900,20,0,0);
        while (CB_Line_T1 == 0 && CB_Line_T2 == 0 && CB_Line_T3 == 0 && CB_Line_T4 ==0){};

        while (CB_Line_T1 == 0 && CB_Line_T2 == 0 && CB_Line_T3 == 0 && CB_Line_T4 ==0)
        {
            robotRunAngle(0,20,0,0);
            if (lazeTruocValue > 120)
        {
            break;
        }
        };
    }
}
