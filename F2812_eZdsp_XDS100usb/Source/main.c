//
//
//###########################################################################
//
// FILE:    Main.c
//
//  CITCEA 7/6/2005 DC
//###########################################################################

// Step 0.  Include required header files
         // DSP28_Device.h: device specific definitions #include statements for
         // all of the peripheral .h definition files.
         // DSP28_Example.h is specific for the given example.

#include "DSP281x_Device.h"


// Prototype statements for functions found within this file.



void main(void)
{

// Step 1. Initialize System Control registers, PLL, WatchDog, Clocks to default state:
    // This function is found in the DSP28_SysCtrl.c file.
    InitSysCtrl();

// Step 2. Select GPIO for the device or for the specific application:
    // This function is found in the DSP28_Gpio.c file.
    InitGpio();  // Not required for this example

// Step 3. Initialize PIE vector table:
    // The PIE vector table is initialized with pointers to shell Interrupt
    // Service Routines (ISR).  The shell routines are found in DSP28_DefaultIsr.c.
    // Insert user specific ISR code in the appropriate shell ISR routine in
    // the DSP28_DefaultIsr.c file.

    // Disable and clear all CPU interrupts:
    DINT;
    IER = 0x0000;
    IFR = 0x0000;

    // Initialize Pie Control Registers To Default State:
    // This function is found in the DSP28_PieCtrl.c file.
    InitPieCtrl();

    // Initialize the PIE Vector Table To a Known State:
    // This function is found in DSP28_PieVect.c.
    // This function populates the PIE vector table with pointers
    // to the shell ISR functions found in DSP28_DefaultIsr.c.
    InitPieVectTable();

// Step 4. Initialize all the Device Peripherals to a known state:
    // This function is found in DSP28_InitPeripherals.c
    // InitPeripherals();  // For this example just init the CPU Timers
    InitCpuTimers();
    //enableinterruptTIM0(1000);//1ms = 1 kHz
    enableinterruptTIM0(5000);//5ms = 200Hz

// Step 5. User specific functions, Reassign vectors (optional), Enable Interrupts:
    //InitAdc();    // Inicialitzo el ADC
    // Enable global Interrupts and higher priority real-time debug events:

//  EINT;   // Enable Global interrupt INTM
//  ERTM;     // Enable Global realtime interrupt DBGM

// Step 6. IDLE loop. Just sit and loop forever (optional):
    //enableinterruptTIM0(2000000);//2 seconds =0,5Hz
    setupForDACexercice();
    setupForPWM();
    setupForADC();
    //_iq19 ejercicio4_speed=_IQ19(0.1);
    for(;;)
    {

       //ejercicio1_ledblink();
       //ejercicio2_cochefantastico();
       //ejercicio3_contadorbinarioboton();
       //ejercicio4_secretpassword();
       //ejerciciolab4_10turns_wait2000_changedirection(&ejercicio4_speed);
       ejerciciolab5_ADCopenloop();
    }

}



//===========================================================================
// No more.
//===========================================================================
