/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:33:45 by slaye             #+#    #+#             */
/*   Updated: 2024/07/11 17:42:57 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
class Array {
	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array const &ref);
		virtual ~Array<T>(void);
		Array	&operator=(Array const &ref);
		T		&operator[](unsigned int index) const;

		unsigned int	size(void) const;

	private:
		unsigned int	_length;
		T				*_array;
};

template <typename T>
Array<T>::Array(void) : _length(0), _array(new T[0])
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _length(n), _array(new T[n])
{
	for (unsigned int i = 0; i < this->_length; i++)
		this->_array[i] = 0;
}

template <typename T>
Array<T>::Array(Array const &ref) : _length(ref._length), _array(new T[ref._length])
{
	for (unsigned int i = 0; i < this->_length; i++)
		this->_array[i] = ref._array[i];
}

template <typename T>
Array<T>::~Array(void)
{
	if (this->_length == 0)
		return ;
	delete [] this->_array;
}

template <typename T>
T	&Array<T>::operator[](unsigned int index) const
{
	if (index > this->_length)
		throw std::exception();
	return (this->_array[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_length);
}