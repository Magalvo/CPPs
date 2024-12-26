/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:21:32 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/26 17:40:34 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	ScavTrap	scavTrap("TheScavRobotD999X");
	//ClapTrap	clapTrap("TheClapRobotYYYcc00");

	// clapTrap.attack("LitlleZombie");
	// clapTrap.takeDamage(5);
	// clapTrap.beRepaired(9);

	//scavTrap.attack("Orc");
	scavTrap.guardGate();

	scavTrap.takeDamage(15);
	if (scavTrap.getHitPoints() == 0)
		return 0;
	scavTrap.beRepaired(50);
	
	return (0);
}