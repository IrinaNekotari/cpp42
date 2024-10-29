/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:07:01 by nmascrie          #+#    #+#             */
/*   Updated: 2024/10/29 10:07:02 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Needs 2 arguments !" << std::endl;
        return (1);
    }
    PMergeMe p;
    p.init_deque(argv);
    p.init_vector(argv);
    p.print_all();
    return 0;
}

