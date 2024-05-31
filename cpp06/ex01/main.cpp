/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:57:05 by nmascrie          #+#    #+#             */
/*   Updated: 2024/06/01 00:57:06 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data* data;
	uintptr_t rawData;
	Data* retData;

	data = new Data;
	data->n = 98;
	data->s = "Coucou";

	std::cout << "Data		 : " << data << "(" << data->n << ", " << data->s << ")" << std::endl;
	rawData = Serializer::serialize(data);
	std::cout << "Raw data	 : " << rawData << std::endl;
	retData = Serializer::deserialize(rawData);
	std::cout << "Deserialized data: " << retData << "(" << retData->n << ", " << retData->s << ")" << std::endl;

	delete data;

	return 0;
}
