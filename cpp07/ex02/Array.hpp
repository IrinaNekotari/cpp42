/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:39:54 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/02 01:39:55 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <cstddef>
# include <exception>

template <typename T> class Array
{
	private:
		T* val;
		int len;
	public:
		Array() : val(NULL), len(0) {};
		~Array() 
		{
			delete[] this->val;
		};
		Array(unsigned int size) : val(new T[size]), len(size) {};
		Array(const Array & a);
		Array & operator=(const Array & a)
		{
			*this = a;
		};
		T& operator[](int i)
		{
			if (i >= this->len || i < 0)
				throw Array<T>::InvalidIndexException();
			else
				return this->val[i];
		};
		const T& operator[](int i) const
		{
			if (i >= this->len || i < 0)
				throw Array<T>::InvalidIndexException();
			else
				return this->val[i];
		};
		int	size() const
		{
			return (this->len);
		};

		class InvalidIndexException : public std::exception
		{
			public: 
				const char* what(void) const throw()
				{
					return "Invalid index";
				};
		};

};
