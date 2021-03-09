#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
	std::string str1 (argv[1]);
	std::string str2 (argv[2]);
	std::string str = str1 + str2;
	
	std::cout << str << std::endl;
	
	return 0;
}