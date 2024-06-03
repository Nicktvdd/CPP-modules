#ifndef MAX_HPP
# define MAX_HPP

template<typename T>
T max(T& first, T& second) {
    if (first > second)
        return first;
    return second;
}

#endif