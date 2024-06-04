#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp" // Include the header file for the base class
#include <string>

class PresidentialPardonForm : public AForm // Declare the class and inherit from AForm
{
    public:

        PresidentialPardonForm(std::string const& target); // Constructor with target parameter
        ~PresidentialPardonForm(); // Destructor

        void executeLogic() const; // Function to execute the logic of the form

    private:

        const std::string target; // Member variable to store the target

        // Private default constructor, copy constructor, and assignment operator
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const& other);
        PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
};

#endif