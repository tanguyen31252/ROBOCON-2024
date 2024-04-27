
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
char buf[50],ky_tu[40],ky_tu_1[40],ky_tu_2[40],ky_tu_3[40];
uint8_t Buffer_HMI[50];
vs32 bien_hmi;
void HMI_ky_tu(char *_buf1)		  //字符串发送函数
{
//	char Buffer_HMI[]="0";
	int _i=0,_k;

//	 while(buf1[hmi]!=0)
//	 	{
//       Buffer_HMI[hmi]=buf1[hmi];
//	
//		 	hmi++;
//		}
	_k=strlen(_buf1);
	
	for(_i=0;_i<_k;_i++){
			
       Buffer_HMI[_i]=_buf1[_i];
	}
	

DMA_Cmd(DMA1_Stream7, ENABLE);
	}
//}	
	
///////////////
void HMISends(char *buf1)		  //字符串发送函数
{
	u8 hmi=0;
	while(1)
	{
	 if(buf1[hmi]!=0)
	 	{
			USART_SendData(UART5,buf1[hmi]);  //发送一个字节
		//	delay_ms(5);
			while(USART_GetFlagStatus(UART5,USART_FLAG_TXE)==RESET){};//等待发送结束
			//goto main;
		 	hmi++;
		}
	 else 
	 return ;

		}
	}
void HMISendb(u8 k)		         //字节发送函数
{		 
	u8 hmi;
	 for(hmi=0;hmi<3;hmi++)
	 {
	 if(k!=0)
	 	{
			USART_SendData(UART5,k);  //发送一个字节
			while(USART_GetFlagStatus(UART5,USART_FLAG_TXE)==RESET){};//等待发送结束
		}
	 else 
	 return ;

	 } 
} 

/////////////////////////////////


void gui_so (vs32 so_can_gui,u8 vi_tri_gui){
	int hmi;
		
		HMISendb(0x00);
		HMISends("t");
		sprintf(buf,"%d",vi_tri_gui);
					HMISends(buf);
		
		HMISends(".txt=");
	//////////////////////////////
		HMISends("\"");
		
		
		sprintf(buf,"%d",so_can_gui);
			for( hmi=0;hmi<20;hmi++){
						USART_SendData(UART5,buf[hmi]);
						while (USART_GetFlagStatus(UART5, USART_FLAG_TC) == RESET);
		}
	
		HMISends("\"");
				HMISendb(0xff);
						HMISendb(0xff);
						HMISendb(0xff);
}
//////////
void gui_chu(char* chu_can_gui,u8 vi_tri_gui){
		//HMISendb(0x00);
		HMISends("t");	
		sprintf(buf,"%d",vi_tri_gui);
					HMISends(buf);
	
	HMISends(".txt=\"");
	HMISends(chu_can_gui);
	HMISends("\"");
						HMISendb(0xff);
					//	HMISendb(0xff);
					//	HMISendb(0xff);
}
////////////////////////////////////
void HMI_DMI(char* chu_can_gui,vs32 bien_can_gui,vs32 vi_tri_gui){
	char k=0xff,i;
	char 	ky_tu_3[]=".txt=\"";
	char 	ky_tu_4[]="\"";
	char	ky_tu[]="t";	

for(i=0;i<30;i++){
		ky_tu_2[i]=0;
		ky_tu_1[i]=0;
		buf[i]=0;	
	Buffer_HMI[i]=0;
}
buf[0]=10;
buf[1]=255;
buf[2]=255;
buf[3]=255;

sprintf(ky_tu_1,"%d",vi_tri_gui);
strcat (ky_tu,ky_tu_1);
strcat(buf,ky_tu);        ///// 0t1  //nhan duoc chuoi
strcat(buf,ky_tu_3);	    ///// chuoi buf nhan duoc .txt=
strcat(buf,chu_can_gui);	///// chuoi buf nhan duoc chuoi can gui
sprintf(ky_tu_1,"%d",bien_can_gui);
strcat(buf,ky_tu_1);
strcat(buf,ky_tu_4);         
ky_tu_2[0]=0xff;
ky_tu_2[1]=0xff;
ky_tu_2[2]=0xff;

strcat(buf,ky_tu_2);
HMI_ky_tu(buf);

}


