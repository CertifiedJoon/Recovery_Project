#include <string>

class HasPtr;

void swap(HasPtr&, HasPtr&);

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
	HasPtr& operator= (const HasPtr &);
	~HasPtr() {delete ps;}
private:
	std::string *ps;
	int i;
}

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newp = new string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}

HasPtr& HasPtr::operator=(const HasPtr& rhs) 
{
	ps = new std::string(*rhs.ps);
	i = rhs.i;
	return *this;
}