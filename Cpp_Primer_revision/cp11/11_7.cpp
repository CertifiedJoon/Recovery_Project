#include <fstream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <iostream>
#include <iomanip>

int main() {
	std::map<std::string, std::set<std::pair<std::string, std::string>>> family;
	std::string first_name, family_name, age;
	std::ifstream fin("name.txt");
	
	while(fin >> first_name >> family_name >> age)
		family[family_name].insert({first_name, age});
		
	for (const auto & fam : family) {
		std::cout << fam.first << std::endl;
		for (const auto & nb : fam.second)
			std::cout << '\t'  << std::setw(10) << std::left << nb.first << nb.second << std::endl;
	}
}