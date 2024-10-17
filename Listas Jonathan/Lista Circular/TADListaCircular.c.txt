#include "TADlistaCirc.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    tNo* prox;
};

struct lista {
    tNo* inicio;
    int classif;
    int repet;
};

tNo* cria_no(int valor) {
    tNo* no = (tNo*) malloc(sizeof(tNo));
    no->info = valor;
    no->prox = NULL;
    return no;
}

tLista* cria_lista_vazia(int classif, int repet) {
    tLista* l = (tLista*) malloc(sizeof(tLista));
    l->inicio = NULL;
    l->classif = classif;
    l->repet = repet;
    return l;
}

int lista_vazia(const tLista *pl) {
    return (pl->inicio == NULL);
}

int lista_repet(const tLista *pl) {
    return pl->repet;
}

int lista_classif(const tLista *pl) {
    return pl->classif;
}

void lista_percorre(const tLista *pl) {
    if (lista_vazia(pl)) return;

    tNo* noAux = pl->inicio;
    do {
        exibe(noAux->info);
        noAux = noAux->prox;
    } while (noAux != pl->inicio);
}

int lista_inclui(tLista *pl, int valor) {
    if (!pl->repet) {
        tNo* aux = pl->inicio;
        if (!lista_vazia(pl)) {
            do {
                if (aux->info == valor) return 0;
                aux = aux->prox;
            } while (aux != pl->inicio);
        }
    }

    tNo* novo = cria_no(valor);

    if (lista_vazia(pl)) {
        pl->inicio = novo;
        novo->prox = novo;
        return 1;
    }

    if (!pl->classif) {
        tNo* ultimo = pl->inicio;
        while (ultimo->prox != pl->inicio) {
            ultimo = ultimo->prox;
        }
        novo->prox = pl->inicio;
        ultimo->prox = novo;
        pl->inicio = novo;
        return 1;
    }

    tNo* atual = pl->inicio;
    tNo* anterior = NULL;

    do {
        if (atual->info >= valor) break;
        anterior = atual;
        atual = atual->prox;
    } while (atual != pl->inicio);

    if (anterior == NULL) {
        tNo* ultimo = pl->inicio;
        while (ultimo->prox != pl->inicio) {
            ultimo = ultimo->prox;
        }
        novo->prox = pl->inicio;
        ultimo->prox = novo;
        pl->inicio = novo;
    } else {
        anterior->prox = novo;
        novo->prox = atual;
    }

    return 1;
}

int lista_remove(tLista *pl, int valor) {
    if (lista_vazia(pl)) return 0;

    tNo* atual = pl->inicio;
    tNo* anterior = NULL;

    do {
        if (atual->info == valor) break;
        anterior = atual;
        atual = atual->prox;
    } while (atual != pl->inicio);

    if (atual->info != valor) return 0;

    if (atual == pl->inicio && atual->prox == pl->inicio) {
        pl->inicio = NULL;
    } else {
        if (anterior == NULL) {
            tNo* ultimo = pl->inicio;
            while (ultimo->prox != pl->inicio) {
                ultimo = ultimo->prox;
            }
            pl->inicio = atual->prox;
            ultimo->prox = pl->inicio;
        } else {
            anterior->prox = atual->prox;
        }
    }

    free(atual);
    return 1;
}

void exibe(int valor) {
    printf("%d ", valor);
}

void libera_lista(tLista *pl) {
    if (lista_vazia(pl)) return;

    tNo* atual = pl->inicio;
    tNo* proximo;
    do {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    } while (atual != pl->inicio);

    pl->inicio = NULL;
}
