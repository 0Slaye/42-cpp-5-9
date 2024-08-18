/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:11:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/18 15:56:06 by slaye            ###   ########.fr       */
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

void	PmergeMe::vector_sort(std::vector<unsigned int> numbers)
{
	std::vector<unsigned int>::iterator	it = numbers.begin();
	unsigned int						length = (numbers.size() % 2) ? (numbers.size() / 2 + 1) : (numbers.size() / 2);
	std::vector<unsigned int>			doubles[length];
	unsigned int						counter = 0;
	unsigned int						holder;

	// generating pairs
	while (it < numbers.end() - 1) {
		doubles[counter].push_back(*it);
		doubles[counter].push_back(*(it + 1));
		it += 2;
		counter++;
	}
	if (numbers.size() % 2 != 0)
		doubles[counter].push_back(*it);

	// sorting pairs
	for (unsigned int i = 0; i < length; i++) {
		if (doubles[i].size() == 1)
			continue ;
		else if (doubles[i][0] > doubles[i][1]) {
			holder = doubles[i][0];
			doubles[i][0] = doubles[i][1];
			doubles[i][1] = holder;
		}
	}
}

// printing pairs
	// std::cout << "(";
	// for (unsigned int i = 0; i < length; i++) {
	// 	std::vector<unsigned int>::iterator itt = doubles[i].begin();
	// 	std::cout << "(";
	// 	while (itt != doubles[i].end()) {
	// 		std::cout << *itt;
	// 		if (!(itt + 1 == doubles[i].end()))
	// 			std::cout << ",";
	// 		itt++;
	// 	}
	// 	std::cout << ")";
	// 	if (i + 1 < length)
	// 		std::cout << ", ";
	// }
	// std::cout << ")" << std::endl;