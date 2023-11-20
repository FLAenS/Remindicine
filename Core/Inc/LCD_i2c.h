/*
 * LCD_i2c.h
 *
 *  Created on: Nov 19, 2023
 *      Author: flaen
 */

#ifndef INC_LCD_I2C_H_
#define INC_LCD_I2C_H_

int xdigit = 0;
int ydigit = 0;
int buttoncache = 0;
int status = 0;
int hour = 0, minute = 0, second = 0;
int set_hour = 0, set_minute = 0, set_second = 0;
int target;
int count_down = 0;

void lcd_i2c()
{
	char str[16];
	int now = HAL_GetTick() / 1000;
	int xValue = 0;
	int yValue = 0;
	int button = rawValues[2] < 100;

	if (rawValues[0] < 512) {
			xValue = -1;
	} else if (rawValues[0] > 4096 - 512) {
			xValue = 1;
	}
	if (rawValues[1] < 512) {
			yValue = 1;
	} else if (rawValues[1] > 4096 - 512) {
			yValue = -1;
	}

	// changing among hour, minute, second, confirm
	if (buttoncache != button)
	{
		buttoncache = button;
		if (button)
			{
				status = (status + 1) % 4;
			}
	}

	HD44780_Clear();
	if (!status)
	{
		HD44780_SetCursor(0,0);
		HD44780_PrintStr("Rings in:");
	}

	// setting hour
	if (status == 1)
	{
		count_down = 0;
		set_hour = hour;
		HD44780_SetCursor(0,0);
		HD44780_PrintStr("Set Hours:");
		if (yValue == 1) set_hour = (set_hour + 1) % 24;
		else if (yValue == -1)
		{
			if (set_hour == 0) set_hour = 23;
			else set_hour -- ;
		}
		hour = set_hour;
	}

	// setting minute
	if (status == 2)
	{
		set_minute = minute;
		HD44780_SetCursor(0,0);
		HD44780_PrintStr("Set Minutes:");
		if (yValue == 1) set_minute = (set_minute + 1) % 60;
		else if (yValue == -1)
		{
			if (set_minute == 0) set_minute = 59;
			else set_minute -- ;
		}
		minute = set_minute;
	}

	// setting seconds
	if (status == 3)
	{
		set_second = second;
		HD44780_SetCursor(0,0);
		HD44780_PrintStr("Set Seconds:");
		if (yValue == 1) set_second = (set_second + 1) % 60;
		else if (yValue == -1)
		{
			if (set_second == 0) set_second = 59;
			else set_second -- ;
		}
		second = set_second;
		target = now + hour * 3600 + minute * 60 + second;
	}

	if (status == 0)
	{
		count_down = 1;
	}

	if (hour == 0 && minute == 0 && second == 0) count_down = 0;

	if (count_down)
	{
		int dt = target - now;
		hour = dt / 3600;
		minute = (dt / 60) % 60;
		second = dt % 60;
	}




	HD44780_SetCursor(8, 1);
	sprintf(str, "%02d:%02d:%02d", hour, minute, second);
	HD44780_PrintStr(str);

}

#endif /* INC_LCD_I2C_H_ */
