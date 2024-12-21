/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:04:39 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/21 11:04:39 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fbits = 8;

//?Original COnstructor
Fixed::Fixed() : _pfixed(0){
    putStr("\nDefault Constructor Called\n", GREEN);
}

Fixed::~Fixed(){
    putStr("Destructor Called\n", RED);
}

//?Copy Constructor
Fixed::Fixed(const Fixed &copy){
    putStr("\t(COPY) constructor called\n", CYAN);
    *this = copy;
}

Fixed &Fixed::operator = (const Fixed &src){
    putStr("\t(COPY) assignment operator called\n", MAGENTA);
    if(this != &src)
        this->_pfixed = src.getRawBits();
    return (*this);
}

//?Getter
int Fixed::getRawBits(void) const{
    putStr("\tgetRawBits() member function called: ", YELLOW);
    return (_pfixed);
}

//?Setter
void Fixed::setRawBits(int const raw){
    _pfixed = raw;
}
