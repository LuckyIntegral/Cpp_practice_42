/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:07 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:57:35 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <iostream>

Base::~Base() {}

std::ostream	&operator<<( std::ostream &stream, const Base & ) {
	stream << "{Base:{}}";
	return (stream);
}
