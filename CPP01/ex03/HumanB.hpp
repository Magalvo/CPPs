/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:21:23 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/10 13:24:18 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#pragma once

#include "Weapon.hpp"

class HumanB{
    private:
        std::string _name;
        Weapon *_weapon;
        bool _armed;
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack(void);
        ~HumanB(void);
};

#endif