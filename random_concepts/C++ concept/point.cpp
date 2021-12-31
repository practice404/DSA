#include "point.h"

namespace Geom
{
    Point :: Point(double x, double y) : x{x}, y{y}
    {}
    Point :: Point() : Point(0.0, 0.0)
    {}
    Point :: ~Point()
    {}

}