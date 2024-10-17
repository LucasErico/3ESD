// Definição do tipo nó (Nozin)
typedef struct no tNo;

// Definição do tipo pilha (Pilha)
typedef struct pilha Pilha;

// Função para criar uma pilha
Pilha *criaPilha();

// Função para criar um no
tNo *criaNo();

// Função para empilhar (push)
int push(Pilha *p, int dado);

// Função para desempilhar (pop)
int pop(Pilha *p, int *dado);

// Função para exibir os elementos da pilha (só para teste)
void exibePilha(Pilha *p);

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *p);
