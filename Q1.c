#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "Q1.h"
#define n 10

int main(){
    setlocale(LC_ALL, "Portuguese");
	Tstack *z = create();
    int x, y;-
        printf("Entre com a quantidade de itens:\n");
        scanf("%d", &y);
        for(x=0;x<y;x++){
            push(z, x);
    }
    
        printf("\nA soma dos valores pares da lista é: %d\n", soma_par(z));
        clear(z);
        return 0;
}
