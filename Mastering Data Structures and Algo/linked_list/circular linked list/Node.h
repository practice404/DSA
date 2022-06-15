#ifndef NODE_H
#define NODE_H


template <typename T>
class Node
{
public:
	Node<T> * next {nullptr};
	T data {};

public:
	Node() = default;
	Node(T data);
	~Node();
};


template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr)
{}

template <typename T>
Node<T>::~Node()
{
	if(next != nullptr)
	{
		delete next;
	}
	// std::cout<<"memory released of: "<<data<<"\n";
}

#endif