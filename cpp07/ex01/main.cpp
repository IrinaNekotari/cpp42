/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:22:51 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/02 01:22:53 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>void elprinto(const T& t)
{
	std::cout << t << std::endl;
}

int main(void)
{
	std::string array[] = {"Lorem", "Ipsum", "Dolorem", "Sit", "COUCOU", "Amet"};
	int	tablo[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	iter(array, array->length() + 1, &elprinto);
	iter(tablo, 11, &elprinto);
	return (0);
}

