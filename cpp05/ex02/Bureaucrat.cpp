/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:45:48 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/28 00:45:51 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int rank) : name(name), grade(rank)
{
    if (rank > MAX_RANK)
        throw Bureaucrat::GradeTooLowException();
    if (rank < MIN_RANK)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Bureaucrat " << this->name << " created with rank " << this->grade << std::endl;
}

Bureaucrat::~Bureaucrat() {std::cout << "Bureaucrat " << this->name << " destructed" << std::endl;}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.name)
{
    *this = b;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
    this->grade = b.grade;
    return (*this);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

const std::string&   Bureaucrat::getName() const
{
    return (this->name);
}

void    Bureaucrat::rankDown()
{
    if (this->grade >= MAX_RANK)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void    Bureaucrat::rankUp()
{
    if (this->grade <= MIN_RANK)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void    Bureaucrat::executeForm(AForm const & form) const
{
    if (this->grade > form.getToExec())
    {
        std::cout << this->name << " couldn't execute the form \"" << form.getName() << "\" because he had a too low grade !" << std::endl;
        throw AForm::GradeTooLowException();
    }
    std::cout << this->name << " executed the form \"" << form.getName() << "\"." << std::endl;
    form.execute(*this);
}

void    Bureaucrat::signForm(AForm * f) const
{
    if (this->grade > f->getToSign())
    {
        std::cout << this->name << " couldn't sign the form \"" << f->getName() << "\" because he had a too low grade !" << std::endl;
        throw AForm::GradeTooLowException();
    }
    std::cout << this->name << " signed the form \"" << f->getName() << "\"." << std::endl;
}

/**
 * Définition des classes d'exceptions
*/
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exception: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exception: grade too low";
}


/**
 * Surchage du <<
*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance) {
	os << instance.getName() << ", bureaucrat of grade " << instance.getGrade();
	return (os);
}