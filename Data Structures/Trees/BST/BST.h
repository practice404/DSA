#ifndef BST_H
#define BST_H

#include "Node.h"
#include<iostream>
#include<vector>
#include<stack>

class BST
{
public:
	Node * root = nullptr;
	BST() = default;
	~BST() = default;

	int height(Node* p);
	void insert(int key);
	void preorder();
	void postorder();
	void inorder();
	Node * in_pedecessor(Node * p);
	Node * in_successor(Node * p);
	Node * remove(Node * p, int key);
	void create_from_preorder(std::vector<int> arr);
};


void BST::insert(int key)
{
	Node * p = root;
	Node * r = nullptr;

	if(root == nullptr)
	{
		root = new Node(key);
		return;
	}

	while(p)
	{
		r = p;
		if(key < p->data)
			p = p->lchild;
		else if(key > p->data)
			p = p->rchild;
		else
			return;
	}
	p = new Node(key);
	if(p->data > r->data)
		r->rchild = p;
	else
		r->lchild = p;
}

void BST::preorder()
{
	Node * p = root;
	std::stack<Node *> st;

	while(p || !st.empty())
	{
		if(p)
		{
			st.push(p);
			std::cout << p->data <<" ";
			p = p->lchild;
		}
		else
		{
			p = st.top();
			st.pop();
			p = p->rchild;
		}
	}
	std::cout<<std::endl;
}

void BST::inorder()
{
	Node * p = root;
	std::stack<Node *> st;

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
	std::cout<<std::endl;
}

int BST::height(Node* p)
{
	int x, y;
	if(!p)
		return 0;
	x = height(p->lchild);
	y = height(p->rchild);
	return x > y ? x+1 : y+1;
}

Node * BST::in_pedecessor(Node * p)
{
	if(p == nullptr)
		return nullptr;
	else if(p->lchild == nullptr && p->rchild == nullptr)
		return p;
	else if(p->rchild == nullptr)
		return p;
	p = in_pedecessor(p->rchild);
	return p;
}

Node * BST::in_successor(Node * p)
{
	if(p == nullptr)
		return nullptr;
	else if(p->lchild == nullptr && p->rchild == nullptr)
		return p;
	else if(p->lchild == nullptr)
		return p;
	p = in_pedecessor(p->lchild);
	return p;
}
/*
- search for node
- find its inorder_predecessor or successor
- replace the data of node with predecessor/successor
- delete that predecessor/successor
- return nullptr to the parent node of deleted node (Segmentfault error otherwise)
*/
Node * BST::remove(Node * p, int key)
{
	if(!p)
		return nullptr;
	if(!p->lchild && !p->rchild)
	{
		if(p == root)
			root = nullptr;
		delete p;
		return nullptr;
	}

	if(key < p->data)
		p->lchild = remove(p->lchild, key);
	else if(key > p->data)
		p->rchild = remove(p->rchild, key);
	else
	{
		if (height(p->lchild) > height(p->rchild))
		{
			Node * q = in_successor(p->rchild);
			p->data = q->data;
			p->rchild = remove(p->rchild, q->data);
		}
		else
		{
			Node * q = in_pedecessor(p->lchild);
			p->data = q->data;
			p->lchild = remove(p->lchild, q->data);
		}
	}
	return p;
}

/*
- create the root node
- if arr[i] is less the p->data then
	- push p to stack
	- add lchild
	- move p to t
- else
	- if stack empty, then create rchild and move p = t
	- else, 
		- if arr[i] > p->data && arr[i] < st.top()->data
			- create rchild, move p to t
		- else, move p to st.top() and pop()
*/

void BST::create_from_preorder(std::vector<int> arr)
{
	std::stack<Node *> st;
	Node * t {nullptr}, *p{nullptr};
	int i = 0;

	this->root = new Node(arr[i]);
	p = root;
	i++;
	int n = arr.size();
	while(i < n)
	{
		if(arr[i] < p->data)
		{
			t = new Node(arr[i]);
			p->lchild = t;
			st.push(p);
			p = t;
			i++;
		}
		else
		{
			if(!st.empty())
			{
				if(arr[i] > p->data && arr[i] < st.top()->data)
				{
					t = new Node(arr[i]);
					p->rchild = t;
					p = t;
					i++;
				}
				else
				{
					p = st.top();
					st.pop();
				}
			}
			else
			{
				t = new Node(arr[i]);
				p->rchild = t;
				p = t;
				i++;
			}
		}
	}

}

#endif