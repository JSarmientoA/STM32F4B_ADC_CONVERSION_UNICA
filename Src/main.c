#include <stdint.h>
#include <stdio.h> // Para poder usar printf()
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
/*En este programa la convesrion se realiza de forma regular y no es continua
 * por tal razon la conversion (funcion inicio_conversion()) se realiza dentro del bicle infinito
 * while*/

int32_t valor_ADC;
float voltaje_PA1;
int main(void){


	uart2_rx_tx_init();
	pa1_adc_int();


	while(1){
		inicio_conversion();
		valor_ADC = leer_conversion();
		voltaje_PA1 = 0.000805664*valor_ADC;
		printf("Valor del ADC : %d\n\r",(int)valor_ADC);
	}
}
