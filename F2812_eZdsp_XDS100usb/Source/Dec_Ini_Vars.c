//Variables initialization
#include "DSP281x_Device.h"

long dummy1 = 0;

_iq rampa = _IQ(0.0);
_iq rampa_incr = _IQ(0.01);

_iq sinus = _IQ(0.0);

DAC_tipus dacstruct = DAC_def;

Uint32 ticksper5ms=0;
_iq19 revolutionper5ms=0;
_iq19 motor_rpm=0;
