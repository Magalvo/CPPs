#include "Span.hpp"
#include <vector>
#include <iostream>

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span bigSpan(15000);
    std::vector<int> vec;
    for (int i = 0; i < 15000; ++i) vec.push_back(i);
    
    try {
        bigSpan.addNumbers(vec.begin(), vec.end());
        std::cout << "Big Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big Longest: " << bigSpan.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}