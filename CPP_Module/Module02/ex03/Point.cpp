#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed x1, const Fixed y1) : x(x1), y(y1) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point &other) {
	static_cast<void>(other);
	return *this;
}

Point::~Point() {}

const Fixed& Point::getX() const { return x; }

const Fixed& Point::getY() const { return y; }
