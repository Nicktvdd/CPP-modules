#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

// Define a function pointer type for creating forms
typedef AForm* (*FormFactory)(std::string const&);

// Template function for creating a specific form type
template<typename T>
AForm* create(std::string const& target)
{
    return new T(target);
}

AForm* Intern::makeForm(std::string const& form, std::string const& target)
{
    // Array of form names
    std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    // Array of form creation functions
    FormFactory functions[3] = {create<PresidentialPardonForm>, create<RobotomyRequestForm>, create<ShrubberyCreationForm>};

    // Iterate through the form names
    for (int i = 0; i < 3; i++)
    {
        // Check if the current form name matches the requested form
        if (forms[i] == form)
        {
            // Create and return the corresponding form using the appropriate creation function
            return functions[i](target);
        }
    }

    // If the requested form doesn't exist, print an error message
    std::cout << "Form doesn't exist\n";

    // Return NULL pointer
    return nullptr;
}