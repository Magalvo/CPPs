/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:21:45 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 15:32:20 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void putStr(std::string str, std::string color){
    std::cout << color << str << RESET;
}

Zombie::Zombie()
{
    putStr(this->_name, GREEN);
    putStr("A Zombie Got out of his grave!\n", MAGENTA);
	//std::cout << this->_name << "A Zombie Got out of his grave!" << std::endl;
}

void Zombie::setName(std::string _name)
{
    this->_name = _name;
}

void Zombie::announce(void)
{
    putStr(this->_name, GREEN);
    putStr(": BraiiiiiiinnnzzzZ...\n", RED);
    //std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    putStr(this->_name, GREEN);
    putStr(": Destroy!\n", RED);
	//std::cout << this->_name << " Destroyed!" << std::endl;
}

