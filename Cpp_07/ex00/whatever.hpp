/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:19:33 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/10 16:22:19 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template <typename T>
void	swap( T &first, T &second ) {
	T	temp = first;
	first = second;
	second = temp;
}

template <typename T>
T	min( const T &first, const T &second) {
	return (first < second ? first : second);
}

template <typename T>
T	max( const T &first, const T &second) {
	return (first > second ? first : second);
}


#endif // WHATEVER_HPP
