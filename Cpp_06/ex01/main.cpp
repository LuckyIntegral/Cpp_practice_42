/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:15:25 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/10 13:49:32 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"
#include "Data.hpp"

int	main( void ) {
	{ // for class
		uintptr_t	serializedData;
		Data		*data = new Data();

		std::cout << "Log 1: " << *data << std::endl;
		serializedData = Serializer::serialize(data);
		std::cout << "serializedData:  " << serializedData << std::endl;

		std::cout << std::endl;

		data->setInteger(24);
		data->setDbl(5.6);
		data->setStr("Who are you?");
		std::cout << "Log 2: " << *data << std::endl;

		std::cout << std::endl;

		data = NULL;
		std::cout << "Log 3: " << data << std::endl;

		std::cout << std::endl;

		data = Serializer::deserialize(serializedData);
		std::cout << "Log 4: " << *data << std::endl;

		delete data;
	}
	{ // for structure
		// uintptr_t	serializedData;
		// Data		*data = new Data();

		// data->_integer = (42);
		// data->_dbl = (42.42);
		// data->_str = ("Hello World!");
		// std::cout << "Before: " << data->_dbl << ' ' << data->_integer << ' '
		// 	<< data->_str << std::endl;
		// serializedData = Serializer::serialize(data);
		// std::cout << "serializedData:  " << serializedData << std::endl;
		// data->_integer = (24);
		// data->_dbl = (5.6);
		// data->_str = ("What is this?");
		// std::cout << "Within: " << data->_dbl << ' ' << data->_integer << ' '
		// 	<< data->_str << std::endl;
		// data = Serializer::deserialize(serializedData);
		// std::cout << "After: " << data->_dbl << ' ' << data->_integer << ' '
		// 	<< data->_str << std::endl;

		// delete data;
	}
	return (0);
}
