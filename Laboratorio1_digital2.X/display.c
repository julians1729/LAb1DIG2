/*
 * File: display.c
 * Author:HP
 */

#include <xc.h>
#include <stdint.h>
#include "display.h"

//Frecuencia
#define __XTAL_FREQ 4000000

void mux(int selector){
    if(selector == 0){//Si el selector esta en el 1er disp
        PORTC = displaylist[VAL1]; //Enviar valor de display a PORTC
        PORTEbits.RE0 = 1;//Alternar pines
        PORTEbits.RE1 = 0;                  
    }
    if(selector == 1){//Si el selector esta en el 2do disp
        PORTC = displaylist[VAL2]; //Enviar valor de display a PORTC
        PORTEbits.RE0 = 0;//Alternar pines
        PORTEbits.RE1 = 1;                  
    }
}

void display_hex(int value){
    if(value>= PORTD){//Si el valor del ADRESH es mayor que contador
        PORTEbits.RE2 = 1; //Encender alarma
    }
    else {
        PORTEbits.RE2 = 0; //Si es menor apagar alarma
    }
    VAL1 = (value%16);
    VAL2 = (value/16);
}