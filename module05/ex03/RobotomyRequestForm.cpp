#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{}

// Execute the logic of the form
void RobotomyRequestForm::executeLogic() const
{
    // Seed the random number generator
    std::srand(std::time(NULL));

    // Generate a random number and check if it's odd or even
    if (std::rand() & 0x1)
    {
        // If it's odd, the robotomy is successful
        std::cout << target << " has been robotomized successfully\n";
    }
    else
    {
        // If it's even, the robotomy fails
        std::cout << "Robotomy failed\n";
    }
}