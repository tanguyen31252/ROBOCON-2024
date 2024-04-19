 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GAMEPAD_H
#define __GAMEPAD_H

#ifdef __cplusplus
 extern "C" {
#endif 

/*
*************************************************************************************************************************************
*															INCLUDED FILES															*
*************************************************************************************************************************************
*/
#include "stm32f10x.h"

// khai bao ket noi cho gamepad 

#define SPI_MISO_PORT         GPIOD
#define SPI_MISO_CLK          RCC_APB2Periph_GPIOD 
#define SPI_MISO_PIN          GPIO_Pin_9

#define SPI_MOSI_PORT         GPIOD
#define SPI_MOSI_CLK          RCC_APB2Periph_GPIOD 
#define SPI_MOSI_PIN          GPIO_Pin_10

#define SPI_CS_PORT           GPIOD
#define SPI_CS_CLK            RCC_APB2Periph_GPIOD 
#define SPI_CS_PIN            GPIO_Pin_7

#define SPI_SCK_PORT          GPIOD
#define SPI_SCK_CLK           RCC_APB2Periph_GPIOD 
#define SPI_SCK_PIN           GPIO_Pin_8

// thiet lap in/out

#define SPI_MISO 					GPIO_ReadInputDataBit(SPI_MISO_PORT, SPI_MISO_PIN)  //SPI_MISO_PORT->IDR&SPI_MISO_PIN	

#define SPI_MOSI_SET 			SPI_MOSI_PORT->BSRR = SPI_MOSI_PIN
#define SPI_MOSI_CLEAR 		SPI_MOSI_PORT->BRR = SPI_MOSI_PIN

#define SPI_CS_SET 				SPI_CS_PORT->BSRR = SPI_CS_PIN
#define SPI_CS_CLEAR 			SPI_CS_PORT->BRR = SPI_CS_PIN

#define SPI_SCK_SET 			SPI_SCK_PORT->BSRR = SPI_SCK_PIN
#define SPI_SCK_CLEAR 		SPI_SCK_PORT->BRR = SPI_SCK_PIN

#define GP_MASK_SELECT 		0x01
#define GP_MASK_START			0x08
#define GP_MASK_UP				0x10
#define GP_MASK_RIGHT			0x20
#define GP_MASK_DOWN			0x40
#define GP_MASK_LEFT			0x80
#define GP_MASK_L2				0x01
#define GP_MASK_R2				0x02
#define GP_MASK_L1				0x04
#define GP_MASK_R1				0x08
#define GP_MASK_TAMGIAC    0x10
#define GP_MASK_O           0x20
#define GP_MASK_X           0x40
#define GP_MASK_VUONG      0x80
#define GP_MASK_RJOY        0x02
#define GP_MASK_LJOY        0x04

#define GP_MODE_DIGITAL               0x41
#define GP_MODE_NEGCON                0x23
#define GP_MODE_ANALOGUE_RED_LED      0x73
#define GP_MODE_ANALOGUE_GREEN_LED    0x53
#define GP_MODE_NONE                  0xff


// cac nut nhan tren tay game

#define SELECT        (GP_BTN[0] & GP_MASK_SELECT)
#define START        (GP_BTN[0] & GP_MASK_START)
#define LJOY        (GP_BTN[0] & GP_MASK_RJOY)
#define RJOY        (GP_BTN[0] & GP_MASK_LJOY)

#define UP            (GP_BTN[0] & GP_MASK_UP)
#define RIGHT        (GP_BTN[0] & GP_MASK_RIGHT)
#define DOWN        (GP_BTN[0] & GP_MASK_DOWN)
#define LEFT        (GP_BTN[0] & GP_MASK_LEFT)

#define L2            (GP_BTN[1] & GP_MASK_L2)
#define R2            (GP_BTN[1] & GP_MASK_R2)
#define L1            (GP_BTN[1] & GP_MASK_L1)
#define R1            (GP_BTN[1] & GP_MASK_R1)

#define TAMGIAC    (GP_BTN[1] & GP_MASK_TAMGIAC)
#define O            (GP_BTN[1] & GP_MASK_O)
#define X            (GP_BTN[1] & GP_MASK_X)
#define VUONG        (GP_BTN[1] & GP_MASK_VUONG)

#define RJOY_LR        (GP_BTN[2])
#define RJOY_UD        (GP_BTN[3])
#define LJOY_LR        (GP_BTN[4])
#define LJOY_UD        (GP_BTN[5])

//    *************    khai bao bien toan cuc     ***********

extern unsigned char GP_BTN [6];


void gamepad_Init(void);
unsigned char SPIxmit (unsigned char dta);
void gp_update_btn (void);
unsigned char gp_get_mode (void);


/*
*************************************************************************************************************************************
*															PRIVATE MACRO															*
*************************************************************************************************************************************
*/

/*
*************************************************************************************************************************************
*															PRIVATE VARIABLES														*
*************************************************************************************************************************************
*/


/*
*************************************************************************************************************************************
*															PRIVATE FUNCTION PROTOTYPES												*
*************************************************************************************************************************************
*/



 /*
*************************************************************************************************************************************
*							  						   		GLOBAL FUNCTION PROTOTYPES												*
*************************************************************************************************************************************
*/

// ****** High-levlel functions ******
// these functions provide the high-level control of the LCD
// such as clearing the display, setting cursor positions,
// displaying text and special characters



#ifdef __cplusplus
}
#endif


#endif /* __GAMEPAD_H */

/******************* (C) COPYRIGHT 2009 ARMVietNam *****END OF FILE****/
