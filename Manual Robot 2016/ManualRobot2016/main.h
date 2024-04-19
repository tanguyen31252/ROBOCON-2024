
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif 

/*
*************************************************************************************************************************************
*															INCLUDED FILES															*
*************************************************************************************************************************************
*/
#include "stm32f10x.h"
extern char autoRun;
extern unsigned char _accAla;
	 
void delay_us(__IO uint32_t num);
void delay_ms(__IO uint32_t num);
void resetIMU(void);
void Nang(int pwm);
void Day (int pwm);
void setMorNang (int pwm);
void setMorDay (int pwm);
void haTay(void);
void nangTay(void);
void xoay_Dung(void);
void xoay_Ngang(void);
char bapBenh (void);
void nang_xichDu(void);
void ha_xichDu(void);
void cB_on (void);
void onDinhGoc(int goc);
void haTayADC(int adc);
void datRobotLenBB (void);
void Giu (void);
void donRobottrenBB (void);
void datRobotLenBB_xanh (void);
void nangTayADC (int adc);
char bapBenh_nhanh(void);
 /*
*************************************************************************************************************************************
*							  						   		GLOBAL FUNCTION PROTOTYPES												*
*************************************************************************************************************************************
*/

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */



#ifdef __cplusplus
}
#endif


#endif /* __MAIN_H */

/**
  * @}
  */

/**
  * @}
  */


/******************* (C) COPYRIGHT 2009 ARMVietNam *****END OF FILE****/

