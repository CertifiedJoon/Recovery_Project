#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <algorithm>

void transform(std::string &word);

int main() {
	std::ifstream fin("lyrics.txt");
	std::string word;
	std::map<std::string, size_t> word_cnt;
	std::set<std::string> exclude {"and", "the", "a", "an", "or"};
	
	while(fin >> word){
		transform(word);
		if (exclude.find(word) == exclude.end())
			++word_cnt[word];
	}
	
	for (const auto &wc : word_cnt) 
		std::cout << std::setw(12) << std::left << wc.first << ": " << wc.second << std::endl;
}

void transform(std::string &word){
	auto it = word.begin();
	
	while((it = find_if(it, word.end(), [](const char& c) { return std::ispunct(c); })) != word.end())
		it = word.erase(it);
	
	for (auto &c : word)
		c = tolower(c);
}