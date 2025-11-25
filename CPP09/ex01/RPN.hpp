#ifndef RPN_HPP
# define RPN_HPP
# pragma once

# include <iostream>
# include <string>
# include <stdexcept>
# include <sstream>
# include <stack>
# include <list>
# include <algorithm>
# include <iomanip>
#include <cstdlib>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"


class RPN
{
    private:
        std::stack<int> _stack;

    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &assign);
        ~RPN();

        void run(std::string input);
};


void putStr(std::string str, std::string color);
void putErr(std::string str, std::string color);

#endif