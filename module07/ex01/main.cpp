#include "iter.hpp"
#include <string>
#include <iostream>

int main(void) {
    // Initialize arrays
    int foo[] = {0, 1, 2, 3, 4};
    char bar[] = {'a', 'b', 'c', 'd', 'e'};
    float floarr[] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f};
    double doubarr[] = {0.0, 100.11, 200.22, 300.33, 400.44};
    std::string strs[] = {"bart", "lisa", "maggie", "marge", "homer"};

    // Perform operations on int array
    std::cout << "* * * * * INT ARRAY * * * * *" << std::endl;
    std::cout << "calling plusone() on int array foo[]" << std::endl;
    iter(foo, 5, plusone<int>);
    std::cout << "calling printer() on int array foo[]" << std::endl;
    iter(foo, 5, printer<const int>);

    // Perform operations on char array
    std::cout << std::endl << "* * * * * CHAR ARRAY * * * * *" << std::endl;
    std::cout << "calling plusone() on char array bar[]" << std::endl;
    iter(bar, 5, plusone<char>);
    std::cout << "calling printer() on char array bar[]" << std::endl;
    iter(bar, 5, printer<const char>);

    // Perform operations on float array
    std::cout << std::endl << "* * * * * FLOAT ARRAY * * * * *" << std::endl;
    std::cout << "calling plusone() on float array floarr[]" << std::endl;
    iter(floarr, 5, plusone<float>);
    std::cout << "calling printer() on float array floarr[]" << std::endl;
    iter(floarr, 5, printer<const float>);

    // Perform operations on double array
    std::cout << std::endl << "* * * * * DOUBLE ARRAY * * * * *" << std::endl;
    std::cout << "calling plusone() on double array doubarr[]" << std::endl;
    iter(doubarr, 5, plusone<double>);
    std::cout << "calling printer() on double array doubarr[]" << std::endl;
    iter(doubarr, 5, printer<const double>);

    // Perform operations on string array
    std::cout << std::endl << "* * * * * STRING ARRAY * * * * *" << std::endl;
    std::cout << "calling printer() on string array strs[]" << std::endl;
    iter(strs, 5, printer<const std::string>);

    return 0;
}