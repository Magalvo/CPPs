/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:21:25 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 16:04:48 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->_name = name;
    this->_armed = false;
    putStr(this->_name, GREEN);
    putStr(" joined the battlefield.\n", RESET);
}

HumanB::~HumanB(void){
    putStr(this->_name, GREEN);
    putStr(" died!", RED_BLINK);
    putStr("\n", RESET);
}

void HumanB::setWeapon(Weapon &weapon){
    this->_weapon = &weapon;
    this->_armed = true;
    putStr(this->_name, GREEN);
    putStr(" grabbed a ", RESET);
    putStr(this->_weapon->getType(), MAGENTA);
    putStr(" to fight with.\n", RESET);
}

void HumanB::attack(void){
    putStr(this->_name, GREEN);
    this->_armed ? std::cout << RED << " attacks " << RESET<<  "with his " << MAGENTA << this->_weapon->getType() << "." << RESET << std::endl : \
        std::cout << RED << " attacks " << RESET << "with his fists." << std::endl;
}
