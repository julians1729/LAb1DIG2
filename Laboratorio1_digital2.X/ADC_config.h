/* 
 * File:   ADC_config.h
 * Author: HP
 *
 * Created on 19 de julio de 2023, 09:55 PM
 */

#ifndef ADC_CONFIG_H
#define	ADC_CONFIG_H

#include <xc.h>
#include <stdint.h>

//Setup del ADC
void adc_init(int channel);
int adc_read();
void adc_change_channel(int channel);
int adc_get_channel();


#endif	/* ADC_CONFIG_H */

