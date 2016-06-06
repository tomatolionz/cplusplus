#include "OrOperator.h"

using namespace std;

set<string> OrOperator::operate()
{
	set<string> operResult;

	if (operands.size() != dimension)
	{
		return operResult;
	}

	set_union(operands[0].begin(), operands[0].end(), operands[1].begin(), operands[1].end(), 
		insert_iterator<set<string> >(operResult, operResult.begin()));

	return operResult;
}