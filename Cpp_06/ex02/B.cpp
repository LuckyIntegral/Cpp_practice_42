/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:45 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:58:33 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

#include <iostream>

B::~B() {}

std::ostream	&operator<<( std::ostream &stream, const B & ) {
	stream << "{B}";
	return (stream);
}
