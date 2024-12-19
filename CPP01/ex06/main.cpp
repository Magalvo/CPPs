/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:29:20 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 20:35:35 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void putStr(std::string str, std::string color)
{
	std::cout << color << str << RESET;
}

int main(int argc, char **argv)
{
	Harl harl;
	std::string level(argv[1]);
	if (argc == 2)
		harl.complain(level);
	else
		putStr("Invalid Command!\n\n", RED_BLINK);
	return (0);
}