#include "TextQuery.h"
#include <fstream>
#include <iostream>
#include <unistd.h>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);

    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        // ofstream ofile("/Users/zhoulei/Documents/TomatoProjects/textQuery/Debug/result");
        print(cout, tq.query(s)) << endl;
        // print(ofile, tq.query(s)) << endl;
        // ofile.close();
    }
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}

// int main()
// {
//     string something;
//     while (true)
//     {
//         cout << "please input something: ";

//         if (!(cin >> something) || something == "q")
//             break;
//         cout << something << endl;
//     }

//     return 0;
// }

int main()
{
    char buf[80];
    getcwd(buf, sizeof(buf));
    cout << buf << endl;

    ifstream in("/Users/zhoulei/Documents/TomatoProjects/textQuery/Debug/fileTomato");

    if(!in)
    {
        cout << " can not open the file" << endl;
        return -1;
    }


    runQueries(in);

    return 0;
}