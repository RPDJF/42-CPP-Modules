# include "./PmergeMe.hpp"

template <typename container>
size_t PmergeMe<container>::F(size_t n) const {
    size_t sum = 0;
    for (size_t k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<size_t>(ceil(log2(value)));
    }
    return sum;
}

template <typename container>
size_t PmergeMe<container>::G(size_t n) const {
    if (n == 0)
        return 0;
    size_t logCeil = static_cast<size_t>(ceil(log2(n)));
    return n * logCeil - n + 1;
}

template <typename container>
PmergeMe<container>::PmergeMe(char **argv, int argc):
	step_(1),
	level_(1),
	base_(2),
	element_size_(1),
	jacob_lv_(3),
	count_(0) {
	this->init_(argv, argc);
}

template <typename container>
PmergeMe<container>::PmergeMe(const PmergeMe<container>& copy):
	sequence_(copy.sequence_),
	main_(copy.main_),
	pend_(copy.pend_),
	out_(copy.out_),
	step_(copy.step_),
	level_(copy.level_),
	base_(copy.base_),
	element_size_(copy.element_size_),
	jacob_lv_(copy.jacob_lv_),
	count_(copy.count_) {}

template <typename container>
	PmergeMe<container>::~PmergeMe() { this->sequence_.clear(); }

template <typename container>
PmergeMe<container>& PmergeMe<container>::operator=(const PmergeMe<container>& assign) {
	if (this == &assign)
		return *this;
	this->sequence_ = assign.sequence_;
	this->main_ = assign.main_;
	this->pend_ = assign.pend_;
	this->out_ = assign.out_;
	this->step_ = assign.step_;
	this->level_ = assign.level_;
	this->base_ = assign.base_;
	this->element_size_ = assign.element_size_;
	this->jacob_lv_ = assign.jacob_lv_;
	this->count_ = assign.count_;
	return *this;
}

template <typename container>
void PmergeMe<container>::init_(char **argv, int argc) {
	std::stringstream ss;
	int num;
	for(int i = 1; i < argc; i++) {
		ss.clear();
		ss.str(argv[i]);
		ss >> num;
		this->sequence_.push_back(num);
	}
}

template <typename container>
void PmergeMe<container>::pairSwap_(unsigned int a1) {
	for(unsigned int i = 0; i < this->element_size_; i++)
		swap(this->sequence_[a1 + i], this->sequence_[a1 + i + this->element_size_]);
}

template <typename container>
void PmergeMe<container>::mergeSort_() {
	#if DEBUG
	std::cout << C_YELLOW << "[Merge sort]" << C_RESET << std::endl <<"Recursion level " << this->level_ << " base " << this->base_ << std::endl;
	#endif
	for(size_t i = 0; i * this->base_ + this->base_ - 1 < this->sequence_.size(); i++) {
		if (this->isGreater(this->sequence_[i * this->base_ + this->element_size_ - 1], this->sequence_[i * this->base_ + this->base_ - 1]))
			pairSwap_(i * this->base_);
	}
	#if DEBUG
	this->printSequence();
	std::cout << std::endl;
	#endif
	if (this->base_ * 2 <= this->sequence_.size()) {
		this->level_++;
		this->base_ *= 2;
		this->element_size_ *= 2;
	} else
		this->step_ = 2;
}

template <typename container>
void PmergeMe<container>::elementMove(container& src, container& dest, size_t idx, size_t size) {
	if (size == 0) return;
	else if (idx >= src.size()) {
		throw std::out_of_range("Index or range is out of bounds");
	}
	typename container::iterator itStart = src.begin() + idx;
	typename container::iterator itEnd = itStart + size;
	dest.insert(dest.end(), itStart, itEnd);
	src.erase(itStart, itEnd);
}

