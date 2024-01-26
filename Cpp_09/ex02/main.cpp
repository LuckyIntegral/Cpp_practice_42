/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:02 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/26 17:17:58 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <sstream>

#include "PmergeMe.hpp"

static bool	isInvalidNumber( const std::string &v ) {
	if (v.empty())
		return (true);

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

static inline void	pv( vi &ns ) {
	for (viit it = ns.begin(); it != ns.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
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

	if (c == 2) {
        std::cout << "One number is not enough" << std::endl;
        return (1);
    }

	// set up containers
	std::clock_t vector_inserting_start = std::clock(); // Start timer
    vi	first = PmergeMe::parseArgsVector(c, v);
	std::clock_t vector_inserting_end = std::clock(); // Start timer

	std::cout << "Before: "; pv(first);

	std::clock_t vector_sorting_start = std::clock(); // Start timer
	PmergeMe::mergeInsertSort(first);
	std::clock_t vector_sorting_end = std::clock(); // Finish timer

	std::cout << "After:  "; pv(first);

	std::cout << "Vector: {sorting time: " << (vector_sorting_end - vector_sorting_start) / 1000.
		<< " us, time for data management: " << (vector_inserting_end - vector_inserting_start) / 1000.
		<< " us, size of vector: " << first.size() << '}' << std::endl;

	std::clock_t deque_inserting_start = std::clock(); // Start timer
    di	second = PmergeMe::parseArgsDeque(c, v);
	std::clock_t deque_inserting_end = std::clock(); // Start timer

	std::clock_t deque_sorting_start = std::clock(); // Start timer
	PmergeMe::mergeInsertSort(second);
	std::clock_t deque_sorting_end = std::clock(); // Finish timer

	std::cout << "Deque:  {sorting time: " << (deque_sorting_end - deque_sorting_start) / 1000.
		<< " us, time for data management: " << (deque_inserting_end - deque_inserting_start) / 1000.
		<< " us, size of deque: " << first.size() << '}' << std::endl;

	std::cout << "Is vector sorted? " << (PmergeMe::isSorted(first) ? "OK" : "KO") << std::endl;
	std::cout << "Is deque sorted?  " << (PmergeMe::isSorted(second) ? "OK" : "KO") << std::endl;

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
