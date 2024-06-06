/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:51:01 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/07 00:51:02 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class CouldntFindNumber : public std::exception
{
	public: 
        const char* what(void) const throw()
		{
			return "Error : Could find input value in array !";
		}
};

template <typename T>typename T::iterator easyfind(T& array, int toFind)
{
	typename T::iterator it;
	it = std::find(array.begin(), array.end(), toFind);
	if (it == array.end())
		throw CouldntFindNumber();
	return (it);
}