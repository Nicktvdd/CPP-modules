#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	Jake("Jake", 150);
	Bureaucrat	Finn("Finn", 1);
	std::cout << Jake;
	std::cout << Finn.getName() << " " << Finn.getGrade() << "\n";

	std::cout << "\nIncrement and decrement\n";
	try
	{
		Jake.gradeIncrement();
		std::cout << Jake;
		Finn.gradeDecrement();
		std::cout << Finn;
	}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	std::cout << "\nOver increment and decrement\n";
	try
	{
		Jake.gradeDecrement();
		Jake.gradeDecrement();
	}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	try
	{
		Finn.gradeIncrement();
		Finn.gradeIncrement();
	}
	catch (std::exception &e) {std::cout << e.what() << "\n";}


	std::cout << "\nCreating class with too high or too low grade\n";
	try {Bureaucrat	Kalle("Kalle", 0);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	try {Bureaucrat	Jonne("Jonne", 190);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	std::cout << "\n\nFORM:\n";

	Bureaucrat	cantSign("!Signer", 82);
	Bureaucrat	canSign("Signer", 72);
	Bureaucrat	canExecute("Executer", 31);
	Form	x("Test", 80, 40);
	std::cout << x;
	std::cout << x.getName() << x.getIsSigned() << x.getMinimumGradeToSign() << x.getMinimumGradeToExecute() << "\n";

	std::cout << "\nCreating class with too high or too low grade\n";
	try {Form tooHigh("High", 0, 1);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}
	try {Form tooHigh("High", 1, 0);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}
	try {Form tooLow("Low", 1, 155);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}
	try {Form tooLow("Low", 155, 4);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	std::cout << "\nSigning the form\n";
	cantSign.signForm(x);

    canSign.signForm(x);

	return 0;
}