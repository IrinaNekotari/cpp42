/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:06:39 by nmascrie          #+#    #+#             */
/*   Updated: 2024/10/29 10:06:40 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <algorithm>
# include <sstream>
# include <time.h>

class PMergeMe
{
private:
    std::vector<int>    vec;
    std::deque<int>     deq;

    clock_t         start, end;
    double          time_vec, time_deq;
public:
    PMergeMe();
    ~PMergeMe();
    PMergeMe(const PMergeMe & p);
    PMergeMe & operator=(const PMergeMe & p);

    bool    check_duplicate();
    bool    is_sorted();

    void    init_vector(char **args);
    void    sort_vector();

    void    init_deque(char **args);
    void    sort_deque();

    void    print_all();
};

typedef struct s_tuple
{
    int a;
    int b;
}   t_tuple;
