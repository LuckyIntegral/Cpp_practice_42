/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:43 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:58:44 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

#include <iostream>

A::~A() {}

std::ostream	&operator<<( std::ostream &stream, const A & ) {
	stream << "{A}";
	return (stream);
}
