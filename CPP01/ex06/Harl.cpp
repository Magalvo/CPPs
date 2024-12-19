/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:29:07 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 20:36:40 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	putStr("HARLEY\n\n", GREEN);
}

Harl::~Harl(void)
{
	putStr("HARLEY BUM!\n", RED);
}

void Harl::debug(void)
{
	putStr("[DEBUG]: ", GREEN);
	putStr("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n", CYAN);
}

void Harl::info(void)
{
	putStr("[INFO]: ", GREEN);
	putStr("I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n", CYAN);
}

void Harl::warning(void)
{
	putStr("[WARNING]: ", GREEN);
	putStr("I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n", CYAN);
}

void Harl::error(void)
{
	putStr("[ERROR]\n ", GREEN);
	putStr("This is unacceptable! I want to speak to the manager now.\n\n", CYAN);
}

void Harl::complain(std::string level)
{
	if (level == "DEBUG")
		Harl::debug();
	else if (level == "INFO")
		Harl::info();
	else if (level == "WARNING")
		Harl::warning();
	else if (level == "ERROR")
		Harl::error();
	else
		putStr("Invalid Command!\n\n", RED_BLINK);
}