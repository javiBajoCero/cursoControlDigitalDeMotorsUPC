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


//enciende solo un LED
void turnSingleLEDon(int16 lednumber){
    switch (lednumber) {
        case 0:
            GpioDataRegs.GPESET.bit.GPIOE0=0x1;
            break;
        case 1:
            GpioDataRegs.GPESET.bit.GPIOE1=0x1;
            break;
        case 2:
            GpioDataRegs.GPBSET.bit.GPIOB2=0x1;
            break;
        case 3:
            GpioDataRegs.GPBSET.bit.GPIOB3=0x1;
            break;

        default:
            break;
    }
}

//enciende solo un LED
void turnSingleLEDoff(int16 lednumber){
    switch (lednumber) {
        case 0:
            GpioDataRegs.GPECLEAR.bit.GPIOE0=0x1;
            break;
        case 1:
            GpioDataRegs.GPECLEAR.bit.GPIOE1=0x1;
            break;
        case 2:
            GpioDataRegs.GPBCLEAR.bit.GPIOB2=0x1;
            break;
        case 3:
            GpioDataRegs.GPBCLEAR.bit.GPIOB3=0x1;
            break;

        default:
            break;
    }
}

// returns 1 if the bit number (bitnumber) from the variable (variabletocheck) is set, 0 otherwise.
int16 checkbit(int16 variabletocheck,int16 bitnumber){
    if(((1<<bitnumber)&variabletocheck)==(1<<bitnumber)){
        return 1;
    }else{
        return 0;
    }
}

//necesita un puntero a una variable de 8 bits, si detecta que el boton GPIOB4 se pulsó, incrementa +1.
void isGPB4Buttonpresed_incrementVariable(int16 * variable){
    if(GpioDataRegs.GPBDAT.bit.GPIOB4==0x00){//0x00 significa botón presionado (botón con pullup activo en low)
        *variable+=1;
    }

    if(*variable>15){//rollover de 0 a 15
        *variable=0;
    }
}
