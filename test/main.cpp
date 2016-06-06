#include <string>
#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <cassert>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::string;
using std::min;
using std::max;

bool isMatch(string s, string p) {
    if (p.empty())    return s.empty();

    if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
        return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
    else
        return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
}

int lengthOfLongestSubstring(string s) {
    int result = 0;
    int dict[256];
    memset(dict, -1, sizeof(dict));
    int begin = -1;
    for (int i = 0; i < s.length(); ++i) {
        char cur = s[i];
        if (dict[cur] > begin) begin = dict[cur];
        dict[cur] = i;
        result = std::max(result, i - begin);
    }
    return result;
}

int main() {

    cout << isMatch("ab","a*") << endl;

    return 0;
}



