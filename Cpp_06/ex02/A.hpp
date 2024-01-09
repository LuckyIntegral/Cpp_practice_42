/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:43 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:58:15 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef A_HPP
# define A_HPP


# include <string>

# include "Base.hpp"

class A : public Base {
public:
	~A();
};

std::ostream	&operator<<( std::ostream &stream, const A &instance );


#endif // A_HPP
