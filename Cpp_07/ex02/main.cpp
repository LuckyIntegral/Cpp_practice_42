/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:19:40 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/15 14:50:56 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Array.hpp"
#include "Point.hpp"

inline static void	print( int &i ) {std::cout << i << " ";}
inline static void	print( Point &i ) {std::cout << i << " ";}

int	main( void ) {
	std::cout << "\nTest 1: non const int array" << std::endl;
	{
		Array<int>	arr(10);

		std::cout << "Array:" << std::endl;
		forEach(arr, print);
		std::cout << std::endl;

		for (unsigned int i = 0; i < arr.size(); ++i)
			arr[i] = (42 + i * 37) % 17;

		std::cout << "Array:" << std::endl;
		forEach(arr, print);
		std::cout << std::endl;

		try {
			int temp = arr[1u << 31];
			std::cout << "OK, temp = " << temp << std::endl;
		} catch ( std::exception &e ) {
			std::cerr << "KO, " <<  e.what() << std::endl;
		}
	}
	std::cout << "\nTest 2: const int array" << std::endl;
	{
		const Array<int>	arr(20);

		std::cout << "Array of size '" << arr.size() << "': "<< std::endl;
		forEach(arr, print);
		std::cout << std::endl;
	}
	std::cout << "\nTest 3: non const Point array" << std::endl;
	{
		Array<Point>	arr(5);

		std::cout << "Array of size '" << arr.size() << "': "<< std::endl;
		forEach(arr, print);
		std::cout << std::endl;

		for (unsigned int i = 1; i <= arr.size(); ++i)
			arr[i - 1] = Point(i * 37 % 13, i * 29 % 16, i * 17 % 7);

		std::cout << "Array of size '" << arr.size() << "': "<< std::endl;
		forEach(arr, print);
		std::cout << std::endl;

		try {
			Point &temp = arr[1u << 31];
			std::cout << "OK, temp = " << temp << std::endl;
		} catch ( std::exception &e ) {
			std::cerr << "KO, " <<  e.what() << std::endl;
		}
	}

	return (0);
}
