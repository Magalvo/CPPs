#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    srand(time(NULL));

    putStr("\nTest ShrubberyCreationForm\n", CYAN_BOLD);
    Bureaucrat Mr_Shrubby("Mr_Shrubby", 130);
    ShrubberyCreationForm Shrubby_form("Hello");
    putStr("\n", RESET);
    putNum(Shrubby_form.getSignGrade(), GREEN);
    putStr("\n", RESET);
    putNum(Shrubby_form.getIsSigned(), GREEN);
    putStr("\n", RESET);
    putNum(Shrubby_form.getExecuteGrade(), GREEN);
    putStr("\n", RESET);
    std::cout << Shrubby_form;
    Mr_Shrubby.signForm(Shrubby_form);
    std::cout << Shrubby_form;
    Mr_Shrubby.executeForm(Shrubby_form);

    putStr("\nTest RobotomyRequestForm\n", CYAN_BOLD);
    RobotomyRequestForm Robo_form("I am a robo form");
    Bureaucrat Mr_Robo("Mr_Robo", 45);

    Mr_Robo.executeForm(Robo_form);
    Mr_Robo.signForm(Robo_form);
    Mr_Robo.executeForm(Robo_form);
    Mr_Robo.executeForm(Robo_form);
    Mr_Robo.executeForm(Robo_form);


    putStr("\nTest PresidentialPardonForm\n", CYAN_BOLD);

    PresidentialPardonForm President_form("I am a robo form");
    Bureaucrat Mr_President("Mr_President", 5);

    Mr_Robo.executeForm(President_form);
    Mr_Robo.signForm(President_form);

    Mr_President.executeForm(President_form);
    Mr_President.signForm(President_form);
    Mr_President.executeForm(President_form);

    return (0);
}