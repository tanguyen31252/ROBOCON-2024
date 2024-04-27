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
            if(LAZENGANG_2[SAN][i-1] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][i])
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
            if(LAZENGANG_2[SAN][i+1] < lazePhaiValue && lazePhaiValue < LAZENGANG_2[SAN][i])
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
        XL_DAY_BAT;
        robotRunAngle(-900, 20, 0, 0);
        while(ENCODER_TONG() < 600) {if(wantExit()) break; vTaskDelay(1);}

        robotRunAngle(-900, 25, 0, 0);
        while(lazePhaiValue > laze_ngang_ve){if(wantExit()) break; vTaskDelay(1);}
        
//        for(i=0;i<50;i++)   while(lazeSauValue < laze_doc_truot-20)       bam_thanh_laze_ngang(0, 80, 0, -50, laze_ngang_ve, 2);
//        for(i=0;i<50;i++)   while(lazeSauValue < 310)                     bam_thanh_laze_ngang(0, 20, 0, -50, laze_ngang_ve, 2);
        
        if(lazeTruocValue < laze_ngang_ve)
        {
            robotRunAngle(1800, 10, 0, 0);
            while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        if(lazeTruocValue > laze_ngang_ve)
        {
            robotRunAngle(0, 10, 0, 0);
            while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1){if(wantExit()) break; vTaskDelay(1);}
        }
    }
    else
    {
        XL_DAY_BAT;
        robotRunAngle(900, 20, 0, 0);
        while(ENCODER_TONG() < 600) {if(wantExit()) break; vTaskDelay(1);}

        robotRunAngle(900, 25, 0, 0);
        while(lazePhaiValue > laze_ngang_ve){if(wantExit()) break; vTaskDelay(1);}
        
//        for(i=0;i<50;i++)   while(lazeSauValue < laze_doc_truot-20)       bam_thanh_laze_ngang(1800, 80, 0, -50, laze_ngang_ve, 2);
//        for(i=0;i<50;i++)   while(lazeSauValue < 310)                     bam_thanh_laze_ngang(1800, 20, 0, -50, laze_ngang_ve, 2);
        
        if(lazeTruocValue < laze_ngang_ve)
        {
            robotRunAngle(0, 10, 0, 0);
            while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        if(lazeTruocValue > laze_ngang_ve)
        {
            robotRunAngle(1800, 10, 0, 0);
            while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1){if(wantExit()) break; vTaskDelay(1);}
        }
    }
}

void quy_trinh_trong_lua_hang_1()
{
/****************************************LEN TRONG LUA*************************************************/    
    thong_so_laze_ngang_doc();
    XL_KEP_LUA_TREN_KEP;
    XL_KEP_LUA_DUOI_KEP;
    XL_DAY_LUA_BAT;
    reset_all();
    delay_ms(400);
/****************************************TRONG LUA HANG 1**************************************************/        
/****************************************SAN DO**************************************************/ 
    if(SAN == 1)
    {
//        for(i=0;i<50;i++)   while(lazeTraiValue > laze_doc_truot+30)        bam_thanh_laze_ngang(0, 80, 0, 100, lazengang, 2);
//        for(i=0;i<50;i++)   while(lazeTraiValue > lazedoc+25)               bam_thanh_laze_ngang(0, 25, 0, 100, lazengang, 2);

        robotStop(20);
    }
/****************************************SAN XANH**************************************************/ 
    else
    {
//        for(i=0;i<50;i++)   while(lazePhaiValue > laze_doc_truot+30)        bam_thanh_laze_ngang(0, 80, 0, -100, lazengang, 2);
//        for(i=0;i<50;i++)   while(lazePhaiValue > lazedoc+25)               bam_thanh_laze_ngang(0, 25, 0, -100, lazengang, 2);
        
        robotStop(20);
    }
}    
    
/****************************************TRONG LUA HANG 2**************************************************/      


void quy_trinh_trong_lua_hang_2()
{    
    thong_so_laze_ngang_doc();
    
    ///////////////////////////////////////////// SAN DO////////////////////////////////////////////////////
    if(SAN == 1)
    {   
//        for(i=0;i<50;i++)   while(lazeTraiValue > lazedoc+7)          bam_thanh_laze_ngang(0, 20, 0, 450, lazengang, 2);

        robotStop(0);
    }
    ////////////////////////////////////////////// SAN XANH/////////////////////////////////////////////////////
    else
    {        
//        for(i=0;i<50;i++)   while(lazePhaiValue > lazedoc+5)          bam_thanh_laze_ngang(0, 20, 0, -400, lazengang, 0);

        robotStop(0);
    }    
    
}

