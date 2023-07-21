/*
 * interruptsADC.c
 *
 *  Created on: Jul 21, 2023
 *      Author: javi
 */

#include "DSP281x_Device.h"

#define  buffersize (Uint16) 10
#define ADCmaxreading _IQ19(2047.0)
#define ADCminreading _IQ19(500.0)
#define ADCspanreading ADCmaxreading-ADCminreading

Uint16 P1valueADCbuffer[buffersize]={0};    //circular buffer for moving average array
Uint16 P1bufferindex=0;             //index for P1valueADCbuffer circular buffer
Uint32 averagedP1value=0;
_iq19 alphaP1=_IQ19(0.0);


interrupt void interrupt_ADC(void){
    TOGGLE_LED7;

    P1valueADCbuffer[P1bufferindex]=(Uint16)(AdcRegs.ADCRESULT1>>4)>>1;//i dont know why i dont know what are they suggesting with this in the slides
    if(P1bufferindex>buffersize){
        P1bufferindex=0;
    }else{
        P1bufferindex++;
    }

    Uint16 i=0;
    averagedP1value=0;
    for (i = 0; i < buffersize; ++i) {
        averagedP1value+=P1valueADCbuffer[i];
    }
    averagedP1value/=buffersize;

    alphaP1=_IQ19mpyI32(_IQ19(1.0),averagedP1value);
    alphaP1-=ADCminreading;
    alphaP1=_IQ19div(alphaP1,ADCspanreading);
    if(alphaP1>_IQ19(1.0)){
        alphaP1=_IQ19(1.0);
    }else if(alphaP1<_IQ19(0.0)){
        alphaP1=_IQ19(0.0);
    }
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
