# include "./PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv, int argc) {
	this->init_(argv, argc);
}

PmergeMe::PmergeMe(const PmergeMe& copy):
	sequence_(copy.sequence_) {}

PmergeMe::~PmergeMe() { this->sequence_.clear(); }

PmergeMe& PmergeMe::operator=(const PmergeMe& assign) {
	if (this == &assign)
		return *this;
	this->sequence_ = assign.sequence_;
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

void PmergeMe::pairSwap_(unsigned int a1, unsigned int base) {
	for(unsigned int i = 0; i < base / 2; i++)
		swap(this->sequence_[a1 + i], this->sequence_[a1 + i + base / 2]);
}

void PmergeMe::pairSort_(unsigned int level) {
	if (level < 2) {
		pairSort_(2);
		return;
	}
	for(size_t i = 0; i + level - 1 < this->sequence_.size(); i += level)
		if (this->sequence_[i + level / 2 - 1] > this->sequence_[ i + level - 1])
			pairSwap_(i, level);
	if (level < this->sequence_.size())
		this->pairSort_(level * 2);
}

void PmergeMe::printSequence() const {
	for(std::vector<unsigned int>::const_iterator it = this->sequence_.begin(); it != this->sequence_.end(); it++) {
		std::cout << *it;
		if (it + 1 != this->sequence_.end())
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}

void PmergeMe::buildSequence() {
	pairSort_(2);
}

const std::vector<unsigned int>& PmergeMe::getSequence() const { return this->sequence_; }