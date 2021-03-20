#ifndef WORD_QUERY_H
#define WORD_QUERY_H

#include "query.h"
#include "textQuery.h"

class wordQuery: public queryBase {
	friend class Query;
	wordQuery(const std::string &s): query_word(s) {}
	
	queryResult eval(const textQuery &t) const { return t.query(queryWord);}
	
	std::string rep() const {return queryWord;}
	std::string queryWord;
};

inline
Query::Query(const std::string &s) : q (new wordQuery(s)) {}


#endif