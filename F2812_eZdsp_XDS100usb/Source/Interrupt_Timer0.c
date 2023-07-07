#include "DSP281x_Device.h"

#define fivems_inside_1_minute 12000  //60000ms/5ms
#define QEPricksregister EvaRegs.T2CNT
//tim0 INTERRUPT ROUTINE
interrupt void interrupt_timer0(void){
    TOGGLE_LED8;
//
//    rampa += rampa_incr;
//
//    if (rampa > _IQ(1.0))
//        rampa = _IQ(0.0);
//
//    sinus = _IQsinPU(rampa)+_IQ(1.0);
//
//    DAC_envia(&dacstruct);

    //QEP
    ticksper5ms=QEPricksregister;                                               //5ms passed, how many ticks
    revolutionper5ms=ticksper5ms*_IQ19(0.0005);                                 //the encoder has 2000ticks/revolution.//TODO i suspect is not 2000, is 500
    motor_rpm=fivems_inside_1_minute*_IQtoIQ10(_IQ19toIQ(revolutionper5ms));                          //translating from 5ms to one minute
    QEPricksregister=0;                                                         //reset counter for next time

    PieCtrlRegs.PIEACK.all= PIEACK_GROUP1;
}
