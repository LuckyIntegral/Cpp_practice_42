/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:12:23 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/09 21:51:54 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DATA_HPP
# define DATA_HPP


# include <string>

# define DEFAULT_INTEGER 42
# define DEFAULT_STR "Hello World!"
# define DEFAULT_DBL 42.42

// typedef struct	t_data {
// 	int	_integer;
// 	std::string	_str;
// 	double	_dbl;
// } Data;

class Data {
protected:
	int	_integer;
	std::string	_str;
	double	_dbl;

public:
	Data();
	Data( int integer, std::string str, double dbl );
	Data( const Data &other );
	~Data();

	int			getInteger( void ) const;
	void		setInteger( const int integer );
	std::string	getStr( void ) const;
	void		setStr( const std::string str );
	double		getDbl( void ) const;
	void		setDbl( const double dbl );

	Data &operator=( const Data &other );
};

std::ostream	&operator<<( std::ostream &stream, const Data &instance );


#endif // DATA_HPP
