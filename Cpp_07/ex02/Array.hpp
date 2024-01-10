/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:19:33 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/10 22:39:44 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#ifndef ARRAY_HPP
# define ARRAY_HPP


# include <string>
# include <exception>

# define DEFAULT_SIZE 0

template <typename T>
class Array {
public:
	Array( void ) : _size(DEFAULT_SIZE), _arr(NULL) {};
	Array( unsigned int n ) : _size(n) {
		this->_arr = new T[this->_size]();
	};
	Array( const Array &other ) : _size(other._size), _arr(new T[this->_size]()) {
		for (unsigned int i = 0; i < this->_size; ++i)
			this->_arr[i] = other._arr[i];
	};
	~Array() {
		delete[] this->_arr;
	};

	unsigned int	size( void ) const {
		return (this->_size);
	};

	Array			&operator=( const Array &other ) {
		if (this->_size)
			delete[] this->_arr;
		this->_size = other.size();
		this->_arr = new T[this->_size]();
		for (unsigned int i = 0; i < this->_size; ++i)
			(*this)[i] = T(other[i]);
		return (*this);
	};

	T	&operator[]( unsigned int index ) {
		if (index >= this->size())
			throw IndexOutOfBoundsException();
		return (this->_arr[index]);
	};

	const T	&operator[]( unsigned int index ) const {
		if (index >= this->size())
			throw IndexOutOfBoundsException();
		return (this->_arr[index]);
	};

	class IndexOutOfBoundsException : public std::exception {
	public:
		virtual const char	*what( void ) const throw() {
			return ("Index out of bounds exception");
		};
	};
private:
	unsigned int	_size;
	T				*_arr;
};

template<typename T>
void	forEach( Array<T> arr, void (f)( T & ) ) {
	for (unsigned int i = 0; i < arr.size(); ++i)
		f(arr[i]);
}

template<typename T>
void	forEach( const Array<T> arr, void (f)( const T & ) ) {
	for (unsigned int i = 0; i < arr.size(); ++i)
		f(arr[i]);
}

#endif // ARRAY_HPP
