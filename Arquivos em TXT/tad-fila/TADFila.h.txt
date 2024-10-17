// Definição do tipo nó (Nozin)
typedef struct no tNo;

// Definição do tipo fila (Fila)
typedef struct fila Fila;

// Função para criar uma fila
Fila *criaFila();

// Função para criar um no
tNo *criaNo();

// Função para enfilar
int enfila(Fila *f, int dado);

// Função para desenfilar
int desenfila(Fila *f, int *dado);

// Função para exibir os elementos da fila (só para teste)
void exibeFila(Fila *f);

// Verifica se a fila está vazia
int filaVazia(Fila *f);

// Apaga toda a fila
int liberaFila(Fila *f);
