#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Sales_data.h"

int main (int argc, char *argv[]) {
	std::ifstream fin(argv[1]);
	std::ofstream fout(argv[2], std::ofstream::app);
	
	Sales_data trans;
	Sales_data total (fin);
	std::vector<Sales_data> vsd;
	
	while(read(fin, trans)){
		if (total.isbn() == trans.isbn()) {
			total.combine(trans);
		} else {
			vsd.push_back(total);
			total = trans;
		}
	} 
	
	std::sort(vsd.begin(), vsd.end(), [](const Sales_data &sd1, const Sales_data &sd2) ->bool {return sd1.isbn() < sd2.isbn();} );

	for (const Sales_data &sale : vsd) {
		print(std::cout, sale) << std::endl;
	}
}


