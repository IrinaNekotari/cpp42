/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:15:48 by nmascrie          #+#    #+#             */
/*   Updated: 2023/12/19 14:15:52 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

static int valid(std::string a)
{
    int     i;

    i = 0;
    while (a[i])
    {
        if (a[i] == ' ')
        {
            i++;
            continue ;
        }
        else if (a[i] > '9' || a[i] < '0')
            return (0);
        i++;
    }
    return (1);
}

void    add(PhoneBook *phone)
{
    std::string	data[5];
    std::string	input;

    std::cout << "Please input your CONTACT INFORMATIONS." << std::endl;
    std::cout << "First name     : ";
    std::getline(std::cin, data[0]);
    std::cout << "Last name      : ";
    std::getline(std::cin, data[1]);
    std::cout << "Nickname       : ";
    std::getline(std::cin, data[2]);
    do
    {
        std::cout << "Phone number   : ";
        std::getline(std::cin, data[3]);
        if (valid(data[3]))
            break ;
        std::cout << "Please input a VALID phone number." << std::endl;
    } while (!valid(data[3]));
    std::cout << "Darkest Secret : ";
    std::getline(std::cin, data[4]);
    (*phone).add_contact(data);
    std::cout << "CONGRATULATION ! You added a CONTACT." << std::endl;
}

void    search(PhoneBook phone, std::string *input)
{
	int     index;
    
	phone.get_all_contacts();
	std::cout << "Please input a valid INDEX." << std::endl;
	std::cin >> index;
	if (std::cin.fail() || index < 0 || index >= phone.get_size())
	{
		std::cout << "Invalid Index!\n" << std::endl;
		std::cin.clear();
		std::getline(std::cin, *input);
	    	return ;
	}
	phone.get_contact(index);
	std::cin.clear();
	std::getline(std::cin, *input);
}

int main(void)
{
    PhoneBook	phonebook;
	std::string	input;

    std::cout << "WELCOME TO THE YELLOW PAGES" << std::endl;
    while (1)
    {
        std::cout << "Input ADD to add a CONTACT." << std::endl;
        std::cout << "Input SEARCH to search for a CONTACT." << std::endl;
        std::cout << "Input EXIT to exit the YELLOW PAGES." << std::endl;
        std::getline(std::cin, input);
        if (input == "ADD")
            add(&phonebook);
        else if (input == "SEARCH")
            search(phonebook, &input);
        else if (input == "EXIT")
            break ;
        else
            std::cout << "Please input a VALID command." << std::endl;
    }
    
}
