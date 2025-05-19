#include "ScalarConverter.hpp"
#include <sstream>

template<typename T>
std::string toString(T value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << value;
    return oss.str();
}

bool isFloat(std::string &stringLiteral) {
    if (stringLiteral.find('.') == stringLiteral.npos)
        return false;
    char lastChar = stringLiteral[stringLiteral.length() - 1];
    if (lastChar != 'f' && lastChar != 'F') {
        return false;
    }
    std::string floatString = stringLiteral.substr(0, stringLiteral.length() - 1);
    char *end;
    strtod(floatString.c_str(), &end);
    if (*end != '\0')
        return false;
    return true;
}

bool isDouble(const std::string &stringLiteral) {
    char *end;
    strtod(stringLiteral.c_str(), &end);
    if (stringLiteral.find('.') == stringLiteral.npos)
        return false;
    return (*end == '\0' && end != stringLiteral.c_str());
}

bool isChar(std::string &stringLiteral) {
    return stringLiteral.length() == 1 && std::isprint(stringLiteral[0]) && !std::isdigit(stringLiteral[0]);
}

bool isInff(std::string &stringLiteral) {
    return (stringLiteral == "+inff" || stringLiteral == "+inf" ||
            stringLiteral == "-inff" || stringLiteral == "-inf" ||
            stringLiteral == "nan" || stringLiteral == "nanf");
}

void charConversion(std::string &stringLiteral) {
	isprint(stringLiteral[0]);
    if (isprint(stringLiteral[0]))
        putStr("char: '" + std::string(1, stringLiteral[0]) + "'\n", GREEN);
    else
        putStr("char: Non displayable\n", RED);

    int intNumber = static_cast<int>(stringLiteral[0]);
    putStr("int: " + toString(intNumber) + "\n", GREEN);
    putStr("float: " + toString(static_cast<float>(intNumber)) + "f\n", GREEN);
    putStr("double: " + toString(static_cast<double>(intNumber)) + "\n", GREEN);
}

void intConversion(std::string &stringLiteral) {
    try {
        for (size_t i = 0; i < stringLiteral.length(); ++i)
            if (!std::isdigit(stringLiteral[i]) && stringLiteral[i] != '-' && stringLiteral[i] != '+')
                throw std::exception();

        long representation = std::atol(stringLiteral.c_str());
        if (representation < std::numeric_limits<int>::min() || representation > std::numeric_limits<int>::max())
            throw std::exception();

        putStr("char: ", GREEN);
        if (representation < 255 && representation > -1 && std::isprint(representation))
            putStr("'" + std::string(1, static_cast<char>(representation)) + "'\n", GREEN);
        else if (representation >= 0 && representation <= 127)
            putStr("Non displayable\n", RED);
        else
            putStr("impossible\n", RED);

        putStr("int: " + toString(static_cast<int>(representation)) + "\n", GREEN);
        putStr("float: " + toString(static_cast<float>(representation)) + "f\n", GREEN);
        putStr("double: " + toString(static_cast<double>(representation)) + "\n", GREEN);
    } catch (std::exception &e) {
        putStr("char: impossible\n", GREEN);
        putStr("int: impossible\n", GREEN);
        putStr("float: nanf\n", GREEN);
        putStr("double: nan\n", GREEN);
    }
}

void floatConversion(std::string &stringLiteral) {
    try {
        float floatNumber = std::atof(stringLiteral.c_str());
        if (floatNumber < 255 && floatNumber > -1 && std::isprint(floatNumber))
            putStr("char: '" + std::string(1, static_cast<char>(floatNumber)) + "'\n", CYAN_BOLD);
        else if (floatNumber >= 0 && floatNumber <= 127)
            putStr("char: Non displayable\n", CYAN);
        else
            putStr("char: impossible\n", RED);

        putStr("int: " + toString(static_cast<int>(floatNumber)) + "\n", GREEN);
        putStr("float: " + toString(floatNumber) + "f\n", GREEN);
        putStr("double: " + toString(static_cast<double>(floatNumber)) + "\n", GREEN);
    } catch(const std::exception& e) {
        putStr("char: impossible\n", GREEN);
        putStr("int: impossible\n", GREEN);
        putStr("float: nanf\n", GREEN);
        putStr("double: nan\n", GREEN);
    }
}

void doubleConversion(std::string &stringLiteral) {
    try {
        double doubleNumber = std::atof(stringLiteral.c_str());
        if (doubleNumber < 255 && doubleNumber > -1 && std::isprint(doubleNumber))
            putStr("char: '" + std::string(1, static_cast<char>(doubleNumber)) + "'\n", CYAN_BOLD);
        else if (doubleNumber >= 0 && doubleNumber <= 127)
            putStr("char: Non displayable\n", MAGENTA);
        else
            putStr("char: impossible\n", RED);

        putStr("int: " + toString(static_cast<int>(doubleNumber)) + "\n", GREEN);
        putStr("float: " + toString(static_cast<float>(doubleNumber)) + "f\n", GREEN);
        putStr("double: " + toString(doubleNumber) + "\n", GREEN);
    } catch (std::exception &e) {
        putStr("char: impossible\n", GREEN);
        putStr("int: impossible\n", GREEN);
        putStr("float: nanf\n", GREEN);
        putStr("double: nan\n", GREEN);
    }
}

void infinityConversion(std::string stringLiteral){
    if (stringLiteral == "+inff" || stringLiteral == "+inf") {
        putStr("char: impossible\n", GREEN);
        putStr("int: impossible\n", GREEN);
        putStr("float: +inff\n", GREEN);
        putStr("double: +inf\n", GREEN);
    }
    else if (stringLiteral == "-inff" || stringLiteral == "-inf") {
        putStr("char: impossible\n", GREEN);
        putStr("int: impossible\n", GREEN);
        putStr("float: -inff\n", GREEN);
        putStr("double: -inf\n", GREEN);
    }
    else if (stringLiteral == "nan" || stringLiteral == "nanf") {
        putStr("char: impossible\n", GREEN);
        putStr("int: impossible\n", GREEN);
        putStr("float: nanf\n", GREEN);
        putStr("double: nan\n", GREEN);
    }
}

void ScalarConverter::convert(std::string stringLiteral) {
    if (isFloat(stringLiteral))
        floatConversion(stringLiteral);
    else if (isDouble(stringLiteral))
        doubleConversion(stringLiteral);
    else if (isChar(stringLiteral))
        charConversion(stringLiteral);
    else if (isInff(stringLiteral))
        infinityConversion(stringLiteral);
    else
        intConversion(stringLiteral);
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

void putStr(const std::string &str, const std::string &color) {
    std::cout << color << str << RESET;
}

void putNum(int bits, const std::string &color) {
    std::cout << color << bits << RESET;
}

void putErr(const std::string &str, const std::string &color) {
    std::cerr << color << str << RESET;
}
