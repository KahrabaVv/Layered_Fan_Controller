

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "DC_MOTOR.h"
int main(void)
{
	ADC_ConfigType ADC_Configurations = {DF8,Internal};
	uint8 temp;
	DcMotor_Init();
	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Configurations); /* initialize ADC driver */

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_moveCursor(0,3);
	temp = LM35_getTemperature();
	if(temp<30)
		LCD_displayString("FAN is OFF");
	else
		LCD_displayString("FAN is ON");
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =    C");


	while(1)
	{
		temp = LM35_getTemperature();
		LCD_moveCursor(0,10);
		if(temp>=120){
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,255);

		}
		else if(temp>=90){
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,192);

		}
		else if(temp>=60){
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,128);

		}
		else if(temp>=30){
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,64);

		}
		else if(temp<30){
			DcMotor_Rotate(OFF,0);
			LCD_displayString("OFF");}




		LCD_moveCursor(1,10);
		LCD_intgerToString(temp);
		LCD_displayString(" C ");


	}
}
