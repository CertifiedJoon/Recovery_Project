#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

void transform(std::string &word){
	auto it = word.begin();
	
	while((it = find_if(it, word.end(), [](const char& c) { return std::ispunct(c); })) != word.end())
		it = word.erase(it);
	
	for (auto &c : word)
		c = tolower(c);
}

int main(){
	std::string word ("h,ey,");
	transform(word);
	std::cout << word << std::endl;
}
