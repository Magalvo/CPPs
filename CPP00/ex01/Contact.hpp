/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:38 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/05 17:08:07 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS
#define CONTACTS

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkSecret;
    int         _index;
public:
    Contact(void);
    std::string switchGet(int val);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
    std::string getPhoneNumber(void);
    std::string getDarkSecret(void);
    void        switchSet(std::string input, int val);
    void        setFirstName(std::string firstName);
    void        setLastName(std::string lastName);
    void        setNickname(std::string nickname);
    void        setPhoneNumber(std::string phoneNumber);
    void        setDarkSecret(std::string darkestSecret);
    void        increaseIndex(int i);
    void        setIndex(int index);
    //void        putStr(std::string str);
    int         getIndex(void);
    ~Contact(void);
};

#endif
