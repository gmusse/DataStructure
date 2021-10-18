#include <stdio.h>
#include <stdlib.h>
#include "q3.h"

int main (){
    Tqueue *list = create();
    Tcl *circ = create_circular();
    for (int var = 1; var < 11; var++) {
        insert(list, var);
    }
    printf("Lista circular\n");
    circ = gera_circular(list);
    print_circular(circ);

    clear(list);

    return 0;
}
