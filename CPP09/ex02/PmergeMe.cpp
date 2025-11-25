#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArgs(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string input = argv[i];
        size_t j = 0;

        while (j < input.length())
        {
            while (j < input.length() && std::isspace(input[j]))
                j++;

            if (j == input.length())
                break;

            size_t start = j;

            if (input[j] == '+')
                j++;
            
            if (j == input.length() || !std::isdigit(input[j]))
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }

            while (j < input.length() && std::isdigit(input[j]))
                j++;

            if (j < input.length() && !std::isspace(input[j]))
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }

            std::string numStr = input.substr(start, j - start);
            long val = std::atol(numStr.c_str());

            if (val < 0 || val > INT_MAX)
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }

            _vec.push_back(static_cast<int>(val));
            _deq.push_back(static_cast<int>(val));
        }
    }
}


std::vector<int> PmergeMe::_generateJacobsthal(int n)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    int last = 1;
    int prev = 0;
    
   
    for (int i = 2; ; ++i)
    {
        int next = last + 2 * prev;
        if (next >= n) {
            jacobsthal.push_back(n);
            break;
        }
        jacobsthal.push_back(next);
        prev = last;
        last = next;
    }
    return jacobsthal;
}

void PmergeMe::_sortVector(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return;

    int straggler = -1;
    bool hasStraggler = false;
    if (arr.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
    }

    _sortVector(mainChain);

    std::vector<int> pendingChain;
    
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == mainChain[i])
            {
                pendingChain.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j); 
                break;
            }
        }
    }

    if (!pendingChain.empty())
    {
        mainChain.insert(mainChain.begin(), pendingChain[0]);
    }

    std::vector<int> jacobSeq = _generateJacobsthal(pendingChain.size());

    for (size_t k = 1; k < jacobSeq.size(); k++)
    {

        int index = jacobSeq[k]; 
        int lowerBound = jacobSeq[k - 1];

        if (index >= (int)pendingChain.size())
            index = pendingChain.size() - 1;


        for (int i = index; i > lowerBound; i--)
        {
            int valueToInsert = pendingChain[i];
            
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
            mainChain.insert(pos, valueToInsert);
        }
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

void PmergeMe::exec()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
    {
        if (i > 4) {
            std::cout << "[...]";
            break;
        }
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;


    std::clock_t startVec = std::clock();
    _sortVector(_vec);
    std::clock_t endVec = std::clock();
    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    std::clock_t startDeq = std::clock();
    _sortDeque(_deq);
    std::clock_t endDeq = std::clock();
    double timeDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;


    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); i++)
    {
        if (i > 4) {
            std::cout << "[...]";
            break;
        }
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;


    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}

void PmergeMe::_sortDeque(std::deque<int> &arr)
{
    
    if (arr.size() <= 1) return;


    int straggler = -1;
    bool hasStraggler = false;
    if (arr.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }


    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }


    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].first);

    _sortDeque(mainChain);


    std::deque<int> pendingChain;
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == mainChain[i])
            {
                pendingChain.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }


    if (!pendingChain.empty())
        mainChain.push_front(pendingChain[0]);

    std::vector<int> jacobSeq = _generateJacobsthal(pendingChain.size());
    
    for (size_t k = 1; k < jacobSeq.size(); k++)
    {
        int index = jacobSeq[k];
        int lowerBound = jacobSeq[k - 1];

        if (index >= (int)pendingChain.size())
            index = pendingChain.size() - 1;

        for (int i = index; i > lowerBound; i--)
        {
            int valueToInsert = pendingChain[i];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
            mainChain.insert(pos, valueToInsert);
        }
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}