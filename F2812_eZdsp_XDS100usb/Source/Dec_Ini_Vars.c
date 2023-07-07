//Variables initialization
#include "DSP281x_Device.h"

long dummy1 = 0;

_iq rampa = _IQ(0.0);
_iq rampa_incr = _IQ(0.01);

_iq sinus = _IQ(0.0);

DAC_tipus dacstruct = DAC_def;

Uint32 ticksper5ms=0;
_iq19 revolutionper5ms=0;
_iq10 motor_rpm=0;

Uint32 tickcount=0;
Uint32 turncount=0;
Uint32 turncount_limit=0;

_iq19 alpha= _IQ19(0.0);// de +1.0 (full foward) a -1.0(full backwars), 0.0 (stop)
ON_OFF_enum ONOFF=ON;         //1=PWM ON, 0= PWM off
