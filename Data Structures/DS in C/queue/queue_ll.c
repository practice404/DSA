#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * front = NULL;
struct Node * rare = NULL;

void insert(int data)
{
    struct Node * t = (struct Node *) malloc(sizeof(struct Node));
    t->data  = data;
    if(rare == NULL)
    {
        front = rare = t;
        t->next = NULL;
    }
    else
    {
        t->next = rare->next; // NULL
        rare->next = t;
        rare = t;
    }
}

void Delete()
{
    struct Node * p = front;
    front = front->next;
    free(p);
}

void display()
{
    struct Node * p = front;
    while(p != rare)
    {
        printf("%d - ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    for(int i=1; i<=5; i++)
        insert(i);

    display();
    Delete();
    display();
}