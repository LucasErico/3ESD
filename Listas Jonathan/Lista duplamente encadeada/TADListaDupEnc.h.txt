typedef struct no tNo;
typedef struct lista tLista;

tLista* cria_lista_vazia(int classif, int repet);
int lista_vazia(const tLista *pl);
int lista_repet(const tLista *pl);
int lista_classif(const tLista *pl);
void lista_percorre(const tLista *pl);
int lista_inclui(tLista *pl, int valor);
int lista_remove(tLista *pl, int valor);
void libera_lista(tLista *pl);
void exibe(int valor);
