#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STACK USING LINKED LIST
typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *top = NULL;
int c = 0;
stack *lead = NULL;

void cre()
{
    if (c == 0)
    {
        stack *new = (stack *)malloc(sizeof(stack));
        new->data = -1;
        new->next = NULL;
        lead = new;
        return;
    }
    else
    {
        stack *new1 = (stack *)malloc(sizeof(stack));
        new1->data = -1;
        new1->next = lead;
        lead = new1;
    }
    return;
}

void push(int x, int n, FILE *st)
{
    if (c == n)
    {
        fprintf(st, "overflow\n");
        return;
    }
    else
    {
        fprintf(st, "pushed %d\n", x);
    }
    if (c == 0)
    {
        cre();
        top = lead;
        top->data = x;
        c++;
    }
    else
    {
        cre();
        top = lead;
        top->data = x;
        c++;
    }
}

void pop(FILE *st)
{
    if (c == 0)
    {
        fprintf(st, "underflow\n");
        return;
    }
    fprintf(st, "popped %d\n", top->data);
    top->data = -1;
    stack *temp = lead;
    temp = temp->next;
    free(top);
    lead = temp;
    top = temp;
    c--;
    return;
}

void sear(int n, FILE *st)
{
    stack *temp;
    temp = lead;
    int k = 0;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            k = 1;
            break;
        }
        else
        {
            temp = temp->next;
            continue;
        }
    }
    if (k == 1)
    {
        fprintf(st, "found %d\n", n);
    }
    else
    {
        fprintf(st, "not found %d\n", n);
    }
    return;
}

void dis(FILE *st)
{
    stack *temp;
    temp = lead;
    while (temp != NULL)
    {
        fprintf(st, "%d ", temp->data);
        temp = temp->next;
    }
    fprintf(st, "\n");
    return;
}

// QUEUE USING LINKED LIST
typedef struct qu
{
    int data;
    struct qu *next;
} qu;

qu *headqu = NULL;
qu *start = NULL;
qu *tail = NULL;
int ctr = 0;

void create(int n)
{
    qu *new = (qu *)malloc(sizeof(qu));
    new->data = -1;
    new->next = headqu;
    headqu = new;
    for (int i = 1; i < n; i++)
    {
        qu *new1 = (qu *)malloc(sizeof(qu));
        new1->data = -1;
        new1->next = headqu;
        headqu = new1;
    }
    start = headqu;
    tail = headqu;
    qu *temp = headqu;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = headqu;
    return;
}

void enqueue(int x, int n, FILE *q)
{
    if (ctr == n)
    {
        fprintf(q, "overflow\n");
        return;
    }
    else
    {
        fprintf(q, "enqueued %d\n", x);
    }
    tail->data = x;
    tail = tail->next;
    ctr++;

    return;
}

void dequeue(FILE *q)
{
    if (ctr == 0)
    {
        fprintf(q, "undeflow\n");
        return;
    }
    else
    {
        fprintf(q, "dequeued %d\n", start->data);
    }

    start->data = -1;
    start = start->next;
    ctr--;
    return;
}

int findqu(int n, FILE *q)
{
    qu *temp;
    temp = start;
    int k = 0;
    for (int i = 0; i < ctr; i++)
    {
        if (temp->data == n)
        {
            k = 1;
            break;
        }
        else
        {
            temp = temp->next;
            continue;
        }
    }
    if (k == 1)
    {
        fprintf(q, "found %d\n", n);
        return 0;
    }
    else
    {
        fprintf(q, "not found %d\n", n);
        return 0;
    }
}

void display(FILE *q)
{
    qu *temp;
    temp = start;
    for (int i = 0; i < ctr; i++)
    {
        fprintf(q, "%d ", temp->data);
        temp = temp->next;
    }
    fprintf(q, "\n");
}

// DOUBLY LINKED LIST

typedef struct nodedll
{
    int data;
    struct nodedll *next;
    struct nodedll *pre;
} nodedll;

nodedll *head = NULL;

void insert(int y, FILE *d)
{
    nodedll *new = (nodedll *)malloc(sizeof(struct nodedll));
    new->data = y;
    new->pre = NULL;
    new->next = NULL;
    fprintf(d, "inserted %d\n", y);
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        new->next = head;
        head->pre = new;
        head = new;
    }
}

int sea(int y)
{
    nodedll *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->data == y)
        {
            i = 1;
            break;
        }
        temp = temp->next;
    }
    if (i == 1)
    {
        return 1;
    }
    else
        return 0;
}

void delete (int y, FILE *d)
{
    nodedll *temp = head;
    int k = sea(y);
    if (head == NULL)
    {
        fprintf(d, "cannot delete %d\n", y);
        return;
    }
    if (k == 1)
    {
        fprintf(d, "deleted %d\n", y);
        while (temp->data != y)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            head = head->next;
            head->pre = NULL;
            free(temp);
        }
        else if (temp->next == NULL)
        {
            temp->pre->next = NULL;
            free(temp);
        }
        else
        {
            temp->next->pre = temp->pre;
            temp->pre->next = temp->next;
            free(temp);
        }
    }
    else
    {
        fprintf(d, "cannot delete %d\n", y);
    }
}

void find(int y, FILE *d)
{
    nodedll *temp = head;
    int k = 0;
    while (temp != NULL)
    {
        if (temp->data == y)
        {
            k = 1;
            break;
        }
        temp = temp->next;
    }
    if (k == 1)
    {
        fprintf(d, "found %d\n", y);
    }
    else
    {
        fprintf(d, "not found %d\n", y);
    }
}

void print(FILE *d)
{
    nodedll *temp = head;
    while (temp != NULL)
    {
        fprintf(d, "%d ", temp->data);
        temp = temp->next;
    }
    if (head == NULL)
    {
        fprintf(d, "");
    }
    fprintf(d, "\n");
    return;
}

// INT MAIN

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("File doesnt exist");
        return 0;
    }
    int n;
    n = atoi(argv[2]);
    char str[15];
    // stack file pointer
    FILE *st;
    st = fopen("stack.txt", "w");
    // queue file pointer
    FILE *q;
    q = fopen("queue.txt", "w");
    create(n);
    // dll file pointer
    FILE *d;
    d = fopen("dll.txt", "w");

    while (fgets(str, 15, fp))
    {
        char op = str[0];
        int m = strlen(str);
        char number[m - 2];
        for (int i = 0; i < m - 2; i++)
        {
            number[i] = str[i + 2];
        }
        int k = atoi(number);
        if (op == '+')
        {
            push(k, n, st);
            enqueue(k, n, q);
            insert(k, d);
        }
        else if (op == '-')
        {
            pop(st);
            dequeue(q);
            delete (k, d);
        }
        else if (op == '!')
        {
            dis(st);
            display(q);
            print(d);
        }
        else if (op == '?')
        {
            sear(k, st);
            findqu(k, q);
            find(k, d);
        }
    }

    fclose(st);
    fclose(q);
    fclose(d);
    fclose(fp);

    return 0;
}


void delete (){
    if(head==NULL){
        printf("Can't Delete node") 
    }
    if(head->next==head){
        node* temp=head;
        free(temp);
        head=NULL;
    }
    node* temp=head;
    node *pre=NULL;
    while(temp->next!=head){
        pre=temp;
        temp=temp->next;
    }
    pre->next=head;
    free(temp);
}















