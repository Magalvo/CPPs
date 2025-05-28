#include "RPN.hpp"

// ? Tests
// ? ./RPN "1 2 * 0 / 0 * 2 4 - +"
// ? ./RPN "1 2 + 3 * 4 - 5 /"
// ? ./RPN "1 2 + 3 * 4 - 5 / 6 +"
// ? ./RPN "1 2 + 3 * 4 - 5 / 6 + 7 *"
// ? ./RPN "1 2 + 3 * 4 - 5 / 6 + 7 * 8 /"
// ? ./RPN "7 7 * 7 -"
// ? ./RPM "8 9 * 9 - 9 - 9 - 4 - 1 +"
// ? ./RPN "(1 + 1)"

int main(int argc, char **argv) {
	try {
		RPN rpn;
		rpn.parse(argc, argv);
	} catch (std::exception &e) {
        putErr(e.what(), RED_BLINK);
        putStr("\n", RESET);
	}
	return (0);
}