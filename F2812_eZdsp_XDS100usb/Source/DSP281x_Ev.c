// TI File $Revision: /main/2 $
// Checkin $Date: April 29, 2005   11:10:23 $
//###########################################################################
//
// FILE:    DSP281x_Ev.c
//
// TITLE:   DSP281x Event Manager Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP281x C/C++ Header Files V1.20 $
// $Release Date: July 27, 2009 $
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File


//sets up everything needed to use the H bridge to drive the motor in the testbed
void initpwm1Andpwm2(void){
    // Peripheral clock enables set for the selected peripherals.
    EALLOW;
    SysCtrlRegs.PCLKCR.bit.EVAENCLK=1;//1 enable - 0 disable
    EDIS;

    // Initialization of the dead band timer control register
    EvaRegs.DBTCONA.bit.EDBT1 = 1; // Enable dead band timer 1
    EvaRegs.DBTCONA.bit.EDBT2 = 1; // Enable dead band timer 1
    EvaRegs.DBTCONA.bit.DBT   = 13; // Set the DB Timer period to 13 //LIMITADO A 4 BITS MAX=15
    EvaRegs.DBTCONA.bit.DBTPS = 2; // Set the dead band prescaler to 4
    //deadtime to 4*13*0,04us=2.08us

   //compare action control register
    EvaRegs.ACTRA.bit.CMP1ACT = 0x002; // Pin Action on PWM1 active high
    EvaRegs.ACTRA.bit.CMP2ACT = 0x001; // Pin Action on PWM2 active low
    EvaRegs.ACTRA.bit.CMP3ACT = 0x001; // Pin Action on PWM3 active high
    EvaRegs.ACTRA.bit.CMP4ACT = 0x002; // Pin Action on PWM4 active low
   // Initialization of timers and compare points
   EvaRegs.T1PR                = pwmperiodinticks; //25Mhz/2500=10Khz
   EvaRegs.T2PR                = pwmperiodinticks; //25Mhz/2500=10Khz
   EvaRegs.CMPR1               = pwmperiodinticks/2; //50%
   EvaRegs.CMPR2               = pwmperiodinticks/2; //50%

   EvaRegs.EXTCONA.bit.INDCOE  = 1; // Independent Compare Output Enabled

   EvaRegs.COMCONA.bit.C1TRIPE         = 1; // Full Compare 1 Trip enabled
   EvaRegs.COMCONA.bit.C2TRIPE         = 1; // Full Compare 1 Trip enabled
   EvaRegs.COMCONA.bit.FCMP1OE         = 1; // Full Compare 1 Output enabled
   EvaRegs.COMCONA.bit.FCMP2OE         = 1; // Full Compare 1 Output enabled
   EvaRegs.COMCONA.bit.PDPINTASTATUS   = 0; // PDPint High (DISABLES TO HIGH IMPEDANCE, HARDWARE GPIO FAULT ALARM)
   EvaRegs.COMCONA.bit.SVENABLE        = 0; // SVPWM disabled
   EvaRegs.COMCONA.bit.CLD             = 1; // Reload condition when T1CNT or T1PR = 0
   EvaRegs.COMCONA.bit.CENABLE         = 1; // Compare Enable

   // Initialization of the Timer 1 control registers
   EvaRegs.T1CON.bit.TECMPR    = 1; // Timer 1 Compare enabled
   EvaRegs.T1CON.bit.TCLD10    = 1; // Compare to reload when counter equals zero or period register
   EvaRegs.T1CON.bit.TCLKS10   = 0; // Timer 1 Clock source set to internal (HSPCLK)
   EvaRegs.T1CON.bit.TENABLE   = 1; // Timer 1 enabled
   EvaRegs.T1CON.bit.TPS       = 0; // preescaler to 1, 25Mhz
   EvaRegs.T1CON.bit.TMODE     = 1; // Continuous up-down counting
   EvaRegs.T1CON.bit.FREE      = 1; // Free run mode
   EvaRegs.T1CON.bit.SOFT      = 0;

   // Initialization of the Timer 2 control registers
   EvaRegs.T2CON.bit.TECMPR    = 1; // Timer 2 Compare enabled
   EvaRegs.T2CON.bit.TCLD10    = 1; // Compare to reload when counter equals zero or period register
   EvaRegs.T2CON.bit.TCLKS10   = 0; // Timer 2 Clock source set to internal (HSPCLK)
   EvaRegs.T2CON.bit.TENABLE   = 1; // Timer 2 enabled
   EvaRegs.T2CON.bit.TPS       = 0; // preescaler to 2, 25Mhz
   EvaRegs.T2CON.bit.TMODE     = 1; // Continuous up-down counting
   EvaRegs.T2CON.bit.FREE      = 1; // Free run mode
   EvaRegs.T2CON.bit.SOFT      = 0;
}

//setsup the quadrature encoder attached to the motor in the testbed
void initQEP(void){
    //painfully extracted from the provided HW schematics.
    //CA_DC ==CAP4_QEP3
    //CB_DC ==CAP5_QEP4
    //CI_DC ==CAP6_QEPI2

    // Peripheral clock enables set for the selected peripherals.
    EALLOW;
    SysCtrlRegs.PCLKCR.bit.EVBENCLK=1;//1 enable - 0 disable
    EDIS;

// SPRU065E https://www.ti.com/lit/ug/spru065e/spru065e.pdf?ts=1688512663363&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FTMS320F2810
//    3.5 Quadrature Encoder Pulse (QEP) Circuit
//    Each Event Manager module has a quadrature encoder pulse (QEP) circuit.
//    The QEP circuit, when enabled, decodes and counts the quadrature encoded
//    input pulses on pins CAP1/QEP1 and CAP2/QEP2 (in case of EVA) or
//    CAP4/QEP3 and CAP5/QEP4 (in case of EVB). The QEP circuit can be used
//    to interface with an optical encoder to get position and speed information from
//    a rotating machine.
/////When the QEP circuit is enabled, the capture function on CAP1/CAP2 and CAP4/CAP5 pins is disabled.


//    3.5.2 QEP Circuit Time Base
//    The time base for the QEP circuit is provided by GP timer 4,
//    . The GP timer must be put in directional-up/down count mode with the
//    QEP circuit as the clock source. Figure 3−3 shows the block diagram of the
//    QEP circuit for EVA and Figure 3−4 shows the block diagram of the QEP circuit
//    for EVB.
    // Initialization of the Timer 3



//    3.5.5 Register Setup for the QEP Circuit
//    To start the operation of the QEP circuit in EVB:
//    1) Load GP timer 4s counter, period, and compare registers with desired values,
//    if necessary
    EvbRegs.T4PR=0xFF;//Maximum uint16 value.

//    2) Configure T4CON to set GP timer 4 in directional-up/down mode with the
//    QEP circuits as clock source, and enable the selected timer
    EvbRegs.T4CON.bit.TECMPR    =1;// Timer 4 Compare enabled
    EvbRegs.T4CON.bit.TCLKS10   =3; // Timer 4 Clock source set to QEP circuit
    EvbRegs.T4CON.bit.TENABLE   =1; // Timer 4 enabled
    EvbRegs.T4CON.bit.TPS       =0; // preescaler to 1, 25Mhz
    EvbRegs.T4CON.bit.TMODE     =3; // Directional-Up/-Down Count Mode
}

//---------------------------------------------------------------------------
// InitEv: 
//---------------------------------------------------------------------------
// This function initializes to a known state.
//
void InitEv(void)
{
    initpwm1Andpwm2();
    initQEP();
}

//===========================================================================
// No more.
//===========================================================================
