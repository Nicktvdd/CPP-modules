#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// Constructor
Bureaucrat::Bureaucrat(std::string const& name, int grade)
	: name(name)
{
	// Check if the grade is too high
	if (grade < GRADE_HIGHEST)
		throw(GradeTooHighException());
	// Check if the grade is too low
	if (grade > GRADE_LOWEST)
		throw(GradeTooLowException());
	this->grade = grade;
}

// Destructor
Bureaucrat::~Bureaucrat()
{}

// Overloaded output stream operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".\n";
	return (os);
}

// Get the name of the bureaucrat
std::string Bureaucrat::getName() const
{
	return (name);
}

// Get the grade of the bureaucrat
int Bureaucrat::getGrade() const
{
	return (grade);
}

// Increment the grade of the bureaucrat
void Bureaucrat::gradeIncrement()
{
	// Check if the grade will become too high
	if (grade - 1 < GRADE_HIGHEST)
		throw(GradeTooHighException());
	grade--;
}

// Decrement the grade of the bureaucrat
void Bureaucrat::gradeDecrement()
{
	// Check if the grade will become too low
	if (grade + 1 > GRADE_LOWEST)
		throw(GradeTooLowException());
	grade++;
}

// Exception class for a grade that is too high
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

// Exception class for a grade that is too low
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

// Sign a form
void Bureaucrat::signForm(Form& ref)
{
	try
	{
		ref.beSigned(*this);
		std::cout << name << " signed " << ref.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't sign " << ref.getName() << " because " << e.what() << '\n';
	}
}
