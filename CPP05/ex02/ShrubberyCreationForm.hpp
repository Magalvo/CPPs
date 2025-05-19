#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#pragma once

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
    virtual void performAction() const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    class OpenFileExeption : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif