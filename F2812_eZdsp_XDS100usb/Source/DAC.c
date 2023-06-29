// ·················· DAC ·······················
//DAC TLV5614 4channels 12bits
//DAC works with words of 16bits, 4 bit configuration and 12 bit data
//Example:
// dac.inici();
// dac.envia(&dac);


#include "DSP281x_Device.h"
#include "DAC.h"
// SPI configuration for DAC

void DAC_inici()
{
	int i;
		
	//SPI configuration for DAC
	EALLOW;
	
	SysCtrlRegs.PCLKCR.bit.SPIENCLK = 1; // Peripheral activation

	GpioMuxRegs.GPFMUX.bit.SPISIMOA_GPIOF0 = 1; // configured as SPI
	GpioMuxRegs.GPFMUX.bit.SPICLKA_GPIOF2 = 1; // configured as SPI
	GpioMuxRegs.GPFMUX.bit.SPISTEA_GPIOF3 = 1; // configured as SPI
		
	SpiaRegs.SPICCR.bit.SPISWRESET = 0; // reset for configuration modification
	
	SpiaRegs.SPICCR.bit.SPICHAR = 0x000F;	// 16 bits words
   	SpiaRegs.SPICTL.bit.CLK_PHASE = 1;
  	SpiaRegs.SPICCR.bit.CLKPOLARITY = 1;	// Down trigger
  	SpiaRegs.SPICCR.bit.SPILBK = 0;			// Loopback disabled
  							
	SpiaRegs.SPICTL.bit.MASTER_SLAVE = 1; 	// Master Mode
	SpiaRegs.SPICTL.bit.OVERRUNINTENA = 0;
	SpiaRegs.SPICTL.bit.SPIINTENA = 0;	// SPI interruptions disabled
	SpiaRegs.SPICTL.bit.TALK = 1;
	
	SpiaRegs.SPICCR.bit.SPISWRESET = 1; // out of reset

    SpiaRegs.SPIBRR =0x0000;	// Divided by 1 lowspeedclK of 18,75MHz
								// SPICLK at 18,75MHz
	
	// Wait until SPICLK is configured
	for(i=0; i<10000;i++)								
	{
		asm("	NOP");
	}
	
	EDIS;

	SpiaRegs.SPIDAT = 0x00000001; //send something to enable SPI

	return;
}


void DAC_envia(DAC_tipus *v)
{
	
	if(SpiaRegs.SPISTS.bit.INT_FLAG)
	{		
		SpiaRegs.SPIRXBUF;
		
		switch(v->nDAC)
		{
		case 0:
		SpiaRegs.SPITXBUF = (((((*(long *)v->A.Data) * v->A.Guany + v->A.Offset)>>20)|0x1000));
		v->nDAC++;
		break;

		case 1:
		SpiaRegs.SPITXBUF = (((((*(long *)v->B.Data) * v->B.Guany + v->B.Offset)>>20)|0x5000));
		v->nDAC++;
		break;

		case 2:
		SpiaRegs.SPITXBUF = (((((*(long *)v->C.Data) * v->C.Guany + v->C.Offset)>>20)|0x9000));
		v->nDAC++;
		break;

		case 3:
		SpiaRegs.SPITXBUF = (((((*(long *)v->D.Data) * v->D.Guany + v->D.Offset)>>20)|0xD000));
		v->nDAC=0;
		break;	
		
		}
		
	}
	
	return;
}
