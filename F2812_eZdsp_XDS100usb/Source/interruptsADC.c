/*
 * interruptsADC.c
 *
 *  Created on: Jul 21, 2023
 *      Author: javi
 */

#include "DSP281x_Device.h"



interrupt void interrupt_ADC(void){
    TOGGLE_LED7;
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
