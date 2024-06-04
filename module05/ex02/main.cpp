#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // Create two bureaucrats: one with high privileges and one with low privileges
    Bureaucrat canDoAll("Jake", 1);
    Bureaucrat cannotDoAll("Finn", 150);

    // Create three different forms
    ShrubberyCreationForm shrub("target");
    RobotomyRequestForm robo("target");
    PresidentialPardonForm pres("target");

    // Try to execute the forms without signing them
    std::cout << "Trying to execute non-signed forms:\n\n";
    canDoAll.executeForm(shrub);
    canDoAll.executeForm(robo);
    canDoAll.executeForm(pres);

    // Sign all the forms
    std::cout << "\n\nSigning all the forms:\n\n";
    canDoAll.signForm(shrub);
    canDoAll.signForm(robo);
    canDoAll.signForm(pres);

    // Execute all the forms
    std::cout << "\n\nExecuting all the forms:\n\n";
    canDoAll.executeForm(shrub);
    std::cout << "\n";
    canDoAll.executeForm(robo);
    std::cout << "\n";
    canDoAll.executeForm(pres);

    // Try to execute the forms without sufficient privileges
    std::cout << "\n\nExecuting all the forms without sufficient privileges:\n\n";
    cannotDoAll.executeForm(shrub);
    cannotDoAll.executeForm(robo);
    cannotDoAll.executeForm(pres);

    return 0;
}