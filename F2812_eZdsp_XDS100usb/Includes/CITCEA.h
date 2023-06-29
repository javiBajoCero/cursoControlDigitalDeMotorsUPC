
// Definició d'estructures i variables globals
extern long  dummy1;

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
