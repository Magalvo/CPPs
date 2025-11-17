#include "Span.hpp"

Span::Span() : _n(0), _isSorted(true) {}

Span::Span(unsigned int N) : _n(N), _isSorted(true) {}

Span::~Span() {}

Span::Span(const Span &other) : _n(other._n), _v(other._v), _isSorted(other._isSorted) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _n = other._n;
        _v = other._v; 
        _isSorted = other._isSorted;
    }
    return *this;
}

void Span::addNumber(int num) {
    if (_v.size() >= _n)
        throw std::runtime_error("Span is full");
    _v.push_back(num);
    _isSorted = false;
}

int Span::shortestSpan() {
    if (_v.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");

    if (!_isSorted) {
        std::sort(_v.begin(), _v.end());
        _isSorted = true;
    }

    int minSpan = std::numeric_limits<int>::max();
    
    for (size_t i = 1; i < _v.size(); i++) {
        int span = _v[i] - _v[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() {
    if (_v.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");

    
    if (!_isSorted) {
        std::sort(_v.begin(), _v.end());
        _isSorted = true;
    }
    
    return _v.back() - _v.front();
}


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