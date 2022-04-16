#ifndef CODE_LIST
#define CODE_LIST

#include "Node.h"
#include <iostream>
#include <cassert>
#include <string>

namespace sway
{

    template <typename T = int>
    class List
    {
        private:
            std::shared_ptr<Node<T>> head;
            std::shared_ptr<Node<T>> tail;
            size_t list_size{0};

        public:
            // constructors
            List() = default;
            ~List();

            //getters
            std::shared_ptr<Node<T>> get_head() const;
            std::shared_ptr<Node<T>> get_tail() const;
            size_t size() const;

            // helper functions
            void push_front(const T & data);
            void push_back(const T & data);
            void insert(const T & data, size_t pos);
            bool search(const T & key) const;
            bool recursive_search(std::shared_ptr<Node<T>> & begin, const T & key) const;
            void pop_front();
            void pop_back();
            void delete_position(size_t pos);
            void reverse();

            // friend functions 
            friend std::ostream & operator << (std::ostream & out, const List & source)
            {
                std::shared_ptr<Node<T>> temp = source.head;
                while(temp != nullptr)
                {
                    out << temp->get_data() << " -> ";
                    temp = temp->get_next_node();
                }
                out << "null " << std::endl;
                temp.reset();
                return out;
            }

            friend std::istream & operator >> (std::istream & in, List & source)
            {
                size_t size;
                in >> size;
                while(size--)
                {
                    T item;
                    in >> item;
                    source.push_back(item);
                }
                return in;
            }
    };

    template <typename T>
    List<T>::~List()
    {
        head.reset();
        tail.reset();
    }

    template <typename T>
    std::shared_ptr<Node<T>> List<T>::get_head() const
    {
        return head;
    }

    template <typename T>
    std::shared_ptr<Node<T>> List<T>::get_tail() const
    {
        return tail;
    }

    template <typename T>
    size_t List<T>::size() const
    {
        return list_size;
    }

    template <typename T>
    void List<T>::push_front(const T & data)
    {
        std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>> (Node<T>(data));
        if(head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            temp->set_next_node(head);
            head = temp;
        }

        temp.reset();
        ++list_size;
    }

    template <typename T>
    void List<T>::push_back(const T & data)
    {
        std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>> (Node<T>(data));
        if(tail == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->set_next_node(temp);
            tail = temp;
        }

        temp.reset();
        ++list_size;
    }

    template <typename T>
    void List<T>::insert(const T & data, size_t pos)
    {
        if(pos == 0)
        {
            push_front(data);
            return;
        }
        int count = 0;
        std::shared_ptr<Node<T>> temp = head;
        std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>> (Node<T>(data));
        while(temp->get_next_node() != nullptr && count != pos-1)
        {
            temp = temp->get_next_node();
            count++;
        }
        if(temp->get_next_node() == nullptr)
            push_back(data);
        else
        {
            std::shared_ptr<Node<T>> prev = temp->get_next_node();
            new_node->set_next_node(prev);
            temp->set_next_node(new_node);
            ++list_size;
        }
        temp.reset();
        new_node.reset();
    }

    template <typename T>
    bool List<T>::search(const T & key) const
    {
        std::shared_ptr<Node<T>> temp = head;
        while(temp)
        { 
            if(temp->get_data() == key)
                return true;
            temp = temp->get_next_node();
        }
        return false;
    }

    template <typename T>
    bool List<T>::recursive_search(std::shared_ptr<Node<T>> & begin, const T & key) const
    {
        if(!begin)
            return false;
        if(begin->get_data() == key)
            return true;
        begin = begin->get_next_node();
        return recursive_search(begin, key);
    }

    template <typename T>
    void List<T>::pop_front()
    {
        std::shared_ptr<Node<T>> temp = head;
        head = head->get_next_node();
        temp->reset_next_node();
        temp.reset();
        --list_size;
    }

    template <typename T>
    void List<T>::pop_back()
    {
        std::shared_ptr<Node<T>> temp = head;
        while(temp->get_next_node()->get_next_node())
        {
            temp = temp->get_next_node();
        }
        tail = temp;
        std::shared_ptr<Node<T>> to_delete = temp->get_next_node();
        temp->reset_next_node();
        to_delete.reset();
        --list_size;
    }

    template <typename T>
    void List<T>::delete_position(size_t pos)
    {
        assert(pos < list_size);
        if(pos == 0)
        {
            pop_front();
            return;
        }
        else if(pos == list_size-1)
        {
            pop_back();
            return;
        }
        int count = 0;
        std::shared_ptr<Node<T>> temp = head;
        while(count != pos-1)
        {
            temp = temp->get_next_node();
            count++;
        }
        std::shared_ptr<Node<T>> to_delete = temp->get_next_node();
        std::shared_ptr<Node<T>> to_pass = to_delete->get_next_node();
        temp->set_next_node(to_pass);
        to_delete->reset_next_node();
        temp.reset();
        to_delete.reset();
        to_pass.reset();
        --list_size;
    }

    template <typename T>
    void List<T>::reverse()
    {
        std::shared_ptr<Node<T>> current = head;
        std::shared_ptr<Node<T>> prev;
        std::shared_ptr<Node<T>> next;

        while (current)
        {
            next = current->get_next_node();
            current->set_next_node(prev);

            prev = current;
            current = next;
        }

        tail = head;
        head = prev;
    }
}


#endif