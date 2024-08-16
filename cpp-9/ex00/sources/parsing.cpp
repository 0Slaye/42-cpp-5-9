/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:55:18 by slaye             #+#    #+#             */
/*   Updated: 2024/08/16 13:33:03 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

std::map<std::string, double>	parse_data(const char *path) {
	std::ifstream					file;
	std::string						line;
	std::map<std::string, double>	map;
	bool							is_first = true;
	unsigned int					comma_index = 0;

	file.open(path);
	if (!file.good())
		throw std::runtime_error(ERR_FILE);
	while (getline(file, line)) {
		if (is_first) {
			is_first = false;
			continue ;
		}
		comma_index = line.find(',');
		map[line.substr(0, comma_index)] = atof(line.substr(comma_index + 1, line.length()).c_str());
	}
	file.close();
	return (map);
}

std::map<std::string, double>	parse_input(char *path) {
	std::ifstream					file;
	std::string						line;
	std::map<std::string, double>	map;
	bool							is_first = true;

	file.open(path);
	if (!file.good())
		throw std::runtime_error(ERR_FILE);
	while (getline(file, line)) {
		if (is_first && line == "date | value") {
			is_first = false;
			continue ;
		}
		else if (is_first) {
			throw std::runtime_error(ERR_FILE);
		}
		if (!is_formated(line))
			std::cerr << DEBUG_NAME << ERR_BAD_INPUT << line << std::endl;
	}
	file.close();
	return (map);
}