#pragma once

#include <set>
#include <string>
#include "Operator.h"

using namespace std;

/** 
* 加法操作符处理器，支持数值相加以及字符串相加
*/ 
class NotOperator: public Operator
{
public:
	NotOperator()
	{
		priority = 3;
		dimension = 1;
	}

	virtual set<string> operate();
};