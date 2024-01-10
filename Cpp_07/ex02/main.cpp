/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:19:40 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/10 22:39:48 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Array.hpp"
#include "Point.hpp"

inline static void	print( int &i ) {std::cout << i << " ";}
inline static void	print( Point &i ) {std::cout << i << " ";}

int	main( void ) {
	std::cout << "Test 1: non const int array" << std::endl;
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
	std::cout << "Test 2: const int array" << std::endl;
	{
		const Array<int>	arr(20);

		std::cout << "Array of size '" << arr.size() << "': "<< std::endl;
		forEach(arr, print);
		std::cout << std::endl;

	}
	std::cout << "Test 3: non const Point array" << std::endl;
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
	std::cout << "Test 4: deep copy test, cso test" << std::endl;
	{
		Array<int>	arr(20);

		for (unsigned int i = 0; i < arr.size(); ++i)
			arr[i] = (42 + i * 37) % 17;

		std::cout << "Array of size '" << arr.size() << "': "<< std::endl;
		forEach(arr, print);
		std::cout << std::endl;

		std::cout << "Copy constructor test:" << std::endl;
		{
			Array<int>	arr2(arr);

			std::cout << "Array of size '" << arr2.size() << "': "<< std::endl;
			forEach(arr2, print);
			std::cout << std::endl;
		}
		std::cout << "Cso test:" << std::endl;
		{
			Array<int>	arr3;

			std::cout << "Array of size '" << arr3.size() << "': "<< std::endl;
			forEach(arr3, print);
			std::cout << std::endl;

			arr3 = arr;

			std::cout << "Array of size '" << arr3.size() << "': "<< std::endl;
			forEach(arr3, print);
			std::cout << std::endl;
		}
	}

	return 0;
}
