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
    //putStr("\nDefault Constructor Called\n", GREEN);
}

Fixed::~Fixed(){
    //putStr("Destructor Called\n", RED);
}

//?Copy Constructor
Fixed::Fixed(const Fixed &copy){
    //putStr("(COPY) constructor called\n", CYAN);
    *this = copy;
}

Fixed &Fixed::operator = (const Fixed &other){
    //putStr("(COPY) assignment operator called\n", MAGENTA);
    if(this != &other)
        this->_pfixed = other.getRawBits();
    return (*this);
}

//?Getter
int Fixed::getRawBits(void) const{
    //putStr("getRawBits() member function called \n", YELLOW);
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

bool Fixed::operator>(const Fixed& other) const{
    return(this->toInt() > other.toInt()) ? true : false;
}

bool Fixed::operator<(const Fixed& other) const{
    return(this->toInt() < other.toInt()) ? true : false;
}

bool Fixed::operator>=(const Fixed& other) const{
    return(this->toInt() >= other.toInt()) ? true : false;
}

bool Fixed::operator<=(const Fixed& other) const{
    return(this->toInt() <= other.toInt()) ? true : false;
}

bool Fixed::operator==(const Fixed& other) const{
    return(this->toInt() == other.toInt()) ? true : false;
}

bool Fixed::operator!=(const Fixed& other) const{
    return(this->toInt() != other.toInt()) ? true : false;
}

Fixed Fixed::operator+(const Fixed& other) const{
    Fixed temp(*this);

    temp._pfixed += other._pfixed;
    return(temp);
}

Fixed Fixed::operator-(const Fixed& other) const{
    Fixed temp(*this);
    
    temp._pfixed = roundf((this->toFloat() - other.toFloat()) * (1 << _fbits)) ;
    return(temp);
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed temp(*this);
 
    temp._pfixed = roundf((this->toFloat() * other.toFloat()) * (1 << _fbits)) ;
    return(temp);
}

Fixed Fixed::operator/(const Fixed& other) const{
    Fixed temp(*this);
 
    temp._pfixed = roundf((this->toFloat() / other.toFloat()) * (1 << _fbits)) ;
    return(temp);
}

Fixed Fixed::operator++(int){
  Fixed temp(*this);
  this->_pfixed++;
  return temp;
}

Fixed& Fixed::operator++(){
    this->_pfixed++;
    return *this;
}


Fixed Fixed::operator--(int){
  Fixed temp(*this);
  this->_pfixed--;
  return temp;
}

Fixed& Fixed::operator--(){
    this->_pfixed--;
    return *this;
}


const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    return (first.toFloat() < second.toFloat()) ? first : second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    return (first.toFloat() > second.toFloat()) ? first : second;
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    return (first.toFloat() < second.toFloat()) ? first : second;
}

Fixed& Fixed::max(Fixed& first,  Fixed& second) {
    return (first.toFloat() > second.toFloat()) ? first : second;
}

//?Output Overload | std output manipulation
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}