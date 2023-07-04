// ·················· DAC ·······················
//DAC TLV5614  4canals 12bits
//El DAC té paraules de 16bits, 4 de configuració i 12 de dades


//Totes aquestes funcions són no crítiques i sempre aniran a la Flash
//Exemple de crida des de C
//	dac.inici();
//  dac.envia(&dac);


#ifndef DAC_H
#define DAC_H


typedef struct
{
	unsigned long	*Data;
	unsigned long Offset;
	unsigned long Guany;
} DAC_Struct;

#define DAC_DEFAULTS { (unsigned long *)0x00008182 \
						, 0x80000000			\
						, 0x000001 }



typedef struct
{
	DAC_Struct 	A;
	DAC_Struct 	B;
	DAC_Struct 	C;
	DAC_Struct 	D;
	int			nDAC;//es un contador extra;o interno, no es un enable., no tocar
} DAC_tipus;

typedef DAC_tipus *DAC_handle;

#define DAC_def { 	DAC_DEFAULTS \
					, DAC_DEFAULTS \
					, DAC_DEFAULTS \
					, DAC_DEFAULTS \
					, 0	}
					

void DAC_inici();
void DAC_envia(DAC_handle);


#endif
