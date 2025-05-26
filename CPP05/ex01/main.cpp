#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    putStr("\nTest 01\n", CYAN_BOLD);
    putStr("\nTest too high and too low creation\n", CYAN_BOLD);
    try
    {
        Bureaucrat Sleeper1("Bernd", 1500);
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RESET);
    }

    try
    {
        Bureaucrat Sleeper2("Olaf", -10);
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RESET);
    }
    putStr("\nTest 02\n", CYAN_BOLD);
    putStr("\nTest increasing\n", CYAN_BOLD);
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
        putStr("\n", RESET);
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
        putStr("\n", RESET);
    }
    std::cout << bob;

    putStr("\nTest 03\n", CYAN_BOLD);
    putStr("\nTest decreasing\n", CYAN_BOLD);
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
        putStr("\n", RESET);
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
        putStr("\n", RESET);    
    }
    std::cout << tim;

    putStr("\nTest 04\n", CYAN_BOLD);
    putStr("Test sign form\n", CYAN_BOLD);
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