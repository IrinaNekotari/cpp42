/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:15:43 by nmascrie          #+#    #+#             */
/*   Updated: 2023/12/19 14:15:44 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    private:
        Contact contacts[8];
        int     size;
        int     index;
    public:
        PhoneBook() : size(0), index(0) {}
        int     get_size(void) const;
        void	add_contact(std::string data[5]);
	void	get_contact(int i) const;
	void	get_all_contacts(void) const;
};
