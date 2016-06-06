#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include "unittest.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::hex;
using std::dec;
using namespace std::placeholders;

string concat(const string &a, const string &b)
{
	return a + b;
}

TEST_CASE(concat)
{
	TEST_ASSERT(concat("a", "b")=="ab");
	TEST_ASSERT(concat("a", "")=="a");
	TEST_ASSERT(concat("", "b")=="b");
	TEST_ASSERT(concat("", "")=="1");
	cout << "test cases pass!" << endl;
}

int main()
{
	return 0;
}