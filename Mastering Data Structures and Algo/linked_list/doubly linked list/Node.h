#ifndef NODE_H
#define NODE_H


template <typename T>
class Node
{
public:
	Node<T> * prev {nullptr};
	T data {};
	Node<T> * next {nullptr};

public:
	Node() = default;
	Node(T data);
	~Node();
};


template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr), prev(nullptr)
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