/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tsc.c
  * @brief   This file provides code for the configuration
  *          of the TSC instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "tsc.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

TSC_HandleTypeDef htsc;

/* TSC init function */
void MX_TSC_Init(void)
{

  /* USER CODE BEGIN TSC_Init 0 */

  /* USER CODE END TSC_Init 0 */

  /* USER CODE BEGIN TSC_Init 1 */

  /* USER CODE END TSC_Init 1 */

  /** Configure the TSC peripheral
  */
  htsc.Instance = TSC;
  htsc.Init.CTPulseHighLength = TSC_CTPH_4CYCLES;
  htsc.Init.CTPulseLowLength = TSC_CTPL_4CYCLES;
  htsc.Init.SpreadSpectrum = DISABLE;
  htsc.Init.SpreadSpectrumDeviation = 1;
  htsc.Init.SpreadSpectrumPrescaler = TSC_SS_PRESC_DIV1;
  htsc.Init.PulseGeneratorPrescaler = TSC_PG_PRESC_DIV4;
  htsc.Init.MaxCountValue = TSC_MCV_8191;
  htsc.Init.IODefaultMode = TSC_IODEF_OUT_PP_LOW;
  htsc.Init.SynchroPinPolarity = TSC_SYNC_POLARITY_FALLING;
  htsc.Init.AcquisitionMode = TSC_ACQ_MODE_NORMAL;
  htsc.Init.MaxCountInterrupt = DISABLE;
  htsc.Init.ChannelIOs = TSC_GROUP1_IO2|TSC_GROUP1_IO3|TSC_GROUP2_IO2|TSC_GROUP2_IO4
                    |TSC_GROUP4_IO2|TSC_GROUP4_IO3|TSC_GROUP7_IO2|TSC_GROUP7_IO3
                    |TSC_GROUP7_IO4;
  htsc.Init.ShieldIOs = 0;
  htsc.Init.SamplingIOs = TSC_GROUP1_IO1|TSC_GROUP2_IO1|TSC_GROUP4_IO1|TSC_GROUP7_IO1;
  if (HAL_TSC_Init(&htsc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TSC_Init 2 */

  /* USER CODE END TSC_Init 2 */

}

void HAL_TSC_MspInit(TSC_HandleTypeDef* tscHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(tscHandle->Instance==TSC)
  {
  /* USER CODE BEGIN TSC_MspInit 0 */

  /* USER CODE END TSC_MspInit 0 */
    /* TSC clock enable */
    __HAL_RCC_TSC_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TSC GPIO Configuration
    PC0     ------> TSC_G7_IO1
    PC1     ------> TSC_G7_IO2
    PC2     ------> TSC_G7_IO3
    PC3     ------> TSC_G7_IO4
    PA0     ------> TSC_G1_IO1
    PA1     ------> TSC_G1_IO2
    PA2     ------> TSC_G1_IO3
    PA4     ------> TSC_G2_IO1
    PA5     ------> TSC_G2_IO2
    PA7     ------> TSC_G2_IO4
    PA9     ------> TSC_G4_IO1
    PA10     ------> TSC_G4_IO2
    PA11     ------> TSC_G4_IO3
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = C1_Pin|C2_Pin|L4_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|C3_Pin|L1_Pin
                          |T1_Pin|T2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* TSC interrupt Init */
    HAL_NVIC_SetPriority(TSC_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TSC_IRQn);
  /* USER CODE BEGIN TSC_MspInit 1 */

  /* USER CODE END TSC_MspInit 1 */
  }
}

void HAL_TSC_MspDeInit(TSC_HandleTypeDef* tscHandle)
{

  if(tscHandle->Instance==TSC)
  {
  /* USER CODE BEGIN TSC_MspDeInit 0 */

  /* USER CODE END TSC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TSC_CLK_DISABLE();

    /**TSC GPIO Configuration
    PC0     ------> TSC_G7_IO1
    PC1     ------> TSC_G7_IO2
    PC2     ------> TSC_G7_IO3
    PC3     ------> TSC_G7_IO4
    PA0     ------> TSC_G1_IO1
    PA1     ------> TSC_G1_IO2
    PA2     ------> TSC_G1_IO3
    PA4     ------> TSC_G2_IO1
    PA5     ------> TSC_G2_IO2
    PA7     ------> TSC_G2_IO4
    PA9     ------> TSC_G4_IO1
    PA10     ------> TSC_G4_IO2
    PA11     ------> TSC_G4_IO3
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_0|C1_Pin|C2_Pin|L4_Pin);

    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4
                          |C3_Pin|L1_Pin|GPIO_PIN_9|T1_Pin
                          |T2_Pin);

    /* TSC interrupt Deinit */
    HAL_NVIC_DisableIRQ(TSC_IRQn);
  /* USER CODE BEGIN TSC_MspDeInit 1 */

  /* USER CODE END TSC_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
