typedef struct retangulo tRetangulo;
#include "TADPonto.h"
//cria, libera, area, exibe, getRetangulo
tRetangulo* ret_Cria(int x1,int y1, int x2, int y2);
void ret_libera(tRetangulo* ret);
int ret_area(tRetangulo* ret);
void ret_exibe(tRetangulo* ret);
char* ret_getRetangulo(tRetangulo* ret);
