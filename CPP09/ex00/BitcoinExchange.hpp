#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <iomanip>
# include <exception>
# include <algorithm>
# include <limits>
# include <string>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

class BitcoinExchange {
	private:
		std::map<std::string, double> _data;
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void get_data();

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void execute(int argc,char **argv);
		void outputData(const std::string& date, double btc_amount);
};

void putStr(std::string str, std::string color);
void putNum(int bits, std::string color);
void putErr(std::string str, std::string color);

#endif