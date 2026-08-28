#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();
	public:
		const Fixed& getX() const;
		const Fixed& getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
