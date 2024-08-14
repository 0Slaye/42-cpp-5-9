/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/14 15:38:43 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

std::map<std::string, double>	parse_csv(char *path) {
	std::ifstream					file;
	std::string						line;
	std::map<std::string, double>	map;

	file.open(path);
	if (!file.good())
		throw std::exception();
	while (getline(file, line)) {
		map[line] = 0;
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
	std::map<std::string, double>::iterator it = map.begin();
	while (it != map.end()) {
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}
	return (0);
}