#include <stdlib.h>
#include <stdio.h>
#include "TADRetangulo.h"

//cria, libera, area, exibe, getRetangulo

struct retangulo {
 Ponto *pie;
 Ponto *pid;
 Ponto *pse;
 Ponto *psd;
 int base;
 int altura;
} ;

tRetangulo* ret_Cria(int x1,int y1, int x2, int y2)
{
    tRetangulo* ret;
    
    ret = (tRetangulo*)malloc(sizeof(tRetangulo));
    ret->pie = pto_cria(x1, y1);
    ret->pid = pto_cria(x2, y1);
    ret->pse = pto_cria(x1, y2);
    ret->psd = pto_cria(x2, y2);
    
    ret->base = pto_distancia(ret->pie, ret->pid);
    ret->altura = pto_distancia(ret->pie, ret->pse);
    
    return ret;
}

void ret_libera(tRetangulo* ret)
{
    free(ret->pie);
    free(ret->pid);
    free(ret->pse);
    free(ret->psd);
    free(ret);
}

int ret_area(tRetangulo* ret)
{
    int area;
    
    area = ret->base * ret->altura;
    
    return area;
}

void ret_exibe(tRetangulo* ret)
{
    printf("\n\tPonto Inferior Esquerdo: %s", pto_getPonto(ret->pie));
    printf("\n\tPonto Inferior Direito: %s", pto_getPonto(ret->pid));
    printf("\n\tPonto Superior Esquerdo: %s", pto_getPonto(ret->pse));
    printf("\n\tPonto Superior Direito: %s", pto_getPonto(ret->psd));
    printf("\n\tBase: %d", ret->base);
    printf("\n\tAltura: %d", ret->altura);
    
}

void ret_getRetangulo(tRetangulo* ret)
{
    char* rt;
  int tam = sizeof(*ret)+19;
  rt = (char*)malloc(tam);
  sprintf(rt,"\n\tPonto Inferior Esquerdo: %s\n\tPonto Inferior Direito: %s\n\tPonto Superior Esquerdo: %s\n\tPonto Superior Direito: %s\n\tBase: %d\n\tAltura: %d", pto_getPonto(ret->pie), pto_getPonto(ret->pid), pto_getPonto(ret->pse), pto_getPonto(ret->psd), ret->base, ret->altura);
  return rt;

}


