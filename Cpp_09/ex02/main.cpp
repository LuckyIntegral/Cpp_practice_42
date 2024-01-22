/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:02 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/22 20:05:32 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

#include "PmergeMe.hpp"

static bool	isInvalidNumber( const std::string &v ) {
	for (int i = v[0] == '-' ? 1 : 0; v[i]; ++i)
		if (!std::isdigit(v[i]))
			return (true);

	std::istringstream  iss(v);
	int	n;
	iss >> n;
	if ((n == 2147483647 && v != "2147483647")
		|| (n == -2147483648 && v != "-2147483648"))
		return (true);
	return (false);
}

static inline bool	areValidNumbers( const int &c, const char **v ) {
	for (int i = 1; i < c; ++i)
		if (isInvalidNumber(v[i]))
			return (false);
	return (true);
}

int main( int c, const char **v ) {
    if (c == 1) {
        std::cout << "Usage: " << v[0] << " <numbers_to_sort>" << std::endl;
        return (1);
    }

	if (!areValidNumbers(c, v)) {
	    std::cout << "Error: Wrong input" << std::endl;
		return (1);
	}

    std::vector<int>    first = PmergeMe::parseArgs(c, v);

	PmergeMe::mergeInsertSort(first);

	std::cout << "Size " << first.size() << std::endl;

	// vi first = PmergeMe::jacobsthalNumbers();

	// for (vi::iterator it = first.begin(); it != first.end(); ++it) {
	// 	std::cout << *it << " ";
	// }

    return (0);
}

// 7 6 4 3 8 9 2 1 0 5 12
// (6, 7) (3, 4) (8, 9) (1, 2) (0, 5) 12
// 7 4 9 2 5
// 2 4 5 7 9
// 1 2 3 4 5 6 7 8 9

// 3 5 6 2 1 7 8 9 0 11
// (3, 5) (2, 6) (1, 7) (8, 9) (0, 11)

// 5 6 7 9 11 // sort anuway
// 2 3 5 6 7 9 11 // sort anuway
