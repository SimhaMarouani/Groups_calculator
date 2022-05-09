#pragma once
#include "Union.h"
#include "Intersection.h"
#include "Difference.h"
#include "Product.h"
#include "Composite.h"
#include <unordered_map>
#include <string>


enum class Operation
{
	uni,
	eval,
	inter,
	diff,
	prod,
	comp,
	del,
	help,
	exit
};


class Calculator
{
public:
	Calculator();
	void Calculate();

private:
	void operation(std::string operetion);
	void printList();
	void printHelpText() const;

	std::vector<std::shared_ptr<Function>> m_functionsList;
	std::unordered_map<std::string, Operation> m_function;
	std::string m_command;
};
