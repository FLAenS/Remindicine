/*
 * Light_Sensor.h
 *
 *  Created on: Nov 19, 2023
 *      Author: flaen
 */

#ifndef INC_LIGHT_SENSOR_H_
#define INC_LIGHT_SENSOR_H_

void Light_Sensor()
{
	int lux = rawValues[3];
	if (hour == 0 && minute == 0 && second == 0)
	{
		// Blink the LED for one second
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1); // Turn ON the LED
	    HAL_Delay(1000);// Delay for one second
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0); // Turn OFF the LED
	    HAL_Delay(1000); // Delay for one second
	}
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
	GPIO_PinState pinState = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
	if (pinState)
	{
		if (lux > 3500) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
	}
}


#endif /* INC_LIGHT_SENSOR_H_ */
