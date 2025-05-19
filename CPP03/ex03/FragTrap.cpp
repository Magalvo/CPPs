/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:06:49 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 13:26:09 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	putStr("FragTrap constructor method called: ", RESET);
	putStr("FragTrap ", GREEN);
	putStr(_name, YELLOW);
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
}

FragTrap::FragTrap(std::string nameParam) : ClapTrap(nameParam) 
{
	putStr("FragTrap constructor method call: ", CYAN_BOLD);
    putStr("FragTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" is born!\n\n", RESET);
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
}

FragTrap::~FragTrap(){
    putStr("FragTrap destructor method call: ", RED);
    putStr("FragTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" has been destoyed!\n\n", RESET);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	putStr("FragTrap copy constructor method call: ", CYAN_BOLD);
    putStr("FragTrap ", GREEN);
    putStr(this->_name,YELLOW);
    putStr("is born! \n\n", RESET);
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	putStr("FragTrap assignment operator called: ", RESET);
	putStr("FragTrap ", GREEN);
    putStr(this->_name,YELLOW);
    putStr("\n\n", RESET);
	if(this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	putStr("FragTrap ", RESET);
	putStr(this->_name, YELLOW);
	putStr(" attacks ", RESET);
	putStr(target, CYAN_BOLD);
	putStr(" causing ", RESET);
	putNum(this->_attackDamage, RED);
	putStr(" points of damage!\n\n", RESET);
}

void FragTrap::highFivesGuys(void){
    putStr("FragTrap ", GREEN);
    putStr(this->_name, YELLOW);
    putStr(" says: ", RESET);
    putStr(" High Five Guys!\n\n", MAGENTA);
}