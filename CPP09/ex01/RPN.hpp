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

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"


class RPN {
	private:
		std::stack<double, std::list<double> > _stack;
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		bool isOperator(const std::string &token);
		double calculate(double a, double b, const std::string &op);
		void checkExpression(const std::string &expression);

	public:
		RPN();
		~RPN();
		void parse(int argc, char **argv);
};


void putStr(std::string str, std::string color);
void putErr(std::string str, std::string color);

#endif