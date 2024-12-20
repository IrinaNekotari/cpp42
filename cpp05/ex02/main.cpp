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

# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

int main(void)
{
    Bureaucrat *a = new Bureaucrat("Ada", 30);
    Bureaucrat *l = new Bureaucrat("Barry Burton", 130);
    Bureaucrat *w = new Bureaucrat("Wesker", 1);
    std::cout << *a << std::endl;
    std::cout << *l << std::endl;
    std::cout << *w << std::endl;
    AForm *f1 = new RobotomyRequestForm("Ethan");
    AForm *f2 = new PresidentialPardonForm("Leon");
    AForm *f3 = new ShrubberyCreationForm("Raccoon City");
    std::cout << *f1 << std::endl;
    std::cout << *f2 << std::endl;
    std::cout << *f3 << std::endl;

    try
    {
        f1->beSigned(*l);
    }
    catch(const std::exception& e) {}
    try
    {
        f1->beSigned(*a);
        f3->beSigned(*a);
        f2->beSigned(*a);
    }
    catch(const std::exception& e) {}
    try
    {
        f3->execute(*l);
        l->executeForm(*f3);
        f2->execute(*l);
        l->executeForm(*f2);
    }
    catch(const std::exception& e) {}
    f2->beSigned(*w);
    w->executeForm(*f1);
    f2->execute(*w);
    f3->execute(*w);
    
    delete (f1);
    delete (f2);
    delete (f3);

    delete (a);
    delete (l);
    delete (w);
    return 0;
}
