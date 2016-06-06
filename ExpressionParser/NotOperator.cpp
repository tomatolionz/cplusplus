#include "NotOperator.h"

using namespace std;

set<string> NotOperator::operate()
{
	set<string> operResult;

	if (operands.size() != dimension)
	{
		return operResult;
	}

	set_difference(universalSet.begin(), universalSet.end(), operands[0].begin(), operands[0].end(), 
		insert_iterator<set<string> >(operResult, operResult.begin()));

	return operResult;
}