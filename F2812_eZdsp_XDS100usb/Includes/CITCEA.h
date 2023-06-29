
// Definició d'estructures i variables globals
extern long  dummy1;
extern DAC_tipus dacstruct;


#define TIMER0clockfreq 150 //Mhz

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

//toggle LED
#define TOGGLE_onboardLED   (GpioDataRegs.GPFTOGGLE.bit.GPIOF14=0x01)
#define TOGGLE_LED5         (GpioDataRegs.GPETOGGLE.bit.GPIOE0=0x01)
#define TOGGLE_LED6         (GpioDataRegs.GPETOGGLE.bit.GPIOE1=0x01)
#define TOGGLE_LED7         (GpioDataRegs.GPBTOGGLE.bit.GPIOB2=0x01)
#define TOGGLE_LED8         (GpioDataRegs.GPBTOGGLE.bit.GPIOB3=0x01)


void delay(int32 times);
void allGPIOSloff(void);
void allGPIOSon(void);
void turnSingleLEDon(int16 lednumber);
void turnSingleLEDoff(int16 lednumber);
int16 checkbit(int16 variabletocheck,int16 bitnumber);
void isGPB4Buttonpresed_incrementVariable(int16 * variable);

void ejercicio1_ledblink(void);
void ejercicio2_cochefantastico(void);
void ejercicio3_contadorbinarioboton(void);
void ejercicio4_secretpassword(void);

interrupt void interrupt_timer0(void);
void enableinterruptTIM0(float period);
void setupForDACexercice(void);
