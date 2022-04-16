// using array

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rare;
    int * arr;
};

struct Queue q;

int isEmpty()
{
    if(q.front == q.rare)
        return 1;
    return 0;
}

void insert(int data)
{
    if((q.rare+1)%q.size != q.front)
    {
        q.rare = (q.rare+1)%q.size;
        q.arr[q.rare] = data;
    }
    else
        printf("queue is full\n");
}

void Delete()
{
    if(!isEmpty())
        q.front = (q.front+1)%q.size;
    else
        printf("Queue is already empty\n");
}

void display()
{
    for(int i = q.front+1; i!=(q.rare+1)%q.size; i = (i+1)%q.size)
    {
        printf("%d - ", q.arr[i]);
    }
    printf("\n");
}

int main()
{
    q.size = 7;
    q.arr = (int *)malloc(q.size * sizeof(int));
    q.front = q.rare = 0; // for circular queue

    for(int i = 1; i<=q.size-1; i++)
    {
        insert(i);
    }
    display();
    Delete();
    Delete();
    display();
    insert(7);
    insert(8);
    display();
    

}