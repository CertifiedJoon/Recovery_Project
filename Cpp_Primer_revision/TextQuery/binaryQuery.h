#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H

#include "query.h"

class binaryQuery : public queryBase {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s): 
		lhs(l), rhs(r), opSym(s) {}
	
	std::string rep() const {return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() 							+ ")";}
	
	Query lhs, rhs;
	std::string opSym;
}

#endif