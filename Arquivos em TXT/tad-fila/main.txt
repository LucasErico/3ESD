/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "TADFila.h"

int main()
{
    Fila* fila;
    int dado;
    
    fila = criaFila();
    
    enfila(fila, 1);
    enfila(fila, 7);
    enfila(fila, 4);
   
    
   exibeFila(fila);
   
   desenfila(fila, &dado);
   
   printf("\n\tDado: %d", dado);

    exibeFila(fila);
    
    enfila(fila, 8);
    
    exibeFila(fila);

    liberaFila(fila);
    
    exibeFila(fila);
    
    return 0;
}