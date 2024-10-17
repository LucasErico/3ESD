#include "TADlistaCirc.h"
#include <stdio.h>

int main() {
    tLista* lista = cria_lista_vazia(1, 1);

    lista_inclui(lista, 10);
    lista_inclui(lista, 5);
    lista_inclui(lista, 20);
    lista_inclui(lista, 15);

    printf("Elementos da lista:\n");
    lista_percorre(lista);

    printf("\nRemovendo o elemento 10...\n");
    lista_remove(lista, 10);

    printf("Elementos da lista após remover 10:\n");
    lista_percorre(lista);

    printf("\nAdicionando o valor 5 novamente...\n");
    lista_inclui(lista, 5);

    printf("Elementos da lista após adicionar 5 novamente:\n");
    lista_percorre(lista);

    libera_lista(lista);

    return 0;
}
