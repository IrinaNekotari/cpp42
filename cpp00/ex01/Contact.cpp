/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:15:24 by nmascrie          #+#    #+#             */
/*   Updated: 2023/12/19 14:15:25 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

const std::string&	Contact::get_firstname() const
{
	return (this->first_name);
}

const std::string&	Contact::get_lastname() const
{
	return (this->last_name);
}

const std::string&	Contact::get_nickname() const
{
	return (this->nickname);
}

const std::string&	Contact::get_secret() const
{
	return (this->darkest_secret);
}

const std::string&	Contact::get_number() const
{
	return (this->phone_number);
}

void    Contact::set_firstname(std::string first)
{
    this->first_name = first;
}

void    Contact::set_lastname(std::string last)
{
    this->last_name = last;
}

void    Contact::set_nickname(std::string nick)
{
    this->nickname = nick;
}

void    Contact::set_secret(std::string secret)
{
    this->darkest_secret = secret;
}

void    Contact::set_number(std::string number)
{
    this->phone_number = number;
}