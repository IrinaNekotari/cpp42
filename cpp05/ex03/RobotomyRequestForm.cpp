/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:53:43 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/29 00:53:45 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
        : AForm("Robotomy request", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << "RobotomyRequestForm " << this->getName() << " destroyed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &p)
        : AForm(p.getName(), p.getTarget(), p.getToSign(), p.getToExec())
{
    *this = p;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& p)
{
    (void)p;
    return (*this);
}

void        RobotomyRequestForm::action(const Bureaucrat & executor) const
{
    std::srand(std::time(NULL));
    std::cout << "*DRIIIIIIILL*" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << this->getTarget() << " has been robotomized succesfully by " << executor.getName() << std::endl;
	} else
		std::cout << "Failed to robotomize " << this->getTarget() << std::endl;
}
