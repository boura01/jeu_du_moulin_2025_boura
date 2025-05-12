/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define C2_LED_Pin GPIO_PIN_13
#define C2_LED_GPIO_Port GPIOC
#define C1_Pin GPIO_PIN_1
#define C1_GPIO_Port GPIOC
#define C2_Pin GPIO_PIN_2
#define C2_GPIO_Port GPIOC
#define L4_Pin GPIO_PIN_3
#define L4_GPIO_Port GPIOC
#define C3_LED_Pin GPIO_PIN_3
#define C3_LED_GPIO_Port GPIOA
#define C3_Pin GPIO_PIN_5
#define C3_GPIO_Port GPIOA
#define L1_Pin GPIO_PIN_7
#define L1_GPIO_Port GPIOA
#define L3_LED_Pin GPIO_PIN_4
#define L3_LED_GPIO_Port GPIOC
#define L2_LED_Pin GPIO_PIN_1
#define L2_LED_GPIO_Port GPIOB
#define L1_LED_Pin GPIO_PIN_2
#define L1_LED_GPIO_Port GPIOB
#define TLEDG1_Pin GPIO_PIN_12
#define TLEDG1_GPIO_Port GPIOB
#define TLEDR1_Pin GPIO_PIN_13
#define TLEDR1_GPIO_Port GPIOB
#define TLEDG2_Pin GPIO_PIN_14
#define TLEDG2_GPIO_Port GPIOB
#define TLEDR2_Pin GPIO_PIN_15
#define TLEDR2_GPIO_Port GPIOB
#define T1_Pin GPIO_PIN_10
#define T1_GPIO_Port GPIOA
#define T2_Pin GPIO_PIN_11
#define T2_GPIO_Port GPIOA
#define C1_LED_Pin GPIO_PIN_8
#define C1_LED_GPIO_Port GPIOB
#define L4_LED_Pin GPIO_PIN_9
#define L4_LED_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
