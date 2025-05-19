/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:02:39 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/27 12:00:15 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
	  ScavTrap();
	  ScavTrap(std::string nameParam);
	  ScavTrap(const ScavTrap& other);
	  ScavTrap& operator=(const ScavTrap& other);
	  ~ScavTrap();

	  void  attack(const std::string& target);
	  void  guardGate();
};




#endif