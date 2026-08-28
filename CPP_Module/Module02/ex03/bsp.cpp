#include "Point.hpp"

static Fixed cross_product(const Point& a, const Point& b, const Point& p) {
	return (b.getX() - a.getX()) * (p.getY() - a.getY())
			- (p.getX() - a.getX()) * (b.getY() - a.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed cr1 = cross_product(a, b, point);
	Fixed cr2 = cross_product(b, c, point);
	Fixed cr3 = cross_product(c, a, point);

	return (cr1 < 0 && cr2 < 0 && cr3 < 0) || (cr1 > 0 && cr2 > 0 && cr3 > 0);
}
