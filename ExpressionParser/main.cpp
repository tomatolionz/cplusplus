#include <iostream>
#include <string>
#include "ExpressionParser.h"
#include "TableManager.h"

using namespace std;

int main()
{
	ExpressionParser parser;

	//!(告警编号=‘1006’)&(告警编号=‘1007’)&(告警编号=‘10024’AND告警值=‘255')

	string expr = " !( 告警编号=‘1006’ ) & ( 告警编号=‘1007’ ) & ( 告警编号=‘10024’ AND 告警值=‘255' ) ";
	// !a & (b | (c | d) &  e)
	//a!bcd|e&|&
	//string expr = " !a & (b | (c | d) &  e)";
	//string expr = " !a";
	
	cout << expr << endl;
	parser.computeExpression(expr);

	return 0;
}