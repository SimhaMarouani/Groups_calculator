#include "Difference.h"
#include <algorithm>
#include <iterator>
#include <iostream>


Difference::Difference(const std::shared_ptr<Function>func1, const std::shared_ptr<Function>func2)
{
	m_func1 = func1;
	m_func2 = func2;
}

//   (A U B)
// The function calculates the Difference value of 2 groups
Group Difference::evaluate(std::string &str, Group* gr)
{
	Group gr1;
	Group gr2;

	if (!m_func1 && !gr)
	{
		gr1.readGroup();
		str += "(" + gr1.GroupStr(); // add the group to the string we print
	}

	else if (gr)
	{
		gr1 = *gr;
		str += "(" + gr1.GroupStr();
	}

	else
	{
		gr1 = m_func1->evaluate(str, NULL);
		str += " - ";
	}

	if (!m_func2)
	{
		gr2.readGroup();
		str += " - " + gr2.GroupStr() + ")";
	}
	else
	{
		gr2 = m_func2->evaluate(str, NULL);
	}

	auto result = std::vector<int>();
	// calc the difference
	std::ranges::set_difference(gr1.getGroupVec(), gr2.getGroupVec(), std::back_inserter(result));

	return (Group(result));
}

std::shared_ptr<Function> Difference::getFunc1()
{
	return m_func1;
}

std::shared_ptr<Function> Difference::getFunc2()
{
	return m_func2;
}

// this function print the groups by character
void Difference::print(char& group, std::shared_ptr <Function> func1, std::shared_ptr<Function> func2)
{
	if (m_func1 == NULL)
	{
		if (m_func2 == NULL)
		{
			std::cout << '(' << (group)++ << " - " << (group)++ << ')';
			return;
		}
		std::cout << (group)++;
	}

	std::cout << '(';

	if (m_func1)
		m_func1->print(group, func1->getFunc1(), func1->getFunc2());
	else
		std::cout << (group)++;

	std::cout << " - ";

	if (m_func2)
		m_func2->print(group, func1->getFunc1(), func1->getFunc2());
	else
		std::cout << (group)++;

	std::cout << ')';
}
