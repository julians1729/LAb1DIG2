/*
 *File: ADC_config.c
 *Author: HP
 */
#include "ADC_config.h"
#define _XTAL_FREQ 4000000
//Setup del ADC

void adc_init(int channel){
    
    PIE1bits.ADIE = 1; // Habilitar interrupcion del conversor ADC
    PIR1bits.ADIF = 0; // Lpimpiar bandera de ADC
    
    ADCON0bits.ADCS1 = 0; // FOSC/2
    ADCON0bits.ADCS0 = 0; //
    
    ADCON1bits.VCFG1 = 0; //Referencia VSS
    ADCON1bits.VCFG0 = 0; // Referencia VDD
    
    ADCON1bits.ADFM = 0; // Justificado izquierda
    
    adc_change_channel(channel);
    
    ADCON0bits.ADON = 1; // Habilitamos el ADC
    __delay_us(100); //delay de 100us
}

int adc_read(){
    return ADRESH;
}

void adc_change_channel(int channel){
    if(channel == 0){
        ADCON0bits.CHS = 0b0000; //Canal AN0
        ANSEL =ANSEL | 0b00000001;
    }
    if(channel == 1){
        ADCON0bits.CHS = 0b0001; //Canal AN1
        ANSEL =ANSEL | 0b00000010;
    }
    if(channel == 2){
        ADCON0bits.CHS = 0b0010; //Canal AN2
        ANSEL =ANSEL | 0b00000100;
    }
    if(channel == 3){
        ADCON0bits.CHS = 0b0011; //Canal AN3
        ANSEL =ANSEL | 0b00001000;
    }
    if(channel == 4){
        ADCON0bits.CHS = 0b0100; //Canal AN4
        ANSEL =ANSEL | 0b00010000;
    }
    if(channel == 5){
        ADCON0bits.CHS = 0b0101; //Canal AN5
        ANSEL =ANSEL | 0b00100000;
    }
    if(channel == 6){
        ADCON0bits.CHS = 0b0110; //Canal AN6
        ANSEL =ANSEL | 0b01000000;
    }
    if(channel == 7){
        ADCON0bits.CHS = 0b0111; //Canal AN7
        ANSEL =ANSEL | 0b10000000;
    }
    if(channel == 8){
        ADCON0bits.CHS = 0b1000; //Canal AN8
        ANSEL =ANSELH | 0b00000001;
    }
    if(channel == 9){
        ADCON0bits.CHS = 0b1001; //Canal AN9
        ANSEL =ANSELH | 0b00000010;
    }
    if(channel == 10){
        ADCON0bits.CHS = 0b1010; //Canal AN10
        ANSEL =ANSELH | 0b00000100;
    }
    if(channel == 11){
        ADCON0bits.CHS = 0b1011; //Canal AN11
        ANSEL =ANSELH | 0b00001000;
    }
    if(channel == 12){
        ADCON0bits.CHS = 0b1100; //Canal AN12
        ANSEL =ANSELH | 0b00010000;
    }
    if(channel == 13){
        ADCON0bits.CHS = 0b1101; //Canal AN13
        ANSEL =ANSEL | 0b00100000;
    }
}

int adc_get_channel(){
    if(ADCON0bits.CHS == 0b0000){ //Canal AN0
        return 0;
    }
    if(ADCON0bits.CHS == 0b0001){ //Canal AN1
        return 1;
    }
    if(ADCON0bits.CHS == 0b0010){ //Canal AN2
        return 2;
    }
    if(ADCON0bits.CHS == 0b0011){ //Canal AN3
        return 3;
    }
    if(ADCON0bits.CHS == 0b0100){ //Canal AN4
        return 4;
    }
    if(ADCON0bits.CHS == 0b0101){ //Canal AN5
        return 5;
    }
    if(ADCON0bits.CHS == 0b0110){ //Canal AN6
        return 6;
    }
    if(ADCON0bits.CHS == 0b0111){ //Canal AN7
        return 7;
    }
    if(ADCON0bits.CHS == 0b1000){ //Canal AN8
        return 8;
    }
    if(ADCON0bits.CHS == 0b1001){ //Canal AN9
        return 9;
    }
    if(ADCON0bits.CHS == 0b1010){ //Canal AN10
        return 10;
    }
    if(ADCON0bits.CHS == 0b1011){ //Canal AN11
        return 11;
    }
    if(ADCON0bits.CHS == 0b1100){ //Canal AN12
        return 12;
    }
    if(ADCON0bits.CHS == 0b1101){ //Canal AN13
        return 13;
    }
}
