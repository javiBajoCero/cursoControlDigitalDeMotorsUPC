
// Definició d'estructures i variables globals
extern long  dummy1;

void delay(int32 times);
void allGPIOSloff(void);
void allGPIOSon(void);
void turnSingleLEDon(int16 lednumber);
void turnSingleLEDoff(int16 lednumber);
int16 checkbit(int16 variabletocheck,int16 bitnumber);
void isGPB4Buttonpresed_incrementVariable(int16 * variable);
