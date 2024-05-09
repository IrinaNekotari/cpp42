/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:24:53 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/28 01:24:55 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class AForm
{
private:
    AForm();
    const std::string   name;
    const std::string   target;
    bool    isSigned;
    const int   toSign;
    const int   toExec;
public:
    AForm(const std::string& name, const std::string& target, int toSign, int toExec);
    virtual ~AForm();
    AForm(const AForm& f);
    AForm& operator=(const AForm& f);
    const std::string&  getName() const;
    const std::string&  getTarget() const;
    bool                getSigned() const;
    int                 getToSign() const;
    int                 getToExec() const;
    void                beSigned(const Bureaucrat &b);
    void                execute(const Bureaucrat & executor) const;
    virtual void        action(const Bureaucrat & executor) const;

    /**
     * CLASSES D'EXCEPTIONS
    */
    class GradeTooHighException : public std::exception
    {
	    public: 
            const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception
    {
		public: 
            const char* what(void) const throw();
	};
    class FormUsignedException : public std::exception
    {
		public: 
            const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& instance);