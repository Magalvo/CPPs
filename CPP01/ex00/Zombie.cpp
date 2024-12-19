/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:21:55 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 15:28:19 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void putStr(std::string str, std::string color){
    std::cout << color << str << RESET;
}

void Zombie::announce(void)
{
    putStr(this->_name, GREEN);
    putStr(": BraiiiiiiinnnzzzZ...\n", RED);
    //std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string _name)
{
    this->_name = _name;
}

Zombie::~Zombie(void)
{
    putStr(this->_name, GREEN);
    putStr(": Destroy!\n", RED);
    //std::cout << this->_name << " Destroy!" << std::endl;
}

