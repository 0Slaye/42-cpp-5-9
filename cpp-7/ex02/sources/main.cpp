/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:13 by slaye             #+#    #+#             */
/*   Updated: 2024/07/11 17:45:14 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	unsigned int size = 10;
	Array<int> list(size);
	Array<int> holder(list);

	list[0] = 10;
	std::cout << "list: [";
	for (unsigned int i = 0; i < size - 1; i++)
		std::cout << list[i] << ", ";
	std::cout << list[size - 1];
	std::cout << "]" << std::endl;

	std::cout << "holder: [";
	for (unsigned int i = 0; i < size - 1; i++)
		std::cout << holder[i] << ", ";
	std::cout << holder[size - 1];
	std::cout << "]" << std::endl;

	return (0);
}