/* 
 * File:   Mainlab1.c
 * Author: HP
 *
 * Created on 19 de julio de 2023, 09:47 PM
 */


//Configuraciones
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// Librerias
#include <xc.h>
#include <stdint.h>
#include "IOCB1.h"
#include "ADC_config.h"
#include "TMR0_config.h"
#include "display.h"

//Frecuencia
#define _XTAL_FREQ 4000000

//Variables
int bandera = 0;//Antirrebote
int adc_var = 0;//Valor adc
int select = 0; //Selector

//Prototipos
void setup(void);
void counter(void);

//Loop principal
void main(void){
    setup();
    adc_init(0);
    TMR0_init();
    TMR0 = 252;
    while(1){
        if(ADCON0bits.GO == 0){ //Si el ADC inactivo/activarlo
            ADCON0bits.GO = 1;//Activar
            display_hex(adc_var); //Enviar valor a display
        }
        //PORTD = adc_read();)
    }
}

//Interrupciones
void __interrupt() isr(void){
    if(INTCONbits.T0IF == 1){
        INTCONbits.T0IE = 0;
        TMR0 = 252;
        if(select == 0){
            mux(select);
            select = 1;
        }
        if(select ==1){
            mux(select);
            select = 0;
        }
    }
    if(INTCONbits.RBIF == 1){ //Revisar bandera de interr. portb
        counter();
        INTCONbits.RBIF = 0; //Limpiar bandera
    }
    if(PIR1bits.ADIF == 1){//Revisar bandera puerto B
        adc_var = adc_read();
        PIR1bits.ADIF = 0; //Limpiar bandera  
    }
}

//Setup
void setup(void){
    //ANSEL = 0;
    //ANSELH = 0;
    
    TRISBbits.TRISB6 = 1; //RB6 como entrada
    TRISBbits.TRISB7 = 1; //RB7 como entrada
    
    TRISBbits.TRISB0 = 0; //SAlida
    TRISBbits.TRISB1 = 0;
    
    TRISC = 0;
    TRISD = 0;
    TRISE= 0;
    
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    
    //Habilitar pull ups
    //OPTION_REGbits.nRBPU = 0;
    //WPUBbits.WPUB6 = 1;
    //WPUBbits.WPUB7 = 1;
    
    //BAnderas de interrupcion
    INTCONbits.GIE = 1; //Globales
    INTCONbits.PEIE = 1; //Perifericas
    //INTCONbits.RBIE = 1; // portB
    //IOCBbits.IOCB6 = 1; //RB6
    //IOCBbits.IOCB7 = 1; //RB7
    
    ioc_init(7);
    ioc_init(6);
    
    //INTCONbits.RBIF = 0; Limpiar bandera PORTB
    
    //Oscilador
    OSCCONbits.IRCF = 0b110; //OScilador de 4MHZ
    OSCCONbits.SCS = 1; //OScilador interno
    
    //ADC
    //PIE1bits.ADIE = 1; // Habilitar interrupcion del conversor ADC
    //PIR1bits.ADIF = 0; // Lpimpiar bandera de ADC
    
    //ADCON0bits.ADCS1 = 0; // FOSC/2
    //ADCON0bits.ADCS0 = 0; //
    
    //ADCON1bits.VCFG1 = 0; //Referencia VSS
    //ADCON1bits.VCFG0 = 0; // Referencia VDD
    
    //ADCON1bits.ADFM = 0; // Justificado izquierda
}    
    //Funciones
void counter(void){
    if(PORTBbits.RB6 == 0){//Boton presionado
        bandera = 1; //ACtivar bandera
    }
    if(PORTBbits.RB6 == 1 && bandera == 1){ 
        PORTD--;
        bandera = 0;
    }
    if(PORTBbits.RB7 == 0){//Boton presionado
        bandera = 2; //ACtivar bandera
    }
    if(PORTBbits.RB7 == 1 && bandera == 2){ 
        PORTD--;
        bandera = 0;
    }
}    
