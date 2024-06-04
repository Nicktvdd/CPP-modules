#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

// Forward declaration of Form class
class Form;

// Overloaded insertion operator for Form class
std::ostream&	operator<<(std::ostream& os, const class Form& ref);

// Form class declaration
class Form
{
	public:

		// Constructor
		Form(
			std::string const& name,
			int minimumGradeToSign,
			int minimumGradeToExecute);

		// Destructor
		~Form();
	
		// Getter functions
		std::string 	getName() const;
		bool    		getIsSigned() const;
		int 			getMinimumGradeToSign() const;
		int 			getMinimumGradeToExecute() const;

		// Member functions
		void		    beSigned(Bureaucrat const& ref);

	private:

		// Private member variables
		std::string const	name;
		bool				isSigned;
		int const			minimumGradeToSign;
		int const			minimumGradeToExecute;

		// Exception classes
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

		// Private default constructor (not to be used)
		Form();

		// Private copy constructor (not to be used)
		Form(Form const& other);

		// Private assignment operator (not to be used)
		Form&	operator=(Form const& other);
};

#endif