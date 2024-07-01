/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:17:50 by slaye             #+#    #+#             */
/*   Updated: 2024/07/01 17:51:48 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "commons.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(void); // canonical
		Bureaucrat(Bureaucrat const &ref); // canonical
		virtual ~Bureaucrat(void); // canonical

		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat		&operator=(Bureaucrat const &ref); // canonical
		std::string		getName(void) const;
		unsigned int	getGrade(void) const;
		void			upgrade(void);
		void			downgrade(void);
		void			signForm(Form &ref);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw()
				{
					return ("Grade too low");
				}
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw()
				{
					return ("Grade too high");
				}
		};
	private:
		std::string		_name;
		unsigned int	_grade;
};

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &ref);