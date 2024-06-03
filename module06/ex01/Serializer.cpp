#include "Serializer.hpp"

Serializer::Serializer() {
    // Constructor
}

Serializer::~Serializer() {
    // Destructor
}

Serializer::Serializer(const Serializer& other) {
    // Copy constructor
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other) {
        // Copy possible variables
    }
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t serial = reinterpret_cast<uintptr_t>(ptr);
    return serial;
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data* deserial = reinterpret_cast<Data*>(raw);
    return deserial;
}