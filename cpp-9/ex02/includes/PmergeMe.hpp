/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:10:52 by slaye             #+#    #+#             */
/*   Updated: 2024/08/18 16:20:23 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "commons.hpp"

class PmergeMe {
	public:
		static void	vector_sort(std::vector<unsigned int> numbers);
		static std::vector<unsigned int>	vector_merge(std::vector<unsigned int> *doubles, unsigned int start, unsigned int end);

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &reference);
		virtual ~PmergeMe(void);

		PmergeMe	&operator=(const PmergeMe &reference);

};