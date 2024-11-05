/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:07:01 by nmascrie          #+#    #+#             */
/*   Updated: 2024/10/29 10:07:02 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

bool    only_numbers(int argc, char *argv[])
{
    std::string buffer;

    for (int i = 1; i < argc; i++)
    {
        buffer = argv[i];
        if (buffer.find_first_not_of("0123456789") != std::string::npos)
            return (false);
    }
    return (true);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Needs 2 arguments !" << std::endl;
        return (1);
    }
    if (!only_numbers(argc, argv))
    {
        std::cout << "The program needs only numbers !" << std::endl;
        return (1);
    }
    PMergeMe p;
    p.init_deque(argv);
    p.init_vector(argv);
    if (p.check_duplicate())
    {
        std::cout << "Error : Duplicate found !" << std::endl;
        return (1);
    }
    p.print_all();
    if (p.is_sorted())
        std::cout << "Check completed, list is sorted" << std::endl;
    else 
    {
        std::cout << "Check completed, list is sorted" << std::endl;
        return (1);
    }
    return (0);
}

