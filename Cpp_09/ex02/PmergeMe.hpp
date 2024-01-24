
#pragma once

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP


# include <vector>
# include <deque>

typedef std::vector< int >					vi;
typedef std::vector< int >::iterator		viit;
typedef std::vector< int >::const_iterator	vicit;

typedef std::deque< int >					di;
typedef std::deque< int >::iterator			diit;
typedef std::deque< int >::const_iterator	dicit;

class PmergeMe {
public:

	static vi	&jacobsthalNumbers( void );

	static vi	parseArgsVector( const int &c, const char **v );
	static bool	areValidNumbers( const int &c, const char **v );
	static void	mergeInsertSort( vi &ns );
	static bool	isSorted( const vi &ns );

	static di	parseArgsDeque( const int &c, const char **v );
	static void	mergeInsertSort( di &ns );
	static bool	isSorted( const di &ns );

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
