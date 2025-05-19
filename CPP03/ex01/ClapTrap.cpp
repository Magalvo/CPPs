/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:20:32 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 13:25:07 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("name"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10)
{
    putStr("default constructor method call: ", CYAN);
    putStr("ClapTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" is born!\n\n", RESET);
}

ClapTrap::~ClapTrap(){
    putStr("Destructor method call: ", RED);
    putStr("ClapTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" has been destroyed!\n\n", RESET);
}

ClapTrap::ClapTrap(std::string nameParam) : _name(nameParam), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10)
{
    putStr("\nCustom constructor method call: ", CYAN_BOLD);
    putStr("ClapTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" is born!\n\n", RESET);
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_maxHitPoints = other._maxHitPoints;
    putStr("Copy constructor method call: ", CYAN_BOLD);
    putStr("ClapTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr("\n\n", RESET);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_maxHitPoints = other._maxHitPoints;
    putStr("Assignment operator method call: ", CYAN_BOLD);
    putStr("ClapTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr("\n\n", RESET);    
    return(*this);
}

void ClapTrap::attack(const std::string& target)
{
    if(this->_energyPoints > 0){
        putStr("ClapTrap ", YELLOW);
        putStr(_name,GREEN);
        putStr(" attacks ", RED_BLINK);
        putStr(target, CYAN);
        putStr(", causing ", RESET);
        putNum(_attackDamage, RED);
        putStr(" points of damage!\n\n", RED);

        this->_energyPoints -= 1;

        putStr("Thus ClapTrap ", RESET);
        putStr(_name,GREEN);
        putStr(" has now ", RESET);
        putNum(_energyPoints, CYAN_BOLD);
        putStr(" points of energy \n\n", CYAN);
        return ;
    }else{
        putStr("ClapTrap ", GREEN);
        putStr(_name,YELLOW);
        putStr(" is unable to attack, not enough ", RESET);
        putStr(" energy points!\n\n", CYAN);
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    putStr("ClapTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" took ", RESET);
    putNum(amount, RED);
    putStr(" points of damage!\n\n", RED);
    if (this->_hitPoints <= amount){
        this->_hitPoints = 0;
        putStr("ClapTrap ", GREEN);
        putStr(_name,GREEN);
        putStr(" has died!\n\n", RED);
        return ;
    }else{
        this->_hitPoints -= amount;
    }
    putStr("Thus, ClapTrap ", RESET);
    putStr(_name,GREEN);
    putStr(" has now ", RESET);
    putNum(_hitPoints, RED);
    putStr(" hit points.\n\n", RED);
}

void ClapTrap::beRepaired(unsigned int amount){
   if (amount <= _energyPoints){
    putStr("ClapTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" is repaired for ", RESET);
    putNum(amount, GREEN);
    putStr(" points!\n", GREEN);
    this->_hitPoints += amount;
    if (this->_hitPoints > this->_maxHitPoints)
        this->_hitPoints = this->_maxHitPoints;
    this->_energyPoints -= amount;
    putStr("Thus ClapTrap ", RESET);
    putStr(_name,GREEN);
    putStr(" has now ", RESET);
    putNum(_hitPoints, RED);
    putStr(" hit points ", RED);
    putStr("and ", RESET);
    putNum(_energyPoints, CYAN_BOLD);
    putStr(" energy points.\n\n", CYAN_BOLD);
   }else{
    putStr("ClapTrap ", GREEN);
    putStr(_name,YELLOW);
    putStr(" has not the ", RESET);
    putNum(amount, CYAN_BOLD);
    putStr(" energy points to be repaired!\n\n", CYAN);
   }
}

unsigned int ClapTrap::getHitPoints() const{
    return (this->_hitPoints);
}