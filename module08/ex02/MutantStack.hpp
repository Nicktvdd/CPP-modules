#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
    public:
        // Default constructor
        MutantStack(void);

        // Destructor
        ~MutantStack(void);

        // Copy constructor
        MutantStack(MutantStack const& other);

        // Assignment operator
        MutantStack& operator=(MutantStack const& other);

        // Iterator types
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;

        // Begin and end iterators
        iterator begin(void);
        iterator end(void);
        const_iterator begin(void) const;
        const_iterator end(void) const;

        // Get the address of the underlying container
        std::deque<T>* getContainerAddress(void);
        const std::deque<T>* getContainerAddress(void) const;
};

template <typename T>
MutantStack<T>::MutantStack(void) {
    std::cout << "MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {
    std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& other) : std::stack<T, std::deque<T>>(other) {
    std::cout << "MutantStack copy constructor called" << std::endl;
    *this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& other) {
    std::cout << "MutantStack assignment operator called" << std::endl;
    if (this != &other)
        std::stack<T, std::deque<T> >::operator=(other);
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const {
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const {
    return (this->c.end());
}

template <typename T>
std::deque<T>* MutantStack<T>::getContainerAddress(void) {
    return (&this->c);
}

template <typename T>
const std::deque<T>* MutantStack<T>::getContainerAddress(void) const {
    return (&this->c);
}

#endif