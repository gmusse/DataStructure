typedef struct node_Q {
    int info;
    struct node_Q *next;
} Tnode_Q;

typedef struct queue {
    Tnode_Q *start, *end;
} Tqueue;

Tqueue *create_Q () {
    Tqueue *q = (Tqueue *) malloc (sizeof(Tqueue));
    q->start, q->end = NULL;
    return q;
}

void insert (Tqueue *q, int elem) {
    Tnode_Q *node_Q = (Tnode_Q *) malloc (sizeof(Tnode_Q));
    node_Q->info = elem;
    node_Q->next = NULL;

    if (q->end) {
        q->end->next = node_Q;
    }
    q->end = node_Q;
    if (!q->start) {
        q->start = node_Q;
    }
}

int empty_Q (Tqueue *q) {
  return !q->end;
}

int remove_node (Tqueue *q) {
    if (empty_Q (q)) {
        exit (1);
    }
    int value = q->start->info;
    Tnode_Q *p = q->start;
    q->start = q->start->next;
    if (!q->start) {
        q->end = NULL;
    }
    free (p);
    return value;
}

void clear_Q (Tqueue *q) {
        Tnode_Q *p = q->start, *aux;
    while (p) {
        aux = p;
        p = aux->next;
        free (aux);
    }
    free (q);
}

void print_queue (Tqueue *q) {
    Tqueue *p = create_Q();

    int value;
    while (!empty_Q(q)) {
        value = remove_node (q);
        printf ("%d  ", value);
        insert (p, value);
    }

    while (!empty_Q(p)) {
        value = remove_node (p);
        insert (q, value);
    }
     printf ("\n\n");

     clear_Q (p);
}

typedef struct node_S{
    int info;
    struct node_S *next;
}Tnode_S;
typedef struct stack{
    Tnode_S *top;
}Tstack;

Tstack *create_S () {
    Tstack *s = (Tstack *) malloc (sizeof(Tstack));
    s->top = NULL;
    return s;
}

int empty_S (Tstack *s) {
    return s->top == NULL;
}

void push(Tstack *s, int elem){
    Tnode_S *new_node = (Tnode_S *) malloc (sizeof(Tnode_S));
    new_node->info = elem;
    new_node->next = s->top;
    s->top = new_node;
}

int pop (Tstack *s){
    if(empty_S(s)){
        exit(1);
    }

    Tnode_S *t = s->top;

    s->top = s->top->next;
    int result = t->info;
    free(t);
    return result;
}

void clear_S(Tstack *s){
    Tnode_S *r = s->top, *t;
    while(r){
        t = r;
        r = r->next;
        free(t);
    }
    free(s);
}

void print_stack(Tstack *s){
    Tnode_S *q = s->top;
    while(q->next){
        printf("%d ", q->info);
        q = q->next;
    }
}

Tstack *fila2pilha(Tqueue *q){
    Tstack *s = create_S(), *aux_s = create_S();
    Tqueue *aux_q = create_Q();

    int hold;
    while(!empty_Q(q)){ 
        hold = remove_node(q);
        push(aux_s, hold);
        insert(aux_q, hold);
    }

    while(!empty_S(aux_s)){ 
        push(s, pop(aux_s));
    }

    while(!empty_Q(aux_q)){
        insert(q, remove_node(aux_q));
    }

    print_queue(q);
    return s;
}
