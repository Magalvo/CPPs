/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:43:56 by dde-maga          #+#    #+#             */
/*   Updated: 2025/01/07 13:51:03 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>
#include "Animal.hpp"

typedef std::string t_string;

class WrongAnimal {
	protected:
		t_string type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		t_string getType() const;
		virtual void makeSound() const;
};
#endif