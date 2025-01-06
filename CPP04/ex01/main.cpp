/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:48:09 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/28 15:48:09 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongCat.hpp"

void putStr(std::string str, std::string color)
{
	std::cout << color << str << RESET;
}

void putNum(int bits, std::string color)
{
	std::cout << color << bits << RESET;
}

int main()
{
Animal* Mimosa = new Animal();

Dog* Xispe = new Dog();
Xispe->setIdea("Eat, Play, Sleep Repeat! \n", 0);
putStr(" \n", RESET);
putStr(Xispe->getIdea(0), CYAN);
putStr("\n", RESET);
putStr(Xispe->getIdea(1), CYAN);
putStr("\n", RESET);

Dog* XispeX2 = new Dog(*Xispe);
putStr("Refreshing memory...\n", GREEN);
Xispe->setIdea("RUN RUN RUN", 0);
putStr("\n", RESET);
putStr(XispeX2->getIdea(0), GREEN);
putStr(" \n", RESET);

delete XispeX2;
delete Xispe;
delete Mimosa;
return (0);
}
