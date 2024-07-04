/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:58:47 by slaye             #+#    #+#             */
/*   Updated: 2024/07/04 16:13:03 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "commons.hpp"

class ScalarConverter {
	public:
		ScalarConverter(void); // canonical
		ScalarConverter(ScalarConverter const &ref); // canonical
		virtual ~ScalarConverter(void) = 0; // canonical

		ScalarConverter	&operator=(ScalarConverter const &ref); // canonical
		static void	convert(std::string value);
};
