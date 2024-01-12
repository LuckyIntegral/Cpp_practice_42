/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:45:10 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/11 19:41:38 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP


# include <stdexcept>
# include <algorithm>
# include <exception>
# include <vector>
# include <string>

template <typename T>
typename T::iterator	easyfind( T &container, int number )
			throw( std::invalid_argument ) {
	typename T::iterator it = std::find(container.begin(), container.end(), number);
	if (it == container.end())
		throw std::invalid_argument("Element doesnt exist");
	return (it);
}

template <typename T>
const typename T::const_iterator	easyfind( const T &container, int number )
			throw( std::invalid_argument ) {
	const typename T::const_iterator it = std::find(container.begin(), container.end(), number);
	if (it == container.end())
		throw std::invalid_argument("Element doesnt exist");
	return (it);
}


#endif // EASYFIND_HPP
