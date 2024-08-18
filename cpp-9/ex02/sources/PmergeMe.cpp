/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:11:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/18 14:26:35 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &reference)
{
	static_cast<void>(reference);
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &reference)
{
	static_cast<void>(reference);
	return (*this);
}

void	PmergeMe::vector_sort(std::string value)
{
	std::cout << value << std::endl;
}