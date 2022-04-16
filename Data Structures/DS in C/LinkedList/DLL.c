#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * prev;
    struct Node * next;
};

struct Node * head = NULL;

void create(int A[], int n)
{
    struct Node * t, *tail;
    head = (struct Node *) malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    head->prev = NULL;
    tail = head;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = tail;
        tail->next = t;
        t->next = NULL;
        tail = t;
    }
}

void display()
{
    struct Node * p = head;
    while(p != NULL)
    {
        printf("%d <-> ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insert(int data, int pos)
{
    struct Node * p = head, *t;
    if(pos == 0)
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = data;
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = data;
        for(int i = 0; i <= pos-1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

void Delete(int pos)
{
    struct Node * p = head;
    if(pos == 0)
    {
        head = head->next;
        if(head)
            head->prev = NULL;
        p->next = NULL;
        free(p);
    }
    else
    {
        for(int i = 0; i <= pos-1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        free(p);
    }
}

void reverse()
{
    struct Node * p = head;
    struct Node * temp;
    while(p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;

        if(p != NULL && p->next == NULL)
            head = p;
    }
}

int main()
{
    int A[] = {1,2,3,4,5};
    create(A,5);
    display();
    insert(0,3);
    display();
    Delete(4);
    display();
    reverse();
    display();
}