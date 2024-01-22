/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:00:46 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/22 14:58:14 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP


# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {}
	MutantStack( const MutantStack &other ) : std::stack<T>(other) {};
	~MutantStack() {};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin( void ) {
		return std::stack<T>::c.begin();
	}

	iterator end( void ) {
		return std::stack<T>::c.end();
	}

	const_iterator cbegin( void ) const {
		return std::stack<T>::c.begin();
	}

	const_iterator cend( void ) const {
		return std::stack<T>::c.end();
	}

	reverse_iterator rbegin( void ) {
		return std::stack<T>::c.rbegin();
	}

	reverse_iterator rend( void ) {
		return std::stack<T>::c.rend();
	}

	const_reverse_iterator crbegin( void ) const {
		return std::stack<T>::c.rbegin();
	}

	const_reverse_iterator crend( void ) const {
		return std::stack<T>::c.rend();
	}

    MutantStack &operator=( const MutantStack &other ) {
		this->c = other.c;
		return (*this);
	}
};


#endif // MUTANT_STACK_HPP
