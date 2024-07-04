/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:59:28 by slaye             #+#    #+#             */
/*   Updated: 2024/07/04 17:41:55 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
	*this = ref;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &ref)
{
	(void) ref;
	return (*this);
}

bool	is_int(std::string value)
{
	long unsigned int	i;

	i = -1;
	if (value[0] == '-')
		i = 0;
	while (++i < value.length())
	{
		if (!(value[i] >= '0' && value[i] <= '9'))
			return (false);
	}
	return (true);
}

bool	is_float(std::string value)
{
	long unsigned int	i;
	bool				is_positive;
	int					dot_counter;

	i = -1;
	is_positive = true;
	if (value[0] == '-')
	{
		i = 0;
		is_positive = false;
	}
	if (is_positive && value[0] == '.')
		return (false);
	if (!is_positive && value[1] == '.')
		return (false);
	if (value[value.length() - 1] != 'f')
		return (false);
	while (++i < value.length() - 1)
	{
		if (i == value.length() - 2 && value[i] == '.')
			return (false);
		else if (!(value[i] >= '0' && value[i] <= '9') && value[i] != '.')
			return (false);
	}
	if (is_positive)
		i = -1;
	else
		i = 0;
	dot_counter = 0;
	while (++i < value.length() - 1)
	{
		if (value[i] == '.')
			dot_counter++;
	}
	if (dot_counter != 1)
		return (false);
	return (true);
}

bool	is_double(std::string value)
{
	long unsigned int	i;
	bool				is_positive;
	int					dot_counter;

	i = -1;
	is_positive = true;
	if (value[0] == '-')
	{
		i = 0;
		is_positive = false;
	}
	if (is_positive && value[0] == '.')
		return (false);
	if (!is_positive && value[1] == '.')
		return (false);
	if (value[value.length()] == '.')
		return (false);
	while (++i < value.length())
	{
		if (!(value[i] >= '0' && value[i] <= '9') && value[i] != '.')
			return (false);
	}
	if (is_positive)
		i = -1;
	else
		i = 0;
	dot_counter = 0;
	while (++i < value.length() - 1)
	{
		if (value[i] == '.')
			dot_counter++;
	}
	if (dot_counter != 1)
		return (false);
	return (true);
}

void	ScalarConverter::convert(std::string value)
{
	if (is_float(value))
	{
		float	result;
		std::istringstream convert(value);
		convert >> result;
		std::cout << "char: " << static_cast<char>(result) << std::endl;
		std::cout << "int: " << static_cast<int>(result) << std::endl;
		std::cout << "float: " << static_cast<float>(result) << std::endl;
		std::cout << "double: " << static_cast<double>(result) << std::endl;
	}
	else if (is_double(value))
	{
		double	result;
		std::istringstream convert(value);
		convert >> result;
		std::cout << "char: " << static_cast<char>(result) << std::endl;
		std::cout << "int: " << static_cast<int>(result) << std::endl;
		std::cout << "float: " << static_cast<float>(result) << std::endl;
		std::cout << "double: " << static_cast<double>(result) << std::endl;
	}
	else if (is_int(value))
	{
		int	result;
		std::istringstream convert(value);
		convert >> result;
		std::cout << "char: " << static_cast<char>(result) << std::endl;
		std::cout << "int: " << static_cast<int>(result) << std::endl;
		std::cout << "float: " << static_cast<float>(result) << std::endl;
		std::cout << "double: " << static_cast<double>(result) << std::endl;
	}
	else if (value.length() == 1)
	{
		char	result;
		std::istringstream convert(value);
		convert >> result;
		std::cout << "char: " << static_cast<char>(result) << std::endl;
		std::cout << "int: " << static_cast<int>(result) << std::endl;
		std::cout << "float: " << static_cast<float>(result) << std::endl;
		std::cout << "double: " << static_cast<double>(result) << std::endl;
	}
	else
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: Nanf" << std::endl;
		std::cout << "double: Nan" << std::endl;
	}
}