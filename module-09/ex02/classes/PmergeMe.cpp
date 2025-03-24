# include "./PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv, int argc):
	step_(1),
	level_(1),
	base_(2) {
	this->init_(argv, argc);
}

PmergeMe::PmergeMe(const PmergeMe& copy):
	sequence_(copy.sequence_),
	main_(copy.main_),
	pend_(copy.pend_),
	out_(copy.out_),
	step_(copy.step_),
	level_(copy.level_),
	base_(copy.base_) {}

PmergeMe::~PmergeMe() { this->sequence_.clear(); }

PmergeMe& PmergeMe::operator=(const PmergeMe& assign) {
	if (this == &assign)
		return *this;
	this->sequence_ = assign.sequence_;
	this->main_ = assign.main_;
	this->pend_ = assign.pend_;
	this->out_ = assign.out_;
	this->step_ = assign.step_;
	this->level_ = assign.level_;
	this->base_ = assign.base_;
	return *this;
}

void PmergeMe::init_(char **argv, int argc) {
	std::stringstream ss;
	int num;
	this->sequence_.reserve(argc - 1);
	for(int i = 1; i < argc; i++) {
		ss.clear();
		ss.str(argv[i]);
		ss >> num;
		this->sequence_.push_back(num);
	}
}

void PmergeMe::pairSwap_(unsigned int a1) {
	for(unsigned int i = 0; i < this->base_ / 2; i++)
		swap(this->sequence_[a1 + i], this->sequence_[a1 + i + this->base_ / 2]);
}

void PmergeMe::mergeSort_() {
	#if DEBUG
	std::cout << C_YELLOW << "[Merge sort]" << C_RESET << std::endl <<"Recursion level " << this->level_ << " base " << this->base_ << std::endl;
	#endif
	// base is always 2^level
	for(size_t i = 0; i + this->base_ - 1 < this->sequence_.size(); i += this->base_)
		if (this->isGreater(this->sequence_[i + this->base_ / 2 - 1], this->sequence_[ i + this->base_ - 1]))
			pairSwap_(i);
	#if DEBUG
	this->printSequence();
	std::cout << std::endl;
	#endif
	if (this->base_ * 2 <= this->sequence_.size()) {
		this->level_++;
		this->base_ *= 2;
		this->mergeSort_();
	} else {
		this->step_ = 2;
	}
}

void PmergeMe::elementMove(std::vector<unsigned int>& src, std::vector<unsigned int>& dest, size_t idx, size_t size) {
	if (size == 0) return;
	else if (idx >= src.size()) {
		throw std::out_of_range("Index or range is out of bounds");
	}
	std::vector<unsigned int> newalloc;
	newalloc.reserve(src.size());
	for(size_t i = 0; i < src.size(); i++) {
		if (i >= idx && i < idx + size)
			dest.push_back(src[i]);
		else
			newalloc.push_back(src[i]);
	}
	src = newalloc;
}

void PmergeMe::insertSortInit_() {
	if (this->level_ < 1) {
		this->step_ = 0; // breaks is nothing left
		return;
	}
	#if DEBUG
	std::cout << C_YELLOW << "[Insert sort init]" << C_RESET << std::endl << "Recursion level " << this->level_ << " base " << this->base_ << std::endl;
	#endif
	if (this->base_ >= this->sequence_.size()) {
		this->level_--;
		this->base_ /= 2;
		return;
	}
	this->elementMove(this->sequence_, this->main_, 0, this->base_); // move b1 and a1
	while (this->sequence_.size() >= this->base_) {
		this->elementMove(this->sequence_, this->pend_, 0, this->base_ / 2); // move bx to pend_
		this->elementMove(this->sequence_, this->main_, 0, this->base_ / 2); // move ax to main_
	}
	if (this->sequence_.size() >= this->base_ / 2)
		this->elementMove(this->sequence_, this->pend_, 0, this->base_ / 2); // move last element if any
	this->elementMove(this->sequence_, this->out_, 0, this->sequence_.size()); // move non-participating part
	this->step_ = 3;
	#if DEBUG
	this->printStacks();
	#endif
}

static int jacobsthal(int num) {
	return (std::pow(2, num) - pow(-1, num)) / 3;
}

void PmergeMe::insertSort_() {
	bool trigger;
	size_t jac = jacobsthal(this->level_);

	#if DEBUG
	std::cout << C_MAGENTA << "[Insert sort]" C_RESET << std::endl << "jacobsthal: " << jac << std::endl;
	#endif
	for(size_t i = 0; i < jac; i++) {
		trigger = false;
		if (this->pend_.empty())
			break;
		std::vector<unsigned int> temp;
		temp.reserve(this->main_.size() + this->base_ / 2);
		while (!this->main_.empty()) {
			if (this->isLess(this->main_[this->base_ / 2 - 1], *this->pend_.end().operator-(1)))
				this->elementMove(this->main_, temp, 0, this->base_);
			else {
				this->elementMove(this->pend_, temp, this->pend_.size() - this->base_ / 2, this->base_ / 2);
				this->elementMove(this->main_, temp, 0, this->main_.size());
				trigger = true;
			}
		}
		if (!trigger)
			this->elementMove(this->pend_, temp, this->pend_.size() - this->base_, this->base_);
		this->main_ = temp;
	}
	this->sequence_.clear();
	this->elementMove(this->main_, this->sequence_, 0, this->main_.size());
	this->elementMove(this->out_, this->sequence_, 0, this->out_.size());
	#if DEBUG
	std::cout << "new sequence: " << std::endl;	
	this->printSequence();
	std::cout << std::endl;
	#endif
	this->level_--;
	this->base_ /= 2;
	this->step_ = 2;
}

void PmergeMe::printStack_(const std::vector<unsigned int>& stack) const {
	if (stack.empty()) {
		std::cout << C_RED << "empty" << C_RESET;
		return;
	}
	bool isswitch = false;
	const char *cswitch = C_RESET;
	for(std::vector<unsigned int>::const_iterator it = stack.begin(); it != stack.end(); it++) {
		isswitch = !((it - stack.begin()) % ((this->base_ / 2) ? this->base_ / 2 : 1));
		#if DEBUG
		if (isswitch) {
			cswitch = strcmp(cswitch, C_GREEN) ? C_GREEN : C_BLUE;
			std::cout << cswitch;
		}
		#else
		(void)isswitch;
		#endif
		std::cout << *it;
		if (it + 1 != stack.end()) {
			std::cout << C_RESET << " " << cswitch;
		}
	}
	std::cout << C_RESET;
}

void PmergeMe::printSequence() const {
	this->printStack_(this->sequence_);
	std::cout << std::endl;
}

void PmergeMe::printStacks() const {
	std::cout << std::endl << "Pend: ";
	this->printStack_(this->pend_);
	std::cout << std::endl << "Out: ";
	this->printStack_(this->out_);
	std::cout << std::endl << "Main: ";
	this->printStack_(this->main_);
	std::cout << std::endl << std::endl;
}

void PmergeMe::buildSequence() {
	switch (this->step_) {
		case 0:
			return;
		case 1:
			mergeSort_();
			break;
		case 2:
			insertSortInit_();
			break;
		case 3:
			insertSort_();
			break;
	}
	buildSequence();
}

const std::vector<unsigned int>& PmergeMe::getSequence() const { return this->sequence_; }