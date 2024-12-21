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

Fixed &Fixed::operator = (const Fixed &other){
    putStr("\t(COPY) assignment operator called\n", MAGENTA);
    if(this != &other)
        this->_pfixed = other.getRawBits();
    return (*this);
}

//?Getter
int Fixed::getRawBits(void) const{
    putStr("\tgetRawBits() member function called \n", YELLOW);
    return (_pfixed);
}

//?Setter
void Fixed::setRawBits(int const raw){
    _pfixed = raw;
}

//?To INT
Fixed::Fixed(const int value){
    _pfixed = value << _fbits; //? Bitshifting the given num of bits
}

int Fixed::toInt(void) const{
    return (_pfixed >> _fbits);
}

//?To FLOAT
//? Instead of doing it bit by bit we do it block by block because of the (MANTISSA)
Fixed::Fixed(const float floatValue){
    _pfixed = roundf(floatValue * (1 << _fbits));
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(_pfixed) / (1 << _fbits));
}

//?Output Overload | std output manipulation
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}