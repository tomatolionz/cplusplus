#include <stack>
#include <string>
#include <iostream>
#include "ExpressionParser.h"
#include "TableManager.h"
#include "TreeNode.h"

using namespace std;

set<string> ExpressionParser::computeExpression(const string& expr)
{
	set<string> result;
	if(expr.empty())
	{ 
		return result;
	}
	// 构造表达式树
	TreeNode* tree = buildTree(expr);
	if(tree == NULL)
	{
		return result;
	}

	// 解析计算表达式树
	//result = computeSubTree(tree);

	return result;
}

set<string> ExpressionParser::computeSubTree(TreeNode *node)
{
	set<string> subResult;
	if(node == NULL)
	{
		return subResult;
	}

	TokenType type = node->getNodeType();

	if(type == NONSYMBOl)
	{
		//return computeValue(node->data);
		return subResult;
	}

	vector<TreeNode*> children = node->getChildren();

	vector<set<string> > operands;
	vector<TreeNode*>::iterator it = children.begin();
	while(it != children.end())
	{
		operands.push_back(computeSubTree(*it));
	}

	Operator *op = TableManager::getOperator(node->getData());

	if(op != NULL)
	{
		op->setOperands(operands);
		op->setUniversalset(universalSet);

		subResult = op->operate();
	}

	return subResult;
}

TreeNode* ExpressionParser::buildTree(string expression)
{
	vector<string> postExpr = buildPostExpressionStack(expression);
	//test
	//输出结果
	printPostExpression(postExpr);
	stack<TreeNode*> nodeStack;

	vector<string>::iterator it = postExpr.begin();
	while(it != postExpr.end())
	{ 
		string token = *it; 
		TreeNode* node = new TreeNode(); 
		TokenType nodeType = TableManager::getTokenType(token);
		node->setData(token);
		node->setNodeType(nodeType); 
		if(nodeType == OPERATOR)
		{
			//操作符处理
			//
			int dimension = TableManager::getDimension(token);
			// vector<TreeNode*> children;
			for(int i = dimension - 1; i >= 0; i--)
			{
				node->addChild(nodeStack.top());
				// children.push_back(nodeStack.top());
				nodeStack.pop();
			}
			// node->setChildren(children);
			nodeStack.push(node);
		}
		else
		{
			//操作数处理
			//
			nodeStack.push(node);
		}

		it++;
	}

	TreeNode *root = nodeStack.top();
	nodeStack.pop();

	//test
	//输出结果
	TreeNode::printTree(root);

	return root;
}

/**
 * 
 */
 vector<string> ExpressionParser::buildPostExpressionStack(const string& expression)
 {
 	vector<string> postExpr;
 	stack<string> tmpStack;

 	int iPointer = 0;

 	string expr = expression;
 	//trim(expr);

 	while(iPointer < expr.length())
 	{ 
		// 词法分析，得到单词
 		string token = getToken(expr, iPointer);
 		int step = token.length();

 		trim(token);

 		if (token == "")
 		{
 			iPointer += step;
			continue; 			
 		}
 		else if (token == "(")
 		{
 			tmpStack.push(token); 
 		}
 		else if (token == ")")
 		{
 			while(!tmpStack.empty() && tmpStack.top() != "(")
			{
				//弹出直到开括号
				postExpr.push_back(tmpStack.top());
				tmpStack.pop();
			}
			if (!tmpStack.empty() && tmpStack.top() == "(")
			{
				tmpStack.pop();
			}
 		}
 		else if (TableManager::isOperator(token))
 		{
 			if (tmpStack.empty())
 			{
				//临时栈为空，压入操作符
				tmpStack.push(token);
			}
			else
			{
				//弹出栈中操作符直到栈顶操作数优先级低于当前读入操作数
				while(!tmpStack.empty() && TableManager::isHighPriority(tmpStack.top(), token))
	 			{ 
	 				postExpr.push_back(tmpStack.top());
	 				tmpStack.pop();
	 			}
	 			//压入当前读入操作符
	 			tmpStack.push(token);
			}
 		}
 		else
 		{ 
 			postExpr.push_back(token); 
 		}

 		iPointer += step;
 	}

 	//把栈中剩余的操作符依次弹出
 	while(!tmpStack.empty())
	{
		postExpr.push_back(tmpStack.top());
		tmpStack.pop();
	}

 	return postExpr; 
 }

 void ExpressionParser::printPostExpression(vector<string> postExpr)
 {
 	vector<string>::iterator it = postExpr.begin();
 	while(it != postExpr.end())
 	{
 		cout << *it++;
 	}
 	cout << endl;
 }

/**
 * 获取一个单词
 * @param  expr     表达式，暂不支持转义字符
 * @param  iPointer [description]
 * @return          去无效空格
 */
string ExpressionParser::getToken(const string& expr, const int& iPointer)
{
	if (expr.length() == 0)
	{
		return "";
	}

	int length = 0;
	while(iPointer + length <= expr.length())
	{
		//取出一个字符
		//判断是否为符号
		if (TableManager::isSymbol(expr.substr(iPointer + length, 1)))
		{
			//length=0 为符号， >0 为非符号串结束
			if (length == 0)
			{
				length++;
			}

			break;
		}
		else
		{
			length++;
		}
	}

	return (expr.substr(iPointer, length));
}

/**
 * 去除字符串前后空格
 * @param  s [description]
 * @return   [description]
 */
string& ExpressionParser::trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);

    return s;
}