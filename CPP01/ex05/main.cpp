/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:28:53 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 17:47:22 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    putStr(std::string str, std::string color)
{
   std::cout << color << str << RESET; 
}

int main()
{
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("debug");
    harl.complain("debuga");
    harl.complain("aaaa");
    harl.complain("");
    return (0);
}