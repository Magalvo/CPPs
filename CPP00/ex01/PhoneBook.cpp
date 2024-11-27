/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:25:06 by dde-maga          #+#    #+#             */
/*   Updated: 2024/11/27 16:53:46 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    putStr(std::string str)
{
   std::cout << str << std::endl; 
}

PhoneBook::PhoneBook(void){
    putStr("Phone Book was created");
}

PhoneBook::~PhoneBook(void){
	putStr("Phone Book was destroyed");
}

void        putCharN(std::string toPrint, long unsigned int n){
    if (toPrint.length() > n)
        std::cout << toPrint.substr(0, n - 1) << ".";
    else
        
}