#include <algorithm>
#include <iostream>
#include "Group.h"

Group::Group()
{ }

Group::Group(std::vector<int> group)
{
	m_group = group;
	removeReprtetion();
}

void Group::readGroup()
{
	int groupSize, val;
	std::cin >> groupSize;

	for (int i = 0; i < groupSize; ++i)
	{
		std::cin >> val;
		m_group.push_back(val);
	}

	removeReprtetion();
}

void Group::removeReprtetion()
{
	std::ranges::sort(m_group);
	auto [newEnd, end] = std::ranges::unique(m_group);
	m_group.erase(newEnd, end);
}

void Group::printGroup()
{
	std::cout << "{ ";
	if (!m_group.empty())
	{
		for (int i = 0; i < m_group.size() -1; ++i)
		{
			std::cout << m_group[i] << ", ";
		}
		std::cout << m_group[m_group.size() -1];
	}
	std::cout << " }";
	
}

std::vector<int> Group::getGroupVec()
{
	return m_group;
}

Group Group::evalGroup()
{
	return m_group;
}

// this function convert the group into string
std::string Group::GroupStr()
{
	std::string str = "{ ";

	if (!m_group.empty())
	{
		for (int i = 0; i < m_group.size() - 1; ++i)
		{
			str += std::to_string(m_group[i]) + ", ";
		}
		str += std::to_string(m_group[m_group.size() - 1]);
	}
	str += +" }";

	return str;
}