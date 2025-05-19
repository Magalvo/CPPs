/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:51:53 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/28 15:51:53 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

typedef std::string t_string;

class Animal
{
    protected:
    std::string type;
    public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &copy);
    std::string getType() const;
    virtual void makeSound() const;
};

void putStr(t_string str, t_string color);
void putNum(int bits, t_string color);

#endif