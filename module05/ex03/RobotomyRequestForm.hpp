#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp" // Include the header file for the base class
#include <string>

class RobotomyRequestForm : public AForm // Declare the RobotomyRequestForm class, inheriting from AForm
{
    public:

        RobotomyRequestForm(std::string const& target); // Constructor declaration with a target parameter
        ~RobotomyRequestForm(); // Destructor declaration

        void executeLogic() const; // Function declaration for executing the logic of the form

    private:

        const std::string target; // Private member variable to store the target

        RobotomyRequestForm(); // Default constructor declaration (private to prevent usage)
        RobotomyRequestForm(RobotomyRequestForm const& other); // Copy constructor declaration (private to prevent usage)
        RobotomyRequestForm& operator=(RobotomyRequestForm const& other); // Assignment operator declaration (private to prevent usage)
};

#endif