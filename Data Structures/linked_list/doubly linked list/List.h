#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include<iostream>
#include<cassert>

template <typename T>
class List
{
private:
	Node<T> * head {nullptr};
	Node<T> * tail {nullptr};

public:
	int size {0};
	List() = default;
	void create(T data[], size_t size);
	void display() const;
	void insert(int pos, T data);
	~List();
	void append(T data);
	void remove(int pos);
	void reverse();
	

	//friend function
	friend std::ostream & operator << (std::ostream & os, const List<T> & source)
	{
		Node<T> * t = source.head;
		while(t != nullptr)
		{
			os<<t->data <<" <-> ";
			t = t->next; 
		}
		os << std::endl;
		return os;
	}

	friend std::istream & operator >> (std::istream & in, List<T> & source)
	{
		int value;
		in >> value;
		source.append(value);
		return in;
	}

	T & operator [] (int pos);

};

template <typename T>
void List<T>::create(T data[], size_t size)
{
	head = new Node<T>(data[0]);
	tail = head;

	Node<T> * temp;

	for(size_t i=1; i < size; i++)
	{
		temp = new Node<T>(data[i]);
		temp->prev = tail;
		tail->next = temp;
		tail = temp;

	}
	this->size += size;
}

template <typename T>
void List<T>::display() const
{
	Node<T> * t = head;
	while(t != nullptr)
	{
		std::cout << t->data <<" <-> ";
		t = t->next; 
	}
	std::cout<<std::endl;
}

template <typename T>
void List<T>::insert(int pos, T data)
{
	assert(pos >= 0);
	Node<T> * p;
	Node<T> * t;
	if(pos == 0)
	{
		if(head == nullptr)
		{
			head = new Node<T>(data);
			tail = head;
		}
		else
		{
			p = new Node<T>(data);
			p->next = head;
			head->prev = p;
			head = p;
		}
	}
	else
	{
		p=head;
		for(int i=0; i<pos-1 && p; i++)
		{
			p = p->next;
		}

		t = new Node<T>(data);
		t->prev = p;
		t->next = p->next;
		p->next = t;
		if(pos != size)
			t->next->prev = t;
	}

	size++;
}

template <typename T>
void List<T>::append(T data)
{
	if(head == nullptr)
	{
		head = new Node(data);
		tail = head;
		return;
	}

	Node<T> * p;
	p = new Node(data);
	tail->next = p;
	p->prev = tail;
	tail = p;
	size++;
}

template <typename T>
void List<T>::remove(int pos)
{
	assert(pos >= 0 && pos <= size);
	Node<T> *p, *q;
	assert(pos >= 0);
	if(pos == 0)
	{
		p = head;
		head = head->next;
		p->next = nullptr;
		head->prev = nullptr;
		delete p;
	}
	else
	{
		p = head;
		for(int i=0; i<pos && p; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		if(pos == size)
			p->next->prev = q;
		p->next = nullptr;
		p->prev = nullptr;
		delete p;
	}
	size--;
}

template <typename T>
void List<T>::reverse()
{
	Node<T>*p;
	p = head;
	Node<T> * temp;
	while(p)
	{
		temp = p->prev;
		p->prev = p->next;
		p->next = temp;

		if(p->next == nullptr)
			std::swap(head, tail);

		p = p->prev; // since pointers are swapped;
	}

}

template <typename T>
T & List<T>::operator [] (int pos)
{
	assert(pos >= 0);
	int i = 0;
	Node<T> * p = head;
	while(i != pos && p)
	{
		p = p->next;
		i++;
	}
	assert(p != nullptr);
	return p->data;
}

template <typename T>
List<T>::~List()
{
	if(head != nullptr)
	{
		delete head;
	}
}


#endif