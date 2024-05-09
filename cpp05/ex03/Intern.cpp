/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 02:00:54 by nmascrie          #+#    #+#             */
/*   Updated: 2024/05/09 02:00:55 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "A nameless, faceless intern was created." << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern-kun has ceased to exist. What a tragedy." << std::endl;
}

Intern::Intern(const Intern & i)
{
    (*this) = i;
}

const Intern & Intern::operator=(const Intern & i)
{
    (void)i;
    return (*this);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    AForm *a = NULL;
    t_forms tab[] = {
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)}
	};
    for (size_t i = 0; i < 3; i++)
    {
        if (form == tab[i].target)
            a = tab[i].form;
        else 
            delete (tab[i].form);
    }
    if (!a)
    {
        std::cout << "Intern-kun couldn't create the form : " << form << " because it doesn't exist !" << std::endl;
        throw UnknownFormException();
    }
    return (a);
}

/**
 * Définition des classes d'exceptions
*/
const char* Intern::UnknownFormException::what() const throw() {
	return "Exception: unknown form";
}