typedef struct unidade tUnidade;
#include "TAD_Unidade.h"

tUnidade* uni_Cria(int dia, int mes, int ano, int lote);
void uni_libera(tUnidade* uni);
void uni_exibe(tUnidade* uni);

tData* uni_getData(tUnidade* uni);
int uni_getLote(tUnidade* uni);

//falta essas duas porra aqui aakkakkakak
void uni_setData(tUnidade* uni, int dia, int mes, int ano);
void uni_setLote(tUnidade* uni, int lote);

int uni_Idade(tUnidade* uni, int dia, int mes, int ano);
int uni_Compara(tUnidade* uniA, tUnidade* uniB);

char* uni_getUnidade(tUnidade* uni);
