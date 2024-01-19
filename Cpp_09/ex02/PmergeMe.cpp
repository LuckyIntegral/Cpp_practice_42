
#include "PmergeMe.hpp"

#include <iostream>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe( const PmergeMe & ) {}
PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=( const PmergeMe & ) {
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const PmergeMe & ) {
	stream << "{PmergeMe:{}}";
	return (stream);
}
