#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "q2.h"
int main(){
    setlocale(LC_ALL, "Portuguese");
	Tqueue *q = create_Q();
    int var;
    for(var=1;var<11; var++){
        insert(q, var);
    }
    Tstack *s = fila2pilha(q);
    printf("Valores de saída na ordem:\n");
    print_stack(s);
    return 0;
}
