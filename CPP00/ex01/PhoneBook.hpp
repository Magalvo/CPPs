/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:23:29 by dde-maga          #+#    #+#             */
/*   Updated: 2024/11/27 16:49:37 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
# define PHONEBOOK

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

#ifndef NUMNUM
#define NUMNUM 8
#endif

class PhoneBook
{
    private:
    Contact     contacts[NUMNUM];
    Contact     findContactByIndex(int index, int pos);
    std::string getValidInput(std::string prompt, bool isPhone);
    void        putCharN(std::string toPrint, long unsigned int n);
    bool        validNumber(std::string phoneNumber, bool isPhone);

    public:
    PhoneBook(void);
    ~PhoneBook(void);
    void    addContact(int pos);
    void    searchContacts(int pos);
};

#endif