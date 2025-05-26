#include "BitcoinExchange.hpp"

template<typename T>
std::string toString(T value, int precision = 2) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    return oss.str();
}

void putStr(std::string str, std::string color)
{
    std::cout << color << str << RESET;
}

void putNum(double v, std::string const& color, int prec = 2) {
    std::cout << color << toString(v,prec) << RESET;
}

void putErr(std::string str, std::string color)
{
    std::cerr << color << str << RESET;
}

BitcoinExchange::BitcoinExchange() {
	get_data();
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	(void)other;
	return *this;
}

void BitcoinExchange::get_data() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		throw std::runtime_error("Error data.csv: file not found");
	}

	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("Error data.csv: invalid file format");
	}

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		double btc_data;
		
		std::getline(iss, date, ',');
		iss >> btc_data;
		_data[date] = btc_data;
	}
}

void removeSpaces(std::string &str) {
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}


bool isValidDateString(const std::string& date, int& _year, int& _month, int& _day) {
    if (date.size() != 10 ||
        date[4] != '-'  || date[7] != '-')
        return false;
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i]))) 
            return false;
    }
    _year = std::atoi(date.substr(0,4).c_str());
    _month = std::atoi(date.substr(5,2).c_str());
    _day = std::atoi(date.substr(8,2).c_str());
    if (_year < 2009 || _month < 1 || _month > 12 || _day < 1) return false;

    static const int mdays[13] = {
      0,31,28,31,30,31,30,31,31,30,31,30,31
    };
    int maxd = mdays[_month];
    if (_month == 2 && ((_year%4==0 && _year%100!=0) || (_year%400==0)))
      maxd = 29;
    return _day <= maxd;
}


bool checkline(std::string line)
{
	if (line.empty())
		return false;
	if (line.find_first_of("|") == std::string::npos)
		return false;
	std::string date = line.substr(0, line.find_first_of("|"));
	std::string value = line.substr(line.find_first_of("|") + 1);
	if (date.empty() || value.empty())
		return false;
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return false;
	if (value.find_first_not_of("0123456789.-") != std::string::npos)
		return false;
	return true;
}

void parseInput(std::string &line, std::ifstream &file, int argc, char **argv)
{
    if (argc != 2)
        throw std::runtime_error("Usage: ./btc [input-file]");

    file.open(argv[1]);
    if (!file.is_open())
        throw std::runtime_error("Error: file not found");

    
    std::getline(file, line);
    std::string hdr = line;
    hdr.erase(std::remove(hdr.begin(), hdr.end(), ' '), hdr.end());

    if (hdr != "date|value")
        throw std::runtime_error("Error: invalid input file format");
}

void BitcoinExchange::outputData(const std::string& date, double btc_amount)
{
    std::map<std::string,double>::const_iterator it = _data.lower_bound(date);

    if (it == _data.end() || it->first != date) {
        if (it == _data.begin()) {
            putErr("Error: date before earliest rate => ", RED_BLINK);
            putErr(date + "\n", RED_BLINK);
            return;
        }
        --it;
    }

    double rate   = it->second;
    double result = rate * btc_amount;
    if (result > std::numeric_limits<int>::max()) {
        putErr("Error: too large a number.\n", RED_BLINK);
        return;
    }

    putStr("Date: ", CYAN_BOLD);
    putStr(date, CYAN_BOLD);

    putStr(" | Rate: ", CYAN_BOLD);
    putNum(rate, CYAN_BOLD, 2);

    putStr(" | Amount: ", CYAN_BOLD);
    putNum(btc_amount, CYAN_BOLD, 2);

    putStr(" | Result: ", CYAN_BOLD);
    putNum(result, CYAN_BOLD, 2);

    putStr("\n", CYAN_BOLD);
}




void BitcoinExchange::execute(int argc, char **argv) {
	std::ifstream file;
	std::string line;
	parseInput(line, file, argc, argv);

	while (std::getline(file, line)) {
		std::string parsedLine = line;
		removeSpaces(parsedLine);
		if (!checkline(parsedLine))
		{
            putErr("Error: bad input => ", RED_BLINK);
            putErr(line + "\n", MAGENTA);
			continue;
		}
		std::istringstream iss(parsedLine);
		std::string date;
		double btc_data;

		std::getline(iss, date, '|');
		iss >> btc_data;
        int year, month, day;
		if (date < "2009-01-02" || !isValidDateString(date, year, month, day)) {
            putErr("Error: date out of range => ", RED_BLINK);
            putErr(line + "\n", MAGENTA);
			continue;
		}
		if (btc_data < 0) {
            putErr("Error: not a positive number.\n", RED_BLINK);
			continue;
		}
		else if (btc_data > 1000) {
            putErr("Error: number bigger then 1000. => ", RED_BLINK);
            putErr(toString(btc_data) + " > 1000 \n", MAGENTA);
			continue;
		}
		outputData(date, btc_data);
	}
	file.close();
}