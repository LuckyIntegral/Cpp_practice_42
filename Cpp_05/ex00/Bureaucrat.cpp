/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:19:16 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/30 18:40:11 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name) {
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _name(other._name) {
	this->setGrade(other._grade);
}

Bureaucrat::~Bureaucrat() {}

void	Bureaucrat::incrementGrade( void ) {
	this->setGrade(this->getGrade() - 1);
}

void	Bureaucrat::decrementGrade( void ) {
	this->setGrade(this->getGrade() + 1);
}

void	Bureaucrat::setGrade( int grade ) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

int	Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

const std::string	Bureaucrat::getName( void ) const {
	return (this->_name);
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other ) {
	this->_grade = other._grade;
    return (*this);
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("grade too high exception");
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("grade too low exception");
}


std::ostream	&operator<<( std::ostream &stream, const Bureaucrat &brc ) {
	stream << brc.getName() << ", bureaucrat grade " << brc.getGrade();
	return (stream);
}
