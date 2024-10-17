/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADCandidato.h"
#include "TADPonto.h"

int sorteio(int lInf,int lSup)
{
  return (rand()%((lSup-lInf)+1))+lInf;
}

void preencheCandidatos(tCandidato* vCandidatos[], int n)
{
    
    
    
    
    return;
}


int main()
{
    tCandidato** vetCandidatos;
    tCandidato** vetTestadores;
    int n, tam, contTest=0;
    
    int i, idade, n1, n2, nome;
    char vNome[10][5]={"Dodo","Dede","Didi","Zizo","Vava","Dudu","Mimi","Lala","Lele", "Kaka"};
    
    printf("\n\tQuantos candidatos deseja? ");
    scanf("%d", &n);
    tam=(sizeof(tCandidato*)*n);
    vetCandidatos = (tCandidato**)malloc(tam);
  
    for(i=0; i<n; i++)
    {
        nome = sorteio(0,9);
        idade = sorteio(18,40);
        n1 = sorteio(0,10);
        n2 = sorteio(0,10);
        vetCandidatos[i] = cdt_Cria(vNome[nome], idade, n1, n2);
    }
    
     printf("\n\tCANDIDATOS: ");
    
    for(i =0; i<n; i++)
    {
        printf("\n%s", cdt_getCandidato(vetCandidatos[i]));
    }
    
    for(i=0; i<n; i++)
    {
        if(cdt_EhTestador(vetCandidatos[i], 5, 8, 2))
        {
            contTest++;
        }
    }
    
    tam=(sizeof(tCandidato*)*contTest);
    vetTestadores = (tCandidato**)malloc(tam);
    contTest=0;
    
     for(i=0; i<n; i++)
    {
        if(cdt_EhTestador(vetCandidatos[i], 5, 8, 2))
        {
            vetTestadores[contTest] = vetCandidatos[i];
            contTest++;
        }
    }
    
    printf("\n\tTESTADORES: ");
    
    for(i =0; i<contTest; i++)
    {
        printf("\n%s", cdt_getCandidato(vetTestadores[i]));
    }
    
    
    
    
    return 0;
}
