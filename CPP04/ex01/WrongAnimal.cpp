/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:43:58 by dde-maga          #+#    #+#             */
/*   Updated: 2025/01/07 15:49:57 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	putStr("WrongAnimal default constructor called", GREEN);
	this->type = "Default";
}

WrongAnimal::~WrongAnimal() {
	putStr("WrongAnimal default destructor called", RED);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

t_string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Default WrongAnimal sound" << std::endl;
}
