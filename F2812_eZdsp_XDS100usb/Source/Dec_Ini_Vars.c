//Variables initialization
#include "DSP281x_Device.h"



//Leer GPIOS
#define S1button_activelow (GpioDataRegs.GPBDAT.bit.GPIOB4)
#define S3_1redswitch (GpioDataRegs.GPBDAT.bit.GPIOB5)
#define S3_2redswitch (GpioDataRegs.GPBDAT.bit.GPIOB6)
#define S3_3redswitch (GpioDataRegs.GPBDAT.bit.GPIOB7)

//encender LED
#define SET_onboardLED (GpioDataRegs.GPFSET.bit.GPIOF14=0x1)
#define SET_LED5 (GpioDataRegs.GPESET.bit.GPIOE0=0x1)
#define SET_LED6 (GpioDataRegs.GPESET.bit.GPIOE1=0x1)
#define SET_LED7 (GpioDataRegs.GPBSET.bit.GPIOB2=0x1)
#define SET_LED8 (GpioDataRegs.GPBSET.bit.GPIOB3=0x1)

//apagar LED
#define RESET_onboardLED (GpioDataRegs.GPFCLEAR.bit.GPIOF14=0x1)
#define RESET_LED5 (GpioDataRegs.GPECLEAR.bit.GPIOE0=0x1)
#define RESET_LED6 (GpioDataRegs.GPECLEAR.bit.GPIOE1=0x1)
#define RESET_LED7 (GpioDataRegs.GPBCLEAR.bit.GPIOB2=0x1)
#define RESET_LED8 (GpioDataRegs.GPBCLEAR.bit.GPIOB3=0x1)


int16 dummy1 = 0;
int16 secretpassword=0;

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
    RESET_onboardLED;
    RESET_LED5;
    RESET_LED6;
    RESET_LED7;
    RESET_LED8;
}


//enciende todos los LEDS
void allGPIOSon(void){
    SET_onboardLED;
    SET_LED5;
    SET_LED6;
    SET_LED7;
    SET_LED8;
}


//enciende solo un LED
void turnSingleLEDon(int16 lednumber){
    switch (lednumber) {
        case 0:
            SET_LED5;
            break;
        case 1:
            SET_LED6;
            break;
        case 2:
            SET_LED7;
            break;
        case 3:
            SET_LED8;
            break;
        default:
            allGPIOSloff();//nunca deberia llegar aqui.
            break;
    }
}

//enciende solo un LED
void turnSingleLEDoff(int16 lednumber){
    switch (lednumber) {
        case 0:
            RESET_LED5;
            break;
        case 1:
            RESET_LED6;
            break;
        case 2:
            RESET_LED7;
            break;
        case 3:
            RESET_LED8;
            break;

        default:
            allGPIOSloff();//nunca deberia llegar aqui.
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
    if(S1button_activelow==0x00){//0x00 significa botón presionado (botón con pullup activo en low)
        *variable+=1;
    }

    if(*variable>15){//rollover de 0 a 15
        *variable=0;
    }
}

//si el boton S1 es activado, se guarda el estado de S3 en "secretpassword"
void isGPB4Buttonpresed_setnewpassword(){
    if(S1button_activelow==0x00){//0x00 significa botón presionado (botón con pullup activo en low)
        secretpassword=
                +(0<<GpioDataRegs.GPBDAT.bit.GPIOB5)
                +(1<<GpioDataRegs.GPBDAT.bit.GPIOB6)
                +(2<<GpioDataRegs.GPBDAT.bit.GPIOB7);
    }

}

//si el estado de S3 se corresponde con "secretpassword" , enciende un LED
void issecretpassowrdCorrect(){


}


//Change LED state with a period of 2 seconds with a software counter (that increases in
//the idle loop)
void ejercicio1_ledblink(void){
    delay(0x40);
    allGPIOSon();
    delay(0x40);
    allGPIOSloff();
}


//Generate a LED sequence with the 4 available LEDS in the AROM board (GPIOB3,
//GPIOB2, GPIOE0, GPIOE1) from right to left and left to right (“Knight Rider”).

void ejercicio2_cochefantastico(void){

    Uint16 i=0;
    for(;;){

        for (i = 0; i < 3; ++i) {
            allGPIOSloff();
            turnSingleLEDon(i);
            delay(0xF);
        }

        for (i = 3; i > 0; --i) {
            allGPIOSloff();
            turnSingleLEDon(i);
            delay(0xF);
        }

    }


}

//Set the pushbutton S1 (GPIOB4) as an input and show the number of pulses (up to
//15, and reset the value to 0) using binary code represented by the digital outputs
int16 buttoncounter=0;

void ejercicio3_contadorbinarioboton(){
    int16 i=0;
    isGPB4Buttonpresed_incrementVariable(&buttoncounter);

    for (i = 0; i < 4; ++i) {
        if(checkbit(buttoncounter, i)){
            turnSingleLEDon(i);
        }else{
            turnSingleLEDoff(i);
        }
    }
    delay(0xF);
}







