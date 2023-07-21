/*
 *File: IOCB1.c
 *Author: HP
 */
#include "IOCB1.h"

//Setup puertoB//
void ioc_init(char pin){
    INTCONbits.RBIE = 1; //Habilitat interrupciones en Puerto B
    OPTION_REGbits.nRBPU = 1;//Habilita pullups
    
    if(pin ==7){
        WPUBbits.WPUB7 = 1; //Habilitar pullups en RB7
        IOCBbits.IOCB7 = 1; //Habilitar´interrupciones
    }
    if(pin ==6){
        WPUBbits.WPUB6 = 1; //Habilitar pullups en RB6
        IOCBbits.IOCB6 = 1; //Habilitar´interrupciones
    }
    if(pin ==5){
        WPUBbits.WPUB5 = 1; //Habilitar pullups en RB5
        IOCBbits.IOCB5 = 1; //Habilitar´interrupciones
    }
    if(pin ==4){
        WPUBbits.WPUB4 = 1; //Habilitar pullups en RB4
        IOCBbits.IOCB4 = 1; //Habilitar´interrupciones
    }
    if(pin ==3){
        WPUBbits.WPUB3 = 1; //Habilitar pullups en RB3
        IOCBbits.IOCB3 = 1; //Habilitar´interrupciones
    }
    if(pin ==2){
        WPUBbits.WPUB2 = 1; //Habilitar pullups en RB2
        IOCBbits.IOCB2 = 1; //Habilitar´interrupciones
    }
    if(pin ==1){
        WPUBbits.WPUB1 = 1; //Habilitar pullups en RB1
        IOCBbits.IOCB1 = 1; //Habilitar´interrupciones
    }
    if(pin ==0){
        WPUBbits.WPUB0 = 1; //Habilitar pullups en RB0
        IOCBbits.IOCB0 = 1; //Habilitar´interrupciones
    }
    INTCONbits.RBIF = 0; //Limpiar bandera de portb
}
