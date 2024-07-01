/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:29:24 by slaye             #+#    #+#             */
/*   Updated: 2024/07/01 16:17:27 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "commons.hpp"
#include "Bureaucrat.hpp"

class Form {
	public:
		Form(const std::string name, unsigned int g_sign, unsigned int g_exec); // canonical
		Form(Form const &ref); // canonical
		virtual ~Form(void); // canonical

		Form			&operator=(Form const &ref); // canonical
		std::string		getName(void) const;
		bool			getStatus(void) const;
		unsigned int	getGradeSign(void) const;
		unsigned int	getGradeExec(void) const;
		void			beSigned(Bureaucrat &ref);

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
		bool			_is_signed;
		unsigned int	_g_sign;
		unsigned int	_g_exec;
};

std::ostream	&operator<<(std::ostream &stream, Form const &ref);