/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:45:15 by nmascrie          #+#    #+#             */
/*   Updated: 2024/04/28 00:45:20 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(void)
{
    Bureaucrat *a = new Bureaucrat("Ada", 20);
    Bureaucrat *l = new Bureaucrat("Barry Burton", 130);
    Bureaucrat *w = new Bureaucrat("Wesker", 1);
    std::cout << *a << std::endl;
    std::cout << *l << std::endl;
    std::cout << *w << std::endl;
    try
    {
        Form *f = new Form("bug", 128, 352);
        delete (f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    Form *f = new Form("STARS-03", 50, 50);
    std::cout << *f << std::endl;
    f->beSigned(*l);
    std::cout << *f << std::endl;
    f->beSigned(*w);
    std::cout << *f << std::endl;
    delete (f);
    
    delete (a);
    delete (l);
    delete (w);
    return 0;
}
