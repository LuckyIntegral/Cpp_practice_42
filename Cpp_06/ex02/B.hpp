/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:45 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:58:59 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef B_HPP
# define B_HPP


# include <string>

# include "Base.hpp"

class B : public Base {
public:
	~B();
};

std::ostream	&operator<<( std::ostream &stream, const B &instance );


#endif // B_HPP
