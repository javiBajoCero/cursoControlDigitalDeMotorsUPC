#include "DSP281x_Device.h"

//tim0 INTERRUPT ROUTINE
interrupt void interrupt_timer0(void){
    TOGGLE_LED8;

    rampa += rampa_incr;

    if (rampa > _IQ(1.0))
        rampa = _IQ(0.0);

    sinus = _IQsinPU(rampa)+_IQ(1.0);

    DAC_envia(&dacstruct);

    PieCtrlRegs.PIEACK.all= PIEACK_GROUP1;
}
