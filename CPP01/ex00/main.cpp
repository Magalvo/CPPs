/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:21:26 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/09 17:46:14 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void)
{
    Zombie  test("Jean");
    test.announce();

    Zombie *heapMem = newZombie("Pierre");
    heapMem->announce();

    randomChump("Nenuco");
    
    delete heapMem;
}