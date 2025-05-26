/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:38 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 16:00:07 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void    putStr(std::string str, std::string color)
{
   std::cout << color << str << RESET; 
}

Weapon::Weapon(const std::string &weapon){
    this->setType(weapon);
}

Weapon::~Weapon(){
    putStr(this->getType(), MAGENTA);
    putStr(" dropped to the floor and broke.\n", RESET);
    //std::cout << this->getType() << " dropped to the floor and broke." << std::endl;
}

//? ======== Getters ===========
std::string Weapon::getType() const{
    return (_type);
}

void Weapon::setType(const std::string &weapon)
{
    _type = weapon;
}