#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    // Create two bureaucrats
    Bureaucrat canDoAll("Cat", 1);
    Bureaucrat cannotDoAll("dog", 150);

    // Create three different forms
    ShrubberyCreationForm shrub("target");
    RobotomyRequestForm robo("target");
    PresidentialPardonForm pres("target");

    std::cout << "Trying to execute non signed\n\n";

    // Try to execute the forms without signing them
    canDoAll.executeForm(shrub);
    canDoAll.executeForm(robo);
    canDoAll.executeForm(pres);

    std::cout << "\n\nSigning all the forms\n\n";

    // Sign all the forms
    canDoAll.signForm(shrub);
    canDoAll.signForm(robo);
    canDoAll.signForm(pres);

    std::cout << "\n\nExecuting all the forms\n\n";

    // Execute all the forms
    canDoAll.executeForm(shrub);
    std::cout << "\n";
    canDoAll.executeForm(robo);
    std::cout << "\n";
    canDoAll.executeForm(pres);

    std::cout << "\n\nExecuting all the forms without rights\n\n";

    // Try to execute the forms without sufficient rights
    cannotDoAll.executeForm(shrub);
    cannotDoAll.executeForm(robo);
    cannotDoAll.executeForm(pres);

    std::cout << "\n\nInterns\n\n";

    // Create an intern
    Intern formMachine;
    AForm* form;

    // Use the intern to create different forms
    form = formMachine.makeForm("PresidentialPardonForm", "target");
    std::cout << *form << "\n";
    delete form;

    form = formMachine.makeForm("RobotomyRequestForm", "target");
    std::cout << *form << "\n";
    delete form;

    form = formMachine.makeForm("ShrubberyCreationForm", "target");
    std::cout << *form << "\n";
    delete form;

    return 0;
}
