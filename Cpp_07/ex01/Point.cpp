/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:07:07 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/10 16:16:17 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

Point::Point() : _x(DEFAULT_X), _y(DEFAULT_Y), _z(DEFAULT_Z) {}
Point::Point( int x, int y, int z ) : _x(x), _y(y), _z(z) {}
Point::Point( const Point &other ) : _x(other._x), _y(other._y), _z(other._z) {}
Point::~Point() {}

int	Point::getX( void ) const {
	return (this->_x);
}

void	Point::setX( const int x ) {
	this->_x = x;
}

int	Point::getY( void ) const {
	return (this->_y);
}

void	Point::setY( const int y ) {
	this->_y = y;
}

int	Point::getZ( void ) const {
	return (this->_z);
}

void	Point::setZ( const int z ) {
	this->_z = z;
}

Point &Point::operator=( const Point &other ) {
	this->_x = other._x;
	this->_y = other._y;
	this->_z = other._z;
	return (*this);
}

bool	Point::operator>( const Point &other )	const {
	return ((this->_x + this->_y + this->_z) >
		(other.getX() + other.getY() + other.getZ()));
}

bool	Point::operator<( const Point &other )	const {
	return ((this->_x + this->_y + this->_z) <
		(other.getX() + other.getY() + other.getZ()));
}

std::ostream	&operator<<( std::ostream &stream, const Point &instance ) {
	stream << "{Point:"
		<< "x=" << instance.getX() << ','
		<< "y=" << instance.getY() << ','
		<< "z=" << instance.getZ() << '}';
	return (stream);
}
