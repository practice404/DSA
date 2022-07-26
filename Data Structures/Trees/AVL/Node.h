#ifndef NODE_H
#define NODE_H

#include<iostream>

class Node
{
public:
	Node * lchild {nullptr};
	int data;
	int height; // including the node itself
	Node * rchild {nullptr};

	Node() = default;
	Node(int value);
	~Node() = default;
};


Node::Node(int value) : data(value)
{}
#endif