#include <iostream>
#include <string>
#include <vector>
int main(){
	int i;
	
	std::vector<int> iv;
	std::vector<std::string> sv;
	
	while (std::cin >> i)
		iv.push_back(i);
	
	for (auto temp : iv)
		std::cout << temp << std::endl;
	
	
	std::string s;
	std::cin.clear();
	while (std::cin >> s)
		sv.push_back(s);
	
	for (auto temp : sv)
		std::cout << temp << std::endl;
	
	return 0;
}