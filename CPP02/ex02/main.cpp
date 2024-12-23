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

void putFixed(const Fixed& print, std::string color){
	std::cout << color << print << RESET << "\n";
}

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	putFixed(a, CYAN);
	putFixed(++a, CYAN);
	putFixed(a, CYAN);
	putFixed(a++, CYAN);
	putFixed(a, CYAN);
	putFixed(b, CYAN);
    std::cout << CYAN << Fixed::max( a, b ) << std::endl;
    return (0);
}