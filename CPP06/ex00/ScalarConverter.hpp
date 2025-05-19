#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>
#pragma once

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

class ScalarConverter
{
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

public:
    static void convert(std::string stringLiteral);
};

void putStr(const std::string &str, const std::string &color);
void putNum(int bits, const std::string &color);
void putErr(const std::string &str, const std::string &color);

#endif