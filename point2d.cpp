#include "point2d.h"
#include "math.h"
#include "logger.h"
#include <cfloat>
#include <stdexcept>
#include <cassert>

Point2D::Point2D()
{

}

Point2D::~Point2D()
{

}

Point2D::Point2D(double x_, double y_)
{
    _x = x_;
    _y = y_;
}

Point2D::Point2D(const Point2D &source_)
{
    _x = source_._x;
    _y = source_._y;
}

Point2D::Point2D(std::vector<double> xy_)
{
    if(xy_.size() < 2)
    {
        throw std::invalid_argument("xy_");
    }
    _x = xy_[0];
    _y = xy_[1];
}

Point2D Point2D::operator=(const Point2D &source_)
{
    _x = source_._x;
    _y = source_._y;

    return *this;
}

bool Point2D::operator==(const Point2D &source_)
{
    if(( fabs(source_._x - _x) < DBL_EPSILON) &&
            ( fabs(source_._y - _y) < DBL_EPSILON))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Point2D Point2D::operator-(const Point2D &pt2_) const
{
    return Point2D(_x - pt2_._x, _y - pt2_._y);
}

Point2D Point2D::operator-(const double &value) const
{
    return Point2D(_x - value, _y - value);
}

Point2D Point2D::operator+(const Point2D &pt2_) const
{
    return Point2D(_x + pt2_._x, _y + pt2_._y);
}

Point2D Point2D::operator+(const double &value) const
{
    return Point2D(_x + value, _y + value);
}

Point2D Point2D::operator*(const Point2D &pt2_) const
{
    return Point2D(_x * pt2_._x, _y * pt2_._y);
}

Point2D Point2D::operator*(const double &value) const
{
    return Point2D(_x * value, _y * value);
}

Point2D Point2D::operator/(const Point2D &pt2_) const
{
    return Point2D(_x / pt2_._x, _y / pt2_._y);
}

Point2D Point2D::operator/(const double &value) const
{
    return Point2D(_x / value, _y / value);
}


void Point2D::inverserXY()
{
    double tmp = _x;
    _x = _y;
    _y = tmp;
}

void Point2D::test()
{
    Point2D p1(-1.0, -1.0);
    Point2D p2(2.0, 3.0);
    Point2D p3(-1.0, -1.0);
    Point2D p4(p1);
    Point2D p5 = p4;

    assert(p1._x == -1.0);
    assert(p1._x == -1.0 && p1._y ==-1.0);
    assert(p4._x == -1.0 && p4._y ==-1.0);
    assert(p5._x == -1.0 && p5._y ==-1.0);
    assert( p1 == p4);
    assert( p1 + p2 == Point2D(1.0,2.0));
    assert( p1 - p2 == Point2D(-3.0,-4.0));
    assert( p1 * p2 == Point2D(-2.0,-3.0));
    assert( p1 / p2 == Point2D(-0.5,-1.0/3.0));
    p2.inverserXY();
    assert(p2 == Point2D(3.0,2.0));

    LOG_INFO("Unit tests on Point2D class passed successfully");
}

