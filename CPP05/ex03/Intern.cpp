#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

AForm *Intern::makeForm(const std::string form_name, const std::string form_target)
{
    int i = 0;
    std::string available_forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    while (i < 3 && form_name != available_forms[i])
        i++;

    switch (i)
    {
    case 0:
        putStr("Intern creates " + form_name + "\n", CYAN_BOLD);
        std::cout << "Intern creates " << form_name << std::endl;
        return (new ShrubberyCreationForm(form_target));
    case 1:
        putStr("Intern creates " + form_name + "\n", CYAN_BOLD);
        std::cout << "Intern creates " << form_name << std::endl;
        return (new RobotomyRequestForm(form_name));
    case 2:
        putStr("Intern creates " + form_name + "\n", CYAN_BOLD);
        std::cout << "Intern creates " << form_name << std::endl;
        return (new PresidentialPardonForm(form_target));
    default:
        putStr("Form is not existing " + form_name + "\n", RED);
        std::cout << "Form is not existing" << std::endl;
        return NULL;
    }
}

Intern::~Intern()
{
}