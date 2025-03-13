#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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

#endif