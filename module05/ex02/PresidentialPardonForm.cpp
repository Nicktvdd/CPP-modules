#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{}

// Execute the logic of the form
void PresidentialPardonForm::executeLogic() const
{
    // Print a message indicating that the target has been pardoned
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}