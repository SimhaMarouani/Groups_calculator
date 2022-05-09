#pragma once
#include <vector>
#include <string>

class Group
{
public:
	Group();
	Group(std::vector<int> group);
	void printGroup();
	std::vector<int> getGroupVec();
	Group evalGroup();
	auto begin() const { return m_group.begin(); }
	auto end() const { return m_group.end(); }
	void readGroup();
	std::string GroupStr();

private:
	void removeReprtetion();
	
	std::vector <int> m_group;
};
