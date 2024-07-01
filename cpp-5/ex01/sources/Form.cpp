/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:37:59 by slaye             #+#    #+#             */
/*   Updated: 2024/07/01 16:40:15 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

Form::Form(const std::string name, unsigned int g_sign, unsigned int g_exec)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (g_sign < 1 || g_exec < 1)
		throw Form::GradeTooHighException();
	else if (g_sign > 150 || g_exec > 150)
		throw Form::GradeTooLowException();
	else
	{
		this->_name = name;
		this->_is_signed = false;
		this->_g_sign = g_sign;
		this->_g_exec = g_exec;
	}
}

Form::Form(Form const &ref)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	*this = ref;
}

Form::~Form(void)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Form	&Form::operator=(Form const &ref)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	this->_name = ref.getName();
	this->_is_signed = ref.getStatus();
	this->_g_sign = ref.getGradeSign();
	this->_g_exec = ref.getGradeExec();
	return (*this);
}

std::string	Form::getName(void) const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return (this->_name);
}

bool	Form::getStatus(void) const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return (this->_is_signed);
}

unsigned int	Form::getGradeSign(void) const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return (this->_g_sign);
}

unsigned int	Form::getGradeExec(void) const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return (this->_g_exec);
}

void	Form::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else
		this->_is_signed = true;
}

std::ostream	&operator<<(std::ostream &stream, Form const &ref)
{
	stream << "Name:" << ref.getName();
	stream << "Status:" << ref.getStatus();
	stream << "Sign grade:" << ref.getGradeSign();
	stream << "Exec grade:" << ref.getGradeExec();
	return (stream);
}