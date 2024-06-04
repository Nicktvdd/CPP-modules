#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	// Create two instances of the Bureaucrat class
	Bureaucrat Jake("Jake", 150);
	Bureaucrat Finn("Finn", 16);

	// Print the name and grade of Jake
	std::cout << Jake;

	// Print the name and grade of Finn
	std::cout << Finn.getName() << " " << Finn.getGrade() << "\n";

	// Increment and decrement the grades of Jake and Finn
	std::cout << "\nIncrement and decrement\n";
	try {
		Jake.gradeIncrement();
		std::cout << Jake;
		Finn.gradeDecrement();
		std::cout << Finn;
	}
	catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// Attempt to decrement the grade of Jake below the minimum grade
	// and increment the grade of Finn above the maximum grade
	std::cout << "\nOver increment and decrement\n";
	try {
		Jake.gradeDecrement();
		Jake.gradeDecrement();
	}
	catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	try {
		Finn.gradeIncrement();
		Finn.gradeIncrement();
	}
	catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	// Attempt to create a Bureaucrat instance with an invalid grade
	std::cout << "\nCreating class with too high or too low grade\n";
	try {
		Bureaucrat Kalle("Kalle", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	try {
		Bureaucrat Jonne("Jonne", 190);
	}
	catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	return 0;
}