/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:07:56 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/12 15:09:21 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "easyfind.hpp"

static inline void	print( int i ) { std::cout << i << " "; }

int	main( void ) {
	{
		std::cout << "Non const vector<int> test" << std::endl;
		std::vector<int> vi;

		for (int i = 0; i < 10; ++i)
			vi.push_back(i);

		std::cout << "Array:" << std::endl;
		for_each(vi.begin(), vi.end(), print); std::cout << std::endl;

		std::cout << "\nTry to find each element of array" << std::endl;
		try {
			for (std::vector<int>::iterator it = vi.begin(); it != vi.end(); ++it)
				std::cout << "Value = " << *easyfind(vi, *it) << " exists" << std::endl;
		} catch ( std::invalid_argument &e ) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\nTry to find element that doesnt exist" << std::endl;
		try {
			std::cout << "Value = " << *easyfind(vi, 42) << std::endl;
		} catch ( std::invalid_argument &e ) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\nConst vector<int> test" << std::endl;
		std::vector<int> temp;

		for (int i = 0; i < 10; ++i)
			temp.push_back(i);

		const std::vector<int> vi(temp);

		std::cout << "Array:" << std::endl;
		for_each(vi.begin(), vi.end(), print); std::cout << std::endl;

		std::cout << "\nTry to find each element of array" << std::endl;
		try {
			for (std::vector<int>::const_iterator it = vi.begin(); it != vi.end(); ++it)
				std::cout << "Value = " << *easyfind(vi, *it) << " exists" << std::endl;
		} catch ( std::invalid_argument &e ) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\nTry to find element that doesnt exist" << std::endl;
		try {
			std::cout << "Value = " << *easyfind(vi, 42) << std::endl;
		} catch ( std::invalid_argument &e ) {
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
