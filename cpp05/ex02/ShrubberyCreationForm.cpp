/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:53:23 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/29 00:53:24 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
        : AForm("Shrubbery Creation", target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &p)
        : AForm(p.getName(), p.getTarget(), p.getToSign(), p.getToExec())
{
    *this = p;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& p)
{
    (void)p;
    return (*this);
}

void        ShrubberyCreationForm::action(const Bureaucrat & executor) const
{
    std::ofstream out;

	out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);

    out << "This is a shrubbery !" << std::endl;
    out << std::endl;

    out << "                                                         ." << std::endl;
    out << "                                              .         ;" << std::endl;
    out << "                 .              .              ;%     ;; " << std::endl;
    out << "                   ,           ,                :;\%  %; " << std::endl;
    out << "                    :         ;                   :;%;'     ., " << std::endl;
    out << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    out << "             ;       ;%;  %\%;        ,     %;    ;%;    ,%'" << std::endl;
    out << "              %;       %\;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
    out << "               ;%;      %;        ;%;        %\ ;%;  ,%;'" << std::endl;
    out << "                `%;.     ;%;     %;'         `;%\%;.%;'" << std::endl;
    out << "                 `:;%.    ;%\%. %@;        %; ;@%\;%'" << std::endl;
    out << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    out << "                      `@%:.  :;%.         ;@@%;' " << std::endl;
    out << "                        `@%.  `;@%.      ;@@%; " << std::endl;
    out << "                          `@%\%. `@%\%    ;@@%; " << std::endl;
    out << "                            ;@%. :@%\%  %@@%; " << std::endl;
    out << "                              %@bd%\%%bd%\%:;  " << std::endl;
    out << "                                #@%\%%\%%:;;" << std::endl;
    out << "                                %@@%\%%::;" << std::endl;
    out << "                                %@@@%(o);  . ' " << std::endl;
    out << "                                %@@@o%;:(.,' " << std::endl;
    out << "                            `.. %@@@o%::; " << std::endl;
    out << "                               `)@@@o%::;  " << std::endl;
    out << "                                %@@(o)::; " << std::endl;
    out << "                               .%@@@@%::; " << std::endl;
    out << "                               ;%@@@@%::;.   " << std::endl;
    out << "                              ;%@@@@\%\%:;;;. " << std::endl;
    out << "                          ...;%@@@@@\%\%:;;;;,.. " << std::endl;
}
