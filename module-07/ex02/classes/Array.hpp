#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <memory>
# include <stdexcept>

template<typename T>
class Array {
	private:
		unsigned int len_;
		T *arr_;
	public:
		Array(): len_(0), arr_(0) {}
		Array(unsigned int len): len_(len), arr_(new T[len]) {
			std::fill(&arr_[0], &arr_[len], 0);
		}
		Array(const Array& copy): len_(copy.len_), arr_(new T[this->len_]) {
			for(unsigned int i = 0; i < this->len_; i++) {
				this->arr_[i] = copy.arr_[i];
			}
		}
		const Array& operator=(const Array& assign) {
			if (this == &assign)
				return *this;
			delete this->arr_;
			this->arr_ = new T[assign.len_];
			for(unsigned int i = 0; i < assign.len_ < this->len_ ? assign.len_ : this->len_; i++) {
				this->arr_[i] = assign.arr_[i];
			}
			this->len_ = assign.len_;
			return *this;
		}
		T& operator[](unsigned int idx) {
			if (idx >= this->len_) throw std::out_of_range("index is out of range");
			return this->arr_[idx];
		}
		~Array() { delete[] this->arr_; }
		unsigned int size() const { return this->len_; }
};

#endif