#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Group.h"

class Function
{
public:
	Function();
	virtual ~Function() = default;
	virtual Group evaluate(std::string &str, Group* gr) = 0;
	virtual std::shared_ptr<Function> getFunc1() = 0;
	virtual std::shared_ptr<Function> getFunc2() = 0;
	virtual void print(char& group, std::shared_ptr <Function> func1, std::shared_ptr<Function> func2) = 0;

protected:
	std::shared_ptr<Function> m_func1;
	std::shared_ptr<Function> m_func2;
};
