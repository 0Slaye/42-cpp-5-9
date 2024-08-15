/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:12:24 by uwywijas          #+#    #+#             */
/*   Updated: 2024/08/15 15:07:36 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>

#define DATA_PATH "utils/data.csv"
#define DEBUG_NAME "btc: "
#define ERR_ARG "error: wrong number of arguments."
#define ERR_FILE "error: input file cannot be read."
#define ERR_BAD_INPUT "error: bad input => "

std::map<std::string, double>	parse_data(const char *path);
std::map<std::string, double>	parse_input(char *path);