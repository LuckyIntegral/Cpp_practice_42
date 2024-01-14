/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:28:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/14 22:53:11 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int	main( int argc, const char **argv ) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0]
			<< " \"Reverse Polish Expression\"" << std::endl;
		return (1);
	}
	std::string	expression(argv[1]);
	RPN	rpn;

	try {
		double result = rpn.evaluateExpression(expression);
		std::cout << "Your result is: " << result << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Error: " << e.what() << std::endl; // subject requires standart output:)
	}

	return (0);
}
