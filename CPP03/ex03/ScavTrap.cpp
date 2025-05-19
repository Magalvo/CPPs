/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:02:30 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 13:26:04 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	putStr("ScavTrap constructor method called: ", RESET);
	putStr("ScavTrap ", GREEN);
	putStr(_name, YELLOW);
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
}

ScavTrap::ScavTrap(std::string nameParam) : ClapTrap(nameParam) 
{
	putStr("ScavTrap constructor method call: ", CYAN_BOLD);
    putStr("ScavTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" is born!\n\n", RESET);
	this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
	this->_maxHitPoints = 100;
}

ScavTrap::~ScavTrap(){
    putStr("ScavTrap destructor method call: ", RED);
    putStr("ScavTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" has been destoyed!\n\n", RESET);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	putStr("ScavTrap copy constructor method call: ", CYAN_BOLD);
    putStr("ScavTrap ", GREEN);
    putStr(this->_name,YELLOW);
    putStr("is born! \n\n", RESET);
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	putStr("ScavTrap assignment operator called: ", RESET);
	putStr("ScavTrap ", GREEN);
    putStr(this->_name,YELLOW);
    putStr("\n\n", RESET);
	if(this != &other)
		ClapTrap::operator=(other);
	return (*this);
}


void ScavTrap::attack(const std::string& target)
{
    putStr("ScavTrap ", GREEN);
    putStr(this->_name,YELLOW);
    putStr(" attacks ", RED_BLINK);
    putStr(target, CYAN);
    putStr(", causing ", RESET);
    putNum(this->_attackDamage, RED);
    putStr(" points of damage!\n\n", RED);
}

void ScavTrap::guardGate()
{
	putStr("ScavTrap ", GREEN);
	putStr(this->_name, YELLOW);
	putStr(" has entered in Gate keeper mode.\n\n", RESET);
}