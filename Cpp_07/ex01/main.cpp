/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:19:40 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/15 14:40:21 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"
#include "iter.hpp"

int	main( void ) {
	{
		const int	arr1[5] = { 0, 1, 2, 3, 4 };
		int			arr2[5] = { 10, 11, 12, 13, 14 };

		print("Array 1:");
		iter(arr1, 5, print);
		print("Array 2:");
		iter(arr2, 5, print);
		print("Array 1:");
		iter(arr2, 5, assign);
		iter(arr2, 5, print);
	}
	std::cout << std::endl;
	{
		const Point	arr1[5] = {
			Point(1, 2, 3),
			Point(1, 2, 3),
			Point(1, 2, 3),
			Point(1, 2, 3),
			Point(1, 2, 3)
		};
		Point		arr2[5] = {
			Point(4, 5, 6),
			Point(4, 5, 6),
			Point(4, 5, 6),
			Point(4, 5, 6),
			Point(4, 5, 6)
		};

		print("Array 1:");
		iter(arr1, 5, print);
		print("Array 2:");
		iter(arr2, 5, print);
		print("Array 1:");
		iter(arr2, 5, assign);
		iter(arr2, 5, print);
	}
	return (0);
}
