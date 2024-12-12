/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:03:02 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/12 17:00:01 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[1;31;5m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[0;33m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[36m"

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

void    putStr(std::string str, std::string color)
{
   std::cout << color << str; 
}

int main(int argc, char **argv){
    if (argc != 4)
    {
        putStr("wrong number of arguments\n", CYAN);
        putStr("Usage:\t./replace <file_name> <search> <replace>\n", GREEN);
    }
    if (!argv[2][0])
        putStr("Empty Parameter!\n", RED);
    std::ifstream file(argv[1]);
    std::istreambuf_iterator<char> begin (file), end;
    if (!file.is_open())
    {
        std::perror("Infile Error");
        putStr("Outfile not created nor truncated\n", RED);
        putStr("", RESET);
        return(EXIT_FAILURE);
    }
    std::string content((begin), end);
    changeString(content, argv[2], argv[3]);

	//create a file
	std::string fileName = argv[1];
	fileName.append(".replace");
	std::ofstream newFile(fileName.c_str());
	newFile << content;
	newFile.close();  
}