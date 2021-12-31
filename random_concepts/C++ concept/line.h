#ifndef LINE_H
#define LINE_H

#include "point.h"

namespace Geom
{
    class Line
    {
        private:
            Point p1{};
            Point p2{};

        public:
            Line(const Point & p1, const Point & p2);
            void print_info()
            {
                std::cout << "Line from: ";
                p1.print_info();
                std::cout<< "to: ";
                p2.print_info();
            }
    };
} // namespace Geom


#endif