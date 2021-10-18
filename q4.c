#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "q4.h"
#define size 6

int main(){
    setlocale(LC_ALL, "Portuguese");
	Tqueue *x = create();
    int num [60];

    for(int var=0;var<60;var++){
        insert(x, var+1);
    }
    printf("Os valores sorteados foram: \n");
    print_queue(mega_sena(x)); 

    printf("\nExcluindo os valores sorteados temos: \n");
    print_queue(x);
    clear(x);
    return 0;
}
