
typedef struct candidato tCandidato;

tCandidato* cdt_Cria(char* nome, int idade, int nota1, int nota2);

void cdt_libera(tCandidato* cdt);

void cdt_exibe(tCandidato* cdt);

int cdt_EhTestador(tCandidato* cdt, int n1, int n2, int limiar);

int cdt_compara(tCandidato* cdt1, tCandidato* cdt2);

char* cdt_getCandidato(tCandidato* cdt);
