/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:46 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:59:25 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef C_HPP
# define C_HPP


# include <string>

# include "Base.hpp"

class C : public Base {
public:
	~C();
};

std::ostream	&operator<<( std::ostream &stream, const C &instance );


#endif // C_HPP
