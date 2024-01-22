/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:02:07 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/22 15:02:20 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "MutantStack.hpp"

int	main(void) {
	std::cout << "\nTest from subject" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
	}
	std::cout << "\nTest 2, const test" << std::endl;
	{
		MutantStack<float>	m;

		for (int i = 1; i <= 9; i++)
			m.push(i * 111);

		MutantStack<float>::const_iterator it = m.begin();
		MutantStack<float>::const_iterator ite = m.end();

		while (it <= ite)
			std::cout << "First: " << *it++ << ", Last: " << *--ite << std::endl;

		std::cout << "\nTest 3, deep copy test" << std::endl;
		{
			std::cout << "\ncpy constructor operator:" << std::endl;
			{
				const MutantStack<float>	m2(m);

				MutantStack<float>::const_iterator m2it = m.cbegin();
				MutantStack<float>::const_iterator m2ite = m.cend();

				while (m2it <= m2ite)
			 		std::cout << "First: " << *m2it++ << ", Last: " << *--m2ite << std::endl;
			}
			std::cout << "\nassignment operator:" << std::endl;
			{
				MutantStack<float>	m3;
				m3 = m;

				MutantStack<float>::const_iterator m3it = m.cbegin();
				MutantStack<float>::const_iterator m3ite = m.cend();

				while (m3it <= m3ite)
					std::cout << "First: " << *m3it++ << ", Last: " << *--m3ite << std::endl;
			}
		}
	}
	std::cout << "\nTest 4: reverse_iterator test" << std::endl;
	{
		MutantStack<float>	m;

		for (int i = 1; i <= 8; i++)
			m.push(i * 111);

		MutantStack<float>::reverse_iterator it = m.rbegin();
		MutantStack<float>::reverse_iterator ite = m.rend();

		while (it != ite)
			std::cout << "First: " << *it++ << ", Last: " << *--ite << std::endl;
	}
	std::cout << "\nTest 5: const_reverse_iterator test" << std::endl;
	{
		MutantStack<float>	m;

		for (int i = 1; i <= 8; i++)
			m.push(i * 111);

		MutantStack<float>::const_reverse_iterator it = m.crbegin();
		MutantStack<float>::const_reverse_iterator ite = m.crend();

		while (it != ite)
			std::cout << "First: " << *it++ << ", Last: " << *--ite << std::endl;
	}

	return (0);
}