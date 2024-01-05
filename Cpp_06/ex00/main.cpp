
#include <iostream>

#include "ScalarConverter.hpp"

int main( int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
	} else {
		ScalarConverter::convert(std::string(argv[1]));
	}
	return (0);
}
