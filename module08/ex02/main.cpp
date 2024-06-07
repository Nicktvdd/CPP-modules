#include "MutantStack.hpp"
#include <list>

int main(void) {
    // Create an instance of MutantStack
    MutantStack<int> mstack;

    // Fill in the stack with numbers 1 to 11 using push()
    std::cout << std::endl << "* * * Filling in 1-11 to the stack via push() * * *" << std::endl;
    for (int i = 1; i <= 11; i++) {
        mstack.push(i);
        std::cout << "Pushed " << i << " to the stack" << std::endl;
    }

    // Display the top element of the stack using top()
    std::cout << std::endl << "* * * top() & pop() * * *" << std::endl;
    std::cout << "On the top() of the stack: " << mstack.top() << std::endl;

    // Remove the topmost element using pop()
    std::cout << "Removing topmost elem via pop()" << std::endl;
    mstack.pop();

    // Display the new top element of the stack
    std::cout << "On the top() of the stack: " << mstack.top() << std::endl;

    // Iterate forward in the stack using iterators
    std::cout << std::endl << "* * * Iterating forward in the stack * * *" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator end = mstack.end();
    while (it != end) {
        std::cout << *it << std::endl;
        it++;
    }

    // Iterate backwards in the stack using iterators
    it--;
    std::cout << std::endl << "* * * Iterating backwards in the stack * * *" << std::endl;
    end = mstack.begin();
    end--;
    while (it != end) {
        std::cout << *it << std::endl;
        it--;
    }

    // Create a const stack and handle const iterators
    std::cout << std::endl << "* * * Handling const * * *" << std::endl;
    MutantStack<int> const conststack(mstack);
    MutantStack<int>::const_iterator constit = conststack.begin();
    std::cout << "First element of the new stack: " << *constit << std::endl;

    // Copy and assignment operations
    std::cout << std::endl << "* * * Copy & assignment * * *" << std::endl;
    std::cout << "Address of the first container: " << mstack.getContainerAddress() << std::endl;
    std::cout << "Address of the second container: " << conststack.getContainerAddress() << std::endl << std::endl;

    // Destructor prints
    std::cout << "* * * Destructor prints * * *" << std::endl;
    return (0);
}
