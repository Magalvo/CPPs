/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:21:32 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 12:15:29 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void putStr(std::string str, std::string color)
{
	std::cout << color << str << RESET;
}

void putNum(int bits, std::string color)
{
	std::cout << color << bits << RESET;
}

int		main()
{
	FragTrap	fragTrap("FRAG55AlphaXPTO");
	//ClapTrap	clapTrap("TheClapRobotYYYcc00");

	// clapTrap.attack("LitlleZombie");
	// clapTrap.takeDamage(5);
	// clapTrap.beRepaired(9);

	fragTrap.attack("ORC");
	fragTrap.highFivesGuys();

	fragTrap.takeDamage(10);
	if (fragTrap.getHitPoints() == 0)
		return (0);
	fragTrap.beRepaired(20);
	
	return (0);
}