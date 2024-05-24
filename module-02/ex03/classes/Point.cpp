#include "Point.hpp"

//	CONSTRUCTORS
Point::Point(): x(0), y(0) {}
Point::Point(const float x, const float y):  x(x), y(y) {}
Point::Point(const Point& assign): x(assign.x), y(assign.y) {}

//	DESTRUCTORS
Point::~Point() {}

//	OPERATOR OVERLOADS
//		Assignment operator
Point& Point::operator=(Point& assign) {
	return assign;
}

//		Comparaisons
bool Point::operator==(const Point& assign) const {
	if (this->x == assign.x && this->y == assign.y)
		return true;
	return false;
}

//	MEMBER FUNCTIONS
float Point::getX() const {
	return this->x.toFloat();
}

float Point::getY() const {
	return this->y.toFloat();
}

bool Point::isOnLine(const Point a, const Point b, const Point point) {
	if ((b.y - a.y) / (b.x - a.x) == (point.y - a.y) / (point.x - a.x))
		return true;
	return false;
}

Fixed Point::area(Point const a, Point const b, Point const c) {
	return (abs(((a.x * (b.y-c.y) + b.x * (c.y-a.y) + c.x * (a.y-b.y))/2).toFloat()));
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point) {
	if ( point == a || point == b || point == c
	|| a == b || a == c || b == c )
		return false;
	if (isOnLine(a, b, point) || isOnLine(b, c, point) || isOnLine(c, a, point))
		return false;
	Fixed triangleArea = area(a, b, c);
	Fixed pointAreas[3];
	Fixed totalPointArea = 0;

	pointAreas[0] = area(point, a, b);
	pointAreas[1] = area(point, a, c);
	pointAreas[2] = area(point, b, c);
	for (int i = 0; i < 3; i++)
		totalPointArea = totalPointArea + pointAreas[i];
	if (triangleArea == totalPointArea)
		return true;
	return false;
}