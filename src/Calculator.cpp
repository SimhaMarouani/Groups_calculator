#include <iostream>
#include "Calculator.h"


Calculator::Calculator()
{
	m_function["uni"]	= Operation::uni;
	m_function["eval"]	= Operation::eval;
	m_function["diff"]	= Operation::diff;
	m_function["inter"] = Operation::inter;
	m_function["prod"]	= Operation::prod;
	m_function["comp"]	= Operation::comp;
	m_function["del"]	= Operation::del;
	m_function["help"]	= Operation::help;
	m_function["exit"]	= Operation::exit;
}

void Calculator::Calculate()
{
	m_functionsList.push_back(std::make_shared<Union>());        //(A U B)
	m_functionsList.push_back(std::make_shared<Intersection>()); //(A ^ B)
	m_functionsList.push_back(std::make_shared<Difference>());   //(A - B)
	
	printList();
	
	std::cin >> m_command;

	while (true)
	{
		operation(m_command);

		printList();
		std::cin >> m_command;
	}
}

void Calculator::printList()
{
	std::cout << "\nList of available set operations:\n";

	for (int i = 0; i < m_functionsList.size(); ++i)
	{
		char groupChar = 'A';
	
		std::cout << i << ".\t";
		m_functionsList[i]->print(groupChar, m_functionsList[i]->getFunc1(), m_functionsList[i]->getFunc2());
		std::cout << "\n";
	}
	std::cout << "\nEnter command('help' for the list of available commands): ";
}

void Calculator::operation(std::string operetion)
{
	int num1 = -1, num2 = -1;
	
	if (m_command == "uni" || m_command == "inter" || m_command == "prod" || m_command == "comp" || m_command == "diff")
	{
		std::cin >> num1 >> num2;
		if (num1 < 0 || num1 >= m_functionsList.size() || num2 < 0 || num2 >= m_functionsList.size())
		{
			std::cout << "Number of command is incorrect!\nPlease try again\n\n";
			return;
		}
	}

	if (m_command == "del" || m_command == "eval")
	{
		std::cin >> num1;
		if (num1 < 0 || num1 >= m_functionsList.size())
		{
			std::cout << "Number of command is incorrect!\nPlease try again\n\n";\
			return;
		}
	}

	if (!m_function.contains(operetion))
	{
		std::cout << "Command not found!\nPlease try again\n\n";
		return;
	}

	switch (m_function[operetion])
	{
	case Operation::uni:
		
		m_functionsList.push_back(std::make_shared<Union>(m_functionsList[num1], m_functionsList[num2]));
		break;

	case Operation::eval:
	{
		std::string strFunc = "";
		Group grp = m_functionsList[num1]->evaluate(strFunc, NULL);
		strFunc += " = " + grp.GroupStr();
		std::cout << strFunc;
		std::cout << '\n';
		break;
	}
	case Operation::inter:
		m_functionsList.push_back(std::make_shared<Intersection>(m_functionsList[num1], m_functionsList[num2]));
		break;

	case Operation::diff:
		m_functionsList.push_back(std::make_shared<Difference>(m_functionsList[num1], m_functionsList[num2]));
		break;

	case Operation::prod:
		m_functionsList.push_back(std::make_shared<Product>(m_functionsList[num1], m_functionsList[num2]));
		break;
		
	case Operation::comp:
		m_functionsList.push_back(std::make_shared<Composite>(m_functionsList[num1], m_functionsList[num2]));
		break;

	case Operation::del:	
		m_functionsList.erase(m_functionsList.begin() + num1);
		break;

	case Operation::help:	
		printHelpText();
		break;
			
	case Operation::exit:	
		std::cout << "\nGoodbye\n";
		exit(EXIT_SUCCESS);
	}
}

void Calculator::printHelpText() const
{
	std::cout << "The available commands are:\n\n"
		" * eval(uate) num ... - compute the result of function #num on the following\n"
		"   set(s); each set is prefixed with the count of numbers to read\n\n"
		" * uni(on) num1 num2 - Creates an operation that is the union of operation\n"
		"   #num1 and operation #num2\n\n"
		" * inter(section) num1 num2 - Creates an operation that is the intersection\n"
		"   of operation #num1 and operation #num2\n\n"
		" * diff(erence) num1 num2 - Creates an operation that is the difference of\n"
		"   operation #num1 and operation #num2\n\n"
		" * prod(uct) num1 num2 - Creates an operation that returns the product of\n"
		"   the items from the results of operation #num1 and operation #num2\n\n"
		" * comp(osite) num1 num2 - creates an operation that is the composition of\n"
		"   operation #num1 and operation #num2\n\n"
		" * del(ete) num - delete operation #num from the operation list\n\n"
		" * help - print this command list\n\n"
		" * exit - exit the program\n";
}
