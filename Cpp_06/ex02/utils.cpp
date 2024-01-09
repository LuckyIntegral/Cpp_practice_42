/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:04:17 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 22:20:44 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <locale>

Base	*generate( void ) {
	static int	choise = std::time(NULL) % 3;

	choise = (choise + 1) % 3;
	
	switch (choise) {
		case (0):
			return (new A);
		case (1):
			return (new B);
		default:
			return (new C);
	}
}

void	identify( Base *p ) {
	try {
		if (dynamic_cast<A*>(p))
			std::cout << "Type A" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "Type B" << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "Type C" << std::endl;
	} catch (...) {
		std::cerr << "Error occured during casting" << std::endl;
	}
}

void	identify( Base &p ) {
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "Type A" << std::endl;
	} catch (...) {
		try {
			B b = dynamic_cast<B &>(p);
			std::cout << "Type B" << std::endl;
		} catch (...) {
			try {
				C c = dynamic_cast<C &>(p);
				std::cout << "Type C" << std::endl;
			} catch (...) {
				std::cerr << "Error occured during casting" << std::endl;
			}
		}
	}
}
