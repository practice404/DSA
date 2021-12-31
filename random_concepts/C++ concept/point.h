#ifndef POINT_H
#define POINT_H

#include<iostream>

namespace Geom
{
    class Point
    {
        private:
            double x,y;
        public:
            Point(double x, double y);
            Point();
            ~Point();
            void print_info()
            {
                std::cout<< "Point [x: "<<this->x<<", "<<"y: "<<this->y<<"]"<< std::endl;
            }
    };
} // namespace Geom


#endif