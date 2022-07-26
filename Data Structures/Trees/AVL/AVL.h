#ifndef AVL_H
#define AVL_H

#include "Node.h"
#include<stack>
#include<cassert>

class AVL
{
public:
	Node * root {nullptr};
	AVL() = default;
	~AVL() = default;
	Node * insert(Node * p, int key);
	void inorder();
	int balance_factor(Node * p);
	int node_height(Node * p);
	Node * LL_rotation(Node * p);
	Node * LR_rotation(Node * p);
	Node * RR_rotation(Node * p);
	Node * RL_rotation(Node * p);
};

void AVL::inorder()
{
	std::stack<Node *> st;
	Node * p = root;

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

	std::cout << std::endl;
}

int AVL::node_height(Node * p)
{
	int hl, hr;
	hl = (p && p->lchild) ? p->lchild->height : 0;
	hr = (p && p->rchild) ? p->rchild->height : 0;
	return (hl > hr) ? hl+1 : hr+1;
}

int AVL::balance_factor(Node * p)
{
	int hl, hr;
	hl = (p && p->lchild) ? p->lchild->height : 0;
	hr = (p && p->rchild) ? p->rchild->height : 0;
	return hl - hr;
}

Node * AVL::LL_rotation(Node * p)
{
	Node * pl = p->lchild;
	Node * plr = pl->rchild;

	pl->rchild = p;
	p->lchild = plr;

	p->height = node_height(p);
	pl->height = node_height(pl); // current root

	if(root == p)
		root = pl;

	return pl;
}

Node * AVL::LR_rotation(Node * p)
{
	Node * pl = p->lchild;
	Node * plr = pl->rchild;

	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;

	plr->lchild = pl;
	plr->rchild = p;

	pl->height = node_height(pl);
	p->height = node_height(p);
	plr->height = node_height(plr); // current root

	if(root == p)
		root = plr;

	return plr;
}

Node * AVL::RR_rotation(Node * p)
{
	Node * pr = p->rchild;
	Node * prl = pr->lchild;

	pr->lchild = p;
	p->rchild = prl;

	p->height = node_height(p);
	pr->height = node_height(pr); // current root

	if(root == p)
		root = pr;

	return pr;
}

Node * AVL::RL_rotation(Node * p)
{
	Node * pr = p->rchild;
	Node * prl = pr->lchild;

	pr->lchild = prl->rchild;
	p->rchild = prl->lchild;

	prl->rchild = pr;
	prl->lchild = p;

	pr->height = node_height(pr);
	p->height = node_height(p);
	prl->height = node_height(prl); // current root

	if(root == p)
		root = prl;

	return prl;
}

Node * AVL::insert(Node * p, int key)
{
	if(p == nullptr)
	{
		Node * t = new Node(key);
		t->height = 1;
		return t;
	}

	if(key < p->data)
		p->lchild = insert(p->lchild, key);
	else
		p->rchild = insert(p->rchild, key);
	p->height = node_height(p);

	int bf = balance_factor(p);
	if(bf == 2 && balance_factor(p->lchild) == 1)
		return LL_rotation(p);
	else if(bf == 2 && balance_factor(p->lchild) == -1)
		return LR_rotation(p);
	else if(bf == -2 && balance_factor(p->rchild) == -1)
		return RR_rotation(p);
	else if(bf == -2 && balance_factor(p->rchild) == 1)
		return RL_rotation(p);

	return p;
}

#endif