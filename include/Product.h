#pragma once
#include <memory>
#include "Function.h"

class Product :public Function
{
public:
	Product(const std::shared_ptr<Function> func1 = NULL, const std::shared_ptr<Function> func2 = NULL);

private:
	Group evaluate(std::string &str, Group* gr);
	std::shared_ptr<Function> getFunc1();
	std::shared_ptr<Function> getFunc2();
	void print(char& group, std::shared_ptr <Function> func1, std::shared_ptr<Function> func2);
	std::vector<int> prod(std::vector<int> grp1, std::vector<int> grp2);
};

