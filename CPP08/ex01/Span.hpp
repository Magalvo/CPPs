#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <limits>
# include <cstdlib>
# include <ctime>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

class Span {
    private:
        unsigned int _n;
        std::vector<int> _v;
        bool _isSorted;

    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);

        void addNumber(int num);

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end) {
            if (std::distance(begin, end) > static_cast<long>(_n - _v.size()))
                throw std::runtime_error("Not enough space in Span");
            
            _v.insert(_v.end(), begin, end);
            _isSorted = false;
        }

        int shortestSpan();
        int longestSpan();
};

void putStr(std::string str, std::string color);
void putNum(int bits, std::string color);
void putErr(std::string str, std::string color);

#endif