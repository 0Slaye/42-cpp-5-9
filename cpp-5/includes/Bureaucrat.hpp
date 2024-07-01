/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:17:50 by slaye             #+#    #+#             */
/*   Updated: 2024/07/01 14:19:11 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Bureaucrat {
	public:
		Bureaucrat(void); // canonical
		Bureaucrat(Bureaucrat const &ref); // canonical
		virtual ~Bureaucrat(void); // canonical

		Bureaucrat	&operator=(Bureaucrat const &ref); // canonical
};
