#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

class Base {
private:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
	int a = {137};
	int b = {279};
	int c = {397};
	long d = {1314};
};

int main()
{
	typedef void(*Fun)();
	Base b;
	Fun pFun = nullptr;
	cout << "虚函数表地址："  << std::hex << *(long*)(&b) << endl;
	cout << "虚函数表 — 第一个函数地址：" << (long*)(*(long*)(&b)) << endl; 
	pFun = (Fun)(*((long*)(*((long*)(&b)))+0));
	pFun();
	pFun = (Fun)(*((long*)(*((long*)(&b)))+1));
	pFun();
	pFun = (Fun)(*((long*)(*((long*)(&b)))+2));
	pFun();
	cout << std::dec << (int)(*((long*)(&b)+1)) << endl;
	cout << std::dec << (((long)(*((long*)(&b)+1))) >> 32) << endl;
	cout << std::dec << (int)(*((long*)(&b)+2)) << endl;
	cout << std::dec << (long)(*((long*)(&b)+3)) << endl;

	return 0;
}