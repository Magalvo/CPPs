#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
    if (this != &assign)
    {
        this->_data = assign._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() 
{
    if (_file.is_open())
        _file.close();
}

void BitcoinExchange::readDb(std::string filename)
{
    _file.open(filename.c_str());
    if (!_file.is_open())
    {
        std::cout << "Error: could not open database file." << std::endl;
        exit(1);
    }

    std::string line;
    if (std::getline(_file, line)) {}

    while (std::getline(_file, line))
    {
        size_t delimiter = line.find(',');
        if (delimiter == std::string::npos)
            continue;
        
        std::string date = line.substr(0, delimiter);
        std::string value = line.substr(delimiter + 1);
        
        _data[date] = std::atof(value.c_str());
    }
    _file.close();
}

bool BitcoinExchange::parseDate(std::string date)
{
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009) return false; 
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap && day > 29) return false;
        if (!isLeap && day > 28) return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30) return false;
    }

    return true;
}

void BitcoinExchange::run(std::string filename)
{
    std::ifstream input(filename.c_str());
    if (!input.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line))
    {
        if (line == "date | value")
            continue;

        if (line.empty()) 
            continue;

        size_t delimiter = line.find('|');
        if (delimiter == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delimiter - 1); 
        std::string valueStr = line.substr(delimiter + 1);
        float value = std::atof(valueStr.c_str());

        if (parseDate(date) == false)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _data.lower_bound(date);

        if (it != _data.end() && it->first == date)
        {
            std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
        }
        else
        {
            if (it == _data.begin())
            {
                std::cout << "Error: bad input => " << date << " (too early)" << std::endl;
            }
            else
            {
                it--;
                std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
            }
        }
    }
    input.close();
}

void putStr(std::string str, std::string color)
{
    std::cout << color << str << RESET;
}

void putErr(std::string str, std::string color)
{
    std::cerr << color << str << RESET;
}