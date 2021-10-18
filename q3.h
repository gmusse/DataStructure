#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int info;
    struct node *next;
} Tnode;

typedef struct queue {
    Tnode *start, *end;
} Tqueue;

Tqueue *create () {
    Tqueue *q = (Tqueue *) malloc (sizeof(Tqueue));
    q->start, q->end = NULL;
    return q;
}

int empty (Tqueue *q) {
    return !q->end;
}

void insert (Tqueue *q, int elem) {
    Tnode *node = (Tnode *) malloc (sizeof(Tnode));
    node->info = elem;
    node->next = NULL;

    if (q->end) {
        q->end->next = node;
    }

    q->end = node;

    if (!q->start) {
        q->start = node;
    }
}

int remove_node (Tqueue *q) {
    if (empty(q)) {
        exit (1);
    }
    int value = q->start->info;
    Tnode *p = q->start;
    q->start = q->start->next;
    if (!q->start) {
        q->end = NULL;
    }
    free (p);
    return value;
}

void clear (Tqueue *q) {
  Tnode *p = q->start, *aux;

  while (p) {
    aux = p;
    p = aux->next;
    free (aux);
  }
  free (q);
}

void print_queue (Tqueue *q) {
  Tqueue *p;
  p = create();
  int value;

  while (!empty(q)) {
    value = remove_node (q);
    printf ("%d  ", value);
    insert (p, value);
  }

  while (!empty(p)) {
    value = remove_node (p);
    insert (q, value);
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
        Tcl *q = p;
        p = p->next;
        free (q);
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

Tcl *search_circular (Tcl *l, int elem) {
    if (!l) {
        return NULL;
    }
    if (l->info == elem) {
        return l;
    }

    Tcl *p = l->next;
    while (p != l && p->info != elem) {
        p = p->next;
    }

    if (p == l) {
        return NULL;
    }

    return p;
}

Tcl *remove_circular (Tcl *l, int elem) {
    if (!l) {
        printf ("Lista inexistente ou vazia\n");
        return NULL;
    }

    if (l->info == elem && l->next == l) {
        printf ("Elemento %d removido\n", l->info);
        free (l);
        return NULL;
    }

    Tcl *p = l->next;
    Tcl *previous = l;

    while (p != l && p->info != elem) {
        previous = p;
        p = p->next;
    }

    if (p == l && p->info != elem) { // voltamos ao início da lista e não encontramos o elemento
        printf ("Elemento removido n�o encontrado\n");
        return l;
    }

    if (p == l) { // o elemento a ser removido é o mesmo do início da lista
        l = l->next;
    }

    previous->next = p->next;
    printf ("Elemento %d removido\n", p->info);
    free (p);
    return l;
}

void print_2_laps (Tcl *l) {
    Tcl *p = l->next;
    int laps = 1;

    while (laps <= 2) {
        printf ("> %d\n", p->info);
        p = p->next;
        if (p == l->next) {
        printf (">>>>>>>>>> VOLTA %d COMPLETA\n", laps);
        laps++;
        }
    }
}

Tcl *gera_circular (Tqueue *q){
    Tcl *c = create_circular();
    Tqueue *q_aux = create();

    while (!empty(q)) {
        int hold = remove_node(q);
        insert(q_aux, hold);
        c = insert_circular(c, hold);
    }
    
    while(!empty(q_aux)){
        insert(q, remove_node(q_aux));
    }
    clear(q_aux);
    return c;
}
