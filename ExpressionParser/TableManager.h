#pragma once

#include <map>
#include "Operator.h"
#include "TokenType.h"

using namespace std;

class TableManager
{
private:
    // static const TableManager* instance;
    TableManager(){}
public:
    // static const TableManager* getInstance()
    // {
    //     return instance;
    // }

    /**
     * 判断是否是操作符
     * @param  identifier [description]
     * @return            [description]
     */
	static bool isOperator(const string& identifier);

    /**
     * 取得操作符优先级
     * @param  identifier 操作符字符串
     * @return            优先级，-1表示输入不是操作符
     */
	static int getPriority(const string& identifier);

    /**
     * 取得操作符定义的操作数个数
     * @param  identifier 操作符字符串
     * @return            操作数个数，-1表示输入不是操作符
     */
 	static int getDimension(const string& identifier);

 	/**
     * 取得单词类型
     * @param  identifier 单词
     * @return            单词类型
     */
 	static TokenType getTokenType(const string& identifier);

 	// 根据标示符号字符串取得操作符（工厂）
 	static Operator* getOperator(const string& identifier);

    /**
     * 判断是否为符号
     * @param  identifier 单词
     * @return            判断结果
     */
 	static bool isSymbol(const string& identifier);

    /**
     * 比较操作符优先级
     * @param  oper1 操作符
     * @param  oper2 操作符
     * @return       优先级是否高
     */
    static bool isHighPriority(const string& oper1, const string& oper2);
};