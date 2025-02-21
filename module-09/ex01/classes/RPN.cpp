#include "./RPN.hpp"

RPN::RPN(const std::string& strRef): args_(strRef) {}
RPN::RPN(const RPN& copy): nbs_(copy.nbs_), args_(copy.args_) {}
RPN::~RPN() {}
const RPN& RPN::operator=(const RPN& assign) {
	if (this == &assign)
		return *this;
	this->args_ = assign.args_;
	this->nbs_ = assign.nbs_;
	return *this;
}

bool RPN::isOperand(int cstr) {
	if (cstr != '+'  && cstr != '-' && cstr != '*' && cstr != '/')
		return false;
	return true;
}

void RPN::handleNb_(std::string::const_iterator it) {
	char c[2] = {0};
	c[0] = *it;
	std::stringstream ss(c);
	int nb = 0;
	ss >> nb;
	this->nbs_.push(nb);
}

void RPN::handleOperand_(std::string::const_iterator it) {
	if (this->nbs_.size() < 2)
		throw std::runtime_error("not enough numbers on stack");
	int rslt;
	switch(*it) {
		case '+':
			rslt = this->nbs_.top();
			this->nbs_.pop();
			rslt += this->nbs_.top();
			this->nbs_.pop();
			this->nbs_.push(rslt);
			break;
		case '-':
			rslt = this->nbs_.top();
			this->nbs_.pop();
			rslt = this->nbs_.top() - rslt;
			this->nbs_.pop();
			this->nbs_.push(rslt);
			break;
		case '/':
			if (this->nbs_.top() == 0)
				throw std::runtime_error("undefined divid by 0");
			rslt = this->nbs_.top();
			this->nbs_.pop();
			rslt = this->nbs_.top() / rslt;
			this->nbs_.pop();
			this->nbs_.push(rslt);
			break;
		case '*':
			rslt = this->nbs_.top();
			this->nbs_.pop();
			rslt *= this->nbs_.top();
			this->nbs_.pop();
			this->nbs_.push(rslt);
			break;
	}
}

void RPN::start() {
	std::stringstream ss;
	bool hasArg = false;
	for(std::string::const_iterator it = this->args_.begin(); it != this->args_.end(); it++) {
		if(std::isspace(*it)) {
			hasArg = false;
			continue;
		}
		if (hasArg)
			throw std::runtime_error("not valid input => " + this->args_);
		if (!std::isdigit(*it) && !isOperand(*it)) {
			char c[2];
			c[0] = *it;
			c[1] = 0;
			throw std::runtime_error("not valid operand: " + std::string(c));
		}
		hasArg = true;
		if (std::isdigit(*it))
			handleNb_(it);
		else
			handleOperand_(it);
	}
	if (this->nbs_.size() > 1)
		throw std::runtime_error("not enough operand in input");
}

void RPN::printStack() {
	while (!this->nbs_.empty()) {
		std::cout << "> " << this->nbs_.top() << std::endl;
		this->nbs_.pop();
	}
}

int RPN::getTop() const {
	return this->nbs_.top();
}