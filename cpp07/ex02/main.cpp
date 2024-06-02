/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:39:40 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/02 01:39:43 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Array<char> test(7);
	test[0] = 'B';
	test[1] = 'o';
	test[2] = 'n';
	test[3] = 'j';
	test[4] = 'o';
	test[5] = 'u';
	test[6] = 'r';

	try
	{
		test[-1] = 'W';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		test[48] = 'W';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	for (int i = 0; i < test.size(); i++)
	{
		std::cout << test[i];
	}
	std::cout << std::endl;

	Array<std::string> test2(5);
	test2[0] = "Salutations ";
	test2[1] = "j'être ";
	test2[2] = "la ";
	test2[3] = "révélation";
	test2[4] = " !!!!!!!!!!!";

	for (int i = 0; i < test2.size(); i++)
	{
		std::cout << test2[i];
	}
	std::cout << std::endl;
	
	return (0);
}
