#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TADCandidato.h"
#include "TADPonto.h"

struct candidato {
 char* nome;
 int idade;
 Ponto* notas;
} ;


tCandidato* cdt_Cria(char* nome, int idade, int nota1, int nota2)
{
    int tam;
    tCandidato* cdt;
    cdt = (tCandidato*)malloc(sizeof(tCandidato));
    cdt->nome = (char*)malloc(strlen(nome)+1);
    strcpy(cdt->nome, nome);
    
    cdt->idade = idade;
    
    cdt->notas = pto_cria(nota1, nota2);
    
    return cdt;
}

void cdt_libera(tCandidato* cdt)
{
    free(cdt->nome);
    free(cdt->notas);
    free(cdt);
    return;
}

void cdt_exibe(tCandidato* cdt)
{
    printf("\n\tNome do candidato: %s", cdt->nome);
    printf("\n\tIdade do candidato: %d", cdt->idade);
    printf("\n\tNotas: %s", pto_getPonto(cdt->notas));
    return;
}

int cdt_EhTestador(tCandidato* cdt, int n1, int n2, int limiar)
{
   int dist;
   Ponto* aux;
   aux = pto_cria(n1, n2);
   
   dist = pto_distancia(aux, cdt->notas);
   
   if(dist<=limiar)
   {
       return 1;
   }
   else
   {
       return 0;
   }
}

int cdt_compara(tCandidato* cdt1, tCandidato* cdt2)
{
    if(cdt1->idade == cdt2->idade)
    {
        return 0;
    }
    else
    {
        if(cdt1->idade<cdt2->idade)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}

char* cdt_getCandidato(tCandidato* cdt)
{
  char* cd;
  int tam = sizeof(*cdt)+100;
  cd = (char*)malloc(tam);
  sprintf(cd,"\n\tNome do candidato: %s\n\tIdade do candidato: %d\n\tNotas: %s", cdt->nome, cdt->idade, pto_getPonto(cdt->notas));
  return cd;
}






