/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:04:25 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/21 11:04:25 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

class Fixed
{
    private:
        int _pfixed;
        static const int _fbits; //8 bits
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator = (const Fixed & src);
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

void putStr(std::string str, std::string color);
void putNum(int bits, std::string color);

#endif