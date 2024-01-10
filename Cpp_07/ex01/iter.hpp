/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:05 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/10 16:49:54 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	print( const T &e ) {
	std::cout << e << std::endl;
}

template <typename T>
void	assign( T &number ) {
	number = T();
}

template <typename T>
void	iter( const T *e, const int &size, void (*foo)(const T &e) ) {
	for (int i = 0; i < size; ++i)
		foo(e[i]);
}

template <typename T>
void	iter( T *e, const int &size, void (*foo)(T &e) ) {
	for (int i = 0; i < size; ++i)
		foo(e[i]);
}


#endif // ITER_HPP
