#include <string>
#include <iostream>
#include <cctype>

void lower_string(std::string &);

bool check_cap(const std::string &);

int main () {
	std::string word; 
	std::cin >> word;
	
	std::cout << check_cap(word) << std::endl;
	lower_string(word);
	
	std::cout << word << std::endl;
	
	return 0;
}

void lower_string(std::string &s){
	for (char &c : s)
		c = tolower(c);
}

bool check_cap (const std::string &s){
	for (const char &c : s){
		if (isupper(c)) return true;
	}
	
	return false;
}