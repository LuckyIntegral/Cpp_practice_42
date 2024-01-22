
#pragma once

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP


# include <vector>

typedef std::vector< int >								vi;
typedef std::vector< int >::iterator					viit;

class PmergeMe {
public:

	static vi	&jacobsthalNumbers( void );
	static vi	parseArgs( const int &c, const char **v );
	static bool	areValidNumbers( const int &c, const char **v );
	static void	mergeInsertSort( vi &ns );

	class OverflowException : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

private:
	PmergeMe();
	PmergeMe( const PmergeMe &other );
	~PmergeMe();

    PmergeMe &operator=( const PmergeMe &other );
};


#endif // PMERGE_ME_HPP
