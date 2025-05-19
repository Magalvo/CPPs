#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
        putErr("Error: Invalid number of arguments\n", RED_BLINK);
        return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}