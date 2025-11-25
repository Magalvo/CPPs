#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>   
#include <cstdlib>
#include <climits>
#include <cctype>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;

        void    _sortVector(std::vector<int> &arr);
        void    _insertVector(std::vector<int> &main, std::vector<int> &pending);

        std::vector<int> _generateJacobsthal(int n);

    
        void    _sortDeque(std::deque<int> &arr);
        void    _insertDeque(std::deque<int> &main, std::deque<int> &pending);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &assign);
        ~PmergeMe();


        void    parseArgs(int argc, char **argv);
        
 
        void    exec();
};

#endif