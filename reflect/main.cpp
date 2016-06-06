#include <iostream>

using std::cout;
using std::endl;

class A {
private:
    int a_;

public:
    A(int a):a_(a){}
    void run(int data);

};

void A::run(int data) {

    cout<<data<<endl;
    cout<<a_<<endl;
}

typedef void(A::*func)(int data); 
typedef void(*funcc)(const A*, int data);

int main(int argc, char** argv) {

    func p = &A::run;
    int* dp = (int*)(reinterpret_cast<void*>(p));
    cout<<dp<<endl;

    A a(6666);
        //A* ptr = NULL;
    funcc f = (funcc)(dp);
    f(&a, 100);
        //f(ptr, 8888);   // 将输出8888, 但输出a_时肯定出错

        return 0;  
}