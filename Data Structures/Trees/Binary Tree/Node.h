#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
	Node<T> * lchild = nullptr;
	T data;
	Node<T> * rchild = nullptr;
	
	Node() = default;
	Node(T value);
	T get_data();
	~Node();
};

template <typename T>
Node<T>::Node(T value): data(value)
{}

template <typename T>
Node<T>::~Node()
{
	this->rchild = nullptr;
	this->rchild = nullptr;
	// std::cout<<"\nmemory for "<<this->data<<" is released";
}

#endif