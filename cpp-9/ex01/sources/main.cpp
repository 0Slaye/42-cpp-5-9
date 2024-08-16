/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/16 15:35:16 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << DEBUG_NAME << ERR_ARG << std::endl;
		return (1);
	}
	std::cout << RPN::calculate(argv[1]) << std::endl;
	return (0);
}