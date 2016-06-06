#pragma once
#include <ostream>

#include <vector>
#include <string>
#include <memory>
#include <set>

using std::vector;
using std::shared_ptr;
using std::string;
using std::set;

class QueryResult
{
	using line_no = vector<string>::size_type;
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no> > p, shared_ptr<vector<string> > f): sought(s), lines(p), file(f) {}
private:
	string sought;
	shared_ptr<set<line_no> > lines;
	shared_ptr<vector<string> > file;
};