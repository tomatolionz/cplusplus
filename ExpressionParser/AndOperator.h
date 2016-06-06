#pragma once

#include <set>
#include "Operator.h"

using namespace std;

/** 
* 加法操作符处理器，支持数值相加以及字符串相加
*/ 
class AndOperator: public Operator
{
public:
	AndOperator()
	{
		priority = 2;
		dimension = 2;
	}

	virtual set<string> operate();
};