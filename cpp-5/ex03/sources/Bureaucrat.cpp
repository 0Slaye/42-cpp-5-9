/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:16:48 by slaye             #+#    #+#             */
/*   Updated: 2024/07/02 16:25:54 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
{
	
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
	*this = ref;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &ref)
{
	
	this->_name = ref.getName();
	this->_grade = ref.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	
	return (this->_grade);
}

void	Bureaucrat::upgrade(void)
{
	
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}
void	Bureaucrat::downgrade(void)
{
	
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &ref)
{
	try
	{
		ref.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << ref.getName() << "because" << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << ref.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &ref)
{
	stream << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (stream);
}