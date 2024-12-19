/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:03:02 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/19 17:21:43 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#define RESET       "\033[0m"
#define RED         "\033[1;31m"
#define RED_BLINK   "\033[1;31;5m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define MAGENTA     "\033[0;35m"
#define CYAN_BOLD   "\033[1;36m"
#define CYAN        "\033[0;36m"

//?search and replace function
void	changeString(std::string &content, std::string s1, std::string s2)
{
	size_t pos = content.find(s1);
    while (pos != std::string::npos)
    {
        content.erase(pos, s1.size());
        content.insert(pos, s2);
        pos = content.find(s1, pos + s2.size());
    }
}

//?my putstr
void    putStr(std::string str, std::string color)
{
   std::cout << color << str << RESET; 
}

int main(int argc, char **argv)
{
    std::string error = std::strerror(errno);
    if (argc != 4)
    {
        putStr("Wrong number of arguments!\n", RED_BLINK);
        putStr("Usage:\t", CYAN_BOLD);
        putStr("./replace <file_name> <search> <replace>\n", GREEN);
        return (EXIT_FAILURE);
    }
    std::string fileName(argv[1]);
    std::string searchWord(argv[2]);
    std::string replaceWord(argv[3]);
    if (fileName == "")
    {
        putStr("Empty FILE Parameter!\n", RED_BLINK);
        putStr("Outfile not created nor truncated\n", MAGENTA);
        return (EXIT_FAILURE); 
    }
    else if (searchWord == "")
    {
        putStr("Empty SEARCH Parameter!\n", RED_BLINK);
        putStr("Outfile not created nor truncated\n", MAGENTA);
        return (EXIT_FAILURE); 
    }
    std::ifstream file(argv[1]);
    std::istreambuf_iterator<char> begin (file), end;
    if (!file.is_open())
    {
        error = std::strerror(errno);
        putStr("Infile Error: ", CYAN_BOLD);
        putStr(error, MAGENTA);
        putStr("\nOutfile not created nor truncated\n", RED);
        return(EXIT_FAILURE);
    }
    std::string content((begin), end);
    changeString(content, argv[2], argv[3]);
	fileName.append(".replace");
	std::ofstream newFile(fileName.c_str());
	newFile << content;
	newFile.close();
}