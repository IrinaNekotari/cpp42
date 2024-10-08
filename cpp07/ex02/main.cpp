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
	std::cout << "###LE TRUC###" << std::endl;
	int * a = new int();
	std::cout << a << std::endl;
	delete a;
	std::cout << "###CREATION###" << std::endl;
	Array<char> test(7);
	test[0] = 'B';
	test[1] = 'o';
	test[2] = 'n';
	test[3] = 'j';
	test[4] = 'o';
	test[5] = 'u';
	test[6] = 'r';

	std::cout << "###TEST INDEX -1###" << std::endl;
	try
	{
		test[-1] = 'W';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "###TEST INDEX 42###" << std::endl;
	try
	{
		test[42] = 'W';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "###TEST IMPRESSION###" << std::endl;
	for (int i = 0; i < test.size(); i++)
	{
		std::cout << test[i];
	}
	std::cout << std::endl;
	std::cout << "###TEST MODIFICATION 1###" << std::endl;
	try
	{
		test[1] = 'W';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "###TEST IMPRESSION POST MODIFICATION 1###" << std::endl;
	for (int i = 0; i < test.size(); i++)
	{
		std::cout << test[i];
	}
	std::cout << std::endl;
	
	std::cout << std::endl << std::endl << "###TEST MEGA ARRAY###" << std::endl;
	Array<std::string> test2(5);
	test2[0] = "Salutations ";
	test2[1] = "j'être ";
	test2[2] = "la ";
	test2[3] = "révélation";
	test2[4] = " !!!!!!!!!!!";
	
	std::cout << "###TEST INDEX -8###" << std::endl;
	try
	{
		test2[-8] = "Ay";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "###TEST INDEX 42###" << std::endl;
	try
	{
		test2[42] = "Uwu";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "###TEST IMPRESSION###" << std::endl;
	for (int i = 0; i < test2.size(); i++)
	{
		std::cout << test2[i];
	}
	std::cout << std::endl;
	
	std::cout << "###TEST MODIFICATION 3###" << std::endl;
	try
	{
		test2[3] = "Puissance du pouvoir de la puissance";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "###TEST IMPRESSION POST MODIFICATION 3###" << std::endl;
	for (int i = 0; i < test2.size(); i++)
	{
		std::cout << test2[i];
	}
	std::cout << std::endl;
	
	Array<char> test3;
	
	return (0);
}