template <typename container>
void PmergeMe<container>::insertSortInit_() {
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
		this->element_size_ /= 2;
		return;
	}
	this->elementMove(this->sequence_, this->main_, 0, this->base_); // move b1 and a1
	while (this->sequence_.size() >= this->base_) {
		this->elementMove(this->sequence_, this->pend_, 0, this->element_size_); // move bx to pend_
		this->elementMove(this->sequence_, this->main_, 0, this->element_size_); // move ax to main_
	}
	if (this->sequence_.size() >= this->element_size_)
		this->elementMove(this->sequence_, this->pend_, 0, this->element_size_); // move last element if any
	this->elementMove(this->sequence_, this->out_, 0, this->sequence_.size()); // move non-participating part
	this->step_ = 3;
	#if DEBUG
	this->printStacks();
	#endif
}

static int jacobsthal(int num) {
	return (std::pow(2, num) - pow(-1, num)) / 3;
}

template <typename container>
void PmergeMe<container>::insertSort_() {
	size_t jac = jacobsthal(this->jacob_lv_);
	size_t past_jac = jacobsthal(this->jacob_lv_ - 1);
	size_t insertion = jac - past_jac;
	size_t range = jac + past_jac - 1;
	this->jacob_lv_++;

	if (this->level_ == 1)
		insertion = this->pend_.size();
	#if DEBUG
	std::cout << C_MAGENTA << "[Insert sort]" C_RESET << std::endl << "jacobsthal num: " << jac << std::endl << "insertion: " << insertion << std::endl;
	std::cout << std::endl;
	#endif
	for(ssize_t i = insertion; i >= 0; i--) {
		size_t pend_a = i * this->element_size_;
		size_t pend_b = pend_a + (this->element_size_ - 1);
		if (pend_b >= this->pend_.size()) continue;
		size_t idx = this->binarySearch(this->pend_[pend_b], range);
		container temp;
		temp.insert(temp.end(), this->main_.begin(), this->main_.begin() + idx * this->element_size_);
		temp.insert(temp.end(), this->pend_.begin() + pend_a, this->pend_.begin() + pend_a + this->element_size_);
		temp.insert(temp.end(), this->main_.begin() + idx * this->element_size_, this->main_.end());
		typename container::iterator itStart = this->pend_.begin() + pend_a;
		typename container::iterator itEnd = itStart + this->element_size_;
		this->pend_.erase(itStart, itEnd);
		this->main_ = temp;

	}
	this->sequence_.clear();
	this->elementMove(this->main_, this->sequence_, 0, this->main_.size());
	this->elementMove(this->out_, this->sequence_, 0, this->out_.size());
	this->level_--;
	this->base_ /= 2;
	this->element_size_ /= 2;
	this->step_ = 2;
}

template <typename container>
void PmergeMe<container>::printStack_(const container& stack) const {
	if (stack.empty()) {
		std::cout << C_RED << "empty" << C_RESET;
		return;
	}
	bool isswitch = false;
	const char *cswitch = C_RESET;
	for(typename container::const_iterator it = stack.begin(); it != stack.end(); it++) {
		isswitch = !((it - stack.begin()) % ((this->element_size_) ? this->element_size_ : 1));
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

template <typename container>
void PmergeMe<container>::printSequence() const {
	this->printStack_(this->sequence_);
	std::cout << std::endl;
}

template <typename container>
size_t PmergeMe<container>::binarySearch(unsigned int value, size_t range) {
	if (range > this->main_.size() / this->element_size_)
		range = this->main_.size() / this->element_size_;

	ssize_t left = 0;
	ssize_t right = range;

	while (left < right) {
		ssize_t mid = (left + right) / 2;
		const size_t targetIndex = (mid * this->element_size_) + this->element_size_ - 1;
		const unsigned int target = this->main_[targetIndex];

		// One comparison only!
		if (isLess(target, value)) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}


template <typename container>
void PmergeMe<container>::printStacks() const {
	std::cout << std::endl << "Pend: ";
	this->printStack_(this->pend_);
	std::cout << std::endl << "Out: ";
	this->printStack_(this->out_);
	std::cout << std::endl << "Main: ";
	this->printStack_(this->main_);
	std::cout << std::endl << std::endl;
}

template <typename container>
void PmergeMe<container>::buildSequence() {
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

template <typename container>
const container& PmergeMe<container>::getSequence() const { return this->sequence_; }

template <typename container>
size_t PmergeMe<container>::getCount() const { return this->count_; }