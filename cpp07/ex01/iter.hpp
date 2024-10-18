/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:22:57 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/02 01:22:59 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T> void iter(T* t, int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
		f(t[i]);
}

template<typename T> void iter(T* t, int len, void (*f)(const T&))
{
	for (int i = 0; i < len; i++)
		f(t[i]);
}
