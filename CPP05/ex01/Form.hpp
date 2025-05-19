#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include <ostream>
#pragma once

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_execute_grade;

	public:
		Form();
        ~Form();
		Form(const std::string name, const int sign_grade, const int execute_grade);
		Form(const Form &other);
		Form &operator=(const Form &other);

		void		beSigned(const Bureaucrat &bureaucrat);
        int			getSignGrade() const;
		int			getExecuteGrade() const;
        bool		getIsSigned() const;
		std::string getName() const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os,  Form const &form);

#endif