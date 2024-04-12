void XUAT_PHAT_SAN_DO(void)
{
	RESET_ENCODER();
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 6000)				bam_Thanh_Lazer_Truoc_SAN_DO(75 ,50,0,20,2); vTaskDelay(1);

	for(i=0;i<50;i++)	while(lazePhaiValue > 30)						bam_Thanh_Lazer_Truoc_SAN_DO(20,50,0,20,2); vTaskDelay(1);
	
	RESET_ENCODER();
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 3000)				bam_Thanh_Lazer_Phai(75,50,0,20,2); vTaskDelay(1);
	
	for(i=0;i<50;i++)	while(lazePhaiValue < 35)						bam_Thanh_Lazer_Phai(20,50,0,20,2); vTaskDelay(1);
	
	RESET_ENCODER();
	robotRunAngle(0,50,0,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 240)	 				vTaskDelay(1);		
	
	
	RESET_ENCODER();
	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 3500)	 				chay_san_Lazer_Phai(50,50,0,170,2); vTaskDelay(1);
	for(i=0;i<50;i++)	while(lazePhaiValue < 160)						chay_san_Lazer_Phai(10,20,0,170,2); vTaskDelay(1);
	RESET_ENCODER();
	
	
	robotRunAngle(-1800,50,0,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 2300)	 				vTaskDelay(1);		
	RESET_ENCODER();
	

	XI_LANH_LUA_BONG_ON;
	robotRunAngle(-1800,4,0,0.1);
	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 2400)	 				vTaskDelay(1);		
	RESET_ENCODER();
	
	robotStop(0);
																													
	while(1);
	
}