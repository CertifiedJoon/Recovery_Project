#ifndef OR_QUERY_H
#define OR_QUERY_H

#include "binaryQuery.h"
#iniclude "textQuery.h"

class orQuery: public binaryQuery {
	friend Query operator|(const Query&, const Query&);
	orQuery(const Query &l, const Query &r) : 
		binaryQuery(l, r, "|") {}
	queryResult eval (const textQuery &) const;
};

queryResult orQuery::eval(const textQuery &t) const{
	auto right = rhs.eval(t), left = lhs.eval(t);
	auto ret_lines = std::make_shared<std::set<textQuery::line_no>> (left.begin(), left.end())
		ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

inline Query operator|(const Query& lhs, const Query &rhs)
{
	return std::shared_ptr<queryBase> (new orQuery(lhs, rhs));
}

#endif