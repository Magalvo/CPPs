#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#pragma once

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
    virtual void performAction() const;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    class RobotizationFailed : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif