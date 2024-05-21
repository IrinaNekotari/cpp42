/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:59:41 by nmascrie          #+#    #+#             */
/*   Updated: 2023/12/19 13:59:42 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

void    upper(char *s[])
{
    int i;

    i = 0;
    while((*s)[i])
    {
        if ((*s)[i] >= 'a' && ((*s)[i]) <= 'z')
            (*s)[i] -= 'a' - 'A';
        i++;
    }
}

int main(int args, char *argv[])
{
    int i;

    i = 1;
    (void)argv;
    if (args == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else 
    {
        while (argv[i])
        {
            upper(&argv[i]);
            std::cout << argv[i];
            if (i + 1 < args)
                std::cout << " ";
            i++;
        }
        std::cout << std::endl;
    }
}