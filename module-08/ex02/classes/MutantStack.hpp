#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stdexcept>
# include <climits>
# include <iostream>
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
	private:

	public:
		MutantStack() {}
		MutantStack(const MutantStack<T, Container>& copy): std::stack<T, Container>(copy) {
			*this = copy;
		}	
		const MutantStack<T, Container>& operator=(const MutantStack<T, Container>& assign) {
			if (this == &assign)
				return *this;
			std::stack<T, Container>::operator=(assign);
			return *this;
		}
		~MutantStack() {}
		typedef typename Container::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

#endif