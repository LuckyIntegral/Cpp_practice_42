/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:27:33 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/14 22:47:24 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef RPN_HPP
# define RPN_HPP


# include <exception>
# include <string>

class RPN {
private:
	static std::string	VALID_TOKENS;

	void	validateExpression( const std::string &line );

public:
	RPN();
	RPN( const RPN &other );
	~RPN();

	double	evaluateExpression( const std::string &line );

	class SyntaxException : public std::exception {
	public:
		virtual const char	*what( void ) const throw ();
	};

	class UnsolvableExpressionException : public std::exception {
	public:
		virtual const char	*what( void ) const throw ();
	};

	class DivisionByZeroException : public std::exception {
	public:
		virtual const char	*what( void ) const throw ();
	};

	RPN &operator=( const RPN &other );
};


#endif // RPN_HPP
