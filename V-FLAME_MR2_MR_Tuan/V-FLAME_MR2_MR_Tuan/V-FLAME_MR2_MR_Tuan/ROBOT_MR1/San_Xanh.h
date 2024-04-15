////************************ san xanh *********************************
void XUAT_PHAT_SAN_XANH(void)
{
	int speed1 = 40, speed = 10;robotResetIMU();
	RESET_ENCODER();
	
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 6000)				bam_Thanh_Lazer_Truoc_SAN_XANH(40 ,50,0,20,2); vTaskDelay(1);//80
	
	for(i=0;i<50;i++)	while(lazeTraiValue > 30)						bam_Thanh_Lazer_Truoc_SAN_XANH(20,50,0,20,2); vTaskDelay(1);//20
	
	RESET_ENCODER();
	for(i=0;i<50;i++)	while(ENCODER_TONG() < 3000)				bam_Thanh_Lazer_Trai(40,50,0,20,2); vTaskDelay(1); //80
	
	for(i=0;i<50;i++)	while(lazeTraiValue < 35)						bam_Thanh_Lazer_Trai(20,50,0,20,2); vTaskDelay(1);//20
	
	RESET_ENCODER();
	robotRunAngle(0,40,0,0.1); //40
	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 270)	 				vTaskDelay(1);		
	
	RESET_ENCODER();
	robotRunAngle(900,40,0,0.1); //60
	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 4000)	 				vTaskDelay(1);		
	RESET_ENCODER();
	robotRunAngle(-1800,30,0,0.1); //60
	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 2500)	 				vTaskDelay(1);		
	RESET_ENCODER();
	
	XI_LANH_LUA_BONG_ON;
	robotRunAngle(-1800,10,0,0.1); //60
	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 2000)	 				vTaskDelay(1);		
	RESET_ENCODER();
	robotStop(0);
																													
	while(1);
	
}
	























//void XUAT_PHAT_SAN_XANH(void)
//{
//	int speed1 = 40, speed = 10;robotResetIMU();
//	RESET_ENCODER();
//	
//	for(i=0;i<50;i++)	while(ENCODER_TONG() < 6000)				bam_Thanh_Lazer_Truoc_SAN_XANH(40 ,50,0,20,2); vTaskDelay(1);//80
//	
//	for(i=0;i<50;i++)	while(lazeTraiValue > 30)						bam_Thanh_Lazer_Truoc_SAN_XANH(20,50,0,20,2); vTaskDelay(1);//20
//	
//	RESET_ENCODER();
//	for(i=0;i<50;i++)	while(ENCODER_TONG() < 3000)				bam_Thanh_Lazer_Trai(40,50,0,20,2); vTaskDelay(1); //80
//	
//	for(i=0;i<50;i++)	while(lazeTraiValue < 35)						bam_Thanh_Lazer_Trai(20,50,0,20,2); vTaskDelay(1);//20
//	
//	RESET_ENCODER();
//	robotRunAngle(0,40,0,0.1); //40
//	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 270)	 				vTaskDelay(1);		
//	
//	RESET_ENCODER();
//	robotRunAngle(900,40,0,0.1); //60
//	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 4000)	 				vTaskDelay(1);		
//	RESET_ENCODER();
//	robotRunAngle(-1800,40,0,0.1); //60
//	for(i=0;i<50;i++)	while(ENCODER_TONG()  < 3500)	 				vTaskDelay(1);		
//	RESET_ENCODER();
//	
//	robotStop(0);
//																													
//	while(1);
//	
//}



