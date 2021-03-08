#include <iostream>
#include <string>
#include <cctype>

int main() {
	std::string text();
	std::string vowels = "aAeEiIoOuU";
	std::getline(std::cin, text);
	
	unsigned vCnt = 0;
	unsigned pCnt = 0;
	for (const char c : text){
		if (vowels.find(c))
			++vCnt;
		else if (isspace(c)){
			++pCnt;
		}
	}
}