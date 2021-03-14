#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <iostream>

int main () {
	std::string number;
	int digit;
	std::vector<std::pair<std::string, int>> vp;
	
	while(std::cin >> number >> digit){
		vp.push_back({number, digit});
		vp.push_back(make_pair(number, digit));
		vp.push_back(std::pair<std::string, int>(number, digit));
	}
	
	for (const auto & idk : vp) {
		std::cout << std::setw(10)  << std::left << idk.first << " " << idk.second << std::endl; 
	}
}