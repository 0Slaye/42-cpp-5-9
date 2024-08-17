/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/17 15:59:23 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

std::string			operations = "+-/*";

bool	is_format(std::string value)
{
	unsigned int	spaceless_length = 0;

	for (unsigned int i = 0; i < value.length(); i++) {
		if (!isdigit(value[i]) && value[i] != '+' && value[i] != ' ' && value[i] != '-' && value[i] != '/' && value[i] != '*')
			return (false);
	}
	for (unsigned int i = 0; i < value.length(); i++) {
		if (value[i] == ' ')
			spaceless_length++;
	}
	if (value.length() - spaceless_length < 3)
		return (false);
	return (true);
}

int	main(int argc, char **argv) {
	std::string	value;

	if (argc != 2) {
		std::cerr << DEBUG_NAME << ERR_ARG << std::endl;
		return (1);
	}
	value = argv[1];
	if (!is_format(value)) {
		std::cerr << DEBUG_NAME << ERR_FORMAT << std::endl;
		return (2);
	}
	try { std::cout << RPN::calculate(value) << std::endl; }
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}