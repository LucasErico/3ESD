#include "TADLista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/* Em seguida, um tipo para a lista */ 
struct tipo_lista 
{ 
    int* vnos; 
    int qtnos; 
    int maximo; 
    int classificada; // 1: classificada 0: não classificada 
    int repeticao; // 1: com repetição 0: sem repetição 
}; 
//////////////////////////////////////////
//FUNÇÔES AUXILIARES

//exibe item 
void exibe(int valor) ;

//Busca DESORDENADA sem repetição 
int busca_des_srep(tLista *pl,int chave,int *pos);
//Busca BINÁRIA 
int busca_bin(tLista *pl, int chave, int *pos) ;
//////////////////////////////////////////////////


//cria lista vazia
tLista * cria_lista_vazia(int maximo,int classif, int repet) 
{
    tLista * pl= (tLista*) malloc(sizeof(tLista));
    pl->vnos=(int *) malloc(sizeof(int) * maximo);
    pl->qtnos = 0; 
    pl->maximo= maximo; 
    pl->classificada=classif; 
    pl->repeticao=repet; 
    return pl;
} 
//lista está vazia? 
int lista_vazia( const tLista *pl){ 
    return ( pl->qtnos == 0); 
}
//lista está cheia? 
int lista_cheia( const tLista *pl){ 
    return ( pl->qtnos == pl->maximo); 
} 
//lista com repetição? 
int lista_repet( const tLista *pl){ 
    return ( pl->repeticao == 1); 
} 
//lista classificada? 
int lista_classif( const tLista *pl){ 
    return ( pl->classificada == 1); 
} 
//percorre a lista 
void lista_percorre(const tLista *pl) { 
    int i; 
    for(i = 0; i < pl->qtnos; i++) 
        exibe(pl->vnos[i]); 
}

// remove um item da lista
int lista_remove(tLista *pl, int valor) {
    int pos, st, remov = 0;
    if (lista_vazia(pl))
        return 0;

    
    if (lista_classif(pl)) {
        while ((st = busca_bin(pl, valor, &pos)) == 1) {
            if (pos < pl->qtnos - 1) {
                int qt = pl->qtnos - pos - 1;
                memcpy(pl->vnos+pos,pl->vnos+pos+1,qt*(sizeof(int)));
            }
            pl->qtnos--;
            remov++;
            if (!lista_repet(pl)) {
                break;
            }
        }
    } else {
        while ((st = busca_des_srep(pl, valor, &pos)) == 1) {
            if (pos < pl->qtnos - 1) {
                int qt = pl->qtnos - pos - 1;
                memcpy(pl->vnos+ pos, pl->vnos+pos+1,qt*(sizeof(int)));
            }
            pl->qtnos--;
            remov++;
            if (!lista_repet(pl)) {
                break;
            }
        }
    }
    return remov;
}


//inclui um item na lista: verifica caso repetição e classificação
int lista_inclui(tLista *pl, int valor) {
    int pos;
    int st;
    if (lista_cheia(pl))
        return 0;

    //determinar a pos de inclusão
    if (!lista_classif(pl) && lista_repet(pl)){
        pos=pl->qtnos;
        st=0;
    }
    else if (lista_classif( pl)){
        st= busca_bin(pl,valor,&pos);
        if (lista_repet(pl))
            st=0;
    }
    else{
        st= busca_des_srep(pl,valor,&pos);
    }

    // pode ou não incluir?
    if (st==1) 
        return -1; 

    // abrir o buraco pos
    if (pos <pl->qtnos){
        int qt= pl->qtnos-pos;
        memcpy(pl->vnos+pos+1, pl->vnos+pos, qt*sizeof(int)); //chegaprálá 1 posd
    }
    pl->vnos[pos]=valor;
    pl->qtnos++;
    return 1;
}














//FUNÇÔES AUXILIARES

//exibe item 
void exibe(int valor) { 
    printf("\n%d",valor);
} 

//////////////////////////////
  //FUNÇÕES AUXILIARES

  // Exibe item


  // Busca Desordenada sem Repetição
  int busca_des_srep(tLista *pl, int chave, int *pos) {
      int i;
      for (i = 0; i < pl->qtnos; i++) {
          if (pl->vnos[i] == chave) {
              *pos = i;
              return 1; // Valor encontrado
          }
      }
      *pos = i; // Posição onde o valor pode ser inserido
      return 0; // Valor não encontrado
  }

  // Busca Binária
  int busca_bin(tLista *pl, int chave, int *pos) {
      int inicio = 0;
      int meio;
      int fim = pl->qtnos - 1;
      int achou = 0;

      while (inicio <= fim) {
          meio = (inicio + fim) / 2;
          if (pl->vnos[meio] == chave) {
              achou = 1;
              break;
          } else if (pl->vnos[meio] > chave) {
              fim = meio - 1;
          } else {
              inicio = meio + 1;
          }
      }

      if (achou) {
          *pos = meio;
      } else {
          *pos = inicio; // Posição onde o valor pode ser inserido
      }

      return achou;
}

tLista * lst_sublista(tLista * original, int i, int j)
{
    tLista * sub = (tLista*) malloc(sizeof(tLista));
    int tam = (j-i)+1;
    
    sub->classificada = original->classificada; 
    sub->repeticao = original->repeticao; 
    
    if(i<1 || j>original->maximo || i>j)
    {
        sub->vnos = 0;
        sub->qtnos = 0; 
    }
    else
    {
       sub->vnos=(int *) malloc(sizeof(int) * tam); 
       sub->qtnos = tam;
       sub->maximo= tam;
       
       for(int k = i; k <= j; k++)
       {
           lista_inclui(sub, original->vnos[k-1]);
       }
    }
    
    return sub;
}


tLista * lst_soma_listas(tLista * lst1, tLista * lst2)
{
    tLista * sub = (tLista*) malloc(sizeof(tLista));
    int tam, soma;
    if(lst1->maximo <= lst2->maximo)
    {
        tam = lst1->maximo;
    }
    else
    {
        tam = lst2->maximo;
    }
    
    sub->vnos=(int *) malloc(sizeof(int) * tam); 
    sub->qtnos = tam;
    sub->maximo= tam;
    
    if(lst1->classificada == lst2->classificada && lst1->repeticao == lst2->repeticao)
    {
        sub->classificada = lst1->classificada;
        sub->repeticao = lst1->repeticao;
    }
    else
    {
        sub->classificada = 1;
        sub->repeticao = 0;
    }
    
    for(int i=0; i<tam; i++)
    {
        soma = lst1->vnos[i] + lst2->vnos[i];
        lista_inclui(sub, soma);
        
    }
    
    return sub;
}


