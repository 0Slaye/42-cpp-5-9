/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:08:21 by slaye             #+#    #+#             */
/*   Updated: 2024/07/02 16:48:41 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const &ref)
{
	*this = ref;
}

Intern	&Intern::operator=(Intern const &ref)
{
	(void) ref;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	if (name == "ShrubberyCreationForm")
	{
		AForm	*result = new ShrubberyCreationForm(target);
		std::cout << "Intern creates " << name << std::endl;
		return (result);
	}
	else if (name == "RobotomyRequestForm")
	{
		AForm	*result = new RobotomyRequestForm(target);
		std::cout << "Intern creates " << name << std::endl;
		return (result);
	}
	else if (name == "PresidentialPardonForm")
	{
		AForm	*result = new PresidentialPardonForm(target);
		std::cout << "Intern creates " << name << std::endl;
		return (result);
	}
	std::cerr << "Form name don't exist" << std::endl;
	return (NULL);
}

Intern::~Intern(void)
{
}