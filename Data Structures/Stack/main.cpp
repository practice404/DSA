#include <iostream>
#include "Stack.h"

int main()
{
    sway::Stack<int> stack;
    for(int i = 1; i<=5; i++)
        stack.push(i);
    
    std::cout << stack;

    while(!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    std::cout << std::boolalpha;
    std::cout << "is stack empty: " << stack.empty();
}

