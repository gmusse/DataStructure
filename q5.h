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

typedef struct node{
    int info;
    struct node *next;
}Tnode;

typedef struct stack{
    Tnode *top;
}Tstack;

Tstack *create () {
    Tstack *s = (Tstack *) malloc (sizeof(Tstack));
    s->top = NULL;
    return s;
}

void push(Tstack *s, int elem){
    Tnode *new_node = (Tnode *) malloc (sizeof(Tnode));
    new_node->info = elem;
    new_node->next = s->top;
    s->top = new_node;
}

int pop (Tstack *s){
    Tnode *t = s->top;

    s->top = s->top->next;
    int result = t->info;
    free(t);
    return result;
}

int empty_s (Tstack *s) {
    return s->top == NULL;
}

void clear(Tstack *s){
    Tnode *r = s->top, *t;
    while(r){
        t = r;
        r = r->next;
        free(t);
    }
    free(s);
}

void print_stack (Tstack *s) {
    Tstack *t = create();
    int elem, counter = 1;

    while (!empty_s(s)) {
        push (t, pop (s));
    }

    while (!empty_s (t)) {
        elem = pop (t);
        printf ("Elemento %d armazenado na pilha = %d\n", counter, elem);
        push (s, elem);
        counter ++;
    }
    clear(t);
}

void imprime_invertido(Tqueue *q){
    Tstack *s = create();

    while(!empty_Q(q)){
        int hold = remove_node(q);
        push(s, hold);
    }

    while(!empty_s(s)){
        insert(q, pop(s));
    }
    
    clear(s);

    print_queue(q);
}
