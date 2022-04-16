#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * top = NULL;

int isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    return 0;
}

void push(int data)
{
    struct Node * t = (struct Node *) malloc(sizeof(struct Node));
    if(t == NULL)
    {
        printf("stack overflow\n");
        return;
    }
    t->data = data;
    t->next = top;
    top = t;
}

void pop()
{
    struct Node * p = top;
    if(p == NULL)
    {
        printf("stack underflow\n");
        return;
    }

    top = top->next;
    free(p);
}

int peek(int pos)
{
    struct Node * p = top;
    for(int i = 0; i < pos-1 && p; i++)
    {
        p = p->next;
    }
    if(p)
    {
        return p->data;
    }
    return -1;
}

void display()
{
    struct Node * p = top;
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main()
{
    push(1);
    push(2);
    push(3);

    display();
    printf("done\n\n");

    pop();
    display();
    printf("done\n\n");
}