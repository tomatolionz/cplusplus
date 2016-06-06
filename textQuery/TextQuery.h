#pragma once
#include "QueryResult.h"

#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

using std::vector;
using std::shared_ptr;
using std::string;
using std::map;
using std::set;

class TextQuery
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string> > file;
	map<string, shared_ptr<set<line_no> > > wm;
};