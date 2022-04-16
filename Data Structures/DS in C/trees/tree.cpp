#include<iostream>
#include<queue>
#include<stack>

class Node
{
    public:
        Node() = default;
        int data;
        Node * lchild = nullptr;
        Node * rchild = nullptr;

};

class Tree
{
    public:
        Node * root;
        Tree()
        {
            root = nullptr;
        }
        void createTree();
        void Preorder(Node * p);
        void Preorder_iter(Node * p);
        void Postorder(Node * p);
        void Inorder(Node * p);
        void Inorder_iter(Node * p);
        void Levelorder(Node * p);
        void Height();
        int count_nodes(Node * p);
};

void Tree::Preorder(Node * p)
{
    if(p)
    {
        std::cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Preorder_iter(Node * p)
{
    std::stack<Node *> st;
    while(p != nullptr || !st.empty())
    {
        if(p != nullptr)
        {
            std::cout << p->data << " ";
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            p = p->rchild;
        }
    }
}

void Tree::Inorder_iter(Node * p)
{
    std::stack<Node *> st;
    while(p != nullptr || !st.empty())
    {
        if(p != nullptr)
        {
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            std::cout << p->data << " ";
            p = p->rchild;
        }
    }
}

void Tree::Inorder(Node * p)
{
    if(p)
    {
        Preorder(p->lchild);
        std::cout << p->data << " ";
        Preorder(p->rchild);
    }
}

void Tree::Postorder(Node * p)
{
    if(p)
    {
        Preorder(p->lchild);
        Preorder(p->rchild);
        std::cout << p->data << " ";
    }
}

void Tree::Levelorder(Node * p)
{
    std::queue<Node *> q;

    std::cout <<p->data << " ";
    q.push(p);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->lchild)
        {
            std::cout <<p->lchild->data << " ";
            q.push(p->lchild);
        }
        if(p->rchild)
        {
            std::cout <<p->rchild->data << " ";
            q.push(p->rchild);   
        }
    }
}


void Tree::createTree()
{
    std::queue<Node *> q;
    Node * p, *t;
    int x;
    std::cout << "Enter the root value: ";
    std::cin >> x;
    root = new Node();
    root->data = x;
    q.push(root);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        std::cout << "Enter left child of " << p->data << " : ";
        std::cin >> x;
        if(x != -1)
        {
            t = new Node();
            t->data = x;
            p->lchild = t;
            q.push(t);
        }

        std::cout << "Enter left child of " << p->data << " : ";
        std::cin >> x;
        if(x != -1)
        {
            t = new Node();
            t->data = x;
            p->rchild = t;
            q.push(t);
        }
    }
}

int Tree::count_nodes(Node * p)
{
    int x = 0, y = 0;
    if(p == nullptr)
        return 0;
    x = count_nodes(p->lchild);
    y = count_nodes(p->rchild);
    return x + y + 1;
}

int main()
{
   Tree tree;
   tree.createTree();
   tree.Levelorder(tree.root);
   std::cout<<std::endl << "The number of nodes are: " << tree.count_nodes(tree.root);
} 