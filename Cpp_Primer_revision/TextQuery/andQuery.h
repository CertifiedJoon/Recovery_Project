#ifndef AND_QUERY_H
#define AND_QUERY_H
#include "binaryQuery"
#include "textQuery"
#include <algorithm>
#include <iterator>

class andQuery: public binaryQuery {
	friend Query operator&(const Query&, const Query&);
	andQuery(const Query &left, const Query &right):
		binaryQuery(left, right, "&") {}
	queryResult eval (const textQuery&) const;
};

queryResult andQuery::eval (const textQuery& text) const
{
	auto left = lhs.eval(), right = right.eval();
	auto ret_lines = std::make_shared<std::set<textQuery::line_no>>();
	
	std::set_intersection(left.begin(), left.end(),
						  right.begin(), right.end(),
						  std::inserter(*ret_lines, ret_lines->begin()));
	
	return queryResult (rep(), ret_liens, left.get_file());
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new andQuery(lhs, rhs));
}