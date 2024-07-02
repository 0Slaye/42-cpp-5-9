/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:37:59 by slaye             #+#    #+#             */
/*   Updated: 2024/07/01 17:53:26 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

AForm::AForm(void) : _name("Default"), _is_signed(false), _g_sign(150), _g_exec(150)
{
}

AForm::AForm(const std::string name, unsigned int g_sign, unsigned int g_exec)
{
	if (g_sign < 1 || g_exec < 1)
		throw AForm::GradeTooHighException();
	else if (g_sign > 150 || g_exec > 150)
		throw AForm::GradeTooLowException();
	else
	{
		this->_name = name;
		this->_is_signed = false;
		this->_g_sign = g_sign;
		this->_g_exec = g_exec;
	}
}

AForm::AForm(AForm const &ref)
{
	*this = ref;
}

AForm::~AForm(void)
{
}

AForm	&AForm::operator=(AForm const &ref)
{
	this->_name = ref.getName();
	this->_is_signed = ref.getStatus();
	this->_g_sign = ref.getGradeSign();
	this->_g_exec = ref.getGradeExec();
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getStatus(void) const
{
	return (this->_is_signed);
}

unsigned int	AForm::getGradeSign(void) const
{
	return (this->_g_sign);
}

unsigned int	AForm::getGradeExec(void) const
{
	return (this->_g_exec);
}

void	AForm::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	else
		this->_is_signed = true;
}

std::ostream	&operator<<(std::ostream &stream, AForm const &ref)
{
	stream << "Name: " << ref.getName() << "\nStatus: " << ref.getStatus() << "\nSign grade: " << ref.getGradeSign() << "\nExec grade: " << ref.getGradeExec();
	return (stream);
}