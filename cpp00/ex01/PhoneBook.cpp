/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:15:38 by nmascrie          #+#    #+#             */
/*   Updated: 2023/12/19 14:15:39 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int   PhoneBook::get_size(void) const
{
    return (this->size);
}

void   PhoneBook::get_contact(int i) const
{
    std::cout << "First name     = " << this->contacts[i].get_firstname() << std::endl;
    std::cout << "Last name      = " << this->contacts[i].get_firstname() << std::endl;
    std::cout << "Nickname       = " << this->contacts[i].get_firstname() << std::endl;
    std::cout << "Phone Number   = " << this->contacts[i].get_firstname() << std::endl;
    std::cout << "Darkest secret = " << this->contacts[i].get_firstname() << std::endl;
}