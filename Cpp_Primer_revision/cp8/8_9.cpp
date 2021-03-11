#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

int main() {
	std::ifstream fin("calsagan.txt");
	std::string line;
	std::vector<std::string> cosmos;
	
	while (getline(fin, line)){
		cosmos.push_back(line);
	}
	
	for (auto it = cosmos.begin(); it != cosmos.end(); ++it){
		std::istringstream record (*it);
		std::string word;
		while (record >> word) {
			std::cout << word << std::endl;
		}
	}
	
	return 0;
}