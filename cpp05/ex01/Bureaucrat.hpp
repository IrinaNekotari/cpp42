/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:45:30 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/28 00:45:39 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

# define MAX_RANK 150
# define MIN_RANK 1

class Form;

class Bureaucrat
{
private:
    Bureaucrat();
    const std::string   name;
    int     grade;
public:
    Bureaucrat(const std::string& name, int rank);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& b);
    Bureaucrat& operator=(const Bureaucrat& b);
    int getGrade() const;
    const std::string& getName() const;
    void    rankUp();
    void    rankDown();
    void    signForm(Form *f) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance);