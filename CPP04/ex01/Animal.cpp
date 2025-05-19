/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:51:40 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/28 15:51:40 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
    type = "Default Animal";
    putStr("Animal constructor called\n", CYAN);
}

Animal::~Animal(){
    putStr("Animal destrutor called\n", RED);
}

Animal::Animal(const Animal &copy){
    putStr("Animal copy constructor called\n", CYAN);
    *this=copy;
}

Animal &Animal::operator=(const Animal &copy){
    putStr("Animal assignment operator called\n", CYAN);
    if(this != &copy)
        type = copy.type;
        
    return(*this);
}

std::string Animal::getType() const{
    return(type);
}

void Animal::makeSound() const{
    putStr("(in silence)\n", CYAN);
}