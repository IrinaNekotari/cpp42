/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:16:23 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/02 01:16:25 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

template<typename T> void swap(T &a, T&b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>const T& min(const T &a, const T &b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

template<typename T>const T& max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}