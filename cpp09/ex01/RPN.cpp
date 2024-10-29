/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:25:28 by nmascrie          #+#    #+#             */
/*   Updated: 2024/10/29 09:25:30 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN & r)
{
    *this = r;
}

RPN & RPN::operator=(const RPN & r)
{
    this->_stack = r._stack;
    return (*this);
}

static bool is_operator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return (true);
    return (false);
}

static bool is_valid(std::string str)
{
    if (str.find_first_not_of(' ') == std::string::npos) 
    {
		std::cout << "Error: empty string" << std::endl;
		return (false);
	}
	if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
    {
		std::cout << "Error: invalid character" << std::endl;
		return (false);
	}
	if (str.find_first_of("+-*/") == std::string::npos)
    {
		std::cout << "Error: no operator" << std::endl;
		return (false);
	}
	if (str.length() < 5)
    {
		std::cout << "Error: format must be \"x x x\"" << std::endl;
		return (false);
	}
	if (!is_operator(str[str.length() - 1]))
    {
		std::cout << "Error: last character must be an operator" << std::endl;
		return (false);
	}
	for (size_t i = 0; i < str.length(); i++)
    {
		if (i % 2 == 0)
        {
			if (!isdigit(str[i]) && !is_operator(str[i]))
            {
				std::cout << "Error: format must be \"x x x\"" << std::endl;
				return (false);
			}
		}
        else
        {
			if (str[i] != ' ')
            {
				std::cout << "Error: format must be \"x x x\"" << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

RPN::RPN(std::string s)
{
    size_t i = 0;
    int    a, b;

    failed = true;
    if (!is_valid(s))
        return ;
    while (i < s.length())
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if (this->_stack.size() < 2)
            {
				std::cout << "Error: not enough numbers" << std::endl;
				while (!this->_stack.empty())
					this->_stack.pop();
                return;
            }
            a = _stack.top();
            _stack.pop();
            b = _stack.top();
            _stack.pop();
            if (s[i] == '+')
                _stack.push(b + a);
            else if (s[i] == '-')
                _stack.push(b - a);
            else if (s[i] == '*')
                _stack.push(b * a);
            else if (s[i] == '/')
            {
                if (a == 0)
                {
                    std::cout << "Error: Divided by 0 !" << std::endl;
                    return ;
                }
                _stack.push(b / a);
            }
        }
        else
            _stack.push(std::atoi(s.substr(i).c_str()));
        i++;
    }
    failed = false;
}

void    RPN::calculate()
{
    if (failed || _stack.size() > 1)
        return ;
    else
        std::cout << _stack.top() << std::endl;
}