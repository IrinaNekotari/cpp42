/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:15:31 by nmascrie          #+#    #+#             */
/*   Updated: 2023/12/19 14:15:32 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact {
    private:
	    std::string	first_name;
	    std::string	last_name;
	    std::string	phone_number;
	    std::string	nickname;
	    std::string	darkest_secret;
    public:
	    const std::string&	get_firstname(void) const;
        const std::string&	get_lastname(void) const;
        const std::string&	get_nickname(void) const;
        const std::string&	get_secret(void) const;
        const std::string&	get_number(void) const;
        void				set_firstname(std::string first);
        void				set_lastname(std::string last);
        void				set_nickname(std::string nick);
        void				set_secret(std::string secret);
        void				set_number(std::string number);
};
