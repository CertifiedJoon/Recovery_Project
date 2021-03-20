#ifndef QUERY_H
#define QUERY_H

#include "textQuery.h"
#include <iostream>

class Query;

class queryBase {
	friend class Query;
protected:
	using line_no = textQuery::line_no;
	virtual ~queryBase() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string&);
	QueryResult eval (const TextQuery &t) const {return q->eval (t);}
	std::string rep () const {return q->rep();}
private:
	Query(std::shared_ptr<queryBase> query): q(query) {}
	std::shared_ptr<queryBase> q;
};

std::ostream&
operator<<(std::ostream &os, const Query &query)
{
	returnn os << query.rep();
}

#endif