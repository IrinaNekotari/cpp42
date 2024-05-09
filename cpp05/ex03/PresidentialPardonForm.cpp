/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:53:58 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/29 00:54:00 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
        : AForm("Presidential Pardon", target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() 
{
    std::cout << "PresidentialPardonForm " << this->getName() << " destroyed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p)
        : AForm(p.getName(), p.getTarget(), p.getToSign(), p.getToExec())
{
    *this = p;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p)
{
    (void)p;
    return (*this);
}

void        PresidentialPardonForm::action(const Bureaucrat & executor) const
{
    (void)executor;
    std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}