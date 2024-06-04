#include "AForm.hpp"
#include <iostream>

// Constructor
AForm::AForm(std::string const& name, int minimumGradeToSign, int minimumGradeToExecute)
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
AForm::~AForm()
{}

// Output stream operator overload
std::ostream& operator<<(std::ostream& os, const AForm& ref)
{
	os << ref.getName() << "\n";
	os << "Signed: " << (ref.getIsSigned() ? "True\n" : "False\n");
	os << "Minimum grade to sign: " << ref.getMinimumGradeToSign() << "\n";
	os << "Minimum grade to execute: " << ref.getMinimumGradeToExecute() << "\n";
	return (os);
}

// Getters
std::string AForm::getName() const
{
	return (name);
}

bool AForm::getIsSigned() const
{
	return (isSigned);
}

int AForm::getMinimumGradeToSign() const
{
	return (minimumGradeToSign);
}

int AForm::getMinimumGradeToExecute() const
{
	return (minimumGradeToExecute);
}

// Exception classes

// Exception for when the grade is too high
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

// Exception for when the grade is too low
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

// Exception for when the form has not been signed
const char* AForm::FormNotSignedExpection::what() const throw()
{
	return ("Form has not been signed");
}

// Sign the form
void AForm::beSigned(Bureaucrat const& ref)
{
	// Check if the bureaucrat's grade is low enough to sign the form
	if (ref.getGrade() > minimumGradeToSign)
		throw(GradeTooLowException());
	isSigned = true;
}

// Execute the form
void AForm::execute(Bureaucrat const& ref) const
{
	// Check if the form has been signed
	if (!isSigned)
		throw(FormNotSignedExpection());
	// Check if the bureaucrat's grade is low enough to execute the form
	if (ref.getGrade() > minimumGradeToExecute)
		throw(GradeTooLowException());
	executeLogic();
}
