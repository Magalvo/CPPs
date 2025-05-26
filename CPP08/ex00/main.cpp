#include "Easyfind.hpp"

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

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int arr2[] = {10, 20, 30, 40, 50};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	std::list<int> lst(arr2, arr2 + sizeof(arr2) / sizeof(int));

	try {
		putStr("\nFound: ", GREEN);
		putNum(easyfind(vec, 3), GREEN);
		putStr("\nFound: ", GREEN);
		putNum(easyfind(lst, 20), GREEN);
		putStr("\nFound: ", GREEN);
		putNum(easyfind(vec, 6), GREEN);
	} catch (std::exception &e) {
		putStr(e.what(), RED);
		putStr("\n", RESET);
		// std::cout << e.what() << std::endl;
	}
	return 0;
}