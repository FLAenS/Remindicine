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
	if (hour == 1)
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
	GPIO_PinState pinState = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
	if (pinState)
	{
		if (lux > 3500) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
	}


}


#endif /* INC_LIGHT_SENSOR_H_ */
