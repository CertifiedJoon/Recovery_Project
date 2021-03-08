#include <iostream>
#include <string>

int main(){
	unsigned max = 1;
	unsigned cnt = 1;
	std::string word;
	std::string prev;
	std::string repeated;
	
	while (std::cin >> word){
		if (prev != "" && prev == word) {
			cnt++;
		} else {
			cnt = 1;
		}
		
		if (cnt > max){
			repeated = word;
			max = cnt;
		}
		std::cout << word << max << cnt << std::endl;
		prev = word;
	}
	if (max != 1)
		std::cout << repeated << " was repeated " << max << " times." << std::endl;
	else 
		std::cout << "No word was repeated" << std::endl;
}