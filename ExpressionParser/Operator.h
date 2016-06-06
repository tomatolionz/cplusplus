#pragma once

#include <vector>
#include <set>
#include <string>

using namespace std;

class Operator
{
protected:
	int priority;
	int dimension;
	vector<set<string> > operands;
	set<string> universalSet;
		
public:
	Operator() {}
	int getPriority() {return priority;}

	int getDimension() {return dimension;}

	void setOperands(vector<set<string> > operandVec) {operands = operandVec;}

	void setUniversalset(const set<string>& uSet)
	{
		universalSet = uSet;
	}
	
	virtual set<string> operate() = 0;
};