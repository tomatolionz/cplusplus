#include <iostream>

using std::string;
using std::cout;
using std::endl;

class HasPtr
{
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const string& s = string()): a(0), str(new string(s)) {}
    //析构函数
    ~HasPtr()
    {
        delete str;
    }
    //拷贝构造函数
    HasPtr(const HasPtr& hp): a(hp.a), str(new string(*hp.str)) {}
    //拷贝赋值运算符
    //

    HasPtr& operator =(const HasPtr& hp)
    {
        // if (&hp == this)
        // {
        //     return *this;
        // }
        // delete str;
        // a = hp.a;
        // str = new string(*hp.str);
    
        string *newStr = new string(*hp.str);
        delete str;
        a = hp.a;
        str = newStr;

        return *this;
    }

    string getStr() { return *str; }

private:
    int a;
    string *str;
};

void swap(HasPtr& hp1, HasPtr &hp2)
{
    std::swap(hp1.a, hp2.a);
    std::swap(hp1.str, hp2.str);
}

class HasPtr2
{
public:
    HasPtr2(const string& s = string()): a(0), str(new string(s)), use(new size_t(1)) {}
    HasPtr2(const HasPtr2& hp): a(0), str(hp.str), use(hp.use) { ++*hp.use; }
    ~HasPtr2()
    {
        if (--*use == 0)
        {
            delete str;
            delete use;
        }
    }

    HasPtr2& operator =(const HasPtr2& hp)
    {
        ++*hp.use;
        if (--*use == 0)
        {
            delete str;
            delete use;
        }
        a = hp.a;
        str = hp.str;
        use = hp.use;

        return *this;
    }

    string getStr() { return *str; }
    
private:
    int a;
    string *str;
    //引用计数器
    size_t *use;
};

int main()
{

    HasPtr hp("hello");
    HasPtr hp1("world");
    hp1 = hp1;
    swap(hp1, hp);
    cout << hp.getStr() << endl;

    HasPtr2 hp2("hello");
    HasPtr2 hp3("world");
    hp3 = hp2;
    cout << hp3.getStr() << endl;

    return 0;
}