void HMI_PUTS(char* chu_can_gui,char* bien_can_gui,vs32 vi_tri_gui){
	char k=0xff,i;
	char 	ky_tu_3[]=".txt=\"";
	char 	ky_tu_4[]="\"";
	char	ky_tu[]="t";	

for(i=0;i<10;i++){
		ky_tu_2[i]=0;
		ky_tu_1[i]=0;
		buf[i]=0;	
}
buf[0]=10;
buf[1]=255;
buf[2]=255;
buf[3]=255;
sprintf(ky_tu_1,"%d",vi_tri_gui);
strcat (ky_tu,ky_tu_1);
strcat(buf,ky_tu);        ///// 0t1  //nhan duoc chuoi
strcat(buf,ky_tu_3);	    ///// chuoi buf nhan duoc .txt=
strcat(buf,chu_can_gui);	///// chuoi buf nhan duoc chuoi can gui
strcat(buf,bien_can_gui);
strcat(buf,ky_tu_4);         
ky_tu_2[0]=0xff;
ky_tu_2[1]=0xff;
ky_tu_2[2]=0xff;
ky_tu_2[3]=0;
ky_tu_2[4]=0;
strcat(buf,ky_tu_2);
HMI_ky_tu(buf);

}
///////////////////////////////////////////
void gui_line(){
//lcd_printInt(0,0,LINE_0);lcd_printInt(0,2,LINE_1);lcd_printInt(0,4,LINE_2);lcd_printInt(0,6,LINE_3);lcd_printInt(0,8,LINE_4);lcd_printInt(0,10,LINE_5);lcd_printInt(0,12,LINE_6);lcd_printInt(0,14,LINE_7);	
			HMISendb(0x00);

		HMISends("t");	
		sprintf(buf,"%d",13);
				HMISends(buf);
	
				HMISends(".txt=\"");
				sprintf(buf,"%d",GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5));
				HMISends(buf);
				sprintf(buf,"%d",GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)) ;
				HMISends(buf);
				sprintf(buf,"%d",GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7));
				HMISends(buf);
				sprintf(buf,"%d",GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6));
				HMISends(buf);
				sprintf(buf,"%d",GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15));
				HMISends(buf);
				sprintf(buf,"%d",GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14));
				HMISends(buf);
				sprintf(buf,"%d",GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13));
				HMISends(buf);
				sprintf(buf,"%d",GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6));
				HMISends(buf);
	
	HMISends("\"");
						HMISendb(0xff);
						HMISendb(0xff);
						HMISendb(0xff);
}


void HMI_PUT_j(tham_so){
	char k=0xff,i;
	char 	ky_tu_3[]=".val=";
	char 	ky_tu_4[]="\"";
	char	ky_tu[]="j";	

for(i=0;i<50;i++){
		ky_tu_2[i]=0;
		ky_tu_1[i]=0;
		buf[i]=0;	
}
buf[0]=10;
buf[1]=255;
buf[2]=255;
buf[3]=255;
sprintf(ky_tu_1,"%d",0);
strcat (ky_tu,ky_tu_1);
strcat(buf,ky_tu);        ///// 0t1  //nhan duoc chuoi
strcat(buf,ky_tu_3);	    ///// chuoi buf nhan duoc .txt=

sprintf(ky_tu_1,"%d",tham_so);
strcat(buf,ky_tu_1);
//strcat(buf,ky_tu_4);         
ky_tu_2[0]=0xff;
ky_tu_2[1]=0xff;
ky_tu_2[2]=0xff;
ky_tu_2[3]=0;
ky_tu_2[4]=0;
strcat(buf,ky_tu_2);
HMI_ky_tu(buf);

}

