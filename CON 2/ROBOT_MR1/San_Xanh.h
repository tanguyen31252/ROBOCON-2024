void restartXanh()
{
    int silo = 4;
    int check_phai = 1;
    reset_all();
    // robotRunAngle(450, 40, 0, 0.5);
    // for(i=0;i<50;i++) while(laze_4H_Value > 50){vTaskDelay(1);}
    // robotRunAngle(0, 60, 0, 0.5);
    // RESET_ENCODER();
    // for(i=0;i<50;i++) while(ENCODER_TONG() < 3900){vTaskDelay(1);}
    // robotRunAngle(0, 20, 0, 0.5);
    // for(i=0;i<50;i++) while(laze_0H_Value > 165){vTaskDelay(1);}
    // RESET_ENCODER();
    // robotRunAngle(900, 60, 0, 0.5);
    // for(i=0;i<50;i++) while(ENCODER_TONG() < 3500){vTaskDelay(1);}

    // robotRunAngle(900, 40, 0, 0.5);
    // for(i=0;i<50;i++) while(laze_4H_Value > 200){vTaskDelay(1);}

    // RESET_ENCODER();
    // robotRunAngle(-1800, 40, 0, 0.5);
    // for(i=0;i<50;i++) while(ENCODER_TONG() < 2600){vTaskDelay(1);}
    // delay_ms(500);
    // robotStop(0);
    // while(1){vTaskDelay(1);}

check_bong:
    check_phai = 1;
    if(laze_4H_Value < 50) {
            XL_NONG_XOAY_BAT;
            XL_DONG_90;
            vTaskDelay(1000);
        }else{
            XL_NONG_XOAY_TAT;
            XL_MO_90;
            vTaskDelay(1000);
        }
    for(i=0;i<150;i++) while(GP_BTN[1] != 22){
        if(GP_BTN[1] == 33) robotRunAngle(-900, 30, 0, -0.5);
        else if(GP_BTN[1] == 11) robotRunAngle(900, 30, 0, 0.5);
        else if(GP_BTN[1] == 44){
            if(laze_4H_Value > 50){
                if(check_phai) robotRunAngle(900,30,0,0.5);
                else robotRunAngle(-900,20,0,0.5);
            }
            else{check_phai = 0;robotRunAngle(-900,30,0,0.5);}
        }

        if(laze_4H_Value < 50) {
            XL_NONG_XOAY_BAT;
            XL_DONG_90;
            vTaskDelay(1000);
        }else{
            XL_NONG_XOAY_TAT;
            XL_MO_90;
            vTaskDelay(1000);
        }
    }
    robotStop(0);
    robotRunAngle(-1800,30,0,-0.5);
    bien_nhan_bong = 0;
    bien_cham_tuong = 0;
    XL_NONG_HA_TAT;
    XL_TR_NONG_HA_BAT;
    delay_ms(500);
    XL_TR_NONG_HA_TAT;
    while (CB_TU_DUNG_THANH == 1 && bien_cham_tuong == 0 && bien_nhan_bong == 0)
    {   
        
        robotRunAngle(-1800,20,0,-0.5);
        Mor_hot_bong = 200, Bang_tai = Mor_nong = 254;
        Mor_hot_bong_vao, Bang_tai_thuan, Mor_nong_ra;
        if(CB_NHAN_DO_TREN == 0 || CB_NHAN_XANH_TREN == 0)  {bien_nhan_bong = 1;XL_NONG_HA_BAT;Mor_hot_bong=0;delay_ms(100);Bang_tai=0;break;}
        while(CB_TU_DUNG_LAY_BANH == 1){
            if(CB_TU_DUNG_THANH == 0) break;
            robotStop(0);
            vTaskDelay(10);
        }

        vTaskDelay(1);
    }
    robotStop(0);
    delay_ms(500);

    while(CB_BONG_NONG_RA == 0){
            Bang_tai = Mor_nong = 254;
            vTaskDelay(1);
        }
    Bang_tai = Mor_nong = 0;
    
    robotRunAngle(0,60,0,-0.5);
    while (laze_8H_Value < 400)
    {
        if(bien_nhan_bong == 1){
            XL_DONG_90;
            XL_NONG_HA_BAT;
            XL_NONG_XOAY_BAT;
            Bang_tai = Mor_nong = 254;
            
            if(CB_BONG_NONG_RA == 0){
                Bang_tai = Mor_nong = 254;
                vTaskDelay(1);
            }
            else{Bang_tai = Mor_nong = 0;}
        }
        else{
            RESET_ENCODER();
            robotRunAngle(0,40,0,-0.5);
            for(i=0;i<50;i++) while(ENCODER_TONG() < 3000){
                vTaskDelay(1);
            }
            goto check_bong;
        }
        vTaskDelay(1);
    }
    
    

//     for(i=0;i<50;i++) while(laze_0H_Value > 30){
//         Bam_thanh_laser_phai(abs(laze_0H_Value - 10)/4,0,list_lazer_silo_xanh[silo],2);
//     }
//     robotStop(0);
// check_silo:
//     for(i=0;i<50;i++) while (abs(laze_4H_Value -list_lazer_silo_xanh[silo] ) > 15)
//     {
//         if(laze_4H_Value > list_lazer_silo_xanh[silo]) robotRunAngle(900,20,0,0.5);
//         else robotRunAngle(-900,20,0,0.5);
//     }

//     // for(i=0;i<50;i++) while (abs(laze_4H_Value -list_lazer_silo_xanh[silo] ) > 2)
//     // {
//     //     if(laze_4H_Value > list_lazer_silo_xanh[silo]) robotRunAngle(850,8,0,0.5);
//     //     else robotRunAngle(-850,8,0,0.5);
//     // }
//     robotStop(0);
//     kiem_tra_cap_thanh();
//     resetIMU();
//     delay_ms(50);
//     for(i=0;i<50;i++) while (abs(laze_4H_Value -list_lazer_silo_xanh[silo] ) > 1)
//     {
//         if(laze_4H_Value > list_lazer_silo_xanh[silo]) robotRunAngle(850,8,0,0.5);
//         else robotRunAngle(-850,8,0,0.5);
//     }
//     // for(i=0;i<50;i++) while(CB_TU_NHAN_SILO != 0){
//     //     if(laze_4H_Value > list_lazer_silo_xanh[silo]) robotRun(850,8);
//     //     else robotRun(-850,8);
//     // }
//     robotStop(0);
//     if(!CB_BONG_3) {
//         silo -= 1;
//         goto check_silo;
//     }
//     robotStop(0);
//     delay_ms(100);
//     Mor_nong = 220;
//     delay_ms(1300);
//     Mor_nong = 0;
    robotStop(0);
    for(i=0;i<50;i++) while (laze_0H_Value < 212)
    {
        Bam_thanh_laser_phai_lui(60,0,190,2);
    }
    RESET_ENCODER();
    robotRunAngle(-1800,30,0,-0.5);
    for(i=0;i<50;i++) while(ENCODER_TONG() < 1400){
        vTaskDelay(1);
    }
    robotStop(0);
    delay_ms(200);
    goto check_bong;

    
}