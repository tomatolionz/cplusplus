// #include <stdlib.h>
#include <cctype>
#include <stdio.h>
// #include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cassert>
#include <fstream>
#include <functional>
#include <iterator>
#include <memory>

// using namespace std::placeholders;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::flush;
using std::ends;
using std::runtime_error;
using std::ostream_iterator;
using std::shared_ptr;
using std::make_shared;

/*
   这个函数是把浮点数字符串转换为浮点数的函数。
   函数将会跳过字符串中的空格字符和不是'+'、'-'、'.'、
   数字的字符。如果字符串是空的或者都是由空格组成，将不会
   做任何转换，仅仅是把字符串的结束地址赋给endptr。如果字
   符串合法，将会进行转换，并把字符串最后的NULL的地址给
   endptr。如果你想使用endptr参数，那么赋一个NULL值就
   可以了。
*/
   double my_strtod(const char* s, char** endptr)
   {
    register const char*  p     = s;
    register long double  value = 0.L;
    int                   sign  = 0;
    long double           factor;
    unsigned int          expo ;

    while ( isspace(*p) )//跳过前面的空格
      p++;

  if(*p == '-' || *p == '+')
      sign = *p++;//把符号赋给字符sign，指针后移。

   //处理数字字符

    while ( (unsigned int)(*p - '0') < 10u )//转换整数部分
      value = value*10 + (*p++ - '0');
   //如果是正常的表示方式（如：1234.5678）
  if ( *p == '.' )
  {
      factor = 1.;
      p++;
      while ( (unsigned int)(*p - '0') < 10u )
      {
         factor *= 0.1;
         value  += (*p++ - '0') * factor;
     }
 }
   //如果是IEEE754标准的格式（如：1.23456E+3）
 if ( (*p | 32) == 'e' )
 {
    expo   = 0;
    factor = 10.L;
    switch (*++p)
    {
      case '-':
      factor = 0.1;
      case '+':
      p++;
      break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      break;
      default :
      value = 0.L;
      p     = s;
      goto done;
  }
  while ( (unsigned int)(*p - '0') < 10u )
      expo = 10 * expo + (*p++ - '0');
  while ( 1 )
  {
      if ( expo & 1 )
         value *= factor;
     if ( (expo >>= 1) == 0 )
      break;
  factor *= factor;
}
}
done:
if ( endptr != 0 )
  *endptr = (char*)p;

return (sign == '-' ? -value : value);
}

