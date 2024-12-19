/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:28:44 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 17:49:43 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

# include <iostream>
# include <string>

#define RESET       "\033[0m"
#define RED         "\033[1;31m"
#define RED_BLINK   "\033[1;31;5m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[0;33m"
#define MAGENTA     "\033[0;35m"
#define CYAN_BOLD   "\033[1;36m"
#define CYAN        "\033[0;36m"

class Harl
{
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
    public:
        Harl(void);
        void complain(std::string level);
        ~Harl(void);    
};

void    putStr(std::string str, std::string color);

#endif