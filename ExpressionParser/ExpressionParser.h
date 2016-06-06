#pragma once

#include <stack>
#include <set>
#include <string>
#include "TreeNode.h"

using namespace std;

class ExpressionParser
{
public:
	/** 
	 * 计算表达式。 通过递归解析计算表达式树得到计算结果。
	 * @param expr 输入表达式
	 * @return 计算结果
	 */ 
	 set<string> computeExpression(const string& expr);

	 void setUniversalSet(set<string> uSet)
	 {
	 	universalSet = uSet;
	 }

protected:
	set<string> universalSet;
	/** 
	* 解析计算表达式子树
	* @param node 子树根节点
	* @return 子树计算结果
	*/ 
	set<string> computeSubTree(TreeNode *node);

	/**
	 * 构造表达式树。首先通过词法分析构造表达式栈，然后构造表达式树
	 * @param  expr 输入表达式
	 * @return      表达式树
	 */
 	TreeNode* buildTree(string expression);

	/**
	 * 构造后缀表达式栈
	 * @param expr 输入表达式
	 * @return     由各个单词构成的表达式栈
	 */
	vector<string> buildPostExpressionStack(const string& expression);

	string getToken(const string& expr, const int& iPointer);

	string& trim(string& s);

 	static void printPostExpression(vector<string> postExpr);
};