double my_atof(char *str)
{
 return my_strtod(str,0);
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

// class StrBlob
// {
// public:
//     typedef vector<string>::size_type size_type;
//     StrBlob();
//     StrBlob(std::initializer_list<string> il);
//     size_type size() const { return data->size(); }
//     bool empty() const { return data->empty(); }

//     void push_back(const string &t) { data->push_back(t); }
//     void pop_back();
//     string& front();
//     string& back();

// private:
//     shared_ptr<vector<string>> data;
//     void check(size_type i, const string &msg) const;
// };

int main()
{
    shared_ptr<string> p(new string("hello"));
    cout << p.use_count() << endl;
    cout << *p << endl;
    auto q(p);
    cout << p.use_count() << endl;
    if (!q.unique())
    {
        q.reset(new string(*q));
    }
    cout << p.use_count() << endl;
    *q += " world";
    cout << *p << endl;
    cout << *q << endl;
    p = nullptr;
    cout << p.use_count() << endl;

    //std::shared_ptr<int> p = std::make_shared<int>();
    // int a = 10;
    // auto p = make_shared<int>(a);

    // cout << *p << endl;
    // cout << p.use_count() << endl;
    // auto q = p;
    // cout << p.use_count() << endl;
    // p = make_shared<int>();
    // cout << p.use_count() << endl;"auto_save_on_modified": false,
    

    // string str("C++, Java, PHP, C#, go, ruby");
    // auto comma = find(str.begin(), str.end(), ',');
    // cout << string(str.begin(), comma) << endl;
    // auto rcomma = find(str.rbegin(), str.rend(), ',');
    // cout << string(str.rbegin(), rcomma) << endl;
    // cout << string(rcomma.base(), str.end()) << endl;

    

    // ostream_iterator<int> out_iter(cout, "\n");
    // int a[] = { 10, 20, 30, 40, 50, 10, 20, 30, 40, 50, 10, 20, 30, 40, 50, 10, 20, 30, 40, 50 };
    // vector<int> vec(a, a + sizeof(a)/sizeof(int));

    // // for(auto e : vec)
    // // {
    // //     *out_iter++ = e;
    // // }
    
    // copy(vec.begin(), vec.end(), out_iter); 
    

    // char * str = "12345.6789";
    // printf("%f\n",my_strtod(str,0));
    // printf("%f\n",my_atof(str));

    // str = "-12345.6789";
    // printf("%f\n",my_strtod(str,0));
    // printf("%f\n",my_atof(str));

    // str = "9.8546721E+4";
    // printf("%f\n",my_strtod(str,0));
    // printf("%f\n",my_atof(str));

    // str = "-985467.21e-4";
    // printf("%f\n",my_strtod(str,0));
    // printf("%f\n",my_atof(str));

  // char str[8];
  // cin.getline(str, 5);
  // cout << str << endl;
  // cin.getline(str, 5);
  // cout << str << endl;
  // 

  // char str1[10], str2[10];
  // cin >> str1;
  // cin >> str2;
  // cout << str1 << endl;
  // cout << str2 << endl;

  // vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  // vector<string> v2 = {"1", "2", "3"};
  // vector<int> v(5, 2);
  // for (auto i : v)
  // {
  //   cout << i << endl;
  // }

  // auto it = v.end() - 1;
  // *it = 10;

  // for (auto i : v)
  // {
  //   cout << i << endl;
  // }

  // cout << endl << v[v.size() - 1] << endl;

  // int a[] = {1, 2, 3, 4, 5};
  // for (auto i : v)
  // {
  //   cout << i << endl;
  // }

  // cerr << "a o!" << endl;

  // throw runtime_error("Throw a exception!");

    // try
    // {
    //     int a = 1;
    //     int b = 0;
    //     cout << a/b << endl;
    //     // throw runtime_error("Throw a exception!");
    // }
    // catch (const runtime_error& e)
    // {
    //     cerr << e.what() << endl;
    // }
    // catch (const std::overflow_error& e)
    // {
    //     cerr << e.what() << endl;
    // }
    // catch (const std::exception& e)
    // {
    //     cerr << e.what() << endl;
    // }

    // cout << "file name = " << __FILE__ << endl;
    // cout << "line No = " << __LINE__ << endl;
    // cout << "time = " << __TIME__ << endl;
    // cout << "date = " << __DATE__ << endl;

    // assert(0);
    // string str;
    // while (cin >> str)
    // {
    //     cout << "print: " << str << ends;
    // }
    // 
    // ofstream out("file", ofstream::in);
    // out << "Hello World!";
    // out.close();

    // ifstream in("file");
    // string str;
    // in >> str;
    // cout << str << endl;

    // vector<int> vec;
    // vec.push_back(1);
    // fill_n(back_inserter(vec), 10, 0);

    // int a[] = { 10, 20, 30, 40, 50, 10, 20, 30, 40, 50, 10, 20, 30, 40, 50, 10, 20, 30, 40, 50 };
    // cout << sizeof(a)/sizeof(int) << endl;
    // vector<int> vec(a, a + sizeof(a)/sizeof(int));

    // for(auto i = vec.begin(); i != vec.end(); i++)
    // {
    //     cout << *i << endl;
    // }

    // for (auto i : vec)
    // {
    //     cout << i << endl;
    // }

    // for_each (vec.begin(), vec.end(), [] (const string &s) { cout << s << endl; });
    // auto f = [] { return 32; };
    // cout << f() << endl;

    // auto it = find(vec.begin(), vec.end(), 30);

    // if(it != vec.end())
    // {
    //     cout << "find " << *it << endl;
    // }
    // else
    // {
    //     cout << "can not find " << *it << endl;
    // }

    // cout << count(vec.begin(), vec.end(), 10) << endl;

    // cout << search_n(vec.begin(), vec.end(), 1, 30) - vec.begin() << endl;

    // cout << *min_element(vec.begin(), vec.end()) << endl;

    // int target[] = { 50, 60, 40 };

    // cout << search(vec.begin(), vec.end(), target, target + 2) - vec.begin() << endl;

    // auto check = bind(check_size, _1, 6);

    return 0;
}