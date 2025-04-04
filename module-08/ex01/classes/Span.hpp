#ifndef SPAN_HPP
# define SPAN_HPP

# include <numeric>
# include <stdexcept>
# include <climits>
# include <vector>
# include <cstdlib>
# include <iostream>
# include <ctime>
# include <algorithm>

class Span {
	private:
		unsigned int size_;
		std::vector<int> arr_;
	public:
		Span(unsigned int alloc);
		Span(const Span&);
		const Span& operator=(const Span&);
		~Span();
		void addNumber(int);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void fill(std::vector<int>::iterator first, std::vector<int>::iterator last);
		std::vector<int>::iterator begin();
		std::vector<int>::iterator end();


};

#endif