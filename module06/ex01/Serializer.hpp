#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>
#include "Data.hpp"

class Serializer {
private:
    // Private constructors and assignment operator
    Serializer(void);
    Serializer(Serializer const& other);
    Serializer& operator=(Serializer const& other);
    ~Serializer(void);

public:
    // Serialize a Data object to a uintptr_t
    static std::uintptr_t serialize(Data* ptr);

    // Deserialize a uintptr_t to a Data object
    static Data* deserialize(std::uintptr_t raw);
};

#endif