/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:31 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/09 17:27:29 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    void announce(void);
    ~Zombie(void);
};

Zombie  *newZombie(std::string name);
void randomChump(std::string name);

#endif
