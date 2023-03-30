#include "stm32f4xx_hal.h" // Keil::Device:STM32Cube HAL:Common
#include "stm32f4xx_hal_adc.h" // Keil::Device:STM32Cube HAL:Common
#include "stm32f4xx_hal_adc_ex.h" // Keil::Device:STM32Cube HAL:Common

//Structure de données permettant de caractériser le périphérique pour le MANIPULER (Handle)
ADC_HandleTypeDef myADC2Handle;

//Fonction d'initalisation de l'ADC2, sur PA0
void init_PIN_PA0()
{
	GPIO_InitTypeDef ADCpin; 										// Création de structure de config PIN_ANALOG
	ADC_ChannelConfTypeDef Channel_AN0; 							// Création de structure de config ADC

	//Intialisation PA0
	__HAL_RCC_GPIOA_CLK_ENABLE(); 									// activation Horloge GPIOA
	ADCpin.Pin = GPIO_PIN_0; 										// Selection pin PA0
	ADCpin.Mode = GPIO_MODE_ANALOG; 								// Selection mode analogique
	ADCpin.Pull = GPIO_NOPULL; 										// Désactivation des résistance de pull-up et pull-down

	//Paramétrage ADC2
	__HAL_RCC_ADC2_CLK_ENABLE(); 									// activation Horloge ADC2
	myADC2Handle.Instance = ADC2; 									// Selection de ADC2
	myADC2Handle.Init.Resolution = ADC_RESOLUTION_8B; 				// Selection résolution 12 bit
	myADC2Handle.Init.EOCSelection = ADC_EOC_SINGLE_CONV; 			// Selection du mode single pour l'EOC(end of conversion)
	myADC2Handle.Init.DataAlign = ADC_DATAALIGN_RIGHT; 				// Alignement des data à gauche des octets
	myADC2Handle.Init.ClockPrescaler =ADC_CLOCK_SYNC_PCLK_DIV8; 	// Syncronisation des horloges

	//Paramètrage CHANEL0
	Channel_AN0.Channel = ADC_CHANNEL_0; 							// Selection analog channel 0
	Channel_AN0.Rank = 1; 											// Selection du Rang : 1
	Channel_AN0.SamplingTime = ADC_SAMPLETIME_15CYCLES; 			// Selection du temps d'échentillonage à 15

	HAL_GPIO_Init(GPIOA, &ADCpin); 									// Initialisation PA0 avec les paramètre ci-dessus
	HAL_ADC_Init(&myADC2Handle); 									// Initialisation ADC2 avec les paramètre ci-dessus
	HAL_ADC_ConfigChannel(&myADC2Handle, &Channel_AN0); 			// Initialisation Chanel_0 avec les paramètre ci-dessus.
}

