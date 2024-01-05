/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:19:16 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/30 21:30:38 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


# include <exception>
# include <ostream>
# include <string>

# include "AForm.hpp"

class AForm;

class Bureaucrat {
protected:
	const std::string	_name;
	int					_grade;
public:
    Bureaucrat();
    Bureaucrat( const std::string name, int grade );
    Bureaucrat( const Bureaucrat &other );
    ~Bureaucrat();

	void	incrementGrade( void );
	void	decrementGrade( void );
	void	signForm( AForm &fm );
	void	executeForm(AForm const & form) const;

	void				setGrade( int grade );
	int					getGrade( void ) const;
	const std::string	getName( void ) const;

	class GradeTooHighException : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

    Bureaucrat    &operator=( const Bureaucrat &other );
};

std::ostream	&operator<<( std::ostream &out, const Bureaucrat &brc );

#endif // BUREAUCRAT_HPP
