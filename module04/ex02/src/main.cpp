#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/colors.hpp"

int main() 
{
    // UNCOMMENT TO TEST IF ABSTRACT CLASS IS WORKING
    // Animal *animo = new Animal();
    // animo->getType();
    // animo->makeSound();
    // delete animo;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;
    std::cout << GREEN << "-----CREATING ANIMALS ARRAY-----" << RESET << std::endl << std::endl;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;
    Animal *animalsArr[100];
    for (int i = 0; i <= 49; i++)
    {
        std::cout << MAGENTA << "Animal: " << i << RESET << std::endl;
        animalsArr[i] = new Dog();
        std::cout << "Type: " << RED << animalsArr[i]->getType() << RESET << std::endl;
        std::cout << "Sound: ";
        animalsArr[i]->makeSound();
        std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;
    }
        
    for (int i = 50; i <= 99; i++)
    {
        std::cout << MAGENTA << "Animal: " << i << RESET << std::endl;
        animalsArr[i] = new Cat();
        std::cout << "Type: " << RED << animalsArr[i]->getType() << RESET << std::endl;
        std::cout << "Sound: ";
        animalsArr[i]->makeSound();
        std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;
    }

    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;
    std::cout << GREEN << "-----DESTROYING ANIMALS ARRAY-----" << RESET << std::endl << std::endl;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;
    for (int i = 0; i <= 99; i++)
    {
        std::cout << MAGENTA << "Animal: " << i << RESET << std::endl;
        delete animalsArr[i];
        std::cout << GREEN << "--------------------------" << RESET << std::endl;
    }
        
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;
    std::cout << GREEN << "-----DEEP COPY PROOF------" << RESET << std::endl << std::endl;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;
    
    
    std::cout << MAGENTA << "Cat: A" << RESET << std::endl;
    Cat *a = new Cat();
    a->getBrain()->setIdea("Humans are our slaves", 0);
    std::cout << "Type: " << RED << a->getType() << RESET << std::endl;
    std::cout << "Sound: ";
    a->makeSound();
    std::cout << "Idea 0: ";
    std::cout << RED << a->getBrain()->getIdea(0) << RESET << std::endl;
    std::cout << "Idea 0 Adress: ";
    std::cout << RED << a << RESET << std::endl;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;

    std::cout << MAGENTA << "Cat: B is a Copy from Cat A" << RESET << std::endl;
    Cat *b = new Cat(*a);
    std::cout << MAGENTA << "Now we delete Cat A" << RESET << std::endl;
    delete a;
    std::cout << "Type: " << RED << b->getType() << RESET << std::endl;
    std::cout << "Sound: ";
    b->makeSound();
    std::cout << "Idea 0: ";
    std::cout << RED << b->getBrain()->getIdea(0) << RESET << std::endl;
    std::cout << "Idea 0 Adress: ";
    std::cout << RED << b << RESET << std::endl;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;

    delete b;
    return 0;
 }