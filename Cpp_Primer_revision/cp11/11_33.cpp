#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>


void word_transform(std::ifstream &map_file, std::ifstream &input) {
	auto trans_map = buildMap(map_file);
	std::string text;
	while(std::getline(input, text)) {
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				std::cout << " ";
			std::cout <<transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}

std::map<string, string> buildMap(std::ifstream &map_file){
	std::map<std::string, std::string> trans_map;
	std::string key, val;
	
	while(map_file >> key && std::getline(map_file, value)) {
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw std::runtime_error("no rule for " + key);
	}
	
	return trans_map;
}

const std::string &
transform (const string &s, const map<std::string, std::string> &m){
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}

int main(int argc, char *argv[]) {
	std::ifstream fin(string(argv[1]));
	std::ifstream frule(string(argv[2]));
	
	word_transform(frule, fin);
}