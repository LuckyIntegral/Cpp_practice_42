
#include <iostream>

#include "ScalarConverter.hpp"

void	ScalarConverter::convert( std::string original ) {
	if ()

	std::cout << "" << static_cast<char>(nbr) << std::endl;
	std::cout << "" << static_cast<int>(nbr) << std::endl;
	std::cout << "" << static_cast<float>(nbr) << std::endl;
	std::cout << "" << static_cast<double>(nbr) << std::endl;

}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter( const ScalarConverter & ) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=( const ScalarConverter & ) {return (*this);}
