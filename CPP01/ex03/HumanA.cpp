/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:21 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/10 16:21:35 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon){
    this->_name = name;
    putStr(this->_name, GREEN);
    putStr(" joined the battlefield and grabbed a ", RESET);
    putStr(this->_weapon.getType(), CYAN);
    putStr(" to fight\n", RESET);
}

HumanA::~HumanA(void){
    putStr(this->_name, GREEN);
    putStr(" died.", RED);
    putStr("\n", RESET);
}

void HumanA::attack(void){
    putStr(this->_name, GREEN);
    putStr(" attack with his ", RESET);
    putStr(this->_weapon.getType(), CYAN);
    putStr(".\n", RESET);
}