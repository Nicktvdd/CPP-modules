#ifndef MIN_HPP
# define MIN_HPP

template<typename T>
T min(T& first, T& second) {
	if (first < second)
		return (first);
	return (second);
}

#endif