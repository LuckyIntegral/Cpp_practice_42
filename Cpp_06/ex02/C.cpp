/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:46 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:59:09 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

#include <iostream>

C::~C() {}

std::ostream	&operator<<( std::ostream &stream, const C & ) {
	stream << "{C}";
	return (stream);
}
