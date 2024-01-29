/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:54:22 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/29 20:24:43 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	std::cout << "     TABLE   " << std::endl;
	std::cout << "6|           " << std::endl;
	std::cout << "5|    B      " << std::endl;
	std::cout << "4|      P    " << std::endl;
	std::cout << "3|    V   C  " << std::endl;
	std::cout << "2|           " << std::endl;
	std::cout << "1|A   D      " << std::endl;
	std::cout << "0+-----------" << std::endl;
	std::cout << " 01 2 3 4 5 6" << std::endl;
	std::cout << "Points: A(1;1) B(3;5) C(5;3)" << std::endl;
	{
		Point	a(1, 1), b(3, 5), c(5, 3);
		Point	p(4, 4), d(3, 1), v(3, 3);

		std::cout << "Is P(4;4) inside ? " << (bsp(a, b, c, p) ? "Yes" : "No") << std::endl;
		std::cout << "Is D(3;1) inside ? " << (bsp(a, b, c, d) ? "Yes" : "No") << std::endl;
		std::cout << "Is V(3;3) inside ? " << (bsp(a, b, c, v) ? "Yes" : "No") << std::endl;
	}
	return (0);
}