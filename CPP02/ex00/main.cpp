/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:04:48 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/21 11:04:48 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//?polymorphism, operator overloading and Orthodox Canonical class form

#include "Fixed.hpp"

//? ============= AUX FUNCTIONS ==============
void putStr(std::string str, std::string color)
{
	std::cout << color << str << RESET;
}

void putNum(int bits, std::string color)
{
	std::cout << color << bits << RESET;
}

//?    As in C / ~=
//?     int a;
//?     int *b;
//?     int c;
//?     b = &a
//?     c = b;
int main(void)
{
    
    Fixed a;    //?Default Constructor Called (a)
    Fixed b(a); //?Copy Contructor Called / Get raw bits function called
    Fixed c;    //?Default Constructor Called (c)
    c = b;
    
    std::cout << CYAN << a.getRawBits() << std::endl;
    std::cout << MAGENTA << b.getRawBits() << std::endl;
    std::cout << GREEN << c.getRawBits() << std::endl;

    return(0);
}