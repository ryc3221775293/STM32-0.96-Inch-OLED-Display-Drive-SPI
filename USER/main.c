#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include <stdio.h>
#include "oled.h"
/************************************************    
 ALIENTEK��ӢSTM32������       
 ���ߣ�Ψ������      
 CSDN���ͣ�https://blog.csdn.net/tichimi3375      
 12864_SPI_OLED_STM32����
 OLED��ʾ����ģ�飺SSD1306
 ����SPI:SCL,SDA,REST,D/C
 ��Ӧ�ӿڣ�PA5,PA7,PA12,PA11
************************************************/   
int main(void)
{
  

	SPI_OLED_Init();//SPI��ʼ��
	OLED_Init();//OLED��ʼ��	
	while(1)
		{
			// ���Կ��أ�OK
			OLED_Display_Off();
		
			OLED_Display_On();
	
			
			// ���� OK
			OLED_CLS();  
	
	  //  OLED_DLY_ms(5000);
			
			OLED_CLS();
	//		OLED_DLY_ms(5000);
			//����
			OLED_Fill(0,0,127,63, 1);
		  OLED_Refresh_Gram();
	//		OLED_DLY_ms(5000);
			//����
			OLED_CLS();
	    OLED_DrawPoint(0,1,1);
	    OLED_DrawPoint(32,16,1);
	    OLED_DrawPoint(48,32,1);
			OLED_Refresh_Gram();
		
	//    OLED_DLY_ms(10000);
			
			//��ʾ��ĸ
			OLED_CLS();
	    OLED_ShowChar(0,0,'a',12,1);											    
	    OLED_Refresh_Gram();//������ʾ
	 //   OLED_DLY_ms(5000);
			
			//��ʾ����
			OLED_CLS();  
			OLED_ShowNum(0,0,333,3,12);											    
	    OLED_Refresh_Gram();//������ʾ
		
	 //   OLED_DLY_ms(5000);
	    
			// ��ʾ�ַ������������ַ���x8�����㣬������Ϊ��16�������壬��Ҫ��16�ı�������
			OLED_ShowString(0,0,"First");	
			OLED_ShowString(48,0,"Second");	
			OLED_ShowString(16,16,"Third");	
			OLED_ShowString(103,48,"END");											    
	    OLED_Refresh_Gram();//������ʾ

	    OLED_DLY_ms(500);
		} 
}
