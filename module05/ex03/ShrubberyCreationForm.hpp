#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
public:
    // Constructor
    ShrubberyCreationForm(std::string const& target);

    // Destructor
    ~ShrubberyCreationForm();

    // Executes the logic of the form
    void executeLogic() const;

private:
    const std::string target; // The target for the shrubbery creation

    // Private default constructor (not to be used)
    ShrubberyCreationForm();

    // Private copy constructor (not to be used)
    ShrubberyCreationForm(ShrubberyCreationForm const& other);

    // Private assignment operator (not to be used)
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
};

#endif