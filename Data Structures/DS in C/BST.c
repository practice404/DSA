#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * lchild;
    struct Node * rchild;
};

struct Node * root = NULL;

void insert(struct Node * p, int data)
{
    struct Node * t, *r=NULL;
    if(p == NULL)
    {
        p = (struct Node *) malloc(sizeof(struct Node));
        p->data = data;
        p->lchild = p->rchild = NULL;
        root = p;
    }
    else
    {
        while(p != NULL)
        {
            r = p;
            if(p->data == data)
            {
                printf("key already exist\n");
                return;
            }
            else if(p->data > data)
                p = p->lchild;
            else
                p = p->rchild;
        }

        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = data;
        t->lchild = t->rchild = NULL;
        if(r->data > data)
            r->lchild = t;
        else
            r->rchild = t;
    }
}

struct Node * rinsert(struct Node * p, int data)
{
    if(p == NULL)
    {
        p = (struct Node *) malloc(sizeof(struct Node));
        p->data = data;
        p->lchild = p->rchild = NULL;
        if(root == NULL)
            root = p;
    }
    else
    {
        if(p->data < data)
        {
            p->rchild = rinsert(p->rchild, data);
        }
        else
            p->lchild = rinsert(p->lchild, data);
    }
}

struct Node * rsearch(struct Node * p, int key)
{
    while (p != NULL)
    {
        if(p->data == key)
            return p;
        else if(p->data < key)
            return rsearch(p->rchild, key);
        else
            return rsearch(p->lchild, key);
    }
    return NULL;
}

void inorder(struct Node * p)
{
    if(p == NULL)
        return;
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
}

int main()
{
    insert(root, 30);
    insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 50);
    insert(root, 40);
    insert(root, 60);
    rinsert(root, 80);

    inorder(root);

    // struct Node * p = rsearch(root, 20);
    // printf("\n%d", p->data);
}