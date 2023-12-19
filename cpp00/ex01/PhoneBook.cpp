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

void    print_truc(std::string s)
{
    int     len;
    int     i;

    len = s.length();
    i = 0;
    if (len > 10)
    {
        std::cout << s.substr(0, 9);
	std::cout << ".";
    }
    else
    {
        while (i < 10 - len)
        {
            std::cout << " ";
            i++;
        }
        std::cout << s;
    }
}

void    PhoneBook::get_contact(int i) const
{
    std::cout << "Index selected = " << i << std::endl;
    std::cout << "First name     = " << this->contacts[i].get_firstname() << std::endl;
    std::cout << "Last name      = " << this->contacts[i].get_lastname() << std::endl;
    std::cout << "Nickname       = " << this->contacts[i].get_nickname() << std::endl;
    std::cout << "Phone Number   = " << this->contacts[i].get_number() << std::endl;
    std::cout << "Darkest secret = " << this->contacts[i].get_secret() << std::endl;
}

void    PhoneBook::add_contact(std::string data[5])
{
    int     index;

    index = this->index;
    this->contacts[index].set_firstname(data[0]);
    this->contacts[index].set_lastname(data[1]);
    this->contacts[index].set_nickname(data[2]);
    this->contacts[index].set_number(data[3]);
    this->contacts[index].set_secret(data[4]);
    this->index = (index + 1) % 8;
	if (this->size < 8)
		this->size++;
}

void    PhoneBook::get_all_contacts(void) const
{
    int     i;

    i = 0;
    std::cout << "+----------|----------|----------|----------+" << std::endl;
    std::cout << "+     index|first name| last name|  nickname+" << std::endl;
    std::cout << "+----------|----------|----------|----------+" << std::endl;
    while (i < this->size)
    {
        std::cout << "|         " << i << "|";
        print_truc(this->contacts[i].get_firstname());
        std::cout << "|";
        print_truc(this->contacts[i].get_lastname());
        std::cout << "|";
        print_truc(this->contacts[i].get_nickname());
        std::cout << "|" << std::endl;
        i++;
    }
    std::cout << "+----------+----------+----------+----------+" << std::endl;
}
