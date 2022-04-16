#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct Stack * st)
{
    if(st->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack * st)
{
    if(st->top == st->size-1)
        return 1;
    return 0;
}

void push(struct Stack * st, int data)
{
    if(st->top == st->size-1)
    {
        printf("stack overflow\n");
        return;
    }

    st->top++;
    st->arr[st->top] = data;
}

int pop(struct Stack *st)
{
    if(st->top == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    int x = st->arr[st->top];
    st->top--;
    return x;
}

int peek(struct Stack * st, int pos)
{
    int x = -1;
    if(st->top - pos + 1 < 0)
    {
        printf("position is invalid\n");
    }
    else
    {
        x = st->arr[st->top - pos + 1];
    }

    return x;
}

void display(struct Stack st)
{
    while(st.top != -1)
    {
        printf("%d\n", st.arr[st.top]);
        st.top--;
    }
}

int main()
{
    struct Stack st;
    printf("Enter the size of stack: ");
    scanf("%d", &st.size);
    st.arr = (int *)malloc(st.size*sizeof(int));
    st.top = -1;
    push(&st, 1);
    push(&st, 2);
    display(st);
    printf("done\n\n");
    push(&st, 3);
    display(st);
    printf("done\n\n");
    pop(&st);
    display(st);
    printf("done\n\n");
}