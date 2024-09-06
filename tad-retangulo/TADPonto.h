/* Tipo exportado */
typedef struct ponto Ponto;

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y);

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p);

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y);

/* Função acessa X - Retorna o valor da coordenada X de um ponto */
void pto_acessaX(Ponto* p, float* x);

/* Função acessa Y - Retorna o valor da coordenada Y de um ponto */
void pto_acessaY(Ponto* p, float* y);

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y);

/* Função atribui X - Atribui novo valor à coordenada X de um ponto */
void pto_atribuiX(Ponto* p, float x);

/* Função atribui Y - Atribui novo valor à coordenada X de um ponto */
void pto_atribuiY(Ponto* p, float y);

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2);

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p);

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p);

int pto_compara(Ponto* pt1,Ponto* pt2);
/* Função compara -recebe dois pontos e retorna:
0 se os pontos são iguais
valor negativo se o ponto 1 1 está mais próximo da origem que o pto 2
valor positivo,  cc*/


/* Função pto_soma, recebe dois pontos e retorna um
novo ponto, com as soma das coordenadas */
Ponto* pto_soma(Ponto * p1, Ponto* p2);

/* Função copia - Recebe um ponto e cria um novo ponto com as coordenadas do primeiro*/
Ponto* pto_copia(Ponto *p);

/* Função desloca - Recebe um n1 e um n2 e desloca x n1 vezes e y n2 vezes */
void pto_desloca(Ponto* p, float* x, float* y, int n1, int n2);

/* Função desloca X - Recebe um n1 desloca x n1 vezes */
void pto_deslocaX(Ponto* p, float* x, int n1);

/* Função descola Y - Recebe um n1 desloca y n1 vezes */
void pto_deslocaY(Ponto* p, float* y, int n2);
