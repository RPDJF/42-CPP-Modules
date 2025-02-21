#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <cctype>
# include <string>
# include <stdexcept>
# include <sstream>
# include <iostream>

class RPN {
	private:
		std::stack<int> nbs_;
		std::string args_;
		void handleNb_(std::string::const_iterator);
		void handleOperand_(std::string::const_iterator);
	public:
		RPN(const std::string&);
		RPN(const RPN&);
		const RPN& operator=(const RPN&);
		~RPN();
		void start();
		static bool isOperand(int);
		void printStack();
		int getTop() const;
};

#endif