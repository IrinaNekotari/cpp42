/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:53:18 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/29 00:53:20 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm(const std::string& name);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& p);
    const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& p);
    void        action(const Bureaucrat & executor) const;
};
