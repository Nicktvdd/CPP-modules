#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

// Define the highest and lowest grades
#define GRADE_HIGHEST 1
#define GRADE_LOWEST 150

// Forward declaration of class Form
class Form;

// Overload the << operator for Bureaucrat class
std::ostream& operator<<(std::ostream& os, const class Bureaucrat& ref);

class Bureaucrat
{
public:
	// Constructor and destructor
	Bureaucrat(std::string const& name, int grade);
	~Bureaucrat();

	// Getter methods
	std::string getName() const;
	int getGrade() const;

	// Methods to increment and decrement grade
	void gradeIncrement();
	void gradeDecrement();

	// Method to sign a form
	void signForm(Form& ref);

private:
	// Exception class for grade too high
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};

	// Exception class for grade too low
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	std::string const name; // Bureaucrat's name (constant)
	int grade; // Bureaucrat's grade

	// Private default constructor and copy constructor
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);

	// Private assignment operator
	Bureaucrat& operator=(const Bureaucrat& other);
};

#endif