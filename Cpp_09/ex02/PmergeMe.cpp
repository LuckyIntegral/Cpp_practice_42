
#include "PmergeMe.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe( const PmergeMe & ) {}
PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=( const PmergeMe & ) {
	return (*this);
}

static inline void	pv( vi &ns ) {
	for (viit it = ns.begin(); it != ns.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

vi	&PmergeMe::jacobsthalNumbers( void ) {
	static vi	jacobsthalNumbers;
	int			buf = 0;

	if (!jacobsthalNumbers.empty())
		return (jacobsthalNumbers);
	jacobsthalNumbers.push_back(1);
	jacobsthalNumbers.push_back(3);
	for (int i = 2; true; i++)
	{
		buf = jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2];
		if (buf < jacobsthalNumbers.back())
			break ;
		jacobsthalNumbers.push_back(buf);
	}
	return (jacobsthalNumbers);
}

static bool	isSorted( vi &ns ) {
	for (viit it = ns.begin(); it != ns.end() - 1; ++it)
		if (*it > *(it + 1))
			return (false);
	return (true);
}

static std::pair<vi, vi>	sortePairs( vi &ns, int i ) {
	vi	smaller, bigger;

	for (viit it = ns.begin(); it <= ns.end() - 1 - i; std::advance(it, 2)) {
		bigger.push_back(std::max(*it, *(it + 1)));
		smaller.push_back(std::min(*it, *(it + 1)));
	}
	return (std::pair<vi, vi>(smaller, bigger));
}

static void mergePairs( viit begin, viit middle, viit end ) {
	vi		left(begin, middle), right(middle, end);
	viit	leftIt = left.begin(), rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end())
		*begin++ = (*leftIt <= *rightIt ? *leftIt++ : *rightIt++);

	std::copy(leftIt, left.end(), begin);
	std::copy(rightIt, right.end(), begin);
}

static void	recursiveSort( vi &ns, viit begin, viit end ) {
	if (std::distance(begin, end) <= 2) {
		if (std::distance(begin, end) == 2
				&& *begin > *(begin + 1))
			std::swap(*begin, *(begin + 1));
		return ;
	}
	viit	middle = begin + (end - begin) / 2;

	recursiveSort(ns, begin, middle);
	recursiveSort(ns, middle, end);

	mergePairs(begin, middle, end);
}

static vi	jacobsthalInsert( vi &first, vi &second ) {
	vi	res(second), jn = PmergeMe::jacobsthalNumbers();

	// pv(first);
	// pv(second);
	// pv(jn);
	for (int n = 1; !first.empty(); ++n) {
        for (int i = jn[n] - jn[n - 1] - 1; i >= 0; --i) {
			if (first.empty())
				break ;
			i = std::min(i, static_cast<int>(first.size()) - 1);
			// std::cout << "n: " << n << " i: " << i << " number to insert: " << first[i] << std::endl;
            viit where = std::lower_bound(res.begin(), res.end(), first[i]);
            res.insert(where, first[i]);
            first.erase(first.begin() + i);
		}
	}
	// pv(res);
	return (res);
}

void	PmergeMe::mergeInsertSort( vi &ns ) {
	if (isSorted(ns))
		return ;
	bool	hasExtraElement = ns.size() % 2 == 1;
	int		extraElement = 0;
	if (hasExtraElement) {
		extraElement = ns.back();
		ns.pop_back();
	}

	pv(ns);

	std::pair<vi, vi> pairs = sortePairs(ns, hasExtraElement);

	recursiveSort(pairs.first, pairs.first.begin(), pairs.first.end());
	recursiveSort(pairs.second, pairs.second.begin(), pairs.second.end());

	pairs.second.insert(pairs.second.begin(), *pairs.first.begin());
	pairs.first.erase(pairs.first.begin());

	ns = jacobsthalInsert(pairs.first, pairs.second);

	if (hasExtraElement)
    	ns.insert(std::lower_bound(ns.begin(), ns.end(), extraElement), extraElement);

	pv(ns);
}

vi	PmergeMe::parseArgs( const int &c, const char **v ) {
	vi	res;

	for (int i = 1; i < c; ++i)
		res.push_back(std::atoi(v[i]));

	return (res);
}

const char	*PmergeMe::OverflowException::what( void ) const throw() {
	return ("Overflow detected");
}
