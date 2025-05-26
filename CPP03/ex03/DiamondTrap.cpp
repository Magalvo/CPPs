/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:45:28 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 13:33:18 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{
	this->_name = "default";
    putStr("DiamondTrap constructor method called: ", RESET);
    putStr("Diamond ", GREEN);
    putStr(_name, YELLOW);
    putStr(" is born!\n\n", RESET);
}

DiamondTrap::DiamondTrap(std::string nameParam) : ClapTrap(nameParam + "_clap_name"), ScavTrap(nameParam), FragTrap(nameParam), _name(nameParam)
{
    this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
    
    putStr("DiamondTrap constructor method called: ", CYAN_BOLD);
    putStr("Diamond ", GREEN);
    putStr(_name, YELLOW);
    putStr(" is born!!\n\n", RESET);
}

DiamondTrap::~DiamondTrap(){
    putStr("DiamondTrap destructor method call: ", RED);
    putStr("DiamondTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" has been destoyed!\n\n", RESET);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
    putStr("DiamondTrap copy constructor called\n", RESET);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    putStr("DiamondTrap assignment operator called\n", RESET);
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->_name = other._name;
    }
    return (*this);
}

void DiamondTrap::whoAmI()
{
    putStr("whoAmI() member function call: ", RESET);
    putStr("\"I am ", RESET);
    putStr(this->_name, YELLOW);
    putStr(" and my ", RESET);
    putStr("ClapTrap", GREEN);
    putStr(" name is ", RESET);
    putStr(ClapTrap::_name, YELLOW);
    putStr("\"\n\n", RESET);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}