/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:27:33 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/14 22:47:05 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stack>

std::string	RPN::VALID_TOKENS = std::string("0123456789+-/*");

RPN::RPN() {}
RPN::RPN( const RPN & ) {}
RPN::~RPN() {}

void	RPN::validateExpression( const std::string &line ) {
	int	numbers = 0, operators = 0;

	if (line.length() % 2 == 0) // no spaces at the end tolerated:)
		throw RPN::SyntaxException();

	for (int i = 0; line[i]; ++i) { // make sure that it follows "# # # #" pattern
		if (i % 2) { // spaces
			if (line[i] != ' ')
				throw RPN::SyntaxException();
		} else { // tokens
			if (VALID_TOKENS.find(line[i]) == VALID_TOKENS.npos)
				throw RPN::SyntaxException();
			if (std::isdigit(line[i]))
				numbers++;
			else
				operators++;
		}
	}

	if (numbers - operators != 1)
		throw RPN::UnsolvableExpressionException();
}

static void	prepareExpression( double &a, double &b, std::stack<double> &s ) {
	if (s.size() < 2)
		throw RPN::UnsolvableExpressionException();
	b = s.top();
	s.pop();
	a = s.top();
	s.pop();
}

double	RPN::evaluateExpression( const std::string &line ) {
	this->validateExpression(line);
	std::stack<double>	s;
	double	a = 0, b = 0;

	for (std::string::const_iterator it = line.begin(); it != line.end(); ++it) {
		if (*it == ' ')
			continue ;
		switch (*it) {
			case ('+') :
				prepareExpression(a, b, s);
				s.push(a + b);
				break;
			case ('-') :
				prepareExpression(a, b, s);
				s.push(a - b);
				break;
			case ('/') :
				prepareExpression(a, b, s);
				if (b == 0)
					throw DivisionByZeroException();
				s.push(a / b);
				break;
			case ('*') :
				prepareExpression(a, b, s);
				s.push(a * b);
				break;
			default:
				s.push(*it - '0');
		}
	}
	return (s.top());
}

const char	*RPN::SyntaxException::what( void ) const throw () {
	return ("Syntax error encountered");
}

const char	*RPN::UnsolvableExpressionException::what( void ) const throw () {
	return ("Expression is unsolvable");
}

const char	*RPN::DivisionByZeroException::what( void ) const throw () {
	return ("Division by zero encountered");
}

RPN &RPN::operator=( const RPN & ) {
	return (*this);
}
