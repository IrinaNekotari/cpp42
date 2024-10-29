/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:49:57 by nmascrie          #+#    #+#             */
/*   Updated: 2024/10/29 07:50:00 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Needs one argument !" << std::endl;
        return (1);
    }
    BitcoinExchange b("data.csv");
    b.calculate(argv[1]);
    return (0);
}

