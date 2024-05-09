/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 02:00:47 by nmascrie          #+#    #+#             */
/*   Updated: 2024/05/09 02:00:49 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern& i);
    const Intern & operator=(const Intern& i);
    AForm *makeForm(std::string form, std::string target);
    /**
     * CLASSES D'EXCEPTIONS
    */
    class UnknownFormException : public std::exception
    {
	    public: 
            const char* what(void) const throw();
	};
};

typedef struct s_forms {
	std::string     target;
	AForm           *form;
}   t_forms;