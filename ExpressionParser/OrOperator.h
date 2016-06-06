#pragma once

#include <set>
#include "Operator.h"

using namespace std;

/** 
* 加法操作符处理器，支持数值相加以及字符串相加
*/ 
class OrOperator: public Operator
{
public:
	OrOperator()
	{
		priority = 1;
		dimension = 2;
	}

	virtual set<string> operate();
};