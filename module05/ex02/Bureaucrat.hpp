#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define GRADE_HIGHEST 1
#define GRADE_LOWEST 150

#include <string>
#include <iostream>

std::ostream&	operator<<(std::ostream& os, const class Bureaucrat& ref);

class	AForm;

class	Bureaucrat
{
	public:

		Bureaucrat(std::string const& name, int grade);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void		gradeIncrement();
		void		gradeDecrement();
		void		signForm(AForm& ref);
        void        executeForm(AForm const& ref);

	private:

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

		std::string const	name;
		int					grade;

		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
};

#endif