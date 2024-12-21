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
    putStr("\n\n", RESET);
    //Line break for output interpretation
    putNum(a.getRawBits(), CYAN_BOLD);
    putStr("\n", RESET);
    putNum(b.getRawBits(), MAGENTA);
    putStr("\n", RESET);
    putNum(c.getRawBits(), GREEN);
    putStr("\n\n", RESET);
    return(0);
}