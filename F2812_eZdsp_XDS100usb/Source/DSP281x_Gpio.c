// TI File $Revision: /main/2 $
// Checkin $Date: April 29, 2005   11:10:14 $
//###########################################################################
//
// FILE:	DSP281x_Gpio.c
//
// TITLE:	DSP281x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP281x C/C++ Header Files V1.20 $
// $Release Date: July 27, 2009 $
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known state.
//
void InitGpio(void)
{

// Set GPIO A port pins,AL(Bits 7:0)(input)-AH(Bits 15:8) (output) 8bits
// Input Qualifier =0, none
     EALLOW;
     GpioMuxRegs.GPAMUX.all=0x0000;     
     GpioMuxRegs.GPADIR.all=0xFF00;    	// upper byte as output/low byte as input
     GpioMuxRegs.GPAQUAL.all=0x0000;	// Input qualifier disabled

// Set GPIO B port pins, configured as EVB signals //TODO:EVB?
// Input Qualifier =0, none
// Set bits to 1 to configure peripherals signals on the pins
     ////GPIO B CONFIG
     GpioMuxRegs.GPBMUX.all=0x0000;
     GpioMuxRegs.GPBDIR.bit.GPIOB2=1;        // 1=output
     GpioMuxRegs.GPBDIR.bit.GPIOB3=1;        // 1=output
     GpioMuxRegs.GPBDIR.bit.GPIOB4=0;        // 0=input white button S1
     GpioMuxRegs.GPBDIR.bit.GPIOB5=0;        // 0=input red switch S3-1
     GpioMuxRegs.GPBDIR.bit.GPIOB6=0;        // 0=input red switch S3-2
     GpioMuxRegs.GPBDIR.bit.GPIOB7=0;        // 0=input red switch S3-3
     GpioMuxRegs.GPBQUAL.bit.QUALPRD=8;	// Input qualifier enabled with period 8
     GpioDataRegs.GPBCLEAR.bit.GPIOB2=0x1;
     GpioDataRegs.GPBCLEAR.bit.GPIOB3=0x1;
     ////GPIO E CONFIG
     GpioMuxRegs.GPEMUX.all=0x0000;
     GpioMuxRegs.GPEDIR.bit.GPIOE0=1;        // 1=output
     GpioMuxRegs.GPEDIR.bit.GPIOE1=1;        // 1=output
     GpioMuxRegs.GPEQUAL.all=0x0000;    // Input qualifier disabled
     GpioDataRegs.GPECLEAR.bit.GPIOE0=0x1;
     GpioDataRegs.GPECLEAR.bit.GPIOE1=0x1;

     ////GPIO F CONFIG
     GpioMuxRegs.GPFMUX.all=0x0000;
     GpioMuxRegs.GPFDIR.bit.GPIOF14=1;        // 1=output
     GpioDataRegs.GPFCLEAR.bit.GPIOF14=0x1;






     EDIS;

}	
	
//===========================================================================
// No more.
//===========================================================================
