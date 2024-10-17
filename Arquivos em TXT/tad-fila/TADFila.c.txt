#include <stdio.h>
#include <stdlib.h>

#include "TADFila.h"

// Definição do tipo nó (Nozin)
struct no
{ 
    int id; 
    tNo* prox;
}; 

// Definição do tipo fila (Fila)
struct fila
{ 
   tNo* F;
   tNo* R;
}; 

// Função para criar um no
tNo *criaNo(int valor)
{
    tNo* no = (tNo*) malloc(sizeof(tNo));
    no->id = valor;
    no->prox = NULL;
    return no;  
}

// Função para criar uma fila
Fila *criaFila()
{
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->F = NULL;
    fila->R = NULL;
    return fila;
}

// Função para enfilar
int enfila(Fila *f, int dado)
{
    tNo* novo = criaNo(dado);
    
    if(!novo)
    {
        return 0;
    }
    
    if(filaVazia(f))
    {
     f->F = f->R = novo;   
    }
    else
    {
        f->R->prox = novo;
        f->R = novo;
    }
    
    return 1;
}

// Função para desenfilar
int desenfila(Fila *f, int *dado)
{
    
    if(filaVazia(f))
    {
        return 0;
    }
    
    tNo* aux = f->F;
    *dado = f->F->id;
    f->F = f->F->prox;
    free(aux);
    
    return 1;
}

// Função para exibir os elementos da fila (só para teste)
void exibeFila(Fila *f)
{
    
    tNo* aux;
    aux = f->F;
    printf("\n\tFila: ");
    while(aux!=NULL)
    {
        printf("%d, ", aux->id);
        aux = aux->prox;
    }
}

// Verifica se a fila está vazia
int filaVazia(Fila *f)
{
    return (f->F == NULL);
    //errado
    /*
    if(p->topo == NULL)
    {
        return 1;
    }
    
    return 0;
    */
}

// Apaga toda a fila
int liberaFila(Fila *f)
{
    
    if(filaVazia(f))
    {
        return 0;
    }
    
    tNo* ant;
    tNo* suc;

    ant = f->F;
    
    while(ant!=NULL)
    {
        suc = ant->prox;
        free(ant);
        ant = suc;
    }
    
    free(f);
    
    return 1;
}