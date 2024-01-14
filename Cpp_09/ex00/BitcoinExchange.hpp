/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:52:01 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/14 18:41:26 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP


# include <exception>
# include <string>
# include <map>

# define DEFAULT_FILE "invalid_path"

class BitcoinExchange {
private:
	void	initDb( const char *file );

	std::map<std::string, double>	_database;

public:
	BitcoinExchange( void );
	BitcoinExchange( const char *file );
	BitcoinExchange( const BitcoinExchange &other );
	~BitcoinExchange();

	void	dateValidation( const std::string &date ) const throw ( std::exception );
	double	exchange( const std::string &date, double sum ) const throw ( std::exception );
	void	requestValidation( const std::string &line ) const throw ( std::exception );

	class BadFilePathException : public std::exception {
	public:
		const char	*what( void ) const throw( );
	};

	class BadInputException : public std::exception {
	public:
		const char	*what( void ) const throw( );
	};

	class BadNumberException : public std::exception {
	public:
		const char	*what( void ) const throw( );
	};

	BitcoinExchange &operator=( const BitcoinExchange &other );
};


#endif // BITCOIN_EXCHANGE_HPP
