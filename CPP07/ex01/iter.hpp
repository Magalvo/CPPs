#ifndef ITER_HPP
#define ITER_HPP
#pragma once

#include <iostream>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

template <typename T1, typeame T2, typename T3>
void iter(T1 addr, T2 len, T3 func){
    for (T2 i = 0; i < len ; i++)
        func(addr[i]);
}

template <typename T>
void print( T arg){
    std::cout << arg << std::endl;
}

#endif