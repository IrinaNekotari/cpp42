/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 01:10:41 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/07 01:10:42 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size): size(size) {}

Span::~Span(){}

Span::Span(const Span & s)
{
	*this = s;
}

Span & Span::operator=(const Span & s)
{
	this->size = s.size;
	this->list = s.list;
	return *this;
}

void	Span::addNumber(int n)
{
	if (static_cast<int> (this->list.size()) >= this->size)
		throw Span::ErrorTooManyValue();
	this->list.push_back(n);
}

unsigned int Span::shortestSpan() const 
{
	if (this->size < 2 || this->list.size() < 2)
		throw Span::ErrorNotEnoughValue();
	
	std::vector<int> tmp(this->list);
	std::sort(tmp.begin(), tmp.end());
	int smallest = *(tmp.begin() + 1) - *(tmp.begin());
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; ++it)
	{
		if (*(it + 1) - *(it) < smallest)
			smallest = *(it + 1) - *(it);
	}
	return smallest;
	
}

unsigned int Span::longestSpan() const
{
	if (this->size < 2 || this->list.size() < 2)
		throw Span::ErrorNotEnoughValue();
	int highest = *(std::max_element(this->list.begin(), this->list.end()))
					- *(std::min_element(this->list.begin(), this->list.end()));
	return highest;
}

const char * Span::ErrorTooManyValue::what() const throw()
{
	return "ERROR - Can't insert value, max amount of value reached !";
}

const char * Span::ErrorNotEnoughValue::what() const throw()
{
	return "ERROR - Can't find span, there's not enough value in array !";
}