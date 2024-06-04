#include "Form.hpp"
#include <iostream>

// Constructor
Form::Form(std::string const& name, int minimumGradeToSign, int minimumGradeToExecute)
	: name(name),
	  isSigned(false),
	  minimumGradeToSign(minimumGradeToSign),
	  minimumGradeToExecute(minimumGradeToExecute)
{
	// Check if the minimum grades are within the valid range
	if (minimumGradeToSign < GRADE_HIGHEST || minimumGradeToExecute < GRADE_HIGHEST)
		throw(GradeTooHighException());
	if (minimumGradeToSign > GRADE_LOWEST || minimumGradeToExecute > GRADE_LOWEST)
		throw(GradeTooLowException());
}

// Destructor
Form::~Form()
{}

// Output stream operator overload
std::ostream& operator<<(std::ostream& os, const Form& ref)
{
	os << ref.getName() << "\n";
	os << "Signed: " << (ref.getIsSigned() ? "True\n" : "False\n");
	os << "Minimum grade to sign: " << ref.getMinimumGradeToSign() << "\n";
	os << "Minimum grade to execute: " << ref.getMinimumGradeToExecute() << "\n";
	return (os);
}

// Getters
std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

int Form::getMinimumGradeToSign() const
{
	return (minimumGradeToSign);
}

int Form::getMinimumGradeToExecute() const
{
	return (minimumGradeToExecute);
}

// Exception classes

// Exception for when the grade is too high
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

// Exception for when the grade is too low
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

// Sign the form
void Form::beSigned(Bureaucrat const& ref)
{
	// Check if the bureaucrat's grade is low enough to sign the form
	if (ref.getGrade() > minimumGradeToSign)
		throw(GradeTooLowException());
	isSigned = true;
}