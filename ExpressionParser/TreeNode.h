#pragma once

#include <vector>
#include <iostream>
#include "TokenType.h"

using namespace std;

class TreeNode
{
protected:
	string data;
	TokenType nodeType;
	vector<TreeNode*> children;

public:
	TreeNode()
	{
		data = "";
		nodeType = NONSYMBOl;
		children.clear();
	}

	string getData()
	{
		return data;
	}

	TokenType getNodeType()
	{
		return nodeType;
	}

	const vector<TreeNode*>& getChildren()
	{
		return children;
	}

	void setData(string str)
	{
		data = str;
	}

	void setNodeType(const TokenType& type)
	{
		nodeType = type;
	}

	void setChildren(const vector<TreeNode*>& childVec)
	{
		children = childVec;
	}

	void addChild(TreeNode* child)
	{
		children.push_back(child);
	}

	static void printTree(TreeNode* root, int lvl = 0)
	{
		cout << string(lvl*4, ' ') << root->data << " ";

		vector<TreeNode*> childVec = root->children;
		vector<TreeNode*>::iterator it = childVec.begin();

		cout << endl;
		while(it != childVec.end())
		{
			printTree(*it++, lvl + 1);
		}
	}
};