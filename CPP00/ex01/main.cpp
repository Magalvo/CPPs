/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:51 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/05 17:08:47 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstring>

static void    putStr(std::string str)
{
   std::cout << str << std::endl; 
}

int main(void){
    PhoneBook contactList;
    std::string command;
    int contactPos = 0;

    while (command.compare("EXIT")){
        putStr("Command Selection (ADD, SEARCH, EXIT)");
        std::getline(std::cin, command);
        if (std::cin.eof())
            return (putStr("End of file was reached(EOF)! Exiting program..."),1);
        if(!command.compare("ADD")){
            contactList.addContact(contactPos);
            if (contactPos <= NUMNUM - 1)
                contactPos++;
        }
        else if (!command.compare("SEARCH"))
            contactList.searchContacts(contactPos);
        else if (!command.compare("EXIT"))
            putStr("Not Found");
    }
    return (0);
}