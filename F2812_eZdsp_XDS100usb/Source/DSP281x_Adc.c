// TI File $Revision: /main/2 $
// Checkin $Date: April 29, 2005   11:11:45 $
//###########################################################################
//
// FILE:	DSP281x_Adc.c
//
// TITLE:	DSP281x ADC Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP281x C/C++ Header Files V1.20 $
// $Release Date: July 27, 2009 $
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

#define ADC_usDELAY  8000L
#define ADC_usDELAY2 20L

//---------------------------------------------------------------------------
// InitAdc: 
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
void InitAdc(void)
{
	extern void DSP28x_usDelay(Uint32 Count);
	
    // To powerup the ADC the ADCENCLK bit should be set first to enable
    // clocks, followed by powering up the bandgap and reference circuitry.
    // After a 5ms delay the rest of the ADC can be powered up. After ADC
    // powerup, another 20us delay is required before performing the first
    // ADC conversion. Please note that for the delay function below to
    // operate correctly the CPU_CLOCK_SPEED define statement in the
    // DSP28_Examples.h file must contain the correct CPU clock period in
    // nanoseconds. For example:

	AdcRegs.ADCTRL3.all = 0x0100; // Set bit 8 high to enable external
	DELAY_US(ADC_usDELAY);
	AdcRegs.ADCTRL3.bit.ADCBGRFDN = 0x3;	// Power up bandgap/reference circuitry
	DELAY_US(ADC_usDELAY);                  // Delay before powering up rest of ADC
	AdcRegs.ADCTRL3.bit.ADCPWDN = 1;		// Power up rest of ADC
	DELAY_US(ADC_usDELAY2);                 // Delay after powering up ADC


 // Initialization of the ADC Registers
	AdcRegs.ADCTRL3.bit.ADCCLKPS = 0x0003; // ADC Clock Prescaler
	AdcRegs.ADCTRL3.bit.SMODE_SEL = 1; // 0 -> Sequential sampling mode, 1 -> Simultaneous sampling mode
	AdcRegs.ADCTRL1.bit.SEQ_CASC  = 1; // 0 sets Dual Mode, 1 sets cascaded mode
	AdcRegs.ADCTRL1.bit.SEQ_OVRD  = 0; // 0 sets the pointer reset at the end of MAX_CONV1, 1 sets the pointer reset at the end of "end state"
	AdcRegs.ADCTRL1.bit.CONT_RUN  = 1; // 0 stops after reaching end of sequence, 1 doesn't stop
	AdcRegs.ADCTRL1.bit.CPS       = 0; // Conversion prescaler (0 -> CLK/1, 1 -> CLK/2)
	AdcRegs.ADCTRL1.bit.ACQ_PS    = 0xFFFF; // Aquistion time prescaler (S/H window = (ACQ_PS + 1)*(1/ADCCLK)
	AdcRegs.ADCTRL1.bit.SUSMOD    = 0; // 00 -> Free run, 01 -> Stop after current sequence, 10 -> Stop after current conversion, 11 -> Stop immediately
	AdcRegs.ADCTRL1.bit.RESET     = 0; // 1 resets the ADC

	AdcRegs.ADCTRL2.bit.EXT_SOC_SEQ1    =0; // 1 starts the signal from ADCSOC pin
	AdcRegs.ADCTRL2.bit.EVA_SOC_SEQ1    =1; // 1 allows the start trigger to be set to the same as the EVA trigger
	AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1    =0; // 0 interrupts every EOS, 1 every other EOS (EOS = End of Sampling)
	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1    =1; // 1 enables the interrupt, 0 disables it
	AdcRegs.ADCTRL2.bit.SOC_SEQ1        =1; // 0 clears the pending trigger, 1 allows a software trigger to start SEQ1
	AdcRegs.ADCTRL2.bit.RST_SEQ1        =1; // 1 resets SEQ1 to its initial state

	AdcRegs.ADCCHSELSEQ1.bit.CONV00     =0xB;
	AdcRegs.ADCCHSELSEQ1.bit.CONV01     =0xB;

	AdcRegs.ADCMAXCONV.bit.MAX_CONV1    =0x001; // Maximum Conversion channel registers for SEQ1

	AdcRegs.ADCST.bit.INT_SEQ1_CLR      =1; // 1 clears the interrupt, 0 has no effect
}	

//===========================================================================
// No more.
//===========================================================================
