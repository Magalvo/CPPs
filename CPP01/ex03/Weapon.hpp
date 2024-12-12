/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:21:12 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/10 16:29:27 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#pragma once

# include <iostream>
# include <string>

#define RESET   "\033[0m"
#define RED     "\033[1;31;5m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[0;33m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[36m"

class   Weapon{
    private:
        std::string _type;
    public:
        Weapon(const std::string &weapon);
        void setType(const std::string &weapon);
        std::string getType() const;
        ~Weapon();
};

void    putStr(std::string str, std::string color);

#endif