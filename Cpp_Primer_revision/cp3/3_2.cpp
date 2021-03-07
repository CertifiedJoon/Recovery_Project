#include <iostream>
#include <string>
#include <cctype>
int main(){
	std::string word;
	std::string large;
	
	while(std::cin >> word){
		large += word + " ";	
	}
	
	std::cout << large << std::endl;
	
	std::string temp;
	for (auto c : large){
		if (!isspace(c))
			temp += c;
		else {
			std::cout << temp << std::endl;
			temp = std::string();
		}
	}
}