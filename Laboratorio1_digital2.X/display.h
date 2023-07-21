/* 
 * File:   display.h
 * Author: HP
 *
 * Created on 19 de julio de 2023, 09:55 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include <xc.h>
#include <stdint.h>

//VAriables para el ADC en HEX
unsigned int VAL1 = 0;
unsigned int VAL2 = 0;

unsigned char displaylist [16] = {
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01101111, //9
    0b01110111, //A
    0b01111100, //B
    0b00111001, //C
    0b01011110, //D
    0b01111001, //E
    0b01110001, //F
};

//Setup de display
void mux(int selector);
void display_hex(int value);

#endif	/* DISPLAY_H */

