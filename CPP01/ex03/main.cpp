/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:21:19 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/10 16:09:44 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void){
    {
        Weapon club = Weapon("crude spiked club");
        HumanA jp("JeanPierre", club);
        jp.attack();
        club.setType("Some other type of club");
        jp.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB cristine("Kris");
        cristine.attack();
        cristine.setWeapon(club);
        cristine.attack();
        club.setType("Some other type of club");
        cristine.attack();
    }
    return (0);
}