/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "TADPilha.h"

int main()
{
    Pilha* pilha;
    int dado;
    
    pilha = criaPilha();
    
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    
   exibePilha(pilha);
   
   pop(pilha, &dado);
   
   printf("\n\tDado: %d", dado);

    exibePilha(pilha);

    return 0;
}