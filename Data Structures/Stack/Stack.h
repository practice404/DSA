#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include<iostream>
#include<cassert>

template <typename T>
class Stack
{
private:
	Node<T> * Top {nullptr};
	int size {};

public:
	Stack() = default;
	void display() const;
	~Stack();
	void push(T data);
	T pop();
	T top() const;
	bool isempty() const;
	bool isfull() const;
	

	//friend function
	friend std::ostream & operator << (std::ostream & os, const Stack<T> & source)
	{
		Node<T> * t = source.head;
		while(t != nullptr)
		{
			os<<t->data <<" - ";
			t = t->next; 
		}
		os << std::endl;
		return os;
	}

};

template <typename T>
void Stack<T>::display() const
{
	Node<T> * t = Top;
	while(t != nullptr)
	{
		std::cout << t->data <<" - ";
		t = t->next; 
	}
	std::cout<<std::endl;
}

template <typename T>
void Stack<T>::push(T data)
{
	if(Top == nullptr)
	{
		Top = new Node(data);
		return;
	}

	Node<T> * p;
	p = new Node(data);
	p->next = Top;
	Top = p;
	size++;
}

template <typename T>
T Stack<T>::pop()
{
	Node<T> *p = Top;
	Top = Top->next;
	p->next = nullptr;
	T value = p->data;
	delete p;
	size--;
	return value;
}

template <typename T>
T Stack<T>::top() const
{
	return Top->data;
}

template <typename T>
bool Stack<T>::isempty() const
{
	if(Top == nullptr)
		return true;
	return false;
}

template <typename T>
bool Stack<T>::isfull() const	
{
	Node<T> * p = new(std::nothrow) Node<T>();
	if(p == nullptr)
		return true;
	return false;
}

template <typename T>
Stack<T>::~Stack()
{
	if(Top != nullptr)
	{
		delete Top;
	}
}


#endif