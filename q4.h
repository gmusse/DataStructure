#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
  int info;
    struct node *next;
} Tnode;

typedef struct queue {
    Tnode *start, *end;
} Tqueue;

Tqueue *create () {
    Tqueue *x = (Tqueue *) malloc (sizeof(Tqueue));
    x->start, x->end = NULL;
    return x;
}

int empty (Tqueue *x) {
    return !x->end;
}

void insert (Tqueue *x, int elem) {
    Tnode *node = (Tnode *) malloc (sizeof(Tnode));
    node->info = elem;
    node->next = NULL;

    if (x->end) {
        x->end->next = node;
    }

    x->end = node;

    if (!x->start) {
        x->start = node;
    }
}

int remove_node (Tqueue *x) {
    if (empty(x)) {
        exit (1);
    }
    int value = x->start->info;
    Tnode *p = x->start;
    x->start = x->start->next;
    if (!x->start) {
        x->end = NULL;
    }
    free (p);
    return value;
}

void clear (Tqueue *x) {
  Tnode *p = x->start, *aux;

  while (p) {
    aux = p;
    p = aux->next;
    free (aux);
  }
  free (x);
}

void print_queue (Tqueue *x) {
  Tqueue *p;
  p = create();
  int value;

  while (!empty(x)) {
    value = remove_node (x);
    printf ("%d  ", value);
    insert (p, value);
  }

  while (!empty(p)) {
    value = remove_node (p);
    insert (x, value);
  }
  printf ("\n\n");

  clear (p);
}

typedef struct circular {
    int info;
    struct circular *next;
} Tcl;

Tcl *create_circular () {
    return NULL;
}

Tcl *insert_circular (Tcl *l, int elem) {
    Tcl *new_elem = (Tcl *) malloc (sizeof (Tcl));
    new_elem->info = elem;

    if (!l) { 
        new_elem->next = new_elem; 
        return new_elem;
    }

    new_elem->next = l->next;
    l->next = new_elem;
    return l;
}

void clear_circular (Tcl *l) {
    if (l) {
        Tcl *p = l->next;
        while (p != l) {
        Tcl *x = p;
        p = p->next;
        free (x);
        }
        free (p);
    }
}

void print_circular (Tcl *l) {
    if (l) {
        printf ("%d\n", l->info);
        Tcl *p = l->next;
        while (p != l) {
        printf ("%d\n", p->info);
        p = p->next;
        }
    }
}

Tcl *gera_circular (Tqueue *x){
    Tcl *c = create_circular();
    Tqueue *x_aux = create();

    while (!empty(x)) {
        int hold = remove_node(x);
        insert(x_aux, hold);
        c = insert_circular(c, hold);
    }
    
    while(!empty(x_aux)){
        insert(x, remove_node(x_aux));
    }
    clear(x_aux);
    return c;
}

Tqueue *mega_sena (Tqueue *x){
    Tqueue *sorted = create(), *aux_q = create();
    int var, random;
    time_t t;
    srand((unsigned) time(&t));

    for(var=0; var<6; var++){
        random = rand() %60; 
        while(!empty(x)){
            int hold = remove_node(x);
            if(hold == random){ 
                insert(sorted, hold);
            }else{
                insert(aux_q, hold);
            }
        }
        while(!empty(aux_q)){
            insert(x, remove_node(aux_q));
        }
    }
    clear(aux_q);
    return sorted;
}

