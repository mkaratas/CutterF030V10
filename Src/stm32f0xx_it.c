#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
#include "stm32f0xx_it.h"

/* External variables --------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M0 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles Non maskable interrupt.
*/
void NMI_Handler		( void ) {

}
/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler	( void ) {

  while (1)
  {
  }
}
/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler		( void ) {

}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler		( void ) {

}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler	( void ) {
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles EXTI line 0 and 1 interrupts.
*/
void EXTI0_1_IRQHandler	( void ) {
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
}
