/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:10:52 by slaye             #+#    #+#             */
/*   Updated: 2024/08/17 16:11:06 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "commons.hpp"

class PmergeMe {
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &reference);
		virtual ~PmergeMe(void);

		PmergeMe	&operator=(const PmergeMe &reference);

	private:
};