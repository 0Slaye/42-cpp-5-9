/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/18 14:26:56 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

int	main(int argc, char **argv) {
	std::string	numbers;

	if (argc < 2) {
		std::cerr << DEBUG_NAME << ERR_ARG <<std::endl;
		return (1); 
	}
	numbers = argv[1];
	PmergeMe::vector_sort(numbers);
	return (0);
}