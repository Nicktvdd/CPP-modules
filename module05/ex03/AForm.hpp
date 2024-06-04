#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

// Forward declaration of AForm class
class AForm;

// Overloaded insertion operator for AForm class
std::ostream& operator<<(std::ostream& os, const class AForm& ref);

// AForm class declaration
class AForm
{
public:
	// Constructor
	AForm(
		std::string const& name,
		int minimumGradeToSign,
		int minimumGradeToExecute);

	// Destructor
	virtual ~AForm();

	// Getter functions
	std::string getName() const;
	bool getIsSigned() const;
	int getMinimumGradeToSign() const;
	int getMinimumGradeToExecute() const;

	// Member functions
	void beSigned(Bureaucrat const& ref);
	void execute(Bureaucrat const& ref) const;
	virtual void executeLogic() const = 0;

private:
	// Member variables
	std::string const name;
	bool isSigned;
	int const minimumGradeToSign;
	int const minimumGradeToExecute;

	// Exception classes
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	class FormNotSignedExpection : public std::exception
	{
		const char* what() const throw();
	};

	// Private default constructor (not accessible)
	AForm();

	// Private copy constructor (not accessible)
	AForm(AForm const& other);

	// Private assignment operator (not accessible)
	AForm& operator=(AForm const& other);
};

#endif