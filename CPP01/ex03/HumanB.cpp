/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:21:25 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/10 16:58:44 by dde-maga         ###   ########.fr       */
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
    putStr(" died.", RED);
    putStr("\n", RESET);
}

void HumanB::setWeapon(Weapon &weapon){
    this->_weapon = &weapon;
    this->_armed = true;
    putStr(this->_name, GREEN);
    putStr(" grabbed a ", RESET);
    putStr(this->_weapon->getType(), CYAN);
    putStr(" to fight with.\n", RESET);
}

void HumanB::attack(void){
    putStr(this->_name, GREEN);
    this->_armed ? std::cout << MAGENTA << " attacks " << RESET<<  "with his " << this->_weapon->getType() << "." << std::endl : \
        std::cout << MAGENTA << " attacks " << RESET << "with his fists." << std::endl;
}
