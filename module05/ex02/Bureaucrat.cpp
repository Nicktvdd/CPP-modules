#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const& name, int grade)
: name(name)
{
	if (grade < GRADE_HIGHEST)
		throw(GradeTooHighException());
	if (grade > GRADE_LOWEST)
		throw(GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".\n";
	return (os);
}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::gradeIncrement()
{
	if (grade - 1 < GRADE_HIGHEST)
		throw(GradeTooHighException());
	grade--;
}

void	Bureaucrat::gradeDecrement()
{
	if (grade + 1 > GRADE_LOWEST)
		throw(GradeTooLowException());
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

void	Bureaucrat::signForm(AForm& ref)
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

void	Bureaucrat::executeForm(AForm const& ref)
{
    try
    {
        ref.execute(*this);
        std::cout << name << " executed " << ref.getName() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << name << " failed to execute the form. Reason: " << e.what() << '\n';
    }
}
