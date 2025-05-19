#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    putStr("\nTest 01\n", CYAN_BOLD);
    std::cout << "\033[33m" << std::endl
              << "Test ex01" << "\033[0m" << std::endl;
    putStr("\nTest too high and too low creation\n", CYAN_BOLD);
    std::cout << "\033[33m" << std::endl
              << "Test too high and too low creation" << "\033[0m" << std::endl;
    try
    {
        Bureaucrat Sleeper1("Bernd", 1500);
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        std::cout << std::endl;
    }

    try
    {
        Bureaucrat Sleeper2("Olaf", -10);
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        std::cout << std::endl;
    }
    putStr("\nTest 02\n", CYAN_BOLD);
    putStr("\n Test increasing\n", CYAN_BOLD);
    std::cout << "\033[33m" << std::endl
              << "Test increasing" << "\033[0m" << std::endl;
    Bureaucrat bob("Bob", 2);
    std::cout << bob;
    try
    {
        bob.incrementGrade();
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        std::cout << std::endl;
    }
    std::cout << bob;

    try
    {
        bob.incrementGrade();
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        std::cout << std::endl;
    }
    std::cout << bob;

    putStr("\nTest 03\n", CYAN_BOLD);
    putStr("\n Test decreasing\n", CYAN_BOLD);
    std::cout << "\033[33m" << std::endl
              << "Test decreasing" << "\033[0m" << std::endl;
    Bureaucrat tim("Tim", 149);
    std::cout << tim;
    try
    {
        tim.decrementGrade();
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        std::cout << std::endl;
    }
    std::cout << tim;

    try
    {
        tim.decrementGrade();
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        std::cout << std::endl;
    }
    std::cout << tim;

    putStr("\nTest 04\n", CYAN_BOLD);
    putStr("Test sign form\n", CYAN_BOLD);
    std::cout << "\033[33m" << std::endl
              << "Test ex01" << "\033[0m" << std::endl;

    Form id_form("ID FORM", 100, 90);
    Bureaucrat mr_slow("MR SLOW", 150);
    Bureaucrat mr_id("MR_ID", 100);
    std::cout << id_form;

    // ? MR SLOW
    putStr("\nMR SLOW\n", RED);
    mr_slow.signForm(id_form);
    putStr("Sign Grade: ", GREEN);
    putNum(id_form.getSignGrade(), YELLOW);

    putStr("\nExecute Grade: ", GREEN);
    putNum(id_form.getExecuteGrade(), MAGENTA);

    putStr("\nIs signed : ", GREEN);
    putNum(id_form.getIsSigned(), GREEN);

    putStr("\nGrade : ", GREEN);
    putNum(mr_slow.getGrade(), GREEN);
    putStr("\n", RESET);
    std::cout << CYAN_BOLD << id_form << RESET;

    // ? MR ID
    putStr("\nMR_ID\n", RED);
    mr_id.signForm(id_form);
    putStr("Sign Grade: ", GREEN);
    putNum(id_form.getSignGrade(), YELLOW);

    putStr("\nExecute Grade: ", GREEN);
    putNum(id_form.getExecuteGrade(), MAGENTA);

    putStr("\nIs signed : ", GREEN);
    putNum(id_form.getIsSigned(), GREEN);

    putStr("\nGrade : ", GREEN);
    putNum(mr_id.getGrade(), GREEN);
    putStr("\n", RESET);
    std::cout << CYAN_BOLD << id_form << RESET;

    return (0);
}