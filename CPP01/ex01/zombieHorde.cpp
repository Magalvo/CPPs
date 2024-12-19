/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:21:43 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 15:33:17 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int nbr, std::string name)
{
    if (nbr < 0)
    {
        putStr("try again\n", CYAN);
        //std::cout << "try again" << std::endl;
        return (0);
    }
    Zombie *group = new Zombie[nbr];
    
    for (int i = 0; i < nbr; i++)
    {
        group[i].setName(name);
        group[i].announce();
    }
    return (group);
}