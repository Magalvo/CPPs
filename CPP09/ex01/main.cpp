#include "RPN.hpp"

// ? Tests
// ? ./RPN "1 2 * 0 / 0 * 2 4 - +"
// ? ./RPN "1 2 + 3 * 4 - 5 /"
// ? ./RPN "1 2 + 3 * 4 - 5 / 6 +"
// ? ./RPN "1 2 + 3 * 4 - 5 / 6 + 7 *"
// ? ./RPN "1 2 + 3 * 4 - 5 / 6 + 7 * 8 /"
// ? ./RPN "7 7 * 7 -"
// ? ./RPM "8 9 * 9 - 9 - 9 - 4 - 1 +"
// ? ./RPN "(1 + 1)"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl; 
        return 1;
    }
    
    RPN rpn;
    rpn.run(argv[1]);
    
    return 0;
}