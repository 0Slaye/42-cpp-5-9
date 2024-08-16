/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:41:18 by slaye             #+#    #+#             */
/*   Updated: 2024/08/16 13:35:05 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

bool	is_valid_date(std::string value) {
	unsigned int	digits[8] = {0, 1, 2, 3, 5, 6, 8, 9};
	unsigned int	dashs[2] = {4, 7};
	unsigned int	year;
	std::string		month_31[7] = {"01", "03", "05", "07", "08", "10", "12"};
	bool			is_31 = false;

	for (unsigned int i = 0; i < 8; i++) {
		if (!std::isdigit(value[digits[i]]))
			return (false);
	}
	for (unsigned int i = 0; i < 2; i++) {
		if (value[dashs[i]] != '-')
			return (false);
	}
	if (value[10] != ' ')
		return (false);
	// value checking
	if (atof(value.substr(5, 2).c_str()) > 12)
		return (false);
	for (unsigned int i = 0; i < 7; i++) {
		if (value.substr(5, 2) == month_31[i]) {
			is_31 = true;
			break ;
		}
	}
	if (is_31 && atof(value.substr(8, 2).c_str()) > 31)
		return (false);
	else if (!is_31 && atof(value.substr(8, 2).c_str()) > 30)
		return (false);
	year = atof(value.substr(0, 4).c_str());
	if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
		if (value.substr(5, 2) == "02" && value.substr(8, 2) == "29")
			return (false);
	}
	return (true);
}

bool is_formated(std::string value) {
	std::string	date;
	std::string	number;

	if (value.find('|') == std::string::npos)
		return (false);
	date = value.substr(0, value.find('|'));
	number = value.substr(value.find('|') + 1, value.length());
	if (date.length() != 11 || !is_valid_date(date))
		return (false);
	return (true);
}