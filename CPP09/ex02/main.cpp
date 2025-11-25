#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        putErr("Error: No arguments provided.\n", RED);
         // std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    PmergeMe sorter;

    try {
        sorter.parseArgs(argc, argv);
        sorter.exec();
    }
    catch (std::exception &e) {
        putErr("Error\n", RED);
       // std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}