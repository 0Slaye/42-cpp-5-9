/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:26:27 by slaye             #+#    #+#             */
/*   Updated: 2024/08/09 12:12:00 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>(void);
		MutantStack<T>(const MutantStack &reference);
		virtual ~MutantStack<T>(void);

		MutantStack<T>	&operator=(const MutantStack &reference);

		class iterator;
		iterator begin();
		iterator end();
		const iterator begin() const;
		const iterator end() const;
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	// Implementation
}