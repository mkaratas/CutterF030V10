#include "gpio.h"

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init	( void ) {

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin( LedGreen_GPIO_Port , LedGreen_Pin , GPIO_PIN_RESET );
  HAL_GPIO_WritePin( LedRed_GPIO_Port	, LedRed_Pin   , GPIO_PIN_SET   );

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin 	= LedRed_Pin|LedGreen_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin 	= Cutter_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  HAL_GPIO_Init( Cutter_GPIO_Port , &GPIO_InitStruct );



  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);

}
