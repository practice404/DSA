#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include<queue>
#include<vector>
#include<stack>

template <typename T>
class Tree
{
public:
	Node<T> * root = nullptr;

	void create_tree();
	void preorder(Node<T> * p);
	void inorder(Node<T> * p);
	void postorder(Node<T> * p);
	void iter_preorder();
	void iter_inorder();
	void iter_postorder();
	void levelorder();
};

template <typename T>
void Tree<T>::create_tree()
{
	Node<T> * p {nullptr}, *temp {nullptr};
	std::queue<Node<T> *> q;
	T x;
	// std::cout<<"Enter root node: "
	std::cin >> x;
	root = new Node<T>(x);
	q.push(root);

	while(!q.empty())
	{
		p = q.front();
		q.pop();

		// std::cout << "Enter value for"
		std::cin >> x;
		if(x != -1) // lchild
		{
			temp = new Node<T>(x);
			q.push(temp);
			p->lchild = temp;
		}
		std::cin >> x;
		if(x != -1) // rchild
		{
			temp = new Node<T>(x);
			q.push(temp);
			p->rchild = temp;
		}
	}
}

template <typename T>
void Tree<T>::preorder(Node<T> * p)
{
	if(p)
	{
		std::cout<< p->data << " ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

template <typename T>
void Tree<T>::inorder(Node<T> * p)
{
	if(p)
	{
		inorder(p->lchild);
		std::cout<< p->data << " ";
		inorder(p->rchild);
	}
}

template <typename T>
void Tree<T>::postorder(Node<T> * p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		std::cout<< p->data << " ";
	}
}

template <typename T>
void Tree<T>::iter_preorder()
{
	std::stack<Node<T> *> st;
	Node<T> * p = root;
	while(p || !st.empty())
	{
		if(p)
		{
			std::cout << p->data <<" ";
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
template <typename T>
void Tree<T>::iter_inorder()
{
	std::stack<Node<T> *> st;
	Node<T> * p = root;

	while(p || !st.empty())
	{
		if(p)
		{
			st.push(p);
			p = p->lchild;
		}
		else
		{
			p = st.top();
			st.pop();
			std::cout << p->data <<" ";
			p = p->rchild;
		}
	}
}

template <typename T>
void Tree<T>::iter_postorder()
{
	Node<T> * p = root;
	std::stack<long long int> st;

	while(p || !st.empty())
	{
		if(p)
		{
			st.push((long int)p);
			p = p->lchild;
		}
		else
		{
			long int t = st.top();
			st.pop();
			if(t > 0)
			{
				st.push(-t);
				p = ((Node<T> *)t)->rchild;
			}
			else
			{
				p = ((Node<T> *)(-1*t));
				std::cout << p->data <<" ";
				p = nullptr;
			}
		}
	}
}

template <typename T>
void Tree<T>::levelorder()
{
	std::queue<Node<T>*> q;
	Node<T> * p = root;
	while(p || !q.empty())
	{
		if(p)
		{
			std::cout <<p->data <<" ";
			if(p->lchild)
				q.push(p->lchild);
			if(p->rchild)
				q.push(p->rchild);
			p = nullptr;
		}
		else
		{
			p = q.front();
			q.pop();
		}
	}
}

#endif