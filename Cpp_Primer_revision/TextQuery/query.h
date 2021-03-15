#ifndef QUERY_H
#define QUERY_H

#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>

class QueryResult;

class TextQuery{
friend class QueryResult;
public:
	TextQuery(std::ifstream &);
	
	QueryResult& query(const std::string &);
private:
	std::shared_ptr<std::vector<std::string>> lines {"line zero"};
	std::map<std::string, std::set<unsigned>> foundAt;
};

class QueryResult{
public:
	QueryResult(TextQuery& a) : lines(a.lines), lineNo(a.foundAt.second) {}
	
private:
	std::shared_ptr<std::vector<std::string>> lines;
	std::set<unsigned> lineNo;
}

TextQuery::TextQuery (std::ifstream &fin) 
{
	std::string line;
	unsigned no = 0;
	while(std::getline(fin, line)){
		lines->push_back(fin);
		std::isstringstream iss (line);
		std::string word;
		while(iss >> word){
			map[word].insert(++n);
		}
	}
}

QueryResult& TextQuery::query(const std::string &s) {
	
}




#endif