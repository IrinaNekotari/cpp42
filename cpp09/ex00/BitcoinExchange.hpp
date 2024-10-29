/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:50:41 by nmascrie          #+#    #+#             */
/*   Updated: 2024/10/29 07:50:42 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <fstream>
# include <map>
# include <algorithm>
# include <sstream>
# include <string>

class BitcoinExchange
{
private:
    std::map<std::string, float> data;
    BitcoinExchange();
public:
    BitcoinExchange(std::string file);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange & b);
    BitcoinExchange & operator=(const BitcoinExchange & b);

    void    print() const;
    float   search(std::string date) const;
    void    calculate(std::string file) const;
};

