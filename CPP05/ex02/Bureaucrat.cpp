#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        _grade = other._grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
    _grade == 1 ? throw GradeTooHighException() : _grade--;
}

void Bureaucrat::decrementGrade()
{
    _grade == 150 ? throw GradeTooLowException() : _grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch (const std::exception &e)
    {
        putStr(_name + " couldn't sign " + form.getName() + " -> " + e.what() + "\n", RED);
        return;
    }
    putStr(_name + " signed " + form.getName() + "\n", CYAN);
}

void Bureaucrat::executeForm(const AForm &form)
{
    try
    {
        form.execute(*this);
        putStr(_name + " executed " + form.getName() + "\n", CYAN);
    }
    catch (const std::exception &e)
    {
        putErr(_name + " couldn't execute " + form.getName() + " because " + e.what() + "\n", RED);
    }
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

void putStr(std::string str, std::string color)
{
    std::cout << color << str << RESET;
}

void putNum(int bits, std::string color)
{
    std::cout << color << bits << RESET;
}

void putErr(std::string str, std::string color)
{
    std::cerr << color << str << RESET;
}