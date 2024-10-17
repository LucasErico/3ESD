#include <stdlib.h>
#include <stdio.h>
#include "TADCirculo.h"
#define PI 3.14159


struct circulo {
 Ponto *p;
 float r;
} ;


void circSetRaio(tCirculo * c, float r){
    c->r=r;
}

tCirculo * circCria(int x,int y, float r){
  tCirculo * c=(tCirculo*)malloc(sizeof(tCirculo));
  c->p=pto_cria(x,y);
  //pto_atribui(&c->p,x,y);
  circSetRaio(c,r);
  return c;
}

float circGetRaio(tCirculo *c){
    return c->r;
}

float circArea(tCirculo *c){
    return PI*c->r*c->r;
}

float circComprimento(tCirculo *c){
    return 2*PI*c->r;
}

int circCompara(tCirculo *c1, tCirculo *c2){
    if(circComprimento(c1)>circComprimento(c2)){
        printf("Primeiro circulo maior que o segundo");
        return 1;
    }
    else {
        if(circComprimento(c1)==circComprimento(c2)){
            printf("Circulos iguais");
            return -1;
        }
        else {
            printf("Segundo circulo maior que o primeiro");
            return 0;
        }
    }
}
char* circ_getCirculo(tCirculo* p){

    char* pt = (char*)malloc(sizeof(*p) + 8);

    sprintf(pt, "(centro:%s , raio:%.2f )", pto_getPonto(p->p), p->r);

    return pt;

}

void circ_exibe(tCirculo* p){

     pto_exibe(p->p)
     printf("%.2f",p->r)
    //printf("(centro: %s, raio: % .2f)",pto_getPonto(p->p), p->r);

}


/*
tCirculo* circ_clona(tCirculo* cO){

    tCirculo* cD = (tCirculo*)malloc(sizeof(tCirculo));
    
    cD->p = pto_clona(cO->p);
    
    cD->r = cO->r;
    
    return cD;

}
*/
