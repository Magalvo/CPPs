#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    putStr("Test too high and too low creation\n", CYAN_BOLD);
	std::cout << "\033[33m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;
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
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}


    putStr("\nTest increasing\n", CYAN_BOLD);
	std::cout << "\033[33m" << std::endl << "Test increasing" << "\033[0m" << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob;
	try
	{
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;
	
	try
	{
	bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
	    std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;


    putStr("\nTest decreasing\n", CYAN_BOLD);
	std::cout << "\033[33m" << std::endl << "Test decreasing" << "\033[0m" << std::endl;
	Bureaucrat tim("Tim", 149);
	std::cout << tim;
	try
	{
		tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;
	
	try
	{
	tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
        putErr("Exception caught: " + std::string(e.what()) + "\n", RED);
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	std::cout << tim;


    putStr("Test ex02\n", CYAN_BOLD);
	std::cout << "\033[33m" << std::endl << "Test ex02" << "\033[0m" << std::endl;

    putStr("\nTest ex02 ShrubberyCreationForm\n", CYAN_BOLD);
	std::cout << "\033[33m" << std::endl << "Test ex02 ShrubberyCreationForm" << "\033[0m" << std::endl;
	Bureaucrat Mr_Shrubby("Mr_Shrubby", 130);
	ShrubberyCreationForm Shrubby_form("Hello");
    putStr("\n", RESET);
	std::cout << std::endl;
	std::cout << Shrubby_form;
	Mr_Shrubby.signForm(Shrubby_form);
	std::cout << Shrubby_form;
	Mr_Shrubby.executeForm(Shrubby_form);

    putStr("\nTest ex02 RobotomyRequestForm\n", CYAN_BOLD);
	std::cout << "\033[33m" << std::endl << "Test ex02 RobotomyRequestForm" << "\033[0m" << std::endl;
	RobotomyRequestForm Robo_form("I am a robo form");
	Bureaucrat Mr_Robo("Mr_Robo", 45);

	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.signForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);

    putStr("\nTest ex02 PresidentialPardonForm\n", CYAN_BOLD);
	std::cout << "\033[33m" << std::endl << "Test ex02 PresidentialPardonForm" << "\033[0m" << std::endl;
	PresidentialPardonForm President_form("I am a robo form");
	Bureaucrat Mr_President("Mr_President", 5);

	Mr_Robo.executeForm(President_form);
	Mr_Robo.signForm(President_form);

	Mr_President.executeForm(President_form);
	Mr_President.signForm(President_form);
	Mr_President.executeForm(President_form);
	

    putStr("\nTest ex03 Intern\n", CYAN_BOLD);
	std::cout << "\033[33m" << std::endl << "Test ex03 Intern" << "\033[0m" << std::endl;

	Intern Jr_Intern;
	AForm *robo_intern;

	robo_intern = Jr_Intern.makeForm("DoYouKnowMe", "Hmmmm");
	robo_intern = Jr_Intern.makeForm("RobotomyRequestForm", "World");

    putStr(robo_intern->getName() + "\n", CYAN_BOLD);
	std::cout << robo_intern->getName() << std::endl;
	delete robo_intern;
	return (0);
}