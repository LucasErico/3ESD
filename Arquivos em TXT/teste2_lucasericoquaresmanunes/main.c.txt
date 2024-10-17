/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "TADLista.h"

int main()
{
    tLista * lista1;
    tLista * lista2;
    tLista * lista3;
    int n, class, rep;
    
    
    // teste teste teste teste teste teste 
    printf("\n\tQuantidade de elementos da primeira lista: ");
    scanf("%d", &n);
    printf("\n\tClassificada? 1-S 2-N: ");
    scanf("%d", &class);
    printf("\n\tCom repetição? 1-S 2-N: ");
    scanf("%d", &rep);
    lista1 = cria_lista_vazia(n, class, rep);
    
    printf("\n\tQuantidade de elementos da segunda lista: ");
    scanf("%d", &n);
    printf("\n\tClassificada? 1-S 2-N: ");
    scanf("%d", &class);
    printf("\n\tCom repetição? 1-S 2-N: ");
    scanf("%d", &rep);
    lista2 = cria_lista_vazia(n, class, rep);

    return 0;
}