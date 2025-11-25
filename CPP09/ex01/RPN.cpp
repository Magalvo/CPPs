#include "RPN.hpp"

void putStr(std::string str, std::string color)
{
    std::cout << color << str << RESET;
}

void putErr(std::string str, std::string color)
{
    std::cerr << color << str << RESET;
}

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &assign)
{
    if (this != &assign)
    {
        this->_stack = assign._stack;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::run(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
            continue;
        

        if (input[i] >= '0' && input[i] <= '9')
        {
            _stack.push(input[i] - '0');
        }

        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            if (_stack.size() < 2)
            {
                putErr("Error\n", RED);
                // std::cerr << "Error" << std::endl;
                return;
            }

            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();

            if (input[i] == '+')
                _stack.push(b + a);
            else if (input[i] == '-')
                _stack.push(b - a);
            else if (input[i] == '*')
                _stack.push(b * a);
            else if (input[i] == '/')
            {
                if (a == 0)
                {
                    putErr("Error\n", RED);
                    // std::cerr << "Error" << std::endl;
                    return;
                }
                _stack.push(b / a);
            }
        }
        else
        {
            putErr("Error\n", RED);
            // std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1)
    {
        putErr("Error\n", RED);
        // std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}

