/*
    Tarefa TAD_Composto
    Dupla: Lucas Érico, Jonathan Bastos

*/

#include <stdlib.h>
#include <stdio.h>
#include "TAD_Data.h"
#include "TAD_Unidade.h"



//idade 
//compara 



struct unidade {
 
 tData* dataFab;
 int lote;
} ;


tUnidade* uni_Cria(int dia, int mes, int ano, int lote)
{
    tUnidade* uni;
    uni = (tUnidade*)malloc(sizeof(tUnidade));
    uni->dataFab = dta_cria(dia, mes, ano);
    uni->lote = lote;
    
    return uni;
    
}


void uni_libera(tUnidade* uni)
{
    
    free(uni->dataFab);
    free(uni);
    return;
}

void uni_exibe(tUnidade* uni)
{
    printf("\n\tData de fabricacao: %s", dta_getData(uni->dataFab))
    printf("\n\tLote: %d", uni->lote);
    return;
}

tData* uni_getData(tUnidade* uni)
{
    return uni->dataFab;
}

int uni_getLote(tUnidade* uni)
{
    return uni->lote;
}

void uni_setData(tUnidade* uni, int dia, int mes, int ano)
{
    dta_atribui(uni->dataFab, dia, mes, ano);
    return;
}

void uni_setLote(tUnidade* uni, int lote)
{
    uni->lote = lote;
    return;
}

//falta essas duas porra aqui aakkakkakak
int uni_Idade(tUnidade* uni, int dia, int mes, int ano)
int uni_Compara(tUnidade* uniA, tUnidade* uniB);

char* uni_getUnidade(tUnidade* uni){
    
    char* ur;
    
    int tam = sizeof(*uni)+30;
    
    ur = (char*)malloc(tam);
    
    sprintf(ur, "\n\tData de fabricacao: %s\n\tLote: %d", dta_getData(uni->dataFab),uni->lote);
    
    return ur;
}




