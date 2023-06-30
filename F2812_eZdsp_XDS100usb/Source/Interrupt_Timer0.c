#include "DSP281x_Device.h"

//tim0 INTERRUPT ROUTINE
interrupt void interrupt_timer0(void){
    TOGGLE_LED8;
    DAC_envia(&dacstruct);
    dacstruct.A.Data++;
    PieCtrlRegs.PIEACK.all= PIEACK_GROUP1;
}
