/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:10:52 by slaye             #+#    #+#             */
/*   Updated: 2024/08/18 14:44:49 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "commons.hpp"

class PmergeMe {
	public:
		static void	vector_sort(std::vector<int> numbers);

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &reference);
		virtual ~PmergeMe(void);

		PmergeMe	&operator=(const PmergeMe &reference);
};