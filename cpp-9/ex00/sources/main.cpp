/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/15 15:05:07 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

int	main(int argc, char **argv) {
	std::map<std::string, double>	data;
	std::map<std::string, double>	input;

	if (argc != 2) {
		std::cerr << DEBUG_NAME << std::invalid_argument(ERR_ARG).what() << std::endl;
		return (1);
	}
	try { data = parse_data(DATA_PATH); }
	catch (std::exception &e) {
		std::cerr << DEBUG_NAME << e.what() << std::endl;
		return (1);
	}
	try { input = parse_input(argv[1]); }
	catch (std::exception &e) {
		std::cerr << DEBUG_NAME << e.what() << std::endl;
		return (1);
	}
	return (0);
}