#include "classes/Point.hpp"
#include <iostream>

int main() {
	if (Point::bsp(Point(3, 2), Point(6,3), Point(5, 6), Point(6, 4)))
		std::cout << "inside" << std::endl;
	else
		std::cout << "not inside" << std::endl;
	if (Point::bsp(Point(3, 2), Point(6,3), Point(5, 6), Point(3, 4)))
		std::cout << "inside" << std::endl;
	else
		std::cout << "not inside" << std::endl;
	if (Point::bsp(Point(3, 2), Point(6,3), Point(5, 6), Point(4, 3.99f)))
		std::cout << "inside" << std::endl;
	else
		std::cout << "not inside" << std::endl;
	if (Point::bsp(Point(3, 2), Point(6,3), Point(5, 6), Point(4, 3)))
		std::cout << "inside" << std::endl;
	else
		std::cout << "not inside" << std::endl;
	if (Point::bsp(Point(3, 2), Point(6,3), Point(5, 6), Point(5, 3)))
		std::cout << "inside" << std::endl;
	else
		std::cout << "not inside" << std::endl;
}