/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:33:45 by slaye             #+#    #+#             */
/*   Updated: 2024/07/08 16:34:11 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
class Array {
	public:
		Array(void);
		Array(Array const &ref)
		virtual ~Array(void);
		Array	&operator=(Array const &ref);
		T		&operator[](unsigned int index) const;

		unsigned int	size(void) const;

	private:
		T			_content;
		Array<T>	*_next;
};
