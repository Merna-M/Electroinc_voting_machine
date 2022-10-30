#include "LCD_interface.h"
#include "BTN_interface.h"
#define F_CPU 8000000UL
#include "util/delay.h"



int main(void)
{
	uint16 counterA=0 , counterB=0 , counterC=0 , counterD=0;
	//initialize LCD
	LCD_vInit();
	//initialize Buttons
	BTN_vInit('A',PIN0);
	BTN_vInit('A',PIN1);
	BTN_vInit('A',PIN2);
	BTN_vInit('A',PIN3);
	BTN_vInit('A',PIN4);
	//Connecting Pull up
	BTN_vConnectPullUp('A',PIN0,1);
	BTN_vConnectPullUp('A',PIN1,1);
	BTN_vConnectPullUp('A',PIN2,1);
	BTN_vConnectPullUp('A',PIN3,1);
	BTN_vConnectPullUp('A',PIN4,1);
	
	LCD_vMoveCursor(ROW1,COL5);
	LCD_vSendString("Welcome");
	_delay_ms(2000);
	LCD_vClearScreen();
	LCD_vSendString("A=0");
	LCD_vMoveCursor(ROW1,COL9);
	LCD_vSendString("B=0");
	LCD_vMoveCursor(ROW2,COL1);
	LCD_vSendString("C=0");
	LCD_vMoveCursor(ROW2,COL9);
	LCD_vSendString("D=0");
	
    while(1)
    {
        if(BTN_u8Read('A',PIN0) == 0)
		{
			counterA++;
			LCD_vMoveCursor(ROW1,COL3);
			LCD_vSendNumber(counterA);
			while(BTN_u8Read('A',PIN0)==0);
		}	
		else if(BTN_u8Read('A',PIN1) == 0)
		{
			counterB++;
			LCD_vMoveCursor(ROW1,COL11);
			LCD_vSendNumber(counterB);
			while(BTN_u8Read('A',PIN1)==0);
		}	
		else if(BTN_u8Read('A',PIN2) == 0)
		{
			counterC++;
			LCD_vMoveCursor(ROW2,COL3);
			LCD_vSendNumber(counterC);
			while(BTN_u8Read('A',PIN2)==0);
		}
		else if(BTN_u8Read('A',PIN3) == 0)
		{
			counterD++;
			LCD_vMoveCursor(ROW2,COL11);
			LCD_vSendNumber(counterD);
			while(BTN_u8Read('A',PIN3)==0);
		}
		else if(BTN_u8Read('A',PIN4) == 0)
		{
			counterA = counterB = counterC = counterD = 0;
			LCD_vMoveCursor(ROW1,COL3);
			LCD_vSendString("0    ");
			LCD_vMoveCursor(ROW1,COL11);
			LCD_vSendString("0    ");
			LCD_vMoveCursor(ROW2,COL3);
			LCD_vSendString("0    ");
			LCD_vMoveCursor(ROW2,COL11);
			LCD_vSendString("0    ");
			while(BTN_u8Read('A',PIN4)==0);
		}	
    }
}

