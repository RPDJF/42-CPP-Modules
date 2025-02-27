#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <ostream>
#include <sstream>

class Iter {
	public:
		template<typename T>
		static std::string to_string(const T& value)  {
			std::ostringstream oss;
			oss << value;
			return oss.str();
		}
		template<typename T>
		static void swap(T& v1, T& v2) {
			T swap = v1;
			v1 = v2;
			v2 = swap;
		}
		template<typename T>
		static const T& min(const T& v1, const T& v2) {
			if (v1 < v2)
				return v1;
			return v2;
		}
		template<typename T>
		static const T& max(const T& v1, const T& v2) {
			if (v1 > v2)
				return v1;
			return v2;
		}
		template<typename T>
		static void iter(T* arr, size_t len, void (*f)(T)) {
			for(size_t i = 0; i < len; i++) {
				f(arr[i]);
			}
		}
};

#endif