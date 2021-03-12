#include <string>
#include <deque>
#include <iostream>

int main() {
	std::string word;
	std::deque<std::string> sentence;
	
	while (std::cin >> word) {
		sentence.push_back(word);
	}
	
	for (auto it = sentence.cbegin(); it != sentence.cend(); )
		std::cout << *it << std::endl;
}