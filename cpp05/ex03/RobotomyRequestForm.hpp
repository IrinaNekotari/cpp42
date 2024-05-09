/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:53:38 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/29 00:53:39 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm(const std::string& name);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& p);
    const RobotomyRequestForm& operator=(const RobotomyRequestForm& p);
    void        action(const Bureaucrat & executor) const;
};

