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

class queryResult;

class textQuery{
friend class queryResult;
public:
	using line_no = std::vector<std::string>::size_type;
	textQuery(std::ifstream &);
	
	queryResult query(const std::string &) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

std::ostream& print(std::ostream&, const queryResult&);

class queryResult{
friend std::ostream& print(std::ostream&, const queryResult&);
public:
	queryResult(std::string s,
				std::shared_ptr<std::set<textQuery::line_no>> p,
				std::shared_ptr<std::vector<std::string>> f)
				: sought(s), lines(p), file(f) { }
	std::shared_ptr<std::vector<std::string>> get_file() const {return file;}
private:
	std::string sought;
	std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<std::set<textQuery::line_no>> lines;
};

textQuery::textQuery (std::ifstream &fin) : file (new std::vector<std::string>)
{
	std::string text;
	while(std::getline(fin, text)){
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream iss(text);
		std::string word;
		while(iss >> word) {
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}


queryResult textQuery::query(const std::string &sought) const {
	static std::shared_ptr<std::set<line_no>> nodata (new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return queryResult(sought, nodata, file);
	else
		return queryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream &os, const queryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << "time(s)" << std::endl;
	for (auto num : *qr.lines)
		os << "\t (line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}


#endif