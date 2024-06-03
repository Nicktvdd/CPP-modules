#ifndef SWAP_HPP
# define SWAP_HPP

template<typename T>
void swap(T& first, T& second) {
	T temporary = first;
	first = second;
	second = temporary;
}

#endif