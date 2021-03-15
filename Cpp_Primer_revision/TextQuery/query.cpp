#include "query.h"
#include <iostream>
#include <fstream>

void runQueries(std::ifstream &fin) 
{
	Textquery tq(infile);
	
	while(true){
		std::cout << "enter a word to look for, or q to quit: ";
		std::string s;
		
		if(!(std::cin >> s) || s == "q") break;
		
		print(std::cout, tq.query(s)) << std::endl;
	}
}

/* i need:
	

*/