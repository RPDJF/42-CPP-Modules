#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
	//	CONSTRUCTORS
		Point();
		Point(const float x, const float y);
		Point(const Point& assign);
	//	DECONSTRUCTORS
		~Point();
	//	OPERATOR OVERLOADS
	//		Assignment operator
		Point& operator=(Point& assign);
	//		Comparaisons
		bool operator==(const Point & assign) const;
	//	MEMBER FUNCTIONS
	float	getX() const;
	float	getY() const;
	static bool bsp(Point const a, Point const b, Point const c, Point const point);
	static Fixed area(Point const a, Point const b, Point const c);
	static bool isOnLine(const Point a, const Point b, const Point point);
};

#endif