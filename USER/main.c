#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include <stdio.h>
#include "oled.h"
/************************************************    
 ALIENTEK精英STM32开发板       
 作者：唯恋殊雨      
 CSDN博客：https://blog.csdn.net/tichimi3375      
 12864_SPI_OLED_STM32驱动
 OLED显示驱动模块：SSD1306
 四线SPI:SCL,SDA,REST,D/C
 对应接口：PA5,PA7,PA12,PA11
************************************************/   
int main(void)
{
  

	SPI_OLED_Init();//SPI初始化
	OLED_Init();//OLED初始化	
	while(1)
		{
			// 测试开关，OK
			OLED_Display_Off();
		
			OLED_Display_On();
	
			
			// 清屏 OK
			OLED_CLS();  
	
	  //  OLED_DLY_ms(5000);
			
			OLED_CLS();
	//		OLED_DLY_ms(5000);
			//满屏
			OLED_Fill(0,0,127,63, 1);
		  OLED_Refresh_Gram();
	//		OLED_DLY_ms(5000);
			//画点
			OLED_CLS();
	    OLED_DrawPoint(0,1,1);
	    OLED_DrawPoint(32,16,1);
	    OLED_DrawPoint(48,32,1);
			OLED_Refresh_Gram();
		
	//    OLED_DLY_ms(10000);
			
			//显示字母
			OLED_CLS();
	    OLED_ShowChar(0,0,'a',12,1);											    
	    OLED_Refresh_Gram();//更新显示
	 //   OLED_DLY_ms(5000);
			
			//显示数子
			OLED_CLS();  
			OLED_ShowNum(0,0,333,3,12);											    
	    OLED_Refresh_Gram();//更新显示
		
	 //   OLED_DLY_ms(5000);
	    
			// 显示字符串，方向按照字符数x8来计算，竖向因为是16像素字体，需要用16的倍数处理
			OLED_ShowString(0,0,"First");	
			OLED_ShowString(48,0,"Second");	
			OLED_ShowString(16,16,"Third");	
			OLED_ShowString(103,48,"END");											    
	    OLED_Refresh_Gram();//更新显示

	    OLED_DLY_ms(500);
		} 
}
