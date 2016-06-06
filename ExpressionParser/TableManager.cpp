#include <iostream>
#include "TableManager.h"
#include "AndOperator.h"
#include "OrOperator.h"
#include "NotOperator.h"


using namespace std;

//外部初始化 before invoke main
// const TableManager* TableManager::instance = new TableManager;

Operator* TableManager::getOperator(const string& identifier)
{
	if (identifier == "&")
	{
		return (new AndOperator);
	}
	else if (identifier == "|")
	{
		return (new OrOperator);
	}
	else if (identifier == "!")
	{
		return (new NotOperator);
	}

	return NULL;
}

bool TableManager::isOperator(const string& identifier)
{
	if(getOperator(identifier))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int TableManager::getPriority(const string& identifier)
{
	Operator* oper = getOperator(identifier);

	if(oper)
	{
		return oper->getPriority();
	}
	else
	{
		return -1;
	}
}

int TableManager::getDimension(const string& identifier)
{
	Operator* oper = getOperator(identifier);

	if(oper)
	{
		return oper->getDimension();
	}
	else
	{
		return -1;
	}
}

TokenType TableManager::getTokenType(const string& identifier)
{
	if (isOperator(identifier))
	{
		return OPERATOR;
	}

	return NONSYMBOl;
}

bool TableManager::isSymbol(const string& identifier)
{
	//是否为括号、操作符
	if (identifier == "(" || identifier == ")" || isOperator(identifier))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TableManager::isHighPriority(const string& oper1, const string& oper2)
{
	return (getPriority(oper1) >= getPriority(oper2));
}