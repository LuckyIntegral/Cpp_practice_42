
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

bool	PmergeMe::isSorted( const vi &ns ) {
	for (vicit it = ns.begin(); it != ns.end() - 1; ++it)
		if (*it > *(it + 1))
			return (false);
	return (true);
}

bool	PmergeMe::isSorted( const di &ns ) {
	for (dicit it = ns.begin(); it != ns.end() - 1; ++it)
		if (*it > *(it + 1))
			return (false);
	return (true);
}

static std::pair<vi, vi>	sortePairs( const vi &ns, int i ) {
	vi	smaller, bigger;

	for (vicit it = ns.begin(); it <= ns.end() - 1 - i; std::advance(it, 2)) {
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
	const vi jn = PmergeMe::jacobsthalNumbers();
	vi		res(second);
	viit	lower, upper, where;

	for (int n = 1; !first.empty(); ++n) {
		for (int i = jn[n] - jn[n - 1] - 1; i >= 0; --i) {
			if (first.empty())
				break ;
			i = std::min(i, static_cast<int>(first.size()) - 1);
			lower = res.begin() + (jn[n - 1]) - 1;
			upper = std::min((res.begin() + (2 * jn[n]) - 1), res.end());
			where = std::lower_bound(lower, upper, first[i]);
			res.insert(where, first[i]);
			first.erase(first.begin() + i);
		}
	}
	return (res);
}

void	PmergeMe::mergeInsertSort( vi &ns ) {
	if (isSorted(ns)) return ;

	bool	hasExtraElement = ns.size() % 2 == 1;
	int		reminder = 0;
	if (hasExtraElement) {
		reminder = ns.back();
		ns.pop_back();
	}

	std::pair<vi, vi> pairs = sortePairs(ns, hasExtraElement);

	recursiveSort(pairs.first, pairs.first.begin(), pairs.first.end());
	recursiveSort(pairs.second, pairs.second.begin(), pairs.second.end());

	pairs.second.insert(pairs.second.begin(), *pairs.first.begin());
	pairs.first.erase(pairs.first.begin());

	ns = jacobsthalInsert(pairs.first, pairs.second);

	if (hasExtraElement)
		ns.insert(std::lower_bound(ns.begin(), ns.end(), reminder), reminder);
}

static di	jacobsthalInsert( di &first, di &second ) {
	const vi jn = PmergeMe::jacobsthalNumbers();
	di		res(second);
	diit	lower, upper, where;

	for (int n = 1; !first.empty(); ++n) {
		for (int i = jn[n] - jn[n - 1] - 1; i >= 0; --i) {
			if (first.empty())
				break ;
			i = std::min(i, static_cast<int>(first.size()) - 1);
			lower = res.begin() + (jn[n - 1]) - 1;
			upper = std::min((res.begin() + (2 * jn[n]) - 1), res.end());
			where = std::lower_bound(lower, upper, first[i]);
			res.insert(where, first[i]);
			first.erase(first.begin() + i);
		}
	}
	return (res);
}

static void mergePairs( diit begin, diit middle, diit end ) {
	di		left(begin, middle), right(middle, end);
	diit	leftIt = left.begin(), rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end())
		*begin++ = (*leftIt <= *rightIt ? *leftIt++ : *rightIt++);

	std::copy(leftIt, left.end(), begin);
	std::copy(rightIt, right.end(), begin);
}

static void	recursiveSort( di &ns, diit begin, diit end ) {
	if (std::distance(begin, end) <= 2) {
		if (std::distance(begin, end) == 2
				&& *begin > *(begin + 1))
			std::swap(*begin, *(begin + 1));
		return ;
	}
	diit	middle = begin + (end - begin) / 2;

	recursiveSort(ns, begin, middle);
	recursiveSort(ns, middle, end);

	mergePairs(begin, middle, end);
}

static std::pair<di, di>	sortePairs( const di &ns, int i ) {
	di	smaller, bigger;

	for (dicit it = ns.begin(); it <= ns.end() - 1 - i; std::advance(it, 2)) {
		bigger.push_back(std::max(*it, *(it + 1)));
		smaller.push_back(std::min(*it, *(it + 1)));
	}
	return (std::pair<di, di>(smaller, bigger));
}

void	PmergeMe::mergeInsertSort( di &ns ) {
	if (isSorted(ns)) return ;

	bool	hasExtraElement = ns.size() % 2 == 1;
	int		reminder = 0;
	if (hasExtraElement) {
		reminder = ns.back();
		ns.pop_back();
	}

	std::pair<di, di> pairs = sortePairs(ns, hasExtraElement);

	recursiveSort(pairs.first, pairs.first.begin(), pairs.first.end());
	recursiveSort(pairs.second, pairs.second.begin(), pairs.second.end());

	pairs.second.insert(pairs.second.begin(), *pairs.first.begin());
	pairs.first.erase(pairs.first.begin());

	ns = jacobsthalInsert(pairs.first, pairs.second);

	if (hasExtraElement)
		ns.insert(std::lower_bound(ns.begin(), ns.end(), reminder), reminder);
}

vi	PmergeMe::parseArgsVector( const int &c, const char **v ) {
	vi	res;

	for (int i = 1; i < c; ++i)
		res.push_back(std::atoi(v[i]));

	return (res);
}

di	PmergeMe::parseArgsDeque( const int &c, const char **v ) {
	di	res;

	for (int i = 1; i < c; ++i)
		res.push_back(std::atoi(v[i]));

	return (res);
}

const char	*PmergeMe::OverflowException::what( void ) const throw() {
	return ("Overflow detected");
}
