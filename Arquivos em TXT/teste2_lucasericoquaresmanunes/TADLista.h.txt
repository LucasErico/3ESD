typedef struct tipo_lista tLista; 
//cria lista vazia
tLista * cria_lista_vazia(int maximo,int classif, int repet);
//lista está vazia? 
int lista_vazia( const tLista *pl);
//lista está cheia? 
int lista_cheia( const tLista *pl);
//lista com repetição? 
int lista_repet( const tLista *pl);
//lista classificada? 
int lista_classif( const tLista *pl);
//percorre a lista 
void lista_percorre(const tLista *pl) ;
//inclui um item na lista: verifica caso repetição e classificação
int lista_inclui(tLista *pl, int valor);

int lista_remove(tLista *pl, int valor);

void exibe(int valor) ;

tLista * lst_sublista(tLista * original, int i, int j);
tLista * lst_soma_listas(tLista * lst1, tLista * lst2);

//Busca DESORDENADA sem repetição 
int busca_des_srep(tLista *pl,int chave,int *pos);
//Busca BINÁRIA 
int busca_bin(tLista *pl, int chave, int *pos) ;
//////////////////////////////////////////////////