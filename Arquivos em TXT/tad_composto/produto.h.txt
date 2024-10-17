typedef struct produto tProduto;
#include "TAD_Unidade.h"

tUnidade* uni_Cria(int dia, int mes, int ano, int lote);
void uni_libera(tUnidade* uni);
void uni_exibe(tUnidade* uni);

int uni_Idade(tUnidade* uni, int dia, int mes, int ano);
int uni_Compara(tUnidade* uniA, tUnidade* uniB);

char* uni_getUnidade(tUnidade* uni);
