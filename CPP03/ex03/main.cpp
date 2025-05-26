/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:21:32 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 13:35:58 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
	DiamondTrap		diamondobj("SuperDiamond42");

	std::cout << MAGENTA << "Hit Points: " << diamondobj.getHitPoints() << RESET << std::endl;
	std::cout << MAGENTA << "Energy Points: " << diamondobj.getEnergyPoints() << RESET << std::endl;
	std::cout << MAGENTA << "Attack Damage: " << diamondobj.getAttackDamage() << RESET << std::endl << std::endl;

	diamondobj.whoAmI();

	diamondobj.attack("Eifel Tower");

	diamondobj.highFivesGuys();
	diamondobj.guardGate();

	return (0);
}