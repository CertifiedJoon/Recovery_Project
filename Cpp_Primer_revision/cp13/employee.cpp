#include <string>

class Employee {
public:
	Employee() : name(""), id(curr++) {}
	Employee(cosnt std::string &nombre) : name(nombre), id(curr++) {} 
private:
	std::string name;
	int id;
	static int curr;
};
