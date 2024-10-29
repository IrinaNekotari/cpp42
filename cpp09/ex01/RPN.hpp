/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:25:42 by nmascrie          #+#    #+#             */
/*   Updated: 2024/10/29 09:25:43 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stack>
# include <algorithm>
# include <sstream>
# include <string>

class RPN
{
private:
    RPN();
    std::stack<int>     _stack;
    bool                failed;
public:
    RPN(std::string s);
    ~RPN();
    RPN(const RPN & r);
    RPN & operator=(const RPN & r);
    void    calculate();
};