/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/15 14:35:33 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

std::map<std::string, double>	parse_csv(char *path) {
	std::ifstream					file;
	std::string						line;
	std::map<std::string, double>	map;
	bool							is_first = true;
	unsigned int					comma_index = 0;

	file.open(path);
	if (!file.good())
		throw std::exception();
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

int	main(int argc, char **argv) {
	std::map<std::string, double>	map;

	if (argc != 2) {
		std::cerr << DEBUG_NAME << ERR_ARG << std::endl;
		return (1);
	}
	map = parse_csv(argv[1]);
	return (0);
}