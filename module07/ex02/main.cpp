#include "Array.hpp"

int main(void) {
    // Construction with no parameter and trying to access empty memory
    std::cout << "* * * Construction with no parameter & trying to access empty memory * * *" << std::endl;
    Array<int> noparam;
    std::cout << "Size of the array: " << noparam.size() << std::endl;
    try {
        noparam[0] = 1; // Trying to access index 0 of an empty array
    } catch (std::exception &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    try {
        std::cout << noparam[-15] << std::endl; // Trying to access a negative index of an empty array
    } catch (std::exception &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "* * * Another type of array (char) * * *" << std::endl;
    Array<char> char_arr(10);
    for (int i = 0; i < 10; i++) {
        char_arr[i] = i + 65; // Assigning ASCII values to the elements of the char array
    }
    for (int i = 0; i < 10; i++) {
        std::cout << char_arr[i] << std::endl; // Printing the elements of the char array
    }
    try {
        std::cout << char_arr[10] << std::endl; // Trying to access index 10 of the char array
    } catch (std::exception &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "* * * Showcasing initialization to default * * *" << std::endl;
    Array<int> int_arr(1);
    std::cout << "Int_arr[0] = " << int_arr[0] << std::endl;
    Array<std::string> string_arr(1);
    std::cout << "String_arr[0] = " << string_arr[0] << std::endl;
    std::cout << "Standard behavior with int* a = new int();" << std::endl;
    int *a = new int();
    std::cout << "a = " << *a << std::endl;
    std::cout << "Standard behavior with std::string* b = new std::string();" << std::endl;
    std::string *b = new std::string();
    std::cout << "b = " << *b << std::endl;
    delete a;
    delete b;

    std::cout << std::endl
              << "* * * Copy, assignment & deep/shallow test * * *" << std::endl;
    Array<float> float_arr(5);
    float_arr[0] = 0.1f;
    float_arr[1] = 1.2f;
    float_arr[2] = 2.3f;
    float_arr[3] = 3.4f;
    float_arr[4] = 4.5f;
    Array<float> another_float_arr(float_arr); // Copying float_arr to another_float_arr
    Array<float> yet_another_float_arr = another_float_arr; // Assigning another_float_arr to yet_another_float_arr
    std::cout << "Addresses of the float arrays:" << std::endl;
    std::cout << "1. :" << &float_arr << std::endl;
    std::cout << "2. :" << &another_float_arr << std::endl;
    std::cout << "3. :" << &yet_another_float_arr << std::endl;
    float_arr[0] = 105.105f;
    std::cout << "Arr 1 index 0: " << float_arr[0] << std::endl;
    std::cout << "Arr 2 index 0: " << another_float_arr[0] << std::endl;
    std::cout << "Arr 3 index 0: " << yet_another_float_arr[0] << std::endl;

    std::cout << std::endl
              << "* * * Accessing a const array * * *" << std::endl;
    Array<int> const const_arr(1);
    std::cout << const_arr[0] << std::endl;

    std::cout << std::endl
              << "Okay, that's it! Thank you for your patience. Going out of scope now, so have a good one & enjoy the destructor prints!" << std::endl;
    return (0);
}