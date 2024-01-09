/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:12:23 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:51:44 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#include <iostream>

Data::Data() : _integer(DEFAULT_INTEGER), _str(DEFAULT_STR), _dbl(DEFAULT_DBL) {}
Data::Data( int integer, std::string str, double dbl ) : _integer(integer), _str(str), _dbl(dbl) {}
Data::Data( const Data &other ) : _integer(other._integer), _str(other._str), _dbl(other._dbl) {}
Data::~Data() {}

int Data::getInteger( void ) const {
	return (this->_integer);
}

void Data::setInteger( const int integer ) {
	this->_integer = integer;
}

std::string Data::getStr( void ) const {
	return (this->_str);
}

void Data::setStr( const std::string str ) {
	this->_str = str;
}

double Data::getDbl( void ) const {
	return (this->_dbl);
}

void Data::setDbl( const double dbl ) {
	this->_dbl = dbl;
}

Data &Data::operator=( const Data &other ) {
	this->_integer = other._integer;
	this->_str = other._str;
	this->_dbl = other._dbl;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Data &instance ) {
	stream << "{Data:"
		<< "integer=" << instance.getInteger() << ','
		<< "str=" << instance.getStr() << ','
		<< "dbl=" << instance.getDbl() << '}';
	return (stream);
}
