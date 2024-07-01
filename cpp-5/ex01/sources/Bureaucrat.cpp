/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:16:48 by slaye             #+#    #+#             */
/*   Updated: 2024/07/01 16:40:40 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		this->_name = name;
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	*this = ref;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &ref)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	this->_name = ref.getName();
	this->_grade = ref.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return (this->_grade);
}

void	Bureaucrat::upgrade(void)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}
void	Bureaucrat::downgrade(void)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form &ref)
{
	try
	{
		ref.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << "couldn't sign " << ref.getName() << "because" << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << ref.getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &ref)
{
	stream << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (stream);
}