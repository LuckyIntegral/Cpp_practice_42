/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:07:07 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/10 16:24:49 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
# define POINT_HPP


# include <string>

# define DEFAULT_X 0
# define DEFAULT_Y 0
# define DEFAULT_Z 0

class Point {
protected:
	int	_x;
	int	_y;
	int	_z;

public:
	Point();
	Point( int x, int y, int z );
	Point( const Point &other );
	~Point();

	int			getX( void ) const;
	void		setX( const int x );
	int			getY( void ) const;
	void		setY( const int y );
	int			getZ( void ) const;
	void		setZ( const int z );

	Point &operator=( const Point &other );
	bool operator>( const Point &other )	const;
	bool operator<( const Point &other )	const;
};

std::ostream	&operator<<( std::ostream &stream, const Point &instance );


#endif // POINT_HPP
