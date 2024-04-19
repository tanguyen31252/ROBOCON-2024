#include "main.h"
#include "gamepad.h"

//  ************ Dat bien nut nhan  *****************


//    ******************    chuong trinh con    **************

void gamepad_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable GPIO clocks for gamepad control pins */
	RCC_APB2PeriphClockCmd(SPI_MISO_CLK | SPI_MOSI_CLK | SPI_CS_CLK | SPI_SCK_CLK, ENABLE);
	
	/* initialize gamepad control lines to input */
	GPIO_InitStructure.GPIO_Pin 	= SPI_MISO_PIN;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(SPI_MISO_PORT, &GPIO_InitStructure); 
	
	/* initialize gamepad control lines to output */ 	
	GPIO_InitStructure.GPIO_Pin 	= SPI_MOSI_PIN;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(SPI_MOSI_PORT, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin 	= SPI_CS_PIN;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(SPI_CS_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin 	= SPI_SCK_PIN;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(SPI_SCK_PORT, &GPIO_InitStructure);
		
}

unsigned char SPIxmit (unsigned char dta)
{
    unsigned char tmp = 0;
    unsigned char i;
     for (i = 0x01; i > 0; i <<= 1)
    {
        SPI_SCK_CLEAR;
        delay_us(20);
			if(dta & i)		{SPI_MOSI_SET;}
			else 					SPI_MOSI_CLEAR;
        SPI_SCK_SET;
        delay_us(20);
        if (SPI_MISO) tmp |= i;
    }	
    return tmp;
}

void gp_update_btn (void)
{
    SPI_CS_CLEAR;
    delay_us(20);
    SPIxmit(0x01);    //start command
    SPIxmit(0x42); // request data
    SPIxmit(0xff); //rx 0x5A
    GP_BTN[0] = SPIxmit(0xff); //SLCT JOYR JOYL STRT UP   RGHT DOWN LEFT
    GP_BTN[1] = SPIxmit(0xff); //L2   R2   L1   R1   /\   O    X    |_|
    GP_BTN[2] = SPIxmit(0xff); //Right Joy 0x00 = Left  0xFF = Right
    GP_BTN[3] = SPIxmit(0xff); //Right Joy 0x00 = Up    0xFF = Down
    GP_BTN[4] = SPIxmit(0xff); //Left Joy  0x00 = Left  0xFF = Right
    GP_BTN[5] = SPIxmit(0xff); //Left Joy  0x00 = Up    0xFF = Down
		delay_us(20);
    SPI_CS_SET;
		delay_us(20);
}

unsigned char gp_get_mode (void)
{
    unsigned char ret = 0;
    SPI_CS_CLEAR;
    delay_us(20);
    SPIxmit(0x01);
    ret = SPIxmit(0x42);
    SPI_CS_SET;
    delay_us(20);
    return ret;
}
