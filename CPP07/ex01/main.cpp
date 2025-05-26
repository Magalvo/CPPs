#include "iter.hpp"

void putStr(const std::string &str, const std::string &color) {
    std::cout << color << str << RESET;
}

void putNum(int bits, const std::string &color) {
    std::cout << color << bits << RESET;
}

void putErr(const std::string &str, const std::string &color) {
    std::cerr << color << str << RESET;
}

int main() {
    
	int arr[] = {1, 2, 3, 4, 5};
	::iter(arr, 5, ::print<int>);
    putStr("\n", RESET);
    putStr("------------", GREEN);
    putStr("\n", RESET);

    //------------------------------------------------------

	char arr2[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(arr2, 5, ::print<char>);
    putStr("\n", RESET);
    putStr("------------", GREEN);
    putStr("\n", RESET);
    
	std::string arr3[] = {"Hello", "World", "!"};
	::iter(arr3, 3, ::print<std::string>);
    
	return (0);
}

