#include "7segdisp.h"

uint8_t data1[] = "Dva parking mjesta su slobodna! \r\n";
uint8_t data2[] = "Jedno parking mjesto je slobodno \r\n";
uint8_t data3[] = "Parking je zauzet \r\n";

void seg() {
	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0
			&& HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, 1);

		HAL_UART_Transmit(&huart2, data3, sizeof(data3), 1000);

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, 0);

	}

	else if (((HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 1)
			&& (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0))
			|| ((HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0)
					&& (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 1))) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, 1);

		HAL_UART_Transmit(&huart2, data2, sizeof(data2), 1000);

		if ((HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 1)
				&& (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0)) {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, 0);

		} else if ((HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0)
				&& (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 1)) {

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, 1);

		}

	}

	else if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 1
			&& HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 1) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, 1);

		HAL_UART_Transmit(&huart2, data1, sizeof(data1), 1000);

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, 1);
	}
}
