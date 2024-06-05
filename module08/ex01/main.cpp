#include "Span.hpp"

int main(void) {
    // Creating an instance of Span with a capacity of 5
    Span foo(5);

    try {
        // Adding numbers to foo
        foo.addNumber(42);
        foo.addNumber(1);
        foo.addNumber(666);
        foo.addNumber(43);
        foo.addNumber(1001);
    } catch (std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    // Printing the longest and shortest span in foo
    std::cout << "Return value of foo.longestSpan(): " << foo.longestSpan() << std::endl;
    std::cout << "Return value of foo.shortestSpan(): " << foo.shortestSpan() << std::endl;

    std::cout << std::endl << "* * * Copying * * *" << std::endl;

    // Creating another instance of Span with a capacity of 6
    Span bar(6);

    try {
        // Adding numbers to bar
        bar.addNumber(1);
        bar.addNumber(3);
        bar.addNumber(6);
        bar.addNumber(10);
        bar.addNumber(100);
        bar.addNumber(1000000);
    } catch (std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    // Printing the longest and shortest span in bar
    std::cout << "Return value of bar.longestSpan(): " << bar.longestSpan() << std::endl;
    std::cout << "Return value of bar.shortestSpan(): " << bar.shortestSpan() << std::endl;

    // Copying foo to bar
    bar = foo;

    // Printing the longest and shortest span in bar after copying
    std::cout << "Return value of bar.longestSpan(): " << bar.longestSpan() << std::endl;
    std::cout << "Return value of bar.shortestSpan(): " << bar.shortestSpan() << std::endl << std::endl;

    std::cout << "* * * Stress test!!! * * *" << std::endl;

    // Creating an instance of Span with a capacity of 10000
    Span tengrand(10000);

    try {
        // Adding numbers to tengrand
        tengrand.addNumber(1);
        tengrand.addManyNumbers(2499, 42);
        tengrand.addNumber(50);
        tengrand.addManyNumbers(2499, 100);
        tengrand.addNumber(101);
        tengrand.addManyNumbers(2499, 200);
        tengrand.addNumber(252);
        tengrand.addManyNumbers(2499, 500);
        tengrand.addManyNumbers(99999, 1);
    } catch (std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    // Printing the longest and shortest span in tengrand
    std::cout << "Return value of tengrand.longestSpan(): " << tengrand.longestSpan() << std::endl;
    std::cout << "Return value of tengrand.shortestSpan(): " << tengrand.shortestSpan() << std::endl << std::endl;

    return (0);
}

//SUBJECT MAIN
// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }