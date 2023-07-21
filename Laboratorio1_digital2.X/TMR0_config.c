/*
 *File: TMR0_config.c
 *Author:HP
 */

#include "TMR0_config.h"

//Frecuencia
#define __XTAL_FREQ 4000000

void TMR0_init(void){
    INTCONbits.T0IF = 0; //Bandera del TMR0 apagada
    INTCONbits.T0IE = 1; //Bandera de interrupcion del TMR0
    
    OPTION_REGbits.T0CS = 0; //Establecer TMR0 interno
    OPTION_REGbits.PSA = 0; //Prescaler al TMR0
    
   OPTION_REGbits.PS = 111; //PRescaler de 256
           
}
