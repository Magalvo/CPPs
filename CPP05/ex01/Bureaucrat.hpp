#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
#pragma once

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

class Form;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form);
    int getGrade() const;
    std::string getName() const;

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

void putStr(std::string str, std::string color);
void putNum(int bits, std::string color);
void putErr(std::string str, std::string color);

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other);

#endif