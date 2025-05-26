#ifndef RPN_HPP
#define RPN_HPP
#pragma once

#include <exception>
#include <iostream> 
#include <map>
#include <sstream>
#include <string>
#include <stack>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

class RPM {
    private:
        static double add (double a, double b);
        static double sub (double a, double b);
        static double mlt (double a, double b);
        static double div (double a, double b);

        static bool isTerm(const std::string &str);
        static bool isOperator(const std::string &str);
        static bool isNumber(const std::string &str);
        static double toNumber(const std::string &str);
        static void checkStackSize(const std::stack<double> &stack, size_t size);

    protected:
        RPN(void):
        RPN(RPN const &other) = delete,
        RPN &operator=(RPN const &other) = delete;

    public:
        ~RPM();

        static double calculate(const std::string &expression);
    
    class exception : public std::exception {
        public:
            exception(const std::string &msg) : _msg(msg) {}
            virtual ~exception() throw() {}
            virtual const char *what() const throw() {
                return _msg.c_str();
            }
        private:
            std::string _msg;
    };
};

void putStr(std::string str, std::string color);
void putNum(int bits, std::string color);
void putErr(std::string str, std::string color);

#endif // RPN_HPP