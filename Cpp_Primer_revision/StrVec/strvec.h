#include <string>
#include <allocator>
#include <initializer_list>

class StrVec {
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec (const StrVec&);
	StrVec (std::initializer_list<std::string> il);
	StrVec (StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {s.elements = s.first_free = s.cap = nullptr;}
	StrVec &operator= (const StrVec&);
	StrVec &operator= (StrVec&&);
	StrVec &operator= (std::initializer_list<std::string>);
	~StrVec();
	
	StrVec& push_back(const std::string&);
	StrVec& push_back(std::string &&rhs);
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}
	std::string *begin() const {return elements;}
	std::string *end() const {return first_free;}
	void reserve(size_t i);
	void resize(size_t i, const std::string &s = "");
private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate();}
	std::pair<std::string*, std::string*> alloc_n_copy (const std::string*, const std::string*);
	void free();
	void reallocate();
	
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

void StrVec::reserve(size_t i)
{
	auto newcap = i;
	auto newdata = alloc.allocate(newcap);
	auto dest = newdata;
	auto elem = elements;
	
	for (size_t i =0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcap;
}

void StrVec::resize(size_t i, const std::string &s)
{
	if (i < size()){
		while(first_free != elements + i)
			alloc.destroy(--first_free);
	} else if ( i > size()){
		while (first_free != elements + i){
			chk_n_alloc();
			alloc.construct(first_free++, s);
		}
	}
}

StrVec& StrVec::push_back(const std::string&s) 
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
	
	return *this;
}

StrVec& StrVec::push_back(std::string &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy (const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return {data, std::uninitialied_copy(b, e, data)};
}

void StrVec::free ()
{
	if (elements){
		std::for_each(first_free, elements, alloc.destroy()
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
void StrVec::reallocate()
{
	auto newcap = size() ? 2 * size() : 1;
	auto first = alloc.allocate(newcap);
	auto last = std::unintialized_copy(std::make_move_iterator(begin()),
									   std::make_move_iterator(end()),
									   first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcap;
}

StrVec::StrVec (const StrVec &s) 
{
	auto newdata = alloc_n_copy(s.begin, s.end());
	elements = newdata.first;
	first_free = cap = newdata_second;
}

StrVec::~StrVec() 
{
	free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rsh.end());
	free();
	elements = data.frst;
	first_free = cap = data.second;
	return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs)
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
  
StrVec::StrVec(std::initializer_list<std::string> il) 
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	free();
	elements = newdata.first;
	first_free = newdata.second;
	cap = newdata.second;
}
					  
StrVec& StrVec::operator=(std::intializer_list<std::string>)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}