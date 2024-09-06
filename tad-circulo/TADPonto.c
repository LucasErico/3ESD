#include "TADPonto.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/* Implementação TAD: Ponto (x,y) */
/*definição do tipo exportado*/ 
struct ponto {
  double x;
  double y;
};

/*definição das funções exportadas*/ 
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y){
   Ponto* p = (Ponto*) malloc(sizeof(Ponto));
   if (p == NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
   }
   p->x = x;
   p->y = y;
   return p;
}

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p) {
  free(p);
}

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y) {
  pto_acessaX(p, x);
  pto_acessaY(p, y);
}

/* Função acessa X - Retorna o valor da coordenada X de um ponto */
void pto_acessaX(Ponto* p, float* x)
{
    *x=p->x;
}

/* Função acessa Y - Retorna o valor da coordenada Y de um ponto */
void pto_acessaY(Ponto* p, float* y)
{
    *y=p->y;
}

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y) {
  pto_atribuiX(p, x);
  pto_atribuiY(p, y);
  
}

/* Função atribui X - Atribui novo valor à coordenada X de um ponto */
void pto_atribuiX(Ponto* p, float x)
{
    p->x=x;
}

/* Função atribui Y - Atribui novo valor à coordenada X de um ponto */
void pto_atribuiY(Ponto* p, float y)
{
    p->y=y;
}

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2) {
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  return sqrt(dx*dx + dy*dy);

  
}

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p1) {
  char* pt;
  int tam = sizeof(*p1)+ 8;
  pt = (char*)malloc(tam);
  sprintf(pt,"( %.2f , %.2f )", p1->x, p1->y);
  return pt;

}

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p) {
  printf(" (%f,%f) ",p->x,p->y);
}
int pto_compara(Ponto* pt1,Ponto* pt2){
/* Função menorque -recebe dois pontos e retorna 1 se o pt1 está mais pr´ximo da origem, 0 cc*/
  Ponto * origem=pto_cria(0,0);
  float distpt1_Orig=pto_distancia(pt1,origem);
  float distpt2_Orig=pto_distancia(pt2,origem);
  pto_libera(origem);

return distpt1_Orig-distpt2_Orig;
}
/* Função pto_soma, recebe dois pontos e retorna um
novo ponto, com as soma das coordenadas */
Ponto* pto_soma(Ponto * p1, Ponto* p2){
  float x, y;
  x=p1->x + p2->x;
  y=p1->y+p2->y;
  return pto_cria( x,  y);  
}


/* Função copia - Recebe um ponto e cria um novo ponto com as coordenadas do primeiro*/
Ponto* pto_copia(Ponto *p)
{
    return pto_cria(p->x, p->t);
}


/* Função desloca - Recebe um n1 e um n2 e desloca x n1 vezes e y n2 vezes */
void pto_desloca(Ponto* p, float* x, float* y, int n1, int n2)
{
    pto_deslocaX(p, x, n1);
    pto_deslocaY(p, y, n2);
}

/* Função desloca X - Recebe um n1 desloca x n1 vezes */
void pto_deslocaX(Ponto* p, float* x, int n1)
{
    p->x += *x;
}

/* Função descola Y - Recebe um n1 desloca y n1 vezes */
void pto_deslocaY(Ponto* p, float* y, int n1)
{
    p->y += *y;
}