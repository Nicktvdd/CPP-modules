#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

// The Intern class is responsible for creating different types of forms.
class Intern
{
public:
    // Creates a form based on the given form name and target.
    AForm* makeForm(std::string const& form, std::string const& target);

    // Default constructor.
    Intern();

    // Destructor.
    ~Intern();

private:
    // Copy constructor (private to prevent copying).
    Intern(Intern const& other);

    // Assignment operator (private to prevent assignment).
    Intern& operator=(Intern const& other);
};

#endif