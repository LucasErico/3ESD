#include <stdio.h>
#include <stdlib.h>

#include "TADPilha.h"

// Definição do tipo nó (Nozin)
struct no
{ 
    int id; 
    tNo* prox;
}; 

// Definição do tipo pilha (Pilha)
struct pilha
{ 
   tNo* topo;
}; 

// Função para criar um no
tNo *criaNo(int valor)
{
    tNo* no = (tNo*) malloc(sizeof(tNo));
    no->id = valor;
    no->prox = NULL;
    return no;  
}

// Função para criar uma pilha
Pilha *criaPilha()
{
    Pilha* pilha= (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}



// Função para empilhar (push)
int push(Pilha *p, int dado)
{
    tNo* novo = criaNo(dado);
    
    if(!novo)
    {
        return 0;
    }
    
    novo->prox = p->topo;
    p->topo = novo;
    
    return 1;
}

// Função para desempilhar (pop)
int pop(Pilha *p, int *dado)
{
    
    if(pilhaVazia(p))
    {
        return 0;
    }
    
    tNo* aux = p->topo;
    *dado = p->topo->id;
    p->topo = p->topo->prox;
    
    free(aux);
    return 1;
}

// Função para exibir os elementos da pilha (só para teste)
void exibePilha(Pilha *p)
{
    tNo* aux;
    aux = p->topo;
    printf("\n\tPilha: ");
    while(aux!=NULL)
    {
        printf("\n\t%d, ", aux->id);
        aux = aux->prox;
    }
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *p)
{
    return (p->topo == NULL);
    //errado
    /*
    if(p->topo == NULL)
    {
        return 1;
    }
    
    return 0;
    */
}
