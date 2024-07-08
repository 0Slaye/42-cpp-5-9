/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:13:28 by slaye             #+#    #+#             */
/*   Updated: 2024/07/08 16:38:20 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _content(new T()), _next(NULL)
{
}

template <typename T>
Array<T>::Array(Array const &ref)
{
	Array<T>	*result = new Array();
	Array<T>	*holder;

	holder = result;
	for (size_t i = 0; i < ref.size(); i++)
	{
		holder->next = new Array();
		holder = holder->next;
	}
	
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &ref)
{
}

template <typename T>
T		&Array<T>::operator[](unsigned int index) const
{
	Array<T>	*result;

	result = this;
	if (index > this->size())
		throw (std::exception);
	for (size_t i = 0; i < this->size(); i++)
		result = result->_next;
	return (result);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	Array<T>	*holder;
	size_t		result;

	holder = this;
	result = 0;
	while (this)
	{
		this = this->_next;
		result++;
	}
	this = holder;
	return (result);
}

template <typename T>
Array<T>::~Array(void)
{
	while (this)
	{
		delete (this->_content);
		this = this->next;
	}
}
