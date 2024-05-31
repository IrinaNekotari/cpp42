/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:11:44 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/01 01:11:45 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) 
{
	std::srand(time(NULL));
	int n = rand() % 3;
	if (n == 0)
	{
		std::cout << "A: I have come." << std::endl;
		return (new A);
	}
	else if (n == 1)
	{
		std::cout << "B: I am here." << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "C: Showtime." << std::endl;
		return (new C);
	}
	std::cout << "uh-oh the computer made a FUCKY WUCKY" << std::endl;
	return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) 
		std::cout << "Found A." << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "That's a B." << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Identified a C." << std::endl;
	else 
		std::cout << "How did we even reach that ?" << std::endl;
}

void identify(Base& p) {
	try
	{
		A& trying = dynamic_cast<A&>(p);
		(void)trying;
		std::cout << "Alternative : A is here." << std::endl;
		return;
	}
	catch (const std::exception& e) {}
	try
	{
		B& trying = dynamic_cast<B&>(p);
		(void)trying;
		std::cout << "Alternative : That's a B." << std::endl;
		return;
	}
	catch (const std::exception& e) {}
	try
	{
		C& trying = dynamic_cast<C&>(p);
		(void)trying;
		std::cout << "Alternative : Found a C." << std::endl;
		return;
	}
	catch (const std::exception& e) {}
	std::cout << "Alternative : WTF happened ?" << std::endl;
}

int main(void)
{
	Base *base;

	base = generate();
	identify(base);
	identify(*base);

	delete (base);
	
	return 0;
}