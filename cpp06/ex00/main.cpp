/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:16:54 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/01 00:16:55 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int args, char *argv[])
{
	if (args != 2)
		std::cout << "The program needs exactly one argument to work !!!" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}