#ifndef __MAIN_H
#define __MAIN_H

#define Cutter_Pin 			GPIO_PIN_1
#define Cutter_GPIO_Port	GPIOA
#define Cutter_EXTI_IRQn 	EXTI0_1_IRQn
#define LedRed_Pin 			GPIO_PIN_9
#define LedRed_GPIO_Port 	GPIOA
#define LedGreen_Pin 		GPIO_PIN_10
#define LedGreen_GPIO_Port 	GPIOA

void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

#endif /* __MAIN_H */
