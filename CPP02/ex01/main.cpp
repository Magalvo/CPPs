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


int main( void ) 
{
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << CYAN_BOLD <<  "a is " << MAGENTA << a << std::endl;
std::cout << CYAN_BOLD <<  "b is " << MAGENTA <<  b << std::endl;
std::cout << CYAN_BOLD <<  "c is " << MAGENTA <<  c << std::endl;
std::cout << CYAN_BOLD <<  "d is " << MAGENTA <<  d << std::endl;
std::cout << CYAN_BOLD <<  "a is " << MAGENTA <<  a.toInt() << RESET << " as integer" << std::endl;
std::cout << CYAN_BOLD <<  "b is " << MAGENTA <<  b.toInt() << RESET <<  " as integer" << std::endl;
std::cout << CYAN_BOLD <<  "c is " << MAGENTA <<  c.toInt() << RESET <<  " as integer" << std::endl;
std::cout << CYAN_BOLD <<  "d is " << MAGENTA <<  d.toInt() << RESET <<  " as integer" << std::endl;
return(0);
}

/* int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);

	putStr("\n", RESET);
	putStr("\ta is: ", CYAN_BOLD);
	putFixed(a, MAGENTA);
	putStr("\tb is: ", CYAN_BOLD);
	putFixed(b, MAGENTA);
	putStr("\tc is: ", CYAN_BOLD);
	putFixed(c, MAGENTA);
	putStr("\td is: ", CYAN_BOLD);
	putFixed(d, MAGENTA);
	putStr("\n", RESET);

	std::cout << CYAN_BOLD << "\ta is: " << MAGENTA << a.toInt()   << " as integer" << std::endl;
	std::cout << CYAN_BOLD << "\tb is: " << MAGENTA << b.toFloat() << " as integer" << std::endl;
	std::cout << CYAN_BOLD << "\tc is: " << MAGENTA << c.toInt()   << " as integer" << std::endl;
	std::cout << CYAN_BOLD << "\td is: " << MAGENTA << d.toInt()   << " as integer" << std::endl << std::endl;

	return (0);
} */