void trong_lua()
{
    if(SAN == 1)
    {
        if(hang_trong == 1)         
        {
            XL_DAY_LUA_TAT;
            XL_KEP_LUA_DUOI_NHA;
            hang_trong = 2;
            quy_trinh_trong_lua_hang_2();
        }
        else
        {
            thong_so_laze_ngang_doc();
            if(lan_trong !=3)
            {
                ve_lay_lua();
                lan_trong++;
                hang_trong = 1;
            }
            else
            {
            }
        }
    }
    else
    {
        if(hang_trong == 2)
        {
            thong_so_laze_ngang_doc();
            XL_DAY_TAT;
            XL_KEP_LUA_TREN_NHA;
            if(lan_trong !=3)
            {
                ve_lay_lua();
                lan_trong++;
                hang_trong = 1;
            }
            else
            {
            }            
        }
        else 
        {
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
        while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1) {if(wantExit()) break; vTaskDelay(1);}
    }
    else
    {
        robotRunAngle(-900, 15, 0,0);
        while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1) {if(wantExit()) break; vTaskDelay(1);}
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
        robotRunAngle(-450, 50, 0, 0.5);
        while(ENCODER_TONG() < 1000) {if(wantExit()) break;  vTaskDelay(1);}
        
        robotRunAngle(-450, 20, 0, 0.5);
        while(lazePhaiValue > 313) {if(wantExit()) break;  vTaskDelay(1);}
        
        chuanbicocau();
        
        robotRunAngle(0,50, 0, 0.5);
        while(lazeTruocValue < 150){if(wantExit()) break; vTaskDelay(1);}  
        
        robotRunAngle(450, 15, 0, 0.5);
        while(lazeTruocValue < 150){if(wantExit()) break; vTaskDelay(1);}  
        
        if(lazeTruocValue < 105)
        {
            // robotRunAngle(900, 10, 0, 0);
            robotRun(0, 10);
            while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        else if(lazeTruocValue > 95)
        {
            // robotRunAngle(-900, 10, 0, 0);
            robotRun(1800, 10);
            while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1){if(wantExit()) break; vTaskDelay(1);}
        }
        
        lan_trong++;
    }
    else
    {       
        robotRunAngle(450, 30, 0, 2);
        while(ENCODER_TONG() < 700) {if(wantExit()) break;  vTaskDelay(1);}
        
        // robotRunAngle(-200, 30, 0, 2);
        // while(lazePhaiValue < 300) {if(wantExit()) break;  vTaskDelay(1);}  bam_thanh_laze_ngang(-200,30,0,0)
        
        for(i = 0; i < 50 ; i++) 
        {
            bam_thanh_laze_ngang (0, 30, 0, 2, 50, 300, 0, lazePhaiValue); 
            while(lazeTruocValue > 150){if(wantExit()) break;  vTaskDelay(1);} 
        }

        chuanbicocau();
        
        // robotRunAngle(-150,30, 0, 2);
        // while(lazeTruocValue > 150){if(wantExit()) break; vTaskDelay(1);}  
        
        robotRunAngle(-900, 15, 0, 2);
        while(lazeTruocValue < 300 ){if(wantExit()) break; vTaskDelay(1);}  
        
        // if(lazeTruocValue > 105)
        // {
        //     // robotRunAngle(900, 10, 0, 0);
        //     robotRun(0, 10);
        //     while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1){if(wantExit()) break; vTaskDelay(1);}
        // }
        // else if(lazeTruocValue < 95)
        // {
        //     // robotRunAngle(-900, 10, 0, 0);
        //     robotRun(1800, 10);
        //     while(CB_LUA_TREN == 1 || CB_LUA_DUOI == 1){if(wantExit()) break; vTaskDelay(1);}
        // }
        
        // lan_trong++;
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
        while(lazeTraiValue < 380){if(wantExit()) break; vTaskDelay(1);};

        robotRunAngle(900,20,0,0);
        while (CB_Line_P1 == 0 && CB_Line_P2 == 0 && CB_Line_P3 == 0 && CB_Line_P4 == 0){if(wantExit()) break; vTaskDelay(1);};

        robotStop(0);

        robotRunAngle(1800,20,0,0);
        while(lazeTruocValue > 200){if(wantExit()) break; vTaskDelay(1);};

        RESET_ENCODER();

        robotRunAngle(900,20,0,0);
        while (CB_Line_P1 == 0 && CB_Line_P2 == 0 && CB_Line_P3 == 0 && CB_Line_P4 ==0){if(wantExit()) break; vTaskDelay(1);};

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
        while(lazeTraiValue < 380){if(wantExit()) break; vTaskDelay(1);};

        robotRunAngle(900,20,0,0);
        while (CB_Line_T1 == 0 && CB_Line_T2 == 0 && CB_Line_T3 == 0 && CB_Line_T4 == 0){if(wantExit()) break; vTaskDelay(1);};

        robotStop(0);

        robotRunAngle(1800,20,0,0);
        while(lazeTruocValue > 200){if(wantExit()) break; vTaskDelay(1);};

        RESET_ENCODER();

        robotRunAngle(900,20,0,0);
        while (CB_Line_T1 == 0 && CB_Line_T2 == 0 && CB_Line_T3 == 0 && CB_Line_T4 ==0){if(wantExit()) break; vTaskDelay(1);};

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
