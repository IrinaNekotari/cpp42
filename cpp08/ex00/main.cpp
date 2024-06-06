/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:50:41 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/07 00:50:49 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::vector<int>::iterator it;
	srand (time(NULL));

	int amount = rand() % 11 + 10;;
	for (int i = 0; i < amount; ++i) {
		v.push_back((rand() % 10 + 1) * (rand() % 10 + 1));
	}

	std::cout << "-------------------- ARRAY VECTOR --------------------" << std::endl;
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		std::cout << *i << std::endl;
	}
	std::cout << "-------------------- END OF VECTOR --------------------" << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		try
		{
			int value = rand() % 100 + 1;
			std::cout << "Searching for " << value << " ..." << std::endl;
			it = easyfind(v, value);
			std::cout << "Found " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
