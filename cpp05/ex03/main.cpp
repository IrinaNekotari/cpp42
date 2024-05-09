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
# include "Intern.hpp"

int main(void)
{
    Bureaucrat *w = new Bureaucrat("Albert Wesker", 1);
    Intern *i     = new Intern();
    AForm *f;
    try
    {
        f = i->makeForm("robotomy request", "Ethan Winters");
        f->beSigned(*w);
        w->executeForm(*f);
        delete (f);
    }
    catch(const std::exception& e) {}
    try
    {
        f = i->makeForm("shrubbery creation", "Arklay Forest");
        f->beSigned(*w);
        w->executeForm(*f);
        delete (f);
    }
    catch(const std::exception& e) {}
    try
    {
        f = i->makeForm("presidential pardon", "Leon S. Kennedy");
        f->beSigned(*w);
        w->executeForm(*f);
        delete (f);
    }
    catch(const std::exception& e) {}
    try
    {
        f = i->makeForm("ultima request", "Ethan Winters");
        f->beSigned(*w);
        w->executeForm(*f);
        delete (f);
    }
    catch(const std::exception& e) {}
    
    delete (w);
    delete (i);
    return 0;
}
