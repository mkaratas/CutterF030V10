#include "main.h"
#include "stm32f0xx_hal.h"
#include "gpio.h"

void SystemClock_Config ( void );

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if ( GPIO_Pin == Cutter_Pin ) {
		HAL_NVIC_DisableIRQ( Cutter_EXTI_IRQn );
		HAL_GPIO_WritePin( LedGreen_GPIO_Port , LedGreen_Pin , GPIO_PIN_RESET );
		HAL_GPIO_WritePin( LedRed_GPIO_Port   , LedRed_Pin   , GPIO_PIN_SET   );
	}
}

int main	( void ) {

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  while ( 1 )   {

  }
}

/** 	System Clock Configuration		*/
void SystemClock_Config	( void ) {

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  /**	Initializes the CPU, AHB and APB busses clocks	   */
  RCC_OscInitStruct.OscillatorType 		= RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState 			= RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState 		= RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource 		= RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL 			= RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV 			= RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    _Error_Handler(__FILE__, __LINE__);

  /**	Initializes the CPU, AHB and APB busses clocks 	 */
  RCC_ClkInitStruct.ClockType 			= RCC_CLOCKTYPE_HCLK
		  	  	  	  	  	  	  	  	 |RCC_CLOCKTYPE_SYSCLK
										 |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource 		= RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider 		= RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider 		= RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
    _Error_Handler(__FILE__, __LINE__);


  /**	Configure the Systick interrupt time     */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  /**	Configure the Systick 	    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif
