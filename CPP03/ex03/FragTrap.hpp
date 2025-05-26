/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:07:00 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 12:15:36 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
	  FragTrap();
	  FragTrap(std::string nameParam);
	  FragTrap(const FragTrap& other);
	  FragTrap& operator=(const FragTrap& other);
	  ~FragTrap();

	void	attack(const std::string& target);
    void    highFivesGuys(void);
};

void putStr(std::string str, std::string color);
void putNum(int bits, std::string color);

#endif