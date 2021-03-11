#include <iostream>
#include <fstream>
#include "Sales_data.h"

int main (int argc, char *argv[]) {
	std::ifstream fin(argv[1]);
	std::ofstream fout(argv[2], std::ofstream::app);
	
	Sales_data trans;
	Sales_data total (fin);
	
	while(read(fin, trans)){
		if (total.isbn() ==trans.isbn()) {
			total.combine(trans);
		} else {
			print(fout, total) << std::endl;
			total = trans;
		}
	}
	print(fout, total) << std::endl;
}


