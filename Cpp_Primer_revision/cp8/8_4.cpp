#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main() {
	std::ifstream fin("calsagan.txt");
	std::string line;
	std::vector<std::string> cosmos;
	
	while (getline(fin, line)){
		cosmos.push_back(line);
	}
	
	for (auto it = cosmos.begin(); it != cosmos.end(); ++it)
		std::cout << *it << std::endl;
	
	return 0;
}