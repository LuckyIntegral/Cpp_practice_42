
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "ScalarConverter.hpp"

#define IMP "impossible"
#define ND "Non displayable"

static inline void	puti( int i ) {std::cout << "int: " << i << std::endl;}
static inline void	puti( std::string i ) {std::cout << "int: " << i << std::endl;}
static inline void	putc( char i ) {std::cout << "char: '" << i << '\'' << std::endl;}
static inline void	putc( std::string i ) {std::cout << "char: " << i << std::endl;}
static inline void	putf( float i ) {std::cout << "float: " << i << 'f' << std::endl;}
static inline void	putf( std::string i ) {std::cout << "float: " << i << std::endl;}
static inline void	putd( double i ) {std::cout << "double: " << i << std::endl;}
static inline void	putd( std::string i ) {std::cout << "double: " << i << std::endl;}

inline bool	isInt( const std::string &str ) {
	if (str == "-" || str == "+")
		return (false);

	size_t i = str[0] == '-' ? 1 : 0;
	for (; i < str.length(); ++i)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

inline bool	isChar( const std::string &str ) {
	return (str.length() == 1 && std::isprint(str[0]));
}

bool	isFloatingPoint( const std::string &str, bool isFloat ) {
	size_t	i = 0;

	if (str.length() < 1 || str == ".f")
		return (false);
	if (str[i] == '-')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (isFloat && str[i] == 'f')
		i++;
	return (str[i] == '\0');
}

inline bool	isException( const std::string &str ) {
	return (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf"
		|| str == "-inf" || str == "+inf" || str == "inf" || str == "nan");
}

inline bool	isIntOverflow( const std::string &str ) {
	int	res = 0;

	std::istringstream(str) >> res;
	return (str != "2147483647" && str != "-2147483648"
		&& (res == 2147483647 || res == -2147483648));
}

void	toInt( const std::string &str ) {
	if (isIntOverflow(str)) {
		double	res = std::atof(str.c_str());
		putc(IMP);
		puti(IMP);
		putf(static_cast<float>(res));
		putd(res);
	} else {
		int	res = 0;
		std::istringstream(str) >> res;
		if (res < 0 || res > 127)
			putc(IMP);
		else if (res < 32 || res > 126)
			putc(ND);
		else
			putc(static_cast<char>(res));
		puti(res);
		putf(res);
		putd(res);
	}
}

void	toChar( const std::string &str ) {
	char	c = str[0];

	putc(c);
	puti(c);
	putf(c);
	putd(c);
}

void	toFloat( const std::string &str ) {
	float	n = std::atof(str.c_str());

	if (n < 0 || n > 127)
		putc(IMP);
	else if (n < 32 || n > 126)
		putc(ND);
	else
		putc(static_cast<char>(n));
	if (n <= 2147483647.0 && n >= -2147483648.0)
		puti(static_cast<int>(n));
	else
		puti(IMP);
	putf(n);
	putd(n);
}

void	toDouble( const std::string &str ) {
	double	n = std::atof(str.c_str());

	if (n < 0 || n > 127)
		putc(IMP);
	else if (n < 32 || n > 126)
		putc(ND);
	else
		putc(static_cast<char>(n));
	if (n <= 2147483647.0 && n >= -2147483648.0)
		puti(static_cast<int>(n));
	else
		puti(IMP);
	putf(n);
	putd(n);
}

void	toException( const std::string &str ) {
	double	res = std::atof(str.c_str());

	putc(IMP);
	puti(IMP);
	putf(res);
	putd(res);
}

void	ScalarConverter::convert( std::string &original ) {
	if (!original.length())
	{
		std::cout << "Empty line deteceted" << std::endl;
		return (putc(IMP), puti(IMP), putf(IMP), putd(IMP));
	}
	if (isInt(original)) {
		std::cout << "Catch by int block" << std::endl;
		toInt(original);
	} else if (isChar(original)) {
		std::cout << "Catch by char block" << std::endl;
		toChar(original);
	} else if (isFloatingPoint(original, false)) {
		std::cout << "Catch by double block" << std::endl;
		toDouble(original);
	} else if (isFloatingPoint(original, true)) {
		std::cout << "Catch by float block" << std::endl;
		toFloat(original);
	} else if (isException(original)) {
		std::cout << "Catch by exception block" << std::endl;
		toException(original);
	} else {
		std::cout << "Wrong input detected" << std::endl;
		putc(IMP);
		puti(IMP);
		putf(IMP);
		putd(IMP);
	}
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter( const ScalarConverter & ) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=( const ScalarConverter & ) {return (*this);}
