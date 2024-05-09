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

#include "Form.hpp"

Form::Form(const std::string &name, int toSign, int toExec) : name(name), toSign(toSign), toExec(toExec)
{
    if (toSign > MAX_RANK || toExec > MAX_RANK)
        throw GradeTooLowException();
    if (toSign < MIN_RANK || toExec < MIN_RANK)
        throw GradeTooHighException();
    this->isSigned = false;
    std::cout << "Form " << name << " created." << std::endl;
}

Form::~Form() {std::cout << "Form " << name << " destroyed." << std::endl;}

Form& Form::operator=(const Form& f)
{
    (void)f;
    return (*this);
}

Form::Form(const Form& f) : name(f.name), isSigned(f.isSigned), toSign(f.toSign), toExec(f.toExec) {}

const std::string& Form::getName() const
{
    return (this->name);
}

bool    Form::getSigned() const
{
    return (this->isSigned);
}

int   Form::getToSign() const
{
    return (this->toSign);
}

int   Form::getToExec() const
{
    return (this->toExec);
}

void        Form::beSigned(const Bureaucrat& b)
{
    try
    {
        b.signForm(this);
        this->isSigned = true;
    }
    catch(const std::exception& e){}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form Exception: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form Exception: grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& instance) {
	os << "Form " << instance.getName()
		<< ", signed : " << instance.getSigned()
		<< ", sign grade : " << instance.getToSign()
		<< ", execute grade : " << instance.getToExec();
	return (os);
}