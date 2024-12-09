/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:51 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/09 12:15:50 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstring>

static void    putStr(std::string str)
{
   std::cout << str; 
}

int main(void){
    PhoneBook contactList;
    std::string command;
    int contactPos = 0;

    while (command.compare("EXIT")){
        putStr("Command Selection (ADD, SEARCH, EXIT)\n");
        std::getline(std::cin, command);
        if (std::cin.eof())
            return (putStr("End of file was reached(EOF)! Exiting program...\n"),1);
        if(!command.compare("ADD")){
            contactList.addContact(contactPos);
            if (contactPos <= NUMNUM - 1)
                contactPos++;
        }
        else if (!command.compare("SEARCH"))
            contactList.searchContacts(contactPos);
        else if (!command.compare("EXIT"))
            putStr("Not Found\n");
    }
    return (0);
}