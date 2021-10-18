#include <stdio.h>
#include <stdlib.h>
#include "q5.h"

int main(){
    Tqueue *q = create_Q();
    int var;
    for(var=1; var<11; var++){
        insert(q, var);
    }
    printf("Valores invertidos da lista:\n");
    imprime_invertido(q);
    return 0;
}
