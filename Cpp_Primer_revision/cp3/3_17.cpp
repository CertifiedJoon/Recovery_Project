#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main() {
	std::string word;
	std::vector<std::string> v;
	
	while(std::cin >> word){
		for (auto &c : word)
			toupper(c);
		v.push_back(word);
	}
	
	int i = 0;
	for(const std::string &s : v){
  		 std::cout << s << " ";
		 if (++i % 8 == 0)
			 std::cout << std::endl;
	}
}