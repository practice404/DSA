#ifndef NODE_H
#define NODE_H

#include<iostream>

class Node
{
public:
	Node * lchild {nullptr};
	int data;
	Node * rchild {nullptr};

	Node() = default;
	Node(int value);
	~Node();
};


Node::Node(int value) : data(value)
{}

Node::~Node()
{
	// std::cout << "memory of" << this->data <<" is released\n";
}

#endif