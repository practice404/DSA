#include<iostream>
#include "point.h"
#include "line.h"

namespace Test
{
    int a = 10;
}
// annoymous namespace

namespace
{
    double give_double();
}

int a = 50;

// double give_double()
// {
//     return 10.9;
// }

// using nested namespaces
namespace Outer
{
    int a = 10;
    namespace Inner
    {
        int b = 40;
        void print_something()
        {
            std::cout<<a<<std::endl;
        }
    }

    void print_something()
    {
        std::cout << Inner::b << std::endl;
    }
}

int main(int argc, char ** args)
{
    int a = 30;
    /*
    Geom::Point p1(1,1);
    Geom::Point p2(5,5);
    // p1.print_info();
    // p2.print_info();

    Geom::Line l(p1,p2);
    l.print_info();
    */

   Outer::Inner::print_something();
   Outer::print_something();

   // namespace aliases
   namespace data = Outer::Inner;
   data::print_something();
   
}

namespace
{
    double give_double(){return 5.0;}
}

