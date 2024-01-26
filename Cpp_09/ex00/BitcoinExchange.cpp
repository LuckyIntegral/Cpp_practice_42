/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:52:01 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/26 14:16:09 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange()
		: _database(std::map<std::string, double>()) {
	this->_database = std::map<std::string, double>();
	this->initDb(DEFAULT_FILE);
}

BitcoinExchange::BitcoinExchange( const char *file )
		: _database(std::map<std::string, double>()) {
	this->initDb(file);
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other )
		: _database(std::map<std::string, double>(other._database)) {}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::initDb( const char *file ) {
	std::ifstream	input(file);
	std::string		line;

	if (!input.is_open())
		throw BadFilePathException();
	if (!std::getline(input, line))
		input.close(), throw InvalidDatabase();
	if (line != "date,exchange_rate")
		input.close(), throw InvalidDatabase();
	while (std::getline(input, line)) {
		if (line.length() < 10 || line.at(10) != ',')
			input.close(), throw InvalidDatabase();
		std::string key = line.substr(0, 10);
		dateValidation(key);
		double value = std::atof(line.c_str() + 11);
		if (value < 0)
			input.close(), throw InvalidDatabase();
		// std::cout << "valid" << std::endl;
		this->_database[key] = value;
	}
	input.close();
}

static inline void	validateDatePattern( const std::string &date ) {
	for (size_t i = 0; i < 10; ++i) // check for date pattern ####-##-##
		if ((i == 4 || i == 7) && date[i] != '-')
			throw BitcoinExchange::BadInputException();
		else if (!(i == 4 || i == 7) && !std::isdigit(date[i]))
			throw BitcoinExchange::BadInputException();
}

static void	validateNumber( const std::string &line ) {
	size_t	i = 0;

	if (line.find('.') != line.npos) { // if float
		bool	point = false;

		for (; i < line.length(); ++i)
			if (line[i] == '.') {
				if (point)
					throw BitcoinExchange::BadNumberException();
				point = true;
			} else if (!std::isdigit(line[i]))
				throw BitcoinExchange::BadNumberException();
		if (line == ".")
			throw BitcoinExchange::BadNumberException();
	} else { // if int
		for (; i < line.length(); ++i)
			if (!std::isdigit(line[i]))
				throw BitcoinExchange::BadNumberException();
	}
}

void	BitcoinExchange::requestValidation( const std::string &line ) const {
	if (line.length() < 14) // check line len
		throw BitcoinExchange::BadInputException();

	validateDatePattern(line);

	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw BitcoinExchange::BadInputException();

	validateNumber(line.c_str() + 13);
}

double	BitcoinExchange::exchange( const std::string &date, double sum ) const {
	if (sum > 1000 || sum < 0)
		throw BitcoinExchange::BadNumberException();
	this->dateValidation(date, true);
	double nbr = 0;
	if (this->_database.find(date) != this->_database.end())
		nbr = this->_database.at(date);
	else {
		std::map<std::string, double>::const_iterator	entity;

		entity = this->_database.lower_bound(date);
		if (entity == this->_database.begin())
			throw BitcoinExchange::BadInputException();
		nbr = (--this->_database.lower_bound(date))->second;
	}
	// std::cout << nbr << std::endl;
	return (nbr * sum);
}

void	BitcoinExchange::dateValidation( const std::string &date, bool input ) const {
	if (date.length() !=  10) // check date len
		throw BitcoinExchange::BadInputException();

	validateDatePattern(date);

	int	y, m, d; // parse numbers
	std::sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);

	if (!m || !d || m > 12)
		throw BitcoinExchange::BadInputException(); // invalid month
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		throw BitcoinExchange::BadInputException(); // invalid day in month with 30 days
	else if (d > 31)
		throw BitcoinExchange::BadInputException(); // invalid day in month with 31 days
	else if (m == 2 && ((y % 4 == 0 && d > 29) || (y % 4 != 0 && d > 28)))
		throw BitcoinExchange::BadInputException(); // exception for february
	if (input)
		if (date < this->_database.begin()->first)
			throw BitcoinExchange::BadInputException(); // invalid year (out of db range)
}

const char	*BitcoinExchange::InvalidDatabase::what( void ) const throw() {
	return ("Invalid database");
}

const char	*BitcoinExchange::InvalidDatabasePath::what( void ) const throw() {
	return ("Cannot open the database");
}

const char	*BitcoinExchange::BadFilePathException::what( void ) const throw() {
	return ("Cannot open file");
}

const char	*BitcoinExchange::BadInputException::what( void ) const throw() {
	return ("Bad input detected");
}

const char	*BitcoinExchange::BadNumberException::what( void ) const throw() {
	return ("Invalid number detected");
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other ) {
	this->_database = std::map<std::string, double>(other._database);
	return (*this);
}
