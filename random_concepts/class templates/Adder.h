//
// Created by Swayam Singh on 29/01/22.
//

#ifndef CONCEPTS_ADDER_H
#define CONCEPTS_ADDER_H

#include <iostream>
#include<cstring>

template <typename T>
class Adder
{
    public:
        Adder();
        T add (T a, T b);
        void do_something(){
            std::cout << "doing something" << std::endl;
        }
};

template <typename T>
T Adder<T>::add(T a, T b)
{
    return a+b;
}

template<> inline
char * Adder<char *>::add(char * a, char * b)
{
    return strcat(a,b);
}

#endif //CONCEPTS_STREAM_H
