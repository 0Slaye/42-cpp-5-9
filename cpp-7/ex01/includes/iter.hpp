/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:12:09 by slaye             #+#    #+#             */
/*   Updated: 2024/08/15 14:01:13 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename A, typename B>
void	iter(A *addr, size_t length, B *func)
{
	if (func == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
	{
		func(addr[i]);
	}
}
