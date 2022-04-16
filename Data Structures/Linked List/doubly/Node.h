#ifndef CODE_NODE
#define CODE_NODE

namespace sway
{
    template <typename T=int>
    class Node
    {
        private:
            T data;
            Node * next = nullptr;
            Node * prev = nullptr;

        public:
            Node() = default;
            Node(int data);
    };
}




#endif