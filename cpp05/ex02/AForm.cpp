/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:25:04 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/28 01:25:07 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, const std::string& target, int toSign, int toExec)
    : name(name), target(target), toSign(toSign), toExec(toExec)
{
    if (toSign > MAX_RANK || toExec > MAX_RANK)
        throw GradeTooLowException();
    if (toSign < MIN_RANK || toExec < MIN_RANK)
        throw GradeTooHighException();
    this->isSigned = false;
    std::cout << "Form " << name << " created." << std::endl;
}

AForm::~AForm() {std::cout << "Form " << name << " destroyed." << std::endl;}

AForm& AForm::operator=(const AForm& f)
{
    (void)f;
    return (*this);
}

AForm::AForm(const AForm& f) : name(f.name), isSigned(f.isSigned), toSign(f.toSign), toExec(f.toExec) {}

const std::string& AForm::getName() const
{
    return (this->name);
}

const std::string& AForm::getTarget() const
{
    return (this->target);
}


bool    AForm::getSigned() const
{
    return (this->isSigned);
}

int   AForm::getToSign() const
{
    return (this->toSign);
}

int   AForm::getToExec() const
{
    return (this->toExec);
}

void        AForm::action(const Bureaucrat & executor) const {}

void        AForm::execute(const Bureaucrat & executor) const 
{
        if (this->isSigned == false)
            throw FormUsignedException();
        this->action(executor); 
}

void        AForm::beSigned(const Bureaucrat& b)
{
    try
    {
        b.signForm(this);
        this->isSigned = true;
    }
    catch(const std::exception& e){}
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form Exception: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form Exception: grade too low";
}

const char* AForm::FormUsignedException::what() const throw() {
	return "Form Exception: form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& instance) {
	os << "Form " << instance.getName()
		<< ", signed : " << instance.getSigned()
		<< ", sign grade : " << instance.getToSign()
		<< ", execute grade : " << instance.getToExec()
		<< std::endl;
	return (os);
}