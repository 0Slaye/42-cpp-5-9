/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:13 by slaye             #+#    #+#             */
/*   Updated: 2024/07/08 15:32:14 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	printer(std::string value)
{
	std::cout << "[" << value << "], ";
}

int main( void ) {
	std::string	array[5] = {"Hello", "this", "is", "a", "test"};

	iter(array, 5, &printer);
	std::cout << std::endl;
	return (0);
}