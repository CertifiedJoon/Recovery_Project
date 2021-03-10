#ifndef PERSON_H
#define PERSON_H

#include <string>

struct person{
	person () = default;
	person (const std::string &s) : name(s) {}
	person (const std::string &s, const std::string &a) : name(s), address(a) {}
	person (std::istream &is); 
	
	std::string getName() const { return name; }
	std::string getAddress() const { return address; }
	
	std::string name;
	std::string address;
};

std::istream& read (std::istream &, person &);
std::ostream& print (std::ostream &, person &);

person::person(std::istream &is) { read(is, *this); }

std::istream& read (std::istream &is, person &ind) {
	is >> ind.name >> ind.address;
	return is;
}

std::osream& print (std::ostream &os, person &ind) {
	os << ind.name() << ": " << ind.getAddress() << std::endl;
}

#endif