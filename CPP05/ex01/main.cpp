#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    //! TEST 1
    putStr("\nTest 01\n", CYAN_BOLD);
    putStr("Test too high and too low creation\n", CYAN_BOLD);
    try {
        Bureaucrat Sleeper1("Bernd", 1500);
    }
    catch (const std::exception &e) {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RESET);
    }
    try {
        Bureaucrat Sleeper2("Olaf", -10);
    }
    catch (const std::exception &e) {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RESET);
    }
    putStr("-------------------------------------\n", RESET);
    
    //! -------------------------------------
    //! TEST 2
    putStr("\nTest 02\n", CYAN_BOLD);
    putStr("Test increasing\n", CYAN_BOLD);
    Bureaucrat bob("Bob", 2);
    std::cout << bob;
    try {
        bob.incrementGrade();
    }
    catch (const std::exception &e) {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RESET);
    }
    std::cout << bob;

    try {
        bob.incrementGrade();
    }
    catch (const std::exception &e) {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RESET);
    }
    std::cout << bob;
    putStr("-------------------------------------\n", RESET);
    
    //! -------------------------------------
    //! TEST 3
    putStr("\nTest 03\n", CYAN_BOLD);
    putStr("Test decreasing\n", CYAN_BOLD);

    Bureaucrat tim("Tim", 149);
    std::cout << tim;
    try {
        tim.decrementGrade();
    }
    catch (const std::exception &e) {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RESET);
    }
    std::cout << tim;

    try {
        tim.decrementGrade();
    }
    catch (const std::exception &e) {
        putStr("Exception caught: ", RED);
        putStr(e.what(), RED);
        putStr("\n", RESET);
    }
    std::cout << tim;
    putStr("-------------------------------------\n", RESET);
    
    //! -------------------------------------
    //! TEST 4
    putStr("\nTest 04\n", CYAN_BOLD);
    putStr("Test sign form\n", CYAN_BOLD);

    Form id_form("ID FORM", 100, 90);
    Bureaucrat mr_watson("MR WATSON", 150);
    Bureaucrat mr_sherlock("MR SHERLOCK", 100);
    std::cout << id_form;

    //? MR WATSON
    putStr("\nMR WATSON\n", RED);
    putStr("Grade : ", GREEN);
    putNum(mr_watson.getGrade(), GREEN);
    putStr("\n", RESET);
    putStr("Sign Grade: ", GREEN);
    putNum(id_form.getSignGrade(), YELLOW);
    putStr("\n", RESET);
    mr_watson.signForm(id_form);
    putStr("Execute Grade: ", GREEN);
    putNum(id_form.getExecuteGrade(), MAGENTA);
    putStr("\nIs signed : ", GREEN);
    putNum(id_form.getIsSigned(), GREEN);
    putStr("\n", RESET);

    //? MR SHERLOCK
    putStr("\nMR_SHERLOCK\n", RED);
    putStr("Grade : ", GREEN);
    putNum(mr_sherlock.getGrade(), GREEN);
    putStr("\n", RESET);
    putStr("Sign Grade: ", GREEN);
    putNum(id_form.getSignGrade(), YELLOW);
    putStr("\n", RESET);
    mr_sherlock.signForm(id_form);
    putStr("Execute Grade: ", GREEN);
    putNum(id_form.getExecuteGrade(), MAGENTA);
    putStr("\nIs signed : ", GREEN);
    putNum(id_form.getIsSigned(), GREEN);
    putStr("\n", RESET);

    return 0;
}