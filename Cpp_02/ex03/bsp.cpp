/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:48:55 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/29 20:25:51 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static inline Point	calculateVector(Point begin, Point end) {
	return (Point(
		(end.getX() - begin.getX()).toFloat(),
		(end.getY() - begin.getY()).toFloat()
	));
}

static inline Fixed	multiplyVector(Point first, Point second) {
	return (first.getX() * second.getY() - first.getY() * second.getX());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Point	AB = calculateVector(a, b);
	Point	BC = calculateVector(b, c);
	Point	CA = calculateVector(c, a);
	Point	AP = calculateVector(a, point);
	Point	BP = calculateVector(b, point);
	Point	CP = calculateVector(c, point);

	Fixed	ABxAP = multiplyVector(AB, AP);
	Fixed	BCxBP = multiplyVector(BC, BP);
	Fixed	CAxCP = multiplyVector(CA, CP);

	return ((ABxAP > 0 && BCxBP > 0 && CAxCP > 0) || (ABxAP < 0 && BCxBP < 0 && CAxCP < 0));
}
