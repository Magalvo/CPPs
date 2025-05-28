#include "RPN.hpp"

void putStr(std::string str, std::string color)
{
    std::cout << color << str << RESET;
}

void putNum(int bits, std::string color)
{
    std::cout << color << bits << RESET;
}

void putErr(std::string str, std::string color)
{
    std::cerr << color << str << RESET;
}

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	(void)other;
	return *this;
}

bool RPN::isOperator(const std::string &token) {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

double RPN::calculate(double a, double b, const std::string &op)
{
	if (op == "+")
		return a + b;
    else if (op == "-")
		return a - b;
    else if (op == "*")	
		return a * b;
   else {
        if (b == 0) 
			throw std::runtime_error("Error! Division by zero(0) ┻━┻ ︵ヽ(`Д´)ﾉ︵ ┻━┻");
        return a / b;
    }
}

void RPN::checkExpression(const std::string &expression) {
	if (expression.empty()) {
		throw std::runtime_error("Expression Error! (╯°□°）╯︵ ┻━┻");
	}
	if (expression.find_first_not_of("0123456789+-*/ ") != std::string::npos) {
		throw std::runtime_error("Expression Error! (╯°□°）╯︵ ┻━┻");
	}
	for (size_t i = 0; i < expression.size(); i++) {
		if (expression[i] == ' ') 
			i++;
		if (isOperator(std::string(1, expression[i]))) {
			if (!(expression[i + 1] == ' ' || expression[i + 1] == '\0')) {
				throw std::runtime_error("Expression Error! (╯°□°）╯︵ ┻━┻");
			}
		} else if (expression[i] >= '0' && expression[i] <= '9') {
			if (!(expression[i + 1] == ' ' || expression[i + 1] == '\0')) {
				throw std::runtime_error("Expression Error! (╯°□°）╯︵ ┻━┻");
			}
		}
		
	}
}

void RPN::parse(int argc, char **argv) {
	if (argc != 2) {
		throw std::runtime_error("Usage: (┛✧Д✧))┛ ./rpn \"expression\"");
	}
	std::string expression = argv[1];
	checkExpression(expression);
	
	std::istringstream iss(expression);
	std::string token;
	double a, b, result;
	while (iss >> token) {
		if (isOperator(token)) {
			if (_stack.size() < 2) {
				throw std::runtime_error("Parse Error! ┻━┻ ︵ヽ(`Д´)ﾉ︵ ┻━┻");
			}
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			result = calculate(b, a, token);
			_stack.push(result);
		} else {
			double number;
            std::istringstream numStream(token);
            if (!(numStream >> number)) {
                throw std::runtime_error("Parse Error! ┻━┻ ︵ヽ(`Д´)ﾉ︵ ┻━┻");
            }
            _stack.push(number);
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("Parse Error! ┻━┻ ︵ヽ(`Д´)ﾉ︵ ┻━┻");
	}
    putStr("Result: (☞ﾟヮﾟ)☞ ", CYAN_BOLD);
    putNum(static_cast<int>(_stack.top()), GREEN);
    putStr(" ☜(ﾟヮﾟ☜)", CYAN_BOLD);
    // putStr(" ୧(๑•̀ヮ•́)૭ LET'S GO!", MAGENTA);
    putStr("\n", RESET);
	// std::cout << _stack.top() << std::endl;
}