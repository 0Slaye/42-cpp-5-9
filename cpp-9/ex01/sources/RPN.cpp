/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:30:37 by slaye             #+#    #+#             */
/*   Updated: 2024/08/16 15:36:25 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN &reference)
{
	(void) reference;
}

RPN::~RPN(void)
{
}

RPN	&RPN::operator=(const RPN &reference)
{
	(void) reference;
	return (*this);
}

float	RPN::calculate(char *value)
{
	float	result;

	result = 0;
	(void) value;
	return (result);
}