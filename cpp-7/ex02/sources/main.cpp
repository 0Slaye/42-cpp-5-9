/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/08 14:46:12 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	unsigned int size = 10;
	Array<int> list(size);
	Array<int> holder(list);
	Array<int> tester;

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

	try
	{
		std::cout << holder[9] << std::endl;
		std::cout << tester[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}