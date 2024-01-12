/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:52:50 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/12 15:06:15 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP


# include <string>
# include <vector>
# include <exception>

# define DEFAULT_SIZE 0

typedef std::vector<int>::const_iterator	vci;
typedef unsigned int						ui;

class Span {
private:
	ui					_size;
	std::vector<int>	_ns;

public:
	Span();
	Span( ui N );
	Span( const Span &other );
	~Span();

	ui	size( void ) const;

	void	addNumber( int nbr ) throw ( std::exception );
	void	addNumbers( vci begin, vci end ) throw ( std::exception );
	ui		shortestSpan( void ) const throw ( std::exception );
	ui		longestSpan( void ) const throw ( std::exception );

	const int	&operator[]( const ui index ) const;
	int			&operator[]( ui index ) ;
	Span		&operator=( const Span &other );

	class FullSpanException : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

	class InvalidArgsException : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

	class TooSmallSpanException : public std::exception {
	public:
		const char	*what( void ) const throw();
	};
};

std::ostream	&operator<<( std::ostream &stream, const Span &instance );


#endif // SPAN_HPP
