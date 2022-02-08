#ifndef CODE_Stack
#define CODE_Stack

#include "Node.h"
#include <iostream>
#include <cassert>
#include <string>

namespace sway
{

    template <typename T = int>
    class Stack
    {
        private:
            std::shared_ptr<Node<T>> head;

        public:
            // constructors
            Stack() = default;
            ~Stack();

            //getters
            std::shared_ptr<Node<T>> get_head() const;

            // helper functions
            void push(const T & data);
            void pop();
            bool empty() const;
            T top() const;

            // friend functions 
            friend std::ostream & operator << (std::ostream & out, const Stack & source)
            {
                std::shared_ptr<Node<T>> temp = source.head;
                while(temp != nullptr)
                {
                    out << temp->get_data() << " | ";
                    temp = temp->get_next_node();
                }
                out << std::endl;
                temp.reset();
                return out;
            }

            friend std::istream & operator >> (std::istream & in, Stack & source)
            {
                size_t size;
                in >> size;
                while(size--)
                {
                    T item;
                    in >> item;
                    source.push(item);
                }
                return in;
            }
    };

    template <typename T>
    Stack<T>::~Stack()
    {
        head.reset();
    }

    template <typename T>
    std::shared_ptr<Node<T>> Stack<T>::get_head() const
    {
        return head;
    }

    template <typename T>
    void Stack<T>::push(const T & data)
    {
        std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>> (Node<T>(data));
        if(head == nullptr)
        {
            head = temp;
        }
        else
        {
            temp->set_next_node(head);
            head = temp;
        }

        temp.reset();
    }

    template <typename T>
    void Stack<T>::pop()
    {
        std::shared_ptr<Node<T>> temp = head;
        head = head->get_next_node();
        temp->reset_next_node();
        temp.reset();
    }

    template <typename T>
    bool Stack<T>::empty() const
    {
        return !(static_cast<bool>(head)); // we can cast smart pointers as
    }

    template <typename T>
    T Stack<T>::top() const
    {
        return head->get_data();
    }
}


#endif