/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "touchsensing.h"
#include "tsc.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TKEY_DET(NB) (MyTKeys[(NB)].p_Data->StateId == TSL_STATEID_DETECT)
#define TKEY_PRX(NB) (MyTKeys[(NB)].p_Data->StateId == TSL_STATEID_PROX)
#define TKEY_REL(NB) (MyTKeys[(NB)].p_Data->StateId == TSL_STATEID_RELEASE)
#define TKEY_CAL(NB) (MyTKeys[(NB)].p_Data->StateId == TSL_STATEID_CALIB)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
tsl_user_status_t tsl_status;
uint16_t i,j;
uint8_t touchDetect[13];					//correspond aux designateurs du PCB, [0] n'est pas utiliser
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TSC_Init();
  MX_TOUCHSENSING_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(tsl_user_Exec_IT() != TSL_USER_STATUS_BUSY){
	      int id;
	      for(id=0; id < TSLPRM_TOTAL_CHANNELS; id++){
	        if(!TKEY_CAL(id)){
	       /*   printf("Sensor%d: Delta %3d Ref %3d Measurement %3d StateId %3d\n"
	          ,id
	          ,MyTKeys[id].p_ChD->Delta
	          ,MyTKeys[id].p_ChD->Ref
	          ,MyTKeys[id].p_ChD->Meas
	          ,MyTKeys[id].p_Data->StateId);*/
	          if(TKEY_DET(3) && (TKEY_DET(6))){ touchDetect[1] = 1;}		//(TKEY_DET(id))// we detect a touch
	          else if(TKEY_REL(3) && (TKEY_REL(6))){touchDetect[1] = 0;}	//(TKEY_REL(id)) // No more detection

	          if(TKEY_DET(3) && (TKEY_DET(7))){ touchDetect[2] = 1;}
	          else if(TKEY_REL(3) && (TKEY_REL(7))){ touchDetect[2] = 0;}

	          if(TKEY_DET(3) && (TKEY_DET(2))){ touchDetect[3] = 1;}
	          else if(TKEY_REL(3) && (TKEY_REL(2))){ touchDetect[3] = 0;}

	          if(TKEY_DET(1) && (TKEY_DET(6))){ touchDetect[4] = 1;}
	          else if(TKEY_REL(1) && (TKEY_REL(6))){ touchDetect[4] = 0;}

	          if(TKEY_DET(1) && (TKEY_DET(7))){ touchDetect[5] = 1;}
	          else if(TKEY_REL(1) && (TKEY_REL(7))){ touchDetect[5] = 0;}

	          if(TKEY_DET(1) && (TKEY_DET(2))){ touchDetect[6] = 1;}
	          else if(TKEY_REL(1) && (TKEY_REL(2))){ touchDetect[6] = 0;}

	          if(TKEY_DET(0) && (TKEY_DET(6))){ touchDetect[7] = 1;}
	          else if(TKEY_REL(0) && (TKEY_REL(6))){ touchDetect[7] = 0;}

	          if(TKEY_DET(0) && (TKEY_DET(7))){ touchDetect[8] = 1;}
	          else if(TKEY_REL(0) && (TKEY_REL(7))){ touchDetect[8] = 0;}

	          if(TKEY_DET(0) && (TKEY_DET(2))){ touchDetect[9] = 1;}
	          else if(TKEY_REL(0) && (TKEY_REL(2))){ touchDetect[9] = 0;}

	          if(TKEY_DET(8) && (TKEY_DET(6))){ touchDetect[10] = 1;}
	          else if(TKEY_REL(8) && (TKEY_REL(6))){ touchDetect[10] = 0;}

	          if(TKEY_DET(8) && (TKEY_DET(7))){ touchDetect[11] = 1;}
	          else if(TKEY_REL(8) && (TKEY_REL(7))){ touchDetect[11] = 0;}

	          if(TKEY_DET(8) && (TKEY_DET(2))){ touchDetect[12] = 1;}
			  else if(TKEY_REL(8) && (TKEY_REL(2))){ touchDetect[12] = 0;}
	        }
	      }
	    }else{
	      HAL_Delay(1); //Can be replace by __WFI()
	    }

	  if (touchDetect[1])
	  {
		  i++;
		  if (i==2000)
			  i=0;
		  HAL_GPIO_WritePin(GPIOB, TLEDG1_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  j++;
		  if (j==2000)
			  j=0;
		  HAL_GPIO_WritePin(GPIOB, TLEDG1_Pin, GPIO_PIN_RESET);
	  }

	  if (touchDetect[2])
		  HAL_GPIO_WritePin(GPIOB, TLEDR1_Pin, GPIO_PIN_SET);
	  else
		  HAL_GPIO_WritePin(GPIOB, TLEDR1_Pin, GPIO_PIN_RESET);
	  if (touchDetect[3])
		  HAL_GPIO_WritePin(GPIOB, TLEDR2_Pin, GPIO_PIN_SET);
	  else
		  HAL_GPIO_WritePin(GPIOB, TLEDR2_Pin, GPIO_PIN_RESET);

	  if (touchDetect[4])
		  HAL_GPIO_WritePin(GPIOB, TLEDG2_Pin, GPIO_PIN_SET);
	  else
		  HAL_GPIO_WritePin(GPIOB, TLEDG2_Pin, GPIO_PIN_RESET);
	  if (touchDetect[5])
	  {
		  HAL_GPIO_WritePin(GPIOB, L1_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOB, L1_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_RESET);
	  }
	  if (touchDetect[6])
	  {
		  HAL_GPIO_WritePin(GPIOB, L1_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOB, L1_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_RESET);
	 	  }
	  if (touchDetect[7])
	  {
		  HAL_GPIO_WritePin(GPIOB, L1_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOB, L1_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_RESET);
	  }
	  if (touchDetect[8])
	  {
		  HAL_GPIO_WritePin(GPIOB, L2_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOB, L2_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_RESET);
	  }
	  if (touchDetect[9])
	  {
		  HAL_GPIO_WritePin(GPIOB, L2_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOB, L2_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_RESET);
	  }
	  if (touchDetect[10])
	  {
		  HAL_GPIO_WritePin(GPIOB, L2_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOB, L2_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_RESET);
	  }
	  if (touchDetect[11])
	  {
		  HAL_GPIO_WritePin(GPIOC, L3_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOC, L3_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOC, C2_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_RESET);
	  }
	  if (touchDetect[12])
	  {
		  HAL_GPIO_WritePin(GPIOC, L3_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_SET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOC, L3_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, C1_LED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, C3_LED_Pin, GPIO_PIN_RESET);
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV4;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_24;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
