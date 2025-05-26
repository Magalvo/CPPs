#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    putStr("Test too high and too low creation\n", CYAN_BOLD);
	try
	{
		Bureaucrat Sleeper1("Bernd", 1500);
	}
	catch(const std::exception &e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Sleeper2("Olaf", -10);
	}
	catch(const std::exception &e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
	}


    putStr("\nTest increasing\n", CYAN_BOLD);
	Bureaucrat bob("Bob", 2);
	std::cout << bob;
	try
	{
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
	}
	std::cout << bob;
	
	try
	{
	bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
	}
	std::cout << bob;


    putStr("\nTest decreasing\n", CYAN_BOLD);
	Bureaucrat tim("Tim", 149);
	std::cout << tim;
	try
	{
		tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
	}
	std::cout << tim;
	
	try
	{
	tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
    }
	std::cout << tim;


    putStr("Test ex02\n", CYAN_BOLD);

    putStr("\nTest ex02 ShrubberyCreationForm\n", CYAN_BOLD);
	Bureaucrat Mr_Shrubby("Mr_Shrubby", 130);
	ShrubberyCreationForm Shrubby_form("Hello");
    putStr("\n", RESET);
	std::cout << Shrubby_form;
	Mr_Shrubby.signForm(Shrubby_form);
	std::cout << Shrubby_form;
	Mr_Shrubby.executeForm(Shrubby_form);

    putStr("\nTest ex02 RobotomyRequestForm\n", CYAN_BOLD);
	RobotomyRequestForm Robo_form("I am a robo form");
	Bureaucrat Mr_Robo("Mr_Robo", 45);

	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.signForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);

    putStr("\nTest ex02 PresidentialPardonForm\n", CYAN_BOLD);
	PresidentialPardonForm President_form("I am a robo form");
	Bureaucrat Mr_President("Mr_President", 5);

	Mr_Robo.executeForm(President_form);
	Mr_Robo.signForm(President_form);

	Mr_President.executeForm(President_form);
	Mr_President.signForm(President_form);
	Mr_President.executeForm(President_form);
	

    putStr("\nTest ex03 Intern\n", CYAN_BOLD);

	Intern Jr_Intern;
	AForm *robo_intern;

	robo_intern = Jr_Intern.makeForm("DoYouKnowMe", "Hmmmm");
	robo_intern = Jr_Intern.makeForm("RobotomyRequestForm", "World");

    putStr(robo_intern->getName() + "\n", CYAN_BOLD);
	delete robo_intern;
	return (0);
}