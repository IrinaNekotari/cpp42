/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 01:10:14 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/07 01:10:18 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int>			list;
		int							size;
	public:
		Span(unsigned int size);
		~Span();
		Span(const Span & s);
		Span & operator=(const Span & s);

		void			addNumber(int n);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		class ErrorTooManyValue : public std::exception
		{
			public: 
        		const char* what(void) const throw();
		};

		class ErrorNotEnoughValue : public std::exception
		{
			public: 
        		const char* what(void) const throw();
		};
};
