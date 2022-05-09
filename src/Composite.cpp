#include "Composite.h"
#include <algorithm>
#include <iterator>
#include <iostream>

Composite::Composite(const std::shared_ptr<Function>func1, const std::shared_ptr<Function>func2)
{
	m_func1 = func1;
	m_func2 = func2;
}

// ((A U B) * C)
// (A U B) -> (D * C)
// The function Composite 2 function
Group Composite::evaluate(std::string &str, Group* gr)
{
	auto grp0 = m_func1->evaluate(str, NULL);
	str += " -> ";
	return m_func2->evaluate(str, &grp0);
}

std::shared_ptr<Function> Composite::getFunc1()
{
	return m_func1;
}

std::shared_ptr<Function> Composite::getFunc2()
{
	return m_func2;
}

// this function print the groups by character
void Composite::print(char& group, std::shared_ptr <Function> func1, std::shared_ptr<Function> func2)
{
	if (m_func1 == NULL)
	{
		if (m_func2 == NULL)
		{
			std::cout << '(' << (group)++ << " -> " << (group)++ << ')';
			return;
		}
		std::cout << (group)++;
	}

	std::cout << '(';

	if (m_func1)
		m_func1->print(group, func1->getFunc1(), func1->getFunc2());

	else
		std::cout << (group)++;

	std::cout << " -> ";

	if (m_func2)
		m_func2->print(group, func1->getFunc1(), func1->getFunc2());

	else
		std::cout << (group)++;

	std::cout << ')';
}