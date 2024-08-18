/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:11:13 by slaye             #+#    #+#             */
/*   Updated: 2024/08/18 17:13:52 by slaye            ###   ########.fr       */
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

std::vector<unsigned int>	PmergeMe::vector_merge(std::vector<unsigned int> *doubles, unsigned int start, unsigned int end)
{
	std::vector<unsigned int>	result;
	unsigned int				length = end - start;

	if (length == 1) {
		std::vector<unsigned int>::iterator	left_it = doubles[start].begin();
		while (left_it != doubles[start].end()) {
			std::vector<unsigned int>::iterator	right_it = doubles[end].begin();
			while (right_it != doubles[end].end()) {
				if (*left_it < *right_it) {
					result.push_back(*left_it);
					left_it = doubles[start].erase(left_it);
					break ;
				}
				else {
					result.push_back(*right_it);
					right_it = doubles[end].erase(right_it);
				}
			}
		}
		if (doubles[start].size() != 0) {
			std::vector<unsigned int>::iterator	it = doubles[start].begin();
			while (it != doubles[start].end()) {
				result.push_back(*it);
				it++;
			}
		}
		else if (doubles[end].size() != 0) {
			std::vector<unsigned int>::iterator	it = doubles[end].begin();
			while (it != doubles[end].end()) {
				result.push_back(*it);
				it++;
			}
		}
	}
	else {
		std::vector<unsigned int> holder = vector_merge(doubles, start + 1, end);
		std::vector<unsigned int>::iterator	left_it = doubles[start].begin();
		while (left_it != doubles[start].end()) {
			std::vector<unsigned int>::iterator	right_it = holder.begin();
			while (right_it != holder.end()) {
				if (*left_it < *right_it) {
					result.push_back(*left_it);
					left_it = doubles[start].erase(left_it);
					break ;
				}
				else {
					result.push_back(*right_it);
					right_it = holder.erase(right_it);
				}
			}
		}
		if (doubles[start].size() != 0) {
			std::vector<unsigned int>::iterator	it = doubles[start].begin();
			while (it != doubles[start].end()) {
				result.push_back(*it);
				it++;
			}
		}
		else if (holder.size() != 0) {
			std::vector<unsigned int>::iterator	it = holder.begin();
			while (it != holder.end()) {
				result.push_back(*it);
				it++;
			}
		}
	}
	return (result);
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

	// first half merge (right half)
	unsigned int				start = 0;
	unsigned int				end = length - 1;
	std::vector<unsigned int>	result = vector_merge(doubles, start, end);
	std::vector<unsigned int>::iterator itr = result.begin();
	while (itr != result.end()) {
		std::cout << *itr << ", ";
		itr++;
	}
	std::cout << std::endl;
}