#include <memory>

class A
{
public:
    static A* create() { return new A(); }
    void destroy() { delete this; }

protected:
    A() {}
    ~A() {}
    
};

class B
{
public:
    B() {}
    ~B() {}

private:
    void* operator new(size_t t) {}
    void operator delete(void* p) {}
    
};

int main()
{
    // A a;
    //A *pa = new A();
    // delete pa;

    A *pa = A::create();
    pa->destroy();

    // B *pb = new B();
    // delete pb;
    B b;


    return 0;
}