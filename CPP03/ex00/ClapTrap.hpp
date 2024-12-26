/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:21:09 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/26 16:42:36 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//? ClapTrap <name> attacks <target>, causing <damage> points of damage!

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

#include <iostream>

class ClapTrap{
    private:
        std::string     _name;
        unsigned int	_hitPoints;
    	unsigned int	_energyPoints;
    	unsigned int	_attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string nameParam);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount); 

        unsigned int    getHitPoints() const;
};

void putStr(std::string str, std::string color);
void putNum(int bits, std::string color);

#endif