#include "Product.h"
#include <algorithm>
#include <iterator>
#include <iostream>


Product::Product(const std::shared_ptr<Function>func1, const std::shared_ptr<Function>func2)
{
	m_func1 = func1;
	m_func2 = func2;
}


//   (A * B)
// The function calculates the Product value of 2 groups
Group Product::evaluate(std::string &str, Group* gr)
{
	Group gr1;
	Group gr2;

	if (!m_func1 && !gr)
	{
		gr1.readGroup();
		str += "(" + gr1.GroupStr();
	}
	else if (gr)
	{
		gr1 = *gr;
		str += "(" + gr1.GroupStr();
	}
	else
	{
		gr1 = m_func1->evaluate(str, NULL);
		str += " * ";
	}

	if (!m_func2)
	{
		gr2.readGroup();
		str += " * " + gr2.GroupStr() + ")";
	}
	else
	{
		gr2 = m_func2->evaluate(str, NULL);
	}

	// calc the product
	auto result = prod(gr1.getGroupVec(), gr2.getGroupVec());

	return (Group(result));
}

std::shared_ptr<Function> Product::getFunc1()
{
	return m_func1;
}

std::shared_ptr<Function> Product::getFunc2()
{
	return m_func2;
}

// this function print the groups by character
void Product::print(char& group, std::shared_ptr <Function> func1, std::shared_ptr<Function> func2)
{
	if (m_func1 == NULL)
	{
		if (m_func2 == NULL)
		{
			std::cout << '(' << (group)++ << " * " << (group)++ << ')';
			return;
		}
		std::cout << (group)++;
	}

	std::cout << '(';

	if (m_func1)
		m_func1->print(group, func1->getFunc1(), func1->getFunc2());

	else
		std::cout << (group)++;

	std::cout << " * ";

	if (m_func2)
		m_func2->print(group, func1->getFunc1(), func1->getFunc2());

	else
		std::cout << (group)++;

	std::cout << ')';
}

// calc the product
std::vector<int> Product::prod(std::vector<int> grp1, std::vector<int> grp2)
{
	std::vector<int> result;

	for (int i = 0; i < grp1.size(); i++)
	{
		for (int j = 0; j < grp2.size(); j++)
		{
			result.push_back(grp1[i] * grp2[j]);
		}
	}

	std::ranges::sort(result);
	auto [newEnd, end] = std::ranges::unique(result);
	result.erase(newEnd, end);

	return result;
}
