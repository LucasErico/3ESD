typedef struct circulo tCirculo;
#include "TADPonto.h"

tCirculo* circCria(int x,int y, float r); 
void circSetRaio(tCirculo* c, float r);
float circGetRaio(tCirculo * c); 
float circArea(tCirculo * c); 
float circComprimento(tCirculo *c);
int circCompara(tCirculo *c1, tCirculo *c2); 
char* circ_getCirculo(tCirculo* p);
void circ_exibe(tCirculo* p);
//tCirculo* circ_clona(tCirculo* cO);

