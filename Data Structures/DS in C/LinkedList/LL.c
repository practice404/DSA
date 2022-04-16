#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};
struct Node * head = NULL;
struct Node * tail = NULL;

void create(int A[], int n)
{
    struct Node * temp, *last;
    head = (struct Node *) malloc (sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node * temp)
{
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void recursive_display(struct Node * temp)
{
    if(temp == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d -> ", temp->data);
    recursive_display(temp->next);
}

int count(struct Node * p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }

    return c;
    
}

int sum(struct Node * p)
{
    if(p == NULL)
        return 0;
    return sum(p->next) + p->data;
}

int max(struct Node * p)
{
    if(p == NULL)
        return INT32_MIN;
    int x = max(p->next);
    return (x > p->data) ? x : p->data;
}

struct Node * search (struct Node * p, int key)
{
    if(p == NULL)
        return NULL;
    if(p -> data == key)
        return p;
    return search(p->next, key);
}

void insert(int data, int pos)
{
    struct Node * p, *temp;
    if(pos == 0)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    else if(pos > 0)
    {
        p = head;
        for(int i = 1; i <= pos-1 && p; i++)
        {
            p = p->next;
        }
        if(p)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
        }
        else
            printf("Index is not valid\n");
    }
}

void delete(int pos)
{
    struct Node * p = head;
    struct Node * q = NULL;
    if(pos == 1)
    {
        head = head->next;
        free(p);
    }
    else if(pos > 0)
    {
        for(int i = 0; i < pos-1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            free(p); 
        }
    }
}

void reverse()
{
    struct Node * p = head;
    struct Node * q = NULL;
    struct Node * r = NULL;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void recursive_reverse(struct Node * p, struct Node * q)
{
    if(p == NULL)
    {
        head = q;
        return;
    }

    recursive_reverse(p->next, p);
    p->next = q;
}

int main()
{
    for (size_t i = 0; i < 5; i++)
    {
        insert(i+1,i);
    }
    
    display(head);
    recursive_reverse(head, NULL);
    display(head);
}