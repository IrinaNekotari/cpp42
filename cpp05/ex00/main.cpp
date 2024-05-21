/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:45:15 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/28 00:45:20 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat *a = new Bureaucrat("Chris", 999);
        std::cout << *a << std::endl;
        delete (a);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat *a = new Bureaucrat("Wesker", 0);
        std::cout << *a << std::endl;
        delete (a);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat *a = new Bureaucrat("Jill", 12);
        std::cout << *a << std::endl;
        a->rankDown();
        std::cout << *a << std::endl;
        a->rankUp();
        std::cout << *a << std::endl;
        a->rankUp();
        std::cout << *a << std::endl;
        delete (a);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat *a = new Bureaucrat("Ada", 1);
    try
    {
        std::cout << *a << std::endl;
        a->rankUp();
        std::cout << *a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete (a);

    a = new Bureaucrat("Leon", 150);
    try
    {
        std::cout << *a << std::endl;
        a->rankDown();
        std::cout << *a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete (a);
    
    return 0;
}
