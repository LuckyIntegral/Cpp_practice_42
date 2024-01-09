/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:07 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 22:10:52 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BASE_HPP
# define BASE_HPP


# include <string>

class Base {
public:
	virtual ~Base();
};

std::ostream	&operator<<( std::ostream &stream, const Base &instance );


#endif // BASE_HPP
