#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		putErr(std::string("Usage: ") + argv[0] + " <input_file>\n", RED);
		// std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange;
		exchange.readDb("data.csv");
		exchange.run(argv[1]);
	} catch (const std::exception &e) {
		putErr(e.what(), RED);
		// std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}