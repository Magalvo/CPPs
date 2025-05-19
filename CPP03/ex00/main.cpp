/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:21:32 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 13:10:24 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void putStr(std::string str, std::string color)
{
	std::cout << color << str << RESET;
}

void putNum(int bits, std::string color)
{
	std::cout << color << bits << RESET;
}

int main()
{

	ClapTrap		clapobj("Marvin");
	// ClapTrap		clapobj2(clapobj);
	// ClapTrap		clapobj3("ClapTrap3");

	// clapobj3 = clapobj2;

	std::string		target = "JackEnemy";

	while (clapobj.getHitPoints() > 0)
	{
		clapobj.attack(target);
		clapobj.takeDamage(3);
		if (clapobj.getHitPoints() == 0)
			break ;
		clapobj.beRepaired(2);
	}
	return (0);
}