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

class Bureaucrat;

class Form
{
private:
    Form();
    const std::string   name;
    bool    isSigned;
    const int   toSign;
    const int   toExec;
public:
    Form(const std::string& name, int toSign, int toExec);
    ~Form();
    Form(const Form& f);
    Form& operator=(const Form& f);
    const std::string&  getName() const;
    bool                getSigned() const;
    int                 getToSign() const;
    int                 getToExec() const;
    void                beSigned(const Bureaucrat &b);

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
};

std::ostream& operator<<(std::ostream& os, const Form& instance);