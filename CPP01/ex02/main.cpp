/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:01:20 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/10 12:13:54 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void    putStr(std::string str)
{
   std::cout << str; 
}

int main(void){
    std::string test = "HI THIS IS BRAIN";
    std::string *stringPTR = &test;
    std::string &stringREF = test;
    //?    ===== Memory Address =====
    putStr("address of the string test -> ");
    std::cout << &test << std::endl;
    putStr("address of the stringPTR -> ");
    std::cout << stringPTR << std::endl;
    putStr("address of the stringREF -> ");
    std::cout << &stringREF << std::endl;
    //?     ===== Value =====
    putStr("value of the string test -> ");
    std::cout << test << std::endl;
    putStr("value of the stringPTR -> ");
    std::cout << *stringPTR << std::endl;
    putStr("value of the stringREF -> ");
    std::cout << stringREF << std::endl;
}