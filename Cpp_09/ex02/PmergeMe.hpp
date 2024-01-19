
#pragma once

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP


# include <string>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe( const PmergeMe &other );
	~PmergeMe();

    PmergeMe &operator=( const PmergeMe &other );
};

std::ostream	&operator<<( std::ostream &stream, const PmergeMe &instance );


#endif // PMERGE_ME_HPP
