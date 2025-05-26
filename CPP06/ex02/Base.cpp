#include "Base.hpp"
void putStr(const std::string &str, const std::string &color) {
    std::cout << color << str << RESET;
}

void putNum(int bits, const std::string &color) {
    std::cout << color << bits << RESET;
}

void putErr(const std::string &str, const std::string &color) {
    std::cerr << color << str << RESET;
}

Base::~Base() {}