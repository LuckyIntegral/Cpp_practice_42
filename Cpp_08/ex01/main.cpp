/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:36:00 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/12 15:04:44 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>

#include "Span.hpp"

int	main( void ) {
	std::cout << "Test from subject" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

std::cout << std::endl;
		std::cout << "The shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "The longest span = " << sp.longestSpan() << std::endl;
	}
	std::cout << "\nTest 2, addNumbers test" << std::endl;
	{
		std::vector<int>	arr;

		for (int i = 0; i < 20; ++i)
			arr.push_back((std::rand() * (i + 4)) % 100);

		Span sp = Span(arr.size());

		sp.addNumbers(arr.begin(), arr.end());

std::cout << std::endl;
		try {
			sp.addNumber(*arr.end());
		} catch ( std::exception &e ) {
			std::cerr << e.what() << std::endl;
		}

		try {
			sp.addNumbers(arr.end(), arr.begin());
		} catch ( std::exception &e ) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << sp << std::endl;

std::cout << std::endl;
		std::cout << "The shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "The longest span = " << sp.longestSpan() << std::endl;
	}
	std::cout << "\nTest 3, copy constructor and copy assignment test" << std::endl;
	{
		const int	size = 10;
		Span		a(size);

		for (int i = 1; i <= size; ++i)
			a.addNumber(i);

		std::cout << "Span a:" << a << std::endl;
		{
			const Span	b(a);
			std::cout << "Span b size: " << b.size() << std::endl;
			std::cout << "Span b:" << b << std::endl;
		}
		{
			Span	c;
			c = a;
			std::cout << "Span c:" << c << std::endl;
		}
	}
	std::cout << "\nTest 4, some overflows and the same elements" << std::endl;
	{
		{
			Span	a(4);

			a.addNumber(1 << 31);
			a.addNumber(~(1 << 31));

			std::cout << a << std::endl;
			std::cout << "The shortest span = " << a.shortestSpan() << std::endl;
			std::cout << "The longest span =  " << a.longestSpan() << std::endl;
		}
		{
			Span	a(4);

			a.addNumber(1 << 31);
			a.addNumber(1 << 31);

			std::cout << a << std::endl;
			std::cout << "The shortest span = " << a.shortestSpan() << std::endl;
			std::cout << "The longest span =  " << a.longestSpan() << std::endl;
		}
	}
	std::cout << "\nTest 5, make sure it works" << std::endl;
	{
		Span	s(10);

std::cout << std::endl;
		std::cout << "Empty span" << std::endl;
		try {
			std::cout << s[0] << std::endl;
		} catch ( std::exception &e ) {
			std::cerr << "Error, " << e.what() << std::endl;
		}

std::cout << std::endl;
		std::cout << "Invalid index" << std::endl;
		try {
			std::cout << s[11] << std::endl;
		} catch ( std::exception &e ) {
			std::cerr << "Error, " << e.what() << std::endl;
		}

std::cout << std::endl;
		std::cout << "Print empty span" << std::endl;
		try {
			std::cout << s << std::endl;
		} catch ( std::exception &e ) {
			std::cerr << "Error, " << e.what() << std::endl;
		}

std::cout << std::endl;
		std::cout << "Invalid executions" << std::endl;
		for (int i = 0; i < 3; ++i) {
			std::cout << "\nElements in span = " << i << std::endl;
			try {
				unsigned int	res = s.longestSpan();
				std::cout << "The longest span = " << res << std::endl;
			} catch ( std::exception &e ) {
				std::cerr << "Error, " << e.what() << std::endl;
			}

			try {
				unsigned int	res = s.shortestSpan();
				std::cout << "The shortest span = " << res << std::endl;
			} catch ( std::exception &e ) {
				std::cerr << "Error, " << e.what() << std::endl;
			}
			s.addNumber(i * 37);
		}
	}
std::cout << std::endl;
	std::cout << "Test 6: array insertions" << std::endl;
	{
		Span	s(25);

		try {
			for (int i = 1; i <= 6; ++i) {
				std::cout << "\nCircle N " << i << ", elements insertions: "
					<< (i - 1) * 5 << "-" << i * 5 << std::endl;
				std::cout << "Array values before: " << s << std::endl;
				std::vector<int>	temp(5, i);
				s.addNumbers(temp.begin(), temp.end());
				std::cout << "Array values after:  " << s << std::endl;
			}
		} catch ( std::exception &e ) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "Array values after:  " << s << std::endl;
	}
std::cout << std::endl;
	std::cout << "Test 7: I promise it is the last one:)" << std::endl;
	{
		Span	s(10);

		try {
			for (int i = 1; i <= 13; ++i) {
				std::cout << "\nCircle N " << i << std::endl;
				std::cout << "Array values before: " << s << std::endl;
				s.addNumber(i);
				std::cout << "Array values after:  " << s << std::endl;
			}
		} catch ( std::exception &e ) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "Array values after:  " << s << std::endl;
	}
	return (0);
}
