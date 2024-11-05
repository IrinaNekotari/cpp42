/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:50:26 by nmascrie          #+#    #+#             */
/*   Updated: 2024/10/29 07:50:28 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::ifstream   file_open;
    std::string     buffer;
    std::string     value;
    std::string     key;

    file_open.open(file.c_str());
    if (!file_open.is_open())
    {
		std::cerr << "Error 404 : file " << file << " not found" << std::endl;
		return;
	}
    std::getline(file_open, buffer);
    while (std::getline(file_open, buffer))
    {
        key = buffer.substr(0, buffer.find(','));
        value = buffer.substr(buffer.find(',') + 1);
        data[key] = std::atof(value.c_str());
    }
    file_open.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & b)
{
    *this = b;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & b)
{
    this->data = b.data;
    return (*this);
}

void    BitcoinExchange::print() const
{
    std::map<std::string, float>::const_iterator it = data.begin();

    std::cout << "### Dataset begin ###" << std::endl;
    while (it != data.end())
    {
        std::cout << "[" << it->first << "] => " << it->second << std::endl;
        it++;
    }
    std::cout << "### Dataset end ###" << std::endl;
}

float   BitcoinExchange::search(std::string date) const
{
    std::map<std::string, float>::const_iterator it = data.find(date);
    std::map<std::string, float>::const_iterator it2;

    if (it == data.end())
    {
        it2 = data.lower_bound(date);
        if (it2 != data.begin())
        {
            it2--;
            return (it2->second);
        }
        return (-1);
    }
    return (it->second);
}

static bool check_date(std::string date)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string year, month, day;

    if (date[4] != '-' || date[7] != '-')
    {
		std::cerr << "Date format is not YYYY-MM-DD";
		return (false);
	}
    year    = date.substr(0, 4);
    month   = date.substr(5, 2);
    day     = date.substr(8, 2);
    if ((std::atoi(year.c_str()) % 4) == 0 && (((std::atoi(year.c_str()) % 400) == 0 || (std::atoi(year.c_str()) % 100 != 0))))
        days[1] = 29;
    if (year.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cerr << "Error: Year is invalid !";
        return (false);
    }
    if (month.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cerr << "Error: Month is invalid !";
        return (false);
    }
    if (day.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cerr << "Error: Day is invalid !";
        return (false);
    }
    if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
    {
        std::cerr << "Error: Month must be between 1 and 12 !";
        return (false);
    }
    if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > days[std::atoi(month.c_str()) - 1])
    {
        std::cerr << "Error: Day of month " << month << " must be between 1 and " << days[std::atoi(month.c_str()) - 1] << " !";
        return (false);
    }
    return (true);
}

static bool check_value(std::string value)
{
    if (value.length() == 0)
    {
		std::cout << "Error: Value is empty";
		return (false);
	}
	if (value.find_first_not_of("0123456789.-") != std::string::npos)
    {
		std::cout << "Error: Value is not a number";
		return (false);
	}
	if (std::count(value.begin(), value.end(), '.') > 1)
    {
		std::cout << "Error: Value must have only one '.'";
		return (false);
	}
	if (std::count(value.begin(), value.end(), '-') > 1)
    {
		std::cout << "Error: Value must have only one '-'";
		return (false);
	}
	if (value[0] == '.')
    {
		std::cout << "Error: '.' must not be the first character";
		return (false);
	}
	if (value[value.length() - 1] == '.')
    {
		std::cout << "Error: '.' must not be the last character";
		return (false);
	}
	if (std::count(value.begin(), value.end(), '-') == 1)
    {
		if (value[0] != '-')
        {
			std::cout << "Error: '-' must be the first character";
			return (false);
		}
	}
	if (std::atol(value.c_str()) < 0)
    {
		std::cout << "Error: not a positive number";
		return (false);
	}
    if (std::atol(value.c_str()) > 1000)
    {
		std::cout << "Error: too large a number";
		return (false);
	}
	return (true);
}

void   BitcoinExchange::calculate(std::string file) const
{
    std::ifstream   file_open;
    std::string     buffer;
    std::string     date;
    std::string     value;
    float           calcul;

    file_open.open(file.c_str());
    if (!file_open.is_open())
    {
        std::cerr << "Error 404 : file " << file << " not found" << std::endl;
        return ;
    }
    std::getline(file_open, buffer);
    while (std::getline(file_open, buffer))
    {
        if (buffer.find('|') == std::string::npos)
        {
            std::cout << "Error: bad input => " << buffer << std::endl;
            continue ;
        }
        buffer.erase(std::remove_if(buffer.begin(), buffer.end(), isspace), buffer.end());
        date = buffer.substr(0, buffer.find('|'));
		value = buffer.substr(buffer.find('|') + 1);
        if (!check_date(date))
        {
            std::cout << " => [" << date << "]"<< std::endl;
            continue ;
        }
        if (!check_value(value))
        {
            std::cout << " => [" << value << "]"<< std::endl;
            continue ;
        }
        calcul = search(date);
        if (calcul == -1)
        {
            std::cout << "Error: no exchange rate found for date [" << date << "]" << std::endl;
            continue ;
        }
        std::cout << date << " => " << value << " = " << calcul * std::atof(value.c_str()) << std::endl;
    }
    file_open.close();
}