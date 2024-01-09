/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:29:18 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:32:43 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>


Serializer::Serializer() {}
Serializer::Serializer( const Serializer & ) {}
Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

Serializer &Serializer::operator=( const Serializer & ) {
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Serializer & ) {
	stream << "{Serializer:{}}";
	return (stream);
}
