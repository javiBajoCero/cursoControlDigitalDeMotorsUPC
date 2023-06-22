//Variables initialization
#include "DSP281x_Device.h"

int16 dummy1 = 0;

//simple delay por software
void delay(int32 times){
    int32 i,j;
    for ( i = 0;  i < 0xFFFF; ++ i) {
        for ( j = 0;  j < times; ++ j) {
        };
    };
}

//apaga todos los LEDS
void allGPIOSloff(void){
    GpioDataRegs.GPBCLEAR.bit.GPIOB2=0x1;
    GpioDataRegs.GPBCLEAR.bit.GPIOB3=0x1;
    GpioDataRegs.GPECLEAR.bit.GPIOE0=0x1;
    GpioDataRegs.GPECLEAR.bit.GPIOE1=0x1;
    GpioDataRegs.GPFCLEAR.bit.GPIOF14=0x1;
}


//enciende todos los LEDS
void allGPIOSon(void){
    GpioDataRegs.GPBSET.bit.GPIOB2=0x1;
    GpioDataRegs.GPBSET.bit.GPIOB3=0x1;
    GpioDataRegs.GPESET.bit.GPIOE0=0x1;
    GpioDataRegs.GPESET.bit.GPIOE1=0x1;
    GpioDataRegs.GPFSET.bit.GPIOF14=0x1;
}


//enciende todos los LEDS
void turnSingleLEDon(int16 lednumber){
switch (lednumber) {
    case 5:
        GpioDataRegs.GPESET.bit.GPIOE0=0x1;
        break;
    case 6:
        GpioDataRegs.GPESET.bit.GPIOE1=0x1;
        break;
    case 7:
        GpioDataRegs.GPBSET.bit.GPIOB2=0x1;
        break;
    case 8:
        GpioDataRegs.GPBSET.bit.GPIOB3=0x1;
        break;

    default:
        break;
}
}
