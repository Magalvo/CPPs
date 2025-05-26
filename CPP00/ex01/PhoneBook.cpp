/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:25:06 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/16 18:20:33 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void    putStr(std::string str)
{
   std::cout << str; 
}

PhoneBook::PhoneBook(void){
	putStr("Phone Book was created\n");
}

PhoneBook::~PhoneBook(void){
	putStr("Phone Book was destroyed\n");
}

void    PhoneBook::putCharN(std::string toPrint, long unsigned int n){
	if (toPrint.length() > n)
		std::cout << toPrint.substr(0, n - 1) << ".";
	else
		std::cout << std::right << std::setw(10) << toPrint;
}

bool	PhoneBook::validNumber(std::string phoneNumber, bool isPhone){
	int	i = 0;
	if (!isPhone)
		return (true);
	i = phoneNumber[0] && phoneNumber[0] == '+' ? 1 : 0;
	if (!phoneNumber[i]){
		putStr("Invalid phone number! Type again: \n");
		return (false);
	}
	while (phoneNumber[i]){
		if (!std::isdigit(phoneNumber[i++])){
			putStr("Inavlid phone number! Type again: \n");
			return (false);
		}
	}
	return (true);
}

std::string PhoneBook::getValidInput(std::string prompt, bool isPhone){
	std::string input;
	putStr(prompt);
	putStr("\n");
	//std::cout << prompt << std::endl;
	do{
		std::getline(std::cin, input);
		//?checks for non-printables so we can ignore them 
		std::string filteredInput;
		for (std::string::size_type i = 0; i < input.length(); ++i) {
			if (std::isprint(static_cast<unsigned char>(input[i]))) {
				filteredInput += input[i];
			}
		}
		input = filteredInput;
	}
	while(!std::cin.eof() && (!validNumber(input, isPhone) || input.length() == 0));

	if(std::cin.eof()){
		std::cout << std::endl;
		putStr("End of file was reached(EOF)! Exiting program...\n");
		return (input);
	}
	return (input);
}

void	PhoneBook::addContact(int position){
	Contact *appendContact;

	if (position >= NUMNUM)
	{
		for (int i = 0; i < NUMNUM - 1; i++){
			this->contacts[i] = this->contacts[i+1];
			this->contacts[i].increaseIndex(-1);
		}
		appendContact = &this->contacts[NUMNUM - 1];
	} else {
		appendContact = &this->contacts[position];
		appendContact->setIndex(position);
	}
	
	appendContact->setFirstName(getValidInput("First Name:", false));
	appendContact->setLastName(getValidInput("Last Name: ", false));
	appendContact->setNickname(getValidInput("Nickname:", false));
	appendContact->setPhoneNumber(getValidInput("Phone Number:", true));
	appendContact->setDarkSecret(getValidInput("Darkest Secret:", false));
	putStr("Contact added successfully :)\n\n");
}

Contact *PhoneBook::findContactByIndex(int index, int position){
	for (int i = 0; i < position; i++){
		if (this->contacts[i].getIndex() == index)
			return &(this->contacts[i]);
	}
	return &(this->contacts[0]);
}

void	PhoneBook::searchContacts(int position){
	
	int index;
	//?giving a width spacing
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

	for(int i = 0; i < position; i++)
	{
		std::cout << std::right << std::setw(10) << this->contacts[i].getIndex() << "|";
		putCharN(this->contacts[i].getFirstName(), 10);
		std::cout << "|";
		putCharN(this->contacts[i].getLastName(), 10);
		std::cout << "|";
		putCharN(this->contacts[i].getNickname(), 10);
		std::cout << std::endl;
	}
	putStr("Index Check -> ");
	
	if (!(std::cin >> index) || index < 0 || index >= position || index >= NUMNUM){
		putStr("Contact non existent on the database\n");
		if (std::cin.eof()){
			putStr("End of file was reached(EOF)! Exiting program...\n");
			return ;
		}
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		return ;
	} else {
		if(std::cin.eof()){
			putStr("End of file was reached(EOF)! Exiting program...\n");
			return ;
		}
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		Contact	*currentContact = findContactByIndex(index, position);
		std::cout << "Index: " << currentContact->getIndex() << std::endl;
		std::cout << "First Name: " << currentContact->getFirstName() << std::endl;
		std::cout << "Last Name: " << currentContact->getLastName() << std::endl;
		std::cout << "Nickname: " << currentContact->getNickname() << std::endl;
		std::cout << "Phone Number: " << currentContact->getPhoneNumber() << std::endl;
		std::cout << "DARKEST SECRET: " << currentContact->getDarkSecret() << std::endl << std::endl;
	}
}