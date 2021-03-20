#include "query.h"
#include <iostream>
#include <fstream>
#include <string>
void runQueries(std::ifstream &fin) 
{
	textQuery tq(fin);
	
	while(true){
		std::cout << "enter a word to look for, or q to quit: ";
		std::string s;
		
		if(!(std::cin >> s) || s == "q") break;
		
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main(int argc, char* argv[]) {
	std::ifstream fin(argv[1]);
	runQueries(fin);
} 