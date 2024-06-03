#include "Serializer.hpp"

int main(void) {
    // Create an instance of the Data struct
    Data original;
    original.foo = 105;

    // Print the value of original.foo
    std::cout << "Original foo: " << original.foo << std::endl;

    // Print the address of the original object
    std::cout << "Original address: " << &original << std::endl;

    // Serialize the original object and store the serialized address
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized address: " << serialized << std::endl;

    // Deserialize the serialized address and store the deserialized object
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;

    // Print the value of deserialized->foo
    std::cout << "Deserialized foo: " << deserialized->foo << std::endl;

    return 0;
}