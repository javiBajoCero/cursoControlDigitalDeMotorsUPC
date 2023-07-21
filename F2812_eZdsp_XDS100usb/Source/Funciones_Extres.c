#include "DSP281x_Device.h"
//simple delay por software
int16 secretpassword=0;

void delay(int32 times){
    DELAY_US(times*1000);
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

//apaga solo un LED
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

//necesita un puntero a una variable de 8 bits, si detecta que el boton GPIOB4 se pulsÃ³, incrementa +1.
void isGPB4Buttonpresed_incrementVariable(int16 * variable){
    if(S1button_activelow==0x00){//0x00 significa botÃ³n presionado (botÃ³n con pullup activo en low)
        *variable+=1;
    }

    if(*variable>15){//rollover de 0 a 15
        *variable=0;
    }
}

//si el boton S1 es activado, se guarda el estado de S3 en "secretpassword"
void isGPB4Buttonpresed_setnewpassword(){
    if(S1button_activelow==0x00){//0x00 significa botÃ³n presionado (botÃ³n con pullup activo en low)
        secretpassword=
                +((!S3_1redswitch)<<2)
                +((!S3_2redswitch)<<1)
                +((!S3_3redswitch)<<0);
    }

}

//si el estado de S3 se corresponde con "secretpassword" , enciende un LED
void issecretpassowrdCorrect(){
    int16 switchstate;
     switchstate=
                 +((!S3_1redswitch)<<2)
                 +((!S3_2redswitch)<<1)
                 +((!S3_3redswitch)<<0);

    if(switchstate==secretpassword){
        turnSingleLEDon(0);
    }else{
        turnSingleLEDoff(0);
    }


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
//GPIOB2, GPIOE0, GPIOE1) from right to left and left to right (â€œKnight Riderâ€�).

void ejercicio2_cochefantastico(void){

    Uint16 i=0;
    for(;;){

        for (i = 0; i < 3; ++i) {
            allGPIOSloff();
            turnSingleLEDon(i);
            delay(150);
        }

        for (i = 3; i > 0; --i) {
            allGPIOSloff();
            turnSingleLEDon(i);
            delay(150);
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

//Create a unique setting (password) of the switch inputs (SW3_1, SW3_2, SW3_3) to
//swith on one LED. Allow to change the password when the pushbutton (S1) is down,
//save the current SW3 setting as new code.
void ejercicio4_secretpassword(void){
    isGPB4Buttonpresed_setnewpassword();
    delay(0x2);
    issecretpassowrdCorrect();
    delay(0x2);
}




//ENABLES INTERRUPTS AND INITIALICES TIM0 with interruption period as an argument in microseonds
void enableinterruptTIM0(float period){
    //Enable the peripheral interrupcion del tim0 es INT1.7
    ConfigCpuTimer(&CpuTimer0, TIMER0clockfreq, period);

    //Address the interrupt vector to the desired function
    EALLOW;
    PieVectTable.TINT0 = &interrupt_timer0;
    EDIS;
    //Enable interrupt Y of group X.
    PieCtrlRegs.PIEIER1.bit.INTx7=1;//1=enable 0=disable
    //Enable group X of interrupts:
    IER |= M_INT1;
    // Enable global interrupts:
    EINT;
    //Allow next interrupt service (write before leaving the interruption routine)
    PieCtrlRegs.PIEACK.bit.ACK1=1;
    //arranca el timer
    StartCpuTimer0();
}


//initialices the SPI-DAC and the pointers from the DAC data structs to our ramp and sine variables.
void setupForDACexercice(void){
    DAC_inici();

    dacstruct.A.Data= (unsigned long *)&alphaP1;
    dacstruct.A.Guany=1<<8;//por algun motivo que no entendí bien, al usar _iq19 con este dac se descartan los 8 primeros bits.
    dacstruct.A.Offset=0;

    dacstruct.B.Data= (unsigned long *)&sinus;
    dacstruct.B.Guany=1<<7;//quito un bit (1>>) ganancia *0.5
    dacstruct.B.Offset=0.5;//sinus tiene valores entre (-1 y 1)/2 = (-0.5 y 0.5), el DAC no representa valores negativos;

}

//Generating 4 PWM signals at 10Khz following https://youtu.be/78cyedzNock?t=184
void setupForPWM(void){
    InitEv();//initialises the event manager 1
}

//translates _iq19 to uint16 PWM register values.
//throttle could be 0.0 which would be motor stopped, 1.0 would be motor full throttle foward, -1.0 full throttle backwards
void runmotorpwm_PUiq19(_iq19 throttle){

    if(throttle>_IQ19(1.0)){//takes care of out of bounds throttle
        throttle=_IQ19(1.0);
    }else if(throttle<_IQ19(-1.0)){
        throttle=_IQ19(-1.0);
    }

    _iq19   throttleaux=(throttle+ _IQ19(1.0));//remove offset
            throttleaux/=2;

    Uint16 realthrottle=(Uint32)((throttleaux)*pwmperiodinticks)    //scale to fit the PWM register span
                                                            >>19;   //bit shift to remove iq decimal

    if(realthrottle>(pwmperiodinticks)){//takes care of overshoots
        realthrottle=pwmperiodinticks;
    }

    EvaRegs.CMPR1=realthrottle;
    EvaRegs.CMPR2=realthrottle;

}

//takes ONOFF and enables/disables the PWM outputs, disabling by opening all high mosfets (logic low), and enabling low mosfets (logic high), shorting Motor coils to ground.
void enabledisable_PWMs(ON_OFF_enum ONOFF){
    if(ONOFF==ON|| ONOFF==OFF){//anything else other than 1 or 0 getts ignored
        EvaRegs.COMCONA.bit.FCMP1OE         = ONOFF; // Full Compare 1 (1=enabled, 0 disabled)
        EvaRegs.COMCONA.bit.FCMP2OE         = ONOFF; // Full Compare 2 (1=enabled, 0 disabled)
    }

}

//turns the motor X turns at speed_pu speed.
void disableMotorafterXturns(Uint32 X,_iq19 speed_pu){
    if(turncount_limit==0){
        ONOFF=ON;
        alpha=speed_pu;
        tickcount=0;
        turncount=0;
        turncount_limit=X;
    }
}

//to be put in main,
void ejerciciolab4_10turns_wait2000_changedirection(_iq19 * speed){
    if(ONOFF==OFF){
        delay(2000);
        turncount_limit=0;
        *speed=-*speed;
        disableMotorafterXturns(10, *speed);
    }
}

//enabling clocks and setting up ADC
void setupForADC(void){//https://www.youtube.com/watch?v=gCJA_am1-0U&ab_channel=Controller%27sknowledge
    DINT;                                       // Disable global interrupts:

    EALLOW;                                     //enable to write in protected area
    SysCtrlRegs.PCLKCR.bit.ADCENCLK=1;          //enables ADC peripheral clock
    PieVectTable.ADCINT = &interrupt_ADC;       //Address the interrupt vector to the desired function
    EDIS;

    EINT;                                        // Enable global interrupts:

    //Allow next interrupt service (write before leaving the interruption routine)
    PieCtrlRegs.PIEACK.bit.ACK1=1;
    //arranca el ADC
    InitAdc();

    PieCtrlRegs.PIEIER1.bit.INTx6=1;            //Enable interrupt Y of group X. //1=enable 0=disable
    IER |= M_INT1;                              //Enable group X of interrupts:
}


Uint32  AlphaP1_32bit=0;

void ejerciciolab5_ADCopenloop(){

    _iq19 upperlimit=_IQ19(0.7);
    _iq19 lowerlimit=_IQ19(0.0);

    if(alphaP1>upperlimit){
        alpha=upperlimit;
    }else if(alphaP1<lowerlimit){
        alpha=lowerlimit;
    }else{
        alpha=alphaP1;
    }

}



