/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:30:50 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:34:01 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP


# include <string>
# include <stdint.h>

# include "Data.hpp"

class Serializer {
private:
	Serializer();
	Serializer( const Serializer &other );
	~Serializer();

	Serializer &operator=( const Serializer &other );
public:
	static uintptr_t	serialize( Data* ptr );
	static Data			*deserialize( uintptr_t raw );
};


#endif // SERIALIZER_HPP
