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

#include "Point.hpp"

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

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point p1(0, 0);
    Point p2(10, 30);
    Point p3(20, 0);


	Point check(5,5);


	bool variavel =  bsp(p1, p2, p3, check);

	if(variavel == true)
	{
    	std::cout << MAGENTA << true << std::endl;
		putStr("O ponto está dentro do triângulo\n", GREEN);
	}else{
		putStr("O ponto está fora do triângulo\n", RED);
	}
    return (0);
}