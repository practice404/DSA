#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * head = NULL;

void create(int A[], int n)
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;

    struct Node * temp;
    struct Node * last = head;
    for(int i=1; i<n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = head;
        last->next = temp;
        last = temp;
    }
}

void display()
{
    struct Node * p = head;
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
    
}

void insert(int data, int pos)
{
    struct Node * p=head, *temp;
    if(pos == 0)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        if(head == NULL)
        {
            head = temp;
            head->next = head;
        }
        else
        {
            while(p->next != head)
            {
                p = p->next;
            }
            p->next = temp;
            temp->next = head;
            head = temp;
        }
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

void Delete(int pos)
{
    struct Node * p = head;
    if(pos == 0)
    {
        while(p->next != head)
            p = p->next;
        if(p == head) // if only 1 element is there
        {
            head->next = NULL;
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            head->next = NULL;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for(int i = 0; i < pos-1; i++)
        {
            p = p->next;
            printf("%d -- %d \n", p->data, i);
        }
        struct Node * temp = p->next;
        p->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
}

int main()
{
    int A[] = {1,2,3,4,6};
    create(A, 5);
    display();
    insert(5,4);
    display();
    Delete(5);
    display();
}