#ifndef CODE_NODE
#define CODE_NODE

#include <memory>
namespace sway
{

    template <typename T = int >
    class Node
    {
        private:
            T data;
            std::shared_ptr<Node<T>> next_node;

        public:
            // constructors
            Node() = default;
            Node(T item);
            // destructor
            ~Node();
            // getters
            T get_data() const;
            std::shared_ptr<Node<T>> get_next_node() const;
            //setters
            void set_data(T & item);
            void set_next_node(std::shared_ptr<Node<T>> & next);
            void reset_next_node();

    };
    template <typename T>
    Node<T>::Node(T item) : data(item)
    {}

    template <typename T>
    Node<T>::~Node()
    {
        this->next_node.reset();
    }

    template <typename T>
    T Node<T>::get_data() const
    {
        return this->data;
    }

    template <typename T>
    std::shared_ptr<Node<T>> Node<T>::get_next_node() const
    {
        return this->next_node;
    }

    template <typename T>
    void Node<T>::set_data(T & item)
    {
        this->data = item;
    }

    template <typename T>
    void Node<T>::set_next_node(std::shared_ptr<Node<T>> & next)
    {
        this->next_node = next;
    }

    template <typename T>
    void Node<T>::reset_next_node()
    {
        this->next_node.reset();
    }
}

#endif