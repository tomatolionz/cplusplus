#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::hex;
using std::dec;

class BigObject {

public:

	BigObject() {

		cout << "constructor. " << endl;

	}

	~BigObject() {

		cout << "destructor."<< endl;

	}

	BigObject(const BigObject&) {

		cout << "copy constructor." << endl;

	}

	BigObject(BigObject&&) {

		cout << "move constructor." << endl;

	}
	
};

BigObject foo() {

	BigObject localObj;

	return localObj;

}

BigObject foo1() {

	BigObject localObj;

	return std::move(localObj);

}

BigObject&& foo2() {

	BigObject localObj;

	return std::move(localObj);

}

int main() {

	BigObject obj = foo();
	cout << endl;
	BigObject obj1 = foo1();
	cout << endl;
	BigObject obj2 = foo2();
	cout << endl;
}