#include <vector>
#include <iostream>
#include <string>
int main() {
	std::vector<std::string> v{10, "hi"};
	
	for (auto s : v){
		std::cout << s << std::endl;
	}
	
	return 0;
}