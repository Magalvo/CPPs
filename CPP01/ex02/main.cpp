/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:01:20 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 15:38:05 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[1;31;5m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[0;33m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[36m"

void    putStr(std::string str, std::string color)
{
   std::cout << color << str << RESET; 
}

int main(void)
{
    std::string test = "HI THIS IS BRAIN";
    std::string *stringPTR = &test;
    std::string &stringREF = test;
    //?    ===== Address =====
    putStr("Address of the string test -> ", CYAN);
    std::cout << &test << std::endl;
    putStr("Address of the stringPTR -> ", CYAN);
    std::cout << stringPTR << std::endl;
    putStr("Address of the stringREF -> ", CYAN);
    std::cout << &stringREF << std::endl;
    //?     ===== Value =====
    putStr("Value of the string test -> ", GREEN);
    std::cout << test << std::endl;
    putStr("Value of the stringPTR -> ", GREEN);
    std::cout << *stringPTR << std::endl;
    putStr("Value of the stringREF -> ", GREEN);
    std::cout << stringREF << std::endl;
}