/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:55:48 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/09 12:15:18 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

//my putstr for CPP
void    putStr(std::string str)
{
   std::cout << str; 
}

//converts char by char the characters given on the string
void    toUpperCase(std::string &convertString)
{
    for (size_t i = 0; i < convertString.length(); i++)
        convertString[i] = static_cast<char>(toupper(convertString[i]));
}

int main(int argc, char **argv)
{
    if(argc == 1)
        putStr("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
    else
    {
        for(int i = 1; i < argc; i++)
        {
            std::string singleWord(argv[i]);
            toUpperCase(singleWord);
            putStr(singleWord);
            putStr("\n");
        }
    }
}

