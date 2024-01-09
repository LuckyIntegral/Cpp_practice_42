/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:59:44 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 22:21:46 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base	*generate( void );
void	identify( Base *p );
void	identify( Base &p );

int	main( void ) {
	{
		for (int i = 0; i < 3; ++i) {
			std::cout << "\nTest " << i + 1 << std::endl;

			Base	*random = generate();
			identify(*random);
			identify(random);

			delete random;
		}
	}
	return (0);
}
