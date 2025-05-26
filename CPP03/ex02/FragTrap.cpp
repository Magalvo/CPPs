/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:06:49 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 13:25:07 by dde-maga         ###   ########.fr       */
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
	putStr("FragTrap default constructor method call: ", CYAN_BOLD);
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

void FragTrap::highFivesGuys(void){
    putStr("FragTrap ", GREEN);
    putStr(this->_name, YELLOW);
    putStr(" says: ", RESET);
    putStr(" High Five Guys!\n\n", MAGENTA);
}