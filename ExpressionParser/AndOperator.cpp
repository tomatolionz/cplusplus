#include "AndOperator.h"

using namespace std;

set<string> AndOperator::operate()
{
	set<string> operResult;

	if (operands.size() != dimension)
	{
		return operResult;
	}

	set_intersection(operands[0].begin(), operands[0].end(), operands[1].begin(), operands[1].end(), 
		insert_iterator<set<string> >(operResult, operResult.begin()));

	return operResult;
}