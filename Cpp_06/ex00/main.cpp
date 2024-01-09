
#include <iostream>

#include "ScalarConverter.hpp"

int main( int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
	} else {
		std::string	str(argv[1]);
		ScalarConverter::convert(str);
	}
	return (0);
}
