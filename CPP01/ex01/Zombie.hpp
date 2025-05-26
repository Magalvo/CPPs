/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:27:39 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 15:30:38 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

#define RESET   "\033[0m"
#define RED     "\033[1;31;5m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[0;33m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[36m"

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        void setName(std::string name);
        void announce(void);
        ~Zombie(void);
};

Zombie* zombieHorde(int nbr, std::string name);
void putStr(std::string str, std::string color);

#endif