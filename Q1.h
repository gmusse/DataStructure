#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct node{
    int info;
    struct node *next;
}Tnode;

typedef struct stack{
    Tnode *top;
}Tstack;

Tstack *create () {
    Tstack *z = (Tstack *) malloc (sizeof(Tstack));
    z->top = NULL;
    return z;
}

void push(Tstack *z, int elem){
    Tnode *new_node = (Tnode *) malloc (sizeof(Tnode));
    new_node->info = elem;
    new_node->next = z->top;
    z->top = new_node;
}

int pop (Tstack *z){
    Tnode *t = z->top;

    z->top = z->top->next;
    int result = t->info;
    free(t);
    return result;
}

int soma_par(Tstack *par){
    Tnode *aux = par->top;
    int x=0, pares=0;
    while(aux->info){
        if(!(aux->info % 2)){ 
            printf("Total adicionado: %d\n", aux->info);
            pares += aux->info;
        }
        aux = aux->next;
    }
    return pares;
}

void clear(Tstack *z){
    Tnode *r = z->top, *t;
    while(r){
        t = r;
        r = r->next;
        free(t);
    }
    free(z);
}

void print_stack(Tstack *z){
    Tnode *q = z->top;
    while(q->next){
        printf("%d ", q->info);
        q = q->next;
    }
}
