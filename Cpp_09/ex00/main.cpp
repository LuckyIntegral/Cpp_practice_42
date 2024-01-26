/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:36:00 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/26 14:05:20 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

#define DATABASE_PATH "data.csv"
#define INPUT_DB_HEADER "date | value"

int	main( int argc, const char **argv ) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <database>" << std::endl;
		return (1);
	}

	std::ifstream	inputFileStream(argv[1]);
	std::string		line;

	if (!inputFileStream.is_open()) {
		std::cerr << "Error: cannot open file" << std::endl;
		return (1);
	}

	try {
		BitcoinExchange	exchanger(DATABASE_PATH);
		if (!std::getline(inputFileStream, line))
			throw BitcoinExchange::BadInputException();

		if (line != INPUT_DB_HEADER)
			throw BitcoinExchange::BadInputException();

		while (std::getline(inputFileStream, line)) {
			try {
				exchanger.requestValidation(line);
				std::string	date = line.substr(0, 10);
				double	nbr = std::atof(line.c_str() + 13);
				double sum = exchanger.exchange(date, nbr);
				std::cout << date << " => " << nbr << " = " << sum << std::endl;
			} catch ( BitcoinExchange::BadNumberException &e ) {
				std::cerr << "Error: " << e.what() << " => " << line.c_str() + 13 << std::endl;
			} catch ( BitcoinExchange::BadInputException &e ) {
				std::cerr << "Error: " << e.what() << " => " << line << std::endl;
			} catch ( std::exception &e ) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	} catch ( std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	inputFileStream.close();
	return (0);
}
