/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 01:10:07 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/07 01:10:08 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

int main(void)
{
	Span *s = new Span(20);
	srand(time(NULL));

	for (size_t i = 0; i < 10; i++)
	{
		int a = rand() % 20 + 1;
		s->addNumber(a);
		std::cout << "Added value : " << a << " in Span." << std::endl;
	}
	unsigned int ss;
	ss = s->shortestSpan();
	std::cout << "Shortest span	: " << ss << std::endl;
	ss = s->longestSpan();
	std::cout << "longest span	: " << ss << std::endl;

	delete (s);
}
