#include "ScalarConverter.hpp"

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
	if (stringLiteral.length() != 1)
	{
		return false;
	}
	if (!isdigit(stringLiteral[0]))
		return true;
	return false;
}

bool isInff(std::string &stringLiteral) {
	if (stringLiteral == "+inff" || stringLiteral == "+inff" ||
	stringLiteral == "-inf" || stringLiteral == "-inf" || stringLiteral == "nan" || stringLiteral == "nanf")
		return true;
	return false;
}

void charConversion(std::string &stringLiteral) {
	if (isprint(stringLiteral[0]))
		putStr("char: '" + std::string(1, stringLiteral[0]) + "'\n", GREEN);
	else
        putStr("char: Non displayable\n", RED);
	int intNumber = static_cast<int>(stringLiteral[0]);
    putStr("int: " + std::to_string(intNumber) + "\n", GREEN);
	float floatNumber = static_cast<float>(intNumber);
    putStr("float: " + std::to_string(floatNumber) + "f\n", GREEN);
	double doubleNumber = static_cast<double>(intNumber);
    putStr("double: " + std::to_string(doubleNumber) + "\n", GREEN);
}

void intConversion(std::string &stringLiteral) {
    putStr("int: \n", GREEN);
	try {
		for (int ctd = 0; stringLiteral[ctd]; ctd++)
			if (!std::isdigit(stringLiteral[ctd]) && stringLiteral[ctd]!= '-' && stringLiteral[ctd]!= '+')
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
		std::cout << "int: " << representation << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(representation) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(representation) << std::endl;
	} catch (std::exception &e) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}

void floatConversion(std::string &stringLiteral) {
	try
	{
		if (stringLiteral.find('-') != stringLiteral.npos && stringLiteral.length() > 10)
			throw std::exception();
		else if (stringLiteral.find('-') == stringLiteral.npos && stringLiteral.length() > 9)
			throw std::exception();
			
		float floatNumber = std::atof(stringLiteral.c_str());
		if (floatNumber < 255 && floatNumber > -1 && std::isprint(floatNumber))
			std::cout << "char: '" << static_cast<char>(floatNumber) << "'" << std::endl;
		else if (floatNumber >= 0 && floatNumber <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << static_cast<int>(floatNumber) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << floatNumber << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(floatNumber) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	
}

void doubleConversion(std::string &stringLiteral) {
	try {
		if (stringLiteral.find('-') != stringLiteral.npos && stringLiteral.length() > 9)
			throw std::exception();
		else if (stringLiteral.find('-') == stringLiteral.npos && stringLiteral.length() > 8)
			throw std::exception();
		double doubleNumber = std::atof(stringLiteral.c_str());
		if (doubleNumber < 255 && doubleNumber > -1 && std::isprint(doubleNumber))
			std::cout << "char: '" << static_cast<char>(doubleNumber) << "'" << std::endl;
		else if (doubleNumber >= 0 && doubleNumber <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << static_cast<int>(doubleNumber) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(doubleNumber) << "f" << std::endl;
		std::cout << "double: " << doubleNumber << std::endl;
	} catch (std::exception &e) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}

void infinityConvesion(std::string stringLiteral){
	if (stringLiteral == "+inff" || stringLiteral == "+inf") {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "+inf" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if (stringLiteral == "-inff" || stringLiteral == "-inf") {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "-inf" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else if (stringLiteral == "nan" || stringLiteral == "nanf") {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
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
		infinityConvesion(stringLiteral);
	else
		intConversion(stringLiteral);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}


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