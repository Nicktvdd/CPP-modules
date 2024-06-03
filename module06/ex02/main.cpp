#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>

// Generate a random derived class instance of Base
Base* generate() {
	Base* ptr = nullptr;
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	int index = std::rand() % 3;
	switch (index) {
		case 0:
			ptr = new A();
			std::cout << "Generated class A." << std::endl;
			break;
		case 1:
			ptr = new B();
			std::cout << "Generated class B." << std::endl;
			break;
		case 2:
			ptr = new C();
			std::cout << "Generated class C." << std::endl;
			break;
	}
	return ptr;
}

// Identify the derived class type from a pointer
void identify(Base* p) {
	A* a_ptr = dynamic_cast<A*>(p);
	B* b_ptr = dynamic_cast<B*>(p);
	C* c_ptr = dynamic_cast<C*>(p);

	if (a_ptr) {
		std::cout << "Identified from pointer as A." << std::endl;
	} else if (b_ptr) {
		std::cout << "Identified from pointer as B." << std::endl;
	} else if (c_ptr) {
		std::cout << "Identified from pointer as C." << std::endl;
	}
}

// Identify the derived class type from a reference
void identify(const Base& p) {
	try {
		dynamic_cast<const A&>(p);
		std::cout << "Identified from reference as A." << std::endl;
	} catch (const std::bad_cast&) {
		std::cout << "It ain't A!" << std::endl;
	}
	try {
		dynamic_cast<const B&>(p);
		std::cout << "Identified from reference as B." << std::endl;
	} catch (const std::bad_cast&) {
		std::cout << "It ain't B!" << std::endl;
	}
	try {
		dynamic_cast<const C&>(p);
		std::cout << "Identified from reference as C." << std::endl;
	} catch (const std::bad_cast&) {
		std::cout << "It ain't C!" << std::endl;
	}
}

int main() {
	Base* random_class = generate();
	std::cout << std::endl;

	identify(random_class);
	std::cout << std::endl;

	identify(*random_class);

	delete random_class;
	return 0;
}
