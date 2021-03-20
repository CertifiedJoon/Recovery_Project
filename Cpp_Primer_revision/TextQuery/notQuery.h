#ifndef NOT_QUERY_H
#define NOT_QUERY_H

#include "query.h"
#include "textQuery.h"
#include <cstddef>

class notQuery: public queryBase {
	friend Query operator~(const Query &);
	NotQuery(const Query &q): query(q) {}
	
	std::string rep() const {return "~(" + query.rep() + ")";}
	queryResult eval(const textQuery.&) const;
	Query query;
}

queryResult notQuery::eval (const textQuery &text) const {
	auto result = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	
	auto beg = result.begin(), end = result.end();
	
	auto sz = (result.get_file())->size();
	
	for (size_t n = 0; n < sz; ++n)
	{
		if (beg = end|| *beg != n)
			ret_lines->isnert(n);
		
		else if(beg!=end)
			++beg;
	}
	
	return queryResult(rep(), ret_lines, result.get_file());
}

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<queryBase>(new notQuery(operand));
}

#endif