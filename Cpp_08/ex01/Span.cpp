/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:52:49 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/12 15:06:38 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <stdexcept>

Span::Span() : _size(DEFAULT_SIZE), _ns(std::vector<int>()) {}
Span::Span( ui N ) : _size(N), _ns(std::vector<int>()) {}
Span::Span( const Span &other ) : _size(other._size), _ns(std::vector<int>(other._ns)) {}
Span::~Span() {}

ui	Span::size( void ) const {
	return (this->_size);
}

void	Span::addNumber( int nbr ) throw ( std::exception ) {
	if (this->_ns.size() == this->_size)
		throw FullSpanException();
	this->_ns.push_back(nbr);
}

void	Span::addNumbers( vci begin, vci end ) throw ( std::exception ) {
	if (begin > end)
		throw InvalidArgsException();
	if (this->_ns.size() + std::distance(begin, end) > this->_size)
		throw FullSpanException();
	this->_ns.insert(this->_ns.end(), begin, end);
}

ui	Span::shortestSpan( void ) const throw ( std::exception ) {
	if (this->_ns.size() < 2)
		throw TooSmallSpanException();
	long	shortest = ~0u;
	for (vci it = this->_ns.begin(); it != this->_ns.end() - 1; ++it) {
		for (vci jt = it + 1; jt != this->_ns.end(); ++jt) {
			shortest = std::min(
				std::abs(static_cast<long>(*it) - static_cast<long>(*jt)),
				shortest
			);
		}
	}
	return (shortest);
}

ui	Span::longestSpan( void ) const throw ( std::exception ) {
	if (this->_ns.size() < 2)
		throw TooSmallSpanException();
	int		max = *std::max_element(this->_ns.begin(), this->_ns.end());
	int		min = *std::min_element(this->_ns.begin(), this->_ns.end());
	long	delta = static_cast<long>(max) - static_cast<long>(min);
	return (static_cast<ui>(delta));
}

int &Span::operator[]( ui index ) {
	if (index >= this->_size || index >= this->_ns.size())
		throw std::out_of_range("Out of range");
	return (this->_ns[index]);
}

const int &Span::operator[]( ui index ) const {
	if (index >= this->_size || index >= this->_ns.size())
		throw std::out_of_range("Out of range");
	return (this->_ns[index]);
}

Span &Span::operator=( const Span &other ) {
	this->_size = other._size;
	this->_ns = std::vector<int>(other._ns);
	return (*this);
}

const char	*Span::TooSmallSpanException::what( void ) const throw () {
	return ("Less that 2 elements detected in span");
}

const char	*Span::InvalidArgsException::what( void ) const throw () {
	return ("Invalid iterators detected");
}

const char	*Span::FullSpanException::what( void ) const throw () {
	return ("Span is already full");
}

std::ostream	&operator<<( std::ostream &stream, const Span &span ) {
	stream << "{Span:{" ;
	try {
		for (ui i = 0; i < span.size(); ++i) {
			(void) span[i];
			if (i)
				stream << ", ";
			stream << span[i];
		}
	} catch ( ... ) {}
	stream << "}}";
	return (stream);
}
