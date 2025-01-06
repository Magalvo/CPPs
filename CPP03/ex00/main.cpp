/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:21:32 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/26 16:59:34 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void putStr(std::string str, std::string color)
{
	std::cout << color << str << RESET;
}

void putNum(int bits, std::string color)
{
	std::cout << color << bits << RESET;
}

int main(){
    ClapTrap    clapObj("Marvin");
    ClapTrap    clapObj2(clapObj);
    ClapTrap    clapObj3("ClapTrap3");

    clapObj3 = clapObj2;
    
    std::string target = "JackEnemy";
    
    while (clapObj.getHitPoints() > 0)
    {
        clapObj.attack(target);
        clapObj.takeDamage(3);
        if (clapObj.getHitPoints() == 0)
            break ;
        clapObj.beRepaired(2);        
    }
    return (0);
}