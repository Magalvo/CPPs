#include "Bureaucrat.hpp"

int main(void)
{
    putStr("Test 01\n", CYAN_BOLD);
    putStr("Testing HIGH and LOW\n", CYAN_BOLD);
    // ? LOW
    try
    {
        Bureaucrat Sleeper1("Bernardo", 1500);
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RED);
    }

    // ? HIGH
    try
    {
        Bureaucrat Sleeper2("Olek", -10);
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RED);
    }

    // ------------------------------------------------------------

    putStr("\nTest increasing\n", CYAN_BOLD);
    
    Bureaucrat bob("Bob", 2);

    std::cout << GREEN << bob << RESET;
    //? (-1) (Increment Grade)
    try
    {
        bob.incrementGrade();
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RED);
    }
    std::cout << GREEN << bob << RESET;
    //? (-1) (Increment Grade)
    try
    {
        bob.incrementGrade();
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RED);
    }
    std::cout << GREEN << bob << RESET;

    // ============================================

    putStr("\nTest decreasing\n", CYAN_BOLD);
    Bureaucrat tim("Tim", 149);
    std::cout << GREEN << tim << RESET;
    //? (+1) (Decrement Grade)
    try
    {
        tim.decrementGrade();
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RED);
    }
    std::cout << GREEN << tim << RESET;
    //? (+1) (Decrement Grade)
    try
    {
        tim.decrementGrade();
    }
    catch (const std::exception &e)
    {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RED);
    }
    std::cout << GREEN << tim << RESET;


    return (0);
}