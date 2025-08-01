#include "Point.h"
#include <cstring>

Point::Point(int xA, int yA, const char* labelA)
    : x(xA), y(yA)
{
    label = new char[strlen(labelA) + 1];
    std::strcpy(label, labelA);
}

Point::~Point()
{
    delete[] label;
}

Point::Point(const Point& src)
    : x(src.x), y(src.y)
{
    label = new char[strlen(src.label) + 1];
    std::strcpy(label, src.label);
}

Point& Point::operator=(const Point& rhs)
{
    if (this == &rhs)
        return *this;

    delete[] label;

    x = rhs.x;
    y = rhs.y;

    label = new char[strlen(rhs.label) + 1];
    std::strcpy(label, rhs.label);

    return *this;
}

int Point::getx() const
{
    return x;
}

int Point::gety() const
{
    return y;
}

char* Point::get_label() const
{
    return label;
}
