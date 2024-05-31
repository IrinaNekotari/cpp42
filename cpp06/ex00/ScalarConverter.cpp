/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:16:48 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/01 00:16:50 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool ft_isPrintable(char c)
{
    if (c >= 32 && c <= 126)
        return true;
    return false;
}

static bool ft_isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & s)
{
    *this = s;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & s)
{
    (void)s;
    return (*this);
}

void ScalarConverter::convert(const std::string& s)
{
    std::string exceptions[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

    if (s.size() == 1 && ft_isPrintable(s[0]) && !ft_isDigit(s[0]))
    {
        toChar      = s[0];
        toInt       = static_cast<int>(toChar[0]);
        toFloat     = static_cast<float>(toChar[0]);
        toDouble    = static_cast<double>(toChar[0]);
    }
    else 
    {
        toInt = std::atoi(s.c_str());
        if (s[s.length() - 1] == 'f') 
        {
            toFloat = std::atof(s.c_str());
            toDouble = static_cast<double>(toFloat);
        } 
        else 
        {
            toDouble = std::atof(s.c_str());
            toFloat = static_cast<float>(toDouble);
        }
        for (int i = 0; i < 6; i++) 
        {
            if (s == exceptions[i]) 
            {
                toChar = "imposible"; 
                break;
            }
	    }
        if (toChar == "" && ft_isPrintable(toInt))
        {
            toChar = "'";
			toChar += static_cast<char>(toInt);
            toChar += "'";
        } 
        else if (toChar == "") 
            toChar = "Non displayable";
    }
    std::cout << "char:	" << toChar << std::endl;
	if (toChar == "imposible") 
		std::cout << "int:	imposible" << std::endl;
    else
		std::cout << "int:	" << toInt << std::endl;
	if (toChar == "imposible" && toFloat == 0) 
	{
		std::cout << "float:	imposible" << std::endl;
		std::cout << "double:	imposible" << std::endl;
	}
	else
	{
		if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0)
		{
			std::cout << "float:	" << toFloat << ".0f" << std::endl;
			std::cout << "double:	" << toDouble << ".0" << std::endl;
		}
		else
		{
			std::cout << "float:	" << toFloat << "f" << std::endl;
			std::cout << "double:	" << toDouble << std::endl;
		}
	}
}