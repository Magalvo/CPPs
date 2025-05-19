#include "PresidentialPardonForm.hpp"
#include <string>
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    _target = other._target;
    setIsSigned(other.getIsSigned());
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::performAction() const
{
    putStr(getName() + " has been pardoned by Zaphod Beeblebrox\n", GREEN);
}