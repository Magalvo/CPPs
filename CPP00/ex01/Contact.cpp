/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:50:20 by dde-maga          #+#    #+#             */
/*   Updated: 2024/11/27 16:45:26 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::switchGet(int val){
    switch (val)
    {
    case (1):
        return (this->_firstName);
    case (2):
        return (this->_lastName);
    case (3):
        return (this->_nickname);
    case (4):
        return (this->_phoneNumber);
    case (5):
        return (this->_darkSecret);
    default:
        return (NULL);
    }
}

void Contact::switchSet(std::string input, int val){
    switch (val)
    {
    case (1):
        this->_firstName = input;
    case (2):
        this->_lastName = input;
    case (3):
        this->_nickname = input;
    case (4):
        this->_phoneNumber = input;
    case (5):
       this->_darkSecret = input;
    default:
        return ;
    }
}

/* std::string Contact::getFirstName(void){
    return (this->_firstName);
}

std::string Contact::getLastName(void){
    return (this->_lastName);
}

std::string Contact::getNickname(void){
    return (this->_lastName);
}

std::string Contact::getPhoneNumber(void){
    return (this->_lastName);
}

std::string Contact::getPhoneNumber(void){
    return (this->_lastName);
} */




